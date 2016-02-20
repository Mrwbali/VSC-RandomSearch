// Random search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "vector"
#include "iostream"

#include "Fcs.h"

int _tmain(int argc, _TCHAR* argv[])
{	
	int iteration_i = 200;
	double size_of_rand = 8;
	std::vector<Solution>solutions;
	std::vector<double> X = {15.6, 48.85, 10 };
	std::vector<double> Y;
	Solution solution;
	std::cout << numero_uno_x(X) << std::endl;
	std::cout << numero_due_x(X) << std::endl;
	std::cout << numero_tre_x(X) << std::endl;

	solution.result_x_ = numero_uno_x(X);
	solution.xes = X;
	solutions.push_back(solution);

	for (int i = 0; i <= iteration_i; i++)
	{
		Y = random_x(X, size_of_rand);
		if(numero_uno_x(Y) < solutions.at(solutions.size()-1).result_x_)
		{
			Solution temp;
			temp.result_x_ = numero_uno_x(Y);
			temp.xes = Y;
			solutions.push_back(temp);
		}
		
	}
	for (auto k : solutions)
	{
		printVector(k.xes);
		std::cout << k.result_x_ << std::endl;
	}
	getchar();
	return 0;
}