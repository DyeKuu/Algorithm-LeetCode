import java.util.Scanner;

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
    /*given an array a and a number q, find the two numbers whose sum is q, else the most proximate lower numbers.*/
    public static void genrandom(int[] a, int range){
        for (int i = 0; i<a.length; i++){
            a[i] = (int)Math.round(Math.random()*range);
        }
        return;
    }
    
    public static void main(String[] args){
        /*input: n, range. n is the size, range is the data range of array*/
        Scanner sc = new Scanner(System.in); 
        int n = sc.nextInt();
        int range = sc.nextInt();
        sc.close();
        int[] a = new int[n];
        genrandom(a, range);
        heapsort aa = new heapsort(a);
        aa.sort();
        for (int i = 0; i<a.length; i++){
            System.out.println(aa.arr[i]);
        }
        
    }
}