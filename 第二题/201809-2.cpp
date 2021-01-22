#include<iostream>
using namespace std;
const long long L = 1000000;
int arrH[L+1] = {0}; 
int arrW[L+1] = {0}; 

int main(){
	int n, temp1, temp2, max = 0,result = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp1 >> temp2;
		for(int j = temp1; j < temp2; j++){
			arrH[j] = 1;
		}
		max = temp2 > max ? temp2 : max;
	}
	for(int i = 0; i < n; i++){
		cin >> temp1 >> temp2;
		for(int j = temp1; j < temp2; j++){
			arrW[j] = 1;
		}
		max = temp2 > max ? temp2 : max;
	}
	for(int i = 0; i < max; i++){
		if(arrH[i] && arrW[i]){
			result++;
		}
	}
	cout << result << endl;
	return 0;
} 
