#include "chifr.h"
#include <iostream>
#include <string>

using namespace std;

string chifr::encrypt(string in, const int kluch)
{
    int array_size = in.length();
    int array_height = (array_size/kluch) + ((array_size%kluch > 0) ? 1 : 0);
    int lower_string_lenght = in.length()%kluch;
    int zv = (lower_string_lenght > 0) ? kluch - lower_string_lenght : 0;

    char ** matr= new char*[array_height];
    for (int i =0; i<array_height; i++) matr[i] = new char[kluch];

    string output;

    for (int i = 0; i <zv; i++) {
        matr[array_height-1][(kluch-1)-i] = '*';
    }
    int charId = 0;
    for (int i = 0; i < array_height; i++) {
        for (int j = 0; j < kluch; j++) {
            if (matr[i][j] == '*') continue;

            matr[i][j] = in.at(charId);
            charId++;
        }
    }


    for (int i = 0; i < kluch; i++) {
        for (int j = 0; j < array_height; j++) {
            if (matr[j][(kluch-1)-i] == '*') continue;
            output+=matr[j][(kluch-1)-i];
        }
    }
    for (int i = 0; i < array_height; i++) {
        delete[] matr[i];
    }
    delete[] matr;
    return output;
}
string chifr::decrypt(string in, const int kluch)
{
    int array_height = (in.length()/kluch) + ((in.length()%kluch > 0) ? 1 : 0);
    int lower_string_lenght = in.length()%kluch;
    int zv = (lower_string_lenght > 0) ? kluch - lower_string_lenght : 0;

    char ** matrix = new char*[array_height];
    for (int i =0; i<array_height; i++) matrix[i] = new char[kluch];

    string output;

    for (int i = 0; i < array_height; i++) {
        for (int j = 0; j < kluch; j++) {
            matrix[i][j] = '\0';
        }
    }
    for (int i = 0; i< zvezdi; i++) {
        matrix[array_height-1][(kluch-1)-i] = '*';
    }
    int charId = 0;
    for (int i = 0; i < kluch; i++) {
        for (int j = 0; j < array_height; j++) {
            if (matrix[j][(kluch-1)-i] == '*') continue;

            matrix[j][(kluch-1)-i] = in.at(charId);
            charId++;
        }
    }
    for (int i = 0; i < in.length(); i++) {
        int y = i/kluch;
        int x = (i%kluch);

        char c = matrix[y][x];

        if (c != '\0') {
            output+=c;
        }
    }
    for (int i = 0; i < array_height; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return output;
}
