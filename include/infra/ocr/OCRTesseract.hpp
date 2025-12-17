#ifndef OCR_TESSERACT_HPP
#define OCR_TESSERACT_HPP

#include "infra/ocr/OCRService.hpp" 
#include <string>

class OCRTesseract : public OCRService {
public:
    OCRTesseract() = default;
    virtual ~OCRTesseract() = default;

    bool aceita(const std::string& caminhoImagem) const override;
    double extrairValor(const std::string& caminhoImagem) override;
};

#endif