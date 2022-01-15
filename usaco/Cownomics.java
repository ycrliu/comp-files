import java.io.*;
import java.util.*;

public class Cownomics
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("cownomics.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cownomics.out")));

		// 0 - A, 1 - C, 2 - G, 3 - T
		Map<Character, Integer> map = new HashMap<Character, Integer>();
		map.put('A', 0);
		map.put('C', 1);
		map.put('G', 2);
		map.put('T', 3);

		int n = in.nextInt(), m = in.nextInt();
		char[][] spottyGenome = new char[n][m], plainGenome = new char[n][m];
		for(int i = 0; i < n; ++i)
			spottyGenome[i] = in.next().toCharArray();
		for(int i = 0; i < n; ++i)
			plainGenome[i] = in.next().toCharArray();
		int count = 0;
		for(int i = 0; i < m; ++i)
		{
			boolean[] spotty = new boolean[4], plain = new boolean[4];
			for(int j = 0; j < n; ++j)
				spotty[map.get(spottyGenome[j][i])] = true;
			for(int j = 0; j < n; ++j)
				plain[map.get(plainGenome[j][i])] = true;
			boolean ok = true;
			for(int j = 0; j < 4; ++j)
				if(spotty[j] && plain[j])
					ok = false;
			if(ok)
				count++;
		}
		out.println(count);
		out.close();
	}
}

