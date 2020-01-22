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
	int num;	// 学号
	int score;	// 分数
	char name[10]; // 姓名 
} ss[maxn];

//当 C=1 时，按学号递增排序
bool cmp1(Stu a, Stu b) {
	return a.num < b.num;
}
//当 C=2时，按姓名的非递减字典序排序
bool cmp2(Stu a, Stu b) {
	if(strcmp(a.name, b.name) !=0) return strcmp(a.name, b.name) < 0;	// 第一排序规则：按姓名升序排
	else return a.num < b.num;	// 第二排序规则：学号递增排序 
}

//当 C=3时，按成绩的非递减排序
bool cmp3(Stu a, Stu b) {
	if(a.score != b.score) return a.score < b.score;	// 第一排序规则：按分数升序排
	else return a.num < b.num;	// 第二排序规则：学号递增排序 
}

int main(){
	int n, c;
	int kase = 1;
	while(scanf("%d%d", &n, &c)==2 && n) {
		// 输入 
		for(int i=0; i<n; i++) {
			scanf("%d%s%d", &ss[i].num, ss[i].name, &ss[i].score);
		}
		// 根据c值调用不同的排序规则 
		if(c==1) {
			sort(ss, ss+n, cmp1);
		} else if(c==2) {
			sort(ss, ss+n, cmp2);
		} else if(c==3) {
			sort(ss, ss+n, cmp3);
		}
		// 输出 
		printf("Case %d:\n", kase++);
		for(int i=0; i<n; i++) {
			printf("%06d %s %d\n", ss[i].num, ss[i].name, ss[i].score);
		}
	}

	return 0;
}

