
import java.util.Stack;

public class FindRepeatNumber {
    public int findRepeatNumber(int[] nums) {
        Set<Integer> sets = new HashSet<Integer>();
        if(nums.length>0){
            for (int num : nums) {
                if(!sets.add(num)){
                    return num;
                }
            }
        }
        return  -1;
    }
}

