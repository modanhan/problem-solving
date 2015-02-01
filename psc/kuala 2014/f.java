import java.util.ArrayList;
import java.util.Scanner;

public class f {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int tc = 1; tc <= t; tc++) {
			ArrayList<ArrayList<String>> al = new ArrayList<ArrayList<String>>();
			String l = sc.next().toLowerCase();
			ArrayList<String> ts = new ArrayList<String>();
			while (!l.endsWith(".")) {
				ts.add(l);
				if (l.endsWith(",")) {
					al.add(ts);
					ts = new ArrayList<String>();
				}
				l = sc.next().toLowerCase();
			}
			ts.add(l);
			al.add(ts);

			/*
			 * for (ArrayList<String> tt : al) { for (String s : tt) {
			 * System.out.print(s + " "); } System.out.println(); }
			 */

			int r1 = 0, r2 = 0, r3 = 0, r4 = 0;

			int[] lengths = { 0, 0, 0, 0 };

			for (int i = 0; i < 4; i++) {
				if (i >= al.size()) {
					break;
				}
				for (String s : al.get(i)) {
					int modif = 0;
					if (s.contains(",") || s.contains(".")) {
						modif = 1;
					}
					if (s.length() >= 6 + modif) {
						lengths[i] += 3;
						if (s.length() == 6 + modif
								&& (s.contains("ng") || s.contains("ny"))) {
							lengths[i]--;
						}
					} else if (s.length() >= 4 + modif) {
						lengths[i] += 2;
					} else {
						if (s.length() == 3 + modif) {
							if (s.startsWith("a")) {
								lengths[i] += 1;
							} else if (s.startsWith("e")) {
								lengths[i] += 1;
							} else if (s.startsWith("i")) {
								lengths[i] += 1;
							} else if (s.startsWith("o")) {
								lengths[i] += 1;
							} else if (s.startsWith("u")) {
								lengths[i] += 1;
							} /*else if (s.startsWith("y")) {
								lengths[i]++;
							}*/
						}
						lengths[i] += 1;
					}
				}
			}

			if (lengths[0] == lengths[2] && lengths[0] != 0 && lengths[2] != 0) {
				r2 += 10;
			}
			if (lengths[1] == lengths[3] && lengths[1] != 0 && lengths[3] != 0) {
				r2 += 10;
			}
			
				for(int i:lengths){
					if(i>=8&&i<=12){
						r1+=10;
					}}
			if(al.size()>4) {
				r4 += al.size() - 4;
				r4 *= 10;
			}

			if (al.size() >= 3) {
				String s1 = al.get(0).get(al.get(0).size() - 1);
				String sub1 = s1.substring(s1.length() - 3, s1.length() - 1);
				String s2 = al.get(2).get(al.get(2).size() - 1);
				String sub2 = s2.substring(s2.length() - 3, s2.length() - 1);
				if (sub1.equals(sub2)) {
					r3 += 20;
				}
			}

			if (al.size() >= 4) {
				String s1 = al.get(1).get(al.get(1).size() - 1);
				String sub1 = s1.substring(s1.length() - 3, s1.length() - 1);
				String s2 = al.get(3).get(al.get(3).size() - 1);
				String sub2 = s2.substring(s2.length() - 3, s2.length() - 1);
				if (sub1.equals(sub2)) {
					r3 += 20;
				}
			}

			System.out.println("Case #" + tc + ": " + r1 + " " + r3 + " " + r2
					+ " " + r4 + " " + (r1 + r3 + r2 - r4));
		}

	}
}