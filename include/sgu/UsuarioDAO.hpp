#ifndef USUARIO_DAO_HPP
#define USUARIO_DAO_HPP

#include "sgu/Usuario.hpp"
#include <unordered_map>

class UsuarioDAO {
private:
    std::unordered_map<int, Usuario> usuarios;
    int proximoId = 1;

public:
    int salvar(const Usuario& usuario);
    Usuario buscarPorId(int id);
    bool atualizar(const Usuario& usuario);
};

#endif
