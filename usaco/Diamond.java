import java.io.*;
import java.util.*;

public class Diamond
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("diamond.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("diamond.out")));

		int n = in.nextInt(), k = in.nextInt();
		int[] sizes = new int[n];
		for(int i = 0; i < n; ++i)
		{
			sizes[i] = in.nextInt();
		}
		Arrays.sort(sizes);
		int ans = 0;
		for(int i = 0; i < n; ++i)
		{
			int j = i + 1;
			while(j < n && sizes[j] - sizes[i] <= k)
			{
				j++;
			}
			ans = Math.max(j - i, ans);
		}
		out.println(ans);
		out.close();
	}
}

