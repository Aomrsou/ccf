#include<iostream>
#include<cstring>
#include<stack> 
using namespace std;
int p;
string current, str, perfect;
stack<string> stk;

void initial(){ // 去除N个斜杠 和  ./ 当前目录 
	int p1 = 0;
	while((p1 = str.find("//")) != -1) {
		str.replace(p1, 2, "/"); // p1开始 替换2长度的字符为 “/” 
	}
	p1 = 0;
	while((p1 = str.find("./", p1)) != -1) {
		if(p1 != 0 && str[p1 -1] != '.'){ // 判断是否为"../" 
			str.replace(p1, 2, ""); // "./"为当前目录 直接删掉 
		} else {
			++p1;
		}
	}
}

void GetPath(){ // 如果是绝对路径就不管，相对路径就加上当前路径 
	int curLen = current.length();
	if(str[0] != '/'){ // 相对路径 
		if(current[curLen - 1] != '/'){ // 补一个斜杠 
			perfect = current + "/" + str;
		} else {
			perfect = current + str;
		}
	} else { // 绝对路径 
		perfect = str;
	}
	if(perfect[perfect.length() - 1] != '/'){
		perfect = perfect + "/";
	}
}

void operatePath(){ // 处理 "上一级" -- ".."目录  从左往右入栈，碰到..就出栈 
	int p1 = 0,p2 = 0;
	string temp;
	while((p1 = perfect.find('/', p1)) != -1){
		if((p2 = perfect.find('/', p1+1)) != -1){
			temp = perfect.substr(p1 + 1, p2 - p1 - 1);
			if(temp == ".."){
				if(stk.size()){
					stk.pop();
				}
			} else {
				stk.push(temp);
			}
			p1 = p2;
		} else {
			p1++;
		}
	}
}

void printPath(){ // 打印栈里边剩下的元素，对根目录做特判 
	string path = "/";
	while(stk.size()){
		path = "/" + stk.top() + path;
		stk.pop();
	}
	if(path.length() > 1){
		path[path.length() - 1] = '\n';
		cout << path;
	} else {
		cout << "/" << endl;
	}
}

int main(){
	cin >> p;
	cin.get();
	getline(cin, current);
	while(p--){
		while(stk.size()){
			stk.pop();
		} 
		getline(cin, str);
		initial();
		GetPath();
		operatePath();
		printPath();
	}
	return 0;
} 

/*
	Tips:
		今天玥宝可以学到 str.append(len, str1);
		在str后边追加 len 长的字符串 str1 
		
		str = str + str1; 但是这个更香 
		
	核心思路：
		分成了四个函数，每个函数都有注释，去看看叭 
*/
