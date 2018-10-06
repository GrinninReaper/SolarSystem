#shader vertex
#version 330 core

// input varyings
in vec3 vp;
in vec3 norm;
in vec2 texCoord;

// uniforms
uniform vec3 light;
uniform mat4 modelMatrix;
uniform mat4 inverseModelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

// normal, texture coordinates, light in model coordinates
out vec3 normalOut;
out vec2 texCoordOut;
out vec3 lightOut;
// position in model coordinates
out vec3 positionOut;

void main() {
	// transforms light from world coordinates to model coordinates
	lightOut = (inverseModelMatrix * vec4(light, 0.0)).xyz;

	// copies normals and passes them to FS
	normalOut = norm;
	// copies texture coordinates and passes them to FS
	texCoordOut = texCoord;
	// copies position and passes it to FS
	positionOut = vp;

	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(vp, 1.0);
}

#shader fragment
#version 330 core

// normal, texture coordinates, light in model coordinates
in vec3 normalOut;
in vec2 texCoordOut;
in vec3 lightOut;
// position in model coordinates
in vec3 positionOut;

// uniforms
// uniform sampler2DRect mire;

// out color
out vec4 frag_colour;

void main() {
	// diffuse lighting contribution to color
	frag_colour.rgb = vec3(dot(normalize(normalOut), normalize(lightOut)));
}
