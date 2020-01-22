#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int isYeap(int year) {
// 判断year这一年是闰年吗，是返回1
	return year%4==0 && year%100!=0 || year%400==0;	
}

int dayOfMonth[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31}; 

struct Date {	// 日期结构体 
	int year;	// 年
	int month;	// 月
	int day; 	// 天
	void nextDay() {	// 下一天 
		day++;
		if(day>dayOfMonth[month]+ (month==2 && isYeap(year))) {	// 大于这个月的最后一天，进入下一个月的第一条 
								// 闰年的二月份多一天 
			day = 1;
			month++;
			if(month>12) {	// 进入下一年的第一个月 
				year++;
				month = 1;
			}
		}
	} 
	
};

const int maxn = 28423 + 10;
char s[maxn][15];	// s[i]保存第i天的日期，例如：1777-04-30 

int main() {
	Date d;		
	d.year = 1777;		// 初始化会高斯出生的日期 
	d.month = 4;
	d.day = 30;
	
	for(int i=1; i<maxn; i++) {	// 将合法日期全部保存到s数组（表） 
		// printf==>输出到标准输出流（黑窗口）  fprintf==>输出到文件， sprintf==>输出到字符串 
		// scanf, fscanf, sscanf 
		sprintf(s[i], "%4d-%02d-%02d\0", d.year, d.month, d.day);
		d.nextDay();
	}
	int n;
	while(scanf("%d", &n)==1) {
		printf("%s\n", s[n]);	// 直接查表 
	}

	return 0;
}

