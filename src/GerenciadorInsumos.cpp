#include "../include/GerenciadorInsumos.hpp"
#include <iostream>
#include <iomanip>

bool GerenciadorInsumos::cadastrarInsumo(const std::string& codigo, const std::string& nome, 
                                         const std::string& categoria, int quantidade, double preco) {
    if (estoque.find(codigo) != estoque.end()) {
        std::cout << "❌ Erro: Insumo com código '" << codigo << "' já está cadastrado!\n";
        return false;
    }

    ItemInsumo novoItem(codigo, nome, categoria, quantidade, preco);
    estoque.insert({codigo, novoItem});
    std::cout << "✅ Insumo '" << nome << "' cadastrado com sucesso!\n";
    return true;
}

bool GerenciadorInsumos::movimentarEntrada(const std::string& codigo, int quantidade) {
    auto it = estoque.find(codigo);
    if (it != estoque.end()) {
        it->second.adicionarEstoque(quantidade);
        std::cout << "⬆️ Entrada registrada! Novo estoque de " << it->second.getNome() 
                  << ": " << it->second.getQuantidade() << " unidades.\n";
        return true;
    }
    std::cout << "❌ Erro: Insumo não encontrado.\n";
    return false;
}

bool GerenciadorInsumos::movimentarSaida(const std::string& codigo, int quantidade) {
    auto it = estoque.find(codigo);
    if (it != estoque.end()) {
        if (it->second.removerEstoque(quantidade)) {
            std::cout << "⬇️ Saída registrada! Novo estoque de " << it->second.getNome() 
                      << ": " << it->second.getQuantidade() << " unidades.\n";
            return true;
        } else {
            std::cout << "⚠️ Saldo insuficiente para realizar a saída.\n";
            return false;
        }
    }
    std::cout << "❌ Erro: Insumo não encontrado.\n";
    return false;
}

void GerenciadorInsumos::listarEstoque() const {
    if (estoque.empty()) {
        std::cout << "ℹ️ Nenhum insumo cadastrado no sistema.\n";
        return;
    }

    std::cout << "\n========================================================================\n";
    std::cout << std::left << std::setw(10) << "CÓDIGO"
              << std::setw(25) << "NOME"
              << std::setw(15) << "CATEGORIA"
              << std::setw(10) << "QTD"
              << "PREÇO UNIT.\n";
    std::cout << "------------------------------------------------------------------------\n";

    for (const auto& pair : estoque) {
        pair.second.exibirDetalhes();
    }
    std::cout << "========================================================================\n\n";
}

void GerenciadorInsumos::buscarPorCategoria(const std::string& categoria) const {
    std::cout << "\n🔍 Busca por Categoria: [" << categoria << "]\n";
    std::cout << "------------------------------------------------------------------------\n";
    
    bool encontrado = false;
    for (const auto& pair : estoque) {
        if (pair.second.getCategoria() == categoria) {
            pair.second.exibirDetalhes();
            encontrado = true;
        }
    }

    if (!encontrado) {
        std::cout << "Nenhum insumo encontrado nesta categoria.\n";
    }
    std::cout << "------------------------------------------------------------------------\n\n";
}

void GerenciadorInsumos::gerarRelatorioValorTotal() const {
    double valorTotalEstoque = 0.0;
    int totalItens = 0;

    for (const auto& pair : estoque) {
        valorTotalEstoque += (pair.second.getQuantidade() * pair.second.getPrecoUnitario());
        totalItens += pair.second.getQuantidade();
    }

    std::cout << "\n📊 RELATÓRIO CONSOLIDADO DE ESTOQUE\n";
    std::cout << " - Total de tipos de insumos: " << estoque.size() << "\n";
    std::cout << " - Quantidade total de itens: " << totalItens << "\n";
    std::cout << " - Valor total imobilizado: R$ " << std::fixed << std::setprecision(2) << valorTotalEstoque << "\n\n";
}