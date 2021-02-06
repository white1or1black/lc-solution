/**
 * Project: lc-solution
 * File created at 2021/2/4 23:49
 */
import java.util.Stack;

/**
 * 功能描述
 *
 * @author coder
 * @version 1.0
 * @type CQueue
 * @date 2021/2/4 23:49
 */
public class CQueue {
    private Stack<Integer> stackOne;
    private  Stack<Integer> stackTwo;

    public CQueue() {
        stackOne = new Stack<Integer>();
        stackTwo = new Stack<Integer>();
    }

    public void appendTail(int value) {
        stackOne.push(value);
    }

    public int deleteHead() {
        if (stackTwo.isEmpty()) {
            if (!stackOne.isEmpty()) {
                while (!stackOne.isEmpty()) {
                    stackTwo.push(stackOne.pop());
                }
                return stackTwo.pop();
            } else {
                return -1;
            }
        } else {
            return stackTwo.pop();
        }
    }
}

