#ifndef LADDER_H
#define LADDER_H

#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <vector>
#include <string>

using namespace std;

void load_words(set<string>& word_list, const string& file_name);
bool is_adjacent(const string& word1, const string& word2);
bool edit_distance_within(const string& str1, const string& str2, int d);
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list);
void print_word_ladder(const vector<string>& ladder);
void verify_word_ladder();

#endif
