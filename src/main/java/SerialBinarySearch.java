package binary_search;

public class SerialBinarySearch {
	
	private int[] array;
	private int x;
	
	public SerialBinarySearch(int[] array, int x) {
		this.array = array;
		this.x = x;
	}
	
	public int binarySearch(){
    	
		int low = 0, high = this.array.length - 1;

		if (this.array[low] == x)
			return low;
		
		else if (this.array[high] == x)
			return high;

		while (low <= high) {
			int mid = low + (high - low) / 2;

			if (this.array[mid] == x)
				return mid;

			if (this.array[mid] < x)
				low = mid + 1;

			else
				high = mid - 1;
		}

		return -1;
    }

}
