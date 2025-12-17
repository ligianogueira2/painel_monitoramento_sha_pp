#include "infra/imagem/HidrometroParser.hpp"
#include <iostream>

HidrometroParser::HidrometroParser() {
    std::cout << "[Parser] Inicializado em modo de seguranca (Simulado)" << std::endl;
}

double HidrometroParser::lerImagem(const std::string& caminhoImagem) {
    if (caminhoImagem.find("0.00") != std::string::npos) {
        return 0.00;
    }
    
    if (caminhoImagem.find("hidrometro_3") != std::string::npos) return 185.75;
    return 12.50;
}