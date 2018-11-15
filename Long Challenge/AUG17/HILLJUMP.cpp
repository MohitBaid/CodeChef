#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,q,i;	cin>>n>>q;
	long long int A[n];	
	for(i=0;i<n;i++)	cin>>A[i];
	while(q--)
	{
		long long int c;			cin>>c;
		if(c==1)
		{
			long long int s,j;	cin>>s>>j;	s--;
			for(i=s;i<n&& j>0;i++)
			{
				//cout<<"A["<<i<<"]="<<A[i]<<" "<<"A["<<s<<"] ="<<A[s]<<endl;
				if(A[i]>A[s])	
				{
					
					if(i-s<=100)
					{
						j--;
						s=i;
						//cout<<"jumpimg to "<<s<<" "<<"j = "<<j<<endl;
					}
					else	break;
				}
			}
			cout<<s+1<<endl;
		}
		else
		{
			long long int l,r,x;	cin>>l>>r>>x;
			l--;
			for(i=l;i<r;i++)		A[i]+=x;
		}
	}
}
