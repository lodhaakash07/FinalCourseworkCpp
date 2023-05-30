#ifndef WINDOW_H
#define WINDOW_H

class Window {
private:
    int inSampleSize;
    int outSampleSize;

public:
    Window();
    Window(int inSample, int outSample);

    void setInSampleSize(int inSample);
    void setOutSampleSize(int outSample);

    int getInSampleSize() const;
    int getOutSampleSize() const;
};

#endif // WINDOW_H
