//AbstractGeometry
#include<Windows.h>
#include<iostream>
using namespace std;

namespace Geometry
{
	enum Color //enum (Enumeration) -это перечисление. ѕеречисление - это набор целочисленных констант
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
	class Shape // наш абстрактный класс
	{
	protected: // благодар€ протекед к этим пол€м можно будет обращатьс€ напр€мую в дочерних классах без гет и сет методов
		Color color;
		// Ёто координаты, по которым будут выводитьс€ фигура
		unsigned int start_x;
		unsigned int start_y;
		//¬ любой граф. оболочке координаты задаютс€ в пиксел€х
		//Ќачало координат всегда находитс€ в левом верхнем углу.
		unsigned int line_width;// “олщина линии, которой будет рисоватьс€ контур фигуры
	public:
		Shape(unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
		}
		virtual ~Shape() {} // пустые скобки означают пустую реализацию
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
			cout << "ѕлощадь фигуры: " << get_area() << endl;
			cout << "ѕериметр фигуры: " << get_perimeter() << endl;
			draw();
		}
	};



	//class Square : public Shape
	//{
	//	double side;//длина стороны
	//public:
	//	Square(double side, Color color) :Shape(color) // конструктор квадрата
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
	//		cout << "ƒлина стороны: " << side << endl;
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
			HWND hwnd = GetConsoleWindow();// 1-ѕолучаем дескриптор окна консоли
			                               // HWND - Handler to Window (обработчик или дескриптор окна)
			HDC hdc = GetDC(hwnd);            //2  ѕолучаем контекст устройства
										// DC - то, на чем мы будем рисовать
			HPEN hPen = CreatePen(PS_SOLID, 5, get_color());// 3 —оздаем карандаш, pen рисует контур фигуры
														//PS_SOLID сплошна€ лини€
														// 5 толщина линии в пиксел€х
			HBRUSH hBrush = CreateSolidBrush(get_color());

			//5 выбираем чем и на чем рисовать
			SelectObject(hdc,hPen);
			SelectObject(hdc,hBrush);

			// 6 –исуем пр€моугольник:
			::Rectangle(hdc, start_x,start_y,800,350);// :: - знак глобального пространства имен
			//start_x , start_y -  координаты верхнего левого угла
			// 800,350, - это координаты нижнего правого угла
			//7 освобождаем пам€ть
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
			cout << "Ўирина: " << get_width() << endl;
			cout << "¬ысота: " << get_height() << endl;
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
	/*cout << "ƒлина стороны квадрата: " << square.get_side() << endl;
	cout << "ѕлощадь квадрата: " << square.get_area() << endl;
	cout << "ѕериметр квадрата: " << square.get_perimeter() << endl;
	square.draw();*/
	square.info();
	
	Geometry::Rectangle rect(15, 8,500,50,3, Geometry::Color::BLUE);// вводим Geometry::
	// чтобы можно было использовать встроенную ф-цию (Windows.h) Rectangle
	// обворачиваем все до main и помещаем все в область namespace Geometry 
	rect.info();
}