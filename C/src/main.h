/*
 * main.h
 *
 *  Created on: 06.07.2017
 *      Author: johannes.litger
 */

#ifndef SRC_MAIN_H_
#define SRC_MAIN_H_

#include <windows.h>
#include <stdio.h>
#include <windowsx.h>

int xPos;
int yPos;
HWND hwnd;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void CenterWindow(HWND);
void draw();

#endif /* SRC_MAIN_H_ */
