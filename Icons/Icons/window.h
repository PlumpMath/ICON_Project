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


		//���� �������� ����� ���
		if (dx < 0)
		{
			addX = -1;
			dx = -dx;
		}
		else
		{
			addX = 1;
		}

		//���� �������� ����� ���
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

		//dx >= dy �� ���( ���� < 1) y�� ������ �����ϸ� y�� 1������Ų��
		if (dx >= dy)
		{
			for (int i = 0; i < dx; i++)
			{
				//x��  1���� ��Ű�� dy��ŭ Count ����
				x += addX;
				//x�� ��������ŭ Count ����
				counter += dy;

				//�����ϴ� y�� ���� ũ�ٸ�
				if (counter >= dx)
				{
					// y�� 1���� ��Ű�� Count�� �ʱ�ȭ�Ѵ�
					y += addY;
					counter -= dx;
				}
				drawPixel(x, y, 1.0f, 0.0f, 0.0f);
			}
		}
		//dx < dy �� ���( ���� > 1) x�� ������ �����ϸ� y�� 1������Ų��
		else
		{
			for (int i = 0; i < dy; i++)
			{
				//y��  1���� ��Ű�� dx��ŭ Count ����
				y += addY;
				counter += dx;

				//�����ϴ� y�� ���� ũ�ٸ�
				if (counter >= dy)
				{
					// x�� 1���� ��Ű�� Count�� �ʱ�ȭ�Ѵ�
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