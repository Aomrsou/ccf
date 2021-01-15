#include<iostream>
using namespace std;

int containSeven(int num){
	if (num % 7 == 0){
		return 1;
	}
	while(num != 0){
		if(num % 10 == 7){
			return 1;
		}
		num /= 10;
	}
	return 0;
}

int main(){
	int n,count = 0,i = 0;
	int person[4] = {0};
	cin >> n;
	for(int j = 1; count < n; j++){
		i %= 4;
		if(containSeven(j)){
			person[i++] += 1;
			continue;
		}
		i++;
		count++;
	}
	i = 0;
	while(i < 4){
		cout << person[i++] << endl;
	}
	return 0;
} 
