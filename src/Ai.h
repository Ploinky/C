/*
 * Interfac.h
 *
 *  Created on: 21.07.2017
 *      Author: johannes.litger
 */

#ifndef AI_H_
#define AI_H_

#include <stdio.h>
#include "move/Move.h"

class Ai
{
public:
	Ai();
	virtual ~Ai();
	virtual Move* move() = 0;
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual void setX(int newX) = 0;
	virtual void setY(int newY) = 0;
};

#endif /* AI_H_ */
