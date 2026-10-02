#include "../include/ItemInsumo.hpp"
#include <iomanip>

ItemInsumo::ItemInsumo(std::string cod, std::string n, std::string cat, int qtd, double preco)
    : codigo(cod), nome(n), categoria(cat), quantidade(qtd), precoUnitario(preco) {}

std::string ItemInsumo::getCodigo() const { return codigo; }
std::string ItemInsumo::getNome() const { return nome; }
std::string ItemInsumo::getCategoria() const { return categoria; }
int ItemInsumo::getQuantidade() const { return quantidade; }
double ItemInsumo::getPrecoUnitario() const { return precoUnitario; }

void ItemInsumo::adicionarEstoque(int qtd) {
    if (qtd > 0) {
        quantidade += qtd;
    }
}

bool ItemInsumo::removerEstoque(int qtd) {
    if (qtd > 0 && quantidade >= qtd) {
        quantidade -= qtd;
        return true;
    }
    return false;
}

void ItemInsumo::exibirDetalhes() const {
    std::cout << std::left << std::setw(10) << codigo
              << std::setw(25) << nome
              << std::setw(15) << categoria
              << std::setw(10) << quantidade
              << "R$ " << std::fixed << std::setprecision(2) << precoUnitario << std::endl;
}