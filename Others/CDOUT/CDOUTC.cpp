 #include <iostream>  
 #include <queue>  
 using namespace std;  
 struct compare  
 {  
   bool operator()(const int& l, const int& r)  
   {  
       return l > r;  
   }  
 };  
#define MOD 1000000007
 int main()  
 {  
     priority_queue<int,vector<int>, compare > pq;  
		int n,k,i,temp,flag=0;	cin>>n>>k;
		for(i=0;i<n;i++)
		{
				cin>>temp;
				pq.push(temp);
		}
		int ans=0,sum=0;
		while(pq.size()>1&& pq.top()<k)
		{
			int p=pq.top();
			pq.pop();
			int q=pq.top();
			pq.pop();
			pq.push((p+q)*2);	
			ans++;
		}
		if(pq.top()>k)
		{
			flag=1;
			while(pq.size()!=0)
			{
				sum+=pq.top();
				pq.pop();
				sum%=MOD;
			}
		}
		if(flag)
			printf("%d %d",ans,sum%MOD);
		else
			printf("Impossible");	
}
