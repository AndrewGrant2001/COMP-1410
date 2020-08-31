#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    srand(time(0));
    
    char *article[] = {"the", "a", "one", "some", "any"}; //declaring the articles
    char *noun[] = {"boy", "girl", "dog", "town", "car"}; //declaring the nouns
    char *verb[] = {"drove", "jumped", "ran", "walked", "skipped"}; //declaring the verbs
    char *preposition[] = {"to", "from", "over", "under", "on"}; //declaring the prepositions
    
    int sentences = (rand() % 8) + 3;//creates short story with 3-10 sentences
    int counter = 0;//creating counter for new line outputting
    
    do{
        char sentence[100] = ""; //creating array to store sentence/story
        counter++;//increment counter by one.
        
        strcat(sentence, article[rand() % 5]); //selecting random artice
        strcat(sentence, " "); //adding space
        
        sentence[0] = toupper(sentence[0]); //making first character upper case
        
        strcat(sentence, noun[rand() % 5]); //selecting random noun
        strcat(sentence, " "); //adding space
    
        strcat(sentence, verb[rand() % 5]); //selecting random verb
        strcat(sentence, " "); //adding space
        
        strcat(sentence, preposition[rand() % 5]); //selecting random preposition
        strcat(sentence, " "); //adding space
        
        strcat(sentence, article[rand() % 5]); //selecting random article
        strcat(sentence, " "); //adding space
        
        strcat(sentence, noun[rand() % 5]); //selecting random noun
        strcat(sentence, ". "); //adding space
        
        printf("%s", sentence); //outputting sentence/story
        
        //after every 2 sentences go to next line
        if ((counter % 2) == 0){
            puts("");
        }
        
        sentences--;//decrementing sentences remaining
    } while(sentences > 0);
}


