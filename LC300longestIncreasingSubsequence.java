import java.util.ArrayList;
import java.util.List;

class longSolution {
    public int lengthOfLIS(int[] nums) {
        if (nums.length == 0) return 0; 
        int n = nums.length;
        int[] b = new int[n];

        for (int i = 0; i<nums.length;i++){
            int s = 1;
            for (int j = 0; j < i; j++){
                if (nums[j]<nums[i]){
                    if (b[j]+1 > s) s = b[j] + 1;
                }
            }
            b[i] = s;
        }
        int max = 0;
        for (int i = 0; i<nums.length;i++){
            if (b[i]>max) max = b[i];
        }
        return max;
    }
    public static void main(String[] args) {
        int[] nums = {10,9,2,5,3,7,101,18};
        longSolution sol = new longSolution();
        System.out.println(sol.lengthOfLIS(nums));
    }
}