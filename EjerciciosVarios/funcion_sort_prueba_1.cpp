#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int main(){
	
	vector<int> our_vector{3, 5, 6 , 80, 90, 10};
	
	sort(our_vector.begin(), our_vector.end(), greater<int>());
	for (auto& elem : our_vector)
		cout<<elem<< "-";
	
	getchar();
	return 0;
}

