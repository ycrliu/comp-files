import java.io.*;
import java.util.*;

public class Cowtip
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("cowtip.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cowtip.out")));

		int n = in.nextInt();
		boolean[][] cows = new boolean[n][n]; // True - tipped
		for(int i = 0; i < n; ++i)
		{
			String s = in.next();
			for(int j = 0; j < n; ++j)
				cows[i][j] = s.charAt(j) == '1';
		}

		int count = 0;
		for(int i = n - 1; i >= 0; --i)
		{
			for(int j = n - 1; j >= 0; --j)
			{
				if(cows[i][j])
				{
					for(int k = i; k >= 0; --k)
						for(int l = j; l >= 0; --l)
							cows[k][l] = !cows[k][l];
					count++;
				}
			}
		}
		out.println(count);
		out.close();
	}
}

