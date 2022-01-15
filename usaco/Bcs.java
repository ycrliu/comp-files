import java.io.*;
import java.util.*;

public class Bcs
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("bcs.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("bcs.out")));

		int n = in.nextInt();
		int k = in.nextInt();
		boolean[][] original = readGrid(in, n, n);
		boolean[][][] grids = new boolean[k][n][n];
		for(int i = 0; i < k; i++)
			grids[i] = readGrid(in, n, n);
		for(int i = 0; i < k; i++)
		{
			for(int j = i + 1; j < k; j++)
			{
				for(int idi = -(n - 1); idi <= n - 1; idi++)
				{
					for(int idj = -(n - 1); idj <= n - 1; idj++)
					{
						for(int jdi = -(n - 1); jdi <= n - 1; jdi++)
						{
							for(int jdj = -(n - 1); jdj <= n - 1; jdj++)
							{
								boolean works = true;
								outer:
								for(int x = 0; works && x < n; x++)
								{
									for(int y = 0; works && y < n; y++)
									{
										boolean cellI = getCell(grids[i], x + idi, y + idj);
										boolean cellJ = getCell(grids[j], x + jdi, y + jdj);
										if((cellI && cellJ) || (original[x][y] != (cellI || cellJ)))
										{
											works = false;
											break outer;
										}
									}
								}
								if(works)
								{
									out.println((i + 1) + " " + (j + 1));
									out.close();
									return;
								}
							}
						}
					}
				}
			}
		}
	}

	public static boolean getCell(boolean[][] grid, int i, int j)
	{
		return i >= 0 && i < grid.length && j >= 0 && j < grid.length && grid[i][j];
	}

	public static boolean[][] readGrid(Scanner in, int n, int m) throws IOException
	{
		boolean[][] ret = new boolean[n][m];
		for(int i = 0; i < n; i++)
		{
			String l = in.next();
			for(int j = 0; j < m; j++)
				ret[i][j] = l.charAt(j) == '#';
		}
		return ret;
	}
}

