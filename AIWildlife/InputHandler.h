#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <Windows.h>
enum _Keys
{
	A = 65,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z
};


 class InputHandler
{
public:
	static bool IsKeyDown(_Keys keys);
	static bool IsKeyUp(_Keys keys);

};

#endif


