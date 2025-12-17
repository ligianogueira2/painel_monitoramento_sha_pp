#ifndef EMAIL_ADAPTER_HPP
#define EMAIL_ADAPTER_HPP

#include "IAdaptadorNotificacao.hpp"
#include <iostream>
#include <string>

class EmailAdapter : public IAdaptadorNotificacao {
public:
    bool enviar(const std::string& destinatario, const std::string& mensagem) override {
        std::cout << "\n[ADAPTER] --- Iniciando comunicacao externa ---" << std::endl;
        std::cout << "[ADAPTER] Destinatario: " << destinatario << std::endl;
        std::cout << "[ADAPTER] Conteudo: " << mensagem << std::endl;
        std::cout << "[ADAPTER] Status: Enviado com sucesso via Protocolo SMTP." << std::endl;
        return true;
    }
};

#endif