#include "object.h"
#include "stdafx.h"


void Object::Render(SDL_Renderer * renderer)
{
	SDL_Rect rect;

	rect.x = (int)posX;
	rect.y = (int)posY;
	rect.w = (int)w;
	rect.h = (int)h;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
}
