#include <iostream>

class Shape
{
public:
	virtual std::ostream & print(std::ostream &out) const = 0;
	
	friend std::ostream & operator <<(std::ostream &out, const Shape &shape)
	{
		return shape.print(out);
	}

	virtual ~Shape(){}
};

//public:
	class Point
	{
	protected:
		int m_x = 0;
		int m_y = 0;
		int m_z = 0;

	public:
		Point(int x, int y, int z)
			: m_x(x), m_y(y), m_z(z)
		{

		}

		friend std::ostream& operator<<(std::ostream &out, const Point &p)
		{
			out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
			return out;
		}
	};

class Triangle : public Shape
{
protected:
	Point t_a;
	Point t_b;
	Point t_c;

public:
	Triangle(const Point &a,const Point &b,const Point &c):
		t_a(a), t_b(b), t_c(c)
	{}

	virtual std::ostream & print(std::ostream &out) const
	{
		return out << "Triangle(" << t_a << ", " << t_b << ", " << t_c << ")" << "\n";
	}
};

class Circle : public Shape
{
protected:
	Point m_point;
	int m_circle;
public:
	Circle(const Point &point, int circle): m_point(point), m_circle(circle)
	{}

	virtual std::ostream & print(std::ostream &out) const
	{
		return out << "Circle(" << m_point << ", radius " << m_circle << ")" << "\n";
	}
};

int main()
{
	Circle c(Point(1, 2, 3), 7);
	std::cout << c << '\n';
	

	Triangle t(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9));
	std::cout << t << '\n';

	system("pause");
	return 0;
}