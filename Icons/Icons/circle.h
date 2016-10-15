#pragma once
#include "geo_obj.h"


class circle : public geo_obj
{
public:
	int x, y;

	circle() {}
	circle(int arg_x1, int arg_y1)
		: x(arg_x1), y(arg_y1)
	{}

	void draw(windowc &obj)
	{
		obj.drawcircle(x, y, 20, 0, 0);

		obj.drawcircle(x, y, r, obj.xpos, obj.ypos);
	}
};