//AbstractGeometry
#include<Windows.h>
#include<iostream>
using namespace std;

namespace Geometry
{
	enum Color //enum (Enumeration) -��� ������������. ������������ - ��� ����� ������������� ��������
	{
		RED = 0x000000FF,
		GREEN = 0x0000FF00,
		BLUE = 0x00FF0000,

		CONSOLE_BLUE = 0x99,
		CONSOLE_GREEN = 0xAA,
		CONSOLE_RED = 0xCC,
		CONSOLE_DEFAULT = 0x07,

	};

#define SHAPE_TAKE_PARAMETERS unsigned int start_x,unsigned int start_y,unsigned int line_width,Color color
#define SHAPE_GIVE_PARAMETERS  start_x, start_y, line_width,color
	class Shape // ��� ����������� �����
	{
	protected: // ��������� �������� � ���� ����� ����� ����� ���������� �������� � �������� ������� ��� ��� � ��� �������
		Color color;
		// ��� ����������, �� ������� ����� ���������� ������
		unsigned int start_x;
		unsigned int start_y;
		//� ����� ����. �������� ���������� �������� � ��������
		//������ ��������� ������ ��������� � ����� ������� ����.
		unsigned int line_width;// ������� �����, ������� ����� ���������� ������ ������
	public:
		Shape(unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
		}
		virtual ~Shape() {} // ������ ������ �������� ������ ����������
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;

		Color get_color()const
		{
			return color;
		}
		void set_color(Color color)
		{
			this->color = color;
		}
		unsigned int get_start_x()const
		{
			return start_x;
		}
		unsigned int get_start_y()const
		{
			return start_y;
		}
		unsigned int get_line_width()const
		{
			return get_line_width();
		}
		void set_start_x(unsigned int start_x)
		{
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			this->start_y = start_y;
		}
		void get_line_width(unsigned int line_width)
		{
			this->line_width = line_width;
		}

		virtual void info()const
		{
			cout << "������� ������: " << get_area() << endl;
			cout << "�������� ������: " << get_perimeter() << endl;
			draw();
		}
	};



	//class Square : public Shape
	//{
	//	double side;//����� �������
	//public:
	//	Square(double side, Color color) :Shape(color) // ����������� ��������
	//	{
	//		set_side(side);
	//	}
	//	virtual ~Square() {}
	//	double get_area()const override
	//	{
	//		return side * side;
	//	}
	//	double get_perimeter()const override
	//	{
	//		return side * 4;
	//	}
	//	void draw()const override
	//	{
	//		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//		SetConsoleTextAttribute(hConsole, get_color());
	//		for (int i = 0; i < side; i++)
	//		{
	//			for (int i = 0; i < side; i++)
	//			{
	//				cout << "* ";
	//			}
	//			cout << endl;
	//		}
	//		SetConsoleTextAttribute(hConsole, Color::CONSOLE_DEFAULT);
	//	}
	//	double get_side()const
	//	{
	//		return side;
	//	}
	//	void set_side(double side)
	//	{
	//		this->side = side;
	//	}
	//	void info()const override
	//	{
	//		cout << typeid(*this).name() << endl;
	//		cout << "����� �������: " << side << endl;
	//		Shape::info();
	//	}
	//};

	class Rectangle :public Shape
	{
		double width;
		double height;
	public:
		Rectangle(double width, double height, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_width(width);
			set_height(height);
		}
		~Rectangle() {}
		double get_area()const override
		{
			return width * height;
		}
		double get_perimeter()const override
		{
			return (width + height) * 2;
		}
		void draw()const override
		{
			/*for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}*/
			HWND hwnd = GetConsoleWindow();// 1-�������� ���������� ���� �������
			                               // HWND - Handler to Window (���������� ��� ���������� ����)
			HDC hdc = GetDC(hwnd);            //2  �������� �������� ����������
										// DC - ��, �� ��� �� ����� ��������
			HPEN hPen = CreatePen(PS_SOLID, 5, get_color());// 3 ������� ��������, pen ������ ������ ������
														//PS_SOLID �������� �����
														// 5 ������� ����� � ��������
			HBRUSH hBrush = CreateSolidBrush(get_color());

			//5 �������� ��� � �� ��� ��������
			SelectObject(hdc,hPen);
			SelectObject(hdc,hBrush);

			// 6 ������ �������������:
			::Rectangle(hdc, start_x,start_y,800,350);// :: - ���� ����������� ������������ ����
			//start_x , start_y -  ���������� �������� ������ ����
			// 800,350, - ��� ���������� ������� ������� ����
			//7 ����������� ������
			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);

		}
		double get_width()const
		{
			return width;
		}
		double get_height()const
		{
			return height;
		}
		void set_width(double width)
		{
			this->width = width;
		}
		void set_height(double height)
		{
			this->height = height;
		}

		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "������: " << get_width() << endl;
			cout << "������: " << get_height() << endl;
			Shape::info();
		}

		
	};

	class Square :public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) :Rectangle(side, side,SHAPE_GIVE_PARAMETERS) {}

	};
}
void main()
{
	setlocale(LC_ALL, "");
	Geometry::Square square(50,300,50,5,Geometry::Color::BLUE);
	/*cout << "����� ������� ��������: " << square.get_side() << endl;
	cout << "������� ��������: " << square.get_area() << endl;
	cout << "�������� ��������: " << square.get_perimeter() << endl;
	square.draw();*/
	square.info();
	
	Geometry::Rectangle rect(15, 8,500,50,3, Geometry::Color::BLUE);// ������ Geometry::
	// ����� ����� ���� ������������ ���������� �-��� (Windows.h) Rectangle
	// ������������ ��� �� main � �������� ��� � ������� namespace Geometry 
	rect.info();
}