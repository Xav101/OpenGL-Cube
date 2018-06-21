#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <iostream>

class shader {
private:
	unsigned int vertexShader;
	unsigned int fragmentShader;

public:
	int compile_link() {
		const char *vertexShaderSource = "#version 450 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"layout (location = 1) in vec3 aColor;\n"
			"uniform mat4 model;\n"
			"uniform mat4 view;\n"
			"uniform mat4 projection;\n"
			"out vec3 ourColor;\n"
			"void main() {\n"
			"gl_Position = projection * view * model * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
			"ourColor = aColor;\n"
			"}";

		const char *fragmentShaderSource = "#version 450 core\n"
			"uniform vec4 inColor;\n"
			"in vec3 ourColor;\n"
			"out vec4 FragColor;\n"
			"void main() {\n"
			"FragColor = vec4(ourColor, 1.0f);\n"
			"}";

		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		unsigned int shader_program;
		shader_program = glCreateProgram();

		glAttachShader(shader_program, vertexShader);
		glAttachShader(shader_program, fragmentShader);
		glLinkProgram(shader_program);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		return shader_program;
	}

	void check_errors() {
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VETEX::COMPILATION::FAILED\n" << infoLog << std::endl;
		}
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION::FAILED\n" << infoLog << std::endl;
		}
	}
};
#endif