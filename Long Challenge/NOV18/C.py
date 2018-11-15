T=int(input())
while T>0:
	s = list(map(int,input().split()))
	f = s[0]
	k = s[1]
	if f == 2 :
		print("0.5000000")
		continue
	while k>0:
		if f==1:
			break
		elif f<=2:
			f = 1
		elif f%2 == 0:
			if (f/2)%2 ==1:
				f = f//2+1
			else:
				f = f//2
		else:
			f =f//2 +1
		k = k-1
	ans = 1/f
	print('%.6f'%ans)
	T = T-1