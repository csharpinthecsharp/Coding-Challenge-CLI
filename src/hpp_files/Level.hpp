#ifndef LEVEL_HPP
#define LEVEL_HPP 

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

enum {
    TITLE,
    SUBJECT,
    ALL_FNC,
    FILE_T_IN,
    PROTO,
    HINT,
    EXAMPL,
};

class Level {
    private:
        int _level;
        std::vector<std::string> _description;
    public:
        Level( int level);
        ~Level();

        void setTitle( const std::string& str );
        void setSubject( const std::string& str );
        void setAllowedFunctions( const std::string& str );
        void setFileToTurnIn( const std::string& str );
        void setPrototype( const std::string& str );
        void setHint( const std::string& str );
        void setExample( const std::string& str );

        std::string getTitle() const;
        std::string getSubject() const;
        std::string getAllowedFunctions() const;
        std::string getFileToTurnIn() const;
        std::string getPrototype() const;
        std::string getHints() const;
        std::string getExample() const;

        int getIntLevel() const;
        std::vector<std::string>& getVector();

        void loadDataFile( std::fstream &fs );
};

std::ostream& operator<<( std::ostream& os, const Level& level );
#endif