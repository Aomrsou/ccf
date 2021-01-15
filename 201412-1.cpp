#include<iostream>
using namespace std;

int main(){
	int n, temp, num = 0;
	cin >> n;
	int reader[1001] = {0};
	int result[n] = {0};
	for(int i = 0; i < n; i++){
		cin >> temp;
		reader[temp]++;
		result[num++] = reader[temp];
	}
	cout << result[0];
	for(int i = 1; i < n; i++){
		cout << " " << result[i];
	}
	return 0;
}
