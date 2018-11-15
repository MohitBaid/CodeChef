//https://www.geeksforgeeks.org/longest-common-subsequence/
#include<bits/stdc++.h>
using namespace std;
int lcs( string X, string Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   return L[m][n];
}
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,m,i;	cin>>n>>m;
		string ma,mb,a,b,ta,tb;
		cin>>ma>>mb;
		a+=ma[0];
		b+=mb[0];
		int t=0;
		for(i=0;i<n;i++)
		{
			if(ma[i]!=a[t])
			{
				a+=ma[i];
				t++;
			}
		}
		t=0;
		for(i=0;i<m;i++)
		{
			if(mb[i]!=b[t])
			{
				b+=mb[i];
				t++;
			}
		}
		n=a.size();
		m=b.size();
		int a1=0,a2=0;
		a1=n+m-lcs(a,b,n,m);
		a2=n+m-lcs(b,a,m,n);
		cout<<min(a1,a2)<<endl;
	}
}
