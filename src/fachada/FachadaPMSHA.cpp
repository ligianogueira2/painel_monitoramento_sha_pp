#include "fachada/FachadaPMSHA.hpp"
#include "infra/imagem/HidrometroParser.hpp"
#include "infra/logger/Logger.hpp"

#include <iostream>
#include <vector>

// ================= CONSTRUTOR =================

FachadaPMSHA::FachadaPMSHA() {
    Logger::getInstance().info("Fachada PMSHA inicializada");
}

FachadaPMSHA::~FachadaPMSHA() {
    Logger::getInstance().info("Fachada PMSHA finalizada");
}

// ================= SGU =================

int FachadaPMSHA::criarUsuarioConta(const UsuarioDto&) {
    Logger::getInstance().info("Criando novo usuario/conta");
    return 1; // mock
}

UsuarioDto FachadaPMSHA::consultarUsuarioConta(int idUsuario) {
    Logger::getInstance().info(
        "Consultando usuario ID: " + std::to_string(idUsuario)
    );
    return UsuarioDto{};
}

bool FachadaPMSHA::atualizarUsuarioConta(int idUsuario, const UsuarioDto&) {
    Logger::getInstance().info(
        "Atualizando usuario ID: " + std::to_string(idUsuario)
    );
    return true;
}

bool FachadaPMSHA::definirLimiteAlerta(int idUsuario, double limiteVolume) {
    Logger::getInstance().info(
        "Definindo limite de alerta para usuario ID: " +
        std::to_string(idUsuario) +
        " | Limite: " + std::to_string(limiteVolume)
    );
    return true;
}

// ================= LEITURA POR IMAGEM =================

void FachadaPMSHA::registrarLeituraPorImagem(
    int idSHA,
    const std::string& caminhoImagem
) {
    Logger::getInstance().info(
        "Iniciando leitura por imagem para SHA ID: " +
        std::to_string(idSHA)
    );

    HidrometroParser parser;

    double valor = parser.lerImagem(caminhoImagem);

    Logger::getInstance().info(
        "Leitura realizada com sucesso. Valor lido (m3): " +
        std::to_string(valor)
    );
}

// ================= MONITORAMENTO (STUB DE INTEGRAÇÃO) =================

void FachadaPMSHA::monitorarDiretorioSHA(
    int idSHA,
    const std::string& diretorio
) {
    Logger::getInstance().info(
        "Monitorando diretorio do SHA ID: " + std::to_string(idSHA)
    );

    std::vector<std::string> imagensSimuladas = {
        diretorio + "/leitura_001.png",
        diretorio + "/leitura_002.png"
    };

    for (const auto& img : imagensSimuladas) {
        Logger::getInstance().info(
            "Imagem detectada: " + img
        );
        registrarLeituraPorImagem(idSHA, img);
    }
}

// ================= CONSULTAS =================

VolumeDto FachadaPMSHA::monitorarConsumoUsuario(
    int idUsuario,
    const std::string& dataInicio,
    const std::string& dataFim
) {
    Logger::getInstance().info(
        "Monitorando consumo agregado do usuario " +
        std::to_string(idUsuario)
    );
    return VolumeDto{};
}
