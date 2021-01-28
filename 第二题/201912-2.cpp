#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

typedef struct {
	long long x;
	long long y;
}Point;

int n;
int result[6] = {0};
Point *pointByX = (Point *)malloc(sizeof(Point) * 1001);
Point *pointByY = (Point *)malloc(sizeof(Point) * 1001);



bool cmpByX(Point a, Point b){
	if(a.x != b.x){
		return a.x < b.x;
	} else {
		return a.y < b.y;
	}
}

bool cmpByY(Point a, Point b){
	if(a.y != b.y){
		return a.y < b.y;
	} else {
		return a.x < b.x;
	}
}

bool isOne(long long a, long long b){
	int result = 0;
	if(a < 0){
		a = -a;
	}
	if(b < 0){
		b = -b;
	}
	result = a > b ? a - b : b - a;
	return result == 1;
}

int isGarbage(long long x, long long y){
	int result = 0;
	int score = 0;
	for(int i = 0; i < n && pointByX[i].x <= x + 1; i++){
		if(pointByX[i].x == x && pointByX[i].y != y){
			result += isOne(pointByX[i].y, y);
		}
		if(isOne(pointByX[i].x, x) && isOne(pointByX[i].y, y)){
			score++;
		}
	}
	for(int i = 0; i < n && pointByY[i].y <= y + 1; i++){
		if(pointByY[i].y == y && pointByY[i].x != x){
			result += isOne(pointByY[i].x, x);
		}
	}
	if(result != 4){
		score = 5;
	}
	return score;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> pointByX[i].x;
		cin >> pointByX[i].y;
		pointByY[i].x = pointByX[i].x;
		pointByY[i].y = pointByX[i].y;
	}
	sort(pointByX, pointByX + n, cmpByX);
	sort(pointByY, pointByY + n, cmpByY);
	for(int i = 0; i < n; i++){
		result[isGarbage(pointByX[i].x, pointByX[i].y)]++;
	}
	for(int i = 0; i < 5; i++){
		cout << result[i] << endl;
	}
	return 0;
}

/*
7
1 2
2 1
0 0
1 1
1 0
2 0
0 1

11
9 10
10 10
11 10
12 10
13 10
11 9
11 8
12 9
10 9
10 11
12 11

	核心思想：
		倒是不难，因为10^9太大了，所以不能用空间暴力了
		我选了时间暴力，先把坐标按x排序，再按y排序，分别放到两个数组里
		然后对每一个坐标进行遍历，找他上下左右的点和对角的点
		3个for循环套一块，时间暴力
*/
