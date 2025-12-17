#ifndef OCR_STUB_HPP
#define OCR_STUB_HPP

#include "infra/ocr/OCRService.hpp"
#include <iostream>

class OCRStub : public OCRService {
public:
    double extrairValor(const std::string& caminhoImagem) override {
        std::cout << "[OCRStub] Simulando OCR para: "
                  << caminhoImagem << std::endl;

        // Valor fake por enquanto
        return 123.0;
    }
};

#endif
