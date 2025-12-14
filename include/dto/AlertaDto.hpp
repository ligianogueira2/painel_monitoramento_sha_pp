#ifndef ALERTA_DTO_HPP
#define ALERTA_DTO_HPP

#include <string>
#include "dto/TipoAlerta.hpp"

struct AlertaDto {
    int id = 0;
    int idUsuario = 0;
    TipoAlerta tipo;
    std::string mensagem;
    bool enviado = false;
};

#endif
