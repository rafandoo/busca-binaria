#include <iostream>
#include <vector>
#include <numeric>
#include <omp.h>

class BuscaBinaria {
public:
    BuscaBinaria(const std::vector<int>& v) : vetor(v) {}

    int buscar(int chave) const {
        int ini = 0, fim = vetor.size() - 1;
        int resultado = -1;

        #pragma omp parallel for shared(ini, fim, resultado)
        for (int i = ini; i <= fim; i++) {
            if (chave == vetor[i]) {
                #pragma omp critical
                {
                    resultado = i;
                }
                break;
            }
        }

        return resultado;
    }

private:
    const std::vector<int>& vetor;
};

int main() {
    const int tamanho = 1000;
    std::vector<int> vetor(tamanho);

    // Inicializa o vetor com valores ordenados de 1 a 1000
    std::iota(vetor.begin(), vetor.end(), 1);

    for (auto i: vetor) {
        std::cout << i << '\n'; 
    }

    BuscaBinaria busca(vetor);

    int chave;
    std::cout << "Informe a chave: ";
    std::cin >> chave;

    if (std::cin.fail()) {
        std::cerr << "Entrada inválida.\n";
        return EXIT_FAILURE;
    }

    int resultado = busca.buscar(chave);

    if (resultado != -1) {
        std::cout << "O valor " << chave << " está na posição " << resultado << ".\n";
    } else {
        std::cout << "Não foi encontrado o valor " << chave << " no vetor.\n";
    }

    return EXIT_SUCCESS;
}