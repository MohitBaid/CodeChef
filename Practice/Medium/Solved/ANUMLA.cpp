#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,temp,i;	cin>>n;
		long long int s=1<<n;
		multiset < int > sum,ans,pq,te,sum2;
		multiset < int > :: iterator it,jt;
		for(i=0;i<s;i++)
		{
			cin>>temp;
			pq.insert(temp);
		}
		//sum.insert(0);
		it=pq.begin();
		pq.erase(it);
		while(pq.size()>0)
		{
			it=pq.begin();
			int ele=*it;
			pq.erase(it);
			it=sum.find(ele);
			/*cout<<"SUM : ";
			for(jt=sum.begin();jt!=sum.end();jt++)
				cout<<*jt<<" ";	cout<<endl;
			cout<<"ANS : ";
			for(jt=ans.begin();jt!=ans.end();jt++)
				cout<<*jt<<" ";	cout<<endl;*/
			if(it!=sum.end())
			{
				sum.erase(it);
				if(*it!=0)	sum2.insert(*it);
			}
			else
			{
				for(it=sum.begin();it!=sum.end();it++)			te.insert(*it+ele);
				for(it=sum2.begin();it!=sum2.end();it++)		te.insert(*it+ele);
				for(it=te.begin();it!=te.end();it++)
				{
					sum.insert(*it);
					//cout<<"Inserting  " <<*it<<endl;
				}
				te.clear();
				for(it=ans.begin();it!=ans.end();it++)
				{
					sum.insert(*it+ele);
					//cout<<"Inserting  " <<*it+ele<<endl;
				}
				ans.insert(ele);				
			}
		}
		for(it=ans.begin();it!=ans.end();it++)	
			cout<<*it<<" ";
		cout<<endl;	
	}
}
