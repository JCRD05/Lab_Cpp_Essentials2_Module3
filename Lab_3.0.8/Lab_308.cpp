#include <iostream>

static constexpr int DIVIDE_BY_ZERO = 111;

int main()
{
	constexpr int dividend = 8;
	int divisor{};
	double result{};
	std::cin >> divisor;
	try
	{
		if (divisor == 0) { throw "Invalid input: you can't divide by zero"; }
		result = (double)dividend / divisor;
	}
	catch (const char* errorMsg)
	{
		std::cout << errorMsg;
		return 0;
	}

	std::cout << result << '\n';
}