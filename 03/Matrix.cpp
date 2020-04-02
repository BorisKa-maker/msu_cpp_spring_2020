#include "Matrix.h"
Matrix::MyVector::MyVector(int* Vec, const Len N)
{
	this->len = N;
	MyVec = Vec;
}


int& Matrix::MyVector::operator[](const size_t i)
{
	if (i > this->len)
	{
		throw std::out_of_range("");
	}
	else
	{
		return this->MyVec[i];
	}

}
void Matrix::MyVector::operator=(const MyVector Vec)
{
	this->MyVec = Vec.MyVec;
}
const int& Matrix::MyVector::operator[](const size_t i) const
{
	if (i > this->len)
	{
		throw std::out_of_range("");
	}
	else
	{
		return this->MyVec[i];
	}

}

Matrix::Matrix(const number_of_columns i,const number_of_rows j)
{
	this->columns = i;
	this->rows = j;
	this->matrix = new int* [i];
	for (size_t k = 0; k < i; k++)
	{ 
		this->matrix[k] = new int[j];
		if (!this->matrix[k])
		{
			throw std::out_of_range("Init Error!");
			for (size_t m = 0; m < k; m++)
			{
				delete[] this->matrix[k];
			}
			delete[] this->matrix;
			matrix = nullptr;
		}
	}
}

Matrix::Matrix(Matrix& ABC)
{
	this->columns = ABC.columns;
	this->rows = ABC.rows;
	this->matrix = ABC.matrix;
}

const int Matrix::getRows() const
{
	return this->rows;
}

const int Matrix::getColumns() const
{
	return this->columns;
}

const Matrix::MyVector  Matrix::operator[](const size_t i) const
{
	if (i > this->columns)
	{
		throw std::out_of_range("");
	}
	else
	{
		return MyVector(this->matrix[i], this->rows);
	}
}

Matrix::MyVector Matrix:: operator[](const size_t i)
{
	if (i > this->columns)
	{
		throw std::out_of_range("");
	}
	else
	{
		return MyVector(this->matrix[i], this->rows);
	}
}

void Matrix::operator=(Matrix& Mat)
{
	if (this->columns != Mat.columns || this->rows != Mat.rows)
	{
		throw std::out_of_range("");
	}
	else 
	{
		for (size_t i = 0; i < this->columns; ++i)
		{
			for (size_t j = 0; j < this->rows; ++j)
			{
				this->matrix[i][j] = Mat[i][j];
			}
		}
	}
}

void Matrix:: operator*=(const int a)
{
	for (size_t i = 0; i < this->columns; i++)
	{
		for (size_t j = 0; j < this->rows; j++)
		{
			this->matrix[i][j] *= a;
		}
	}
	
}
bool Matrix::operator==(const Matrix Matrix) const
{
	if (this->columns != Matrix.columns || this->rows != Matrix.rows)
	{
		return false;
	}
	else 
	{
		for (size_t i = 0; i < this->columns; ++i)
		{
			for (size_t j = 0; j < this->rows; ++j)
			{
				if (this->matrix[i][j] != Matrix[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}
}

bool Matrix::operator>(const Matrix Matrix) const
{
	if (this->columns != Matrix.columns || this->rows != Matrix.rows)
	{
		throw std::out_of_range("");
	}
	else
	{
		for (size_t i = 0; i < this->columns; ++i)
		{
			for (size_t j = 0; j < this->rows; ++j)
			{
				if (this->matrix[i][j] <= Matrix[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}
}

bool Matrix::operator<(const Matrix Matrix) const
{
	if (this->columns != Matrix.columns || this->rows != Matrix.rows)
	{
		throw std::out_of_range("");
	}
	else
	{
		for (size_t i = 0; i < this->columns; ++i)
		{
			for (size_t j = 0; j < this->rows; ++j)
			{
				if (this->matrix[i][j] >= Matrix[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}
}

std::ostream& operator<< (std::ostream& out, const Matrix& point)
{
	for (size_t i = 0; i < point.columns; i++)
	{
		for (size_t j = 0; j < point.rows; j++)
		{
			out << point[i][j]<<' ';
			
		}
		out <<'\n';
	}
	return out;
}

Matrix::~Matrix()
{
	for (size_t i = 0; i < this->columns; i++)
	{
		delete[] this->matrix[i];
	}
	delete[] this->matrix;
	this->matrix = nullptr;
}