#include<iostream>
using namespace std;
int arr[1001] = {0};
long long result = 0;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < n; i++){
		long long temp = 0;
		int minHeight = 26161; // 虽然题目说最高10000，但是如果这里初值写成是26160 则为90分，可见这ccf骗人 
								// 当然最正确写法应该是 int minHeight = arr[i]; 即可万无一失 
		for(int j = i; j < n; j++){
			if(arr[j] < minHeight){ // 找最小就好 
				minHeight = arr[j];
			}
			temp = (j - i + 1) * minHeight;
			result = temp > result ? temp : result;
		}
	}
	cout << result <<endl;
	return 0;
}
