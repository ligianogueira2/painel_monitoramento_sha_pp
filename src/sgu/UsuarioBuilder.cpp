#include "sgu/UsuarioBuilder.hpp"

UsuarioBuilder& UsuarioBuilder::comId(int id) {
    this->id = id;
    return *this;
}

UsuarioBuilder& UsuarioBuilder::comNome(const std::string& nome) {
    this->nome = nome;
    return *this;
}

UsuarioBuilder& UsuarioBuilder::comEmail(const std::string& email) {
    this->email = email;
    return *this;
}

UsuarioBuilder& UsuarioBuilder::comLimite(double limite) {
    this->limiteAlerta = limite;
    return *this;
}

Usuario UsuarioBuilder::build() {
    return Usuario(id, nome, email, limiteAlerta);
}
