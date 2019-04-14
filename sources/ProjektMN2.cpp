// ProjektMN2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <malloc.h>
#include "Matrix.h"
#include "Matrix_Operations.h"
#include <math.h>

void zadB();
void zadC();
void zadD();

void zadB() {
	int a1 = 10;
	int a2 = -1;
	int a3 = -1;
	int N = 980;
	int f = 1;

	Matrix b(N, 1);
	for (int i = 0; i < N; i++) {
		b(i, 0) = sin((i)*(f + 1));
	}
	//b.draw();
	Matrix m(N, N);
	m.zeros();
	m.fill_diags(a1, a2, a3);
	//m.draw();

	std::cout << "Jacobi" << std::endl;
	//These should be functions not methods
	jacobiMethod(m, b);
	std::cout << "Gauss Seidel" << std::endl;
	//These should be functions not methods
	gaussSeidelMethod(m, b);
	//m.draw();
}

void zadC() {
	int a1 = 3;
	int a2 = -1;
	int a3 = -1;
	int N = 980;
	int f = 1;

	Matrix b(N, 1);
	for (int i = 0; i < N; i++) {
		b(i, 0) = sin((i)*(f + 1));
	}
	//b.draw();
	Matrix m(N, N);
	m.zeros();
	m.fill_diags(a1, a2, a3);
	//m.draw();

	std::cout << "Jacobi" << std::endl;
	//These should be functions not methods
	jacobiMethod(m, b);
	std::cout << "Gauss Seidel" << std::endl;
	//These should be functions not methods
	gaussSeidelMethod(m, b);
	//m.draw();
}

void zadD() {
	int a1 = 3;
	int a2 = -1;
	int a3 = -1;
	int N = 980;
	int f = 1;

	Matrix b(N, 1);
	for (int i = 0; i < N; i++) {
		b(i, 0) = sin((i)*(f + 1));
	}
	//b.draw();
	Matrix m(N, N);
	m.zeros();
	m.fill_diags(a1, a2, a3);
	//m.draw();

	std::cout << "LUDecomp" << std::endl;
	LUdecomp(m, b);
}

int main()
{
	//Use multithreading to do all of these at once? ;)
	zadB();
	zadC();
	zadD();
}
