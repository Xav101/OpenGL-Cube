#define GLM_ENABLE_EXPERIMENTAL
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/vec4.hpp>
#include <iostream>
#include <vector>
#include "shader.h"
#include "vertex.h"


shader sh;
vertex vx;

unsigned int WINDOW_HEIGHT = 900;
unsigned int WINDOW_WIDTH = 1800;

void framebuffer_size_callback(GLFWwindow* window, int NEW_WIDTH, int NEW_HEIGHT) {
	glViewport(0, 0, NEW_WIDTH, NEW_HEIGHT);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL", NULL, NULL);

	if (window == NULL) {
		std::cout << "Failed to create GLFW window\n";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, key_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		std::cout << "Failed to initialize GLAD" << std::endl;

	unsigned int shader_program = sh.compile_link();
	sh.check_errors();

	int width, height, nrChannels;

	unsigned int VAO = vx.bind();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
		glEnable(GL_DEPTH_TEST);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);

		
		model = glm::rotate(model, glm::radians(55.0f), glm::vec3(0.0, 1.0, 0.0));
		//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		view = glm::lookAt(glm::vec3(3, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
		projection = glm::perspective(glm::radians(45.0f), 2.0f / 1.0f, 0.1f, 100.f);
		

		unsigned int model_loc = glGetUniformLocation(shader_program, "model");
		unsigned int view_loc = glGetUniformLocation(shader_program, "view");
		unsigned int projection_loc = glGetUniformLocation(shader_program, "projection");
		
		glUniformMatrix4fv(model_loc, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(view_loc, 1, GL_FALSE, &view[0][0]);
		glUniformMatrix4fv(projection_loc, 1, GL_FALSE, glm::value_ptr(projection));

		glUseProgram(shader_program);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
	glfwTerminate();
	return 0;
}