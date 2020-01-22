#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector> 
using namespace std;
typedef long long ll;

string stdStr(string s) {
// 标准化字符串s：将大写转换为小写，排序
	for(int i=0; i<s.size(); i++) {
		if('A'<=s[i] && s[i]<='Z') {	// 将大写字母转换为小写 
			s[i] = s[i]-'A' + 'a';		
		}
	}	
	sort(s.begin(), s.end());		// 排序[begin, end) 
	return s; 
} 

int main(){
	map<string, int> m;		// 键值对，键为标准化后的字符串，值是该字符串出现次数 
	vector<string> a;		// 保存元素输入
	string s;				// 保存字符串 
	while(cin>>s) {			// 一直做输入 
		if(s[0]=='#') break;
		a.push_back(s);		// 加入 
	} 
	for(int i=0; i<a.size(); i++) {
		string st = stdStr(a[i]);
		if(!m.count(st)) m[st] = 0;		// 第一次出现做初始化 
		m[st]++;		// 标准化后字符串出现次数增一 
	}
	vector<string> ans;		// 保存需要的字符串
	for(int i=0; i<a.size(); i++) {
		string st = stdStr(a[i]);
		if(m[st] == 1) {		// 标准化后的a[i]只出现一次，即不能通过其他字符串重排得到 
			ans.push_back(a[i]);
		}
	} 
	sort(ans.begin(), ans.end());	// 字符串排序 
	for(int i=0; i<ans.size(); i++) {
		cout<<ans[i]<<endl;
	} 
	
	return 0;
}

