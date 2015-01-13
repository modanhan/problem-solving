import java.util.Scanner;

/**
 * My infinite precision arithmetic library i wrote a while ago Uses strings to
 * do arithmetic instead of byte arrays
 */
public class c {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println(div("1","323452345324"));
		String n = sc.next(), i1 = sc.next(), i2 = sc.next();
		for (int i = 1; i < n.length(); i++) {
			if (!n.substring(i).startsWith("0")) {
				String s1=n.substring(0,i);
				System.out.println(s1);
				System.out.println(mod(s1.toString(), i1.toString()));
			/*	if (mod(n.substring(0, i), i1).equals("0")) {
					if (mod(n.substring(i), i2).equals("0")) {
						System.out.println("Yes");
						return;
					}
				}*/
			}

		}
		System.out.println("NO");
	}

	/**
	 * Adds 2 numbers
	 * 
	 * @param l
	 * @param r
	 * @return
	 */
	static String add(String l, String r) {
		String ans = "";
		int longl = l.length() > r.length() ? l.length() : r.length();
		boolean left = l.length() > r.length();
		int increment = 0;
		for (int i = 0; i < longl; i++) {
			try {
				int d = Integer.parseInt(l.charAt(l.length() - 1 - i) + "")
						+ Integer.parseInt(r.charAt(r.length() - 1 - i) + "");
				d += increment;
				ans = (d % 10) + ans;
				increment = d / 10;
			} catch (StringIndexOutOfBoundsException e) {
				int d = 0;
				if (left) {
					d = Integer.parseInt(l.charAt(l.length() - 1 - i) + "");
				} else {
					d = Integer.parseInt(r.charAt(r.length() - 1 - i) + "");
				}
				d += increment;
				ans = (d % 10) + ans;
				increment = (d / 10);
			}
		}
		if (increment != 0) {
			ans = increment + ans;
		}
		return ans;
	}

	/**
	 * Subtract the right side from the left side
	 * 
	 * @param l
	 * @param r
	 * @return
	 */
	static String sub(String l, String r) {
		if (l.equals(r)) {
			return "0";
		}
		if (larger(r, l)) {
			return sub(r, l);
		}
		String ans = "";
		boolean decrement = false;
		for (int i = 1; i < l.length() + 1; i++) {
			int d = 0;
			try {
				d = Integer.parseInt(l.charAt(l.length() - i) + "")
						- Integer.parseInt(r.charAt(r.length() - i) + "");
			} catch (StringIndexOutOfBoundsException e) {
				d = Integer.parseInt(l.charAt(l.length() - i) + "");
			}
			if (decrement) {
				d--;
			}
			if (d < 0) {
				d += 10;
				decrement = true;
			} else {
				decrement = false;
			}
			ans = d + ans;
		}
		return trim0(ans);
	}

	/**
	 * Multiplies 2 numbers
	 * 
	 * @param l
	 * @param r
	 * @return
	 */
	static String mul(String l, String r) {
		String[] list = new String[r.length()];
		for (int i = 0; i < r.length(); i++) {
			String d = mul(l,
					Integer.parseInt(r.charAt(r.length() - 1 - i) + ""));
			for (int n = 0; n < i; n++) {
				d += "0";
			}
			list[i] = d;
		}
		String ans = "0";
		for (String s : list) {
			ans = add(ans, s);
		}
		return ans;
	}

	/**
	 * Multiplies a number and a small integer
	 * 
	 * @param s
	 * @param m
	 * @return
	 */
	static String mul(String s, int m) {
		String ans = "";
		int increment = 0;
		for (int i = 0; i < s.length(); i++) {
			int d = Integer.parseInt(s.charAt(s.length() - 1 - i) + "") * m;
			d += increment;
			ans = d % 10 + ans;
			increment = d / 10;
			if (i == s.length() - 1 && increment != 0) {
				ans = increment + ans;
			}
		}
		return ans;
	}

	/**
	 * Computes the exponent of a number to a small integer
	 * 
	 * @param b
	 * @param e
	 * @return
	 */
	static String exp(String b, int e) {
		if (e == 0) {
			return "1";
		} else if (e == 1) {
			return b;
		} else {
			if (e % 2 == 0) {
				return exp(mul(b, b), e / 2);
			} else {
				return mul(b, exp(mul(b, b), (e - 1) / 2));
			}
		}
	}

	/**
	 * Computes the divisor of 2 numbers
	 * 
	 * @param n
	 * @param d
	 * @return
	 */
	static String div(String n, String d) {
		if (d.equals("0")) {
			System.out.println("Div by 0 - go away");
			return null;
		}
		String upper = "1";
		if (isDiv(n, d, upper)) {
			return upper;
		}
		String lower = "0";
		if (isDiv(n, d, lower)) {
			return lower;
		}
		lower="1";
		upper="2";
		while (!largerOrEqual(mul(upper, d), n)) {
			upper = mul(upper, 2);
			lower = mul(lower, 2);
		}
		if (isDiv(n, d, upper)) {
			return upper;
		}
		String ans = divBy2(add(upper, lower));
		while (!isDiv(n, d, ans)) {
			if (larger(mul(d, ans), n)) {
				upper = ans;
				ans = divBy2(add(upper, lower));
			} else {
				lower = ans;
				ans = divBy2(add(upper, lower));
			}
		}
		return ans;
	}

	/**
	 * Computes a number divided by 2
	 * 
	 * @param n
	 * @return
	 */
	static String divBy2(String n) {
		String ans = "";
		boolean increment = false;
		for (int i = 0; i < n.length(); i++) {
			int d = Integer.parseInt(n.charAt(i) + "");
			if (increment) {
				d += 10;
			}
			increment = d % 2 == 1;
			ans += d / 2;
		}
		return trim0(ans);
	}

	/**
	 * Verifies a number of being the divisor of 2 numbers
	 * 
	 * @param n
	 * @param d
	 * @param ans
	 * @return
	 */
	static boolean isDiv(String n, String d, String ans) {
		return largerOrEqual(n, mul(d, ans))
				&& larger(mul(d, add(ans, "1")), n);
	}

	/**
	 * Computes the modulus
	 * 
	 * @param n
	 * @param d
	 * @return
	 */
	static String mod(String n, String d) {
		return sub(n, mul(div(n, d), d));
	}

	/**
	 * Computes the square root
	 * 
	 * @param s
	 * @return
	 */
	static String sqrt(String s) {
		String upper = divBy2(s);
		String lower = "2";
		String ans = divBy2(add(upper, lower));
		while (!isSqrt(s, ans)) {
			if (larger(mul(ans, ans), s)) {
				upper = ans;
			} else {
				lower = ans;
			}
			ans = divBy2(add(upper, lower));
		}
		return ans;
	}

	/**
	 * Verifies a number being the square root of another
	 * 
	 * @param s
	 * @param ans
	 * @return
	 */
	static boolean isSqrt(String s, String ans) {
		return largerOrEqual(s, mul(ans, ans))
				&& larger(mul(add(ans, "1"), add(ans, "1")), s);
	}

	/**
	 * Verifies a number being prime using the most naive algorithm
	 * 
	 * @param s
	 * @return
	 */
	static boolean isPrime(String s) {
		for (String i = "2"; larger(sqrt(s), i); i = add(i, "1")) {
			if (mod(s, i) == "0") {
				return false;
			}
		}
		return true;
	}

	/**
	 * Verifies a number being larger than another
	 * 
	 * @param left
	 * @param right
	 * @return
	 */
	static boolean larger(String left, String right) {
		if (left.length() > right.length()) {
			return true;
		} else if (left.length() == right.length()) {
			for (int i = 0; i < left.length(); i++) {
				if (Integer.parseInt(left.charAt(i) + "") > Integer
						.parseInt(right.charAt(i) + "")) {
					return true;
				} else if (Integer.parseInt(left.charAt(i) + "") < Integer
						.parseInt(right.charAt(i) + "")) {
					return false;
				}
			}
			return false;
		} else
			return false;
	}

	/**
	 * Verifies a number being larger or equal to another
	 * 
	 * @param left
	 * @param right
	 * @return
	 */
	static boolean largerOrEqual(String left, String right) {
		return larger(left, right) || left.equals(right);
	}

	/**
	 * Trims the 0s in front of a number
	 * 
	 * @param s
	 * @return
	 */
	static String trim0(String s) {
		if (s.charAt(0) == '0' && s.length() > 1) {
			return trim0(s.substring(1));
		} else {
			return s;
		}
	}
}
