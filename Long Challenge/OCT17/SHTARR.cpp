#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int T,i;	cin>>T;
	while(T--)
	{
		long long int n,q;	cin>>n>>q;
		long long int A[n],J[n],ele;
		for(i=0;i<n;i++)	cin>>A[i];
		stack < long long int >st;
		stack < int  > st1;
		st.push(A[0]);
		st1.push(0);
		//printf("Pushing %d %d\n",A[0],0);
		for(i=1;i<n;i++)
		{
			long long int temp=A[i];
			int pos=i;
			if(temp<=st.top())
			{
				st.push(temp);
				st1.push(pos);
				//printf("Pushing %d %d\n",temp,pos);
			}
			else
			{
				while(1)
				{
					long long int t=st.top();
					int p=st1.top();
					st.pop();	st1.pop();
					//printf("Pop %d %d\n",t,p);
					J[p]=pos;
					if(st.size()==0)	break;
					if(st.top()>temp)	break;
				}
				st.push(temp);
				st1.push(pos);
				//printf("Pushing %d %d\n",temp,pos);
			}
		}
		while(st.size())
		{
			long long int t=st.top();
			int p=st1.top();
			st.pop();	st1.pop();
			J[p]=p;
		}
		//for(i=0;i<n;i++)	cout<<J[i]<<" ";	cout<<endl;
		int M[n];
		for(i=0;i<n;i++)	M[i]=0;
		i=0;
		while(1)
		{
			M[i]=1;
			if(i==J[i])	break;
			i=J[i];		
		}
		while(q--)
		{
			char ch;
			long long int i,L,R;	cin>>ch;
			if(ch=='?')
			{
				cin>>i>>L>>R;
				i--;
				L--;
				R--;
				long long int ans=0;
				while(1)
				{
					if(A[i]>L)
					{
						ans++;
					}
					i=J[i];
					if(i==J[i])	
					{
						ans++;
						break;
					}
				}
				cout<<ans<<endl;
			}
			else
			{
				cin>>i>>L;
				A[i]+=L;
			}	
		}	
	}
}
