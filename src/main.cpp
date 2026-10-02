#include "../include/GerenciadorInsumos.hpp"
#include <iostream>

void exibirMenu() {
    std::cout << "\n=== SISTEMA DE RASTREAMENTO DE INSUMOS (C++) ===\n";
    std::cout << "1. Cadastrar Novo Insumo\n";
    std::cout << "2. Registrar Entrada de Estoque\n";
    std::cout << "3. Registrar Saída de Estoque\n";
    std::cout << "4. Listar Todos os Insumos\n";
    std::cout << "5. Filtrar Insumos por Categoria\n";
    std::cout << "6. Exibir Valoração Total do Estoque\n";
    std::cout << "0. Sair\n";
    std::cout << "Escolha uma opção: ";
}

int main() {
    GerenciadorInsumos sistema;
    
    // Dados de teste pré-carregados
    sistema.cadastrarInsumo("INS-001", "Caixa Papelão Tripla", "Embalagem", 500, 4.50);
    sistema.cadastrarInsumo("INS-002", "Palete Padrão PBR", "Armazenagem", 120, 45.00);
    sistema.cadastrarInsumo("INS-003", "Filme Stretch 500mm", "Embalagem", 85, 28.90);

    int opcao = -1;

    while (opcao != 0) {
        exibirMenu();
        if (!(std::cin >> opcao)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (opcao) {
            case 1: {
                std::string cod, nome, cat;
                int qtd;
                double preco;
                std::cout << "\nCódigo: "; std::cin >> cod;
                std::cout << "Nome: "; std::cin.ignore(); std::getline(std::cin, nome);
                std::cout << "Categoria: "; std::getline(std::cin, cat);
                std::cout << "Quantidade inicial: "; std::cin >> qtd;
                std::cout << "Preço unitário: "; std::cin >> preco;
                sistema.cadastrarInsumo(cod, nome, cat, qtd, preco);
                break;
            }
            case 2: {
                std::string cod;
                int qtd;
                std::cout << "Código do insumo: "; std::cin >> cod;
                std::cout << "Quantidade a adicionar: "; std::cin >> qtd;
                sistema.movimentarEntrada(cod, qtd);
                break;
            }
            case 3: {
                std::string cod;
                int qtd;
                std::cout << "Código do insumo: "; std::cin >> cod;
                std::cout << "Quantidade a retirar: "; std::cin >> qtd;
                sistema.movimentarSaida(cod, qtd);
                break;
            }
            case 4:
                sistema.listarEstoque();
                break;
            case 5: {
                std::string cat;
                std::cout << "Informe a categoria: "; std::cin.ignore(); std::getline(std::cin, cat);
                sistema.buscarPorCategoria(cat);
                break;
            }
            case 6:
                sistema.gerarRelatorioValorTotal();
                break;
            case 0:
                std::cout << "\nEncerrando o sistema de insumos... Até logo!\n";
                break;
            default:
                std::cout << "Opção inválida! Tente novamente.\n";
        }
    }

    return 0;
}