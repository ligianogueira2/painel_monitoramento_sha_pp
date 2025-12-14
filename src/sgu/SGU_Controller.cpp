#include "sgu/SGU_Controller.hpp"
#include "sgu/UsuarioBuilder.hpp"
#include "infra/logger/Logger.hpp"

int SGU_Controller::criarUsuario(const UsuarioDto& dto) {
    Logger::getInstance().info("SGU: Criando usuário");

    Usuario usuario = UsuarioBuilder()
        .comNome(dto.nome)
        .comEmail(dto.email)
        .comLimite(dto.limiteAlerta)
        .build();

    return usuarioDAO.salvar(usuario);
}

UsuarioDto SGU_Controller::consultarUsuario(int id) {
    Logger::getInstance().info("SGU: Consultando usuario");

    Usuario usuario = usuarioDAO.buscarPorId(id);

    UsuarioDto dto;
    dto.id = usuario.getId();
    dto.nome = usuario.getNome();
    dto.email = usuario.getEmail();
    dto.limiteAlerta = usuario.getLimiteAlerta();

    return dto;
}

bool SGU_Controller::atualizarUsuario(int id, const UsuarioDto& dto) {
    Logger::getInstance().info("SGU: Atualizando usuario");

    Usuario usuario(id, dto.nome, dto.email, dto.limiteAlerta);
    return usuarioDAO.atualizar(usuario);
}

bool SGU_Controller::definirLimite(int id, double limite) {
    Logger::getInstance().info("SGU: Definindo limite de alerta");

    Usuario usuario = usuarioDAO.buscarPorId(id);
    usuario.setLimiteAlerta(limite);

    return usuarioDAO.atualizar(usuario);
}
