#include<bits/stdc++.h>
#define MOD 1000000007
long long int f[1000000];
using namespace std;
set < string > bit;
void generate(string str,long long int n)
{
	if (str.size()==n)
	{
		bit.insert(str);
	}
	else
	{
		generate(str+'0',n);
		generate(str+'1',n);
	}
}
long long int power(long long int n)
{
	if(n==0)	return 1;
	if(n==1)	return 2;
	if(n==2)	return 4;
	if(n==3)	return 8;   
	long long int temp=power(n/2);
	if(n%2==0)		return (temp*temp)%MOD;
	else			return (((temp*temp)%MOD)*2)%MOD;
}
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		long long int n,m,i,k,j;	cin>>n>>m>>k;
		if(k==1)
		{
			for(i=0;i<m;i++)
			{
				int u,v;	cin>>u>>v;
			}
			long long int pow=power(n-2);
			long long int ans=0;
			ans=(pow*m%MOD)%MOD;
			cout<<ans<<endl;
		}
		else
		{
			string str;
			generate(str,n);
			int A[n+2][n+2];
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					A[i][j]=0;
			for(i=0;i<m;i++)
			{
				int u,v;
				cin>>u>>v;
				A[u-1][v-1]=1;
				A[v-1][u-1]=1;
			}
			long long int ans=0,temp;
			set < string > ::iterator it;
			for(it=bit.begin();it!=bit.end();it++)
			{
				str=*it;	temp=0;
				//for(i=0;i<str.size();i++)	cout<<str[i]<<" ";
				for(i=0;i<str.size();i++)
				{
					for(j=i+1;j<str.size();j++)
					{
						//cout<<i+1<<" "<<str[i]<<" "<<j+1<<str[j]<<" "<<endl;	
						if(str[i]=='1' && str[j]=='1' && A[i][j]==1)
						{
							//cout<<i+1<<" "<<j+1<<endl;	
							temp++;
						}
					}
				}
				if(k==2)
				{
					temp=(temp*temp%MOD)%MOD;
				}
				else
				{
					temp=((temp*temp%MOD)*temp%MOD)%MOD;
				}
				ans+=temp;
				//cout<<" :"<<temp<<endl;
				ans=ans%MOD;
			}		
			cout<<ans<<endl;
			bit.clear();
		}
	}
}
