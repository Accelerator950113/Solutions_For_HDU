import java.io.*;
import java.util.*;
import java.math.*;

public class Main{ 

	public static void main(String []args) {
		String a = null;
		int[] b = new int[32];
		int i = 0;
		int n = 0;
		char ch;
		Scanner cin = new Scanner(System.in);

		while (cin.hasNext()) {
			a = cin.nextLine();
			n = a.length();
			for (i = 0; i < 26; ++ i)
				b[i] = 0;
			for (i = 0; i < n; ++ i)
				if ((a.charAt(i) >= 'a') && (a.charAt(i) <= 'z')) b[a.charAt(i) - 'a'] ++;
			ch = 'a';
			for (i = 0; i < 26; ++ i, ++ ch)
				System.out.println(ch + ":" + b[i]);
			System.out.println();
		} 
	}
}