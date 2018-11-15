#include<bits/stdc++.h>
using namespace std;
int pe[1001];
int m=0;
void SieveOfEratosthenes(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
       if (prime[p])
          pe[m++]=p;
}
int main()
{
	SieveOfEratosthenes(1001);
	int T;	cin>>T;
	while(T--)
	{
		int n,i,j;	cin>>n;
		int A[n];
		for(i=0;i<n;i++)	cin>>A[i];
		map < int , int > ans;
		map < int , int > :: iterator it;
		for(i=0;i<n;i++)
		{
			int p=0;
			int temp=A[i];
			while(temp>1 && p<m)
			{
				if(temp%pe[p]==0)
				{
					int c=0;
					while(temp%pe[p]==0)
					{
						temp=temp/pe[p];
						c++;
					}
					if(ans.find(pe[p])==ans.end())
					{
						ans[pe[p]]=c;
					}
					else
					{
						if(ans[pe[p]]<c)
						{
							ans[pe[p]]=c;
						}
					}
					c=0;
				}
				else p++;
			}
			if(temp!=1)	ans[temp]=1;
		}
		int a=0;
		for(it=ans.begin();it!=ans.end();it++)
			a+=it->second;
		cout<<a<<endl;	
	}
}
