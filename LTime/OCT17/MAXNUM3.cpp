#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i;	//cin>>n;
		string s;	cin>>s;
		n=s.size();
		int f,sum=0;
		for(i=0;i<n;i++)	sum+=(s[i]-'0');
		if((s[n-1]-'0')%2==1)
		{
			if((s[n-2]-'0')%2==1)
			{
				cout<<"-1"<<endl;
				continue;
			}
			else
			{
				sum-=(s[n-1]-'0');
				if(sum%3==0)	for(i=0;i<n-1;i++)		cout<<s[i];	
				else			cout<<"-1";	
				cout<<endl;
			}
		}
		else
		{
			int temp=sum%3;
			int pos=-1,val=-1;
			int P[n];
			set < pair < int,int  > >se;
			set < pair < int,int  > >:: iterator it;
			for(i=0;i<n;i++)
			{
				P[i]=0;
				if((s[i]-'0')%3==temp)
				{
					if(val==-1)			val=s[i]-'0';
					if(val>s[i]-'0')	val=s[i]-'0';		
					P[i]=1;
					se.insert(make_pair(s[i]-'0',i));
				}	
			}
			for(it=se.begin();it!=se.end();it++)
			{
				i=it->second;
				if(i!=n-1 && s[i+1]-'0' >= s[i]-'0')
				{
					pos=i;
					break;
				}
			}
			if(pos==-1)
			{
				for(i=n-1;i>=0;i--)
				{
					if(P[i])
					{
						pos=i;
						break;
					}
				}
			}
			if(pos==n-1)
			{
				if((s[n-2] - '0') %2 ==1)
				{
					pos=-1;
					for(i=n-2;i>=0;i--)
					{
						if(P[i])
						{
							pos=i;
							break;
						}	
					}
				}
			}
			if(pos==-1)	cout<<"-1"<<endl;
			else
			{
				for(i=0;i<n;i++)
				{
					if(i!=pos)
					{
						cout<<s[i];
					}
				}
				cout<<endl;
			}
		}
	}
}
