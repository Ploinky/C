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
#include <conio.h>

int xPos;
int yPos;
int screen_w;
int screen_h;
HWND hwnd;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void init(HWND);
void draw();
int gameLoop();
void handleKey();

#endif /* SRC_MAIN_H_ */
