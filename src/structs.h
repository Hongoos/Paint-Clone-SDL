#include "SDL.h"
#include "SDL_image.h"

struct Vec3
{
	int x, y, z;
};

struct Vec4
{
	int x, y, z, w;
};

struct Entity
{
	short id;

	virtual void Draw(SDL_Renderer* renderer);
};

struct Pixel : Entity
{
	Pixel(float x, float y, float r, float g, float b);
	SDL_FPoint position;
	Vec3 color;

	void Draw(SDL_Renderer* renderer) override;
};

struct Rectangle : Entity
{
	Rectangle(int x, int y, int w, int h, int r, int g, int b);
	SDL_Rect rectangle;
	Vec3 color;

	void Draw(SDL_Renderer* renderer) override;
};

struct Line : Entity
{
	Line(int x1, int y1, int x2, int y2, int r, int g, int b);
	Vec4 line;
	Vec3 color;

	void Draw(SDL_Renderer* renderer) override;
};