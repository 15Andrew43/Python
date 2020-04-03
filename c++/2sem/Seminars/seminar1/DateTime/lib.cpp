#include <iostream>
#include <cstring>
#include <iomanip>

void Delete(char** array, int n=3) {
	for (int i = 0; i < n; ++i) {
			delete[] array[i];
		}
	delete[] array;
}
/*
bool split(char* type_str, char** ArrayOfStr, int n=3) {
	int* seperate_ind = new int[n];
	int k=-1;
	int L = strlen(type_str);
	type_str[L] = '.';
	if (L > 10) {
		delete[] seperate_ind;
		return false;
	}
	for (int i = 0; type_str[i]; ++i) {
		if (type_str[i] == '.' || type_str[i] == '/' || type_str[i] == '-') {
			if (++k > 2) {
				delete[] seperate_ind;
				return false;
			}
			seperate_ind[k] = i;
		}
	}

	int start = 0;
	k = 0;
	int end = seperate_ind[k];
	for (int j = 0; j < n; ++j) {
		for (int i = start; i < end; ++i) {
			ArrayOfStr[j][i-start] = type_str[i];
		}
		start = end+1;
		end = seperate_ind[++k];
	}

	delete[] seperate_ind;
	return true;
}
*/
int ToNumber(const char* str) {
/*	
	int number = 0;
	int magnitude = 1;
	int L = strlen(str);
	for (int i = L-1; i >= 0; --i) {
		number += ( magnitude * (int)(str[i]-'0') );
		magnitude *= 10;
	}
	return number;
*/
	return atoi(str);
}

bool ParseString(int* type_array, char* type_str, char sep='/') {
//array consist of strings ( array like {{"1543"}, {"179"}, {"57"}	)
	int n=3;
	char** ArrayOfStr = new char* [n];
	for (int i = 0 ; i < n; ++i) {
		ArrayOfStr[i] = new char[5];
	}

//	seperate_ind  - array with index where seperating index is
	int* seperate_ind = new int[n];
	int place=-1; // index [0, L-1]
	int L = strlen(type_str);
	type_str[L] = sep;
	if (L > 10) {
		Delete(ArrayOfStr);
		delete[] seperate_ind;
		return false;
	}
	for (int i = 0; type_str[i]; ++i) {
		if (type_str[i] == sep) {
			if (++place > 2) {
				Delete(ArrayOfStr);
				delete[] seperate_ind;
				return false;
			}
			seperate_ind[place] = i;
		}
	}

//	fill the ArrayOfStr with Str(Str like "1234")
	int start = 0;
	place = 0;
	int end = seperate_ind[place];
	for (int j = 0; j < n; ++j) {
		for (int i = start; i < end; ++i) {
			ArrayOfStr[j][i-start] = type_str[i];
		}
		start = end+1;
		end = seperate_ind[++place];
	}
	delete[] seperate_ind;

//	convert str to numbers in array
	for (int i = 0; i < n; ++i) {
		type_array[i] = ToNumber(ArrayOfStr[i]);
	}

	Delete(ArrayOfStr, n);
	return true;
}