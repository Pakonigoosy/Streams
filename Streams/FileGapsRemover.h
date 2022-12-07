#pragma once
#include <string>
#include <fstream>
#include <cstdio>
//Opens file specified in "filename" parameter and deletes all extra gaps (double gaps and gaps at the beginning and the end of file)
//filename - name of file to be modified
//Returns values:
//-2	File cannot be writed
//-1	File cannot be read
//0		No text detected or text consists of gaps
//1		OK
int remove_gaps(std::string filename); 