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
// ��׼���ַ���s������дת��ΪСд������
	for(int i=0; i<s.size(); i++) {
		if('A'<=s[i] && s[i]<='Z') {	// ����д��ĸת��ΪСд 
			s[i] = s[i]-'A' + 'a';		
		}
	}	
	sort(s.begin(), s.end());		// ����[begin, end) 
	return s; 
} 

int main(){
	map<string, int> m;		// ��ֵ�ԣ���Ϊ��׼������ַ�����ֵ�Ǹ��ַ������ִ��� 
	vector<string> a;		// ����Ԫ������
	string s;				// �����ַ��� 
	while(cin>>s) {			// һֱ������ 
		if(s[0]=='#') break;
		a.push_back(s);		// ���� 
	} 
	for(int i=0; i<a.size(); i++) {
		string st = stdStr(a[i]);
		if(!m.count(st)) m[st] = 0;		// ��һ�γ�������ʼ�� 
		m[st]++;		// ��׼�����ַ������ִ�����һ 
	}
	vector<string> ans;		// ������Ҫ���ַ���
	for(int i=0; i<a.size(); i++) {
		string st = stdStr(a[i]);
		if(m[st] == 1) {		// ��׼�����a[i]ֻ����һ�Σ�������ͨ�������ַ������ŵõ� 
			ans.push_back(a[i]);
		}
	} 
	sort(ans.begin(), ans.end());	// �ַ������� 
	for(int i=0; i<ans.size(); i++) {
		cout<<ans[i]<<endl;
	} 
	
	return 0;
}

