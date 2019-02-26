//
//	EE 4374 Assignment # 1 Argument Tokenizer
//	Author:  Jesus Garcia
//

#include <stdio.h>
#include <stdlib.h>
#include "jgarcia_argtok.h"

int find_word_start(char *word, int pos)
{
  int out = 0;
  int state = out;
  int start = 0;
  int lengthOfString = string_length(word);

  for (int i = pos; i <= lengthOfString; i++)
    if (word[i] == '\0')
    {
      start = 1;
      i = lengthOfString;
    }
    else if (word[i] == ' ' || word[i] == '\t')
      state = out;
    else if (state == out)
    {
      start = i;
      i = lengthOfString;
    }
  return start;
}

int find_word_end(char *word, int pos)
{
  int in = 1;
  int out = 0;
  int state = out;
  int end = 0;
  int word_count = 0;
  int lengthOfString = string_length(word);

  for (int i = pos; i <= lengthOfString; i++)
    if (word[i] == ' ' || word[i] == '\0' || word[i] == '\t')
    {
      if (word_count == 1)
      {
        state = out;
        end = i - 1;
        i = lengthOfString;
      }
      else
        state = out;
    }
    else if (state == out)
    {
      state = in;
      word_count++;
    }
  return end;
}

int string_length(char *word)
{
  char *numberOfCharacters = word;

  while (*word)
  {
    word++;
  }
  return word - numberOfCharacters;
}

int count_words(char *word)
{
  int in = 1;
  int out = 0;
  int state = out;
  int word_count = 0;
  int lengthOfString = string_length(word);

  for (int i = 0; i <= lengthOfString; i++)
    if (word[i] == ' ' || word[i] == '\0' || word[i] == '\t')
      state = out;
    else if (state == out)
    {
      state = in;
      word_count++;
    }
  return word_count;
}
void free_tokens(char **word)
{
  int i = 0;
  while (word[i] != NULL)
  {
    free(word[i]);
    i++;
  }
  free(word);
}

void print_tokens(char **word)
{
  int i = 0;
  while (word[i] != NULL)
  {
    printf("%s\n", word[i]);
    i++;
  }
}

char **argtok(char *word)
{
  char **tokens = NULL;
  int length = 0;
  int start = find_word_start(word, 0);
  int end = find_word_end(word, start);
  int word_count = count_words(word);
  tokens = (char **)malloc(word_count * sizeof(char *) + 1);

  for (int i = 0; i < word_count; i++)
  {
    *(tokens + i) = (char *)malloc(length * sizeof(char) + 1);
    length = end - start;
    for (int j = 0; j <= length; j++)
    {
      *(*(tokens + i) + j) = *(word + start);
      start++;
    }
    start = find_word_start(word, (end + 1));
    end = find_word_end(word, start);
  }
  tokens[word_count] = NULL;
  return tokens;
}
