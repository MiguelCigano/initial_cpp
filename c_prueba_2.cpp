#include <iostream>
#include <algorithm>
#include <vector>

/* Revisar este código, se ve interesante, es sobre cosas que comprar con presupuestos*/

using namespace std;

int N, B, A[100000];

void solve() {
	cin >> N >> B;
	for(int i=0; i<=N; ++i){
		cin >> A[i];
	}
	sort(A, A+N);
	int ans = 0;

	for(int i=0; i<=N; ++i){
		if(B>=A[i]){
		B-=A[i];
		++ans;
		}
	}
	cout<<ans<< "\n";
}	



int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t, i=1;
	cin >> t;
	while(t--){
		cout<<"Case #"<<i<< ": ";
		solve();
		++i;
	}	
}


