#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	int n;
	while(scanf("%d", &n)==1) {
		int ans = n;		// �ȵ�nƿ���ϣ��õ�n������ 
		while(n>=3) {		// �����������ڵ���3,���Լ��������� 
			ans += n/3;		// ��һ�ο��Ի�������
			n = n/3 + n%3;  // ���Ϻ��˵õ����Ӽ����ϴ�ʣ��ĸ��� 
		}
		printf("%d\n", ans); 
	} 

	return 0;
}

