// Random search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "Fcs.h"

int _tmain(int argc, _TCHAR* argv[])
{	
	Settings settings;
	std::vector<Solution>solutions,temp_solutions;
	std::vector<double> X,Y;
	Solution solution,temp_solution;

#pragma region get_data

	settings.iteration_i = getIterations();
	settings.dimension_i = getDimension();
	settings.size_of_rand_d = getRandSize();
	settings.num_of_rand_i = getNumOfRand();
	settings.func_i = getFunc();
	X = getFirstIteration(settings.dimension_i);
	settings.limits = getLimits(settings.dimension_i);

#pragma endregion

	solution.result_x_ = funcIt(X, settings.func_i);
	solution.xes = X;
	solutions.push_back(solution);


	for (int i = 0; i < settings.iteration_i; i++)
	{
		temp_solutions.clear();

		for (int l = 0; l <= settings.num_of_rand_i; l++)
		{
			if (l == 0)
			{
				temp_solution.xes = random_x(X, settings.func_i, settings.limits);
				temp_solution.result_x_ = funcIt(temp_solution.xes, settings.func_i);
				temp_solutions.push_back(temp_solution);
			}
			else
			{
				temp_solution.xes = random_x(X, settings.func_i, settings.limits);
				temp_solution.result_x_ = funcIt(temp_solution.xes, settings.func_i);
				if (temp_solution.result_x_ < temp_solutions.back().result_x_)
				{
					temp_solutions.push_back(temp_solution);
				}				
			}
			
		}

		if (temp_solutions.back().result_x_ < solutions.back().result_x_)
		{
			X = temp_solutions.back().xes;
			solutions.push_back(temp_solutions.back());
		}
					
	}

	std::cout << std::endl;

	for (int k = 0; k < solutions.size(); k++)
	{	
		std::cout << "Iteration: " << std::setw(4) << k << " Values of X :";
		printVector(solutions.at(k).xes);
		std::cout << "Function value: " << solutions.at(k).result_x_ << std::endl;
	}
	toFile(solutions, settings);

	getchar();
	getchar();
	return 0;
}
