#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n, result = 0;
	cin >> n;
	int arr[n] = {0};
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	for(int i = 1; i < n; i++){
		if((arr[i] - arr[i-1]) == 1){
			result++;
		}
	}
	cout << result << endl;
	return 0;
}
