import java.util.Scanner;
public class twosum{
    /*given an array a and a number q, find the two numbers whose sum is q, else the most proximate lower numbers.*/
    public static void genrandom(int[] a, int range){
        for (int i = 0; i<a.length; i++){
            a[i] = (int)Math.round(Math.random()*range);
        }
        return;
    }
    
    public static void print(int[] a){
        for (int i = 0; i<a.length; i++){
            System.out.println(a[i]);
        }
    }
    
    public static int[] twoSum(int[] a, int sum){
        int i = 0;
        int j = a.length-1;
        int[] res = new int[2];
        int s;
        while (i < j){
            s = a[i]+a[j];
            if (s>sum) j--;
            if (s<sum) i++;
            if (s == sum) {
                break;
            }
        }
        res[0] = i;
        res[1] = (i==j)?j-1:j;
        return res;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in); 
        int n = sc.nextInt();
        int range = sc.nextInt();
        sc.close();

        int[] a = new int[n];
        genrandom(a, range);

        heapsort arr = new heapsort(a);
        arr.sort();
        a = arr.arr;
        int[] res = new int[2];
        res = twosum.twoSum(a,5);
        System.out.println(res[0]+" "+res[1]);
        print(a);
    }
}

class heapsort{
    public int[] arr;
    
    public heapsort(int[] arr){
        this.arr = arr;
    }

    public void sort() {
        int len = arr.length - 1;
        int beginIndex = (arr.length >> 1)- 1; //从第一个非叶节点开始
        for (int i = beginIndex; i >= 0; i--)
            maxHeapify(i, len);
        
        for (int i = len; i > 0; i--) {
            swap(0, i);
            maxHeapify(0, i - 1);
        }
    }
    void swap(int i, int j){
        arr[i] = arr[i] + arr[j];
        arr[j] = arr[i] - arr[j];
        arr[i] = arr[i] - arr[j];
    }
    
    void maxHeapify(int index, int len){
        int li = (index<<1)+1;
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