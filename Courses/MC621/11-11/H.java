// H. Função Binária
// Change filename to Main.java and class name to Main

import java.io.*;
import java.util.Scanner;
import java.math.BigInteger;

public class H {
  public static void main(String[] args) {
    Scanner s = null;
    s = new Scanner(System.in);
    int t;
    t = s.nextInt();
    while(t-- > 0){
      BigInteger i = s.nextBigInteger();
      System.out.println(i.bitCount());
    }
  }
}
