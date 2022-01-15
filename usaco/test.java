import java.io.*;
import java.util.*;

public class test
{
	public static void main(String[] args) throws IOException
	{

		int[] arr = new int[20];
		for(int i = 1; i <= 20; i++)
			arr[i - 1] = i;
		for(int i = 0; i < arr.length; i++)
			System.out.println(arr[i]);
		sort(arr);
		for(int i = 0; i < arr.length; i++)
			System.out.println(arr[i]);
	}
	public static void sort(int[] l) {
		Arrays.sort(l);
		for(int i = 0; i < l.length-1-i; i++) {
			l[i] ^= l[l.length-1-i];
			l[l.length-1-i] ^= l[i];
			l[i] ^= l[l.length-1-i];
		}
	}

}

