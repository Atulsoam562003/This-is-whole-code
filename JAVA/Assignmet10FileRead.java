import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

public class Assignmet10FileRead {

  public static void main(String[] args) throws Exception {
    try {
      ;
      File f1 = new File(args[0]);
      File f2 = new File(args[1]);
      BufferedReader br1 = new BufferedReader(new FileReader(f1));
      BufferedReader br2 = new BufferedReader(new FileReader(f2));
      String str1 = "", str2 = "";
      while (((str1 = br1.readLine()) != null) && ((str2 = br2.readLine()) != null)) {
        String[] words1 = str1.split(" ");
        String[] words2 = str2.split(" ");
        int len = max(words1.length, words2.length);
        int pos = 0;
        for (int i = 0; i < len; i++) {
          if (words1[i].equalsIgnoreCase(words2[i])) {
            System.out.println(
                "Match: " +
                    words1[i] +
                    ", Length: " +
                    words1[i].length() +
                    ", Position: " +
                    pos++);
          }
        }
      }
      br1.close();
      br2.close();
    } catch (Exception e) {
      System.out.println("Error parsing files");
      System.exit(1);
    }
  }

  private static int max(int length, int length2) {
    if (length > length2) {
      return length;
    }
    return length2;
    // return 0;
  }
}
