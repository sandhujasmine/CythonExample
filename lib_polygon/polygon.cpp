// derived classes
#include "polygon.h"


Polygon::Polygon()
{
	this->width = 0;
	this->height = 0;
};


Polygon::Polygon(int width, int height)
{
	this->width = width;
	this->height = height;
};


void Polygon::set_values(int w, int h)
{
	this->width=w;
	this->height=h;
};

int Polygon::get_width()
{
	return this->width;
}

int Polygon::get_height()
{
	return this->height;
}

int Rectangle::area()
{
	return width * height;
};


int Triangle::area()
{
	return width * height / 2;
};
