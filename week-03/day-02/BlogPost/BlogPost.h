

//
// Created by bolar on 2019. 01. 29..
//
#include <iostream>
#ifndef BLOGPOST_BLOGPOST_H
#define BLOGPOST_BLOGPOST_H


class BlogPost {
std::string authorName;
std::string title;
std::string text;
std::string publicationDate;

public:
    BlogPost(std::string an, std::string ti, std::string te, std::string pd);
};



#endif //BLOGPOST_BLOGPOST_H
