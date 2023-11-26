package source_code.src;

import java.time.Duration;
import java.time.Instant;

/**
 * For 1000000 PointN
 * Thread = 1 => Time Elapsed = 1191
 * Thread = 2 => Time Elapsed = 770
 * Thread = 3 => Time Elapsed = 670
 * Thread = 4 => Time Elapsed = 648
 * Thread = 5 => Time Elapsed = 600
 * Thread = 6 => Time Elapsed = 520
 */

public class MultipleThreaded {

    public static final int THREADS = 100;
    public static final int[] SIZE = { 100, 1000, 10000, 100000, 1000000 };

    public static void split_merge_sort(PointN[] arr, int l, int r) {
        Thread[] tasks = new Thread[THREADS];
        int left = 0;
        for (int i = 0; i < THREADS; i++) {
            int right = ((i + 1) * r) / THREADS;
            int finalLeft = left;
            tasks[i] = new Thread(() -> merge_sort(arr, finalLeft, right));
            left = right + 1;
        }
        for (int i = 0; i < THREADS; i++) {
            tasks[i].start();
        }

        for (int i = 0; i < THREADS; i++) {
            try {
                tasks[i].join();
            } catch (InterruptedException e) {
                System.out.println("Error");
            }
        }

        for (int i = 0; i < THREADS - 1; i++) {
            int mid = (i + 1) * r / THREADS;
            int rig = (i + 2) * r / THREADS;
            merge(arr, 0, mid, rig);
        }
    }

    public static void multiple_threaded() {
        for (int k : SIZE) {
            PointN[] PointNArray = new PointN[k];
            for (int j = 0; j < k; j++) {
                int randomDimension = (int) (Math.floor(Math.random() * 10) + 2);
                PointNArray[j] = new PointN(randomDimension);
                PointNArray[j].setRandomPoints();
            }
            Instant start = Instant.now();
            split_merge_sort(PointNArray, 0, k - 1);
            Instant end = Instant.now();
            Duration timeElapsed = Duration.between(start, end);
            System.out.println("Time Elapsed for " + k + " = " + timeElapsed.toMillis());
        }
    }

    public static void merge_sort(PointN[] arr, int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;
            merge_sort(arr, l, mid);
            merge_sort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }

    public static void merge(PointN[] arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        PointN[] L = new PointN[n1];
        PointN[] R = new PointN[n2];

        System.arraycopy(arr, l, L, 0, n1);
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];

        int i = 0, j = 0;
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i].norm() < R[j].norm()) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k++] = L[i++];
        }
        while (j < n2) {
            arr[k++] = R[j++];
        }
    }

    public static void main(String[] args) {
        System.out.println("THREADS = " + THREADS);
        multiple_threaded();
        // test();
    }

    public static void test() {
        int N = 10;
        PointN[] PointNArray = new PointN[N];
        for (int i = 0; i < N; i++) {
            int randomDimension = (int) (Math.floor(Math.random() * 10) + 2);
            PointNArray[i] = new PointN(randomDimension);
            PointNArray[i].setRandomPoints();
        }
        System.out.println("BEFORE SORTING");
        System.out.println("-----------------------------------------------------");
        for (PointN n : PointNArray) {
            n.print();
        }
        split_merge_sort(PointNArray, 0, N - 1);
        System.out.println("AFTER SORTING");
        System.out.println("-----------------------------------------------------");
        for (PointN n : PointNArray) {
            n.print();
        }
    }
}