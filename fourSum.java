import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Vector; 

class ArrayIndexComparator implements Comparator<Integer>{
    private final Integer[] array;

    public ArrayIndexComparator(Integer[] array){
        this.array = array;
    }

    public Integer[] createIndexArray(){
        Integer[] indexes = new Integer[array.length];
        for (int i = 0; i < array.length; i++){
            indexes[i] = i;
        }
        return indexes;
    }

    @Override
    public int compare(Integer index1, Integer index2){
        return array[index1].compareTo(array[index2]);
    }
}
class FourSolution {
    public void print(Integer[] arr){
        for (int i = 0; i< arr.length ; i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println("");
    }

    public int findN(int i){
        int n = 0;
        while (((n-1)*n)/2 <= i) n++;
        return n-1;
    }
    public HashSet checkDupli(Integer[] indexes, int i1, int i2){
        int ti1 = indexes[i1];
        int ti2 = indexes[i2];
        int n1 = findN(ti1);
        int n2 = findN(ti2);
        int m1 = ti1-((n1-1)*n1)/2;
        int m2 = ti2-((n2-1)*n2)/2;
        HashSet<Integer> set = new HashSet<Integer>();
        set.add(n1);
        set.add(n2);
        set.add(m1);
        set.add(m2);
        return set;

    }
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> list1 = preFourSum(nums, target, 1);
        List<List<Integer>> list2 = preFourSum(nums, target, 2);
        List<List<Integer>> list3 = preFourSum(nums, target, 3);
        list1.addAll(list2);
        list1.addAll(list3);
        List<List<Integer>> listWithoutDuplicates = new ArrayList<>(new HashSet<>(list1));
        return listWithoutDuplicates;
    }
    public List<List<Integer>> preFourSum(int[] nums, int target,int flag) {
        List<List<Integer>> finalRes = new ArrayList<List<Integer>>();
        int len = ((nums.length-1)*nums.length)/2;
        Integer[] arr = new Integer[len];
        int index = 0;
        for (int i2 = 0; i2<nums.length;i2++){
            for (int i1 = 0; i1<i2; i1++){
                arr[index++] = nums[i1]+nums[i2];
            }
        }
        //print(arr);
        ArrayIndexComparator comparator = new ArrayIndexComparator(arr);
        Integer[] indexes = comparator.createIndexArray();
        Arrays.sort(indexes, comparator);
        Arrays.sort(arr);
        //print(arr);
        //print(indexes);
        int i1 = 0;
        int i2 = arr.length-1;
        while (i1<i2){
            int suspectsum = arr[i1]+arr[i2];
            if (suspectsum<target) i1++;
            if (suspectsum>target) i2--;
            if (suspectsum==target) {
                //System.out.println(i1+" "+i2);
                HashSet<Integer> suspect = checkDupli(indexes, i1, i2);
                //System.out.println(suspect.toString());
                if (suspect.size()==4){
                    List<Integer> suspectVal = new ArrayList<Integer>();
                    for (Integer element: suspect)
                        suspectVal.add(nums[element]);
                    finalRes.add(suspectVal);
                }
                //if(2*(i1+i2) <= arr.length) i1++;
                //else i2--;
                if (flag == 1) i1++;
                else if (flag == 2) i2--;
                else if (flag == 3){
                    if ((int)Math.round(Math.random())==0) i1++;
                    else i2--;
                }
            }
        }
        List<List<Integer>> listWithoutDuplicates = new ArrayList<>(new HashSet<>(finalRes));
        return listWithoutDuplicates;
        //return finalRes;
    }
    public static void main(String[] args) {
        int[] test ={-3,-2,-1,0,0,1,2,3};
        FourSolution sol = new FourSolution();

        System.out.println(sol.fourSum(test, 0).toString());
    }
}
