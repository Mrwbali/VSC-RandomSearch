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

std::vector<double> random_x(std::vector<double> vector, double size_d)
{
	std::vector<double> res_vector = { 0 };
	res_vector.clear();
	for (auto i : vector)
	{
		res_vector.push_back( ( ( i + size_d ) - ( i - size_d) ) * ( ( double ) rand() / ( double ) RAND_MAX ) + ( i - size_d ) );
	}
	return res_vector;
}

void printVector(std::vector<double> vector)
{
	for (auto i : vector)
	{
		std::cout << i << " ";
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
