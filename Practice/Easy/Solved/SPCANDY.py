for _ in range(int(input())):
	s=list(map(int,input().split()))
	if s[1]==0:
		print(s[1],s[0],sep=' ')
	else:
		print(s[0]//s[1],s[0]%s[1],sep=' ')
