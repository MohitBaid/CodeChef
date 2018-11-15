#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		char s[1000],t[10000];
		cin>>s>>t;
		int A[26]={0},B[26]={0},i;
		for(i=0;s[i]!='\0';i++)
		{
			A[s[i]-'a']++;
			B[t[i]-'a']++;
		}
		int d=0,f=0,pos=-1;
		for(i=0;i<26;i++)
		{
			if(A[i]!=0 && B[i]==0)
			{
				d=1;
				pos=i;
				if(A[i]>1)
					f=1;
			}
		}
		if(d==1 && f==1)	cout<<"A\n";
		else if(d==1 && f==0)
		{
			A[pos]--;
			d=0;f=0;
			for(i=0;i<26;i++)
			{
				if(B[i]!=0 && A[i]==0)
				{
					d=1;
					pos=i;
				}
			}
			if(d==1)		cout<<"B\n";
			else			cout<<"A\n";
		}
		else				cout<<"B\n";
	}
}
