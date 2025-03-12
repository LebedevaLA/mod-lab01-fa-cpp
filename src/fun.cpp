// Copyright 2022 UNN-IASR
#include <cstring>
#include <cmath>
#include "fun.h"

bool is_letter_up(char a) {
    if ('A' <= a && a <= 'Z') {
      return true;
    }
    return false;
  }

  bool is_letter_down(char a) {
    if ('a' <= a && a <= 'z') {
      return true;
    }
    return false;
  }

  bool is_number(char a) {
    if ('0' <= a && a <= '9') {
      return true;
    }
    return false;
  }

unsigned int faStr1(const char *str) {
    if (strlen(str) == 0) {
      return 0;
    }
    int counter = 0;
    char last = str[0];
    int i = 1;
    bool good;
    if (is_number(last)) {
      good = false;
    } else {
      good = true;
    }
    while (i < strlen(str)) {
      if (last != ' ' && str[i] == ' ') {
        if (good) {
          counter++;
        }
        good = true;
      } else {
        if (is_number(str[i])) {
          good = false;
        }
      }
      last = str[i];
      i++;
    }
    if (good && last != ' ' && !is_number(last)) {
      counter++;
    }
    return counter;
}
unsigned int faStr2(const char *str) {
    if (strlen(str) == 0) {
      return 0;
    }
    char last = str[0];
    if (strlen(str) == 1) {
      if (is_letter_up(last)) {
        return 1;
      }
      return 0;
    }
    int i = 1;
    bool good;
    int counter = 0;
    if (last == ' ' || is_letter_up(last)) {
      good = true;
    } else {
      good = false;
    }
    while (i < strlen(str)) {
      if (str[i] == ' ') {
        if (last != ' ' && good) {
          counter++;
        }
        good = true;
      } else {
        if ((last == ' ' && !is_letter_up(str[i])) ||
        (last != ' ' && !is_letter_down(str[i]))) {
          good = false;
        }
      }
      last = str[i];
      i++;
    }
    if ((str[i - 2] == ' ' && is_letter_up(last)) ||
    (str[i - 2] != ' ' && good && is_letter_down(last))) {
      counter++;
    }
    return counter;
}

unsigned int faStr3(const char *str) {
    if (strlen(str) == 0) {
      return 0;
    }
    int counter = 0;
    int letter = 0;
    char last = str[0];
    if (last != ' ') {
      letter++;
    }
    int i = 1;
    while (i < strlen(str)) {
      if (str[i] != ' ') {
        letter++;
      }
      if (last != ' ' && str[i] == ' ') {
        counter++;
      }
      last = str[i];
      i++;
    }
    if (last != ' ') {
      counter++;
    }
    if (counter == 0) {
      return 0;
    }
    return round(letter / counter);
}
