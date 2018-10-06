#shader vertex
#version 330 core

// input variables
in vec3 vp;
in vec3 color;
in vec3 normal;

// uniform variables
uniform mat4 modelMatrix;
uniform mat4 inverseModelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform vec3 light;

// output variables
out vec3 colorOut;
out vec3 lightOut;
out vec3 normalOut;

void main() {
	colorOut = color;
	normalOut = normal;

	// transforms light from world coordinates to model coordinates
	lightOut = (inverseModelMatrix * vec4(light, 0.0)).xyz;

	// TODO calculate diffuse lighting for Gouraud shading and
	// transfer it to fragment shader

	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(vp, 1.0);

}

#shader fragment
#version 330 core

// input variables
in vec3 colorOut;
in vec3 lightOut;
in vec3 normalOut;

// uniform variables
// uniform sampler2DRect mire;

// output color
out vec4 frag_colour;

void main() {
	// TODO calculate diffuse lighting for Phong shading and
	// use it to calculate output color

	// frag_colour.xyz = texture(mire,texCoord);

	frag_colour = vec4(colorOut, 1);

}
