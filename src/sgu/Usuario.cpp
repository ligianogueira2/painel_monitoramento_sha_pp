#include "sgu/Usuario.hpp"

Usuario::Usuario(int id,
                 const std::string& nome,
                 const std::string& email,
                 double limiteAlerta)
    : id(id), nome(nome), email(email), limiteAlerta(limiteAlerta) {}

int Usuario::getId() const {
    return id;
}

std::string Usuario::getNome() const {
    return nome;
}

std::string Usuario::getEmail() const {
    return email;
}

double Usuario::getLimiteAlerta() const {
    return limiteAlerta;
}

void Usuario::setLimiteAlerta(double limite) {
    limiteAlerta = limite;
}
