package sort;


import java.util.Arrays;

public class MergeSort {

    public int[] sort(int[] data) {
        if (data.length <= 1)
            return data;

        int[] a = new int[data.length / 2];
        int[] b = new int[data.length - data.length / 2];

        System.arraycopy(data, 0, a, 0, a.length);
        System.arraycopy(data, data.length / 2, b, 0, b.length);

        return merge(sort(a), sort(b));
    }

    public int[] merge(int[] a, int[] b) {
        int[] res = new int[a.length + b.length];

        int i = 0;
        int j = 0;
        for (int k = 0; k < res.length; k += 1) {
            if (i >= a.length) {
                res[k] = b[j];
                j += 1;
            } else if (j >= b.length) {
                res[k] = a[i];
                i += 1;
            }  else if (a[i] <= b[j]) {
                res[k] = a[i];
                i += 1;
            } else {
                res[k] = b[j];
                j += 1;
            }
        }

        return res;
    }

    public static void main(String[] args) {
        int[] arr = { 1, 9, 3, 2, 0, 4, 11, 19 };
        int[] res = new MergeSort().sort(arr);

        Arrays.sort(arr);

        for (int i = 0; i < arr.length; i += 1)
            assert arr[i] == res[i];

        System.out.println("SUCCESS");
    }
}
