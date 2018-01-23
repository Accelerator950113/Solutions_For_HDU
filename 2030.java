import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);
        String st;
        int l, s, i;

        st = cin.nextLine();
        while (cin.hasNext()) {
            st = cin.nextLine();
            l = st.length();
            s = 0;
            for (i = 0; i < l; ++ i)
                if (st.charAt(i) > 255) s ++;
            System.out.println(s);
        } 
    }
}