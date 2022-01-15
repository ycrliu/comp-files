import java.io.*;
import java.util.*;

public class Billboard2
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("billboard.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("billboard.out")));

		int x1 = in.nextInt(), y1 = in.nextInt(), x2 = in.nextInt(), y2 = in.nextInt();
		int x3 = in.nextInt(), y3 = in.nextInt(), x4 = in.nextInt(), y4 = in.nextInt();

		// Count the number of covered corners on the lawnmower billboard
		int corners = 0;
		if(covered(x1, y1, x3, y3, x4, y4))
			corners++;
		if(covered(x2, y2, x3, y3, x4, y4))
			corners++;
		if(covered(x1, y2, x3, y3, x4, y4))
			corners++;
		if(covered(x2, y1, x3, y3, x4, y4))
			corners++;

		if(corners == 0 || corners == 1)
			out.println(area(x1, y1, x2, y2));
		else if(corners == 2)
		{
			int ox1 = Math.max(x1, x3);
			int oy1 = Math.max(y1, y3);
			int ox2 = Math.min(x2, x4);
			int oy2 = Math.min(y2, y4);
			// Because there are two corners, it is guaranteed that an overlapping region exists
			// The overlapping region is already covered by the cow billboard, so we need to cover the rest
			out.println(area(x1, y1, x2, y2) - area(ox1, oy1, ox2, oy2));
		}
		else if(corners == 4)
			out.println(0);
		out.close();

	}

	/** Checks if the point (cx1, cy1) is covered by the rectangle (x1, y1), (x2, y2). */
	public static boolean covered(int cx1, int cy1, int x1, int y1, int x2, int y2)
	{
		return cx1 >= x1 && cx1 <= x2 && cy1 >= y1 && cy1 <= y2;
	}

	public static int area(int x1, int y1, int x2, int y2)
	{
		return (y2 - y1) * (x2 - x1);
	}
}

