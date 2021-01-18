#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
typedef struct{
	int time; // 操作发生的时间 
	int op;   // 发生哪个操作 拿or还 1or0
	int num;  // 钥匙编号 
}Operate;
int n, k;
int box[1001] = {0};
bool cmp(Operate a, Operate b){
	if(a.time != b.time){ // 操作时的时间，时间在前的先操作 
		return a.time < b.time;
	} else if(a.op != b.op){ // 先还再拿，还为1，拿为0 
		return a.op > b.op;
	} else { // 编号小的先处理 
		return a.num < b.num;
	}
}

int findKey(int num){ // 找到钥匙在哪个坑上挂着 
	for(int i = 1; i <= n; i++){
		if(box[i] == num){
			return i;
		}
	}
}

int main(){
	int w, s, c;
	cin >> n >> k;
	for(int i = 0; i <= n; i++){ // initial key box
		box[i] = i;
	}
	Operate *operate = (Operate*)malloc(sizeof(Operate) * k * 2);
	for(int i = 0; i < k; i++){
		cin >> w >> s >> c; // which start class
		// 拿操作
		operate[i].num = w;
		operate[i].op = 0;
		operate[i].time = s;
		// 还操作 
		operate[i + k].num = w;
		operate[i + k].op = 1;
		operate[i + k].time = s + c;
	}
	sort(operate, operate + 2 * k, cmp); // 排序nb 
	for(int i = 0; i < k * 2; i++){ // 模拟排序好的每一步操作 
		if(operate[i].op){ // 还钥匙 
			for(int j = 1; j <= n; j++){
				if(box[j] == -1){
//					printf("时刻%d, %d还回来了", operate[i].time, operate[i].num);
					box[j] = operate[i].num;
					break;
				}
			}
		} else { // 拿钥匙 
//			printf("时刻%d, %d拿走了   ", operate[i].time, operate[i].num);
			box[findKey(operate[i].num)] = -1;
		}
//		for(int j = 1; j <= n; j++){
//			cout << " " << box[j];
//		}
//		cout << endl;
	}
	cout << box[1];
	for(int j = 2; j <= n; j++){
		cout << " " << box[j];
	}
	cout << endl;
	return 0;
}

/*
	核心思想：
		将所有操作按照 操作时间 、取/存、钥匙编号（优先级为1 1.5 2.5 3） 
		这样就可以按照实际操作的顺序模拟存取钥匙
		该题玥宝需要学到的技巧是：结构体分别按各个元素排序 
	Tips：
		注释掉的代码是看具体运行过程，你可以取消注释跑一遍样例感受一下 
*/
