#ifndef DIYables_TFT_Round_H
#define DIYables_TFT_Round_H

#include <stdint.h>
#include <stddef.h>
#include <Adafruit_GFX.h>

class DIYables_TFT_GC9A01_Round : public Adafruit_GFX {
  public:
    struct Point {
        uint16_t X, Y;
    };

    struct Frame {
        Point start, end;
    };

    DIYables_TFT_GC9A01_Round(uint8_t resPin, uint8_t dcPin, uint8_t csPin);

    void begin();
    void setFrame(const Frame& frame);
    void write(uint8_t *data, size_t len);
    void writeContinue(uint8_t *data, size_t len);
    void beginWrite();
    void endWrite();

    void drawPixel(int16_t x, int16_t y, uint16_t color) override;
    void fillScreen(uint16_t color) override;
    void setRotation(uint8_t r) override; 
    void invertDisplay(bool i) override;

    static uint16_t colorRGB(uint8_t r, uint8_t g, uint8_t b);

  private:
    uint8_t _res, _dc, _cs;
    uint8_t _rotation;

    inline void setReset(uint8_t val);
    inline void setDataCommand(uint8_t val);
    inline void setChipSelect(uint8_t val);
    inline void delayMs(uint16_t ms);
    void spiTx(uint8_t *data, size_t len);

    void writeCommand(uint8_t cmd);
    void writeData(uint8_t *data, size_t len);
    bool isPixelInsideCircle(int x, int y);
    inline void writeByte(uint8_t val);
};

// Short alias
using DIYables_TFT = DIYables_TFT_GC9A01_Round;

#endif // DIYables_TFT_Round_H
