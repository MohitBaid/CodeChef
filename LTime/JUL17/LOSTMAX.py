for _ in range(int(input())):
	str=list(map(int,input().split()))
	l=len(str)
	str.sort()
	if str[l-1]!=l-1:
		print(str[l-1])
	else:
		print(str[l-2])