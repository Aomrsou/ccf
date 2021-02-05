#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

typedef struct {
	string c; // command 指令
	float p; // price 出价
	long long n; // num 股数 
}data;
vector<data>notes;
data temp;
long long maxNum = 0;
long long money[1000001] = {0}; // 出价最多是 1000000 / 100
int resultIndex = 0;

long long successDealNum(int money){
	long long allSell = 0, allBuy = 0;
	for(vector<data>::iterator it = notes.begin(); it != notes.end(); it++){
		string command = (*it).c;
		int price = round((*it).p * 100);
		long long n = (*it).n;
		if(command == "buy" && price >= money){ // 高价买 
			allBuy += n;
		} else if(command == "sell" && price <= money){ // 低价卖 
			allSell += n;
		} 
	}
	return allBuy < allSell ? allBuy : allSell;
}

int main(){
	while(cin >> temp.c){
		if(temp.c == "buy" || temp.c == "sell"){
			cin >> temp.p >> temp.n;
		} else if(temp.c == "cancel"){
			cin >> temp.n;
			notes[temp.n - 1].n = 0; // 撤销第i条记录的股数
			temp.p = 0;
			temp.n = 0;
		} else {
			break;
		}
		notes.push_back(temp);
	}
	for(vector<data>::iterator it = notes.begin(); it != notes.end(); it++){
		if((*it).c == "buy" && (*it).n != 0){ // 所有买的钱 的价格 找出来 
			int index = round((*it).p * 100); // 这必须要用round进位 
			money[index] = 1;
		}
	}
	for(int i = 1; i < 1000001; i++){
		if(money[i]){
			money[i] = successDealNum(i);
			if(maxNum <= money[i]){
				maxNum = money[i];
				resultIndex = i;
			}
		}
	}
	printf("%.2f %lld\n", resultIndex/100.0, maxNum);
	return 0;
} 

/*
	Tips：
		今天玥宝要学 #include<vector>
		他是一个可以存自定义类型的 算可以随机存取的队列吧 详情百度 
	核心思路：
		最后成交价一定是buy中的某一个价格 
		暴力之 最多5000*5000的时间复杂度，就是个O(n^2) 评测老爷机能接受
		价格的处理一定要先乘100用round取整 再除100.0 
		
		round()函数原理为
		x=(int)(x+0.5)    
		
		无限输入数据，停止的方法是输完数据后 Ctrl + Z 再回车 
*/
