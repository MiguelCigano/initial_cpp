#include<iostream>
#include<vector>

void print_result(const std::vector<double> &X) {
    for(const auto &x : X) {
        std::cout << x << " " << std::endl;
    }
}

std::vector<double> multiply(const std::vector<std::vector<double>> &A, const std::vector<double> &X) {

	std::vector<double> result(A.size(), 0.0);

	for (size_t i = 0; i < A.size(); ++i)         
		for (size_t j = 0; j < X.size(); ++j)             
			result[i] += A[i][j] * X[j];     
	
	return result; 
}

int main() {
    std::vector<std::vector<double>> A = {{1, 2}, {3, 4}};
    std::vector<double> X = {1, 2, 3};
    
    std::vector<double> result = multiply(A, X);
    print_result(result);

    return 0;
}