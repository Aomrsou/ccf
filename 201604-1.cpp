#include<iostream>
using namespace std;

int main(){
	int n, result = 0;
	cin >> n;
	int arr[n] = {0};
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i < n-1; i++){
		if((arr[i] > arr[i-1]) && (arr[i] > arr[i+1])){
			result++;
		}
		if((arr[i] < arr[i-1]) && (arr[i] < arr[i+1])){
			result++;
		}
	}
	cout << result << endl;
	return 0;
} 
