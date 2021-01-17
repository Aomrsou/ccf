#include<iostream>
using namespace std;
int student[1001] = {0};

void toward(int index, int dis){ // 把下标index的格子往前dis个格子 
	int num = student[index];
	for(int i = 0; i < dis; i++){
		student[index - i] = student[index - i - 1];
	}
	student[index - dis] = num;
}
void backward(int index, int dis){ // 把下标index的格子往后dis个格子 
	int num = student[index];
	for(int i = 0; i < dis; i++){
		student[index + i] = student[index + i + 1];
	}
	student[index + dis] = num;
}

int findIndex(int num){ // 找到学号num的下标index 
	int index = 1;
	while(student[index] != num){
		index++;
	}
	return index;
}

int main(){
	int n, m, num, dis;
	cin >> n;
	for(int i = 1; i <= n; i++){
		student[i] = i;
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> num >> dis;
		if(dis < 0){
			toward(findIndex(num), -dis);
		} else {
			backward(findIndex(num), dis);
		}
	}
	for(int i = 1; i <= n; i++){
		cout << student[i] << " ";
	}
	cout << endl;
	return 0;
} 
