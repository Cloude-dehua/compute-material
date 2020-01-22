#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int isYeap(int year) {	
// �ж�year��ƽ�껹�����꣬���꣺�ܱ�4�������ǲ��ܱ�100������������ܱ�400Ҳ���� 
	return year%4==0 && year%100!=0 || year%400==0;	
}

int dayOfMonth[13][2] = {		// �·����飬����ÿ���µ����� 
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

struct Date{	// ���ڽṹ�� 
	int year;
	int month;
	int day;
	void nextDay() {	// ��ǰ���ڵ���һ������ 
		day++;
		if(day> dayOfMonth[month][isYeap(year)]) {	// ���������������� 
			day = 1;	// ��һ���µĵ�һ�� 
			month++;	// ÿ�ݽ�λ 
			if(month>12) {	// ������һ�������·� 
				month = 1;
				year++;
			}
		}
	}
};

int days[10000][13][32];	// day[i][j][k] ��ʾ����i-j-k��0-1-1֮������� 

void init() {
// ���days���飬ȷ�����кϷ����ڵ�0-1-1֮ǰ������ 
	Date d;				// ��ʼ����0-1-1 
	d.year = 0;
	d.month = 1;
	d.day = 1;
	int cnt = 1;		// ��¼��0-1-1������ 
	while(d.year<10000) {	// �������кϷ����� 
		days[d.year][d.month][d.day] = cnt;
		d.nextDay();		// �����ƶ�һ��
		cnt++;				
	}	
}

char months[13][10] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November",
 "December"};		// �·����� 
char weeks[7][15] = {"Sunday","Monday" , "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int month_str_to_int(char* month) {
// ���ַ���month���������·� 
	for(int i=1; i<=12; i++) {
		if(strcmp(month, months[i])==0) return i;
	}
	return 0;
} 

int main(){
	init();		// ��ʼ������ 
	Date d1, d2={2019,1,23};
	char month[10];
	while(scanf("%d %s %d", &d1.day, month, &d1.year)==3) {	// ���յ�һ������ 
		d1.month = month_str_to_int(month);
	
//		int cha = (days[d2.year][d2.month][d2.day]-days[d1.year][d1.month][d1.day]);	//  ��������ֱ�ӵĲ���
		int cha = (days[d1.year][d1.month][d1.day]-days[d2.year][d2.month][d2.day]);	// ����һ�е��߼�������Ϊ���������+3,����������2019-1-4�����Ӧ��Ϊ1�õ������� 
		printf("%s\n", weeks[(((cha%7)+3)+7)%7]);
	}	
	
	return 0;
}


