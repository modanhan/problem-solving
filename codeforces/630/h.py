n=int(input())
ans=(n)*(n-1)*(n-2)*(n-3)*(n-4)
ans//=1*2*3*4*5
ans*=(n)*(n-1)*(n-2)*(n-3)*(n-4)
print(ans)
