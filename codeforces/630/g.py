def w3(n): # num of ways n num sum to 3
	return (n+3-1)*(n+3-2)*(n+3-3)//2//3
	
def w5(n): # num of ways n num sum to 3
	return (n+5-1)*(n+5-2)*(n+5-3)*(n+5-4)*(n+5-5)//2//3//4//5

n=int(input())
print(w3(n)*w5(n))
