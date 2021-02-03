#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<string>
#include<map>
using namespace std;
map<char, int>type; // 记录参数类型，1为带参，2为不带  "map里的int默认为0"
map<char, string>para; // 用作输出每次的结果，每次都初始化 para.clear(); 
string str;

void initial(){
	getline(cin, str);
	int len = str.length();
	for(int i = 0; i < len - 1; i++){
		if(str[i] != ':' && str[i+1] == ':'){ // 带参的 
			type[str[i]] = 1;
		} else if(str[i] != ':'){
			type[str[i]] = 2;
		}
	}
	if(str[len - 1] != ':'){ // 对最后一个特判 
		type[str[len - 1]] = 2;
	}
}

void operateExpress(string str){
	int len = str.length();
	int p1 = 0, p2 = 0, p3 = 0, flag = 0; // flag 区分参数 0为内容 1为参数 
	string temp, parm;
	while((p1 = str.find(' ')) != -1){ // 以空格为起点
		str[p1] = 0;
		p2 = str.find(' ');
		if(p2 == -1){ // 末尾 不是空格，则把字符串长度给了p2 
			p2 = len;
		}
		temp = str.substr(p1 + 1, p2 - p1 - 1); // 保存内容 
		if(!flag){ // 是内容 
			if(temp[0] != '-' || !type[temp[1]]){ // 不是-开头或者不是参数 玥宝应该看到题目中有这句话，指令错误则停止分析 
				break;
			} else if(type[temp[1]] == 2) { // 不带参数
				para[temp[1]] = "*";
			} else { // 带参数 
				parm = temp;
				flag = !flag;
			}
		} else { // 是参数 
			 para[parm[1]] = temp;
			 flag = !flag;
		}
	}
}

void printExpress(int i){
	cout << "Case " << i << ":";
	for(map<char, string>::iterator it = para.begin(); it != para.end(); it++){
		cout << " -" << (*it).first;
		if((*it).second != "*"){
			cout << " " << (*it).second;
		}
	}
	cout << endl;
}

int main(){
	initial();
	int n;
	cin >> n;
	cin.get();//以免读入换行符
	for(int i = 1; i <= n; i++){
		para.clear();
		string str;
		getline(cin, str);
		operateExpress(str);
		printExpress(i);
	} 
	
	return 0;
} 

/*
	Tips：
		字符串分析，这里开始我们要学会使用的库函数是map，string，iterator迭代输出map 
	核心思想：
		使用两个map，
		一个存 有哪些字母是指令，指令是否带参数 
		一个存 每一句话 分析出来的 指令，用作输出，注意每次都要初始化
		接下来观察句子，发现以空格为间隙，刚好可以间隔开
	
	附录：
	c++库函数
	#include<map>
	map<char, int>type;
	clear()　　删除所有元素
	find()　　查找一个元素
	insert()　　插入元素 //而实际中我们直接map['x']  = 1 就存入了键值对 <x, 1> 
	size()　　返回map中元素的个数
	
	#include<cstring> // 是<string.h>的c++版 用cstring就好
	string str = "abc";
	str.length();
	getline(cin, str); // 输入一行 
*/		 
