import java.io.*;
import java.util.*;

public class Square
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("square.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("square.out")));

		int x1 = in.nextInt(), y1 = in.nextInt(), x2 = in.nextInt(), y2 = in.nextInt();
		int x3 = in.nextInt(), y3 = in.nextInt(), x4 = in.nextInt(), y4 = in.nextInt();

		// Get the coordinates of the rectangle that would enclose both of the above squares
		int ox1 = Math.min(x1, x3);
		int ox2 = Math.max(x2, x4);
		int oy1 = Math.min(y1, y3);
		int oy2 = Math.max(y2, y4);

		// Calculate the minimum needed square side length
		int side = Math.max(ox2 - ox1, oy2 - oy1);

		out.println(side * side);
		out.close();
	}
}

