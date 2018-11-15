#include<bits/stdc++.h>
using namespace std;
string s;
set < pair < string , int > > final,temp;
long long int R[2000000]; 
vector < long long int >  X;
struct trie
{
	map < char,trie* > mp;
	int k;
	bool end;
	long long int l;	
};
void ran(long long int n)
{
	for(long long int i=0;i<n;i++)
		R[i]=(n-i)*(n-i+1)/2;
	for(long long int i=0;i<=n;i++)
		X.push_back(i*(i+1)/2);	
}
void func(set < pair < string , int > > se)
{
	set < pair < string , int > > :: iterator it;
	if(se.size()==1)
	{
		it=se.begin();
		final.insert(*it);
		se.clear();
		return;
	}
	set < pair < string , int > > temp;
	for(it=se.begin();it!=se.end();it++)
	{
		string g=it->first;
		int k=it->second;
		int pos=g.size()+k;
		if(pos<s.size())
			g=g+s[pos];
		temp.insert(make_pair(g,k));
	}
	se.clear();
	it=temp.begin();
	string g=it->first;
	for(it=temp.begin();it!=temp.end();it++)
	{
		if(g==it->first)
		{
			se.insert(*it);
		}
		else
		{
			func(se);
			se.clear();
			g=it->first;
			se.insert(*it);
		}
	}
	func(se);
	se.clear();
	
}
trie* insert(trie* ptr,string s,int pos)
{
	int i;
	trie *t = ptr;
	int l=s.size();
	for(i=0;i<s.size();i++)
	{
		if(t->mp.find(s[i]) == t->mp.end())
		{
			trie *new_node= new trie;
			new_node->mp.clear();
			new_node->end = false;
			new_node->k=1;
			new_node->l=0;
			t->mp[s[i]] = new_node;
		}
		else
		{
			t->mp[s[i]]->k++;
		}
		if(i==l-1)
		{
			t->mp[s[i]]->end=true;
			t->mp[s[i]]->l=pos;	
		}
		else
		{
			t->mp[s[i]]->end=false;
		}
		t = t->mp[s[i]];
	}
	return ptr;
}
void print(trie *t)
{
	map < char,trie* > :: iterator it;
	for(it=t->mp.begin();it!=t->mp.end();it++)
	{
		cout<<it->first<<" "<<it->second->k<<" "<<it->second->l<<" "<<it->second->end<<endl;
		print(it->second);
	}
}
char search(long long int *bit,trie *t,long long int l,string g)
{
	char ch=0;
	//cout<<"searching"<< *bit << " " << l <<" " << g<<endl;
	map < char,trie* > :: iterator it;
	if(t->end==1)
	{
		//cout<<"df"<<endl;
		long long int k=R[t->l]-(l*(l+1))/2;
		if(*bit<=k)
		{
			int m=l+1;
			*bit = *bit + X[m];
			long long int f = *bit;
			int len=(lower_bound(X.begin(),X.end(),f) - X.begin());
			*bit = *bit % len;
			/*while(m<*bit)
			{
				*bit= *bit - m;
				m++;
			}
			*bit= *bit - 1;*/
			return s[*bit + t->l];
		}
		else
		{
			*bit-=k;
		}	
	}
	else
	{
		for(it=t->mp.begin();it!=t->mp.end() && ch==0 ;it++)
		{
			g=g+it->first;
			if((it->second->k*(l+1))>=*bit)
			{
				*bit=(*bit -1)%(l+1);
				return g[*bit];
			}
			else
			{
				*bit-=it->second->k*(l+1);
				ch=search(bit,it->second,l+1,g);
			}
			g=g.substr(0,g.size()-1);
		}
	}
	return ch;
}
int main()
{
	cin>>s;
	ran((long long int)s.size());
	set < pair < string , int > > temp,se;
	set < pair < string , int > > :: iterator it;
	for(int i=0;i<s.size();i++)		temp.insert(make_pair("",i));
	func(temp);
	trie *t;
	t = new trie;	
	t->mp.clear();
	t->end = false;
	for(it=final.begin();it!=final.end();it++)
	{
		//cout<<it->first<<" "<<it->second<<endl;
		t=insert(t,it->first,it->second);
	}
	long long int q;	cin>>q;
	long long int g=0,p,m;
	//print(t);
	while(q--)
	{
		cin>>p>>m;
		long long int bit=(p*g)%m +1LL*1;
		//cin>>bit;
		char ch=search(&bit,t,0,"");
		g+=ch;
		cout<<ch<<endl;
	}
}
