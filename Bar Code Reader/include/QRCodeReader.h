#ifndef QRCODEREADER_H
#define QRCODEREADER_H

#include <opencv2/opencv.hpp>
#include <string>

class QRCodeReader {
public:
    QRCodeReader();
    ~QRCodeReader();

    // Metoda do detekcji i dekodowania kodu QR
    std::string detectAndDecode(const cv::Mat& image, cv::Mat& bbox);

    // Rysowanie granic kodu QR na obrazie
    void drawBoundingBox(cv::Mat& image, const cv::Mat& bbox);

private:
    cv::QRCodeDetector qrDetector;
};

#endif // QRCODEREADER_H
