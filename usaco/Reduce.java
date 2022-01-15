import java.io.*;
import java.util.*;

public class Reduce
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("reduce.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("reduce.out")));

		int n = in.nextInt();
		Cow[] locations = new Cow[n];
		int smallestX = -1, largestX = -1, smallestY = -1, largestY = -1;

		// Get the outlier cows
		int minX = Integer.MAX_VALUE, minY = Integer.MAX_VALUE, maxX = Integer.MIN_VALUE, maxY = Integer.MIN_VALUE;
		for(int i = 0; i < n; ++i)
		{
			locations[i] = new Cow(in.nextInt(), in.nextInt());
			if(locations[i].x < minX)
			{
				minX = locations[i].x;
				smallestX = i;
			}
			if(locations[i].x > maxX)
			{
				maxX = locations[i].x;
				largestX = i;
			}
			if(locations[i].y > minY)
			{
				minY = locations[i].y;
				smallestY = i;
			}
			if(locations[i].y > maxY)
			{
				maxY = locations[i].y;
				largestY = i;
			}
		}
		// Try removing the above 4
		
		int ans = getAreaWithout(locations, smallestX);
		ans = Math.min(getAreaWithout(locations, largestX), ans);
		ans = Math.min(getAreaWithout(locations, smallestY), ans);
		ans = Math.min(getAreaWithout(locations, largestY), ans);

		out.println(ans);
		out.close();
	}

	public static int getAreaWithout(Cow[] locations, int skip)
	{
		int minX = Integer.MAX_VALUE, maxX = Integer.MIN_VALUE, minY = Integer.MAX_VALUE, maxY = Integer.MIN_VALUE;
		for(int i = 0; i < locations.length; ++i)
		{
			if(i != skip)
			{
				minX = Math.min(locations[i].x, minX);
				maxX = Math.max(locations[i].x, maxX);
				minY = Math.min(locations[i].y, minY);
				maxY = Math.max(locations[i].y, maxY);
			}
		}
		return (maxY - minY) * (maxX - minX);
	}

	static class Cow implements Comparable<Cow>
	{
		int x, y;
		public Cow(int x, int y)
		{
			this.x = x;
			this.y = y;
		}
		public int compareTo(Cow other)
		{
			int diff = this.x - other.x;
			if(diff == 0)
				diff = this.y - other.y;
			return diff;
		}
	}
}

