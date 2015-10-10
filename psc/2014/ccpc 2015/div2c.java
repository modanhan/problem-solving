import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.concurrent.ArrayBlockingQueue;

public class div2c {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String l = sc.nextLine();
		while (!l.equals("0")) {
			String[] ss = l.split("\\+");
			int[] is = new int[ss.length];
			for (int i = 0; i < is.length; i++) {
				is[i] = Integer.parseInt(ss[i]);
			}
			ArrayList<Queue<Integer>> qs = new ArrayList<Queue<Integer>>();
			for (int i = 0; i < 10; i++) {
				qs.add(new LinkedList<Integer>());
			}
			ArrayList<Integer> ans = new ArrayList<Integer>();
			for (int i : is) {
				int m = i % 10;
				if (qs.get((10 - m) % 10).isEmpty()) {
					qs.get(m).add(i);
				} else {
					int t = qs.get((10 - m) % 10).poll();
					ans.add(t);
					ans.add(i);
				}
			}
			for (Queue<Integer> q : qs) {
				while (!q.isEmpty()) {
					ans.add(q.poll());
				}
			}
			System.out.print(ans.get(0));
			for (int i = 1; i < ans.size(); i++) {
				System.out.print("+");
				System.out.print(ans.get(i));
			}
			System.out.println();
			l = sc.nextLine();
		}
	}
}