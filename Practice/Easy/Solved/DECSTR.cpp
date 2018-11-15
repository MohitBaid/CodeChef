#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,i;	cin>>T;
	string ans,div;
	for(i=97+25;i>=97;i--)	div+=(char)i;	
	while(T--)
	{
		int k;	cin>>k;
		int a=k/25,b=k%25;
		if(b)	for(i=26-b-1;i<26;i++)	cout<<div[i];
		while(a--)			cout<<div;	cout<<endl;
	}
}
