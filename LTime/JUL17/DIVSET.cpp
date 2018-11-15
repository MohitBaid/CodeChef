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
		int i,j;
		long long int A[n];
		for(i=0;i<n;i++)	cin>>A[i],H[A[i]]++;
		int ans=0;
		map <long long int,int> :: iterator it;
		while(1)
		{
			long long int m=0,flag2,temp=0,val;
			for(i=0;i<k;i++)
			{
				flag2=1;
				it=H.begin();
				for(;it!=H.end();it++)
					if(it->first>=temp)
					{
						flag2=0;
						val=it->first;
						temp=val*c;
						H[val]--;
						if(H[val]==0)		H.erase(val);
						break;
					}
				if(flag2)	break;	
			}	
			if(i!=k)		break;
			else		ans++;
		}
		cout<<ans<<endl;
	}
}
