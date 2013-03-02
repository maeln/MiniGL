/*
 * meshloader.hxx
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


#ifndef MESHLOADER_HXX
#define MESHLOADER_HXX

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

/*!
 * \file meshloader.hxx
 * \brief Load a mesh using Assimp, and create all the VBO/VAO for it.
 * \author Maël N.
 * \version 0.1a
 * \date 28.01.2013
 */

/*!
 * \struct MeshVBO
 * \brief Conatain all the VBO of a Mesh.
 */
typedef struct
{
	GLuint VBOvert; /*!< The VBO that contain the Vertices. */
	GLuint VBOnorm; /*!< The VBO that contain the Nomals. */
	std::vector<GLuint> VBOtexC; /*!< The VBOs that contain the Texture Coordinate */
} MeshVBO;

/*!
 * \struct PeMesh
 * \brief A struct that contain everything that describe a mesh.
 * \bug Currently, the inforation of the mesh is uploaded to the Memory and the Video Memory. It's not a big deal, 
 * but it could be useful to let the engine free the information in the memory when it's uploaded to the Video Memory.
 */
typedef struct 
{
	std::vector<glm::vec3> vertices; /*!< An array of vector that contain the vertices of the mesh. */
	std::vector<glm::vec3> normals; /*!< An array of  vector that contain the normals of the mesh. */
	
	unsigned int nbTexCoord; /*!< Number of texture coordinate in the mesh. */
	std::vector< std::vector<glm::vec3> > texCoord; /*!< An array of vector that contain the Tecture Cootdinate of the Mesh ( can be empty ). */
	
	bool uploaded; /*!< Set to true if the mesh has been uploaded to Video Memory ( so it has VBOs ). */
	
	MeshVBO vbos; /*!< Contain all the VBO of the Mesh. */
	
	GLuint mvao; /*!< The VAO that is use to draw the mesh. */
} PeMesh;

/*!
 * \class MeshLoader
 * brief Load Meshs to Memory.
 */
class MeshLoader
{
	public:
		/*!
		 * \brief Constructor of the MeshLoader class.
		 */
		MeshLoader();
		
		/*!
		 * \brief Destuctor of the MeshLoader class.
		 */
		virtual ~MeshLoader();
		
		/*!
		 * \brief Load a Mesh from the file system.
		 * \param path Path of the file to load.
		 * \return An PeMesh containing the Mesh data's.
		 */
		PeMesh loadMesh(std::string path);
		
		/*!
		 * \brief Upload a mesh to the Video Memory ( on the video card ).
		 * \param mesh the mesh to upload.
		 * \param drawType The  draw type of the mesh ( GL_STREAM_DRAW, ... ).
		 */
		 void uploadMesh(PeMesh* mesh, GLenum drawType);
		 
		 /*!
		  * \brief Delete the mesh in video's memory.
		  * \param mesh Mesh to delete.
		  */
		  void cleanVMem(PeMesh mesh);
		 
		 /*!
		  * \brief Convert a vector of glm::vec3 to a float array.
		  * \param array The vector to convert.
		  * \param result The resulting array of float.
		  */
		  void vec3float(std::vector<glm::vec3> array, float* result);
	
	private:
		
};

#endif /* MESHLOADER_HXX */ 
