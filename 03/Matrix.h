#pragma once
#include <vector>
#include <iostream>


class Matrix
{
	using number_of_columns = size_t;
	using number_of_rows = size_t;
	int** matrix;
	number_of_columns columns;
	number_of_rows rows;
	public:
		Matrix(const number_of_columns i,const number_of_rows j);
		Matrix(Matrix& ABC);
		const int getRows() const;
		const int getColumns() const;
		
		class MyVector
		{
			using Len = size_t;
			int* MyVec;
			Len len;
		public:
			MyVector(int* Vec, const Len N);
			int& operator[](const size_t i);
			const int& operator[](const size_t i) const;
			void operator=(const MyVector Vec);
		};
		MyVector operator[](const size_t i);
		const MyVector  operator[](const size_t i) const;
		void operator*=(const int a);
		void operator=(Matrix& Mat);
		bool operator==(const Matrix Matrix) const;
		bool operator>(const Matrix Matrix) const;
		bool operator<(const Matrix Matrix) const;
		friend std::ostream& operator<< (std::ostream& out, const Matrix& point);
		
		~Matrix();

};