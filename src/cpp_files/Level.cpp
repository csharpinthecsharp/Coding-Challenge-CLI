#include "../hpp_files/Level.hpp"

Level::Level( int level ) : 
_level(level), 
_description(7) {}
Level::~Level() {}

void Level::loadDataFile( std::fstream& fs ) {
    char line[256];
    std::string line_s;
    while (fs.getline(line, 256))
    {
        line_s = line;
        size_t pos = line_s.find(':');
        if (pos != std::string::npos)
        {
            std::string value = line_s.substr(pos + 1);
            std::string key = line_s.substr(0, pos);

            if (key == "Title")
                this->setTitle(value);
            else if (key == "Subject")
                this->setSubject(value);
            else if (key == "Allowed_functions")
                this->setAllowedFunctions(value);
            else if (key == "Files_to_turn_in")
                this->setFileToTurnIn(value);
            else if (key == "Prototype")
                this->setPrototype(value);
            else if (key == "Hints")
                this->setHint(value);
            else if (key == "Examples")
                this->setExample(value);
        }
    }
    if (fs.eof())
        return;
    std::cerr << "Error: Smth went while reading a level file"  << std::endl;
    exit(1);
}

void Level::setTitle( const std::string& str ) {
    this->_description.at(0) = str;
}
void Level::setSubject( const std::string& str ) {
    this->_description.at(1) = str;
}
void Level::setAllowedFunctions( const std::string& str ) {
    this->_description.at(2) = str;
}
void Level::setFileToTurnIn( const std::string& str ) {
    this->_description.at(3) = str;
}
void Level::setPrototype( const std::string& str ) {
    this->_description.at(4) = str;
}
void Level::setHint( const std::string& str ) {
    this->_description.at(5) = str;
}
void Level::setExample( const std::string& str ) {
    this->_description.at(6) = str;
}

std::string Level::getTitle() const {
    return this->_description.at(0);
}
std::string Level::getSubject() const {
    return this->_description.at(1);
}
std::string Level::getAllowedFunctions() const {
    return this->_description.at(2);
}
std::string Level::getFileToTurnIn() const {
    return this->_description.at(3);
}
std::string Level::getPrototype() const {
    return this->_description.at(4);
}
std::string Level::getHints() const {
    return this->_description.at(5);
}
std::string Level::getExample() const {
    return this->_description.at(6);
}

int Level::getIntLevel() const {
    return (this->_level);
}

std::vector<std::string>& Level::getVector() {
    return (this->_description);
}


std::ostream& operator<<( std::ostream& os, const Level& level ) {
    os << level.getTitle() << std::endl;
    os << level.getSubject() << std::endl;
    os << level.getAllowedFunctions() << std::endl;
    os << level.getFileToTurnIn() << std::endl;
    os << level.getPrototype() << std::endl;
    os << level.getHints() << std::endl;
    os << level.getExample();
    return (os);
}
