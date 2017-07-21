/*
 * Impl1.h
 *
 *  Created on: 21.07.2017
 *      Author: johannes.litger
 */

#ifndef IMPL1_H_
#define IMPL1_H_

#include "Interface.h"

class Impl1: public Interface
{
public:
	Impl1();
	virtual ~Impl1();
	void saySomething();
};

#endif /* IMPL1_H_ */
