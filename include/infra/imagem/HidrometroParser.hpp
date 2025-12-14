#ifndef HIDROMETRO_PARSER_HPP
#define HIDROMETRO_PARSER_HPP

#include "infra/imagem/LeitorHidrometro.hpp"
#include <string>

class HidrometroParser : public LeitorHidrometro {
public:
    bool aceita(const std::string& caminhoImagem) const override;
    double lerValor(const std::string& caminhoImagem) const override;
};

#endif
