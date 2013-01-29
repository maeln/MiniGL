/*
 * modelhandler.hxx
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


#ifndef MODELHANDLER_HXX
#define MODELHANDLER_HXX

/*!
 * \file modelhandler.hxx
 * \brief Create and manage model ( an object who can contain a mesh, texture, shader model matrix, ... ).
 * \author Maël N.
 * \version 0.1a
 * \date 28.01.2013
 */

typedef struct {} PeModel; // Dummy struct, should contain a model ( mesh, shaders, textures, model matrix ... )

class ModelHandler
{
	public:
		ModelHandler();
		virtual ~ModelHandler();
	
	private:
		/* add your private declarations */
};

#endif /* MODELHANDLER_HXX */ 
