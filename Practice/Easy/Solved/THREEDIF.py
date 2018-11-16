for _ in range(int(input())):
	s = list(map(int,input().split()))
	s.sort()
	ans = s[0]*(s[1]-1)*(s[2]-2)
	print(ans % 1000000007)