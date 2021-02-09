#include<iostream>
#include<cstring>
using namespace std;
char picture[100][100] = {{0}};
bool flag[100][100] = {{0}}; // 每次填充时标记该格已填充 
int m, n, q, op, x1, y1, x2, y2; // m宽 n高 q次画图操作 op操作 


void drawLine(int x1, int y1, int x2, int y2){
	char ch = '|'; // 默认划横线 
	if(x1 > x2){
		x1 = x1 ^ x2;
		x2 = x1 ^ x2;
		x1 = x1 ^ x2; 
	}
	if(y1 > y2){
		y1 = y1 ^ y2;
		y2 = y1 ^ y2;
		y1 = y1 ^ y2;
	}
	if(x1 == x2){ // 本次操作画竖线
		ch = '-';
	}
	for(int i = x1; i <= x2; i++){
		for(int j = y1; j<= y2; j++){
			if((picture[i][j] == '-' && ch == '|') 
			|| (picture[i][j] == '|' && ch == '-')){ //'-' + '|' == 169
				picture[i][j] = '+';
			} else if(picture[i][j] != '+'){ // 非常坑爹 这个点 
				picture[i][j] = ch;
			}
		}
	}
}

void dfs(int x, int y, char ch){
	if(x >= m || y >= n 
	|| x < 0 || y < 0
	|| picture[y][x] == '-' 
	|| picture[y][x] == '|' 
	|| picture[y][x] == '+'
	|| flag[y][x]){ // 停止条件
		return;
	}
	picture[y][x] = ch;
	flag[y][x] = true;
	dfs(x+1, y, ch); // 递归调用 
	dfs(x, y+1, ch);
	dfs(x-1, y, ch);
	dfs(x, y-1, ch);
}

int main(){
	char ch;
	cin >> m >> n >> q;
	memset(picture, '.', sizeof(picture)); // 初始化数组为点点 
	while(q--){ // 0线段 1上下左右填充 
		cin >> op;
		if(op){ // 填充
			memset(flag, 0, sizeof(flag)); // 初始化标记 
			cin >> x1 >> y1 >> ch;
			dfs(x1, y1, ch);
		} else { // 划线 
			cin >> y1 >> x1 >> y2 >> x2;
			drawLine(x1, y1, x2, y2);
		} 
	}
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < m; j++){
			cout << picture[i][j];
		}
		cout << endl;
	}
	return 0;
} 

/*
	Tips:
		这节课玥宝复习一个函数 memset(arr, 填充内容, sizeof(arr))
		可对n维数组 进行自定义初始化 填充 在 #include<cstring>里 
	核心思路：
		线段好画，有个点填的时候可能遇到加号 不管他
		填充的话，用dfs上下左右遍历，标记已经遍历过的点，不然会死循环 
*/
