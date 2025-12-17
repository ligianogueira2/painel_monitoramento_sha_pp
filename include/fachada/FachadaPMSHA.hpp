#ifndef FACHADA_PMSHA_HPP
#define FACHADA_PMSHA_HPP

#include <string>

#include "dto/UsuarioDto.hpp"
#include "dto/VolumeDto.hpp"

#include "sgu/SGU_Controller.hpp"

class FachadaPMSHA {
private:
    SGU_Controller sguController;

public:
    FachadaPMSHA();
    ~FachadaPMSHA();

    // ===== SGU (CRUD USUÁRIO) =====
    int criarUsuarioConta(const UsuarioDto& novoUsuario);
    UsuarioDto consultarUsuarioConta(int idUsuario);
    bool atualizarUsuarioConta(int idUsuario, const UsuarioDto& dados);
    bool definirLimiteAlerta(int idUsuario, double limiteVolume);

    // ===== LEITURA POR IMAGEM (INTEGRAÇÃO SHA) =====
    void registrarLeituraPorImagem(
        int idSHA,
        const std::string& caminhoImagem
    );

    void monitorarDiretorioSHA(
        int idSHA,
        const std::string& caminhoDiretorio
    );

    // ===== CONSULTAS =====
    VolumeDto monitorarConsumoUsuario(
        int idUsuario,
        const std::string& dataInicio,
        const std::string& dataFim
    );
};

#endif
