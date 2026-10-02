#ifndef GERENCIADOR_INSUMOS_HPP
#define GERENCIADOR_INSUMOS_HPP

#include "ItemInsumo.hpp"
#include <unordered_map>
#include <memory>
#include <vector>

class GerenciadorInsumos {
private:
    // Mapeia código do insumo -> Objeto ItemInsumo
    std::unordered_map<std::string, ItemInsumo> estoque;

public:
    GerenciadorInsumos() = default;

    bool cadastrarInsumo(const std::string& codigo, const std::string& nome, 
                         const std::string& categoria, int quantidade, double preco);

    bool movimentarEntrada(const std::string& codigo, int quantidade);
    bool movimentarSaida(const std::string& codigo, int quantidade);

    void listarEstoque() const;
    void buscarPorCategoria(const std::string& categoria) const;
    void gerarRelatorioValorTotal() const;
};

#endif // GERENCIADOR_INSUMOS_HPP