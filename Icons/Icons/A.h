#pragma once 
#include "geo_obj.h"


class A : public geo_obj
{
public:
	int x1, y1;

	A() {}
	A(int arg_x1, int arg_y1)
		: x1(arg_x1), y1(arg_y1)
	{}

	void draw(windowc &obj)
	{
		obj.drawLine(x1+10, y1+25, x1 + 40, y1+25); 
		obj.drawLine(x1-1, y1, x1 + 25, y1 + 50);
		obj.drawLine(x1+ 25, y1 +50, x1 + 55, y1);

		obj.drawcircle(x1 + 25, y1 + 25, r, obj.xpos, obj.ypos);
	}
};
