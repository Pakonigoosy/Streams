#include "FileGapsRemover.h"
#include <iostream> //for debugging
int remove_gaps(std::string filename) {
	FILE** ifPtr = new FILE*;
	fopen_s(ifPtr, filename.c_str(), "r");
	std::string data;
	char sym;
	char pre = 'q'; //initialising "previous symbol" variable on random non-gap symbol 
	bool beg = true; //indicates if current symbol is before beginning of useful part of file
	if (!ifPtr) {
		return -1; //Cannot open file for reading
	}
	while ((sym=fgetc(*ifPtr))!=EOF) {
		if (beg && sym == ' ') {
			continue; //gap in the beginning. Doing nothing
		}
		else if (beg && sym != ' ') {
			beg = false; //useful part of file began
			data.push_back(sym);
		}
		else if (!beg && sym == ' ' && pre == ' ') {
			continue; //Double gap detected. Doing nothing
		}
		else if (!beg && sym == ' ' && pre != ' ') {
			data.push_back(sym); //Single gap
		}
		else if (!beg && sym != ' ') {
			data.push_back(sym); //Not gap
		}

		pre = sym;
	}
	if (data.length() == 0) {
		return 0; //Text consists of gaps or no text detected
	}
	if (data[data.length() - 1] == ' ') {
		data.pop_back(); //Deleting last symbol if it is gap
	}
	fclose(*ifPtr);
	FILE** ofPtr = new FILE*;
	fopen_s(ofPtr, filename.c_str(), "w");
	if (!ofPtr) {
		return -2; //Cannon open file for writing
	}
	for (auto i: data)
	{
		fputc(i, *ofPtr);
	}
	fclose(*ofPtr);
	return 1; //OK
}