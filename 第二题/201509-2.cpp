#include<iostream>
using namespace std;
int arr[2][12] = {
{31,28,31,30,31,30,31,31,30,31,30,31},
{31,29,31,30,31,30,31,31,30,31,30,31}
};
int isLeapYear(int year){
	int result = 0;
	if(((year % 4 == 0) && (year % 100 != 0)) 
		|| (year % 400 == 0)){
			result = 1;
	}
	return result;
}
int main(){
	int year, day, remain, num = 0, month = 1;
	cin >> year >> day;
	remain = day;
	int leap = isLeapYear(year);
	while(remain > arr[leap][num]){
		remain -= arr[leap][num++];
		month++;
	}
	cout << month << endl << remain << endl;
	return 0;
}
