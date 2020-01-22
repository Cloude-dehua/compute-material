#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10;
struct Stu{
	char num[25];	// ���� 
	int score;		// ���� 
} ss[maxn];			// ss�ṹ�����飬������븴�Ե�ͬѧ��Ϣ 
int total;			// �ܹ����븴�Ե����� 

bool cmp(Stu a, Stu b) {
	if(a.score != b.score) return a.score > b.score;		// ��һ���򣺷�������
	return strcmp(a.num, b.num) < 0;						// �ڶ����򣺿������� 
}

int main(){
	int n, m, g;
	int score[15];
	while(scanf("%d%d%d", &n, &m, &g)==3 && n) {
		for(int i=1; i<=m; i++) {	// ����ÿ��������� 
			scanf("%d", &score[i]);
		}
		char num[25];
		int cnt, x, sum;
		total = 0;
		for(int i=0; i<n; i++) {	// ����n��ͬѧ 
			scanf("%s %d", num, &cnt);
			sum = 0;	// �ܷ� 
			for(int j=0; j<cnt; j++) {
				scanf("%d", &x);
				sum += score[x];
			}
			if(sum >= g) {	// �������븴�� 
				ss[total].score = sum;		// ��¼�����Ϣ 
				strcpy(ss[total].num, num);
				total++;	// ���븴��������һ 
			}
		}
		
		sort(ss, ss+total, cmp);	// ����cmp�ȽϹ�������ss[0, total) 
		
		printf("%d\n", total);
		for(int i=0; i<total; i++) {
			printf("%s %d\n", ss[i].num, ss[i].score);
		}
	}

	return 0;
}

