/*
 * Interfac.h
 *
 *  Created on: 21.07.2017
 *      Author: johannes.litger
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <stdio.h>

class Interface
{
public:
	Interface();
	virtual ~Interface();
	virtual void saySomething() = 0;
};

#endif /* INTERFACE_H_ */
