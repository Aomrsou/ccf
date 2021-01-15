#include<iostream>
using namespace std;

int main(){
	int n, result = 0, three = 0, five = 0;
	cin >> n;
	n /= 10;
	if(n > 4){
		five = n/5;
		n -= five*5;
	}
	if(n > 2){
		three = n/3;
		n -= three*3;
	}
	cout << five*2 + three + five*5 + three*3 + n << endl;
	return 0;
} 
