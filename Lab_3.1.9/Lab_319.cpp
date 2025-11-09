#include <iostream>
#include <stdexcept>

class negative_area : public std::runtime_error
{
public:
	negative_area(const char* msg) : runtime_error(msg) {}
};

double squareArea(const int side);

double rectangleArea(const int base, const int height);

int main()
{
	std::cout << "input the square side: ";
	int side{};
	std::cin >> side;

	std::cout << "input the base of the rectangle: ";
	int base{};
	std::cin >> base;

	std::cout << "input the height of the rectangle: ";
	int height{};
	std::cin >> height;

	try
	{
		std::cout << "square area: " << squareArea(side) << '\n';
		std::cout << "rectangle area: " << rectangleArea(base, height) << '\n';
	}
	catch (negative_area& e) { std::cout << e.what(); }
}

double squareArea(const int side)
{
	if (side <= 0) { throw negative_area("Your input is not valid. The area can't be negative."); }
	return static_cast<double>(side) * side;
}

double rectangleArea(const int base, const int height)
{
	if(base <= 0 || height <= 0) { throw negative_area("Your input is not valid. The area can't be negative."); }
	return static_cast<double>(base) * height;
}
