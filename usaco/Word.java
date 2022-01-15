import java.io.*;
import java.util.*;

public class Word
{
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		// Scanner in = new Scanner(new File("word.in"));
		// PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("word.out")));

		int n = in.nextInt(), k = in.nextInt();
		String[] essay = new String[n];
		for(int i = 0; i < n; ++i)
			essay[i] = in.next();
		int i = 0;
		while(i < n)
		{
			int j = i, curLength = 0;
			while(j < n)
			{
				if(curLength + essay[j].length() <= k)
					curLength += essay[j].length();
				else
					break;
				++j;
			}
			for(int it = i; it < j; ++it)
				out.print(essay[it] + (it != j - 1 ? " " : ""));
			out.println();

			i = j;
		}
		out.close();
	}
}

