#ifndef LEITURA_DTO_HPP
#define LEITURA_DTO_HPP

#include <string>

struct LeituraDto {
    int id = 0;
    int idSHA = 0;
    std::string dataHora;
    double volume = 0.0;
};

#endif
