import java.io.*;
import java.util.Scanner;
import java.math.BigInteger;

public class G {
    public static void main(String[] args) throws IOException {

        Scanner s = null;
        try {
            s = new Scanner(System.in);
            int t;
            t = s.nextInt();
            for(int i = 0; i < t; i++){
              BigInteger fact = new BigInteger("1");
              int n;
              n = s.nextInt();
              while(n > 1){
                fact = fact.multiply(BigInteger.valueOf(n));
                n--;
              }

              System.out.println(fact);

          }
        } finally {
            if (s != null) {
                s.close();
            }
        }
    }
}
