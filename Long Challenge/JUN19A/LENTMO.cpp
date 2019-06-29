#include <iostream>
using namespace std;
#define int long long int
main()
{
    int T;  cin>>T;
    while(T--)
    {
        int n,i,k,x;  cin>>n;
        int A[n];
        for(i=0;i<n;i++)
            cin>>A[i];
        cin>>k>>x;    
        int c = 0,sum=0,ans=0,neg_sum=0,pos_sum=0;
        int pos_min=-1,neg_max=1;
        for(i=0;i<n;i++)
        {
            sum+=A[i];
            int temp = A[i]^x;
            if(temp > A[i]) 
            {
                c++;
                pos_sum +=(temp-A[i]);
                if(pos_min == -1)
                    pos_min = temp - A[i];
                pos_min = min(pos_min,temp - A[i]);    
            }
            else
            {
                neg_sum += (temp-A[i]);
                if(neg_max == 1)
                    neg_max = temp - A[i];
                neg_max = max(neg_max,temp-A[i]);    
            }
        }
        if(k == n)
        {
            if(pos_sum + neg_sum >=0)
                ans = sum + pos_sum + neg_sum;
            else ans = sum;    
        }
        else if(k%2 == 0 && c%2 == 1)
        { 
            ans = sum + pos_sum;
            if(c!=n)
            {
                if(pos_min + neg_max > 0)
                    ans+=(neg_max);
                else
                    ans-=(pos_min);
            }
            else
            {
                    ans-=(pos_min);
            }
        }
        else    ans = sum + pos_sum;
        cout<<ans<<endl;
    }
}
