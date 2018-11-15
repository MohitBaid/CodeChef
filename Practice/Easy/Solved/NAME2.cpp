#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,i;	cin>>T;
	while(T--)
	{
		string s1,s2;	cin>>s1>>s2;
		int l1=s1.size(),l2=s2.size();
		string ans="NO";
		if(l1>l2)
		{
			int m=0;
			for(i=0;s1[i]!='\0';i++)
				if(s1[i]==s2[m])
					m++;
			if(m==l2)	ans="YES";	
		}
		else
		{
			int m=0;
			for(i=0;s2[i]!='\0';i++)
				if(s2[i]==s1[m])
					m++;
			if(m==l1)	ans="YES";	
		}
		cout<<ans<<endl;
	}
}
