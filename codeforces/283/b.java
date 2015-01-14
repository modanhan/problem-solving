import java.math.BigInteger;
import java.util.Scanner;


public class b {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		String s=sc.next();
		BigInteger min=new BigInteger(s);
		for(int i=0;i<n;i++){
			char c=s.charAt(0);
			s=s.substring(1);
			s+=c+"";
			BigInteger b=new BigInteger(s);
			min=b.min(min);
		}
		System.out.println(min);
	}
}