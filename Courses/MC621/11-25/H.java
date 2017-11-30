// H. One Geometry Problem
// Rename file to Main.java

import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
      Scanner s = new Scanner(System.in);
      int t = s.nextInt();

      for(int i = 0; i < t; i++){
        BigInteger b, c, d;
        b = s.nextBigInteger();
        c = s.nextBigInteger();
        d = s.nextBigInteger();
        System.out.println(c.add(c.subtract(d.add(b))));
      }

    }
}
