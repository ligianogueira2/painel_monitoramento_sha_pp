#ifndef SGU_CONTROLLER_HPP
#define SGU_CONTROLLER_HPP

#include "dto/UsuarioDto.hpp"
#include "sgu/UsuarioDAO.hpp"

class SGU_Controller {
private:
    UsuarioDAO usuarioDAO;

public:
    int criarUsuario(const UsuarioDto& dto);
    UsuarioDto consultarUsuario(int id);
    bool atualizarUsuario(int id, const UsuarioDto& dto);
    bool definirLimite(int id, double limite);
};

#endif
