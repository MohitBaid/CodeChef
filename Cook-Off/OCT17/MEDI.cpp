#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,k,i;	cin>>n>>k;
		int A[n];
		for(i=0;i<n;i++)	cin>>A[i];
		sort(A,A+n);
		if((n+k)/2 <n)	cout<<A[(n+k)/2]<<endl;
		else			cout<<"1000"<<endl;
	}
}
