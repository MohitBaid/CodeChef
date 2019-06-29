Mod = 1000000007
for _ in range(int(input())):
    t = list(map(int,input().split()))
    n = t[0]
    k = t[1]
    temp = (n+k-2)//(n-1)
    ans = (2*(k-1) - (temp-1)*(n-1))*temp
    ans = ans // 2
    print(ans%Mod)