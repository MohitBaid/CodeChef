#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,q,i,j;	cin>>n>>q;
	string a[n];
	for(i=0;i<n;i++)	cin>>a[i];
	int b_size = ceil(sqrt(n));
	int n_block = ceil(n*1.0/b_size);
	for(i=0;i<n_block;i++)
	{
		for(j=i*b_size;j<min(n,i*b_size+b_size);j++)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
	
}
