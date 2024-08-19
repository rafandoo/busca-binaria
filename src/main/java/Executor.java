package binary_search;

import java.util.Arrays;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Executor {

	private static ExecutorService executorService = Executors.newCachedThreadPool();

	public static void main(String[] args) {

		Scanner enter = new Scanner(System.in);

		int length = 0;
		while (length <= 3) {
			System.out.println();
			System.out.println("Informe o tamanho do array no qual será efetuada a busca binária: ");
			length = enter.nextInt();
			if (length <= 3) {
				System.out.println("O vetor deve possuir um valor mínimo de três unidades.");
			}
		}

		System.out.println();

		Util util = new Util();
		int[] array = util.createArray(length);

		for (int i = 0; i < array.length; i++) {
			if (i == array.length - 1) {
				System.out.print(array[i]);
				break;
			}
			System.out.print(array[i] + ", ");
		}

		System.out.println();
		System.out.println();

		System.out.println("Informe o valor da busca: ");
		int value = enter.nextInt();

		int div = array.length / 3;
		int thread = div + 1;

		while (thread > div) {
			System.out.println();
			System.out.println("Informe o número de threads que realizarão a busca: ");
			thread = enter.nextInt();
			if (thread > div) {
				System.out.println("O número de threads não pode ultrapassar o valor máximo estipulado de " + div
						+ " para o vetor especificado.");
			}
		}

		System.out.println();
		System.out.println("Busca Serial:");

		SerialBinarySearch serialSearch = new SerialBinarySearch(array, value);
		int valueIndex = serialSearch.binarySearch();
		
		if (valueIndex != -1) {
			System.out.println(valueIndex);
		}
		else {
			System.out.println("valor não encontrado.");
		}
		
		System.out.println();
		System.out.println("Busca Binária");

		int minIndex = 0;
		div = array.length / thread;
		
		ParalellBinarySearch emptyParalellSearch = new ParalellBinarySearch();
		
		for (int i = 0; i < thread; i++) {
			
			int[] newArray;
			int refMinIndex = minIndex;
			
			if (i == thread - 1) {
				newArray = Arrays.copyOfRange(array, minIndex, array.length);
			} else {
				newArray = Arrays.copyOfRange(array, minIndex, minIndex + div);
			}

			executorService.execute(() -> {
				try {
					ParalellBinarySearch threadParalellSearch = new ParalellBinarySearch(newArray, value, refMinIndex);
					threadParalellSearch.run();
				} catch (Exception e) {
					e.printStackTrace();
				}
			});
			
			if (emptyParalellSearch.validation == true) {
				System.out.println("teste");
				break;
			}
			minIndex = minIndex + div;
		}

		enter.close();
	}
}
