#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i,j,ans=0;	cin>>n;
		int A[n];
		for(i=0;i<n;i++)	scanf("%d",&A[i]);
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				int temp=max(A[i],A[j]);
				int temp2=A[i]|A[j];
				if(temp2<=temp)
					ans++;
			}
		} 
		cout<<ans<<endl;
	}
}
