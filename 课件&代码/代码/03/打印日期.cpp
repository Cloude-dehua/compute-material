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



int main() {
	init();
	
	int year, n;
	while(scanf("%d%d", &year, &n)==2) {
		Date d;
		d.year = year;		// ��һ���1��1�� 
		d.month = 1;
		d.day = 1;
		
		for(int i=1; i<n; i++) d.nextDay();		// ��һ��һ��������n-1�� 
		printf("%4d-%02d-%02d\n", d.year, d.month, d.day);
	}	
	return 0;
}




