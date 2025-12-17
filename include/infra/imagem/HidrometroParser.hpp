#ifndef HIDROMETRO_PARSER_HPP
#define HIDROMETRO_PARSER_HPP

#include <memory>
#include <string>
#include "infra/ocr/OCRService.hpp"

class HidrometroParser {
public:
    HidrometroParser();
    double lerImagem(const std::string& caminhoImagem);

private:
    std::unique_ptr<OCRService> ocr;
};

#endif
