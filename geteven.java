import java.io.*;
import java.util.*;

public class geteven {

  static Scanner in;
  static PrintWriter out;

  public static void main(String[] args) throws Exception {
    in = new Scanner(new File("geteven.in"));
    out = new PrintWriter(new BufferedWriter(new FileWriter("geteven.out")));

    char[] all = "BESIGOM".toCharArray();

    // count even and odd occurrences
    int[][] cnt = new int[255][2]; // [0] = even, [1] = odd

    /*
     * e.g. for B=[2,3,4], E=[3,4]
     *
     *    ABCDEFGHIJKLMNOPQRSTUVWXYZ
     * 0  -2--1---------------------
     * 1  -1--1---------------------
     *
     */

    int n = in.nextInt();
    for (int i = 0; i < n; i++) {
      char c = in.next().charAt(0);
      int v = in.nextInt();
      cnt[c][Math.abs(v % 2)]++;
    }

    // go through all combinations
    int ans = 0;
    for (int B = 0; B < 2; B++) {
      for (int E = 0; E < 2; E++) {
        for (int S = 0; S < 2; S++) {
          for (int I = 0; I < 2; I++) {
            for (int G = 0; G < 2; G++) {
              for (int O = 0; O < 2; O++) {
                for (int M = 0; M < 2; M++) {
                  if (
                    (B + E + S + S + I + E) *
                    (G + O + E + S) *
                    (M + O + O) %
                    2 ==
                    0
                  ) {
                    ans +=
                      cnt['B'][B] *
                      cnt['E'][E] *
                      cnt['S'][S] *
                      cnt['I'][I] *
                      cnt['G'][G] *
                      cnt['O'][O] *
                      cnt['M'][M];
                  }
                }
              }
            }
          }
        }
      }
    }

    System.out.println(ans);
    out.println(ans);

    out.close();
  }
}
