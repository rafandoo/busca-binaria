package binary_search;

public class ParalellBinarySearch implements Runnable {

	private int[] array;
	private int x;
	private int refMinIndex;
	public static boolean validation = false;
	private final Object lock = new Object();
	
	public ParalellBinarySearch() {
		
	}

	public ParalellBinarySearch(int[] array, int x, int refMinIndex) {
		this.array = array;
		this.x = x;
		this.refMinIndex = refMinIndex;
	}

	public int binarySearch() {

		int low = 0, high = this.array.length - 1;

		if (this.array[low] == x)
			return low + this.refMinIndex;
		
		else if (this.array[high] == x)
			return high + this.refMinIndex;

		while (low <= high) {
			int mid = low + (high - low) / 2;

			if (this.array[mid] == x)
				return mid + this.refMinIndex;

			if (this.array[mid] < x)
				low = mid + 1;

			else
				high = mid - 1;
		}

		return -1;
	}

	public void run() {
		int value = binarySearch();
		
		 synchronized (lock) {
			 if (value != -1) {
				System.out.println(Thread.currentThread().getName() + ": " + value);
			 }
			else
			 	System.out.println(Thread.currentThread().getName() + ": valor não encontrado.");
		 }
	}
}
