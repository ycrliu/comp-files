import java.io.*;
import java.util.*;

public class Lifeguard1
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("lifeguards.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lifeguards.out")));

		int n = in.nextInt();
		int[][] times = new int[n][2];
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < 2; ++j)
				times[i][j] = in.nextInt();
		int ans = Integer.MIN_VALUE;
		for(int i = 0; i < n; ++i)
		{
			boolean[] active = new boolean[1001];
			for(int j = 0; j < n; ++j)
				if(i != j)
					for(int k = times[j][0]; k < times[j][1]; ++k)
						active[k] = true;
			int count = 0;
			for(int j = 0; j <= 1000; ++j)
				if(active[j])
					count++;
			ans = Math.max(count, ans);
		}
		out.println(ans);
		out.close();

	}
}

