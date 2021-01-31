#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int n, a, b, num;
long long result = 0;

typedef struct{
	int index;
	int value;
}Vector;

bool cmpByIndex(Vector a, Vector b){
	int result = 0;
	if(a.index != b.index){
		result = a.index < b.index;
	} else {
		result = a.value < b.value;
	}
	return result;
}

int main(){
	cin >> n >> a >> b; // 两个n纬向量 非零值个数为a和b 
	num = a + b;
	Vector *arr = (Vector *)malloc(sizeof(Vector) * num);
	for(int i = 0; i < num; i++){
		cin >> arr[i].index >> arr[i].value;
	}
	sort(arr, arr + num, cmpByIndex);
	for(int i = 1; i < num; i++){
		if(arr[i].index == arr[i - 1].index){
			result += (arr[i].value * arr[i - 1].value);
		}
	}
	cout << result << endl;
	return 0;
} 

/*
10 3 4
4 5
7 -3
10 1
1 10
4 20
5 30
7 40

*/
