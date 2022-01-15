import java.io.*;
import java.util.*;

public class CrossRoad
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("crossroad.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("crossroad.out")));

		int n = in.nextInt();
		int[][] sighting = new int[n][2];
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < 2; ++j)
				sighting[i][j] = in.nextInt();
		Arrays.sort(sighting, new Comparator<int[]>()
		{
			public int compare(int[] a, int[] b)
			{
				return Integer.valueOf(a[0]).compareTo(Integer.valueOf(b[0]));
			}
		});
		int count = 0;
		int prevCow = -1, prevLoc = -1;
		for(int i = 0; i < n; ++i)
		{
			if(prevCow == sighting[i][0] && prevLoc != sighting[i][1])
				count++;
			prevCow = sighting[i][0];
			prevLoc = sighting[i][1];
		}
		out.println(count);
		out.close();
	}
}

