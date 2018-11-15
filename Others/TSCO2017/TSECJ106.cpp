#include<bits/stdc++.h>
using namespace std;
int main()
{

	int n;	scanf("%d",&n);		int A[n],i;
	for(i=0;i<n;i++)		scanf("%d",&A[i]);
	sort(A,A+n);
	int ans=1,temp=A[0]+6;
	for(i=1;i<n;i++)
	{
		if(A[i]>temp)
		{
			ans++;
			temp=A[i]+6;
		}
	}
	printf("%d\n",ans);
}
