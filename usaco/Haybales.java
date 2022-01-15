import java.io.*;
import java.util.*;

public class Haybales
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("haybales.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("haybales.out")));

		int n = in.nextInt(), q = in.nextInt();
		int[] locations = new int[n];
		for(int i = 0; i < n; ++i)
		{
			locations[i] = in.nextInt();
		}
		Arrays.sort(locations);
		for(int i = 0; i < q; ++i)
		{
			int a = in.nextInt(), b = in.nextInt();
			int lb = findLower(locations, a), ub = findUpper(locations, b);
			if(lb > n - 1)
				out.println(0);
			else
				out.println(ub - lb + 1);
		}
		out.close();
	}

	public static int findLower(int[] locations, int target)
	{
		int l = 0, r = locations.length - 1, ans = locations.length;
		while(l <= r)
		{
			int mid = l + (r - l) / 2;
			if(locations[mid] >= target)
			{
				r = mid - 1;
				ans = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		return ans;
	}

	public static int findUpper(int[] locations, int target)
	{
		int l = 0, r = locations.length - 1, ans = -1;
		while(l <= r)
		{
			int mid = l + (r - l) / 2;
			if(locations[mid] <= target)
			{
				l = mid + 1;
				ans = mid;
			}
			else
			{
				r = mid - 1;
			}
		}
		return ans;
	}
}
