/*****************************************************************************
File: TD1-utils.cpp

Informatique Graphique
Christian Jacquemin, Universite Paris-Sud & LIMSI-CNRS

Copyright (C) 2016 University Paris-Sud
This file is provided without support, instruction, or implied
warranty of any kind.  University Paris 11 makes no guarantee of its
fitness for a particular purpose and is not liable under any
circumstances for any damages or loss whatsoever arising from the use
or inability to use this file or items derived from it.
******************************************************************************/
#include "stdafx.h"
#include "td1_utils.h"

////////////////////////////////////////
// prints errors after shader compiling
void printLog(GLuint obj)
{
	int infologLength = 0;
	int maxLength;

	if (glIsShader(obj))
		glGetShaderiv(obj, GL_INFO_LOG_LENGTH, &maxLength);
	else
		glGetProgramiv(obj, GL_INFO_LOG_LENGTH, &maxLength);

	char *infoLog = new char[maxLength];

	if (glIsShader(obj))
		glGetShaderInfoLog(obj, maxLength, &infologLength, infoLog);
	else
		glGetProgramInfoLog(obj, maxLength, &infologLength, infoLog);

	if (infologLength > 0)
		printf("%s\n", infoLog);

	delete infoLog;
}

////////////////////////////////////////
// shader file loading
unsigned long getFileLength(ifstream& file)
{
	if (!file.good()) return 0;

	file.seekg(0, ios::end);
	unsigned long len = file.tellg();
	file.seekg(ios::beg);

	return len;
}

int loadshader(string filename, GLuint shader)
{
	GLchar* shaderSource;
	unsigned long len;

	ifstream file;
	file.open(filename.c_str(), ios::in); // opens as ASCII!
	if (!file) {
		printf("Error: shader file not found %s!\n", filename.c_str()); throw 53;
	}

	len = getFileLength(file);
	if (len == 0) {
		printf("Error: empty shader file %s!\n", filename.c_str()); throw 53;
	}

	shaderSource = new char[len + 1];
	if (shaderSource == 0) {
		printf("Error: shader string allocation error %s!\n", filename.c_str()); throw 53;
	}

	printf("Loading %s\n", filename.c_str());

	// len isn't always strlen cause some characters are stripped in ascii read...
	// it is important to 0-terminate the real length later, len is just max possible value...
	shaderSource[len] = 0;

	unsigned int i = 0;
	while (file.good()) {
		shaderSource[i] = file.get();       // get character from file.
		if (!file.eof())
			i++;
	}

	shaderSource[i] = 0;  // 0-terminate it at the correct position

	file.close();

	glShaderSource(shader, 1, (const char **)&shaderSource, NULL);

	delete[] shaderSource;

	return 0; // No Error
}

// texture loading
/*
bool loadtexture(string flieName) {
// texture load through OpenCV
image = cv::imread(flieName, CV_LOAD_IMAGE_COLOR);   // Read the file
if (!image.data) {                              // Check for invalid input
printf("Could not open or find the image\n");
return false;
}
glEnable(GL_TEXTURE_2D);
glGenTextures(1, &textureID);
glActiveTexture(GL_TEXTURE0);
glBindTexture(GL_TEXTURE_RECTANGLE, textureID);
glTexImage2D(GL_TEXTURE_RECTANGLE,     // Type of texture
0,                 // Pyramid level (for mip-mapping) - 0 is the top level
GL_RGB,            // Internal colour format to convert to
image.cols,          // Image width  i.e. 640 for Kinect in standard mode
image.rows,          // Image height i.e. 480 for Kinect in standard mode
0,                 // Border width in pixels (can either be 1 or 0)
GL_BGR, // Input image format (i.e. GL_RGB, GL_RGBA, GL_BGR etc.)
GL_UNSIGNED_BYTE,  // Image data type
image.ptr());        // The actual image data itself
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
// glGenerateMipmap(GL_TEXTURE_2D);
return true;
}

////////////////////////////////////////
// glfw callbacks for keystroke and error
void error_callback(int error, const char* description)
{
fputs(description, stderr);
}
*/

