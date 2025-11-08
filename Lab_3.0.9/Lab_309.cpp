#include <iostream>
#include <stdexcept>

class divide_by_zero : std::exception
{
public:
	virtual const char* what() const noexcept 
	{
		return "invalid input: you can't divide by zero.";
	}
};

int main()
{
	std::cout << "Input a dividend: ";
	int dividend{};
	std::cin >> dividend;

	std::cout << "Input a divisor: ";
	int divisor{};
	std::cin >> divisor;

	double result{};
	try
	{
		if (divisor == 0) { throw divide_by_zero(); }
		result = static_cast<double>(dividend) / divisor;
	}
	catch (divide_by_zero& e)
	{
		std::cout << e.what();
		return 0;
	}

	std::cout << result << '\n';
}