#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 10;
struct Stu{
	int num;	// ѧ��
	int score;	// ����
	char name[10]; // ���� 
} ss[maxn];

//�� C=1 ʱ����ѧ�ŵ�������
bool cmp1(Stu a, Stu b) {
	return a.num < b.num;
}
//�� C=2ʱ���������ķǵݼ��ֵ�������
bool cmp2(Stu a, Stu b) {
	if(strcmp(a.name, b.name) !=0) return strcmp(a.name, b.name) < 0;	// ��һ������򣺰�����������
	else return a.num < b.num;	// �ڶ��������ѧ�ŵ������� 
}

//�� C=3ʱ�����ɼ��ķǵݼ�����
bool cmp3(Stu a, Stu b) {
	if(a.score != b.score) return a.score < b.score;	// ��һ������򣺰�����������
	else return a.num < b.num;	// �ڶ��������ѧ�ŵ������� 
}

int main(){
	int n, c;
	int kase = 1;
	while(scanf("%d%d", &n, &c)==2 && n) {
		// ���� 
		for(int i=0; i<n; i++) {
			scanf("%d%s%d", &ss[i].num, ss[i].name, &ss[i].score);
		}
		// ����cֵ���ò�ͬ��������� 
		if(c==1) {
			sort(ss, ss+n, cmp1);
		} else if(c==2) {
			sort(ss, ss+n, cmp2);
		} else if(c==3) {
			sort(ss, ss+n, cmp3);
		}
		// ��� 
		printf("Case %d:\n", kase++);
		for(int i=0; i<n; i++) {
			printf("%06d %s %d\n", ss[i].num, ss[i].name, ss[i].score);
		}
	}

	return 0;
}

