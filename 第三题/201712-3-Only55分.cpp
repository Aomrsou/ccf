#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string.h>
#include<sstream>
using namespace std;
string str; // 分 小时 几号  几月 星期几 指令
			// 0-59 0-23 1-31 1-12 0-6
// 写在最前 我只得了55分 模拟太费人了 这题考出来大家都没时间写

string m[13]={"","jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
string w[7]={"sun","mon","tue","wed","thu","fri","sat"};
int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef struct{
	int *min;
	int *hour;
	int *day;
	int *month;
	int *week;
	string cmd;
}Cron;

typedef struct{
	int year;
	int month;
	int day;
	int hour;
	int min;
	int week;
}TimeStruct;

int isLeap(int year){
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int getWeekFrom1900(TimeStruct t){
	int result = 4; // 第一天是周四 
	int year = 1970, month = 1, day = 1;
	while(t.year > year){
		result += 365;
		if(isLeap(year)){//闰年 
			result++;
		}
		year++;
	}
	while(t.month > month){
		result += mon[month];
		month++;
	}
	if(isLeap(year) && t.month > 2){
		result++;
	}
	while(t.day > day){
		result++;
		day++;
	}
	result %= 7;
}

TimeStruct getTime(){
	string str;
	cin >> str;
	int y, m, d, h, min;
	y = (str[0] - 48)*1000 + (str[1] - 48)*100 + (str[2] - 48)*10 + (str[3] - 48); 
	m = (str[4] - 48)*10 + (str[5] - 48);
	d = (str[6] - 48)*10 + (str[7] - 48);
	h = (str[8] - 48)*10 + (str[9] - 48);
	min = (str[10] - 48)*10 + (str[11] - 48);
	TimeStruct temp = {y, m, d, h, min};
	temp.week = getWeekFrom1900(temp);
	return temp;
}

TimeStruct addTime(TimeStruct start){
	if(isLeap(start.year)){
		mon[2] = 29;
	} else {
		mon[2] = 28;
	}
	++start.min;
	if(start.min == 60){
		start.min = 0;
		++start.hour;
	}
	if(start.hour == 24){
		start.hour = 0;
		++start.day;
		start.week = (start.week + 1) % 7;
	}
	if(start.day == mon[start.month] + 1){
		start.day = 1;
		++start.month;
	}
	if(start.month == 13){
		start.month = 1;
		++start.year;
	}
	return start;
}

int * opStrGetTime(string min, string start, string end, int maxTime){
	int *minArray = (int *)malloc(sizeof(int) * maxTime);
	memset(minArray, 0, maxTime*sizeof(int));

	int time = -1;
	if(min == "*")
		min = start + "-" + end;
	for(int i = 0; i < min.length(); i++){
		if(min[i] >= 48 && min[i] <= 57){ // 是数字 
			if(time == -1) time = 0;
			time = time * 10 + (min[i] - 48);
		} else if(min[i]==','){ // 逗号分隔的是一个数字 
			minArray[time] = 1;
			time = -1;
		} else if(min[i] == '-'){ // 解析这玩意 
			int timeEnd = 0;
			for(int j = i + 1; j < min.length(); j++){
				if(min[j] >= 48 && min[j] <= 57){ // 是数字 
					timeEnd = timeEnd*10 + (min[j] - 48);
				} else if(min[j]==','){
					i = j;
					break;
				}
			}
			for(int k = time; k <= timeEnd;k++){
				minArray[k] = 1;
			}
			time = -1;
		}
	}
	if(time != -1){
		minArray[time] = 1;
	}
	return minArray;
}

string toLower(string str){
	for(int i = 0; i < str.length(); i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			str[i] +=32;
		}
	}
	return str;
}

string getMonthNum(string str){
	str = toLower(str);
	for(int i = 1; i <= 12; i++){
		int p1 = 0;
		if((p1 = (int)str.find(m[i])) != -1){ // string::npos
			stringstream ss;
			ss << i;
			str.replace(p1, 3, ss.str());
		}
	}
	return str;
}

string getWeekNum(string str){
	str = toLower(str);
	for(int i = 0; i <= 6; i++){
		int p1 = 0;
		if((p1 = (int)str.find(w[i])) != -1){
			stringstream ss;
			ss << i;
			str.replace(p1, 3, ss.str());
		}
	}
	return str;
}

int compareTwo(TimeStruct s, TimeStruct e){
	int result = 0;
	if(s.year == e.year
		&& s.month == e.month
		&& s.day == e.day
		&& s.hour == e.hour
		&& s.min == e.min){
		result = 1;
	}
	return result;
}

int main(){
	int n, s, t; // n行命令 start 闭区间   time 开区间
	cin >> n;
	TimeStruct startTime = getTime();
	TimeStruct endTime = getTime();
	
	Cron cron[20] = {0};
	string str;
	for(int i = 0; i < n; i++){ // 录入cmd 
		cin >> str;
		cron[i].min = opStrGetTime(str, "0", "59", 60);
		cin >> str;
		cron[i].hour = opStrGetTime(str, "0", "23", 24);
		cin >> str;
		cron[i].day = opStrGetTime(str, "1", "31", 32);
		cin >> str;
		str = getMonthNum(str);
		cron[i].month = opStrGetTime(str, "1", "12", 13);
		cin >> str;
		str = getWeekNum(str);
		cron[i].week = opStrGetTime(str, "0", "6", 7);
		cin >> cron[i].cmd;
	}
	while(1){
		if(compareTwo(startTime, endTime)){ // 相同时则为1 不同为0
			break;
		} else {
			for(int i = 0; i < n; i++){
				if(cron[i].min[startTime.min]
				&& cron[i].hour[startTime.hour]
				&& cron[i].day[startTime.day]
				&& cron[i].month[startTime.month]
				&& cron[i].week[startTime.week]){
					cout << startTime.year;
					if(startTime.month < 10) cout << "0";
					cout << startTime.month;
					if(startTime.day < 10) cout << "0";
					cout << startTime.day;
					if(startTime.hour < 10) cout << "0";
					cout << startTime.hour;
					if(startTime.min < 10) cout << "0";
					cout << startTime.min << " ";
					cout << cron[i].cmd << endl;
				}
			}
			startTime = addTime(startTime);
		}
	}
	return 0;
} 

/*
	Miss：
		玥宝没考上的第四天 想她
	Tips：
		今天学一个整形转字符串的方法
		#include<sstream>
		stringstream ss;
		int a;
		ss << a;
		ss.str(); 即为所求	 
		
2 200001010000 200001011100
30 * * * * cmd
30 * * * * cdd
*/
