#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>

int buscaBinaria(const std::vector<int>& arr, int chave) {
    int esquerda = 0;
    int direita = arr.size() - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (arr[meio] == chave) {
            return meio; // Retorna a posição do elemento encontrado
        }
        if (arr[meio] < chave) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    return -1; // Retorna -1 se o elemento não for encontrado
}

int main() {
    const int tamanho = 1000;
    std::vector<int> vetor(tamanho);

    // Inicializa o vetor com valores ordenados de 1 a 1000
    std::iota(vetor.begin(), vetor.end(), 1);

    int chave;
    std::cout << "Informe a chave: ";
    std::cin >> chave;

    if (std::cin.fail()) {
        std::cerr << "Entrada inválida.\n";
        return EXIT_FAILURE;
    }

    // Medição de tempo
    auto inicio = std::chrono::high_resolution_clock::now();

    int resultado = buscaBinaria(vetor, chave);

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
