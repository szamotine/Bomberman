#pragma once
#include <iostream>
#include <cmath>
#include <fstream>
#include "iMatrix.h"

iMatrix::iMatrix(int Nvalue, int Mvalue) : N(Nvalue), M(Mvalue) {

	// add an extra row and col for optional i=0 and j=0
	p = new int[(N + 1) * (M + 1)];

	if (p == nullptr)
	{
		std::cout << "\nmemory allocation error in iMatrix::iMatrix(...)";
		return;
	}

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			e(i, j) = 0;
		}
	}
}

int& iMatrix::e(int i, int j) {
	int k;
	static int ans = 0;

	if (i<0 || i>N || j<0 || j>M)
	{
		std::cout << "\nerror in iMatrix::e(): out of bounds";
		return ans;
	}

	// add an extra row and col for optional i=0 and j=0
	k = (M + 1) * i + j;

	return p[k];
}

void iMatrix::print() {
	for (int i = 1; i <= N; i++)
	{
		std::cout << "\n" << i << ":\t";
		for (int j = 1; j <= M; j++)
		{
			std::cout << e(i, j) << " ";
		}
		//cout << "\n";
	}

}

void iMatrix::print0() {

	std::cout << "\n \t";
	for (int i = 0; i <= N; i++)
	{
		std::cout << i << " ";
	}

	for (int i = N; i >= 0; i--)
	{
		std::cout << "\n" << i << ":\t";
		for (int j = 0; j <= M; j++)
		{
			std::cout << e(i, j) << " ";
		}
		//cout << "\n";
	}

}

int& iMatrix::get_matrix_value(int input) {

	if (input > (N + 1) * (M + 1))
	{
		throw std::out_of_range("Index error in get_matrix_value: input= " + input);
	}

	return p[input];
}

