import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.*;

class Solution {
    public void print(int[] arr){
        for (int i = 0; i< arr.length ; i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println("");
    }
    public boolean isZero(int[] nums){
        if (nums.length==0) return false;
        for (int i=0;i<nums.length;i++){
            if (nums[i]!=0) return false;
        }
        return true;
    }
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> finalres = new ArrayList<List<Integer>>();
        if (nums.length < 3){
            return finalres;
        }
        if (isZero(nums)){
            List<Integer> suspect = new ArrayList<Integer>();
            suspect.add(Integer.valueOf(0));
            suspect.add(Integer.valueOf(0));
            suspect.add(Integer.valueOf(0));
            finalres.add(suspect);
            return finalres;
        }
        heapsort arr = new heapsort(nums);
        arr.sort();
        nums = arr.arr;
        //print(nums);
        int sumObject;
        for (int i = 0; i < nums.length; i++) {
            sumObject = -nums[i];
            int[] newarr = new int[nums.length - 1];
            int flag = 0;
            for (int j = 0; j < nums.length; j++) {
                if (j == i) {
                    flag = 1;
                    continue;
                }
                newarr[j-flag] =nums[j];
            }
            int i1 = 0;
            int i2 = newarr.length-1;
            while (i1<i2){
                int suspectsum = newarr[i1]+newarr[i2];
                if (suspectsum<sumObject) i1++;
                if (suspectsum>sumObject) i2--;
                if (suspectsum==sumObject) {
                    List<Integer> suspect = new ArrayList<Integer>();
                    suspect.add(Integer.valueOf(-sumObject));
                    suspect.add(Integer.valueOf(newarr[i1]));
                    suspect.add(Integer.valueOf(newarr[i2]));
                    Collections.sort(suspect);
                    finalres.add(suspect);
                    i1++;
                }
            }
            //print(newarr);
            //finalres.addAll(suspect);
        }
        List<List<Integer>> listWithoutDuplicates = new ArrayList<>(new HashSet<>(finalres));
        return listWithoutDuplicates;
    }
    public static void main(String[] args) {
        int[] test = new int [16];
        /*test[0] = -4;
        test[1] = -2;
        test[2] = -2;
        test[3] = -2;
        test[4] = 0;
        test[5] = 1;
        test[6] = 2;
        test[7] = 2;
        test[8] = 2;
        test[9] = 3;
        test[10] = 3;
        test[11] = 4;
        test[12] = 4;
        test[13] = 6;
        test[14] = 6;
        */
        for (int i = 0; i<test.length;i++){
            test[i]=0;
        }
        Solution sol = new Solution();
        List<List<Integer>> solution = sol.threeSum(test);
        System.out.println(solution.toString());
    }
}

class heapsort {
    public int[] arr;

    public heapsort(int[] arr) {
        this.arr = arr;
    }

    public void sort() {
        int len = arr.length - 1;
        int beginIndex = (arr.length >> 1) - 1;
        for (int i = beginIndex; i >= 0; i--)
            maxHeapify(i, len);

        for (int i = len; i > 0; i--) {
            swap(0, i);
            maxHeapify(0, i - 1);
        }
    }

    void swap(int i, int j) {
        arr[i] = arr[i] + arr[j];
        arr[j] = arr[i] - arr[j];
        arr[i] = arr[i] - arr[j];
    }

    void maxHeapify(int index, int len) {
        int li = (index << 1) + 1;
        int ri = li + 1;
        int cMax = li;
        if (li>len) return;
        if(ri<=len && arr[ri]>arr[li]) cMax=ri;
        if(arr[cMax]>arr[index]){
            swap(index, cMax);
            maxHeapify(cMax, len);
        }
    }
}