#include<iostream>
#include<stdlib.h>
using namespace std;

int player = 0, n, pos, att, heal, from, to;
int num[2] = {0, 0};
char *op = (char *)malloc(8);

typedef struct{
	int heal;
	int att;
}Servlant;

Servlant servlant[2][8] = {{0}};

void callServlant(){
	if(pos <= num[player]){ // 有人 右移 
		for(int i = num[player]; i >= pos; i--){
			servlant[player][i + 1] = servlant[player][i];
		}
		servlant[player][pos].att = att;
		servlant[player][pos].heal = heal;
		num[player]++;
	} else { // 没人 往最左边扔 
		num[player]++;
		int tempPos = num[player];
		servlant[player][tempPos].att = att;
		servlant[player][tempPos].heal = heal;
	}
}

void attackFunction(){
	servlant[player][from].heal -= servlant[!player][to].att;
	servlant[!player][to].heal -= servlant[player][from].att;
}

void clearDead(){ // 死在这了，他会攻击0号英雄！！！ 
	if(servlant[player][from].heal <= 0){
		int tempNum = num[player];
		for(int i = from; i < 7; i++){
			servlant[player][i].att = servlant[player][i+1].att;
			servlant[player][i].heal = servlant[player][i+1].heal;
		}
		servlant[player][tempNum].att = 0;
		servlant[player][tempNum].heal = 0;
		--num[player];
	}
	if(servlant[!player][to].heal <= 0 && to != 0){
		int tempNum = num[!player];
		for(int i = to; i < 7; i++){
			servlant[!player][i].att = servlant[!player][i+1].att;
			servlant[!player][i].heal = servlant[!player][i+1].heal;
		}
		servlant[!player][tempNum].att = 0;
		servlant[!player][tempNum].heal = 0;
		--num[!player];
	}
	
//	cout << "_________________" <<n<<endl;
//	cout << num[0];
//	for(int i = 1; i <= num[0]; i++){
//		cout << " " << servlant[0][i].heal;
//	}
//	cout << endl;
//	cout << num[1];
//	for(int i = 1; i <= num[1]; i++){
//		cout << " " << servlant[1][i].heal;
//	}
//	cout << endl;
//	cout << "_________________" <<n<<endl;
}

void printResult(){
	if(servlant[0][0].heal > 0 && servlant[1][0].heal > 0){ // 平手 
		cout << "0" << endl; 
	} else if(servlant[0][0].heal <= 0){ // 后手玩家胜利 
		cout << "-1" << endl;
	} else {
		cout << "1" << endl;
	}
	// 先手玩家的血量 
	cout << servlant[0][0].heal << endl;
	// 先手玩家剩余随从及其血量
	cout << num[0];
	for(int i = 1; i <= num[0]; i++){
		cout << " " << servlant[0][i].heal;
	}
	cout << endl;
	
	// 后手玩家的血量 
	cout << servlant[1][0].heal << endl;
	// 后手玩家剩余随从及其血量
	cout << num[1];
	for(int i = 1; i <= num[1]; i++){
		cout << " " << servlant[1][i].heal;
	}
	cout << endl;
}

int main(){
	servlant[0][0].heal = 30;
	servlant[1][0].heal = 30;
	cin >> n;
	while(n--){
		scanf("%s", op);
		if(op[0] == 's'){ // 召唤随从 
			cin >> pos >> att >> heal; // 位置 攻击力 血量
			callServlant();
		} else if(op[0] == 'a'){ // 攻击 
			cin >> from >> to;
			attackFunction();
			clearDead();
		} else { // 换人 
			player = !player;
		}
	}
	printResult();
	return 0;
}
/*
	核心思路：
		分模块写会清晰很多
		1.召唤随从即使召唤在7位置，如果此刻没有随从，那他应该在1位置 
*/
