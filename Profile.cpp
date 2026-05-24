#include "Profile.hpp"

Profile::Profile()
: _level(1),
_chapter(1) { }
Profile::~Profile() { }

void Profile::setLevel( unsigned int n ) {
    this->_level = n;
}
void Profile::setChapter( unsigned int n) {
    this->_chapter = n;
}
unsigned int Profile::getLevel() const {
    return (this->_level);
}
unsigned int Profile::getChapter() const {
    return (this->_chapter);
}

void Profile::retrieveProfileData() {
    std::fstream file;
    char line[64];
    std::string line_s;
    file.open("data/profile.dt", std::fstream::in);
    if (!file.is_open())
    {
        std::cout << "No profile data, creating one." << std::endl;
        file.open("data/profile.dt", std::fstream::out);
        file << "level:1\n" << "chapter:1";
        this->setLevel(1);
        this->setChapter(1);
        return;
    }
    std::cout << "Found a profile data" << std::endl;
    while (file.getline(line, 64))
    {
        line_s = line;
        size_t pos = line_s.find(':');
        if (pos != std::string::npos)
        {
            std::string value = line_s.substr(pos + 1);
            std::string key = line_s.substr(0, pos);
            int n = atoi(value.c_str());
            if (n <= 0)
            {
                std::cerr << "Error: atoi on profile.dt" << std::endl;
                exit(1);
            }

            if (key == "level")
                this->setLevel(n);
            else if (key == "chapter")
                this->setChapter(n);
        }
    }
    if (file.eof()) {
        std::cout << "EOF -> profile.data" << std::endl;
        std::cout << "lvl: " << this->getLevel() << " cpt: " << this->getChapter() << std::endl;
        return;
    }
    std::cerr << "Error: Smth went while reading in profile.data" << std::endl;
    exit(1);
}

void Profile::loadChapters()
{
    size_t count = 0;
    for (size_t i(1); i < 10; i++) {
            std::stringstream ss;
            ss << "data/chapter_" << i;
            std::string path = ss.str();
            std::fstream file(path.c_str(), std::fstream::in);
        if (file.good())
        {
            Chapter newChap(i);
            _chapters.push_back(newChap);
            count++;
        }
    }
    if (!count) {
        std::cout << "Error: No chapters found in data" << std::endl;
        exit(1);
    }
    std::cout << "Found: " << count <<  " Chapter" << std::endl; 
}
