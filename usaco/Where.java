import java.io.*;
import java.util.*;

public class Where
{
	private static boolean[][] vis;
	private static int[] dx = {1, -1, 0, 0}, dy = {0, 0, -1, 1};
	private static char[][] grid;
	private static List<PCL> pcls;
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("where.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("where.out")));

		int n = in.nextInt();
		grid = new char[n][n];
		vis = new boolean[n][n];
		pcls = new ArrayList<PCL>();
		for(int i = 0; i < n; ++i)
			grid[i] = in.next().toCharArray();
		for(int lx = 0; lx < n; ++lx)
		{
			for(int ly = 0; ly < n; ++ly)
			{
				for(int rx = lx; rx < n; ++rx)
				{
					for(int ry = ly; ry < n; ++ry)
					{
						// check the rectangle from (lx, ly) to (rx, ry)
						for(int i = lx; i <= rx; ++i)
							for(int j = ly; j <= ry; ++j)
								vis[i][j] = false;
						// Record the colors encountered and a count of their connected components
						List<Pair> colors = new ArrayList<Pair>();
						for(int i = lx; i <= rx; ++i)
							for(int j = ly; j <= ry; ++j)
								if(!vis[i][j])
								{
									dfs(i, j, lx, ly, rx, ry, grid[i][j]);
									// Update the information
									int index = -1;
									for(int k = 0; k < colors.size(); ++k)
										if(colors.get(k).color == grid[i][j])
											index = k;
									if(index == -1)
										colors.add(new Pair(grid[i][j], 1));
									else
										colors.get(index).increment();
								}
						if(colors.size() == 2 && ((colors.get(0).freq == 1 && colors.get(1).freq > 1)
								|| (colors.get(0).freq > 1 && colors.get(1).freq == 1)))
							pcls.add(new PCL(lx, ly, rx, ry));
					}
				}
			}
		}

		//check list of PCLs and count the maximal ones
		int ans = 0;
		for(int i = 0; i < pcls.size(); ++i)
		{
			boolean isMaximal = true;
			for(int j = 0; j < pcls.size(); ++j)
			{
				if(i != j && !maximal(i, j))
				{
					isMaximal = false;
					break;
				}
			}
			if(isMaximal)
				ans++;
		}

		out.println(ans);
		out.close();
	}

	public static void dfs(int x, int y, int lx, int ly, int rx, int ry, char col)
	{
		vis[x][y] = true;
		for(int k = 0; k < 4; ++k)
		{
			int nx = x + dx[k], ny = y + dy[k];
			if(nx <= rx && nx >= lx && ny <= ry && ny >= ly && !vis[nx][ny] && grid[nx][ny] == col)
			{
				dfs(nx, ny, lx, ly, rx, ry, col);
			}
		}
	}

	/** Returns true if the i-th PCL is not a subset of the j-th PCL. */
	public static boolean maximal(int i, int j)
	{
		return pcls.get(i).lx < pcls.get(j).lx || pcls.get(i).ly < pcls.get(j).ly
			|| pcls.get(i).rx > pcls.get(j).rx || pcls.get(i).ry > pcls.get(j).ry;
	}

	static class PCL
	{
		int lx, ly, rx, ry;
		public PCL(int lx, int ly, int rx, int ry)
		{
			this.lx = lx;
			this.ly = ly;
			this.rx = rx;
			this.ry = ry;
		}
	}

	static class Pair
	{
		char color;
		int freq;
		public Pair(char color, int freq)
		{
			this.color = color;
			this.freq = freq;
		}
		public void increment()
		{
			freq++;
		}
	}
}
