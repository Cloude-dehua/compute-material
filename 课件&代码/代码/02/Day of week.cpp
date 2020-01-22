#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int isYeap(int year) {	
// 判断year是平年还是润年，润年：能被4整除但是不能被100整除但是如果能被400也是润 
	return year%4==0 && year%100!=0 || year%400==0;	
}

int dayOfMonth[13][2] = {		// 月份数组，保存每个月的天数 
	0, 0,
	31, 31,
	28, 29,
	31, 31,
	30, 30,
	31, 31,
	30, 30,
	31, 31,
	31, 31,
	30, 30,
	31, 31,
	30, 30,
	31, 31
};

struct Date{	// 日期结构体 
	int year;
	int month;
	int day;
	void nextDay() {	// 求当前日期的下一天日期 
		day++;
		if(day> dayOfMonth[month][isYeap(year)]) {	// 大于这个月最大天数 
			day = 1;	// 下一个月的第一天 
			month++;	// 每份进位 
			if(month>12) {	// 大于这一年的最大月份 
				month = 1;
				year++;
			}
		}
	}
};

int days[10000][13][32];	// day[i][j][k] 表示日期i-j-k到0-1-1之间的天数 

void init() {
// 填充days数组，确定所有合法日期到0-1-1之前的天数 
	Date d;				// 初始是是0-1-1 
	d.year = 0;
	d.month = 1;
	d.day = 1;
	int cnt = 1;		// 记录到0-1-1的天数 
	while(d.year<10000) {	// 遍历所有合法日期 
		days[d.year][d.month][d.day] = cnt;
		d.nextDay();		// 往后移动一天
		cnt++;				
	}	
}

char months[13][10] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November",
 "December"};		// 月份数组 
char weeks[7][15] = {"Sunday","Monday" , "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int month_str_to_int(char* month) {
// 将字符串month返回数子月份 
	for(int i=1; i<=12; i++) {
		if(strcmp(month, months[i])==0) return i;
	}
	return 0;
} 

int main(){
	init();		// 初始化工作 
	Date d1, d2={2019,1,23};
	char month[10];
	while(scanf("%d %s %d", &d1.day, month, &d1.year)==3) {	// 接收第一个日期 
		d1.month = month_str_to_int(month);
	
//		int cha = (days[d2.year][d2.month][d2.day]-days[d1.year][d1.month][d1.day]);	//  两个日期直接的查找
		int cha = (days[d1.year][d1.month][d1.day]-days[d2.year][d2.month][d2.day]);	// 上面一行的逻辑错误，因为我们最后是+3,假设我们是2019-1-4好向减应该为1得到星期四 
		printf("%s\n", weeks[(((cha%7)+3)+7)%7]);
	}	
	
	return 0;
}


