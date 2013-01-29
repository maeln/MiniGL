/*
 * matrixstack.hxx
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


#ifndef MATRIXSTACK_HXX
#define MATRIXSTACK_HXX

/*!
 * \file matrixstack.hxx
 * \brief Implement Matrix Stack, useful for various OpenGL stuff.
 * \author Maël N.
 * \version 0.1a
 * \date 28.01.2013
 */

// Note : Les surcharges d'opérateurs ça troue le cul, y penser.

class MatrixStack
{
	public:
		MatrixStack();
		virtual ~MatrixStack();
	
	private:
		/* add your private declarations */
};

#endif /* MATRIXSTACK_HXX */ 
