#include <iostream>
#include <stdexcept>

class divide_by_zero : std::exception
{
public:
	virtual const char* what() const noexcept
	{
		return "Are you kidding me?\nYour input is not valid.You can't divide by zero.";
	}
};

double divisionA(const int dividend, const int divisor);

double divisionB(const int dividend, const int divisor);

int main()
{
	std::cout << "input a dividend: ";
	int dividend{};
	std::cin >> dividend;

	std::cout << "input a divisor: ";
	int divisor{};
	std::cin >> divisor;

	double result{};

	// Division function that catches the exception
	result = divisionA(dividend, divisor);
	std::cout << '\n' << result;

	try 
	{
		// Division function that only throws the exception
		result = divisionB(dividend, divisor);
		std::cout << '\n' << result;
	}
	catch (divide_by_zero& e)
	{
		std::cout << '\n' << e.what();
	}
}

double divisionA(const int dividend, const int divisor)
{
	try
	{
		if (divisor == 0) { throw divide_by_zero(); }
		return static_cast<double>(dividend) / divisor;
	}
	catch (divide_by_zero& e)
	{
		std::cout << e.what();
	}
}

double divisionB(const int dividend, const int divisor)
{
	if (divisor == 0) { throw divide_by_zero(); }
	return static_cast<double>(dividend) / divisor;
}