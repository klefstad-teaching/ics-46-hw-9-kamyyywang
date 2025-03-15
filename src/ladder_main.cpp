#include "ladder.h"

int main() {
    set<string> word_list;
    load_words(word_list, "src/words.txt");
    
    string begin_word = "work";
    string end_word = "play";
    
    vector<string> ladder = generate_word_ladder(begin_word, end_word, word_list);
    print_word_ladder(ladder);
    
    return 0;
}
