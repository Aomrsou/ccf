#include<iostream>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
int p, n, q, u;

typedef struct{
	int level;
	string cmd;
}Command;

map<string, int> command;
map<string, vector<Command> >role; // 这样定义得多个空格> > 
map<string, vector<Command> >user;

string getStr(string str){
	return str.substr(0, str.length() - 2);
}

void initialCommand(int p){ // 初始化很重要 
	while(p--){
		string temp;
		int tempLevel = -1;
		cin >> temp;
		if(temp.find(':') != -1){ // 有等级 
			tempLevel = temp[temp.length() - 1] - 48;
			temp = getStr(temp);
		}
		command[temp] = tempLevel;
	}
}

void initialRole(int n){ // 录入角色 
	while(n--){
		string name, tempStr;
		cin >> name;
		int num, tempLevel;
		cin >> num;
		vector<Command> vec;
		while(num--){
			tempLevel = -1;
			cin >> tempStr;
			if(tempStr.find(':') != -1){ // 有等级 
				tempLevel = tempStr[tempStr.length() - 1] - 48;
				tempStr = getStr(tempStr);
			}
			Command command = {tempLevel, tempStr};
			vec.push_back(command);
		}
		role[name] = vec;
	}
}

void initialUser(int u){ // 记得比较指令的大小 如git:3 git:1 最后应该存git:3 
	while(u--){
		string userName, roleName;
		cin >> userName;
		vector<Command> vec;
		
		int num;
		cin >> num;
		
		while(num--){
			cin >> roleName;
			vector<Command> vecc = role[roleName];
			for(vector<Command>::iterator it = vecc.begin(); it != vecc.end(); it++){
				string cmd = it -> cmd;
				int tempLevel = it -> level;
				int flag = 1;
				for(vector<Command>::iterator itt = vec.begin(); itt != vec.end(); itt++){
					if(itt -> cmd == cmd && itt -> level < tempLevel){
						itt -> level = tempLevel;
						flag = 0;
					}
				}
				if(flag){ // 不存在本元素 
					Command c = {tempLevel, cmd};
					vec.push_back(c);
				}
			}
		}
		
		user[userName] = vec;
	}
}

int isContainEle(vector<Command> vec, string str){ // -1则无权限 
	int result = -999;
	for(vector<Command>::iterator it = vec.begin(); it != vec.end(); it++){
		if(it -> cmd == str){
			result = it -> level;
			break;
		}
	}
	return result;
}

void selectQuery(int q){
	while(q--){
		string userName, tempStr;
		int tempLevel = -1;
		cin >> userName >> tempStr;
		if(tempStr.find(':') != -1){ // 有等级 
			tempLevel = tempStr[tempStr.length() - 1] - 48;
			tempStr = getStr(tempStr);
		}
		
		if(command.count(tempStr) == 1){ // 系统内存在该指令 
			vector<Command> vec = user[userName]; // 该用户的所有权限 
			int result = isContainEle(vec, tempStr); // 是否拥有该权限
			if(command[tempStr] == -1){ // 无等级指令
				if(result == -999){ // 无权限 
					cout << "false" << endl;
				} else {
					cout << "true" << endl;
				}
			} else { // 有等级指令 
				if(tempLevel == -1){ // 查询时不带等级 返回最高 
					if(result == -999){ // 这人没这权限 
						cout << "false" << endl;
					} else {
						cout << result << endl;
					}
				} else { // 查询时带等级
					if(result == -999){ // 这人没这权限 
						cout << "false" << endl;
					} else {
						cout << ((result >= tempLevel) ? "true" : "false") << endl;
					}
				}
			}
		} else { // 系统内无该指令 
			cout << "false" << endl;
		}
	} 
}

int main(){
	cin >> p; // p种权限
	initialCommand(p);
	cin >> n; // n种角色
	initialRole(n);
	
	cin >> u;
	initialUser(u);
	cin >> q; // q个查询
	selectQuery(q);
	return 0;
} 

/*
	Tips:
		今天玥宝复习vector和map的使用
		1.判断map中有某key: map.count(str) == 1
		2.map的遍历: for(map<str, int>::iterator it = myMap.begin(); it != myMap.end(); it++){
						it -> first; // 迭代器元素的访问 
						it -> second;
					}  vector写法相同，均用迭代器
		3.vector存放元素: vec.push_back(element); 
	核心思路：
		3个map，用来存指令，角色，用户 
*/ 
