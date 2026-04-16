#include <iostream>

void calculate_tax_array(double *salaries, const double tax_rate, const int n) {  
	double net_salary = 0.0;
    double tax = 0.0;
    for (int i = 0; i < n; ++i) {  
		tax = salaries[i] * (tax_rate / 100);
        net_salary = salaries[i] - tax;
        salaries[i] = net_salary;
	}
} 
  
void print_salaries(double *salaries, const int n) {  
	for (int i = 0; i < n; ++i) {  
		std::cout << "Salary "<< (i + 1) << " is: " << salaries[i] << std::endl;  
	}  
	std::cout << std::endl;  
}  
  
int main() {  
	const int n = 3;  
	const double tax_rate = 20.0; // Representa un 20%  
	double salaries[n] = {1500.0, 1200.5, 987.654};  
	  
	calculate_tax_array(salaries, tax_rate, n);  
	print_salaries(salaries, n);  
	  
	return 0;  
}