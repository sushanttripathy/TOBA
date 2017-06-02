//
// Created by tripa on 06/01/17.
//

#ifndef SIMULATIONSANDTECHNIQUES_TRANSMITMESSAGECHECK_H
#define SIMULATIONSANDTECHNIQUES_TRANSMITMESSAGECHECK_H

#include <stdlib.h>
#include <ctime>
namespace TransmitMessage {
#define DEFAULT_PRIMER_SEQUENCE_LENGTH 5
#define MAX_MESSAGE_LENGTH 10000
#define MIN_AMPLICON_LENGTH 20

    class TransmitMessageCheck {
    public:
        TransmitMessageCheck();

        TransmitMessageCheck(int primer_sequence_length);

        ~TransmitMessageCheck();

        bool CheckMessageTransmission(char*curSequence, char *nextSequence);

        bool MatchStrings(char* query, char* string_to_search, int query_length, int string_length);


    protected:
        char *primer_sequence_forward, *primer_sequence_reverse;
        int primer_sequence_length;
    private:
        void init(int primer_sequence_length);
    };

    class TransmitMessageGenerate{
    public:
        TransmitMessageGenerate();
        ~TransmitMessageGenerate();
        char* GenerateTransmitMessage(int length);
        char* MakeBuf();
    };
};
#endif //SIMULATIONSANDTECHNIQUES_TRANSMITMESSAGECHECK_H
