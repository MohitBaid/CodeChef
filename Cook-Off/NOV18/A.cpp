#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		string s;	cin>>s;
		int c1=0,c2=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i] == s[(i+1)%s.size()])
			{
				if(s[i]=='R')
					c1++;
				else
					c2++;	
			}
		}
		if( (c1==1 && c2==1)||(c1==0 && c2==0))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;	
	}
}
