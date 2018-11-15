//from http://www.geeksforgeeks.org/maximum-subarray-sum-modulo-m/

// C++ program to find sub-array having maximum
// sum of elements modulo m.
#include<bits/stdc++.h>
using namespace std;
 
// Return the maximum sum subarray mod m.
#include <bits/stdc++.h>
using namespace std;

int max_mod_sum(const vector<int>& A, int M) {
    vector<int> P(A.size());
    for (int i = 0; i < A.size(); ++i)
        P[i] = (A[i] + (i > 0 ? P[i-1] : 0)) % M;
    set<int> S;
    int res = 0;
    for (int i = A.size() - 1; i >= 0; --i) {
        S.insert(P[i]);
        int a = (A[i] - P[i] + M) % M;
        auto it = S.lower_bound(M - a);
        if (it != begin(S))
            res = max(res, *prev(it) + a);
        res = max(res, (*prev(end(S)) + a) % M);
    }
    return res;
}
int main()
{
    int T;	cin>>T;
    while(T--)
    {
    	int n,i,p;	cin>>n>>p;
    	int A[n];
    	for(i=0;i<n;i++)
    			cin>>A[i];
    	int c=0;	
    	int ans=max_mod_sum(A,n,p,&c);		
    	cout<<ans<<" "<<c<<endl;
	}
    return 0;
}
