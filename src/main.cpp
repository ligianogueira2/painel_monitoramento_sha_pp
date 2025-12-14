#include "fachada/FachadaPMSHA.hpp"
#include <iostream>

int main() {
    FachadaPMSHA fachada;

    // ============================
    // CRUD – Usuario
    // ============================
    UsuarioDto novoUsuario;
    novoUsuario.nome = "Ana";
    novoUsuario.email = "ana@gmail.com";
    novoUsuario.limiteAlerta = 100.0;

    int idUsuario = fachada.criarUsuarioConta(novoUsuario);

    std::cout << "Usuario criado com ID: " << idUsuario << std::endl;

    UsuarioDto usuario = fachada.consultarUsuarioConta(idUsuario);

    std::cout << "Usuario consultado: "
              << usuario.nome
              << " | Email: "
              << usuario.email
              << std::endl;

    fachada.definirLimiteAlerta(idUsuario, 150.0);

    // ============================
    // MONITORAMENTO DOS SHA
    // ============================

    // SHA 1 – seu hidrômetro (projeto próprio)
    fachada.monitorarDiretorioSHA(
        1,
        "C:/Users/Ô_Ô/Downloads/simulador_hidrometro_ligia/projeto_hidrometro_pp/Medicoes_202311250003_5"
    );

    // SHA 2 – hidrômetro de outro aluno
    fachada.monitorarDiretorioSHA(
        2,
        "C:/Users/Ô_Ô/Downloads/simulador-hidrometro/medicoes_hidrometros"
    );

    return 0;
}
