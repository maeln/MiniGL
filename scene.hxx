/*
 * scene.hxx
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


#ifndef SCENE_HXX
#define SCENE_HXX

#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "modelhandler.hxx"

/*!
 * \file scene.hxx
 * \brief Manage the scene and all the OpenGL's call related to it.
 * \author Maël N.
 * \version 0.1a
 * \date 28.01.2013
 */

class Scene
{
	public:
		Scene();
		virtual ~Scene();
		
		/*! 
		 * \brief Make all the OpenGL call to draw the scene.
		 * \return Will return 0 if everything went well, -1 otherwise. NOTE: Should implement different code ( with a nice define for exemple ) to know what the error was. And use exception.
		 */
		int draw();
		
		/*!
		 * \brief Attach a model to render in the current scene.
		 * \param i_model : PeModel to attach to the current scene.
		 * \return Will return 0 if everything went well, -1 if there was an error.
		 */
		int attachModel(PeModel i_model);
		
		/*!
		 * \brief Generate the view Matrix of the current scene.
		 * \param lookat : The point in World coordinate to look at.
		 * \param position : The position of the viewer in world coordinate.
		 * \param up : A vector whoes purpose is to say where is the up of the scene.
		*/
		void genView(glm::vec3 lookat, glm::vec3 position, glm::vec3 up);
		
		/*!
		 * \brief Generate the projection Matrix attach to the current scene.
		 * \param fov : The field of View to use.
		 * \param aspectRatio : The aspectRatio of the rendering space. Should be updated everytime it's resized.
		 * \param near : Every object nearer than that will be clip.
		 * \param far : Every object farer than that will be clip.
		*/
		void genProjection(float fov, float aspectRatio, float near, float far);
		
		/*!
		 * \brief Set the View Matrice of the current scene.
		 * \param camera : The view matrice.
		*/
		void setView(glm::mat4 camera);
		
		/*!
		 * \brief Set the Projection Matrice of the current scene.
		 * \param i_Projection : The projection matrix to attach to the scene.
		*/
		void setProjection(glm::mat4 i_Projetion);
	
	private:
		glm::mat4 viewMatrix;
		glm::mat4 projectionMatrix;
		std::vector<PeModel> attachedModels;
};

#endif /* SCENE_HXX */ 
