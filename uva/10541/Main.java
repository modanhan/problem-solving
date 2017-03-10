import java.util.*;
import java.math.BigInteger;
import java.lang.*;



class Main{
	static int n,l;
	static int[] a;
	
	static BigInteger n1=new BigInteger("-1");
	
	static BigInteger[][] dp;
	//dp[i][j] = # of ways to fit a[i]...a[l-1] in j spots.
	//dp[0][n] = ans
	
	static BigInteger f(int i, int j){
		if(!dp[i][j].equals(n1))return dp[i][j];
		if(i==l-1){
			if(j>=a[i]){
				BigInteger bj=new BigInteger(j+""),
				bai=new BigInteger(a[i]+"");
				dp[i][j]=bj.add(BigInteger.ONE).subtract(bai);
				return dp[i][j];
			}
			else {dp[i][j]=BigInteger.ZERO;return dp[i][j];}
		}
		BigInteger ans=BigInteger.ZERO;
		for(int x=a[i]+1;x<j;x++){
			ans=ans.add(f(i+1,j-x));
		}
		dp[i][j]=ans;
		return ans;
	}
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int tc=0;tc<t;tc++){
			n=sc.nextInt();
			l=sc.nextInt();
			a=new int[l];
			dp=new BigInteger[l][n+1];
			for(int i=0;i<l;i++){
				for(int j=0;j<n+1;j++){
					dp[i][j]=n1;
				}
			}
			for(int i=0;i<l;i++){
				a[i]=sc.nextInt();
			}
			if(l==0)System.out.println(1);
			else System.out.println(f(0,n));
		}
	}
}