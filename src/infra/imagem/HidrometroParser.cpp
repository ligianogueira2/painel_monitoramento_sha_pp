#include "infra/imagem/HidrometroParser.hpp"
#include "infra/logger/Logger.hpp"
#include <iostream>

// Por enquanto, aceita qualquer imagem (versão inicial)
bool HidrometroParser::aceita(const std::string& caminhoImagem) const {
    Logger::getInstance().info("HidrometroParser avaliando imagem: " + caminhoImagem);
    return true;
}

// Leitura simulada (stub)
double HidrometroParser::lerValor(const std::string& caminhoImagem) const {
    Logger::getInstance().info("Realizando leitura de hidrometro (stub) para imagem: " + caminhoImagem);

    // 🔴 IMPORTANTE:
    // Aqui futuramente entra:
    // - ImagemReader
    // - OCRService
    // - lógica de parsing real

    // Valor fictício apenas para integração
    return 123.0;
}
