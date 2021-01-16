#include<iostream>
using namespace std;

int arr[1001] = {0};
int main(){
	int n, temp, max, index, num = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(!arr[temp]){
			num++;
		}
		arr[temp]++;
	}
	for(int i = 0; i < num; i++){
		max = 0;
		for(int i = 1; i <= 1000; i++){
			if(arr[i] && arr[i] > max){
				max = arr[i];
				index = i;
			}
		}
		cout << index << " " << max << endl;
		arr[index] = 0;
	}
	return 0;
}
/*
	核心思想： 
	开最大的数组，输入的数作为下标，该格加一，最后存的即为次数
	遍历num遍（num为一共出现多少个数） ，每遍找到最大值，输出后赋零 
*/
