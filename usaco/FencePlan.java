import java.io.*;
import java.util.*;

public class FencePlan
{
	public static Cow[] cows;
	public static List<Integer>[] adj;
	public static boolean[] vis;
	public static int minX = Integer.MAX_VALUE, maxX = Integer.MIN_VALUE, minY = Integer.MAX_VALUE, maxY = Integer.MIN_VALUE;
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("fenceplan.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("fenceplan.out")));

		int n = in.nextInt(), m = in.nextInt();
		cows = new Cow[n];
		adj = new List[n];
		vis = new boolean[n];
		for(int i = 0; i < n; ++i)
		{
			cows[i] = new Cow(in.nextInt(), in.nextInt());
			adj[i] = new ArrayList<Integer>();
		}
		for(int i = 0; i < m; ++i)
		{
			int a = in.nextInt() - 1, b = in.nextInt() - 1;
			adj[a].add(b);
			adj[b].add(a);
		}
		int minPerim = Integer.MAX_VALUE;
		for(int i = 0; i < n; ++i)
		{
			//explore the entire component
			//need min X, max X, min Y, max Y
			if(!vis[i])
			{
				dfs(i);
				minPerim = Math.min(2 * ((maxY - minY) + (maxX - minX)), minPerim);
				minX = Integer.MAX_VALUE;
				maxX = Integer.MIN_VALUE;
				minY = Integer.MAX_VALUE; 
				maxY = Integer.MIN_VALUE;
			}
		}
		out.println(minPerim);
		out.close();
	}

	public static void dfs(int u)
	{
		minX = Math.min(cows[u].x, minX);
		maxX = Math.max(cows[u].x, maxX);
		minY = Math.min(cows[u].y, minY);
		maxY = Math.max(cows[u].y, maxY);
		vis[u] = true;
		for(int v : adj[u])
			if(!vis[v])
				dfs(v);
	}

	static class Cow
	{
		int x, y;
		public Cow(int x, int y)
		{
			this.x = x;
			this.y = y;
		}
	}
}
