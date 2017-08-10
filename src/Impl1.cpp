/*
 * Impl1.cpp
 *
 *  Created on: 21.07.2017
 *      Author: johannes.litger
 */

#include "Impl1.h"

Impl1::Impl1()
{
	x = 0;
	y = 0;
}

Impl1::~Impl1()
{
	// TODO Auto-generated destructor stub
}

Move* Impl1::move()
{
	return new Move(5, 5);
}

int Impl1::getX()
{
	return x;
}

int Impl1::getY()
{
	return y;
}

void Impl1::setX(int newX)
{
	x = newX;
}

void Impl1::setY(int newY)
{
	y = newY;
}
