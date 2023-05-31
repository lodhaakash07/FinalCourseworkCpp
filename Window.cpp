#include "Headers/Window.h"

Window::Window() : inSampleSize(0), outSampleSize(0) {}

Window::Window(int inSample, int outSample) : inSampleSize(inSample), outSampleSize(outSample) {}

void Window::setInSampleSize(int inSample) {
    inSampleSize = inSample;
}

void Window::setOutSampleSize(int outSample) {
    outSampleSize = outSample;
}

int Window::getInSampleSize() const {
    return inSampleSize;
}

int Window::getOutSampleSize() const {
    return outSampleSize;
}