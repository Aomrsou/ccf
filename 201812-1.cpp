#include<iostream>
using namespace std;

int main(){
	long long r,y,g;
	cin >> r >> y >> g;
	int n;
	cin >> n;
	long long t, sum = 0;
	int k = 0;
	for(int i = 0; i < n; i++){
		cin >> k >> t;
		if(k == 0){
			sum += t;
		}else if(k == 1){
			sum += t;
		}else if(k == 2){
			sum += t;
			sum += r;
		}else if(k == 3){
			continue;
		}
	}
	cout << sum;
	return 0;
}
