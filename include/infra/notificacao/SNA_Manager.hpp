#ifndef SNA_MANAGER_HPP
#define SNA_MANAGER_HPP

#include "IObserver.hpp"
#include "EmailNotificacao.hpp"

class SNA_Manager : public IObserver {
public:
    // Implementa o Observer/Mediator
    void atualizar(const std::string& evento, int idUsuario, double valor) override {
        if (evento == "ALERTA_CONSUMO") {
            std::cout << "[SNA_Manager] Evento recebido. Acionando notificacao..." << std::endl;
            EmailNotificacao notificacao;
            notificacao.notificar(idUsuario, valor);
        }
    }
};

#endif