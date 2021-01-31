#include<iostream>
using namespace std;
int n, k, t, xl, yd, xr, yu; // k个起步算逗留  每个居民t个坐标 

bool isStay(int x, int y){
	return (x >= xl && x <= xr && y >= yd && y <= yu);
}

int main(){
	int x, y, through = 0, stay = 0;
	cin >> n >> k >> t >>xl >> yd >>xr >> yu;
	for(int i = 0; i < n; i++){
		int max = 0, maxSeq = 0;
		for(int j = 0; j < t; j++){
			cin >> x >> y;
			maxSeq = isStay(x, y) ? maxSeq + 1 : 0;
			max = maxSeq > max ? maxSeq : max;
		}
		if(max){
			through++;
			if(max >= k){
				stay++;
			}
		}
	}
	cout << through << endl;
	cout << stay << endl;
	return 0;
}
