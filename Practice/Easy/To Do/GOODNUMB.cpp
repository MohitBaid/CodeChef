#include<stdio.h>
int checkprime(int n)
{
	int i;
	if(n==0||n==1)
		return 0;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
			return 0;	 
	}
	return 1;
}
int A[19]={4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400};
int sqfree(int n)
{
	int i;
	for(i=0;A[i]<=n;i++)
	{
		if(n%A[i]==0)
			return 0;
	}
	return 1;	
}
int main()
{
	int n;
	for(n=2;n<50;n++)
	{
		int i=1,s=0;
		if(sqfree(n))
		{
			while(i<=n)
			{
				if(n%i==0)
					s+=i;
				i++;
			}
			int c=0;
			printf("the Sum IS %d:   %d\n",n,s);
			for(i=2;i<=s;i++)
			{
				if(s%i==0)
					if(checkprime(i))
						c++;
			}
			if(checkprime(c))
				printf("%d \n",n);
		}		
	}			
}
