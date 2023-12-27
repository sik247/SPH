#ifndef SPH_SIMULATOR_H
#define SPH_SIMULATOR_H

#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#endif
#include <glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory> // for std::unique_ptr
#include <vector>
//#include <eigen3/Eigen/Core>

#endif