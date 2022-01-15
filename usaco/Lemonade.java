import java.io.*;
import java.util.*;

public class Lemonade
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("lemonade.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lemonade.out")));

		int n = in.nextInt();
		int[] w = new int[n];
		for(int i = 0; i < n; ++i)
		{
			w[i] = in.nextInt();
		}
		Arrays.sort(w);

		// End loop upon encountering a cow with a w[i] less the number of cows already
		// in the line; subsequent cows certainly won't tolerate the current line
		int count = 0;
		for(int i = n - 1; i >= 0; --i)
		{
			if(w[i] < count)
			{
				break;
			}
			count++;
		}
		out.println(count);
		out.close();
	}
}
