#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int sale[n] = {0};
	int result[n] = {0};
	for(int i = 0; i < n; i++){
		cin >> sale[i];
	}
	result[0] = (sale[0] + sale[1])/2;
	for(int i = 1; i < n-1; i++){
		result[i] = (sale[i-1] + sale[i] + sale[i+1])/3;
	}
	result[n-1] = (sale[n-1] + sale[n-2])/2;
	for(int i = 0; i < n - 1; i++){
		cout << result[i] << " ";
	}
	cout << result[n-1] << endl;
	return 0;
} 
