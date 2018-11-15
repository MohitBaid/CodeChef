#include<bits/stdc++.h>
using namespace std;
double check(double A[],double k,double number,int c,double m)
{
	if(number>k)			return 0;
	if(c==-1)				return 1;
	if(c && number*m<=k)	return pow(2,c+1) ;			
	return 		check(A,k,number*A[c],c-1,m/A[c]) + check(A,k,number,c-1,m/A[c]);
}
int main()
{
		double k,m=1; int n,i;		scanf("%d %lf",&n,&k);
		double A[n];
		for(i=0;i<n;i++)
		{		
				scanf("%lf",&A[i]);
				m=m*A[i];
		}
		sort(A,A+n);
		double ans=check(A,k,1,n-1,m)  -1;			
		long long int k1=(long long int)ans;
		printf("%lld",k1);
}		
