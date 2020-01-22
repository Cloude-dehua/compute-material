#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
typedef long long ll;

vector<int> maxInWindows(vector<int>& num, int size) {
// ��size��С�Ĵ��ڴ����һ�������num��ÿ�δ��������ֵ�ŵ�һ����̬�����в�����
	vector<int> ans;
	deque<int> maxWin;		// ���������д��ڵġ���ЧԪ�ء����±�	
	for(int i=0; i<num.size(); i++) {
		while(!maxWin.empty() && num[i]>=num[maxWin.back()]) {		// ��ǰ��������Ԫ�ض�Ӧ��ֵС��num[i]��ʾ��ЩԪ��Ϊ����ЧԪ�� �� 
			maxWin.pop_back();
		}
		maxWin.push_back(i);		// ��i�±������� 
		if(maxWin.front() <= i-size) {	// ��ǰ��Ԫ���Ѿ����ڴ������� 
			maxWin.pop_front();			// ��ͷԪ�س��� 
		} 
		if(i>= size-1) {			// �Ѿ��ﵽ�������ڴ�С 
			ans.push_back(num[maxWin.front()]);		// maxWin��ͷ��Ӧ��Ԫ�ؾ��Ǵ������ֵ 
		} 
	}
	return ans;
} 

int main(){
	int n, m;
	while(scanf("%d%d", &n, &m)==2) {
		vector<int> num;
		int x;
		for(int i=0; i<n; i++) {
			scanf("%d", &x);
			num.push_back(x);
		}
		vector<int> ans = maxInWindows(num, m);
		for(int i=0; i<ans.size(); i++) {
			if(i>0) printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}

	return 0;
}

