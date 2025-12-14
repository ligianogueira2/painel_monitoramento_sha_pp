#ifndef USUARIO_DTO_HPP
#define USUARIO_DTO_HPP

#include <string>

struct UsuarioDto {
    int id = 0;
    std::string nome;
    std::string email;
    double limiteAlerta = 0.0;
};

#endif
