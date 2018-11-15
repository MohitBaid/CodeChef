#include<stdio.h>
#include<queue>
#include<vector>
#include<bits/stdc++.h>
template<typename T> void print_queue(T& q) {
    int arr[21000];
    int m=0;
	while(!q.empty()) {
        std::cout << q.top() << " ";
        arr[m++]=q.top();
		q.pop();
    }
    for(int i=0;i<m;i++)
    	q.push(arr[i]);
    std::cout << '\n';
}
using namespace std;
int main()
{
		int T;	scanf("%d",&T);
		while(T--)
		{
			int n,i,m=0,k,f,f2;	scanf("%d %d",&n,&k);
			char ch[n+2];
			scanf("%s",ch);
			int l=1;
			std::priority_queue<int> q;
			for(i=1;ch[i-1]!='\0';i++)
			{
				if(ch[i]!=ch[i-1])
				{
						q.push(l);
						l=1;
				}
				else
					l++;	
			}
			//print_queue(q);
			//printf("\n\n\n");
			while(k--)
			{
				f=q.top();
				if(f==1 && q.size()==1)
					break;
				if(f<2 )
					break;	
				else if(f==2)
				{
					q.pop();	
					f2=q.top();
					if(q.size()>0)
					{
							q.pop();
							q.push(1);
							q.push(f2+1);
					}
					else
					{	
							q.push(1);
							q.push(1);
					}
				}
				else if(f%2)	
				{
					q.pop();	
					q.push(f/2);	
					q.push(f/2);
					q.push(1);		
				}
				else
				{
					q.pop();	
					q.push(f/2);	
					q.push((f/2)-1);
					q.push(1);	
				}
				//print_queue(q);
			}
			printf("%d\n",q.top());	
							
		}
}
