#include "QRCodeReader.h"
#include <iostream>

QRCodeReader::QRCodeReader() {}

QRCodeReader::~QRCodeReader() {}

std::string QRCodeReader::detectAndDecode(const cv::Mat& image, cv::Mat& bbox) {
    return qrDetector.detectAndDecode(image, bbox);
}

void QRCodeReader::drawBoundingBox(cv::Mat& image, const cv::Mat& bbox) {
    if (!bbox.empty()) {
        for (int i = 0; i < bbox.rows; i++) {
            cv::line(image, bbox.at<cv::Point2f>(i), bbox.at<cv::Point2f>((i + 1) % bbox.rows), cv::Scalar(0, 255, 0), 2);
        }
    }
}
