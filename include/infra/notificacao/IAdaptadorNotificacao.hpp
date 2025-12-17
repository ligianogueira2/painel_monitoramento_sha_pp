#ifndef IADAPTADOR_NOTIFICACAO_HPP
#define IADAPTADOR_NOTIFICACAO_HPP

#include <string>

class IAdaptadorNotificacao {
public:
    virtual ~IAdaptadorNotificacao() = default;
    virtual bool enviar(const std::string& destinatario, const std::string& mensagem) = 0;
};

#endif