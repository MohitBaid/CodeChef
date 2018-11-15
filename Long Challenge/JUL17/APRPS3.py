import itertools
mod=1000000000+7
def sum(n, arr):
        p=-1
        ans = []
        for i in range(1,n+1):
                lst = list(itertools.combinations(range(n),i))
                sums = 0
                for j in lst:
                        pro = 1
                        for k in j:
                                pro *= arr[k]
                        sums += pro
                ans.insert(0,sums)
        for i in range(len(ans)):
            p=p*-1
            print((ans[i]*p),end="   ")
for _ in range(int(input())):
    n=int(input())
    sr=list(map(int,input().split()))
    if n==1:
        if sr[0]==1:
            print(1)
            print(mod-1,"1")
        else:
            print(2)
            sr[0]=1000000007-sr[0]
            print(str(sr[0])+" 0 1",end='')
    if n==2:
        f1=(sr[0]**0.5 +sr[1]**0.5)
        f2=(sr[0]**0.5 -sr[1]**0.5)
        f3=(-sr[0]**0.5 +sr[1]**0.5)
        f4=(-sr[0]**0.5 -sr[1]**0.5)
        lst =[f1,f2,f3,f4]
        print(len(lst))
        sum(len(lst),lst)
        print("1",end='')
    if n==3:
        f1=(sr[0]**0.5 +sr[1]**0.5 +sr[2]**0.5)
        f2=(sr[0]**0.5 -sr[1]**0.5 +sr[2]**0.5)
        f3=(sr[0]**0.5 +sr[1]**0.5 -sr[2]**0.5)
        f4=(sr[0]**0.5 -sr[1]**0.5 -sr[2]**0.5)
        f5=(-sr[0]**0.5 +sr[1]**0.5 +sr[2]**0.5)
        f6=(-sr[0]**0.5 -sr[1]**0.5 +sr[2]**0.5)
        f7=(-sr[0]**0.5 +sr[1]**0.5 -sr[2]**0.5)
        f8=(-sr[0]**0.5 -sr[1]**0.5 -sr[2]**0.5)
        lst =[f1,f2,f3,f4,f5,f6,f7,f8]
        print(lst)
        print(len(lst))
        sum(len(lst),lst)
        print("1",end='')
    print("")  