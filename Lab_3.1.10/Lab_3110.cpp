#include <iostream>
#include "Matrix.h"

int main()
{
	Matrix matrix1(3, 3);
	matrix1.fill();
	matrix1.print();
	Matrix matrix2(3, 3);
	matrix2.fill();
	matrix2.print();
	Matrix matrix3(2, 2);
	matrix3.fill();
	matrix3.print();
	try
	{
		(matrix1 + matrix2).print();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}

	try
	{
		(matrix1 + matrix3).print();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		(matrix2 + matrix3).print();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}