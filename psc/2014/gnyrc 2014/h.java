import java.math.BigInteger;
import java.util.Scanner;

class h {
	static void fuck(int t, BigInteger n) {
		BigInteger TWO = new BigInteger("2");
		BigInteger a = BigInteger.ZERO, b = BigInteger.ONE, c = BigInteger.ONE, d = new BigInteger(
				n.toString());
		BigInteger num = BigInteger.ZERO, de = BigInteger.ONE;
		BigInteger lastb = BigInteger.ONE, currentb;
		while (c.compareTo(n) <= 0) {
			BigInteger k = n.add(b).divide(d);
			BigInteger ta = a, tb = b;
			a = c;
			b = d;
			c = k.multiply(c).subtract(ta);
			d = k.multiply(d).subtract(tb);
			currentb = b;
			BigInteger tn = lastb.multiply(lastb).add(
					currentb.multiply(currentb));
			BigInteger td = lastb.multiply(currentb);
			num = num.multiply(td).add(de.multiply(tn));
			de = de.multiply(td);
			lastb = currentb;
			if (b.equals(a.multiply(TWO))) {
				break;
			}
		}
		num=num.divide(num.gcd(de));
		System.out.println(t+" "+num+"/2");
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		for (int t = 1; t <= tc; t++) {
			BigInteger x;
			x = sc.nextBigInteger();
			x = sc.nextBigInteger();
			fuck(t, x);
		}
	}
}