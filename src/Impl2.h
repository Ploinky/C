/*
 * Impl2.h
 *
 *  Created on: 21.07.2017
 *      Author: johannes.litger
 */

#ifndef IMPL2_H_
#define IMPL2_H_

#include "Ai.h"

class Impl2 : public Ai
{
public:
	Impl2();
	virtual ~Impl2();
	Move* move();
	int getX();
	int getY();
	void setX(int newX);
	void setY(int newY);

private:
	int x;
	int y;
};

#endif /* IMPL2_H_ */
