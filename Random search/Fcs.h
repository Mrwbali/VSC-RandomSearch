#include "vector"
#include <iostream>
#include <iomanip>
#include <fstream>



struct Solution
{
	std::vector<double> xes;
	double result_x_;
};
struct Limits
{
	double min_d;
	double max_d;
};
struct Settings
{
	std::vector<Limits> limits;
	int iteration_i, dimension_i, func_i, num_of_rand_i;
	double size_of_rand_d;
};

std::vector<double> random_x(std::vector<double> vector, double size_d, std::vector<Limits> limits);
void printVector(std::vector<double> vector);
int getDimension();
int getIterations();
double getRandSize();
int getFunc();
int getNumOfRand();
std::vector<Limits>getLimits(int dimensions_i);
double funcIt(std::vector<double>xes, int func_i);
void toFile(std::vector<Solution>solutions, Settings settings);
std::vector<double> getFirstIteration(int dimension_i);
