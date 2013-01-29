/*
 * renderwindow.hxx
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


#ifndef RENDERWINDOW_HXX
#define RENDERWINDOW_HXX

#include <iostream>
#include <GL/glew.h>
#include <GL/glfw.h>

void GLFWCALL Wresize(int width, int height);

class RenderWindow
{
	public:
		/**
		 * Create a window with an OpenGL context and handle it.
		 **/
		 
		RenderWindow(GLsizei width, GLsizei height, int GLMajor, int GLMinor, int mode);
		virtual ~RenderWindow(); // Close the window.
		
		void SetTitle(const char* title);
		void AddHint(int hint, int value);
		
	private:
		GLsizei WindowWidth;
		GLsizei WindowHeight;
		const char* WindowTitle;
};

#endif /* RENDERWINDOW_HXX */ 
