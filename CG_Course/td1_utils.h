#ifndef UTILS_H
#define UTILS_H

#define GLM_FORCE_RADIANS


#include <GL/glew.h> // include GLEW and new version of GL on Windows
#include <GLFW/glfw3.h> // GLFW helper library
#include <stdio.h>
#include "stdafx.h"
//#include <glm.hpp>
//#include <gtc/type_ptr.hpp>
//#include <gtc/matrix_transform.hpp>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
using namespace std;
#include <fstream>

// function prototypes
//bool loadtexture(string flieName);
void printLog(GLuint obj);
unsigned long getFileLength(ifstream& file);
int loadshader(string filename, GLuint shader);
void error_callback(int error, const char* description);

#endif // UTILS_H