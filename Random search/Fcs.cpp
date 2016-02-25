#include "Fcs.h"
# define M_PI	3.14159265358979323846  /* pi */



double funcIt(std::vector<double>xes, int func_i)
{
	switch (func_i)
	{
	case 1: {
				double ans_x = 0;
				for (auto i : xes)
				{
					ans_x = ans_x + (i*i);
				}
				return ans_x; }
		break;
	case 2: {
				double ans_x = 0;
				for (auto i : xes)
				{
					ans_x = ans_x + (i * i - 10 * cos(2 * M_PI * i));
				}
				return(xes.size() * 10 + ans_x);

			}
		break;
	case 3: {
				double ans_x = 0;
				for (auto i : xes)
				{
					ans_x = ans_x + (i * sin(sqrt(abs(i))));
				}
				return(xes.size() * 418.9829 - ans_x);
			}
		break;	
	}
}

std::vector<double> random_x(std::vector<double> xes, double size_d,  std::vector<Limits> limits)
{
	std::vector<double> res_vector = { 0 };
	double temp = 0;
	res_vector.clear();
	double temp_d;
	for (int i = 0; i < xes.size(); i++)
	{
		temp = ((xes.at(i) + size_d) - (xes.at(i) - size_d)) * ((double)rand() / (double)RAND_MAX) + (xes.at(i) - size_d);

		if (temp < limits.at(i).min_d)
		{
			temp = limits.at(i).min_d;
		}

		else if (temp > limits.at(i).max_d)
		{
			temp = limits.at(i).max_d;
		}

		res_vector.push_back( temp );
	}
	return res_vector;
}

void printVector(std::vector<double> vector)
{
	for (auto i : vector)
	{
		std::cout << std::setw(10) << i << " ";
	}
}

int getDimension()
{
	int temp = 0;
	std::cout << "Dimension?" << std::endl;
	std::cin >> temp;
	return temp;
}

int getIterations()
{
	int temp = 0;
	std::cout << "Iterations?" << std::endl;
	std::cin >> temp;
	return temp;
}

double getRandSize()
{
	double temp = 0;
	std::cout << "Size of rand??" << std::endl;
	std::cin >> temp;
	return temp;
}

int getFunc()
{
	int temp = 0;
	std::cout << "Which function 1,2,3?" << std::endl;
	std::cin >> temp;
	return temp;
}

int getNumOfRand()
{
	int temp = 0;
	std::cout << "Number of randoms?" << std::endl;
	std::cin >> temp;
	return temp;
}

std::vector<Limits> getLimits(int dimensions_i)
{
	Limits temp;
	std::vector<Limits> result;
	for (int i = 1; i <= dimensions_i; i++)
	{
		std::cout << "Max of dimesnion : " << i << std::endl;
		std::cin >> temp.max_d;
		std::cout << "Min of dimesnion : " << i << std::endl;
		std::cin >> temp.min_d;
		result.push_back(temp);
	}
	return result;
}

void toFile(std::vector<Solution>solutions,Settings settings)
{
	std::ofstream myfile;
	myfile.open("../Results.txt",std::ios::out);
	myfile << "Iterations:" << settings.iteration_i << " Dimensions:" << settings.dimension_i << " Function:" << settings.func_i << " Number of random:" << settings.num_of_rand_i << " Size of random:" << settings.size_of_rand_d << std::endl;
	for (int k = 0; k < settings.limits.size(); k++)
	{
		myfile << "Dimension " << k + 1 << " Max:" << settings.limits.at(k).max_d << " Min:" << settings.limits.at(k).min_d << std::endl;
	}
	for (auto i : solutions)
	{
		for (auto j : i.xes)
		{
			myfile << j << "; ";
		}
		myfile << i.result_x_ << ";" << std::endl;
	}
	
	myfile.close();
}

std::vector<double> getFirstIteration(int dimension_i)
{
	std::vector<double> temp;
	double temp_d;
	for (int i = 0; i < dimension_i; i++)
	{
		std::cout << "Number " << i + 1 << " in first operation?" << std::endl;
		std::cin >> temp_d;
		temp.push_back(temp_d);
	}
	return temp;
}
