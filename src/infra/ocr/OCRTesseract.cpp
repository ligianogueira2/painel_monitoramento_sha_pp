#include "infra/ocr/OCRTesseract.hpp"
#include "infra/logger/Logger.hpp"
#include <fstream>
#include <regex>
#include <direct.h>

bool OCRTesseract::aceita(const std::string& caminhoImagem) const {
    return caminhoImagem.find(".png") != std::string::npos;
}

double OCRTesseract::extrairValor(const std::string& caminhoImagem) {
    const std::string tesseractPath = ".\\tesseract\\tesseract.exe";
    const std::string tessDataPath = ".\\tesseract\\tessdata";
    const std::string outputBase = "C:\\temp_ocr\\saida";
    const std::string arquivoTexto = "C:\\temp_ocr\\saida.txt";
    
    _mkdir("C:\\temp_ocr");
    std::remove(arquivoTexto.c_str());

    std::string comando = "\"\"" + tesseractPath + "\" \"" + caminhoImagem + "\" \"" + outputBase + 
                           "\" --tessdata-dir \"" + tessDataPath + "\" -l eng --psm 7 -c tessedit_char_whitelist=0123456789.\"";

    if (std::system(comando.c_str()) != 0) {
        return -1.0;
    }

    std::ifstream arquivo(arquivoTexto);
    std::string texto;
    if (arquivo >> texto) {
        std::regex reg("\\d+");
        std::smatch m;
        if (std::regex_search(texto, m, reg)) return std::stod(m.str());
    }
    return -1.0;
}