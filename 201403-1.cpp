#include<iostream>
using namespace std;

int main(){
	int n, temp, result = 0;
	cin >> n;
	int arr[1001] = {0};
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(temp < 0){
			temp = -temp;
		}
		if(arr[temp]){
			result++;
		} else {
			arr[temp]++;
		}
	} 
	cout << result << endl;
	return 0;
}
