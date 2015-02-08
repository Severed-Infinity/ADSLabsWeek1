#include <iostream>
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::ios;

int main() {

	const double pay_increase = 1.076;
	double annualSalary = 0;
	double monthlySalary = 0;
	double backPay = 0;

	ifstream fileInput("employee_pay_record.txt");
	ofstream fileOutput("employee_pay_record.txt", ios::app);
	
	if (fileInput.is_open())
	{
		cout << "pulling from file" << std::endl;
		fileInput >> annualSalary;
		monthlySalary = annualSalary / 12;
	}

	cout << "annual: "<<annualSalary << std::endl 
		<< "monthly: " <<monthlySalary << std::endl;

	backPay = (monthlySalary * 6) + (annualSalary * 6);
	annualSalary = annualSalary * pay_increase;
	monthlySalary = monthlySalary * pay_increase;
	
	fileOutput <<std::endl<< annualSalary << " : Annual Salary" 
		<< std::endl << monthlySalary << " : Monthly ";

	fileInput.close();
	fileOutput.close();

	system("pause");
	return 0;
}