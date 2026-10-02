#ifndef ITEM_INSUMO_HPP
#define ITEM_INSUMO_HPP

#include <string>
#include <iostream>

class ItemInsumo {
private:
    std::string codigo;
    std::string nome;
    std::string categoria;
    int quantidade;
    double precoUnitario;

public:
    // Construtor
    ItemInsumo(std::string cod, std::string n, std::string cat, int qtd, double preco);

    // Getters e Setters
    std::string getCodigo() const;
    std::string getNome() const;
    std::string getCategoria() const;
    int getQuantidade() const;
    double getPrecoUnitario() const;

    void adicionarEstoque(int qtd);
    bool removerEstoque(int qtd);

    // Método de exibição formatada
    void exibirDetalhes() const;
};

#endif // ITEM_INSUMO_HPP