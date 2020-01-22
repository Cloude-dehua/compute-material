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
// 用size大小的窗口从左到右滑动数组num，每次窗口中最大值放到一个动态数组中并返回
	vector<int> ans;
	deque<int> maxWin;		// 滑动过程中窗口的“有效元素”的下标	
	for(int i=0; i<num.size(); i++) {
		while(!maxWin.empty() && num[i]>=num[maxWin.back()]) {		// 当前窗口最后的元素对应的值小于num[i]表示这些元素为“无效元素 ” 
			maxWin.pop_back();
		}
		maxWin.push_back(i);		// 将i下标加入队列 
		if(maxWin.front() <= i-size) {	// 最前面元素已经不在窗口里面 
			maxWin.pop_front();			// 队头元素出队 
		} 
		if(i>= size-1) {			// 已经达到完整窗口大小 
			ans.push_back(num[maxWin.front()]);		// maxWin推头对应的元素就是窗口最大值 
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

