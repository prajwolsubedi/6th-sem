#include <stdio.h>
#include <stdbool.h>

void countLinesWordsChars(const char *str, int *lines, int *words, int *chars) {
    bool inWord = false;
    *lines = *words = *chars = 0;

    while (*str) {
        (*chars)++;

        if (*str == '\n') {
            (*lines)++;
        }

        if (*str == ' ' || *str == '\n' || *str == '\t') {
            inWord = false;
        } else if (inWord == false) {
            inWord = true;
            (*words)++;
        }

        str++;
    }

    // If the string does not end with a newline, count the last line
    if (*chars > 0 && *(str - 1) != '\n') {
        (*lines)++;
    }
}

int main() {
    char str[1000];
    printf("Enter a string:\n");
    fgets(str, sizeof(str), stdin);

    int lines, words, chars;
    countLinesWordsChars(str, &lines, &words, &chars);

    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", chars);

    return 0;
}
