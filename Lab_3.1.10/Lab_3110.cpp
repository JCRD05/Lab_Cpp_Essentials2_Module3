#include <iostream>
#include "Matrix.h"

int main()
{
	try
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

		(matrix1 + matrix2).print();
		(matrix1 + matrix3).print();
		(matrix2 + matrix3).print();
	}
	catch (const std::exception& e) { std::cout << e.what() << '\n'; }
}