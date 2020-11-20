#----------first agument can be whatever - it's a name of the lib
#
#----------there is no need to write "adder.hpp" 
#----------but it makes 2 files into a librarya and not just .cpp it works cuz it has definition and implementation


add_library(adder adder.cpp adder.hpp)