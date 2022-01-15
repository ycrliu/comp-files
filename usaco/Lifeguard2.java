import java.io.*;
import java.util.*;

public class Lifeguard2
{
	public static void main(String[] args) throws IOException
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		Scanner in = new Scanner(new File("lifeguards.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lifeguards.out")));

		int n = in.nextInt();
		Event[] events = new Event[2 * n];

		for(int i = 0; i < n; ++i)
		{
			int start = in.nextInt(), end = in.nextInt();
			events[2 * i] = new Event(start, i);
			events[2 * i + 1] = new Event(end, i);
		}
		Arrays.sort(events);


		// Track the total amount of time any single cow is alone (this can be spread across many intervals)
		int[] loneActive = new int[n];

		int lastEvent = -1, totalActiveT = 0;
		TreeSet<Integer> active = new TreeSet<Integer>();
		for(int i = 0; i < 2 * n; ++i)
		{
			if(active.size() == 1) // Lone cow (calculate the length of the current interval during which it's alone)
			{
				loneActive[active.first()] += events[i].time - lastEvent;
			}
			if(!active.isEmpty())
			{
				totalActiveT += events[i].time - lastEvent;
			}
			if(active.contains(events[i].index)) // End of cow's shift
			{
				active.remove(events[i].index);
			}
			else // Begin cow's shift
			{
				active.add(events[i].index);
			}
			lastEvent = events[i].time;
		}
		int ans = -1;
		for(int alone : loneActive)
			ans = Math.max(totalActiveT - alone, ans);
		out.println(ans);
		out.close();
	}

	static class Event implements Comparable<Event>
	{
		int time, index;
		public Event(int t, int i)
		{
			time = t;
			index = i;
		}
		public int compareTo(Event other)
		{
			return time - other.time;
		}
	}
}
