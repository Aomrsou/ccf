#include<iostream>
using namespace std;

int main(){
	int n, num1 = 0, num2 = 0, max = 0;
	cin >> n;
	cin >> num1;
	n--;
	while(n--){
		cin >> num2;
		if(num1 > num2){
			max = (num1 - num2 > max) ? num1 - num2 : max;
		} else if (num2 > num1){
			max = (num2 - num1 > max) ? num2 - num1 : max;
		}
		num1 = num2;
	}
	cout << max << endl;
	return 0;
}
