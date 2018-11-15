#include<bits/stdc++.h>
using namespace std;
struct node
{
  //int k;
  node *left;
  node *right;
};
int main()
{
	long long int T;	cin>>T;
	while(T--)
	{
		struct node *root=NULL,*p=NULL,*temp=NULL;
		long long int n,q,x=0,i;	cin>>n>>q;
		char ch[100005];
		for(i=0;i<=100000;i++)			ch[i]='0';
		temp=new struct node;
		//temp->k=0;
		temp->left=NULL;
		temp->right=NULL;
		root=temp;
		long long int ans=1;
		while(q--)
		{
			char ch2;	cin>>ch2;
			if(ch2=='!')
			{
				long long int c;	cin>>c;
				if(ch[c]=='1')
				{
					while(ch[c]=='1')
					{
						ch[c]='0';	
						c++;
					}
				}
				ch[c]='1';
				p=root;
				for(i=n-1;i>=0;i--)
				{
					if(ch[i]=='0')
					{
						if(p->left!=NULL)			p=p->left;
						else
						{
							temp=new struct node;
							//temp->k=1;
							ans++;
							temp->left=NULL;
							temp->right=NULL;
							p->left=temp;
							p=p->left;
						}
					}
					else
					{
						if(p->right!=NULL)			p=p->right;
						else
						{
							temp=new struct node;
							//temp->k=1;
							ans++;
							temp->left=NULL;
							temp->right=NULL;
							p->right=temp;
							p=p->right;
						}
					}
				}
				/*if(p->left==NULL)
				{
					temp=new struct node;
					if(temp==NULL)	
						while(temp==NULL)
							temp=new struct node;
					temp->k=1;
					temp->left=NULL;
					temp->right=NULL;
					p->left=temp;
				}
				if(p->right==NULL)
				{
					temp=new struct node;
					if(temp==NULL)	
						while(temp==NULL)
							temp=new struct node;
					temp->k=1;
					temp->left=NULL;
					temp->right=NULL;
					p->right=temp;
				}*/
			/*	p=root;
				for(i=n-1;i>=0;i--)
				{
					ans+=(p->k);
					p->k=0;
					if(ch[i]=='0')	p=p->left;
					else			p=p->right;
				}
				ans+=(p->k);
				p->k=0;*/
			}
			else			cout<<ans<<endl;
		}
		/*free(root);
		free(p);
		free(temp);*/
	}
}
