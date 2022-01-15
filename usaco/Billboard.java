import java.io.*;
import java.util.*;

public class Billboard
{
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		// Scanner in = new Scanner(new File("billboard.in"));
		// PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("billboard.out")));

		// First billboard:
		int x1 = in.nextInt(), y1 = in.nextInt(), x2 = in.nextInt(), y2 = in.nextInt();
		// Second billboard:
		int x3 = in.nextInt(), y3 = in.nextInt(), x4 = in.nextInt(), y4 = in.nextInt();
		// Truck:
		int x5 = in.nextInt(), y5 = in.nextInt(), x6 = in.nextInt(), y6 = in.nextInt();

		int visible1 = area(x1, y1, x2, y2) - overlappingArea(x1, y1, x2, y2, x5, y5, x6, y6);
		int visible2 = area(x3, y3, x4, y4) - overlappingArea(x3, y3, x4, y4, x5, y5, x6, y6);

		out.println(visible1 + visible2);
		out.close();
	}

	/**
	 * Checks if the rectangle (x1, y1), (x2, y2) overlaps with (x3, y3), (x4, y4), and returns the 
	 * area of the overlapping region.
	 */
	public static int overlappingArea(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
	{
		int ox1 = Math.max(x1, x3);
		int oy1 = Math.max(y1, y3);
		int ox2 = Math.min(x2, x4);
		int oy2 = Math.min(y2, y4);
		if(ox1 > ox2 || oy1 > oy2)
			return 0;
		return area(ox1, oy1, ox2, oy2);
	}

	public static int area(int x1, int y1, int x2, int y2)
	{
		return (y2 - y1) * (x2 - x1);
	}
}

