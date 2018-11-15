#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		string s;	cin>>s;
		int A[26]={0},i;
		for(i=0;i<s.size();i++)
		{
			A[s[i]-'a']++;
		}
		bool flag=false;
		for(i=0;i<26;i++)
		{
			if(A[i]>1)
			{
				flag=true;
				break;
			}
		}
		if(flag)	cout<<"yes"<<endl;
		else		cout<<"no"<<endl;
	}
}
