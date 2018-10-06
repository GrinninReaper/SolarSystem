#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define GLM_FORCE_RADIANS

void key_callback(GLFWwindow* window, int key, int scancode,
	int action, int mods);
void char_callback(GLFWwindow* window, unsigned int key);

extern bool perspective;

// texture
//extern cv::Mat image;
extern GLuint textureID;