
__uint128_t gcd(__uint128_t a, __uint128_t b) {
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

void ughhhhh(int t,__uint128_t n) {
	__uint128_t a = 0, b = 1, c = 1, d = n;
	__uint128_t num = 0, de = 1;
	__uint128_t lastb = 1, currentb;
	while (c <= n) {
		__uint128_t k = ((n + b) / d);
		__uint128_t ta = a, tb = b;
		a = c;
		b = d;
		c = k * c - ta;
		d = k * d - tb;
		currentb = b;
		
		__uint128_t tn = lastb * lastb + currentb * currentb;
		__uint128_t td = lastb * currentb;
		
		num = num * td + de * tn;
		de *= td;

		__uint128_t g=gcd(num,de);
		num/=g;
		de/g

		lastb = currentb;
		if (b == a * 2) {
			break;
		}
	}
	printf("%d %d/2\n",t,num);
}

int main() {
	int tc;
	scanf("%d",&tc);
	int t=1;
	while(t <= tc) {
		__uint128_t x;
		scanf("%d",&x);
		scanf("%d",&x);
		ughhhhh(t,x);
		t++;
	}
}
