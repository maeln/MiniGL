/*
 * meshloader.cxx
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


#include "meshloader.hxx"


MeshLoader::MeshLoader()
{
	
}


MeshLoader::~MeshLoader()
{
	
}

PeMesh MeshLoader::loadMesh(std::string path)
{
	Assimp::Importer importer;
	const aiScene* scene;
	
	scene = importer.ReadFile(path, aiProcess_CalcTangentSpace | aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_GenSmoothNormals | aiProcess_SortByPType | aiProcess_OptimizeMeshes);
	if(!scene->HasMeshes())
	{
		std::string errorMsg = "[ER@";
		errorMsg += __FILE__;
		errorMsg += ":";
		errorMsg += __LINE__;
		errorMsg += "->";
		errorMsg += __FUNCTION__;
		errorMsg += "] File ";
		errorMsg += path;
		errorMsg += " does not contain any mesh.";
		
		std::runtime_error(errorMsg.c_str());
		
	}
	
	if(scene->mNumMeshes > 1)
	{
		std::string errorMsg = "[ER@";
		errorMsg += __FILE__;
		errorMsg += ":";
		errorMsg += __LINE__;
		errorMsg += "->";
		errorMsg += __FUNCTION__;
		errorMsg += "] File ";
		errorMsg += path;
		errorMsg += " contain more than one mesh.";
		
		std::runtime_error(errorMsg.c_str());
	}
	
	// Load vertices and normals.
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	unsigned int numVert = scene->mMeshes[0]->mNumVertices;
	
	aiVector3D* tmpVert = scene->mMeshes[0]->mVertices;
	aiVector3D* tmpNorm = scene->mMeshes[0]->mNormals;
	
	for(unsigned int n=0; n < numVert; n++)
	{
		glm::vec3 tmp;
		tmp.x = tmpVert[n].x;
		tmp.y = tmpVert[n].y;
		tmp.z = tmpVert[n].z;
		vertices.push_back(tmp);
		
		tmp.x = tmpNorm[n].x;
		tmp.y = tmpNorm[n].y;
		tmp.z = tmpNorm[n].z;
		normals.push_back(tmp);
	}
	
	delete tmpVert;
	delete tmpNorm;
	
	PeMesh result;
	result.vertices = vertices;
	result.normals = normals;
	
	// Load texture coodinate if they is a least one.
	if(scene->mMeshes[0]->HasTextureCoords(0))
	{
		std::vector< std::vector<glm::vec3> > texCoord;
		// Check how many texture coord there is.
		unsigned int nbTexCoord = 0;
		unsigned int n = 0;
		while(scene->mMeshes[0]->HasTextureCoords(n))
		{
			nbTexCoord++;
			n++;
		}
		
		// Load how any there is.
		for(unsigned int i=0; i < nbTexCoord; i++)
		{
			std::vector<glm::vec3> tmpCoord;
			
			for(unsigned int z=0; z < numVert; z++)
			{
				glm::vec3 tmp;
				tmp.x = scene->mMeshes[0]->mTextureCoords[i][z].x;
				tmp.y = scene->mMeshes[0]->mTextureCoords[i][z].y;
				tmp.z = scene->mMeshes[0]->mTextureCoords[i][z].z;
			}
			
			texCoord.push_back(tmpCoord);
		}
		
		result.nbTexCoord = nbTexCoord;
		result.texCoord = texCoord;
	}
	else
	{
		result.nbTexCoord = 0;
	}
	
	result.uploaded = false;
	
	delete scene;
	
	return result;
}

