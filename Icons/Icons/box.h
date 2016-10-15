#pragma once 
#include "geo_obj.h"


class box : public geo_obj
{
public:
	int x1, y1 ;

	box() {}
	box(int arg_x1, int arg_y1 )
		: x1(arg_x1), y1(arg_y1) 
	{}

	void draw(windowc &obj)
	{
		obj.drawLine(x1, y1, x1+50, y1);
		obj.drawLine(x1, y1+50, x1+50, y1+50);
		obj.drawLine(x1, y1, x1, y1+50);
		obj.drawLine(x1+50, y1, x1+50, y1+50);

		obj.drawcircle(x1+25, y1+25, r, obj.xpos, obj.ypos);
	}
};