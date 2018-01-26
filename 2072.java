import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static String s;

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);

        while (cin.hasNext()) {
            s = cin.nextLine();
            if (s.charAt(0) == '#') break;
            String[] st = s.split(" ");
            int ans = 0;
            int i, j;
            boolean flag;
            for (i = 0; i < st.length; ++ i)
                if (st[i].length() == 0) continue;
                else {
                    flag = true;
                    for (j = 0; j < i; ++ j)
                        if (st[i].compareTo(st[j]) == 0) {
                            flag = false;
                            break;
                        }
                    if (flag) ans ++;
                }
            System.out.println(ans);
        }
    }
}