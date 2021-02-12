
import java.util.Stack;

public class Solution {
    public String replaceSpace(String s) {
        if (s.length() <= 0) {
            return "";
        }
        char[] chars = s.toCharArray();
        String res = "";
        for (char aChar : chars) {
            if (Character.isSpaceChar(aChar)) {
                res = res + "%20";
            } else {
                res = res + aChar;
            }
        }
        return res;
    }
}

