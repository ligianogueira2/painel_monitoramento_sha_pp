#ifndef OCR_SERVICE_HPP
#define OCR_SERVICE_HPP

#include <string>

class OCRService {
public:
    virtual ~OCRService() = default; 
    virtual bool aceita(const std::string& caminhoImagem) const = 0;
    virtual double extrairValor(const std::string& caminhoImagem) = 0;
};

#endif