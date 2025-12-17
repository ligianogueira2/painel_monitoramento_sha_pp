#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP

#include <string>

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void atualizar(const std::string& evento, int idUsuario, double valor) = 0;
};

#endif