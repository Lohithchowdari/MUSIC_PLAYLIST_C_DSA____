#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[40];
    struct node* next;
    struct node* prev;
};

char temp[40];
struct node* head = NULL;
struct node* current_node = NULL;

void add_music_node() {
    printf("Enter the music name: ");
    scanf("%39s", temp);

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(new_node->data, temp);

    if (head == NULL) {
        new_node->next = new_node->prev = new_node;
        head = current_node = new_node;
    } else {
        struct node* last = head->prev;
        new_node->prev = last;
        new_node->next = head;
        last->next = head->prev = new_node;
    }
    printf("Music file - %s added to the playlist.\n", new_node->data);
}

void remove_music_node() {
    if (head == NULL) {
        printf("There is no music saved in your playlist.\n");
        return;
    }

    printf("Enter music name to be deleted: ");
    scanf("%39s", temp);
    struct node* ptr = head;

    do {
        if (strcmp(ptr->data, temp) == 0) {
            if (ptr->next == ptr) {
                printf("Music file - %s deleted. Your playlist is empty now!\n", temp);
                head = NULL;
            } else {
                struct node* prev = ptr->prev;
                struct node* next = ptr->next;
                prev->next = next;
                next->prev = prev;
                if (ptr == head) {
                    head = next;
                }
                printf("Music File - %s deleted.\n", temp);
            }
            free(ptr);
            return;
        }
        ptr = ptr->next;
    } while (ptr != head);

    printf("No music file found by name: %s.\n", temp);
}

void show_all_music_nodes() {
    if (head == NULL) {
        printf("Your playlist is empty!!!\n");
        return;
    }
    struct node* ptr = head;
    printf("\nYour music from your playlist:\n");
    int i = 1;
    do {
        printf("Song %d: %s\n", i++, ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

void show_next_music_node() {
    if (current_node == NULL) {
        printf("No songs in your playlist.\n");
    } else {
        current_node = current_node->next;
        printf("Playing Song: %s\n", current_node->data);
    }
}

void show_previous_music_node() {
    if (current_node == NULL) {
        printf("No songs in your playlist.\n");
    } else {
        current_node = current_node->prev;
        printf("Playing Song: %s\n", current_node->data);
    }
}

void show_first_music_node() {
    if (head == NULL) {
        printf("Playlist is empty!!!\n");
    } else {
        current_node = head;
        printf("Playing Music: %s\n", head->data);
    }
}

void show_last_music_node() {
    if (head == NULL) {
        printf("Playlist is empty!!!\n");
    } else {
        current_node = head->prev;
        printf("Playing Music: %s\n", current_node->data);
    }
}

void show_specific_music_node() {
    if (head == NULL) {
        printf("Your playlist is empty!!!\n");
        return;
    }
    printf("Enter the music to be played: ");
    scanf("%39s", temp);

    struct node* ptr = head;
    do {
        if (strcmp(ptr->data, temp) == 0) {
            current_node = ptr;
            printf("Music Found\nPlaying Music: %s\n", ptr->data);
            return;
        }
        ptr = ptr->next;
    } while (ptr != head);

    printf("No music file found by name: %s\n", temp);
}

int main() {
    int choice;
    while (1) {
        printf("\n-------Music Playlist Menu--------\n");
        printf("1. Add New Music to the playlist\n");
        printf("2. Remove Music from playlist\n");
        printf("3. Display all songs in the playlist\n");
        printf("4. Play Next Song\n");
        printf("5. Play Previous Song\n");
        printf("6. Play first song of the playlist\n");
        printf("7. Play last song of the playlist\n");
        printf("8. Play specific song from the playlist\n");
        printf("9. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_music_node();
                break;
            case 2:
                remove_music_node();
                break;
            case 3:
                show_all_music_nodes();
                break;
            case 4:
                show_next_music_node();
                break;
            case 5:
                show_previous_music_node();
                break;
            case 6:
                show_first_music_node();
                break;
            case 7:
                show_last_music_node();
                break;
            case 8:
                show_specific_music_node();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("You Entered an incorrect option!!!\n");
        }
    }
    return 0;
}
