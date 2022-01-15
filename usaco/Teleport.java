import java.io.*;
import java.util.*;

public class Teleport
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("teleport.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("teleport.out")));

		int a = in.nextInt(), b = in.nextInt(), x = in.nextInt(), y = in.nextInt();

		int dist = Math.abs(b - a);
		dist = Math.min(Math.abs(a - y) + Math.abs(b - x), dist);
		dist = Math.min(Math.abs(a - x) + Math.abs(b - y), dist);
		out.println(dist);
		out.close();
	}
}

