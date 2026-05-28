#include <iostream>
#include <algorithm>
#include <vector>

// Check this code, looks like interesting

int N, B, A[100000];

void fn_solve() {
	std::cin >> N >> B;
	for (int i = 0; i <= N; ++i) {
		std::cin >> A[i];
	}
	std::sort(A, A+N);
	int ans = 0;

	for (int i = 0; i <= N; ++i) {
		if (B >= A[i]) {
			B -= A[i];
			++ans;
		}
	}
	std::cout << ans << std::endl;
}	

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t, i=1;
	std::cin >> t;
	while(t--){
		std::cout<<"Case # "<< i << ": " << std::endl;
		fn_solve();
		++i;
	}	
}


