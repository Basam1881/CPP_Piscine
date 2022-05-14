#include "FileReplacer.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FileReplacer::FileReplacer(char *fileName, char *s1, char *s2) : _fileName(fileName), _s1(s1), _s2(s2)
{
	this->success = 0;
	this->_invalidFiles = 0;
	this->_mainFile.open(fileName, std::fstream::in | std::fstream::out);
	if (!this->_mainFile || _s1.empty()) {
		this->_invalidFiles = 1;
		return ;
	}
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FileReplacer::~FileReplacer()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/

int		FileReplacer::fail() {
	if (this->_invalidFiles || !this->success)
		return (1);
	return (0);
}

void	FileReplacer::replace() {
	if (this->_invalidFiles)
		return ;
	this->_fileNameR = this->_fileName + ".replace";
	this->_newFile.open(this->_fileNameR.c_str());
	if (!this->_newFile)
		this->_invalidFiles = 1;
	if (this->_invalidFiles)
		return ;
	this->_ss << this->_mainFile.rdbuf();
	this->_mainFile.close();
	this->_str = this->_ss.str();
	this->_found = this->_str.find(this->_s1);
	while (this->_found != std::string::npos) {
		this->_str.erase(this->_found, this->_s1.length());
		this->_str.insert(this->_found, this->_s2);
		this->_found = this->_str.find(this->_s1, this->_found + this->_s2.length());
	}
	this->_newFile << this->_str;
	this->_newFile.close();
	this->success = 1;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */