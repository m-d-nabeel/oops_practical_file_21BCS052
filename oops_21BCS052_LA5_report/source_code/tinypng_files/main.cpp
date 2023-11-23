#include <iostream>

#include "pixel.h"
#include "png.h"

class Point {
   public:
    int x;
    int y;
    int intensity;
    Point(int x, int y, int intensity) : x(x), y(y), intensity(intensity) {}

    bool operator<(const Point& other) const {
        return intensity < other.intensity;
    }
};

int main() {
    std::cout << __FILE__ << std::endl;
    tinypng::PNG nightlightsImage("nighlight-igp.png");
    int height = nightlightsImage.getHeight();
    int width = nightlightsImage.getWidth();
    std::cout << "Height: " << height << std::endl;
    std::cout << "Width: " << width << std::endl;

    tinypng::Pixel pixelLB = nightlightsImage(height * 1 / 4, width * 1 / 4);
    uint8_t intensityLB = 0.2126 * pixelLB.red() + 0.7152 * pixelLB.green() +
                          0.0722 * pixelLB.blue();
    Point pointLB = Point(height * 1 / 4, width * 1 / 4, intensityLB);
    std::cout << "Luminance Intensity at cordinate : { " << pointLB.x << ", "
              << pointLB.y << " } of 512x512 PNG" << int(intensityLB)
              << std::endl;

    tinypng::Pixel pixelMid = nightlightsImage(height * 3 / 4, width / 2);
    uint8_t intensityMid = 0.2126 * pixelMid.red() + 0.7152 * pixelMid.green() +
                           0.0722 * pixelMid.blue();
    Point pointMid = Point(height * 3 / 4, width / 2, intensityMid);
    std::cout << "Luminance Intensity at cordinate : { " << pointMid.x << ", "
              << pointMid.y << " } of 512x512 PNG" << int(intensityMid)
              << std::endl;

    tinypng::Pixel pixelRT = nightlightsImage(height * 3 / 4, width * 3 / 4);
    uint8_t intensityRT = 0.2126 * pixelRT.red() + 0.7152 * pixelRT.green() +
                          0.0722 * pixelRT.blue();
    Point pointRT = Point(height * 3 / 4, width * 3 / 4, intensityRT);
    std::cout << "Luminance Intensity at cordinate : { " << pointRT.x << ", "
              << pointRT.y << " } of 512x512 PNG" << int(intensityRT)
              << std::endl;

    std::cout << "PointLB < PointMid: " << (pointLB < pointMid) << std::endl;
    std::cout << "PointMid < PointRT: " << (pointMid < pointRT) << std::endl;
    std::cout << "PointLB < PointRT: " << (pointLB < pointRT) << std::endl;

    return 0;
}