#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
struct Stu{			// ѧ���ṹ�� 
	int score;		// ���� 
	char name[25];	// ���� 
} ss[maxn];			// �ṹ������ 

bool cmp(Stu a, Stu b) {
	return strcmp(a.name,b.name)<0;		// �������������� 
	// a.name < b.name <=> strcmp(a.name, b.name)<0 
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%s%d", ss[i].name, &ss[i].score);
	} 
	sort(ss, ss+n, cmp);
	for(int i=0; i<n; i++) {
		printf("%s %d\n", ss[i].name, ss[i].score);
	}

	return 0;
}

