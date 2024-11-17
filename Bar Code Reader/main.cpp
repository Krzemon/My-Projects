#include <opencv2/opencv.hpp>
#include <iostream>
#include "QRCodeReader.h"

int main(int argc, char** argv) {
    char *path = "../img/qr_code.png";

    cv::Mat image = cv::imread(path);
    if (image.empty()) {
        std::cerr << "Błąd: nie można wczytać obrazu " << path << std::endl;
        return -1;
    }

    QRCodeReader qrReader;
    cv::Mat bbox;

    std::string decodedText = qrReader.detectAndDecode(image, bbox);

    if (!decodedText.empty()) 
        std::cout << "Zdekodowany tekst: " << decodedText << std::endl;
    else 
        std::cout << "Nie znaleziono żadnego kodu QR na obrazie." << std::endl;   

    return 0;
}
