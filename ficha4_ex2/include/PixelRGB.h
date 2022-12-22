#ifndef PIXELRGB_H
#define PIXELRGB_H
#include <iostream>
using namespace std;

class PixelRGB
{
    char r,g,b;
    public:
        PixelRGB();
        PixelRGB(char cr = 0, char cg = 0, char cb = 0) : r(cr), g(cg), b(cb) {}
        int getR() const { return r; }
        int getG() const { return g; }
        int getB() const { return b; }
        void setR(int c) { r = c; }
        void setG(int c) { g = c; }
        void setB(int c) { b = c; }

        virtual ~PixelRGB();

    protected:

    private:
};

#endif // PIXELRGB_H
