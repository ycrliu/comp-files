import java.io.*;
import java.util.*;

public class Blocks
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("blocks.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("blocks.out")));

		int n = in.nextInt();
		int[] minNeeded = new int[26];
		for(int i = 0; i < n; ++i)
		{
			String t = in.next(), b = in.next();
			int[] tC = new int[26], bC = new int[26];
			for(int j = 0; j < t.length(); ++j)
				tC[t.charAt(j) - 'a']++;
			for(int j = 0; j < b.length(); ++j)
				bC[b.charAt(j) - 'a']++;
			for(int j = 0; j < 26; ++j)
				minNeeded[j] += Math.max(tC[j], bC[j]);
		}
		for(int i = 0; i < 26; ++i)
			out.println(minNeeded[i]);
		out.close();
	}
}

