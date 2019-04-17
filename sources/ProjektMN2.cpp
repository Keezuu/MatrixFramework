// ProjektMN2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <malloc.h>
#include "Matrix.h"
#include "Matrix_Operations.h"
#include <math.h>
#include <chrono>
#include <ctime>

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


	//Count time taken
	auto start = std::chrono::system_clock::now();

	jacobiMethod(m, b);

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

	std::cout << "Gauss Seidel" << std::endl;
	//These should be functions not methods
	start = std::chrono::system_clock::now();


	gaussSeidelMethod(m, b);


	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
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
	//Count time taken
	auto start = std::chrono::system_clock::now();

	jacobiMethod(m, b);

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout<< "elapsed time: " << elapsed_seconds.count() << "s\n";

	std::cout << "Gauss Seidel" << std::endl;
	//These should be functions not methods
	start = std::chrono::system_clock::now();


	gaussSeidelMethod(m, b);


	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
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


	//Count time taken
	auto start = std::chrono::system_clock::now();

	std::cout << "LUDecomp" << std::endl;

	LUdecomp(m, b);

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

void zadE() {
	//LUDecomp runs very, very long for N's bigger than 2k
	int N[] = { 100, 500, 1000, 2000, 3000, 4000, 5000, 10000 };
	int a1 = 10;
	int a2 = -1;
	int a3 = -1;
	int f = 1;
	for (int i = 0; i < sizeof(N); i++) {
		std::cout << "SIZE: " << N[i] << std::endl;
		Matrix b(N[i], 1);
		for (int j = 0; j < N[i]; j++) {
			b(j, 0) = sin((j)*(f + 1));
		}
		//b.draw();
		Matrix m(N[i], N[i]);
		m.zeros();
		m.fill_diags(a1, a2, a3);

		std::cout << "Jacobi" << std::endl;
		//Count time taken
		auto start = std::chrono::system_clock::now();

		jacobiMethod(m, b);

		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);

		std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

		std::cout << "Gauss Seidel" << std::endl;
		//These should be functions not methods
		start = std::chrono::system_clock::now();


		gaussSeidelMethod(m, b);


		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		end_time = std::chrono::system_clock::to_time_t(end);

		std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

		start = std::chrono::system_clock::now();

		std::cout << "LUDecomp" << std::endl;

		LUdecomp(m, b);

		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		end_time = std::chrono::system_clock::to_time_t(end);

		std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
	}
}

int main()
{
	//Use multithreading to do all of these at once? ;)
	//zadB();
	//zadC();
	//zadD();
	zadE();
}
