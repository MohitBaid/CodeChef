import math
s=set()
for _ in range(int(input())):
	s.add(0)
	str=list(map(int,input().split()))
	c=[0]*200000
	for _ in range (0,str[1]):
		st=list(input().split())
		if st[0]=='!':
			st[1] = int(st[1])
			if c[st[1]] == 1:
				while c[st[1]] == 1:
					c[int(st[1])] = 0
					st[1] = st[1] + 1
			c[st[1]]=1	
			node = 0
			for i in range(str[0]-1,-1,-1):
				if c[i] == 0:
					s.add(node)
					node = node*2 + 1
				else:
					s.add(node)
					node = node*2 + 2 
				
			s.add(node)	
		else:
			print(len(s))		