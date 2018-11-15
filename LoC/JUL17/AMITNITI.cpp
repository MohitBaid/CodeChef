//http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/
#include<bits/stdc++.h>
using namespace std;
long long int S[40],P[40];
bool isSubsetSum(long long int set[], int n, int sum)
{
   if (sum == 0)	   			return true;
   if (n == 0 && sum != 0)		return false;
   if (set[n-1] > sum)			return isSubsetSum(set, n-1, sum);
   return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}
int main()
{
	S[1]=2;
	S[2]=7;
	int i;
	for(i=3;i<34;i++)
		if(i%2)			S[i]=S[i-1]+3*S[i-2];
		else			S[i]=S[i-1]+7;
	P[1]=S[1];
	P[2]=S[2];
	int p=3;
	for(i=3;i<34;i=i+2)
		P[p++]=S[i];
	int T;			cin>>T;
	while(T--)
	{
		int n;	cin>>n;
		int l=0;
		int r=17;
		int flag=0;
		if(isSubsetSum(P,17,n))			cout<<"YES\n";
		else													cout<<"NO\n";
	}
}
