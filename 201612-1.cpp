#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n, result = -1;
	cin >> n;
	int arr[n] = {0};
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int start = 0, end = n - 1;
	while(arr[start] < arr[end]){
		start++;
		end--;
	}
	if((end - start) > -1){
		if((arr[start] > arr[start-1]) 
			&& (arr[start] < arr[end+1])){
			result = arr[start];
		}
	}
	if((end - start + 1) == n){
		result = arr[start];
	}
	cout << result << endl;
	return 0;
} 
