#include<bits/stdc++.h>
#include<stdio.h>
struct ABC
{
	int l;
	char type;	
};
void insert(struct ABC A[],int n,int p,int m,char c)
{
	if(p>n)
	{
			A[p].l=m;
	 		A[p].type=c;
	}
	else
	{
		for(int i=n;i>=p;i--)
	 	 {
 			 A[i+1].l=A[i].l;
 			 A[i+1].type=A[i].type;
		 }
		 A[p].l=m;
		 A[p].type=c;
	}
}
int main()
{
		freopen("in1.txt","r",stdin);
		freopen("o.txt","w",stdout);
		int T;	scanf("%d",&T);
		while(T--)
		{
			int n,i,m=0,k,f,f2;	scanf("%d %d",&n,&k);
			if(n==0)
			{
					printf("0\n");
			}
			else{
			char ch[n+2];
			scanf("%s",ch);
			int l=1,p=0;
			struct ABC A[n];
			std::priority_queue<int> q;
			for(i=1;i<=n;i++)
			{
				if(ch[i]!=ch[i-1])
				{
						A[p].l=l;
						A[p++].type=ch[i-1];
						q.push(l);
						l=1;
				}
				else
					l++;	
			}
			//for(i=0;i<p;i++)
			//		printf("%d    %c   \n",A[i].l,A[i].type);
			while(k--)
			{
				int f=q.top();
				for(i=0;i<p;i++)
				{
					if(A[i].l==f)	
						break;
				}
				if(f==1 && q.size()==1)
					break;
				if(f<2)
					break;	
				else if(f==2)
				{	
					if(i==p-1)						//........11 OR .......00
					{
						q.pop();
						q.push(1);	
						A[i].l=1;	
						char ch='0';
						if(A[i].type=='0')
							ch='1';
						insert(A,p,i+1,1,ch);			p++;
					}
					else if(i==0)					//110.... or 001.....
					{
						q.pop();
						A[i].l=1;
						char ch='0';
						if(A[i].type=='1')
							ch='1';
						if(A[i].type=='0')
							A[i].type='1';
						else
							A[i].type='0';		
						insert(A,p,i+1,1,ch);			p++;
					}
					else 
					{
						if(A[i+1].l==2)				//...1100......	 or .....0011......
						{
							if(k>=1)
							{
								q.push(1);
								q.pop();
								q.pop();
								A[i].l=1;
								A[i+1].l=1;	
								insert(A,p,i+2,1,A[i].type);			p++;
								insert(A,p,i+3,1,A[i+1].type);			p++;
								k--;
							}
							else
								break;
						}
						else if(A[i+1].l==1)		
						{
							if(i+1==p-1)			
							{
								if(A[i-1].l==1 && i!=0)			//....0110	 or .....1001
								{
									if(k>=1)
									{
										q.push(1);
										q.pop();
										q.pop();
										A[i].l=1;
										A[i+1].l=1;	
										insert(A,p,i+2,1,A[i].type);			p++;
										k--;
									}
								}
								else
									break;
							}			
							else
							{
								if(A[i+2].l==2)			//....11011..	 or .....00100..	
								{
									if(k>=2)
									{
										q.push(1);
										q.pop();
										q.pop();
										A[i].l=1;
										A[i+1].l=1;
										A[i+2].l=1;
										insert(A,p,i+3,1,A[i+1].type);			p++;
										insert(A,p,i+4,1,A[i+2].type);			p++;
										k=k-2;
									}
									else
										break;
								}
								else					//....1101..	 or .....0010..
								{
									if(k>=1)
									{
										q.push(1);
										q.pop();
										q.pop();
										A[i].l=1;
										A[i+1].l=1;
										A[i+2].l=1;
										insert(A,p,i+3,1,A[i+1].type);			p++;
										k--;;
									}
									else
										break;
								}	
							}		
						}
					}	
				}	
				else if(f%2)	
				{
					q.pop();	
					q.push(f/2);	
					q.push(f/2);
					q.push(1);
					A[i].l=f/2;
					char ch='0';
					if(A[i].type=='0')
						ch='1';
					insert(A,p,i+1,1,ch);					p++;		
					insert(A,p,i+2,f/2,A[i].type);			p++;
				}
				else
				{
					q.pop();	
					q.push(f/2);	
					q.push((f/2)-1);
					q.push(1);	
					if(i==0)
					{
						if(A[i].l==4)
						{
								A[i].l=f/2;
								char ch='0';
								if(A[i].type=='0')
									ch='1';
								insert(A,p,i+1,1,ch);					p++;		
								insert(A,p,i+2,(f/2)-1,A[i].type);		p++;
						}
						else
						{
								A[i].l=f/2-1;
								char ch='0';
								if(A[i].type=='0')
									ch='1';
								insert(A,p,i+1,1,ch);					p++;		
								insert(A,p,i+2,(f/2),A[i].type);		p++;
						}
					}
					else
					{
						if(A[i].l==4)
						{
								A[i].l=f/2-1;
								char ch='0';
								if(A[i].type=='0')
									ch='1';
								insert(A,p,i+1,1,ch);					p++;		
								insert(A,p,i+2,(f/2),A[i].type);		p++;
						}
						else
						{
								A[i].l=f/2;
								char ch='0';
								if(A[i].type=='0')
									ch='1';
								insert(A,p,i+1,1,ch);					p++;		
								insert(A,p,i+2,(f/2)-1,A[i].type);		p++;
						}	
					}
				}
				//printf("\n\n");	
				//for(i=0;i<p;i++)
				//	printf("%d    %c   \n",A[i].l,A[i].type);
			}
			printf("%d\n",q.top(),1000-T);}	
		}
}
