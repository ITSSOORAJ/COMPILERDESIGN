#include <stdio.h>
#include <string.h>

char enfa[20][3];  // Array to store transitions
char final[30];    // Array to store final states
int ntrans;        // Number of transitions

// Function to check if a character is in a string
int isin(char c, char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

// Function to add a character to a string if it's not already there
void add(char str[], char c) {
    if (!isin(c, str)) {
        int len = strlen(str);
        str[len] = c;
        str[len + 1] = '\0';
    }
}

// Recursive function to handle epsilon transitions and add valid transitions
void addstate(char c1, char c2) {
    for (int i = 0; i < ntrans; i++) {
        if (enfa[i][0] == c2 && enfa[i][1] != 'e') {
            printf("%c%c%c\n", c1, enfa[i][1], enfa[i][2]);
        } else if (enfa[i][0] == c2 && enfa[i][1] == 'e' && enfa[i][2] != c1) {
            addstate(c1, enfa[i][2]);
        }
    }
}

int main() {
    int i;

    // Input the number of transitions
    printf("Enter number of transitions: ");
    scanf("%d", &ntrans);

    // Input each transition in the format: state symbol state
    printf("Enter transitions as state symbol state:\n");
    for (i = 0; i < ntrans; i++) {
        scanf(" %c %c %c", &enfa[i][0], &enfa[i][1], &enfa[i][2]);
    }

    // Input final states
    printf("Enter final states: ");
    scanf("%s", final);

    // Print NFA transitions that are not epsilon transitions
    printf("NFA transitions:\n");
    for (i = 0; i < ntrans; i++) {
        if (enfa[i][1] != 'e') {
            printf("%c%c%c\n", enfa[i][0], enfa[i][1], enfa[i][2]);
        } else {
            // Handle epsilon transitions
            addstate(enfa[i][0], enfa[i][2]);
        }
    }

    // Adjust final states considering epsilon transitions
    for (i = ntrans - 1; i >= 0; i--) {
        if (isin(enfa[i][2], final) && enfa[i][1] == 'e') {
            add(final, enfa[i][0]);
        }
    }

    // Print final states after considering epsilon closures
    printf("Final states: {%s}\n", final);

    return 0;
}

