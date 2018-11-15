#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,p,i;	cin>>n>>p;
		if(n>2)
		{
			if(p>2)
			{
				int k=n%p;
				if(k%2==0)
				{
					string ans,temp,fin;
					for(i=0;i<(p-1)/2;i++)
						temp+='a';
					ans+=temp;
					if(p%2)	ans+='b';
					else	ans+="bb";
					ans+=temp;
					int q=n/p;
					while(q--)		fin+=ans;
					while(k--)
					{
						fin='a'+fin+'a';
					}
					cout<<fin<<endl;
				}
				else	cout<<"impossible"<<endl;
			}
			else	cout<<"impossible"<<endl;
		}
		else	cout<<"impossible"<<endl;
	}
}
