#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i,j,ans=-1;	scanf("%d",&n);		int A[n],sum=0;
		for(i=0;i<n;i++)	scanf("%d",&A[i]),sum+=A[i];
		int suml=0,sumr=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<i;j++)	suml+=A[j];
			for(j=i+1;j<n;j++)	sumr+=A[j];
			//cout<<i<<" "<<suml<<" "<<sumr<<endl;
			if(suml==sumr)
			{
				ans=i;
				break;
			}
			suml=sumr=0;
		}
		printf("%d\n",ans);
	}
}
