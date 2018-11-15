#include<bits/stdc++.h>
using namespace std;
int A[1000000];
int P[1000000];
int C[1000000];
int c=0;
struct node
{
	int k;
	struct node *l,*r;
};
void inorder(struct node* root)
{
	if(root->l!=NULL)	inorder(root->l);
	C[c++]=root->k;
	if(root->r!=NULL)	inorder(root->r);	
}
int main()
{
    int T;	cin>>T;
    while(T--)
    {
    	int n,i,f;	cin>>n>>f;		c=0;
    	for(i=0;i<n;i++)	cin>>A[i];
		struct node *root=NULL,*root2=NULL,*temp=NULL;
		for(i=0;i<n;i++)
    	{
    		temp=(struct node*)malloc(sizeof(struct node)*1);
    		temp->k=A[i];
    		temp->l=NULL;
    		temp->r=NULL;
			if(i==0)	root=temp,root2=temp;
			else
			{
				if(A[i]>A[i-1])
				{
					root->r=temp;
					root=root->r;
				}
				else
				{
					root->l=temp;
					root=root->l;
				}
			}
    	}
		inorder(root2);
    	sort(A,A+n);
    	bool flag=true;
    	for(i=0;i<n;i++)	if(A[i]!=C[i])		flag=false;
		if(flag)	cout<<"YES\n";
		else		cout<<"NO\n";
	}
    return 0;
}
