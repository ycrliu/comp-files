import java.io.*;
import java.util.*;

public class Buckets
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("buckets.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("buckets.out")));

		char[][] grid = new char[10][10];
		for(int i = 0; i < 10; ++i)
			grid[i] = in.next().toCharArray();
		
		int bI = -1, bJ = -1, rI = -1, rJ = -1, lI = -1, lJ = -1;
		for(int i = 0; i < 10; ++i)
		{
			for(int j = 0; j < 10; ++j)
			{
				if(grid[i][j] == 'B')
				{
					bI = i;
					bJ = j;
				}
				else if(grid[i][j] == 'R')
				{
					rI = i;
					rJ = j;
				}
				else if(grid[i][j] == 'L')
				{
					lI = i;
					lJ = j;
				}
			}
		}

		int dist = Math.abs(bI - lI) + Math.abs(bJ - lJ) - 1;
		if((bI == rI && rI == lI) && ((bJ < rJ && rJ < lJ) || (lJ < rJ && rJ < bJ)))
		{
			dist += 2;
		}
		else if((bJ == rJ && rJ == lJ) && ((bI < rI && rI < lI) || (lI < rI && rI < bI)))
		{
			dist += 2;
		}
		out.println(dist);
		out.close();
	}
}

