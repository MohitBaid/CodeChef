#include<bits/stdc++.h>
#define int long long int
using namespace std;
main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	int T;	cin>>T;
	while(T--)
	{
		int n,s,i,k,j;	cin>>n>>s;
		int A[n],P[n],mn;
		
		for(i=0;i<n;i++)	
			cin>>A[i];
		
		if(n==1)
		{
			cout<<"2\n";
			continue;
		}
		
		set < pair < int ,int > > se;
		
		for(i=0;i<n;i++)	
			se.insert(make_pair(A[i],i));
  		
		i = 0;
  		int prev = 0;
		mn = 1;
		for(set < pair < int ,int > >:: iterator it = se.begin();it!= se.end();it++)
		{
			if(i!=0)
			{
				if(A[it->second]!=prev)
					mn++;
			}
			
			prev = A[it->second];
			A[it->second] = mn;
			P[i++] = it->second;
  		
		}
  		int B[n];
		for(k=0;k<=n;k++)
		{
  			int sum = 0;
			for(i=0;i<n;i++)			B[i] = 0;  	
			
			for(i=0;i<n;i++)
			{
  				int p = P[i];
  				int val = B[P[i]];
  				int equal = 0;
  				for(j=p+1;j<min(n,p+1+k);j++)
					if(B[j]!=0)
					{
						if(B[j]>val)
						{
							val = B[j];
							if(A[j] == A[p])	equal = 1;
							else				equal = 0;	
						}
					}  				
  				for(j=p-1;j>max(-1*1LL,p-1-k);j--)
					if(B[j]!=0)
					{
						if(B[j]>val)
						{
							val = B[j];
							if(A[j] == A[p])	equal = 1;
							else				equal = 0;	
						}
					}
					
  				B[P[i]] = val + 1;
  				if(equal)		B[P[i]]--;
  			}
  			for(i=0;i<n;i++)	
			  cout<<B[i]<<" ",sum+=B[i];
			cout<<endl;  	
  			
			if(sum>s)	
				break;
  		}
  		cout<<k<<"\n";
  		se.clear();
	}
}
