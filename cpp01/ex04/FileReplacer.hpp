/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:37:42 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/17 14:37:43 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACER_HPP
# define FILEREPLACER_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

class FileReplacer
{

	public:

		FileReplacer(char *fileName, char *s1, char *s);
		~FileReplacer();

		void	replace();
		int		fail();

	private:
		int					_invalidFiles;
		std::size_t			_found;
		std::string			_str;
		std::string			_fileName;
		std::string			_fileNameR;
		std::ifstream		_mainFile;
		std::string			_s1;
		std::string			_s2;
		std::ostringstream	_ss;
		std::ofstream		_newFile;
		int					success;

};


#endif /* **************************************************** FILEREPLACER_H */