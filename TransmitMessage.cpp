//
// Created by tripa on 06/01/17.
//
#include "TransmitMessage.h"

TransmitMessage::TransmitMessageCheck::TransmitMessageCheck(){
    this->init(DEFAULT_PRIMER_SEQUENCE_LENGTH);
}

TransmitMessage::TransmitMessageCheck::TransmitMessageCheck(int p){
    this->init(p);
}

void TransmitMessage::TransmitMessageCheck::init(int p){
    this->primer_sequence_forward = (char*)calloc(sizeof(char), p+1);
    this->primer_sequence_reverse = (char*)calloc(sizeof(char), p+1);
    this->primer_sequence_length = p;
    srand((unsigned)time(0));
    for(int i = 0; i < this->primer_sequence_length; i++){
        this->primer_sequence_forward[i] = rand()%4+65;
        this->primer_sequence_reverse[i] = rand()%4+65;
    }
}

TransmitMessage::TransmitMessageCheck::~TransmitMessageCheck(){
    if(this->primer_sequence_forward != NULL){
        free(this->primer_sequence_forward);
        this->primer_sequence_forward = NULL;
    }

    if(this->primer_sequence_reverse != NULL){
        free(this->primer_sequence_reverse);
        this->primer_sequence_reverse = NULL;
    }
}

bool TransmitMessage::TransmitMessageCheck::CheckMessageTransmission(char* curSequence, char *nextSequence) {
    int string_length = 0;
    if(curSequence != NULL){
        for (int i = 0; i < MAX_MESSAGE_LENGTH; i++){
            if(curSequence[i] != 0){
                string_length++;
            }
            else{
                break;
            }
        }
        //We got the sequence length
        //Now we have to find out if there is an amplicon and what's the longest amplicon length
        //Keeping things simple here
        //Chris-Morris-Pratt it later
        int start = 0;
        int end = string_length - 1;
        for( ;start < string_length - this->primer_sequence_length; start++){
            if (this->MatchStrings(this->primer_sequence_forward, curSequence+start,this->primer_sequence_length, string_length-start)){
                break;
            }
        }

        for(;end >=this->primer_sequence_length - 1; end--){
            if (this->MatchStrings(this->primer_sequence_reverse, curSequence+end-this->primer_sequence_length, this->primer_sequence_length, string_length-end - 1 + this->primer_sequence_length)){
                break;
            }
        }

        if(start < end && (end-start) >= MIN_AMPLICON_LENGTH){
            if(nextSequence != NULL){
                int i = start;
                for(; i < end; i++){
                    nextSequence[i - start] = curSequence[i];
                }
                nextSequence[i - start] = 0;
            }
            return true;
        }
    }
    return false;
}

bool TransmitMessage::TransmitMessageCheck::MatchStrings(char *query, char *string_to_search, int query_length,
                                                         int string_length) {
    if(string_length < query_length){
        return false;
    }

    for(int i = 0; i < query_length; i++){
        if(query[i] != string_to_search[i]){
            return false;
        }
    }

    return true;
}

TransmitMessage::TransmitMessageGenerate::TransmitMessageGenerate() {

}

TransmitMessage::TransmitMessageGenerate::~TransmitMessageGenerate() {

}

char* TransmitMessage::TransmitMessageGenerate::GenerateTransmitMessage(int length) {
    srand((unsigned)time(0));
    char* outbuf = (char*)calloc(sizeof(char), MAX_MESSAGE_LENGTH+1);
    for(int i = 0; i < length && i < MAX_MESSAGE_LENGTH; i++){
        outbuf[i] = rand()%4+65;
    }
    return outbuf;
}

char* TransmitMessage::TransmitMessageGenerate::MakeBuf() {
    char* outbuf = (char*)calloc(sizeof(char), MAX_MESSAGE_LENGTH+1);
    return outbuf;
}