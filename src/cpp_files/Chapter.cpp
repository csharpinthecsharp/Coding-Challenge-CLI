#include "../hpp_files/Chapter.hpp"

Chapter::Chapter( int chapter ) : _chapter(chapter) {
}
Chapter::~Chapter() {}

void Chapter::loadLevels()
{
    size_t count = 0;
    for (size_t i(1); i < 10; i++) {
            std::stringstream ss;
            ss << "data/chapter_" << _chapter << "/level_" << i << ".dt";
            std::string path = ss.str();
            std::fstream file(path.c_str(), std::fstream::in);
        if (file.good())
        {
            Level newLevel(i);
            newLevel.loadDataFile(file);
            _levels.push_back(newLevel);
            count++;
        }
    }
    if (!count) {
        std::cout << "Error: No levels found in data (chapter " << _chapter << ")" << std::endl;
        exit(1);
    }
    std::cout << "Found: " << count <<  " Level in chapter " << _chapter << std::endl;
}


Level& Chapter::getFromChaptersLevelsObjects( int n ) {
    for (std::vector<Level>::iterator it(_levels.begin()); it != _levels.end(); ++it) {
        if (it->getIntLevel() == n)
            return (*it);
    }
    std::cerr << "Level " << n << " in Chapter " << _chapter << " in your profile.dt doesn't exist" << std::endl;
    exit(1);
}


int Chapter::getIntChapter() const {
    return (this->_chapter);
}