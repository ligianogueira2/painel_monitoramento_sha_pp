#ifndef EMAIL_NOTIFICACAO_HPP
#define EMAIL_NOTIFICACAO_HPP

#include "NotificacaoTemplateMethod.hpp"
#include "EmailAdapter.hpp"

class EmailNotificacao : public NotificacaoTemplateMethod {
private:
    EmailAdapter adapter_; 

protected:
    std::string formatarMensagem(double valor) override {
        return "Alerta de Consumo Elevado: " + std::to_string(valor) + " m3 detectados.";
    }

    void enviar(const std::string& dest, const std::string& msg) override {
        adapter_.enviar(dest, msg);
    }
};

#endif