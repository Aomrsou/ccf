#include<iostream>
using namespace std;

int main(){
	int n = 0,result = 0,store = 0;
	while(cin >> n){
		if(n == 1){
			store = 1;
		} else if (n == 2) {
			if(store == 1){
				store = 0;
			}
			store += 2;
		}else if(!n){
			break;
		}
		result += store;
	}
	cout << result;
	return 0;
}
