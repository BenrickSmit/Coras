#pragma once

/** @brief CorasCLI is a specialised class to provide a cli interface to the harware information

    Detailed description follows here.
    For more examples of doxygen comments, look here [https://www.doxygen.nl/manual/docblocks.html] and
    [https://flcwiki.desy.de/How%20to%20document%20your%20code%20using%20doxygen]
    
    @author Benrick Smit
    @date October 2020

*/
//\todo add in custom column size

#include <string>
#include "coras.h"

class CorasCLI  {
	public:
		// Ctors and Dtors		

		// Getters
		std::string get_gpu_information();
		std::string get_cpu_information();
		std::string get_mem_information();
		std::string get_os_information();

	protected:

		std::string adapted_string(std::string input, int length=14);
		std::string to_string(double input, int decimals=0);
		std::string repeat_char(char input, int length=14);

	private:
		// Member Variables
		Coras m_coras_info;

};