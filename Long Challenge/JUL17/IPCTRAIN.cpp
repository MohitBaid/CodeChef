#include<bits/stdc++.h>
using namespace std;
struct m
{
	int s,t,d;
	 bool operator<(const m& o) const
    {
        return s < o.s;
    }

};
int compare (const void * a, const void * b)
{

  m *A = (m *)a;
  m *B = (m *)b;
  
  return ( B->s - A->s );
}
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,d,i;	cin>>n>>d;
		m t[n],f;
		int td;long long int tot=0,sc=0;
		priority_queue<m> pq[d];
		priority_queue<m> p;
		for(i=0;i<n;i++)
		{
			cin>>t[i].d>>t[i].t>>t[i].s;
			tot+=(1LL*t[i].s*t[i].t);
			t[i].d--;
			pq[t[i].d].push(t[i]);
		}	
		for(i=0;i<d;i++)
		{
			if(pq[i].size()!=0)
			{
				p.push(pq[i].top());
				pq[i].pop();
			}
			if(p.size())
			{
				f=p.top();
				sc+=f.s;
				f.t=f.t-1;
				p.pop();
				if(f.t==0)
				{
					if(pq[f.d].size()!=0)
					{
						p.push(pq[f.d].top());
						pq[f.d].pop();
					}
				}
				else		p.push(f);
				//cout<<f.s<<endl;
			}
		}
		cout<<tot-sc<<endl;
	}
}
