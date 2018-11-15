dist=[[0 for x in range(300)]for y in range (300)]
P=[[0 for x in range(300)]for y in range (300)]
inf=999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
def iscube(n):
	b=round(n**(1/3))
	if n==b**3:
		return 1
	else:
		return 0
def floydWarshall(graph,V):	
    for k in range(V):
        for i in range(V):
            dist[k][i]=graph[k][i]
    for k in range(V):
        for i in range(V):
            for j in range(V):
                temp=dist[i][j]
                dist[i][j] = min(dist[i][j] ,(dist[i][k]* dist[k][j])//dist[k][k])
                if temp != dist[i][j]:
                    P[i][j]=P[i][k]+P[k][j]
for _ in range (int(input())):
	n=int(input())
	A=list(map(int,input().split()))
	G=[[0 for x in range(300)]for y in range (300)]
	for i in range(n):
		for j in range(n):
			G[i][j]=inf
			if i==j:
				G[i][j]=A[i]
			P[i][j]=0
	for _ in range (0,n-1):
		s=list(map(int,input().split()))
		s[0]=s[0]-1
		s[1]=s[1]-1
		G[s[0]][s[1]]=A[s[0]]*A[s[1]]
		G[s[1]][s[0]]=A[s[0]]*A[s[1]]
		P[s[0]][s[1]]=P[s[0]][s[1]]+1
		P[s[1]][s[0]]=P[s[1]][s[0]]+1		
	floydWarshall(G,n)
	ans=-1
	for i in range(n):
		for j in range(n):
			if iscube(dist[i][j])==1:
				if ans < P[i][j]:
					ans=P[i][j]
	if ans == -1:
		print(ans)
	else:
		print(ans+1)