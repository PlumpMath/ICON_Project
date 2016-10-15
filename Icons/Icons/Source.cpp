#include <vector>
#include "window.h"
#include "init.h"
#include "geo_obj.h"
#include "line.h"
#include "box.h"
#include "circle.h"


int main(void)
{
	windowc my_window;

	while (!glfwWindowShouldClose(my_window.window))
	{
		for (auto &itr : init())
		{
			itr->draw(my_window);
		}
		my_window.postprocess();
	}
}