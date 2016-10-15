#pragma once 
#include "geo_obj.h"


class line  : public geo_obj
{
public:
	int x1, y1, x2, y2;

	line() {}
	line(int arg_x1, int arg_y1, int arg_x2, int arg_y2)
		: x1(arg_x1), y1(arg_y1), x2(arg_x2), y2(arg_y2)
	{}

	void draw(windowc &obj)
	{
		obj.drawLine(x1, y1, x2, y2);

		obj.drawcircle(x1+25, y1+25, r,  obj.xpos, obj.ypos);
	}
};