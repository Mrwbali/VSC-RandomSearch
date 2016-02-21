// Random search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "vector"
#include "iostream"

#include "Fcs.h"

int _tmain(int argc, _TCHAR* argv[])
{	
	int iteration_i, dimension_i, func_i;
	double size_of_rand;
	std::vector<Solution>solutions;
	std::vector<double> X = {15.6, 48.85, 10 };
	std::vector<double> Y;
	Solution solution;
	
	iteration_i = getIterations();
	dimension_i = getDimension();
	size_of_rand = getRandSize();
	func_i = getFunc();
	X = getFirstIteration(dimension_i);

	solution.result_x_ = funcIt(X,func_i);
	solution.xes = X;
	solutions.push_back(solution);


	for (int i = 0; i <= iteration_i; i++)
	{
		Y = random_x(X, size_of_rand);
		if(funcIt(Y,func_i) < solutions.at(solutions.size()-1).result_x_)
		{
			Solution temp;
			temp.result_x_ = funcIt(Y,func_i);
			temp.xes = Y;
			solutions.push_back(temp);
		}
		std::cout << i << std::endl;
		
	}
	for (auto k : solutions)
	{
		printVector(k.xes);
		std::cout << k.result_x_ << std::endl;
	}


	getchar();
	getchar();
	return 0;
}