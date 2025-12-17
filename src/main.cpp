#include <iostream>
#include <string>
#include <memory>
#include "infra/notificacao/SNA_Manager.hpp"
#include "infra/imagem/HidrometroParser.hpp"

int main() {
    std::cout << "========== MONITORAMENTO SHA ==========" << std::endl;
    
    auto sna = std::make_shared<SNA_Manager>();
    HidrometroParser parser;

    int idAna = 1;
    double limite = 100.0;
    
    std::cout << "[INFO] Usuario: Ana | Limite: " << limite << " m3\n" << std::endl;

    // --- CASO 1: CONSUMO NORMAL ---
    std::cout << "[SHA ID: 1] Processando..." << std::endl;
    double v1 = parser.lerImagem("C:/simulador-hidrometro/medicoes_hidrometros/hidrometro_1.png");
    std::cout << "[LEITURA] Valor: " << v1 << " m3\n" << std::endl;

    // --- CASO 2: NOVO ARQUIVO (CONSUMO ZERADO) ---
    std::cout << "[SHA ID: 3] Analisando Hidrometro Parado/Sem Consumo..." << std::endl;
    std::string imgZero = "C:/simulador_hidrometro_ligia/projeto_hidrometro_pp/Medicoes_202311250003_5/hidrometrofinal_0.00.png";
    double vZero = parser.lerImagem(imgZero); 
    std::cout << "[LEITURA] Valor: " << vZero << " m3 (Status: Normal/Sem consumo)\n" << std::endl;

    // --- CASO 3: CONSUMO ALTO (DISPARA ALERTA) ---
    std::cout << "[SHA ID: 2] Processando..." << std::endl;
    double v2 = parser.lerImagem("C:/simulador-hidrometro/medicoes_hidrometros/hidrometro_3.png");
    std::cout << "[LEITURA] Valor: " << v2 << " m3" << std::endl;

    if (v2 > limite) {
        std::cout << "[ALERTA] Limite excedido! Acionando SNA via Observer..." << std::endl;
        sna->atualizar("ALERTA_CONSUMO", idAna, v2);
    }

    std::cout << "=======================================" << std::endl;
    return 0;
}