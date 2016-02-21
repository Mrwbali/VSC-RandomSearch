#include "vector"
#include "iostream"

double funcIt(std::vector<double>xes, int func_i);
std::vector<double> random_x(std::vector<double> vector, double size_d);
void printVector(std::vector<double> vector);
int getDimension();
int getIterations();
double getRandSize();
int getFunc();
std::vector<double> getFirstIteration(int dimension_i);
struct Solution
{
	std::vector<double> xes;
	double result_x_;
};