##-------------------------------------------------------------------------------------------------
## HEADER INFORMATION
##-------------------------------------------------------------------------------------------------
## This Shell Script is used to obtain the program filename from build_name.txt in build_info
## after which it will execute it.

## Read the filename from the chosen location
source_filename="${PWD}/build_info/build_name.txt"
exec_filename=(`cat $source_filename`)
exec_filename=${exec_filename}

## Change directory to execute the file
cd build/src
./${exec_filename}