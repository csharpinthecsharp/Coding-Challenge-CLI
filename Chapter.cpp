#include "Chapter.hpp"

Chapter::Chapter( int chapter ) : _chapter(chapter) {
    std::cout << "im alive: " << chapter << std::endl;
}
Chapter::~Chapter() {}