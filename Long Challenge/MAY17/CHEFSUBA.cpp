#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,p,i,c=0,j;				scanf("%d %d %d",&n,&k,&p);
	if(k>n)		k=n;			
	int A[2*n],B[2*n],res[n],temp=0; 	
	char ch[p+2];B[0]=0;
	multiset <int> myset;
	for(i=0;i<n;i++)				scanf("%d",&A[i]);
	for(;i<2*n;i++)					A[i]=A[i-n];
	for(i=0;i<k;i++)				B[0]+=A[i];
	for(;i<2*n;i++)					B[i-k+1]=B[i-k]+A[i]-A[i-k];
	for(i=0;i<=n-k;i++)				myset.insert(B[i]);
	for(j=0;j<=n;i++,j++)
	{
		multiset<int> ::iterator it;	
		res[j]=*(--myset.end());
		it=myset.find(B[j]);
		myset.erase(it);
		myset.insert(B[i]);
	}
	scanf("%s",ch);
	for(i=0;ch[i]!='\0';i++)
	{
		if(ch[i]=='?')
			printf("%d\n",res[c]);
		else
		{
			c--;
			if(c<0)
				c=n-1;
		}
	}
}
