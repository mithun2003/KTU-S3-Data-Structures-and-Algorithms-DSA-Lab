#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 100     // Size of the hash table
#define WORD_SIZE 50       // Maximum word length

// Node structure for chaining
struct Node {
    char word[WORD_SIZE];
    struct Node* next;
};

// Hash table array (array of pointers to Node)
struct Node* hashTable[TABLE_SIZE];

// -------------------- Hash Function --------------------
// Simple hash function: sum of ASCII values modulo TABLE_SIZE
int hashFunction(const char* word) {
    unsigned long hash = 0;
    for (int i = 0; word[i] != '\0'; i++)
        hash = hash + tolower(word[i]);
    return hash % TABLE_SIZE;
}

// -------------------- Insert Word --------------------
void insertWord(const char* word) {
    int index = hashFunction(word);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// -------------------- Search Word --------------------
int searchWord(const char* word) {
    int index = hashFunction(word);
    struct Node* temp = hashTable[index];

    while (temp != NULL) {
        if (strcasecmp(temp->word, word) == 0)
            return 1;  // Word found
        temp = temp->next;
    }
    return 0; // Word not found
}

// -------------------- Load Dictionary --------------------
void loadDictionary() {
    // For simplicity, insert words manually or you can use a file later.
    char *words[] = {"apple", "banana", "orange", "grape", "cat", "dog",
                     "elephant", "tiger", "lion", "zebra", "car", "bus", "train"};
    int n = sizeof(words) / sizeof(words[0]);

    for (int i = 0; i < n; i++)
        insertWord(words[i]);

    printf("Dictionary loaded with %d words.\n", n);
}

// -------------------- Suggest Similar Words --------------------
void suggestCorrections(const char* word) {
    printf("Did you mean:\n");

    // Suggest words that start with the same first letter
    char first = tolower(word[0]);
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            if (tolower(temp->word[0]) == first)
                printf("- %s\n", temp->word);
            temp = temp->next;
        }
    }
}

// -------------------- Display All Words --------------------
void displayDictionary() {
    printf("\n--- Dictionary Contents ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%s\n", temp->word);
            temp = temp->next;
        }
    }
}

// -------------------- Main Function --------------------
int main() {
    int choice;
    char word[WORD_SIZE];

    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;

    loadDictionary();

    do {
        printf("\n--- Spell Checker Menu ---\n");
        printf("1. Check if Word is Valid\n");
        printf("2. Suggest Corrections\n");
        printf("3. Display Dictionary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                printf("Enter word to check: ");
                scanf("%s", word);
                if (searchWord(word))
                    printf("'%s' is a valid word!\n", word);
                else
                    printf("'%s' is NOT found in dictionary.\n", word);
                break;

            case 2:
                printf("Enter misspelled word: ");
                scanf("%s", word);
                if (searchWord(word))
                    printf("'%s' is already a valid word.\n", word);
                else
                    suggestCorrections(word);
                break;

            case 3:
                displayDictionary();
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (1);

    return 0;
}