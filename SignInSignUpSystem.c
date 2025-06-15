#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void signUp() {
    char username[MAX], password[MAX];
    printf("\n=== Sign Up ===\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    FILE *fp = fopen("users.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "%s %s\n", username, password);
    fclose(fp);
    printf("✅ Registered successfully!\n\n");
}

void signIn() {
    char username[MAX], password[MAX], fileUser[MAX], filePass[MAX];
    int found = 0;

    printf("\n=== Sign In ===\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    FILE *fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("No users found. Please sign up first.\n");
        return;
    }

    while (fscanf(fp, "%s %s", fileUser, filePass) != EOF) {
        if (strcmp(username, fileUser) == 0 && strcmp(password, filePass) == 0) {
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (found)
        printf("✅ Login successful!\n\n");
    else
        printf("❌ Invalid username or password.\n\n");
}

int main() {
    int choice;
    do {
        printf("====== MENU ======\n");
        printf("1. Sign Up\n");
        printf("2. Sign In\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: signUp(); break;
            case 2: signIn(); break;
            case 0: printf("Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}