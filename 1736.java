import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);
        String buf;

        while (cin.hasNext()) {
            buf = cin.nextLine();
            int i;
            int cs = 0;
            char x = '@';
            char pre;
            boolean fst = true;
            for (i = 0; i < buf.length(); ++ i) {
                pre = x;
                x = buf.charAt(i);
                if ((i+1 != buf.length()) && ((x == '<') || (x == '>'))) {
                    if ((x == buf.charAt(i+1)) && (fst)) {
                        fst = false;
                        continue;
                    }
                }
                if (x == '“' || x == '”') 
                    cs = 1 - cs;
                if (x == ',')
                    System.out.print("，");
                else if (x == '.')
                    System.out.print("。");
                else if (x == '!')
                    System.out.print("！");
                else if (x == '"') {
                    if (cs == 0) 
                        System.out.print("“");
                    else 
                        System.out.print("”");
                    cs = 1 - cs;
                }
                else if (x == '<' && pre == '<') {
                    System.out.print("《");
                    fst = true;
                }
                else if (x == '>' && pre == '>') {
                    System.out.print("》");
                    fst = true;
                }
                else if (x == '?')
                    System.out.print("？");
                else 
                    System.out.print(x);
            }
            System.out.println();
        }
    }
}