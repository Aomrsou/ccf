#include<iostream>
using namespace std;
#define ROW 20
#define COL 5

int seat[ROW+1][COL+1] = {{0}};

void plug (int num){ // 最后一排都没有空位的时候执行该插入 
	for(int i = 1; i <= ROW; i++){
		for(int j = 1; j <= COL; j++){
			if(!num){
				return ;
			} else if(!seat[i][j]){
				seat[i][j] = 1;
				cout << ((i - 1) * COL) + j << " ";
				--num;
			}
		}
	}
} 

void manage(int num){
	if(seat[ROW][COL - num + 1]){ // 最后一排都满了，直接插空排 ★注意边界！！ 
		plug(num);
	} else {
		for(int i = 1; i <= ROW; i++){
			for(int j = 1; j <= COL - num + 1; j++){
				if(!seat[i][j]){
					while(num--){
						seat[i][j] = 1;
						cout << ((i - 1) * COL) + j << " ";
						j++;
					}
					return ;
				}
			}
		}
	}
}


int main(){
	int n, temp;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		manage(temp);
		cout << endl;
	}
	return 0;
}

/*
22
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 2
这个样例大可爱看看能不能过
*/
