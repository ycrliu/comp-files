import java.io.*;
import java.util.*;

public class Triangles
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("triangles.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("triangles.out")));

		int n = in.nextInt();
		int[][] triangles = new int[n][2];
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < 2; ++j)
				triangles[i][j] = in.nextInt();
		double maxArea = Double.MIN_VALUE;
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(i != j && triangles[j][0] == triangles[i][0])
				{
					for(int k = 0; k < n; ++k)
					{
						if(i != k && j != k && triangles[k][1] == triangles[i][1])
						{
							double base = Math.abs(triangles[k][0] - triangles[i][0]);
							double height = Math.abs(triangles[j][1] - triangles[i][1]);
							maxArea = Math.max(base * height / 2.0, maxArea);
						}
					}
				}
			}
		}
		out.println((int)(2 * maxArea));
		out.close();
	}
}


