#ifndef USUARIO_BUILDER_HPP
#define USUARIO_BUILDER_HPP

#include "sgu/Usuario.hpp"
#include <string>

class UsuarioBuilder {
private:
    int id = 0;
    std::string nome;
    std::string email;
    double limiteAlerta = 0.0;

public:
    UsuarioBuilder& comId(int id);
    UsuarioBuilder& comNome(const std::string& nome);
    UsuarioBuilder& comEmail(const std::string& email);
    UsuarioBuilder& comLimite(double limite);

    Usuario build();
};

#endif
