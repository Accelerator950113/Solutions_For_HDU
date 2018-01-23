import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static BigInteger san;
    static int n;

    public static void main(String []args) {

        san = new BigInteger("3");
        Scanner cin = new Scanner(System.in);

        n = cin.nextInt();
        while (cin.hasNext()) {
            n = cin.nextInt();
            System.out.println(san.pow(n));
        } 
    }
}