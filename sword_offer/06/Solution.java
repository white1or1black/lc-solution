
import java.util.Stack;

public class Solution {
    public int[] reversePrint(ListNode head) {
        if (head == null) {
            return new int[0];
        }
        Stack<Integer> stack = new Stack<Integer>();
        while (head != null) {
            stack.push(head.val);
            head = head.next;
        }
        int res[] = new int[stack.size()];
        int i = 0;
        while (!stack.empty()) {
            res[i] = stack.pop();
            i++;
        }
        return res;
    }
}

