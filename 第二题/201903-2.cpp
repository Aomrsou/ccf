#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;
stack<int> stkNum;
stack<char> stkChar;

void operate(int a, int b, char op){
	if(op == '+'){
		stkNum.push(a+b);
	}else if(op == '-'){
		stkNum.push(a-b);
	}else if(op == 'x'){
		stkNum.push(a*b);
	} else {
		stkNum.push(a/b);
	}
}

bool isTwentyFour(char *express){
	stkNum.push(express[0] - 48);
	for(int i = 1; i <= 5; i+=2){
		stkNum.push((express[i+1] - 48));
		if(express[i] == '+' || express[i] == '-'){ // 加减先放一放
			if(express[i] == '-'){ // 减号的话，将此数置位负数 并塞入加号 
				int temp = stkNum.top();
				stkNum.pop();
				temp = -temp;
				stkNum.push(temp);
			}
			stkChar.push('+');
		} else { // 乘除直接算 
			int b = stkNum.top();
			stkNum.pop();
			int a = stkNum.top();
			stkNum.pop();
			operate(a, b, express[i]);
		}
	}
	while(stkChar.size()){
		int b = stkNum.top();
		stkNum.pop();
		int a = stkNum.top();
		stkNum.pop();
		char op = stkChar.top();
		stkChar.pop();
		operate(a, b, op);
	}
	
	int result = stkNum.top();
	stkNum.pop();
	return result == 24;
}

int main(){
	int n;
	cin >> n;
	char *express = (char *)malloc(sizeof(char) * 8);
	for(int i = 0; i < n; i++){
		cin >> express;
		if(isTwentyFour(express)){
			cout << "Yes" <<endl;
		} else {
			cout << "No" <<endl;
		}
	}
	return 0;
} 

/*
10
9+3+4x3
5+4x5x5
7-9-9+8
5x6/5x4
3+5+7+9
1x1+9-9
1x9-5/9
8/5+6x9
6x7-3x6
6x4+4/5

	核心思想：
		以两个栈，一个存数，一个存符号，遇到乘除直接算，加减就缓一缓
	玥宝要学到：
		C++栈如何使用
		#include<stack>
		定义栈如下：
		stack<int> stk;
		
		s.empty()               如果栈为空返回true，否则返回false  
		s.size()                返回栈中元素的个数  
		s.pop()                 删除栈顶元素但不返回其值  
		s.top()                 返回栈顶的元素，但不删除该元素  
		s.push()                在栈顶压入新元素  
*/
