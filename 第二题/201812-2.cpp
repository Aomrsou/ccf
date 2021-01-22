#include<iostream>
using namespace std;
long long lightColor[4] = {0}; // 1 红 2 黄 3 绿 
long long r, y, g, n;
long long result = 0;

void switchLight(long long *light, long long time, long long *lightTime){ // 根据所用时间和出发时的灯，返回 当前灯颜色 
	time = -time; // 这三句可以大大缩短运行时间 
	time %= lightColor[0];
	time = -time;
	while(time < 0){
		*light = --(*light) ? *light : 3;
		time += lightColor[*light];
	}
	*lightTime = time;
}


int main(){
	cin >> r >> y >> g >> n;
	lightColor[1] = r;
	lightColor[2] = y;
	lightColor[3] = g;
	lightColor[0] = r + y + g;
	long long initWay[n][2] = {{0}}; // 输入进去的灯的信息 
	for(long long i = 0; i < n; i++){
		cin >> initWay[i][0] >> initWay[i][1];
	}
	for(long long i = 0; i < n; i++){ // 模拟走到每一段路时 灯和时间 的变化 
		if(initWay[i][0]){ // 1 2 3灯 为有红绿灯 
			switchLight(&initWay[i][0], initWay[i][1] - result, &initWay[i][1]);
			if(initWay[i][0] == 1){ // 此刻为红灯，等待剩余秒数 
				result += initWay[i][1];
			} else if (initWay[i][0] == 2){ // 为黄灯，等待剩余秒数+整个红灯 
				result += initWay[i][1];
				result += lightColor[1];
			}
		} else { // 大马路子 直接走
			result += initWay[i][1];
		}
	}
	cout << result << endl;
	return 0;
} 

/*
	核心思想：
		考验玥宝语文能力，他给的初始数据是出发前所有路口的情况
		我们需要先模拟出他走到某一路口时，灯的颜色和剩余时间
		其实模拟完，答案也就出来了。 
	Tips:
		记在小本本上，用int存只有60分，后40分需要用long long存 
	逼叨叨：
		虽然不是你自己试出来的坑，但是也要记住呀，太坑了这种 
*/
