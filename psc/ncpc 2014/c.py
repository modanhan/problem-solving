import math

d = {}

def initDictionary():
	for i in range(0, 10050):
		if i == 0:
			d[i] = 1
		else:
			d[i] = i*d[i-1]

def nCr(n,r):
    #f = math.factorial
    return d[n] / d[r] / d[n-r]

n=int(input())
initDictionary()
n+=1
ans = 0
ans = nCr(2*n, n)
ans /= (n+1)
print ans
