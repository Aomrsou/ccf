#include<iostream>
using namespace std;
int child[1001] = {0};
int k;

int containK(int num){
	int result = 0;
	if(num % k == 0 || num % 10 == k){
		result = 1;
	}
	return result;
}

int main(){
	int n, num = 1, rest;
	cin >> n >> k;
	rest = n;
	for(int i = 0; i <= n; i++){ // initial child
		child[i] = 1;
	}
	while(rest > 1){
		for(int i = 1; i <= n && rest > 1; i++){
			if(child[i] && containK(num++)){ // 用到了逻辑与的短路 
				child[i] = 0;
				rest--;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(child[i]){
			cout << i << endl;
			break;
		}
	}
	return  0;
}
