#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>

class matrix_exception : public std::runtime_error
{
public:
	matrix_exception(const char* msg) : runtime_error(msg) {}
};

class Matrix
{
private:
	int m_rowDimension;
	int m_columnDimension;
	std::vector<double> m_values;

public:
	// Constructors
	Matrix(const int rowDimension, const int columnDimension) :
		m_rowDimension(rowDimension), m_columnDimension(columnDimension)
	{
		if (rowDimension < 1 || columnDimension < 1)
		{
			throw std::invalid_argument("invalid input, the matrix dimensions should be higher than zero.");
		}
		m_values.resize(rowDimension * columnDimension);
	}

	// Getters
	inline int getRowDimension() const { return m_rowDimension; }
	inline int getColumnDimension() const { return m_columnDimension; }

	// Methods
	void print() const;
	const double& at(const int row, const int column) const;
	double& at(const int row, const int column);
	void setValue(const double value, const int row, const int column);
	void fill();
	void fill(const double value);
	void fill(const Matrix& other);
	void add(const Matrix& other);
	Matrix operator+(const Matrix& other) const;
};

#endif 