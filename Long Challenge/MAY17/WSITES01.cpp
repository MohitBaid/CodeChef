#include<bits/stdc++.h>
using namespace std;
int mismatch(string a,string  b)
{
    int c=0;
	while ((a[c]!='\0'||b[c]!='\0') && a[c] == b[c]) 
        	c++;
    //cout<<a<<"  and   "<<b<<" mismatch at:"<<c<<endl;   	
    return c;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,i,b=0,ub=0,j=0,temp=0;	cin>>n;
	char ch;
	string bloc[n],unbloc[n],tem;
	int A[n];
	for(i=0;i<n;i++)
	{
		cin>>ch>>tem;
		if(ch=='+')
			unbloc[ub++]=tem;
		else
			bloc[b++]=tem;			
	}
	if(b)		sort(bloc,bloc+b);
	if(ub)		sort(unbloc,unbloc+ub);	
	if(b==n)
	{
		for(i=0;i<b;i++)
			A[i]=0;	
	}
	else
	{
		int pos=0;
		for(i=0;i<b;i++)
		{
			int max=0;
			for(j=pos;j<ub;j++)
			{
				temp=mismatch(bloc[i],unbloc[j]);					
				if(temp>max)
				{
					max=temp;
					pos=j;
				}
				else if(temp==max)	max=temp;
				else
				{
					A[i]=max;
					break;
				}	
			}
			if(j==ub)
				A[i]=max;	
		}	
	}
	int flag=0;
	for(i=0;i<b;i++)
	{
		if(A[i]==bloc[i].size())
		{
			flag=1;
			break;
		}
	}
	if(b==0)
		flag=1;
	int b2=b;	
	for(i=1;i<b;i++)
	{
		if(A[i]==A[i-1])
		{
			int flag=1;
			for(j=0;j<=A[i];j++)
				if(bloc[i][j]!=bloc[i-1][j])
					flag=0;
			if(flag)
			{
				b2--;
				A[i-1]=-1;
			}	
		}
			
	}
	if(flag)
		cout<<"-1"<<endl;
	else
	{		
		cout<<b2<<endl;
		for(i=0;i<b;i++)
		{
			for(j=0;j<=A[i];j++)
				cout<<bloc[i][j];
			if(j)
				cout<<endl;
		}
	}		
}
