#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
	int arr[11] = {0};
	int sum = 0, flag = 1;
	char temp;
	char* str = (char *)malloc(14);
	cin >> str;
	for(int i = 0; i < 13; i++){
		if(str[i] == '-'){
			continue;
		}
		arr[flag++] = str[i] - 48;
	}
	for(int i = 1; i < 10; i++){
		sum += (i * arr[i]);
	}
	sum %= 11;
	if(sum == arr[10]){
		cout << "Right" << endl;
	} else if(sum == 10){
		if(str[12] == 'X'){
			cout << "Right" << endl;
		}
	} else {
		flag = 1;
		for(int i = 0; i < 12; i++){
			if(str[i] == '-'){
				cout << '-';
				continue;
			}
			cout << arr[flag++];
		}
		if(sum == 10){
			cout << 'X' << endl;
		} else {
			cout << sum << endl;
		}
	}
	return 0;
}
