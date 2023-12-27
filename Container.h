#ifndef CONTAINER_H
#define CONTAINER_H
#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#endif
#include "sph_simulator.h"
#include "Shader.h"

// Vertex data
extern float vertices[];
extern GLuint indices[];
extern GLuint VAO, VBO, EBO;
extern GLuint shaderProgram;
void initializeContainer();
void renderContainer(const glm::mat4& view, const glm::mat4& projection);
void cleanupContainer();


#endif