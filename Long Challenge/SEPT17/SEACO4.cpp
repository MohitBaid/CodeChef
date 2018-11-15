//http://www.geeksforgeeks.org/binary-indexed-tree-range-updates-point-queries/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long int mod(long long int n)
{
	if(n>=0)		return n%MOD;
	else
	{
		long long int q=n/MOD;
		n+=(q+1)*MOD;
		return n%MOD;
	}
}
void updateBIT(long long int BITree[], long long int n, long long int index, long long int val)
{
    index = index + 1;
    while (index <= n)
    {
        BITree[index] +=(val);
        BITree[index] = mod(BITree[index]);
		index += index & (-index);
    }
}
long long int *constructBITree(long long int n)
{
    long long int *BITree = new long long int[n+1];
    for (int i=0; i<=n; i++)
        BITree[i] = 0;
    return BITree;
}
long long int getSum(long long int BITree[], long long int index)
{
    long long int sum = 0; 
    index = index + 1;
    while (index>0)
    {
        sum += BITree[index];
        sum = mod(sum);
        index -= index & (-index);
    }
    return sum;
}
void update(long long int BITree[], long long int l, long long int r, long long int n, long long int val)
{
    updateBIT(BITree, n, l, val);
    updateBIT(BITree, n, r+1, -val);
}
int main()
{
	//cout<<mod(-5)<<" "<<mod(MOD+3)<<" "<<mod(-9)<<endl;
	int T;	cin>>T;
	while(T--)
	{
		vector < pair <int,int>  > s;
		int n,m,i,j;	cin>>n>>m;
		long long int B[m+2],C[m+2],D[m+2];
		long long int A[n+2];
		for(i=0;i<=m+1;i++)	B[i]=0,C[i]=0,D[i]=0;
		for(i=0;i<=n+1;i++)	A[i]=0;
		for(i=1;i<=m;i++)
		{
			int c,l,r;	cin>>c>>l>>r;
			s.push_back(make_pair(l,r));
			if(c==1)
			{
				//A[l]++;
				//A[r+1]--;
			}
			else
			{
				C[i]=-1;
				//B[l]++;
				//B[r+1]--;
			}
			B[i]=1;
		}
		long long int *BIT=constructBITree(m);
		for(i=m;i>=1;i--)
		{
			B[i]+=(mod(getSum(BIT,i-1)));
			B[i]=mod(B[i]);
			if(C[i]==-1)
			{
				int l=s[i-1].first;
				int r=s[i-1].second;
				update(BIT,l-1,r-1,m,B[i]);
				B[i]=0;
			}
		}
		//for(i=0;i<=m;i++)	cout<<B[i]<<" ";	cout<<endl;
		long long int *BIT2=constructBITree(n);
		for(i=1;i<=m;i++)
		{
			if(C[i]!=-1)
			{
				int l=s[i-1].first;
				int r=s[i-1].second;
				update(BIT2,l-1,r-1,n,B[i]);
			}
		}
		for(i=1;i<=n;i++)	cout<<getSum(BIT2,i-1)<<" ";	cout<<endl;
	}
}
