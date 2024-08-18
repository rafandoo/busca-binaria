#include <iostream>
#include <vector>
#include <numeric>
#include <omp.h>
#include <chrono>

int buscaSequencial(const std::vector<int>& arr, int ini, int fim, int chave) {
    for (int i = ini; i <= fim; ++i) {
        if (arr[i] == chave) {
            return i;
        }
    }
    return -1;
}

int buscaParalela(const std::vector<int>& arr, int chave, int num_threads) {
    int tamanho = arr.size();
    int resultado = -1;

    // Define o número de threads
    #pragma omp parallel num_threads(num_threads)
    {
        #pragma omp for
        for (int i = 0; i < num_threads; ++i) {
            // Divide o array em subarrays
            int inicio = i * (tamanho / num_threads);
            int fim = (i == num_threads - 1) ? (tamanho - 1) : (inicio + (tamanho / num_threads) - 1);

            int local_resultado = buscaSequencial(arr, inicio, fim, chave);

            #pragma omp critical
            {
                if (local_resultado != -1) {
                    resultado = local_resultado;
                }
            }
        }
    }

    return resultado;
}

int main() {
    const int tamanho = 1000;
    std::vector<int> vetor(tamanho);

    // Inicializa o vetor com valores ordenados de 1 a 1000
    std::iota(vetor.begin(), vetor.end(), 1);

    int num_threads = 4; // Número de threads que você deseja usar

    int chave;
    std::cout << "Informe a chave: ";
    std::cin >> chave;

    if (std::cin.fail()) {
        std::cerr << "Entrada inválida.\n";
        return EXIT_FAILURE;
    }

    // Medição de tempo
    auto inicio = std::chrono::high_resolution_clock::now();

    int resultado = buscaParalela(vetor, chave, num_threads);

    auto fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracao = fim - inicio;

    if (resultado != -1) {
        std::cout << "O valor " << chave << " está na posição " << resultado << ".\n";
    } else {
        std::cout << "Não foi encontrado o valor " << chave << " no vetor.\n";
    }

    std::cout << "Tempo de execução: " << duracao.count() << " segundos\n";

    return EXIT_SUCCESS;
}
