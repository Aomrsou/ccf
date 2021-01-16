#include<iostream>
using namespace std;

int main(){
	int n, temp = 0, max = 0, result = 0;
	cin >> n;
	int arr[10001] = {0};
	for(int i = 0; i < n; i++){
		cin >> temp;
		arr[temp]++;
	}
	for(int i = 1; i <= 10000; i++){
		if(arr[i] > max){
			result = i;
			max = arr[i];
		}
	}
	cout << result << endl;
	return 0;
}
