#include<iostream>
using namespace std;

int main(){
	int n,m, temp = 0;
	int sum = 0, treeMax = 1, devid = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> temp;
		sum += temp; //¸Õ¿ªÊ¼ 
		int treeSum = 0;
		for(int j = 0; j < m; j++){
			cin >> temp;
			treeSum += temp;
		}
		sum += treeSum; //¿³µôµÄ 
		treeSum = -treeSum;
		if(treeSum > devid){
			treeMax = i;
			devid = treeSum;
		}
	}
	printf("%d %d %d\n",sum, treeMax, devid);
	return 0;
} 
