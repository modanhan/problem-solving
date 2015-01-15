import java.util.Scanner;

class Main{
	
	public static void main(String[] args) {
		
		Scanner x = new Scanner(System.in);
		int o = x.nextInt();
		
		int y = 1;
		while(y <= o){
		int a = x.nextInt();
		int	b = x.nextInt();
		
		if(a<b)
		{
			System.out.println("<");
		}
		else if(a>b)
		{
			System.out.println(">");
		}
		else
			System.out.println("=");
		y++;
		}
	}
}