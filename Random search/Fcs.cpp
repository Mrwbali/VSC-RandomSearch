#include "Fcs.h"
# define M_PI	3.14159265358979323846  /* pi */

double numero_uno_x(std::vector<double>xes)
{
	double ans_x = 0;
	for (auto i : xes)
	{
		ans_x = ans_x + (i*i);
	}
	return ans_x;
}

double numero_due_x(std::vector<double>xes)
{
	double ans_x = 0;
	for (auto i : xes)
	{
		ans_x = ans_x + (i * i - 10 * cos(2 * M_PI * i));
	}
	return(xes.size() * 10 + ans_x);
}

double numero_tre_x(std::vector<double>xes)
{
	double ans_x = 0;
	for (auto i : xes)
	{
		ans_x = ans_x + (i * sin(sqrt(abs(i)))) ;
	}
	return(xes.size() * 418.9829 - ans_x);
}

std::vector<double> random_x(std::vector<double> vector, double size_d)
{
	std::vector<double> res_vector = { 0 };
	res_vector.clear();
	for (auto i : vector)
	{
		res_vector.push_back(((i + size_d) - (i - size_d)) * ((double)rand() / (double)RAND_MAX) + (i - size_d));
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
