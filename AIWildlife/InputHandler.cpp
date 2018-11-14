#include "InputHandler.h"
bool InputHandler::IsKeyDown(_Keys keys)
{
	return GetAsyncKeyState(keys);
}

bool InputHandler::IsKeyUp(_Keys keys)
{
	return !GetAsyncKeyState(keys);
}
