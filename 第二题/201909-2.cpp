#include<iostream>
using namespace std;
int appleTree[1001] = {0};
int n, m, temp, tree;
long long result = 0;

int fallAppleTree(){ // 统计有几颗苹果树有减少apple 
	int result = 0;
	for(int i = 0; i < n; i++){
		if(appleTree[i]){
			result++;
		}
	}
	return result;
} 

int seqFallThreeApple(){ // 连续三个树都有掉落 
	int result = 0;
	for(int i = 1; i < n - 1; i++){
		if(appleTree[i - 1] && appleTree[i] &&appleTree[i + 1]){
			result++;
		}
	}
	if(appleTree[0] && appleTree[1] &&appleTree[n - 1]){
		result++;
	}
	if(appleTree[0] && appleTree[n - 2] &&appleTree[n - 1]){
		result++;
	}
	return result;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> m;
		cin >> tree;
		for(int j = 1; j < m; j++){
			cin >> temp;
			if(temp > 0){ // 更新树是否减少 
				if(tree - temp > 0){ // 苹果掉落 
					appleTree[i] = 1; 
				}
				tree = temp;
			} else { // 直接减 
				tree += temp;
			}
		}
		result += tree;
	}
	cout << result << " ";
	cout << fallAppleTree() << " ";
	cout << seqFallThreeApple() << endl;
	return 0;
} 

/*
4
4 74 -7 -12 -5
5 73 -8 -6 59 -4
5 76 -5 -10 60 -2
5 80 -6 -15 59 0

5
4 10 0 9 0
4 10 -2 7 0
2 10 0
4 10 -3 5 0
4 10 -1 8 0

*/
