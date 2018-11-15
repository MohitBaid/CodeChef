#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j,ans=0;	cin>>n;
	int A[n],S[n];	
	for(i=0;i<n;i++)
		cin>>A[i];
	S[0]=A[0];
	for(i=1;i<n;i++)
		S[i]=A[i]+S[i-1];
	for(i=0;i<n;i++)
	{
		int temp=0;
		for(j=0;j<i;j++)
		{
				temp+=A[j];
				cout<<temp<<endl;
		}
		temp=S[i]-temp;
		ans^=temp;
	}
	cout<<ans<<endl;
}
