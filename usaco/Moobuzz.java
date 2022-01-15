import java.io.*;
import java.util.*;

public class Moobuzz
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("moobuzz.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("moobuzz.out")));

		long n = in.nextInt();
		/*
		 * we want the n-th number that is not divisible by 3 or 5
		 * # of numbers <= n that are divisible by 3 or 5 = ((n/3) + (n/5) - (n/15))
		 * some number x that is >= n
		 * x - ((x/3) + (x/5) - (x/15)) == n
		 * find the lowest value of x (binary search for single answer)
		 */

		long l = 0, r = 5 * n, ans = -1;
		while(l <= r)
		{
			long x = l + (r - l) / 2;
			long num = x - x/3 - x/5 + x/15;
	 		if(num >= n)
			{
				ans = x;
				r = x - 1;
			}
			else
				l = x + 1;
		}
		out.println(ans);
		out.close();
	}
}
