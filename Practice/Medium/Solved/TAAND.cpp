#include<bits/stdc++.h>
using namespace std;
#define POW 1<<29
string dectobin(int x)
{
	long long int p=POW;
	string ans;
	while(p)
	{
		if(x>=p)
		{
			x-=p;
			ans+='1';
		}
		else	ans+='0';
		p/=2;
	}
	return ans;
}
int main()
{
	int n,i,z,j,k;	cin>>n;
	int A[n]; string B[n];
	vector < string > s,t;
	vector < string > :: iterator it;
	for(i=0;i<n;i++)	
	{
		cin>>A[i];
		B[i]=dectobin(A[i]);
		s.push_back(B[i]);
	}
	for(z=0;z<30;z++)
	{
		int c=0;
		for(it=s.begin();it!=s.end();it++)	
		{
			string g=*it;
			if(g[z]=='1')	c++;
		}
		if(c>1)
		{
			t.clear();
			for(it=s.begin();it!=s.end();it++)	
			{
				string g=*it;
				if(g[z]=='1')	
					t.push_back(g);	
			}
			s.clear();
			for(it=t.begin();it!=t.end();it++)
			{
				s.push_back(*it);
			}
		}
	}
	for(i=0,it=s.begin();it!=s.end();i++,it++)
		B[i]=*it;//,cout<<B[i]<<endl;;
	long long int ans=-1;
	for(i=0;i<s.size();i++)
	{
		for(j=i+1;j<s.size();j++)
		{
			long long int temp=0,pow=POW;
			for(k=0;k<30;k++)
			{
				if(B[i][k]=='1' && B[j][k]=='1')
				{
					temp+=pow;	
				}
				pow/=2;
			}
			if(ans<temp)	ans=temp;
		}
	}
	cout<<ans<<endl;
}
