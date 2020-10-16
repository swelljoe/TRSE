#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <QString>
#include <QByteArray>
#include <QFile>
#include "source/LeLib/limage/multicolorimage.h"
#include "source/LeLib/limage/limageqimage.h"
#include "source/LeLib/limage/charsetimage.h"
#include "source/LeLib/limage/c64fullscreenchar.h"
#include <QImage>
#include <math.h>
#include <QtMath>
#include "source/LeLib/limage/charsetimage.h"

class Compression
{
public:
    Compression();

    const int TYPE_REGULAR = 0;
    const int TYPE_SSIM = 1;

    void SaveCharset(QString filename, QImage& img, int w, int h, int div);
    void AddScreen(QByteArray& data, QImage& img, int w, int h, char base, int div);
    void AddToDataX(QByteArray& data, MultiColorImage& img,int x, int y, int w, int h);
    void AddToDataVGA(QByteArray& data, LImageQImage& img,int x, int y, int w, int h);
    void AddBitplaneToData(QByteArray& data, MultiColorImage& img,int x, int y, int w, int h, int bpl);
    void AddAmstradCPCToData(QByteArray& data, LImage* img,int x, int y, int w, int h);
    void AddAtariBitplaneToData(QByteArray& data, MultiColorImage& img,int x, int y, int w, int h);
    void AddSingleAtariBitplaneToData(QByteArray& data, MultiColorImage& img,int x, int y, int w, int h, int bpl_select);

    int CompareSprites(QByteArray& d1,QByteArray& d2, int sprite1, int sprite2);

    void CompressScreenAndCharset(QVector<int>& screen, QByteArray& charset, QVector<int> &sOut, QByteArray& cOut, int sw, int sh, int charSize, int noTargetChar,int bmask);

    void OptimizeScreenAndCharset(QVector<int>& screen, QByteArray& charset, QVector<int> &sOut, QByteArray& cOut, int sw, int sh, int charSize, double compression,int type, LColorList& lst, int bmask);
    void OptimizeScreenAndCharsetGB(QVector<int>& screen, QByteArray& charset, QVector<int> &sOut, QByteArray& cOut, int sw, int sh, int charSize, double compression,int type, LColorList& lst, int bmask);

    void SaveCompressedSpriteData(QByteArray& data, QString dataFile, QString tableFile, int address, int compressionLevel);

    double Compare(QByteArray& a, QByteArray& b, int p1, int p2, int length, int type, int bmask);

    void OptimizeAndPackCharsetData(QByteArray& dataIn, QByteArray& out, QByteArray& table, int width, double compression, bool invertTable,int type,LColorList& lst, int bmask);

    void ConvertToC64(bool dither);

    void AddCharsetScreen(QByteArray& data, QImage& img, CharsetImage* charset,int w, int h);

    void AddGameboyData(QByteArray &data, MultiColorImage &img, int xp, int yp, int w, int h);

 //   void m_compression.AddCharsetScreen(ba, m_effect->m_img, charset, lua_tonumber(L,1),lua_tonumber(L,2));


    void AddPetsciiScreen(QByteArray& data, QImage& img);
    void AddBinaryScreen(QByteArray& data, QImage& img);

    void SaveCompressedTRM(QByteArray& data, QString file, int compression);
};

#endif // COMPRESSION_H
