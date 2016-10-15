#pragma once
#include "geo_obj.h"
#include "line.h"
#include "box.h"
#include "circle.h"
#include "X.h"
#include "A.h"
#include <vector>

std::vector<geo_obj*> init()
{
	std::vector<geo_obj*> obj_list;
	obj_list.push_back(new line(40, 380, 90, 430));
	obj_list.push_back(new line(40, 165, 90, 215));
	obj_list.push_back(new box(170, 380));
	obj_list.push_back(new box(170, 165));
	obj_list.push_back(new circle(330, 405));
	obj_list.push_back(new circle(330, 190));
	obj_list.push_back(new X(450, 405));
	obj_list.push_back(new X(450, 190));
	obj_list.push_back(new A(550, 382));
	obj_list.push_back(new A(550, 165));
	return obj_list;
}