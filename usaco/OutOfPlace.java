import java.io.*;
import java.util.*;

public class OutOfPlace
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("outofplace.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("outofplace.out")));

		int n = in.nextInt();
		int[] heights = new int[n], sortedHeights = new int[n];
		for(int i = 0; i < n; ++i)
		{
			heights[i] = in.nextInt();
			sortedHeights[i] = heights[i];
		}
		Arrays.sort(sortedHeights);
		int swapsNeeded = 0;
		for(int i = 0; i < n; ++i)
			if(heights[i] != sortedHeights[i])
				swapsNeeded++;
		out.println(swapsNeeded - 1);
		out.close();
	}
}
