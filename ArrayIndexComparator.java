import java.util.Arrays;
import java.util.Comparator;

public class ArrayIndexComparator implements Comparator<Integer>
{
    private final Integer[] array;

    public ArrayIndexComparator(Integer[] array)
    {
        this.array = array;
    }

    public Integer[] createIndexArray()
    {
        Integer[] indexes = new Integer[array.length];
        for (int i = 0; i < array.length; i++)
        {
            indexes[i] = i;
        }
        return indexes;
    }

    @Override
    public int compare(Integer index1, Integer index2)
    {
        return array[index1].compareTo(array[index2]);
    }


    public static void main(String[] args) {
        Integer[] countries = {7,6,5,4,3,2,1};
        ArrayIndexComparator comparator = new ArrayIndexComparator(countries);
        Integer[] indexes = comparator.createIndexArray();
        Arrays.sort(indexes, comparator);
        Arrays.sort(countries);
        print(countries);
        print(indexes);
    }
}