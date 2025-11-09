#include <iostream>

class Number
{
private:
	int m_upperLimit;
	int m_lowerLimit;
	int m_value;

public:
	Number(const int number, const int upperLimit, const int lowerLimit) :
		m_value(number), m_upperLimit(upperLimit), m_lowerLimit(lowerLimit) {}

	void add(const int number)
	{
		const bool OUT_OF_LIMIT = m_value + number > m_upperLimit || m_value + number < m_lowerLimit;

		if (OUT_OF_LIMIT) { throw std::runtime_error("Value could exceed limit."); }

		m_value += number;
	}

	void subtract(const int number)
	{
		const bool OUT_OF_LIMIT = m_value - number > m_upperLimit || m_value - number < m_lowerLimit;

		if (OUT_OF_LIMIT) { throw std::runtime_error("Value could exceed limit.\n"); }

		m_value -= number;
	}

	void print() const
	{
		std::cout << m_value << '\n';
	}
};

int main()
{
	std::cout << "input a starting number, lower limit and upper limit, ex: 0 0 10\n";
	int value{};
	int upperLimit{};
	int lowerLimit{};
	std::cin >> value >> lowerLimit >> upperLimit;
	Number number1(value, upperLimit, lowerLimit);

	std::cout << "input another starting number, lower limit and upper limit, ex: 0 0 10\n";
	std::cin >> value >> lowerLimit >> upperLimit;
	Number number2(value, upperLimit, lowerLimit);

	try
	{
		std::cout << "input a value to sum: ";
		std::cin >> value;
		number1.add(value);
	}
	catch (std::exception& e) { std::cout << e.what(); }

	try
	{
		std::cout << "input a value to sum: ";
		std::cin >> value;
		number2.add(value);
	}
	catch (std::exception& e) { std::cout << e.what(); }

	try
	{
		std::cout << "input a value to subtract: ";
		std::cin >> value;
		number1.subtract(value);
	}
	catch (std::exception& e) { std::cout << e.what(); }

	try
	{
		std::cout << "input a value to subtract: ";
		std::cin >> value;
		number2.subtract(value);
	}
	catch (std::exception& e) { std::cout << e.what(); }
}