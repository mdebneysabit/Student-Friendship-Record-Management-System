#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Define a structure to represent a student
struct Student {
    char name[50];
    struct Student* friends;
    struct Student* next;
};

// Initialize the head of the student list
struct Student* head = NULL;

// Function to create a new student
struct Student* createStudent(char name[]) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    strcpy(newStudent->name, name);
    newStudent->friends = NULL;
    newStudent->next = NULL;
    return newStudent;
}

// Function to add a new student to the network
void addStudent(char name[]) {
    struct Student* newStudent = createStudent(name);
    if (head == NULL) {
        head = newStudent;
    } else {
        struct Student* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }
}

// Function to establish a friendship between two students
void establishFriendship(char student1[], char student2[]) {
    struct Student* s1 = head;
    struct Student* s2 = head;

    while (s1 != NULL && strcmp(s1->name, student1) != 0) {
        s1 = s1->next;
    }

    while (s2 != NULL && strcmp(s2->name, student2) != 0) {
        s2 = s2->next;
    }

    if (s1 == NULL || s2 == NULL) {
        printf("Student not found.\n");
        return;
    }

    // Add student2 to the friend list of student1
    struct Student* newFriend = createStudent(s2->name);
    newFriend->next = s1->friends;
    s1->friends = newFriend;

    // Add student1 to the friend list of student2
    newFriend = createStudent(s1->name);
    newFriend->next = s2->friends;
    s2->friends = newFriend;
}

// Function to find common friends between two students
void findCommonFriends(char student1[], char student2[]) {
    struct Student* s1 = head;
    struct Student* s2 = head;

    while (s1 != NULL && strcmp(s1->name, student1) != 0) {
        s1 = s1->next;
    }
    while (s2 != NULL && strcmp(s2->name, student2) != 0) {
        s2 = s2->next;
    }
    if (s1 == NULL || s2 == NULL) {
        printf("Student not found.\n");
        return;
    }
    struct Student* commonFriends = NULL;
    struct Student* friend1 = s1->friends;
    while (friend1 != NULL) {
        struct Student* friend2 = s2->friends;
        while (friend2 != NULL) {
            if (strcmp(friend1->name, friend2->name) == 0) {
                struct Student* commonFriend = createStudent(friend1->name);
                commonFriend->next = commonFriends;
                commonFriends = commonFriend;
            }
            friend2 = friend2->next;
        }
        friend1 = friend1->next;
    }

    if (commonFriends == NULL) {
        printf("No common friends found.\n");
    } else {
        printf("Common friends between %s and %s:\n", student1, student2);
        struct Student* current = commonFriends;
        while (current != NULL) {
            printf("<<%s>>\n", current->name);
            current = current->next;
        }
    }
}

// Function to display the entire network
void displayNetwork() {
    struct Student* current = head;
    while (current != NULL) {
        printf("Student: %s\nFriends: ", current->name);
        struct Student* friend = current->friends;
        while (friend != NULL) {
            printf("%s, ", friend->name);
            friend = friend->next;
        }
        printf("\n\n");
        current = current->next;
    }
}

// Function to free memory used by the network
void freeNetwork() {
    struct Student* current = head;
    while (current != NULL) {
        struct Student* friend = current->friends;
        while (friend != NULL) {
            struct Student* temp = friend;
            friend = friend->next;
            free(temp);
        }
        struct Student* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}

int main() {
    char username[20]="studentfriendshipnetwork";
    char passcode[20]="studentfriendshipnetwork1234";
    char use[20];
    char pass[20];
    printf ("\t\t\t--------------------------------------------\n");
    printf("\t\t\t---<<STUDENT RECORD MANAGEMENT SYSTEM>>---\n");
    printf ("\t\t\t--------------------------------------------\n");
    printf("\n\n\n");
    printf("SUBMITTED BY_");
            printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
            printf("\n\t\t\t        =          Name                           ID        =");
            printf("\n\t\t\t        =***************************************************=");
            printf("\n\t\t\t        = Md Ebney Sabit          **      0242310005101128  =");
            printf("\n\t\t\t        = Dipto Chandra Paul      **      0242310005101316  =");
            printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\nSUBMITTED TO_");
       printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
       printf("\n\t\t\t        =    Ms. Tanzina Afroz Rimi(TAR)  =");
       printf("\n\t\t\t        =*********************************=");
       printf("\n\t\t\t        =    Lecturer                     =");
       printf("\n\t\t\t        =    Dept. of CSE                 =");
       printf("\n\t\t\t        =    DIU                          =");
       printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n        ADMIN LOGIN\n");
    printf("       --------------\n\n\n");
    printf("\n      Enter Username: ");
    gets(use);
    printf("\n      Enter password: ");
    gets(pass);
    if(strcmp(use,username)==0 && strcmp(pass,passcode)==0)
    {
                addStudent("Joy");
                addStudent("Sabit");
                addStudent("Dipto");
                addStudent("Rakib");
                addStudent("Jihad");
                
                establishFriendship("Joy", "Sabit");
                establishFriendship("Joy", "Dipto");
                establishFriendship("Joy", "Rakib");
                establishFriendship("Joy", "Jihad");
                establishFriendship("Sabit", "Rakib");
                establishFriendship("Dipto", "Jihad");


        displayNetwork();

        findCommonFriends("Joy", "Jihad");

        freeNetwork();

    }
    else
    {
        printf("\n       -----------Username or password incorrect----------------\n\n");
    }
   
    return 0;
}

