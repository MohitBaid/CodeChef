#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,i;	cin>>T;
	while(T--)
	{
		char c[100005];		cin>>c;
		int A[10]={0};
		for(i=0;c[i]!='\0';i++)
		{
			A[c[i]-'0']++;
		}
		for(i=65;i<=90;i++)
		{
			int f1=i%10;
			int f2=i/10;
			if((f1==f2 && A[f1]>=2)||(f1!=f2 && A[f1] && A[f2]))	cout<<(char)i;	
		}
		cout<<endl;
	}
}
