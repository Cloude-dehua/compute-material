#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int isYeap(int year) {
// �ж�year��һ�����������Ƿ���1
	return year%4==0 && year%100!=0 || year%400==0;	
}

int dayOfMonth[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31}; 

struct Date {	// ���ڽṹ�� 
	int year;	// ��
	int month;	// ��
	int day; 	// ��
	void nextDay() {	// ��һ�� 
		day++;
		if(day>dayOfMonth[month]+ (month==2 && isYeap(year))) {	// ��������µ����һ�죬������һ���µĵ�һ�� 
								// ����Ķ��·ݶ�һ�� 
			day = 1;
			month++;
			if(month>12) {	// ������һ��ĵ�һ���� 
				year++;
				month = 1;
			}
		}
	} 
	
};

const int maxn = 28423 + 10;
char s[maxn][15];	// s[i]�����i������ڣ����磺1777-04-30 

int main() {
	Date d;		
	d.year = 1777;		// ��ʼ�����˹���������� 
	d.month = 4;
	d.day = 30;
	
	for(int i=1; i<maxn; i++) {	// ���Ϸ�����ȫ�����浽s���飨�� 
		// printf==>�������׼��������ڴ��ڣ�  fprintf==>������ļ��� sprintf==>������ַ��� 
		// scanf, fscanf, sscanf 
		sprintf(s[i], "%4d-%02d-%02d\0", d.year, d.month, d.day);
		d.nextDay();
	}
	int n;
	while(scanf("%d", &n)==1) {
		printf("%s\n", s[n]);	// ֱ�Ӳ�� 
	}

	return 0;
}

