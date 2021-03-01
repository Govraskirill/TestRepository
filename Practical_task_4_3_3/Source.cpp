#include <iostream>
#include <vector>
#include <stdlib.h>

/*
class conversion
{
private:
double m_length;
public:
conversion(double length) : m_length(length)
{}
double getKm()
{
return m_length*1.0668;
}
};

int main()
{
double l;
std::cout << "Enter your length: ";
std::cin >> l;

conversion conversion(l);
std::cout << l << " verst is " << conversion.getKm() << " km" << std::endl;

system("pause");
return 0;
}
*/


/*class Array_u
{
private:
int m_length;
double *ptr;
public:
Array_u(int length) : m_length(length)
{
ptr = new double[length];
}

void enterValues()
{
std::cout << "Enter your array: ";
for (int i = 0; i < m_length; ++i)
{
double x;
std::cin >> x;
if (x == ' ')
{
continue;
}
else
{
ptr[i] = x;
}
}
}

void getValues()
{
for (int i = 0; i < m_length; ++i)
{
std::cout << ptr[i] << " ";
}
std::cout << std::endl;
}

double getArifm()
{
double sum{ 0 };
for (int i = 0; i < m_length; ++i)
{
sum += ptr[i];
}
return sum / m_length;
}

double getMin()
{
double min{ 0 };
min = ptr[0];
for (int i = 0; i < m_length; ++i)
{
if (ptr[i] < min)
{
min = ptr[i];
}
}
return min;
}

double getMax()
{
double max{ 0 };
max = ptr[0];
for (int i = 0; i < m_length; ++i)
{
if (ptr[i] > max)
{
max = ptr[i];
}
}
return max;
}

friend std::ostream& operator<<(std::ostream &out,  Array_u & array)
{
return out << array;
}

~Array_u()
{
delete[] ptr;
ptr = nullptr;
}
};


int main()
{
std::cout << "Enter length of your array: ";
int length;
std::cin >> length;

Array_u array(length);

array.enterValues();

//array.getValues();

std::cout << "Middle arifmetic is " << array.getArifm() << std::endl;
std::cout << "Min value is " << array.getMin() << std::endl;
std::cout << "Max value is " << array.getMax() << std::endl;

system("pause");
return 0;
}*/

class array
{
private:
	std::vector<int> m_array1;
	std::vector<int> m_array2;
	std::vector<int> m_array3;
public:
	array() {}
	array(std::vector<int> array1, std::vector<int> array2) : m_array1(array1), m_array2(array2)
	{
		for (int i = 0; i < m_array1.size(); ++i)
		{
			m_array3.push_back(m_array1[i]);
		}
		for (int j = 0; j < m_array2.size(); ++j)
		{
			m_array3.push_back(m_array2[j]);
		}
		sort(m_array3);
	}
	void sort(const std::vector<int> &array_temp);
	void swap(int& array1, int& array2);

	void getValue()
	{
		//sort();
		for (int k = 0; k < m_array3.size(); ++k)
		{
			std::cout << m_array3[k] << " ";
		}
		std::cout << std::endl;
		
	}

	/*friend std::ostream & operator << (std::ostream &out, const array& a)
	{
		return out << a.m_array3;
	}*/
};

void array::sort(const std::vector<int> &array_temp)
{
	for (int startIndex = 0; startIndex < m_array3.size() - 1; ++startIndex)

	{
		int minIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < m_array3.size(); ++currentIndex)
		{
			if (m_array3[currentIndex] < m_array3[minIndex])
			{
				minIndex = currentIndex;
				swap(m_array3[startIndex], m_array3[minIndex]);
			}
		}
	}
}

void array::swap(int& array1, int& array2)
{
	int i;

	i = array1;
	array1 = array2;
	array2 = i;
}

int main()
{
	std::vector<int> array1;
	std::vector<int> array2;
	std::vector<int> array3;

	int x;
	int y;

	std::cout << "Enter first array elements: ";

	while (std::cin.peek()!= '\n') // посимвольный ввод до тех пор, пока не будет нажат enter
	{
		std::cin >> x;
		if (x == ' ')
		{
			continue;
		}
		else
		{
			array1.push_back(x);
		}
	}

	std::cin.ignore(32767, '\n');
	std::cin.clear();

	std::cout << "Enter second array elements: ";

	while (std::cin.peek() != '\n') // посимвольный ввод до тех пор, пока не будет нажат enter
	{
		std::cin >> y;
		if (y == ' ')
		{
			continue;
		}
		else
		{
			array2.push_back(y);
		}
	}

	std::cin.ignore(32767, '\n');
	std::cin.clear();

	std::cout << "Your first array is: ";
	for (size_t i = 0; i < array1.size(); i++)
	{
		std::cout << array1[i] << " ";
	}
	std::cout << std::endl;


	std::cout << "Your second array is: ";
	for (size_t i = 0; i < array2.size(); i++)
	{
		std::cout << array2[i] << " ";
	}
	std::cout << std::endl;

	array array_u(array1, array2);
	
	std::cout << "Your common array is: " ;
	array_u.getValue();

	/*for (auto &i: array1)
	{
	array3[i] = array1[i];
	}
	for (int j = 0; j < array2.size(); ++j)
	{
	array3[j + array1.size()] = array2[j];
	}*/

	

	system("pause");
	return 0;
}