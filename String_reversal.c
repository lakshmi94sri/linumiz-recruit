#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE1 200

struct link{
    char ele;
    struct link *next;
};

struct link* next_node(char element){
    struct link *node=(struct link *)malloc(sizeof(struct link));
    node->ele=element;
    node->next=NULL;
    return node;
}

int checkEmpty(struct link *node){
    return node==NULL;
}
void createnode(struct link **node, char element){
    struct link *temp=next_node(element);
    temp->next=*node;
    *node=temp;
}

char deletenode(struct link **node){
    if(checkEmpty(*node)){
        return 'a';
    }
    struct link *temp=*node;
    *node=(*node)->next;
    free(temp);
}

void rev(char str[])
{
    int i=0,j;
   	 j = strlen(str) - 1;
   
	while (i < j) {
      char tempChar = str[i];
      str[i] = str[j];
      str[j] = tempChar;
      i++;
      j--;
   }
    printf("Reverse string is: %s\n", str);
}
int main()
{
    char string[SIZE1], op[1];
    
        printf("Enter the string to be reversed: ");
        gets(string);
        rev(string);
		return(0);
        
}