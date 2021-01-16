#include<iostream>
using namespace std;

int main(){
	int n, num1, temp, result = 0;
	cin >> n >> num1;
	n--;
	while(n--){
		cin >> temp;
		if(temp != num1){
			result++;
		}
		num1 = temp;
	}
	cout << result + 1 << endl;
	return 0;
}
