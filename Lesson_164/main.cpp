#include <iostream>

class Parent
{
public:
	// Этот метод getThis() возвращает указатель на класс Parent
	virtual Parent* getThis() { std::cout << "called Parent::getThis()\n"; return this; }
	void printType() { std::cout << "returned a Parent\n"; }
};

class Child : public Parent
{
public:
	// Обычно, типы возврата переопределений и виртуальных функций родительского класса должны совпадать.
	// Однако, поскольку Child наследует класс Parent, следующий метод может возвращать Child* вместо Parent*
	virtual Child* getThis() { std::cout << "called Child::getThis()\n";  return this; }
	void printType() { std::cout << "returned a Child\n"; }
};

int main()
{
	Child ch;
	Parent *p = &ch;
	ch.getThis()->printType(); // вызывается Child::getThis(), возвращается Child*, вызывается Child::printType
	p->getThis()->printType(); // вызывается Child::getThis(), возвращается Parent*, вызывается Parent::printType

	std::cout << "Hello world" << std::endl;

	system("pause");
	return 0;
}