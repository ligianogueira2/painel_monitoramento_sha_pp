#ifndef LEITOR_HIDROMETRO_HPP
#define LEITOR_HIDROMETRO_HPP

#include <string>

class LeitorHidrometro {
public:
    virtual ~LeitorHidrometro() = default;

    virtual bool aceita(const std::string& caminhoImagem) const = 0;

    virtual double lerValor(const std::string& caminhoImagem) const = 0;
};

#endif
