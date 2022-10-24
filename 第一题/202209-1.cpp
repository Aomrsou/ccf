/*******************************************************************************
  * @file        202209-1.cpp
  * @version     v1.0.0
  * @author      zhuhongyu
  * @date        2022-10-24
*******************************************************************************/
#include <cstdio>
#include <cstdlib>

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int *nArr = (int *) calloc(n + 1, sizeof(int));
	for (int i = 1; i <= n; i++) {
		scanf("%d", nArr + i);
	}
	int *cArr = (int *) calloc(n + 1, sizeof(int));
	cArr[0] = 1;
	for (int i = 1; i <= n; i++) {
		cArr[i] = 1;
		for (int j = 1; j <= i; j++) {
			cArr[i] *= nArr[j];
		}
	}
	int *bArr = (int *) calloc(n + 1, sizeof(int));
	for (int i = 1; i <= n; i++) {
		bArr[i] = (m % cArr[i] - m % cArr[i - 1]) / cArr[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		printf("%d", bArr[i]);
		if (i != n)
			printf(" ");
	}
	return 0;
}

/*******************************************************************************
  * @file        202209-1.cpp
  * @version     v1.0.0
  * @author      zhangziyang
  * @date        2022-10-24

#include <iostream>
using namespace std;

int main() {
	int n, m, a[21] = {1}, b[21] = {0};
	long long temp = 0, c[21] = {1};
	cin >> n >> m;
	for (int i = 1; i <= n; i++) { // ci为ai的前缀乘积
		cin >> a[i];
		c[i] = c[i - 1] * a[i];
	}
	for (int i = 1; i <= n; i++) {
		b[i] = (m % c[i] - temp) / c[i - 1];
		temp += b[i];
		cout << b[i] << " ";
	}
	return 0;
}

*******************************************************************************/
