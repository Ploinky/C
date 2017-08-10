/*
 * Impl2.cpp
 *
 *  Created on: 21.07.2017
 *      Author: johannes.litger
 */

#include "Impl2.h"

Impl2::Impl2()
{
	x = 0;
	y = 0;
}

Impl2::~Impl2()
{
	// TODO Auto-generated destructor stub
}

Move* Impl2::move()
{
	return new Move(5, 5);
}

int Impl2::getX()
{
	return x;
}

int Impl2::getY()
{
	return y;
}

void Impl2::setX(int newX)
{
	x = newX;
}

void Impl2::setY(int newY)
{
	y = newY;
}
