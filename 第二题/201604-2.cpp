#include<iostream>
using namespace std;
int map[16][10] = {{0}};
int shape[4][4] = {{0}};
int fall(int x, int y){
	int result = 0;
	for(int i = x + 1; i < 15; i++){
		if(!map[i][y]){
			result++;
		} else { // 好坑 记得这里第一次碰到就要停止! 
			break;
		}
	}
	return result;
}
int main(){
	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 10; j++){
			cin >> map[i][j];
		}
	}
	for(int i = 0; i < 10; i++){ // 底边额外增加一行1，有助于简化计算 
		map[15][i] = 1;
	}
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cin >> shape[i][j];
		}
	}
	int n, minFall = 16, temp;
	cin >> n;
	n--;
	for(int i = 0; i < 4; i++){ // 找到下落几格 
		for(int j = 0; j < 4; j++){
			if(shape[i][j]){ // 如果存在，计算该格可以下移几位 
				temp = fall(i, j + n);
				minFall = temp < minFall ? temp : minFall;
			}
		}
	}
	for(int i = 0; i < 4; i++){ // 进行下落 
		for(int j = 0; j < 4; j++){
			if(shape[i][j]){
				map[i+minFall][j+n] = 1;
			}
		}
	}
	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 10; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
/*
	核心思想 ：
		找到下落几格是关键 
*/
