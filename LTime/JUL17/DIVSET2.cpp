#include<bits/stdc++.h>
using namespace std;
int B[100]={0};
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		map <long long int,int> H;
		int n,k,c;	cin>>n>>k>>c;
		long long int i;
		int j;
		long long int A[n];
		for(j=0;j<n;j++)	cin>>A[j],H[A[j]]++;
		int flag=1,ans=0;
		map <long long int,int> :: iterator it;
		while(flag)
		{
			int m=0,flag3=1;
			for(it=H.begin();it!=H.end();it++)
				if(it->second>0)
				{
					i=it->first;
					H[i]--;
					if(H[i]==0)
						H.erase(i);
					flag3=0;
					break;
				}
			if(!flag3)	B[m++]=i;
			else		break;	
			int temp=i*c;
			int flag2=1;
			for(j=1;j<k;j++)
			{
				flag2=1;
				it=H.begin();
				for(;it!=H.end();it++)
					if(it->first>=temp)
					{
						flag2=0;
						i=it->first;
						H[i]--;
						if(H[i]==0)
							H.erase(i);
						break;
					}
				if(!flag2)
				{
					B[m++]=i;
					temp=i*c;
				}
				else break;
			}	
			if(m < k)	break;
			else		ans++;
		}
		cout<<ans<<endl;
	}
}
