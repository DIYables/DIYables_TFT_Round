#include <DIYables_TFT_Round.h>
#include <Arduino.h>
#include <SPI.h>

// Command codes:
#define COL_ADDR_SET        0x2A
#define ROW_ADDR_SET        0x2B
#define MEM_WR              0x2C
#define COLOR_MODE          0x3A
#define COLOR_MODE__12_BIT  0x03
#define COLOR_MODE__16_BIT  0x05
#define COLOR_MODE__18_BIT  0x06
#define MEM_WR_CONT         0x3C

DIYables_TFT_GC9A01_Round::DIYables_TFT_GC9A01_Round(uint8_t resPin, uint8_t dcPin, uint8_t csPin)
    : Adafruit_GFX(240, 240), _res(resPin), _dc(dcPin), _cs(csPin), _rotation(0) {} // Default rotation 0

inline void DIYables_TFT_GC9A01_Round::setReset(uint8_t val) {
    digitalWrite(_res, val);
}

inline void DIYables_TFT_GC9A01_Round::setDataCommand(uint8_t val) {
    digitalWrite(_dc, val);
}

inline void DIYables_TFT_GC9A01_Round::setChipSelect(uint8_t val) {
    digitalWrite(_cs, val);
}

inline void DIYables_TFT_GC9A01_Round::delayMs(uint16_t ms) {
    delay(ms);
}

void DIYables_TFT_GC9A01_Round::spiTx(uint8_t *data, size_t len) {
    SPI.transfer(data, len); // Use block transfer if available
}

void DIYables_TFT_GC9A01_Round::writeCommand(uint8_t cmd) {
    setDataCommand(0);
    setChipSelect(0);
    SPI.beginTransaction(SPISettings(40000000, MSBFIRST, SPI_MODE0));
    spiTx(&cmd, sizeof(cmd));
    SPI.endTransaction();
    setChipSelect(1);
}

void DIYables_TFT_GC9A01_Round::writeData(uint8_t *data, size_t len) {
    setDataCommand(1);
    setChipSelect(0);
    SPI.beginTransaction(SPISettings(40000000, MSBFIRST, SPI_MODE0));
    spiTx(data, len);
    SPI.endTransaction();
    setChipSelect(1);
}

bool DIYables_TFT_GC9A01_Round::isPixelInsideCircle(int x, int y) {
  int centerX = 120;
  int centerY = 120;
  int radius = 120;

  // Calculate squared distance from the center
  int dx = x - centerX;
  int dy = y - centerY;
  int distanceSquared = dx * dx + dy * dy;

  // Compare squared distance with squared radius
  return distanceSquared <= (radius * radius);
}


inline void DIYables_TFT_GC9A01_Round::writeByte(uint8_t val) {
    writeData(&val, sizeof(val));
}

void DIYables_TFT_GC9A01_Round::begin() {
	pinMode(_res, OUTPUT);
    pinMode(_dc, OUTPUT);
    pinMode(_cs, OUTPUT);
    SPI.begin();

    setChipSelect(1);
    delayMs(5);
    setReset(0);
    delayMs(10);
    setReset(1);
    delayMs(120);

    /* Initial Sequence */ 
    
    writeCommand(0xEF);
    
    writeCommand(0xEB);
    writeByte(0x14);
    
    writeCommand(0xFE);
    writeCommand(0xEF);
    
    writeCommand(0xEB);
    writeByte(0x14);
    
    writeCommand(0x84);
    writeByte(0x40);
    
    writeCommand(0x85);
    writeByte(0xFF);
    
    writeCommand(0x86);
    writeByte(0xFF);
    
    writeCommand(0x87);
    writeByte(0xFF);
    
    writeCommand(0x88);
    writeByte(0x0A);
    
    writeCommand(0x89);
    writeByte(0x21);
    
    writeCommand(0x8A);
    writeByte(0x00);
    
    writeCommand(0x8B);
    writeByte(0x80);
    
    writeCommand(0x8C);
    writeByte(0x01);
    
    writeCommand(0x8D);
    writeByte(0x01);
    
    writeCommand(0x8E);
    writeByte(0xFF);
    
    writeCommand(0x8F);
    writeByte(0xFF);
    
    writeCommand(0xB6);
    writeByte(0x00);
    writeByte(0x00);
    
    writeCommand(0x36);

    setRotation(_rotation);
    
    writeCommand(COLOR_MODE);
    writeByte(COLOR_MODE__16_BIT); // <-- Change to 16-bit color mode
    
    writeCommand(0x90);
    writeByte(0x08);
    writeByte(0x08);
    writeByte(0x08);
    writeByte(0x08);
    
    writeCommand(0xBD);
    writeByte(0x06);
    
    writeCommand(0xBC);
    writeByte(0x00);
    
    writeCommand(0xFF);
    writeByte(0x60);
    writeByte(0x01);
    writeByte(0x04);
    
    writeCommand(0xC3);
    writeByte(0x13);
    writeCommand(0xC4);
    writeByte(0x13);
    
    writeCommand(0xC9);
    writeByte(0x22);
    
    writeCommand(0xBE);
    writeByte(0x11);
    
    writeCommand(0xE1);
    writeByte(0x10);
    writeByte(0x0E);
    
    writeCommand(0xDF);
    writeByte(0x21);
    writeByte(0x0c);
    writeByte(0x02);
    
    writeCommand(0xF0);
    writeByte(0x45);
    writeByte(0x09);
    writeByte(0x08);
    writeByte(0x08);
    writeByte(0x26);
    writeByte(0x2A);
    
    writeCommand(0xF1);
    writeByte(0x43);
    writeByte(0x70);
    writeByte(0x72);
    writeByte(0x36);
    writeByte(0x37);
    writeByte(0x6F);
    
    writeCommand(0xF2);
    writeByte(0x45);
    writeByte(0x09);
    writeByte(0x08);
    writeByte(0x08);
    writeByte(0x26);
    writeByte(0x2A);
    
    writeCommand(0xF3);
    writeByte(0x43);
    writeByte(0x70);
    writeByte(0x72);
    writeByte(0x36);
    writeByte(0x37);
    writeByte(0x6F);
    
    writeCommand(0xED);
    writeByte(0x1B);
    writeByte(0x0B);
    
    writeCommand(0xAE);
    writeByte(0x77);
    
    writeCommand(0xCD);
    writeByte(0x63);
    
    writeCommand(0x70);
    writeByte(0x07);
    writeByte(0x07);
    writeByte(0x04);
    writeByte(0x0E);
    writeByte(0x0F);
    writeByte(0x09);
    writeByte(0x07);
    writeByte(0x08);
    writeByte(0x03);
    
    writeCommand(0xE8);
    writeByte(0x34);
    
    writeCommand(0x62);
    writeByte(0x18);
    writeByte(0x0D);
    writeByte(0x71);
    writeByte(0xED);
    writeByte(0x70);
    writeByte(0x70);
    writeByte(0x18);
    writeByte(0x0F);
    writeByte(0x71);
    writeByte(0xEF);
    writeByte(0x70);
    writeByte(0x70);
    
    writeCommand(0x63);
    writeByte(0x18);
    writeByte(0x11);
    writeByte(0x71);
    writeByte(0xF1);
    writeByte(0x70);
    writeByte(0x70);
    writeByte(0x18);
    writeByte(0x13);
    writeByte(0x71);
    writeByte(0xF3);
    writeByte(0x70);
    writeByte(0x70);
    
    writeCommand(0x64);
    writeByte(0x28);
    writeByte(0x29);
    writeByte(0xF1);
    writeByte(0x01);
    writeByte(0xF1);
    writeByte(0x00);
    writeByte(0x07);
    
    writeCommand(0x66);
    writeByte(0x3C);
    writeByte(0x00);
    writeByte(0xCD);
    writeByte(0x67);
    writeByte(0x45);
    writeByte(0x45);
    writeByte(0x10);
    writeByte(0x00);
    writeByte(0x00);
    writeByte(0x00);
    
    writeCommand(0x67);
    writeByte(0x00);
    writeByte(0x3C);
    writeByte(0x00);
    writeByte(0x00);
    writeByte(0x00);
    writeByte(0x01);
    writeByte(0x54);
    writeByte(0x10);
    writeByte(0x32);
    writeByte(0x98);
    
    writeCommand(0x74);
    writeByte(0x10);
    writeByte(0x85);
    writeByte(0x80);
    writeByte(0x00);
    writeByte(0x00);
    writeByte(0x4E);
    writeByte(0x00);
    
    writeCommand(0x98);
    writeByte(0x3e);
    writeByte(0x07);
    
    writeCommand(0x35);
    writeCommand(0x21);
    
    writeCommand(0x11);
    delayMs(120);
    writeCommand(0x29);
    delayMs(20);
}

void DIYables_TFT_GC9A01_Round::setFrame(const Frame& frame) {
    uint8_t data[4];

    writeCommand(0x2A);
    data[0] = (frame.start.X >> 8) & 0xFF;
    data[1] = frame.start.X & 0xFF;
    data[2] = (frame.end.X >> 8) & 0xFF;
    data[3] = frame.end.X & 0xFF;
    writeData(data, sizeof(data));

    writeCommand(0x2B);
    data[0] = (frame.start.Y >> 8) & 0xFF;
    data[1] = frame.start.Y & 0xFF;
    data[2] = (frame.end.Y >> 8) & 0xFF;
    data[3] = frame.end.Y & 0xFF;
    writeData(data, sizeof(data));
}

void DIYables_TFT_GC9A01_Round::write(uint8_t *data, size_t len) {
    writeCommand(0x2C);
    writeData(data, len);
}

// Begin a continuous write (call before sending many pixels)
void DIYables_TFT_GC9A01_Round::beginWrite() {
    writeCommand(0x2C); // Use 0x2C (MEM_WR) to start a frame write
    setDataCommand(1);
    setChipSelect(0);
    SPI.beginTransaction(SPISettings(40000000, MSBFIRST, SPI_MODE0));
}

// Send pixel data during a continuous write
void DIYables_TFT_GC9A01_Round::writeContinue(uint8_t *data, size_t len) {
    spiTx(data, len);
}

// End a continuous write (call after all pixels sent)
void DIYables_TFT_GC9A01_Round::endWrite() {
    SPI.endTransaction();
    setChipSelect(1);
}

void DIYables_TFT_GC9A01_Round::drawPixel(int16_t x, int16_t y, uint16_t color) {
    if (!isPixelInsideCircle(x, y)) return;
    Frame frame = {{(uint16_t)x, (uint16_t)y}, {(uint16_t)x, (uint16_t)y}};
    setFrame(frame);
    uint8_t data[2] = { (uint8_t)(color >> 8), (uint8_t)(color & 0xFF) };
    write(data, 2);
}

uint16_t DIYables_TFT_GC9A01_Round::colorRGB(uint8_t r, uint8_t g, uint8_t b) {
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}

void DIYables_TFT_GC9A01_Round::fillScreen(uint16_t color) {
    // Set address window for the whole screen
    uint8_t data[4];
    writeCommand(0x2A); // Column address set
    data[0] = 0;
    data[1] = 0;
    data[2] = (width() - 1) >> 8;
    data[3] = (width() - 1) & 0xFF;
    writeData(data, 4);

    writeCommand(0x2B); // Row address set
    data[0] = 0;
    data[1] = 0;
    data[2] = (height() - 1) >> 8;
    data[3] = (height() - 1) & 0xFF;
    writeData(data, 4);

    writeCommand(0x2C); // Memory write

    setDataCommand(1);
    setChipSelect(0);

    // Use direct SPI transfer for maximum compatibility
    SPI.beginTransaction(SPISettings(40000000, MSBFIRST, SPI_MODE0));
    for (uint32_t i = 0; i < (uint32_t)width() * height(); i++) {
        SPI.transfer(color >> 8);   // High byte first
        SPI.transfer(color & 0xFF); // Low byte second
    }
    SPI.endTransaction();

    setChipSelect(1);
}

void DIYables_TFT_GC9A01_Round::setRotation(uint8_t r) {
    Adafruit_GFX::setRotation(r);
    _rotation = r & 0x03; // Only 0-3 valid
    writeCommand(0x36);
    switch (_rotation) {
        case 0:
            writeByte(0x48);
            break;
        case 1:
            writeByte(0xE8);
            break;
        case 2:
            writeByte(0x88);
            break;
        case 3:
            writeByte(0x28);
            break;
        default:
            writeByte(0x48);
            break;
    }
}

void DIYables_TFT_GC9A01_Round::invertDisplay(bool i) {
    writeCommand(i ? 0x21 : 0x20); // 0x21 = invert on, 0x20 = invert off
}