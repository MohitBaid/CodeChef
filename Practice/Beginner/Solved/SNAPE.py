import math
for _ in range(int(input())):
	str=list(map(int,input().split()))
	print(math.sqrt(str[1]*str[1]-str[0]*str[0]),math.sqrt(str[1]*str[1]+str[0]*str[0]))