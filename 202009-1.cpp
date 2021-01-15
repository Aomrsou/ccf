#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int flag = n;
	int x,y;
	cin >> x >> y; // scanf("%d %d", &x, &y);
	float dis[n] = {0};
	int tempx,tempy,i = 0;
	while(flag--){
		cin >> tempx >> tempy;
		tempx -= x;
		tempy -= y;
		dis[i++] = sqrt(tempx*tempx + tempy*tempy);
	}
	for(int j = 0; j < 3; j++){
		float min = 65535;
		int index = 0;
		for(int k = n - 1; k >= 0; k--){
			if(dis[k] <= min){
				index = k;
				min = dis[k];
			}
		}
		cout << index+1 << endl;
		dis[index] = 65535;
	}
	return 0;
}
