//https://www.geeksforgeeks.org/sieve-eratosthenes-0n-time-complexity/
#include<bits/stdc++.h>
//#define map unordered_map
//#define set unordered_set
#define int long long int
#define MAX_SIZE 100001
using namespace std;
int prime[100000];
int pm=0;
int B[1000][10000];
map < int , int > ind;
map < int ,int > mp[1000];
map < int ,int > :: iterator mt;
set < int > s;set < int > :: iterator st; 
set < string > se;
vector<long long >isprime(MAX_SIZE , true);
vector<long long >SPF(MAX_SIZE);
void manipulated_seive(int N)
{
    isprime[0] = isprime[1] = false ;
    for (int i=2; i<N ; i++)
    {
        if (isprime[i])
        {
            prime[pm++]=i;
            SPF[i] = i;
        }
        for (int j=0;j <pm&&i*prime[j] < N && prime[j] <= SPF[i];j++)
        {
            isprime[i*prime[j]]=false;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
    for(int i=0;i<pm;i++)	ind[prime[i]]=i;
}
void match(int p,string t)
{
	if(t.size()==p)		se.insert(t);
	else
	{
		match(p,t+'0');
		match(p,t+'1');
	}
}
void generate(int pos,int ch)
{
	int p=s.size();
	int A[p],i;
	for(st=s.begin(),i=0;st!=s.end();st++,i++)
		A[i]=*st;
	se.clear();
	match(p,"");
	set < string > :: iterator it;
	for(it=se.begin();it!=se.end();it++)
	{
		string t=*it;
		int temp=1,c=0;
		for(i=0;i<t.size();i++)
			if(t[i]=='1')	
				temp*=A[i],c++;
		if(temp!=1 && c>1)
		{		
			if(ch==1)	mp[pos][temp]++;
			else		
			{
				mp[pos][temp]--;
				if(mp[pos][temp]==0)
					mp[pos].erase(temp);
			}
		}
	}
}
void factor(int i,int temp,int ch)
{
	int m=0;
	s.clear();			
	int te=temp;
	while(temp>1&& prime[m]*prime[m]<=te)
	{
		if(temp%prime[m]==0)
		{
			while(temp%prime[m]==0)
				temp/=prime[m];
			if(ch==1)		B[i][m]++;
			else			B[i][m]--;
			s.insert(prime[m]);
		}
		m++;
	}
	if(temp!=1)	
	{
		s.insert(temp);
		m=ind[temp];
		if(ch==1)		B[i][m]++;
		else			B[i][m]--;
	}
	generate(i,ch);
}
void print(int i)
{
	cout<<endl;
	for(int j=0;j<10;j++)
		cout<<B[i][j]<<" ";	
	cout<<endl;
	for(mt=mp[i].begin();mt!=mp[i].end();mt++)
		cout<<mt->first<<" "<<mt->second<<endl;
	cout<<endl;	
}
main()
{
	manipulated_seive(100001);
	freopen("input.txt","r",stdin);
	freopen("out1.txt","w",stdout);
	int n,i,j,k,Q;	cin>>n;		int A[n];
	for(i=0;i<n;i++)		cin>>A[i];
	int q=ceil(sqrt(n));
	for(i=0;i<q;i++)
	{
		for(j=i*q;j<min(n,i*q+q);j++)
			factor(i,A[j],1);
	}
	cin>>Q;
	while(Q--)
	{
		int ch;	cin>>ch;
		if(ch==1)
		{
			int pos,val;	cin>>pos>>val;
			pos--;
			int b=pos/q;
			factor(b,A[pos],-1);
			A[pos]=val;
			factor(b,A[pos],1);
		}
		else
		{
			int l,r,g;	cin>>l>>r>>g;
			s.clear();
			int temp=g,m=0;
			while(temp>1 && prime[m]*prime[m]<=g)
			{
				if(temp%prime[m]==0)
				{
					temp/=prime[m];
					s.insert(m);
				}
				else	m++;
			}
			if(temp!=1)		
			{
				m=ind[temp];
				s.insert(m);
			}
			se.clear();
			set < int > check;
			match(s.size(),"");
			set < string > :: iterator it;
			set < int > :: iterator ct;
			for(it=se.begin();it!=se.end();it++)
			{
				string t=*it;
				int temp=1;
				for(i=0;i<t.size();i++)
					if(t[i]=='1')	
						temp*=A[i];
				check.insert(temp);
			}
			l--;r--;
			int beg=l/q;
			int end=r/q;
			int ans=0;
			for(i=l;i<(beg+1)*q;i++)		if(__gcd(A[i],g)>1)		ans++;
			for(i=(end)*q;i<=r;i++)	if(__gcd(A[i],g)>1)		ans++;
			for(i=beg+1;i<end;i++)
			{
				for(ct=s.begin();ct!=s.end();ct++)		
				{
						ans+=B[i][*ct];
				}
				for(ct=check.begin();ct!=check.end();ct++)
					if(mp[i].find(*ct)!=mp[i].end())
							if(*ct!=1)
								ans-=mp[i][*ct];
			}
			cout<<r-l+1-ans<<endl;
		}
	}
}
