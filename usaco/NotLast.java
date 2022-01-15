import java.io.*;
import java.util.*;

public class NotLast
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("notlast.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("notlast.out")));

		Map<String, Integer> log = new HashMap<String, Integer>();
		String[] names = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
		for(String name : names)
			log.put(name, 0);

		int n = in.nextInt();
		for(int i = 0; i < n; ++i)
		{
			String cow = in.next();
			int amount = in.nextInt();
			log.put(cow, log.get(cow) + amount);
		}
		
		int least = 10000, secondLeast = 10000;
		for(Map.Entry<String, Integer> entry : log.entrySet())
		{
			if(entry.getValue() < least)
			{
				secondLeast = least;
				least = entry.getValue();
			}
			else if(entry.getValue() < secondLeast && entry.getValue() != least)
			{
				secondLeast = entry.getValue();
			}
		}

		// All cows have the same amount
		if(secondLeast == 10000)
		{
			out.println("Tie");
			out.close();
			return;
		}

		int secondLeastCnt = 0;
		String secondLeastCow = "";
		for(Map.Entry<String, Integer> entry : log.entrySet())
		{
			if(entry.getValue() == secondLeast)
			{
				secondLeastCnt++;
				secondLeastCow = entry.getKey();
			}
		}

		// Multiple cows tied for 2nd to last
		if(secondLeastCnt > 1)
			out.println("Tie");
		else
			out.println(secondLeastCow);
		out.close();
	}
}

