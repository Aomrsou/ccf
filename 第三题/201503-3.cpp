#include<iostream>
using namespace std;
int arr[210][367] = {{0}};
int a, b, c, y1, y2, temp; // a月的第b个星期c 建议玥宝不要用abc，我有个字母记错了，查了半天，血的教训  
int week = 2, isLeap = 0, day = 0;
int leapYear[2][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
}; 

int isLeapYear(int year){
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

void fun(int year, int startDay, int endDay){
	int num = 0;
	for(int i = startDay; i <= endDay; i++){
		if(arr[year - 1850][i] == c){
			num++;
		}
		if(num == b){
			cout << year << "/";
			if(a < 10) cout << "0";
			cout << a << "/";
			if(i - startDay + 1 < 10) cout << "0";
			cout << i - startDay + 1 << endl;
			break;
		}
	}
	if(num < b){
		cout << "none" << endl;
	}
}

int main(){
	cin >> a >> b >> c >> y1 >> y2;
	for(int i = 1850; i <= 2050; i++){ // 打表 必须从这开始 
		isLeap = isLeapYear(i);
		temp = i - 1850;
		for(int i = 1; i <= 365 + isLeap; i++){
			arr[temp][i] = week++;
			week = (week == 8) ? 1 : week;
		}
	}
	for(int i = y1; i <= y2; i++){
		isLeap = isLeapYear(i);
		day = 0;
		for(int j = 0; j < a - 1; j++){
			day += leapYear[isLeap][j];
		}
		fun(i, day + 1, day + leapYear[isLeap][a-1]);
	} 
	return 0;
} 
