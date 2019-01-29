#include <iostream>
#include "BlogPost.h"

//Create a BlogPost class that has
//an authorName
//a title
//a text
//a publicationDate
//Create a few blog post objects:
//"Lorem Ipsum" titled by John Doe posted at "2000.05.04."
//Lorem ipsum dolor sit amet.
//"Wait but why" titled by Tim Urban posted at "2010.10.10."
//A popular long-form, stick-figure-illustrated blog about almost everything.
//"One Engineer Is Trying to Get IBM to Reckon With Trump" titled by William Turton at "2017.03.28."
//Daniel Hanley, a cybersecurity engineer at IBM, doesn’t want to be the center of attention.
// When I asked to take his picture outside one of IBM’s New York City offices, he told me that he wasn’t really into
// the whole organizer profile thing.

int main() {
    //BlogPost::BlogPost (std::string an, std::string ti, std::string te, std::string pd)
    BlogPost blog_one ("John Doe", "Loren Ipsum", "Lorem ipsum dolor sit amet.", "2000.05.04.");
    BlogPost blog_two ("Tim Urban", "Wait but why", "A popular long-form, stick-figure-illustrated blog about almost everything.", "2010.10.10.");
    BlogPost blog_three ("William Turton","One Engineer Is Trying to Get IBM to Reckon With Trump",
            "Daniel Hanley, a cybersecurity engineer at IBM, doesn’t want to be the center of attention."
            "When I asked to take his picture outside one of IBM’s New York City offices, "
            "he told me that he wasn’t really into the whole organizer profile thing.","2010.10.10."  );
    return 0;
}