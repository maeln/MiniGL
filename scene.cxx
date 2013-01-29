/*
 * scene.cxx
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


#include "scene.hxx"


Scene::Scene()
{
	
}


Scene::~Scene()
{
	
}

void Scene::genView(glm::vec3 lookat, glm::vec3 position, glm::vec3 up)
{
	viewMatrix = glm::lookAt(lookat, position, up);
}

void Scene::genProjection(float fov, float ratio, float near, float far)
{
	projectionMatrix = glm::perspective(fov, ratio, near, far);
}

void Scene::setView(glm::mat4 camera)
{
	viewMatrix = camera;
}

void Scene::setProjection(glm::mat4 i_Projection)
{
	projectionMatrix = i_Projection;
}
