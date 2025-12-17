#ifndef NOTIFICACAO_TEMPLATE_HPP
#define NOTIFICACAO_TEMPLATE_HPP

#include <string>
#include <iostream>

class NotificacaoTemplateMethod {
public:
    virtual ~NotificacaoTemplateMethod() = default;

    void notificar(int idUsuario, double valor) {
        std::string destinatario = consultarDadosUsuario(idUsuario);
        std::string msg = formatarMensagem(valor);                 
        enviar(destinatario, msg);                                
    }

protected:
    virtual std::string consultarDadosUsuario(int id) { return "ana@gmail.com"; }
    virtual std::string formatarMensagem(double valor) = 0;
    virtual void enviar(const std::string& dest, const std::string& msg) = 0;
};

#endif