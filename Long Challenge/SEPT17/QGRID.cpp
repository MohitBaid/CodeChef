//http://www.geeksforgeeks.org/binary-indexed-tree-range-updates-point-queries/
//http://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/
#include<bits/stdc++.h>
using namespace std;
map < long long int , int > mp;
void updateBIT(long long int BITree[], long long int n, long long int index, long long int val)
{
    index = index + 1;
    while (index <= n)
    {
        BITree[index] +=(val);
        //BITree[index] = mod(BITree[index]);
		index += index & (-index);
    }
}
long long int *constructBITree(long long int n)
{
    long long int *BITree = new long long int[n+1];
    for (int i=0; i<=n; i++)
        BITree[i] = 0;
    return BITree;
}
long long int getSum(long long int BITree[], long long int index)
{
    long long int sum = 0; 
    index = index + 1;
    while (index>0)
    {
        sum += BITree[index];
        //sum = mod(sum);
        index -= index & (-index);
    }
    return sum;
}
void update(long long int BITree[], long long int l, long long int r, long long int n, long long int val)
{
    updateBIT(BITree, n, l, val);
    updateBIT(BITree, n, r+1, -val);
}
int minVal(long long int x,long long int y) { return (x < y)? x: y; }
int getMid(int s, int e) {  return s + (e -s)/2;  }
int RMQUtil(long long int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return INT_MAX;
    int mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}
int RMQ(long long int *st, int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
    return RMQUtil(st, 0, n-1, qs, qe, 0);
}
int constructSTUtil(long long int arr[], int ss, int se,long long int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}
long long int *constructST(long long int arr[], int n)
{
    long long int x = (int)(ceil(log2(n))); 
    long long int max_size = 2*1LL*(int)pow(2, x) - 1; 
    long long int *st = new long long int[max_size]; 
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}
int main()
{
	int m,n,q,i,c,j;	cin>>m>>n>>q;
	long long int temp;
	if(m==1)
	{
		for(i=0;i<n-1;i++)	cin>>temp;
		long long int *BIT=constructBITree(n+2);
		while(q--)
		{
			cin>>c;
			if(c==2)
			{
				//cout<<"sfdsdg\n";
				long long int i,j;	cin>>i>>j;
				printf("%lld\n",getSum(BIT,j-1));
			}
			else
			{
				long long int l1,r1,l2,r2,val;	cin>>l1>>r1>>l2>>r2>>val;
				if(r1<r2)	update(BIT,r1-1,r2-1,n,val);
				else 		update(BIT,r2-1,r1-1,n,val);
			}
		//cout<<q<<endl;
		}
	}
	else
	{
		long long int *BIT1=constructBITree(n+2);
		long long int *BIT2=constructBITree(n+2);
		long long int down[n];
		for(i=0;i<n;i++)	cin>>down[i];
		long long int R1[n],R2[n],d[n];
		R1[0]=0;
		R2[n-1]=0;
		for(i=1;i<n;i++)		cin>>R1[i];	
		for(i=0;i<n-1;i++)		cin>>R2[i]; 
		for(i=1;i<n;i++)		R1[i]+=R1[i-1];
		for(i=n-2;i>=0;i--)		R2[i]+=R2[i+1];
		/*for(i=0;i<n;i++)
		{
			cout<<R1[i]<<" ";
		}
		cout<<endl;
		for(i=0;i<n;i++)
		{
			cout<<R2[i]<<" ";
		}
		cout<<endl;*/
		for(i=0;i<n;i++)
		{
			//cout<<"Adding ... :"<<R2[i]<<" "<<R1[i]<<" "<<down[i]<<endl;
			d[i]=R2[i]+R1[i]+down[i];
			mp[d[i]]=i;
		}
		/*for(i=0;i<n;i++)
		{
			
			//cout<<d[i]<<" ";
		}
		cout<<endl;*/
		long long *st=constructST(d,n);
		/*for(i=0;i<n;i++)
			for(j=i;j<n;j++)
			{
				cout<<i<<" "<<j<<" "<<RMQ(st,n,i,j)<<" "<<mp[RMQ(st,n,i,j)]<<" "<<endl;
			}*/
		while(q--)
		{
			cin>>c;
			if(c==2)
			{
				long long int i,j;	cin>>i>>j;
				if(i==1)		printf("%lld\n",getSum(BIT1,j-1));
				else			printf("%lld\n",getSum(BIT2,j-1));
			}
			else
			{
				long long int l1,r1,l2,r2,val;	cin>>l1>>r1>>l2>>r2>>val;
				if(l1==l2)
				{
					if(l1==1)
					{
						if(r1<r2)	update(BIT1,r1-1,r2-1,n,val);
						else 		update(BIT1,r2-1,r1-1,n,val);
					}
					else
					{
						if(r1<r2)	update(BIT2,r1-1,r2-1,n,val);
						else 		update(BIT,r2-1,r1-1,n,val);
					}	
				}
				else
				{
					if(l2>l1)
					{
						temp=l1;
						l1=l2;
						l2=l1;
						temp=r1;
						r1=r2;
						r2=r1;
					}
					l2--;
					l1--;
					r2--;
					r1--;
					int pos=mp[RMQ(st,n,i,j)];
					update(BIT1,r1,pos,n,val);
					update(BIT2,pos,r2,n,val);
				}
			}
		}
	}
}
