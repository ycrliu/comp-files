import java.io.*;
import java.util.*;

public class Convention
{
	public static int n, m, c;
	public static int[] arrivals;

	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("convention.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("convention.out")));

		n = in.nextInt();
		m = in.nextInt();
		c = in.nextInt();
		arrivals = new int[n];
		for(int i = 0; i < n; ++i)
		{
			arrivals[i] = in.nextInt();
		}
		Arrays.sort(arrivals);
		int l = 0, r = 1000000005, ans = -1;
		while(l <= r)
		{
			int mid = l + (r - l) / 2;
			if(ok(mid))
			{
				ans = mid;
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}

		out.println(ans);
		out.close();
	}

	/** Check if there exists enough buses to meet the required maximum loading time for each bus. */
	public static boolean ok(int time)
	{
		int curBus = 0, totalBuses = 0, startT = arrivals[0];
		for(int i = 0; i < n; ++i)
		{
			if(curBus == c || arrivals[i] - startT > time)
			{
				totalBuses++;
				curBus = 1;
				startT = arrivals[i];
			}
			else
				curBus++;
		}
		return totalBuses + 1 <= m;
	}
}
