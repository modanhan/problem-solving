import itertools, sys
def a(s, c):
	k = len(s)
	t = s
	for y in range(c-1): t = ''.join('G'*k if x == 'G' else s for x in t)
	return t

K = int(sys.argv[1])
C = int(sys.argv[2])


blah = [(''.join(x), a(''.join(x), C)) for x in itertools.product(['G',' '],repeat=K)]
ind = [x for x in range(len(blah[0][1])) if all(y[1][x] == 'G' for y in blah[:-1])]

for b in blah: print(b)

for x in range(len(blah[0][1])): print(len(list(y for y in blah if y[1][x] == ' ')),end=' ')


print(ind)
print(len(ind))
