#include "jgarcia_argtok.h"
#include <stdio.h>
#include <stdlib.h>

int string_length(char * word){
    int count =0;
    while((*word++) != '\0'){
        count++;
    }
    return count;
}
/*
    reject all caps and numbers
 */
char is_valid_character(char c){
    if(c >=0 && c<=64  || c >= 91 && c <= 96 || c >=123 && c<=127){
        return 0;
    }
    else{
        return 1;
    }
}
/*
    needs debugging
    word start is suppose to go 
    to the next word
 */
int find_word_start(char * word, int pos){
    while(*word){
        if(is_valid_character(word[pos])==1 && is_valid_character(word[pos-1]) ==1){
            pos= pos -1;
        }
        else if(is_valid_character(word[pos]) == 1 && is_valid_character(word[pos-1] == 0 )){
            pos=pos-1;
        }
        else if(is_valid_character(word[pos]) ==1 && is_valid_character(word[pos-1] ==1)){
            pos =  pos -1;
        }
        else if (is_valid_character(word[pos]) == 0 && is_valid_character(word[pos+1]) ==1){
            pos = pos + 1;//
        }
        else if(is_valid_character(word[pos]) == 0 && is_valid_character(word[pos+1]) == 0){
            pos =pos+1;
        }
        else{
            return pos;
        }
    }
    return pos;
}
/*
    DEBUGGing : 
*/
int find_word_end(char * word, int pos){
    while(*word){
        if(is_valid_character(word[pos]) == 1 && is_valid_character(word[pos+1]) == 1 ) {
            pos = pos +1;
        }
        else if( is_valid_character(word[pos]) == 1 && is_valid_character(word[pos+1]) == 0){
            return pos;//
        }
        else if( is_valid_character(word[pos] ==0 ) && is_valid_character(word[pos-1]) == 1){
            pos=pos-1;
        }
        else if( is_valid_character(word[pos]) == 0 && is_valid_character(word[pos+1]) == 1){
            pos = pos +1;
        }
        else if(is_valid_character(word[pos]) ==0 && is_valid_character(word[pos+1]) == 0){
            pos= pos + 1;
        }
        else{
            return pos;
        }
    }

    return pos;
}

int count_words(char * word){
    int count = 0;
    int pos =0;


    while(word[pos+1]  != '\0'){
        if(word[pos] !=' ' && word[pos+1] == ' ' ){
            count = count+1;
        }
        else if( word[pos+1] =='\0' && word[pos] == ' '){
            count--;
        }
        pos++;
    }
    return count+1 ;
}

void print_tokens(char ** word){
    int i =0;
    while(word[i] != NULL){
        printf("%s\n",word[i]);
        i++;
    }
}

void free_tokens(char ** word){
    int i =0;
    while(word[i] != NULL)  {
        free(word[i]);
        i++;
    }
    free(word);

}
char ** argtok(char * words){
    char ** token = NULL;
    int start = find_word_start(words,0);
    int end = find_word_end(words,start);
    int w_count = count_words(words);
    int temp = end - start;

    token = ((char ** ) malloc(sizeof(char*) * (w_count + 1))); //rows
    for(int i = 0; i < w_count ; i++){
        *(token + i) = (char*) malloc(sizeof(char) * (temp+1)); //coloms
        temp = end - start;
        for(int j = 0;  j <= temp+1; j++){ //
            *(*(token+i)+j) = *(words + (start)); //copying
            start++;
        }

        start = find_word_start(words, end+1);
        end = find_word_end(words,start); 
    }
    token[count_words(words)+1] = '\0';

    return token;
}
