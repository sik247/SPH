#include "Container.h"

// Vertex data
float vertices[] = {
    // Positions          // Colors
    -10, 10, 10,    0.5f, 0.5f, 0.5f,
    -10, 10, -10,   0.5f, 0.5f, 0.5f,
    -10, -10, -10,  0.5f, 0.5f, 0.5f,
    -10, -10, 10,   0.5f, 0.5f, 0.5f,
    10, 10, -10,    0.5f, 0.5f, 0.5f,
    10, 10, 10,     0.5f, 0.5f, 0.5f,
    10, -10, 10,    0.5f, 0.5f, 0.5f,
    10, -10, -10,   0.5f, 0.5f, 0.5f,
    -10, 10, -10,   0.9f, 0.9f, 0.9f,
    10, 10, -10,    0.9f, 0.9f, 0.9f,
    10, -10, -10,   0.9f, 0.9f, 0.9f,
    -10, -10, -10,  0.9f, 0.9f, 0.9f,
    -10, -10, -10,  0.8f, 0.8f, 0.8f,
    10, -10, -10,   0.8f, 0.8f, 0.8f,
    10, -10, 10,    0.8f, 0.8f, 0.8f,
    -10, -10, 10,   0.8f, 0.8f, 0.8f,
    -10, 10, -10,   0.8f, 0.8f, 0.8f,
    10, 10, -10,    0.8f, 0.8f, 0.8f,
    10, 10, 10,     0.8f, 0.8f, 0.8f,
    -10, 10, 10,    0.8f, 0.8f, 0.8f
};

GLuint indices[] = {
    // Left wall
    0, 1, 2,  2, 3, 0,
    // Right wall
    4, 5, 6,  6, 7, 4,
    // Far wall
    8, 9, 10, 10, 11, 8,
    // Bottom wall
    12, 13, 14, 14, 15, 12,
    // Top wall
    16, 17, 18, 18, 19, 16
};

std::unique_ptr<Shader> shader;
GLuint VAO, VBO, EBO;

void initializeContainer() {
    shader = std::make_unique<Shader>("shaders/vertex_shader.vs", "shaders/fragment_shader.fs");
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void renderContainer(const glm::mat4& view, const glm::mat4& projection) {
    shader->use();

    glUniformMatrix4fv(glGetUniformLocation(shader->ID, "view"), 1, GL_FALSE, glm::value_ptr(view));


    glUniformMatrix4fv(glGetUniformLocation(shader->ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

    glBindVertexArray(VAO);

    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(indices[0]), GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);

}

void cleanupContainer() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}