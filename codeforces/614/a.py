s=input()

l=int(s.split(" ")[0])
r=int(s.split(" ")[1])
k=int(s.split(" ")[2])

x=1
c=0
while(x<=r):
	if(x>=l):
		print(x,end=' ')
		c+=1
	x*=k

if(c==0):
	print(-1)
