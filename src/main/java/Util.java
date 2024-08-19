package binary_search;

import java.util.Random;
import java.util.Arrays;

public class Util {
	
	Random rand = new Random();
	
	public int[] createArray(int length){
		int min = 0;
		int max = 100;
		int[] array = new int[length];
		for(int i = 0; i < length; i++) {
			array[i] = rand.nextInt(max - min) + min;
			min = max + 1;
			max = max + 100;
		}
		Arrays.sort(array);
		return array;
	}
}
