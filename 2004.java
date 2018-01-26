import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main{ 

    static int n;

    public static boolean check(int x, int y) {
        return ((x <= n) && (n <= y));
    }

    public static void print() {
        if (check(90, 100)) {
            System.out.println("A");
            return;
        }
        if (check(80, 89)) {
            System.out.println("B");
            return;
        }
        if (check(70, 79)) {
            System.out.println("C");
            return;
        }
        if (check(60, 69)) {
            System.out.println("D");
            return;
        }
        if (check(0, 59)) {
            System.out.println("E");
            return;
        }
        System.out.println("Score is error!");
    }

    public static void main(String []args) {

        Scanner cin = new Scanner(System.in);

        while (cin.hasNext()) {
            n = cin.nextInt();
            print();
        }
    }
}