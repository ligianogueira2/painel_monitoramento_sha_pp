#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>

class Usuario {
private:
    int id;
    std::string nome;
    std::string email;
    double limiteAlerta;

public:
    Usuario(int id,
            const std::string& nome,
            const std::string& email,
            double limiteAlerta);

    int getId() const;
    std::string getNome() const;
    std::string getEmail() const;
    double getLimiteAlerta() const;

    void setLimiteAlerta(double limite);
};

#endif
