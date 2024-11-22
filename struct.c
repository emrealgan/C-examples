#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countWords(const char *str) {
    int count = 0;
    int inWord = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (isspace(str[i])) {
            inWord = 0;
        } else if (!inWord) {
            ++count;
            inWord = 1;
        }
    }

    return count;
}

typedef struct Word {
    char word[15];
    int length;
} Word;

int findLongestWordIndex(const Word *words, int size) {
    int maxIndex = 0;

    for (int i = 1; i < size; ++i) {
        if (words[i].length > words[maxIndex].length) {
            maxIndex = i;
        }
    }

    return maxIndex;
}

int main() {
    char input[100];

    printf("Enter a sentence: ");
    fgets(input, 100, stdin);

    input[strcspn(input, "\n")] = '\0';

    int wordCount = countWords(input);
    Word words[wordCount];

    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL) {
        strncpy(words[i].word, token, 14);
        words[i].length = strlen(token);
        token = strtok(NULL, " ");
        ++i;
    }

    int longestIndex = findLongestWordIndex(words, wordCount);
    printf("The longest word is: %s\n", words[longestIndex].word);

    return 0;
}
