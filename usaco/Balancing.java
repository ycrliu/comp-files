import java.io.*;
import java.util.*;

public class Balancing
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("balancing.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("balancing.out")));
		
		int n = in.nextInt(), b = in.nextInt();
		Location[] cows = new Location[n];
		for(int i = 0; i < n; ++i)
		{
			cows[i] = new Location(in.nextInt(), in.nextInt());
		}
		Arrays.sort(cows);

		int ans = Integer.MAX_VALUE;
		for(int i = 0; i < n; ++i)
		{
			// Fix the east-west fence along the horizontal line of cows[i].x
			for(int j = 0; j < n; ++j)
			{
				// Fix the north-south fence along the vertical line of cows[j].y
				int bL = 0, tL = 0, bR = 0, tR = 0;
				for(int k = 0; k <= i; ++k)
					if(cows[k].y <= cows[j].y)
						++bL;
				for(int k = i + 1; k < n; ++k)
					if(cows[k].y <= cows[j].y)
						++tL;
				tR = n - 1 - i - tL;
				bR = i + 1 - bL;
				int m = Math.max(bL, Math.max(bR, Math.max(tL, tR)));
				ans = Math.min(m, ans);
			}
		}
		out.println(ans);
		out.close();
	}

	static class Location implements Comparable<Location>
	{
		int x, y;
		public Location(int x, int y)
		{
			this.x = x;
			this.y = y;
		}
		public int compareTo(Location l)
		{
			int diff = this.x - l.x;
			if(diff == 0)
				diff = this.y - l.y;
			return diff;
		}
	}
}

