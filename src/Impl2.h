/*
 * Impl2.h
 *
 *  Created on: 21.07.2017
 *      Author: johannes.litger
 */

#ifndef IMPL2_H_
#define IMPL2_H_

#include "Interface.h"

class Impl2: public Interface
{
public:
	Impl2();
	virtual ~Impl2();
	void saySomething();
};

#endif /* IMPL2_H_ */
