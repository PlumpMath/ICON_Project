#pragma once
#include "geo_obj.h"


class X : public geo_obj
{
public:
	int xx, xy;

	X() {}
	X(int arg_x, int arg_y)
		: xx(arg_x), xy	(arg_y)
	{}

	void draw(windowc &obj)
	{
		obj.drawLine(xx - 25, xy - 25, xx + 25, xy + 25);
		obj.drawLine(xx - 25, xy + 25, xx + 25, xy-25);

		obj.drawcircle(xx, xy, r, (int)obj.xpos, (int)obj.ypos);
	}
};
