Stats
Kata
Solutions
Translations
Collections
Kumite
Social
Discourse
Completed(8)
Unfinished
Obsolete
6 kyu
Duplicate Encoder
C :
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
char *DuplicateEncoder(char *str)
{
	int count = 0, length = strlen(str);
	char* new_str;

	new_str = (char*)malloc(length * sizeof(char));

	for (int i = 0; i < length; i++) {
		int a = tolower(str[i]);
		for (int j = 0; j < length; j++) {
			int b = tolower(str[j]);
			if (a == b && i != j && new_str[i] != ')' && new_str[i] != '(') new_str[i] = ')';
			else if (j == length - 1 && new_str[i] != ')' && new_str[i] != '(') new_str[i] = '(';
		}
	}
	new_str[length] = '\0';

	return  new_str;
}
3 months agoRefactorDiscuss
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
char *DuplicateEncoder(char *str) {
	int count = 0, length = strlen(str);
	char* new_str;

	new_str = (char*)malloc(length * sizeof(char));
	for (int i = 0; i < length; i++) {
		int a = tolower(str[i]);
		for (int j = 0; j < length; j++) {
			int b = tolower(str[j]);
			if (a == b && i != j && new_str[i] != ')' && new_str[i] != '(' && new_str[i] != '@') new_str[i] = ')';
			else if (j == length - 1 && new_str[i] != ')' && new_str[i] != '(' && new_str[i] != '@') new_str[i] = '(';
		}
	}
	new_str[length] = '\0';
	return new_str;
}
3 months agoRefactorDiscuss
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
char *DuplicateEncoder(char *str)
{
	int count = 0, length = strlen(str);
	char* new_str;

	new_str = (char*)malloc(length * sizeof(char));

	for (int i = 0; i < length; i++) {
		if (str[i] == '@') {
			new_str[i] = '@';
			count++;
			continue;
		}

		int a = tolower(str[i]);
		for (int j = 0; j < length; j++) {
			int b = tolower(str[j]);
			if (a == b && i != j && new_str[i] != ')' && new_str[i] != '(' && new_str[i] != '@') new_str[i] = ')';
			else if (j == length - 1 && new_str[i] != ')' && new_str[i] != '(' && new_str[i] != '@') new_str[i] = '(';
		}
	}

	if (count) {
		for (int i = 0; i < length; i++) if (new_str[i] == '@') {
			new_str[i] = '(';
			new_str[i + 1] = '(';
			length++;
		}
	}
	new_str[length] = '\0';

	return  new_str;
}
3 months agoRefactorDiscuss
4 kyu
Twice linear
C++:
#include <set>
#include <iostream>
using namespace std;
class DoubleLinear
{
public:
	static int dblLinear(int n) {
		set<int> numbers = { 1 };
		auto it = numbers.begin();
		for (int i = 0; i < n; i++, it++) {
			numbers.insert(*it * 2 + 1);
			numbers.insert(*it * 3 + 1);
		}
		it = numbers.begin();
		for (int i = 0; i < n; i++, it++);
		return *it;
	}
};
