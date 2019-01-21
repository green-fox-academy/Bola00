#include <iostream>
#include <string>

int main(int argc, char* args[])
{
    std::string url("https//www.reddit.com/r/nevertellmethebots");

    // Accidentally I got the wrong URL for a funny subreddit. It's probably "odds" and not "bots"
    // Also, the URL is missing a crucial component, find out what it is and insert it too!


    // it changes "//" to "://"
    std::string froma = "//";
    int start_pos1 = url.find(froma);
    url = url.replace(start_pos1, froma.length(), "://");


    std::string from = "bots";
    int start_pos2 = url.find(from);
    if(start_pos2 == std::string::npos)//check that from is even in the sentence
        std::cout << "Cannot replace" << std::endl;
    else{
        url.replace(start_pos2, from.length(), "odds");}
    //url.replace (the starting index, the long of the replace, the new string part)



    std::cout << url << std::endl;

    return 0;
}