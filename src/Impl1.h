/*
 * Impl1.h
 *
 *  Created on: 21.07.2017
 *      Author: johannes.litger
 */

#ifndef IMPL1_H_
#define IMPL1_H_

#include "Ai.h"

class Impl1 : public Ai
{
public:
	Impl1();
	virtual ~Impl1();
	Move* move();
	int getX();
	int getY();
	void setX(int newX);
	void setY(int newY);

private:
	int x;
	int y;
};

#endif /* IMPL1_H_ */
