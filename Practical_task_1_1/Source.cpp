/*#include <iostream>
#include <string>
#include <vector>
#include <cassert>

class Sandwich
{
private:
	std::string m_string;
	int m_length;
public:
	Sandwich(std::string& string) :
		m_string(string)
	{
		m_length = 0;
		//assert(string != nullptr);
		while (string[m_length] != '\0')
		{
			++m_length;
		}
		//++m_length;
	}
	
	int getLength()
	{
		return m_length;
	}

	char& operator[] (int index)
	{
		if (index < getLength())
		{
			return m_string[index];
		}
	}

	friend std::ostream& operator<<(std::ostream & out, const Sandwich &sandwich)
	{
		return out << sandwich.m_string;
	}

};

bool Check(Sandwich &sandwich)
{
	bool alpha{false};
	bool beta{false};
	bool tetta{false};
	bool gamma{false};
	int min{0};
	int max{0};

	for (int i = 0; i < sandwich.getLength() - 1; ++i)
	{
		if(sandwich[i] == sandwich[sandwich.getLength() - 1 - i] && (i != sandwich.getLength() - 1 - i))
		{
			alpha = true;
			min = i;
			max = sandwich.getLength() - 1 - i;
		} 
		//while (sandwich[i] == sandwich[sandwich.getLength() - 1 - i]);
	}

	


		if (sandwich[min] != sandwich[min + 1])
		{
			tetta = true;
		}

		if (alpha == true && tetta == true )
		{
			gamma = true;
		}
	

	return gamma;
}

int main()
{
	std::cout << "Enter your string: ";

	std::string string_temp("");
	std::cin >> string_temp;

	Sandwich sandwich(string_temp);

	std::cout << "isIcecreamSandwich (" << sandwich << ") -> " << Check(sandwich) << std::endl;

	system("pause");
	return 0;
}*/

#include <iostream>
#include <vector>

std::vector<int> array_vector;
int i;
char b;
char temp1;
bool repeat{ false };

class Array
{
private:
	std::vector<int> m_array;
	int m_length;
public:
	Array() {}

	Array(std::vector<int> array) : m_array(array)
	{
		m_length = m_array.size();
	}

	int operator[](const int index)
	{
		return m_array[index];
	}

	friend std::istream & operator >> (std::istream & in, const Array &array)
	{
		for (int i = 0; i < array.m_length; ++i)
		{
			in >> array;
		}
		return in;
	}

	friend bool operator<(const Array &array, int k)
	{
		for (int i = 0; i < array.m_length; ++i)
		{
			return array.m_array[i] < k;
		}
	}

	friend bool operator<(const Array &array1, const Array &array2)
	{
		for (int i = 0; i < array1.m_length; ++i)
		{
			return array1.m_array[i] < array2.m_array[i];
		}
	}

	bool getBool()
	{
		bool a{false};
		for (int i = 0; i < m_length; ++i)
		{
			if (m_array[i] < 0)
				a = true;
		}
		return a;
	}

	int getMinValue(Array &array);
	void swap(int a, int b);
};



int Array::getMinValue(Array &array)
{
	for (int startIndex = 0; startIndex < array.m_length - 1; ++startIndex)
	{
		int minIndex = startIndex;
		for (int CurrentIndex = startIndex + 1; CurrentIndex < array.m_length; ++CurrentIndex)
		{
			if (array.m_array[CurrentIndex] < array.m_array[minIndex])
			{
				array.swap(array.m_array[CurrentIndex], array.m_array[minIndex]);
				minIndex = CurrentIndex;
			}
		}
		return array.m_array[minIndex];
	}
}

void Array::swap(int a, int b)
{
	int temp{0};
	a = b;
	b = temp;
	temp = a;
}

void Function_for_input()
{
	do
	{
		std::cout << "Enter your array, please: ";
		std::cin >> i;
		array_vector.push_back(i);
		std::cout << "Have you inputted numbers yet?(T/F)";
		std::cin >> b;
	} while (b == 'T');
}

int main()
{
	/*std::cout << "Enter your array, please: ";
	std::cin >> i;*/
	//array_vector.push_back(i);

	Function_for_input();
	
	Array array(array_vector);

	if (array.getBool())
	{
		std::cout << "You entered incorrect array! Please repeat you trying." << std::endl;
		array_vector.clear();
		Function_for_input();
	}

	std::cout << "Min index of your array is: " << array.getMinValue(array) << "." << std::endl;

	std::cout << "Did you want to continue? (T/F)";
	std::cin >> temp1;
	if (temp1 == 'T')
	{
		Function_for_input();
	}
	
	system("pause");
	return 0;
}
