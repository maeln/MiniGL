/*
 * renderwindow.cxx
 * 
 * Copyright 2013 Mael N. <contact@maeln.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */


#include "renderwindow.hxx"

void GLFWCALL Wresize(int width, int height)
{
	glViewport(0, 0, width, height);
	// projection = glm::perspective(90.f, (float)width/(float)height, 1.f, 10.f);
}

RenderWindow::RenderWindow(GLsizei width, GLsizei height, int GLMajor, int GLMinor, int mode)
{
	std::cerr << "Init:" << std::endl;
	
	WindowHeight = height;
	WindowWidth = width;
		
	// GLFW
	if(glfwInit())
	{
		std::cerr << "Glfw: Done." << std::endl;
	}
	else
	{
		std::cerr << "Glfw: Fail." << std::endl;
	}
	
	// Window
	if(glfwOpenWindow(width, height, 8,8,8,8,16,16, mode))
	{
		std::cerr << "Window: Done." << std::endl;
	}
	else
	{
		std::cerr << "Window: Fail." << std::endl;
		glfwTerminate();
	}
	
	// GLEW
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		std::cerr << "Erreur: " << glewGetErrorString(err) << std::endl;
	}
	std::cerr << "Glew " << glewGetString(GLEW_VERSION) << " : Done." << std::endl;
	
	// Window Hint
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, GLMajor);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, GLMinor);
	
	
	std::cerr << std::endl << "Context:" << std::endl 
		<< "OpenGL Major: " << glfwGetWindowParam(GLFW_OPENGL_VERSION_MAJOR) << std::endl
		<< "OpenGL Minor: " << glfwGetWindowParam(GLFW_OPENGL_VERSION_MINOR) << std::endl
		<< "Refresh Rate: " << glfwGetWindowParam(GLFW_REFRESH_RATE) << std::endl;
		
	glfwSetWindowSizeCallback(Wresize);
	glClearColor(0.f, 0.f, 0.f, 0.f);
}

void RenderWindow::SetTitle(const char *title)
{
	WindowTitle = title;
	glfwSetWindowTitle(WindowTitle);
}

void RenderWindow::AddHint(int hint, int value)
{
	glfwOpenWindowHint(hint, value);
}

RenderWindow::~RenderWindow()
{
	glfwCloseWindow();
}

