def dist(p,q):
	return (p[0]-q[0])*(p[0]-q[0]) + (p[1]-q[1])*(p[1]-q[1])
for _ in range (int(input())):
	r=int(input())
	ans=0
	p1=list(map(int,input().split()))
	p2=list(map(int,input().split()))
	p3=list(map(int,input().split()))
	d=dist(p1,p2)
	if d<=r*r :
		ans+=1
	d=dist(p1,p3)
	if d<=r*r :
		ans+=1
	d=dist(p3,p2)
	if d<=r*r :
		ans+=1
	if ans>=2:
		print("yes")
	else:
		print("no")