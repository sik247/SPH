#ifndef PARTICLERENDERER_H
#define PARTICLERENDERER_H
#include "sph_simulator.h"
#include "Particle.h"
#include "Shader.h"
class ParticleRenderer {
private:
    GLuint VAO, VBO;
    Shader particleShader;

public:
    ParticleRenderer(const char* vertexPath, const char* fragmentPath)
        : particleShader(vertexPath, fragmentPath)
    {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void render(std::vector<Particle>& particles, const glm::mat4& view, const glm::mat4& projection)
    {
        std::vector<glm::vec3> positions;
        
        for (auto& p : particles)
        {
            positions.push_back(p.getPosition());
        }

        particleShader.use();
        glUniformMatrix4fv(glGetUniformLocation(particleShader.ID, "view"), 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(glGetUniformLocation(particleShader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
        particleShader.setFloat("pointSize", 50.0f);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(glm::vec3), &positions[0], GL_DYNAMIC_DRAW);

        glBindVertexArray(VAO);
        glDrawArrays(GL_POINTS, 0, positions.size());
        glBindVertexArray(0);
    }

    ~ParticleRenderer()
    {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
    }
};
#endif