#include <iostream>
#include "TransmitMessage.h"
#include <string.h>

using namespace TransmitMessage;

int main() {

    bool done = false;
    TransmitMessage::TransmitMessageGenerate *T2 = new TransmitMessageGenerate();
    TransmitMessage::TransmitMessageCheck *T = new TransmitMessageCheck();
    char *buf = T2->MakeBuf();
    char *seq = T2->GenerateTransmitMessage(5000+rand()%5000);
    int hops = 0;
    std::cout << strlen(seq) << std::endl;
    while(!done) {


        bool res =  T->CheckMessageTransmission(seq, buf);
        std::cout << res << std::endl;
        //std::cout << buf << std::endl;
        std::cout << strlen(buf) << std::endl;
        strcpy(seq, buf);


        if(!res){
            done=true;
        }
        else{
            hops++;
        }
        delete T;
        T = new TransmitMessageCheck();
    }
    free(buf);
    free(seq);
    delete T2;

    std::cout << hops << std::endl;
    return 0;
}