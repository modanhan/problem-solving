import java.util.Arrays;
import java.util.Scanner;

public class a{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int limak = sc.nextInt();
		n--;
		
		int [] list = new int[n];
		for (int x = 0; x < n; x++){
			list[x] = sc.nextInt();	
		}
		
		Arrays.sort(list);
		int count = 0; 
		
		while (limak <= list[n - 1]){
			
			list[n-1]--;
			limak++;
			count++;
			Arrays.sort(list);
		}
		
		System.out.print(count);
	}
}