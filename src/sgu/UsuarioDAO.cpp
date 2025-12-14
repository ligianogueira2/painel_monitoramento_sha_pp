#include "sgu/UsuarioDAO.hpp"

int UsuarioDAO::salvar(const Usuario& usuario) {
    int id = proximoId++;
    usuarios.emplace(id, Usuario(id,
                                 usuario.getNome(),
                                 usuario.getEmail(),
                                 usuario.getLimiteAlerta()));
    return id;
}

Usuario UsuarioDAO::buscarPorId(int id) {
    return usuarios.at(id);
}

bool UsuarioDAO::atualizar(const Usuario& usuario) {
    usuarios.insert_or_assign(usuario.getId(), usuario);
    return true;
}
