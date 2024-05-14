#include "structs.h"
void Entity::Draw(SDL_Renderer* renderer)
{

}
Pixel::Pixel(float x, float y, float r, float g, float b)
{
	position.x = x;
	position.y = y;
	color.x = r;
	color.y = g;
	color.z = b;
}
void Pixel::Draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, color.x, color.y, color.z, 255);
	SDL_RenderDrawPoint(renderer, position.x, position.y);
}
Rectangle::Rectangle(int x, int y, int w, int h, int r, int g, int b)
{
	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = w;
	rectangle.h = h;
	color.x = r;
	color.y = g;
	color.z = b;
}
void Rectangle::Draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, color.x, color.y, color.z, 255);
	SDL_RenderFillRect(renderer, &rectangle);
}

Line::Line(int x1, int y1, int x2, int y2, int r, int g, int b)
{
	line.x 	= x1;
	line.y 	= y1;
	line.z 	= x2;
	line.w 	= y2;
	color.x = r;
	color.y = g;
	color.z = b;
}

void Line::Draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, color.x, color.y, color.z, 255);
	SDL_RenderDrawLine(renderer, line.x, line.y, line.z, line.w);
}