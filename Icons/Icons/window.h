#pragma once
#include <GLFW/glfw3.h>
#include <iostream> 

class windowc
{
public:

	double xpos, ypos; 
	const int width = 640, height = 480;
	float *pixels;
	GLFWwindow* window;

	windowc(): window(nullptr),pixels(nullptr)
	{
		init();
	}

	~windowc()
	{
		if (pixels != nullptr) delete[] pixels;
		std::cout << "des" << std::endl;
		glfwTerminate();
	}

	virtual void init()
	{
		pixels  = new float[width*height * 3];
		std::fill_n(pixels, width*height * 3, 1.0f);

		/* Initialize the library */
		if (!glfwInit())
		{ 
			exit(1);
		} 

		/* Create a windowed mode window and its OpenGL context */
		window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			exit(1);
		}

		glfwMakeContextCurrent(window);
	}
	

	void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
	{
		pixels[(i + width* j) * 3 + 0] = red;
		pixels[(i + width* j) * 3 + 1] = green;
		pixels[(i + width* j) * 3 + 2] = blue;
	}
	void drawLine(int x1, int y1, int x2, int y2)
	{
		int addX, addY;
		int counter = 0;

		int dx = x2 - x1;
		int dy = y2 - y1;


		//음수 방향으로 진행될 경우
		if (dx < 0)
		{
			addX = -1;
			dx = -dx;
		}
		else
		{
			addX = 1;
		}

		//음수 방향으로 진행될 경우
		if (dy < 0)
		{
			addY = -1;
			dy = -dy;
		}
		else
		{
			addY = 1;
		}

		int x = x1;
		int y = y1;

		//dx >= dy 일 경우( 기울기 < 1) y의 조건이 만족하면 y를 1증가시킨다
		if (dx >= dy)
		{
			for (int i = 0; i < dx; i++)
			{
				//x를  1증가 시키고 dy만큼 Count 증가
				x += addX;
				//x의 증가값만큼 Count 증가
				counter += dy;

				//증가하는 y값 보다 크다면
				if (counter >= dx)
				{
					// y를 1증가 시키고 Count를 초기화한다
					y += addY;
					counter -= dx;
				}
				drawPixel(x, y, 1.0f, 0.0f, 0.0f);
			}
		}
		//dx < dy 일 경우( 기울기 > 1) x의 조건이 만족하면 y를 1증가시킨다
		else
		{
			for (int i = 0; i < dy; i++)
			{
				//y를  1증가 시키고 dx만큼 Count 증가
				y += addY;
				counter += dx;

				//증가하는 y값 보다 크다면
				if (counter >= dy)
				{
					// x를 1증가 시키고 Count를 초기화한다
					x += addX;
					counter -= dy;
				}
				drawPixel(x, y, 1.0f, 0.0f, 0.0f);
			}
		}
	}
	void drawcircle(const int &x_center, const int &y_center, const int& radius, int xpos, int ypos)
	{ 
		for (int x = 0; x <640; x++)
			for (int y = 0; y < 480; y++)
			{
				const double f = (x - x_center)*(x - x_center) + (y - y_center)*(y - y_center) - radius * radius;
				double isin = (xpos - x_center)*(xpos - x_center) + ((480-ypos) - y_center)*((480 - ypos) - y_center) - radius * radius;

				if (f < 150 && f > -150)
				{
					if (isin < 100 )
					{
						drawPixel(x, y, 0.0f, 0.0f, 1.0f);
					}
					else drawPixel(x, y, 1.0f, 0.0f, 0.0f);
				}
			}

	}

	void postprocess()
	{ 
		glfwGetCursorPos(window, &xpos, &ypos );
		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
};