#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int a[3][3];
int b[3][3];	// ת�ú�ľ��� 
void T(int n, int m) {
// ��n��m�е�����ת��������b 
	for(int i=0; i<n; i++) {		// ������ά���� 
		for(int j=0; j<m; j++) {
			b[j][i] = a[i][j];		// ���кź��кŽ������� 
		}
	} 
} 

int main(){
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			scanf("%d", &a[i][j]);
		}
	}
//	
//	for(int j=0; j<3; j++) {
//		for(int i=0; i<3; i++) {
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//	

	T(3, 3);	// ת�ò���
	
	// ��� 
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}


	return 0;
}

