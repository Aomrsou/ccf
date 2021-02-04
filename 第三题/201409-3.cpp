#include<iostream>
#include<cstring>
#include<ctype.h>
using namespace std;
string str, temp, tempSelf;
int flag; // 大小写敏感  0 不敏感   1 敏感 

int main(){
	getline(cin, str);
	cin >> flag;
	int n;
	cin >> n;
	cin.get(); // 吃掉回车 别让他祸害第一行数据 
	for(int i = 0; i < n; i++){
		getline(cin, temp);
		tempSelf = temp; 
		int result = temp.find(str);
		if(!flag){ // 不敏感的话 全转成大写 
			int len = temp.length();
			for(int i = 0; i < len; i++){
				temp[i] = toupper(temp[i]);
			}
			len = str.length();
			for(int i = 0; i < len; i++){
				str[i] = toupper(str[i]);
			}
		}
		if(temp.find(str) != -1){
			cout << tempSelf << endl;
		}
	}
	return 0;
}

/*
	Tips：
		这题我们整一个ctype.h ，toupper('a') => A
		然后查找子串是string的方法 
		string str,str1;
		str.find(str1); 返回值就是位置 没找到返回-1
	Hello
	0
	5
	HelloWorld
	HiHiHelloHiHi
	GrepIsAGreatTool
	HELLO
	HELLOisNOTHello
*/
