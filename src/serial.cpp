#include <iostream>
#include <vector>
#include <numeric>
#include <bits/stdc++.h>

class BuscaBinaria {
public:
    BuscaBinaria(const std::vector<int>& v) : vetor(v) {}

    int buscar(int chave) const {
        int ini = 0, fim = vetor.size() - 1;
        while (ini <= fim) {
            int meio = ini + (fim - ini) / 2;

            if (chave == vetor[meio]) {
                return meio;
            } else if (chave > vetor[meio]) {
                ini = meio + 1;
            } else {
                fim = meio - 1;
            }
        }
        return -1;
    }

private:
    const std::vector<int>& vetor;
};

int main() {
    const int tamanho = 1000;
    std::vector<int> vetor(tamanho);

    // Inicializa o vetor com valores ordenados de 1 a 1000
    std::iota(vetor.begin(), vetor.end(), 1);

    // srand(time(0)); 

    // Generate value using generate 
    // function 
    // generate(vetor.begin(), vetor.end(), rand); 

    // sort(vetor.begin(), vetor.end());

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