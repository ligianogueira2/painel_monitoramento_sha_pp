#ifndef LEITOR_HIDROMETRO_HPP
#define LEITOR_HIDROMETRO_HPP

#include <string>

class LeitorHidrometro {
public:
    virtual ~LeitorHidrometro() = default;

    // Verifica se este leitor consegue tratar a imagem
    virtual bool aceita(const std::string& caminhoImagem) const = 0;

    // Retorna o valor lido em m³
    virtual double lerValor(const std::string& caminhoImagem) const = 0;
};

#endif
