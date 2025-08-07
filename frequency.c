//Write a C program that takes a paragraph input from the user, counts the frequency of each word in the paragraph,
//and prints the frequencies.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PARAGRAPH_LENGTH 1000
#define MAX_WORDS 200
#define MAX_WORD_LENGTH 50


void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}


void removePunctuation(char *word) {
    int i = 0, j = 0;
    char temp[MAX_WORD_LENGTH];
    while (word[i]) {
        if (isalpha(word[i]))
            temp[j++] = word[i];
        i++;
    }
    temp[j] = '\0';
    strcpy(word, temp);
}

int main() {
    char paragraph[MAX_PARAGRAPH_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int count[MAX_WORDS] = {0};
    int wordCount = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);
    paragraph[strcspn(paragraph, "\n")] = '\0'; // remove newline

    // Tokenize the paragraph into words
    char *token = strtok(paragraph, " ");
    while (token != NULL) {
        toLowerCase(token);
        removePunctuation(token);

        if (strlen(token) == 0) {
            token = strtok(NULL, " ");
            continue;
        }

        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], token) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(words[wordCount], token);
            count[wordCount] = 1;
            wordCount++;
        }

        token = strtok(NULL, " ");
    }

    // Print word frequencies
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s : %d\n", words[i], count[i]);
    }

    return 0;
}