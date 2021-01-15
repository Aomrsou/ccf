#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	long long n,max = 0, min = 0;
	double mid = 0.0;
	cin >> n;
	long long arr[n];
	for(long long i = 0; i < n; i++){
		cin >> arr[i];
	}
	if(n%2 == 0){
		mid = ((double)arr[n/2] + (double)arr[(n/2)-1])/2;
	} else {
		mid = (double)arr[n/2];
	}
	if(arr[0] < arr[n-1]){ // ÉýÐò 
		max = arr[n-1];
		min = arr[0];
	} else {
		max = arr[0];
		min = arr[n-1];
	}
	printf("%ld ", max);
	if(mid == (double)((int)mid)){
		printf("%ld ", (long long)mid);
	}else{
		printf("%.1lf ", mid);
	}
	printf("%ld\n", min);
	return 0;
}
