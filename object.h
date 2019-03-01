#pragma once


// TODO Error C2653, 'Object' is not a class or namespace name.
// Yes it is. 

// TO BRIAN: I can't get the serial to communicate with the pong game.
// I can't figure out how to copy the pong game over to this (alcwyn's Serial project)
// I had a go, I've spent hours on this, I can't do it.
// If you read this and you've got a half hour to spare, I'd love a bit of help with this.



class Object
{
public:

	void virtual init() = 0;
	void virtual Move() = 0;
	void virtual Render(SDL_Renderer* renderer);

	bool virtual IsColliding(const Object& o);

protected:

	float posX, posY;
	float w, h;
};


class Object
{
public:


	void virtual Render(SDL_Renderer* renderer);

protected:


	float posX, posY;
	float w, h;
};
