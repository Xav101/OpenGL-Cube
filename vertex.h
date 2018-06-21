#ifndef VERTEX_H
#define VERTEX_H

#include <glad/glad.h>
#include <iostream>
#include <vector>

class vertex {
private:
	const float triangle_vert[216] {
		//bottom
		0.5f, -0.5f,  0.5f,		   1.0f,	0.0f,	 0.0f,
		0.5f, -0.5f, -0.5f,		   1.0f,	0.0f,	 0.0f,
	   -0.5f, -0.5f,  0.5f,		   1.0f,	0.0f,	 0.0f,

	   -0.5f, -0.5f,  0.5f,		   1.0f,	0.0f,	 0.0f,
	   -0.5f, -0.5f, -0.5f,		   1.0f,	0.0f,	 0.0f,
		0.5f, -0.5f, -0.5f,		   1.0f,	0.0f,	 0.0f,
	   //front
		0.5f, -0.5f,  0.5f,		0.9961f, 0.0039f, 0.9961f,
	   -0.5f, -0.5f,  0.5f,		0.9961f, 0.0039f, 0.9961f,
	   -0.5f,  0.5f,  0.5f,		0.9961f, 0.0039f, 0.9961f,

		0.5f,  0.5f,  0.5f,		0.9961f, 0.0039f, 0.9961f,
	   -0.5f,  0.5f,  0.5f,		0.9961f, 0.0039f, 0.9961f,
		0.5f, -0.5f,  0.5f,		0.9961f, 0.0039f, 0.9961f,
		//right
		0.5f, -0.5f,  0.5f,		   0.0f,	1.0f,	 0.0f,
		0.5f,  0.5f,  0.5f,		   0.0f,	1.0f,	 0.0f,
		0.5f,  0.5f, -0.5f,		   0.0f,	1.0f,	 0.0f,

		0.5f,  0.5f, -0.5f,		   0.0f,	1.0f,	 0.0f,
		0.5f, -0.5f, -0.5f,		   0.0f,	1.0f,	 0.0f,
		0.5f, -0.5f,  0.5f,		   0.0f,	1.0f,	 0.0f,
		//left
	   -0.5f,  0.5f, -0.5f,		0.0039f,  0.9961f,	 1.0f,
	   -0.5f,  0.5f,  0.5f,		0.0039f,  0.9961f,	 1.0f,
	   -0.5f, -0.5f,  0.5f,		0.0039f,  0.9961f,	 1.0f,

	   -0.5f,  0.5f, -0.5f,	    0.0039f,  0.9961f,	 1.0f,
	   -0.5f, -0.5f, -0.5f,	    0.0039f,  0.9961f,	 1.0f,
	   -0.5f, -0.5f,  0.5f,	    0.0039f,  0.9961f,	 1.0f,
	   //back
	   -0.5f,  0.5f, -0.5f,		   0.0f,	0.0f,	 1.0f,
		0.5f, -0.5f, -0.5f,		   0.0f,	0.0f,	 1.0f,
	   -0.5f, -0.5f, -0.5f,		   0.0f,	0.0f,	 1.0f,

	   -0.5f,  0.5f, -0.5f,		   0.0f,	0.0f,	 1.0f,
		0.5f,  0.5f, -0.5f,		   0.0f,	0.0f,	 1.0f,
		0.5f, -0.5f, -0.5f,		   0.0f,	0.0f,	 1.0f,
		//top
	   -0.5f,  0.5f, -0.5f,		0.9451f, 0.9569f, 0.0078f,
	   -0.5f,  0.5f,  0.5f,		0.9451f, 0.9569f, 0.0078f,
		0.5f,  0.5f,  0.5f,		0.9451f, 0.9569f, 0.0078f,

	   -0.5f,  0.5f, -0.5f,		0.9451f, 0.9569f, 0.0078f,
		0.5f,  0.5f, -0.5f,		0.9451f, 0.9569f, 0.0078f,
		0.5f,  0.5f,  0.5f,		0.9451f, 0.9569f, 0.0078f
	};

	unsigned int VBO;
	unsigned int VAO;

public:
	int bind() {
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
	
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vert), triangle_vert, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		
		return VAO;
	}
};
#endif