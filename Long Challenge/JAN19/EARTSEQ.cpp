#include<bits/stdc++.h>
using namespace std;
vector < int > pr;
bool isprime(int n)
{
	int i;
	for(i=2;i<=ceil(sqrt(n));i++)
	{
		if(n%i == 0)
			return false;
	}
	return true;
}
void gen()
{
	pr.push_back(2);
	int i;
	for(i=3;;i = i + 2)
	{
		if(isprime(i))
			pr.push_back(i);
		if(pr.size() == 25003)
			break;	
	}
}
int main()
{
	gen();
	
	
	int i,j;
	set < int  > used;
	vector < int > ans,e;
	ans.resize(50000);
	e.resize(50000);
	e[0]=1;
	
	ans[0] = 6;
	e[1] = 3;
	ans[1] = 15;
	e[2] = 5;
	int p =3;
	for(i=2;i<50000;i++)
	{
		ans[i] = 5*pr[p];
		e[i+1] = pr[p];
		i++; 
		if(i==50000)	break;
		
		ans[i] = pr[p]*3;
		e[i+1] = 3;
		i++;
		p++;
		if(i==50000)	break;
		
		ans[i] = 3*pr[p];
		e[i+1] = pr[p];
		i++;
		if(i==50000)	break;
		
		ans[i] = pr[p]*5;
		e[i+1] = 5;
		p++;	
		if(i==50000)	break;
	}
	int T;	cin>>T;
	while(T--)
	{
		int n;	cin>>n;
		if(n%2 == 0 || (n%4 == 3))
		{
			for(i=0;i<n-1;i++)
				cout<<ans[i]<<" ";
			cout<<e[i]*2<<endl;
		}
		else
		{
			
			for(i=0;i<n-2;i++)
				cout<<ans[i]<<" ";
			if(e[i] == 7)
			{
				cout<<"77 22"<<endl;	
			}
			else
			{
				cout<<e[i]*7<<" 14"<<endl;
			}
		}
	}

}
