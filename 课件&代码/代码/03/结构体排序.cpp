#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10;
struct Stu{		// ����һ��ѧ���ṹ�� 
	int score[5];	// ���� 
	char name[20];	// ���� 
}ss[maxn];		// �ṹ������ 
int cnt = 0;	// �μӸ��Ե��� 

bool cmp(Stu a, Stu b) {		// �����ֽܷ������� 
	if(a.score[4] != b.score[4]) return a.score[4] > b.score[4];	// ��һ���򣺸��ݷ�������
	return strcmp(a.name, b.name) < 0;		// �ڶ����򣺸����������� 
}

int main(){
	int n;
	scanf("%d", &n);
	int line[5];
	for(int i=0; i<5; i++) scanf("%d", &line[i]);
	for(int i=0; i<n; i++) {
		char name[20];
		int a[5];
		scanf("%s %d %d %d %d", name, &a[0], &a[1], &a[2], &a[3]);
		a[4] = a[0] + a[1] + a[2] + a[3];
		bool ok = 1;
		for(int j=0; j<5; j++) {
			if(a[j]<line[j]) {
				ok = 0;
				break;
			}
		}
		if(ok) {	// ���븴�ԣ�copy�����Ϣ����ss 
			strcpy(ss[cnt].name, name);
			for(int j=0; j<5; j++) {
				ss[cnt].score[j] = a[j];
			}
			cnt++;	// ���븴��������һ 
		}
	}
	sort(ss, ss+cnt, cmp);		// ����cmp������нṹ������ 
	for(int i=0; i<cnt; i++) {	// ��� 
		printf("%s", ss[i].name);
		for(int j=0; j<5; j++) printf(" %d", ss[i].score[j]);
		printf("\n");
	} 
	return 0;
}

