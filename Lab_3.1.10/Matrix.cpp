#include "Matrix.h"
#include <iostream>
#include <random>

void Matrix::print() const
{
	for (int row = 1; row <= m_rowDimension; row++) 
	{
		for (int column = 1; column <= m_columnDimension; column++) 
		{
			std::cout << at(row, column) << "\t";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

const double& Matrix::at(const int row, const int column) const
{
	const bool OUT_OF_RANGE = row < 1 || row > m_rowDimension || column < 1 || column > m_columnDimension;

	if (OUT_OF_RANGE) { throw std::out_of_range("index out of matrix range"); }

	return m_values[(row - 1) * m_columnDimension + (column - 1)];
}

double& Matrix::at(const int row, const int column)
{
	const bool OUT_OF_RANGE = row < 1 || row > m_rowDimension || column < 1 || column > m_columnDimension;

	if (OUT_OF_RANGE) { throw std::out_of_range("index out of matrix range"); }

	return m_values[(row - 1) * m_columnDimension + (column - 1)];
}

void Matrix::setValue(const double value, const int row, const int column)
{
	const bool OUT_OF_RANGE = row < 1 || row > m_rowDimension || column < 1 || column > m_columnDimension;

	if (OUT_OF_RANGE) { throw std::out_of_range("index out of matrix range"); }

	m_values[(row - 1) * m_columnDimension + (column - 1)] = value;
}

void Matrix::fill()
{
	// Create a random device to obtain a seed
	std::random_device random;

	// Seed a Mersenne Twister engine
	std::mt19937 gen(random()); 

	// Create a uniform integer distribution for numbers between 0 and 9
	std::uniform_int_distribution<> distrib(0, 9);

	for (size_t i = 0; i < m_values.size(); ++i)
	{
		m_values[i] = distrib(gen);
	}
}

void Matrix::fill(const double value)
{
	for (size_t i = 0; i < m_values.size(); ++i)
	{
		m_values[i] = value;
	}
}

void Matrix::fill(const Matrix& other)
{
	const bool DIFFERENT_DIMENSIONS = m_rowDimension != other.getRowDimension() || m_columnDimension != other.getColumnDimension();

	if (DIFFERENT_DIMENSIONS) { throw matrix_exception("different matrices dimensions"); }

	m_values = other.m_values;
}

void Matrix::add(const Matrix& other)
{
	const bool DIFFERENT_DIMENSIONS = m_rowDimension != other.getRowDimension() || m_columnDimension != other.getColumnDimension();

	if (DIFFERENT_DIMENSIONS) { throw matrix_exception("different matrices dimensions"); }

	for (size_t i = 0; i < m_values.size(); ++i)
	{
		m_values[i] += other.m_values[i];
	}
}

Matrix Matrix::operator+(const Matrix& other) const
{
	Matrix result = *this;

	result.add(other);

	return result;
}
