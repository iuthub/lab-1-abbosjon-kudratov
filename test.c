//
//  main.c
//  Ticket
//
//  Created by botirjon nasridinov on 19/12/2018.
//  Copyright © 2018 Orient Software Team. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct Match {
    int id;
    int stadium_id;
    char * stadium_name;
} Match;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Match match;
    match.id = 12;
    match.stadium_id = 23;
    match.stadium_name = "Maracano";
    
    printf("%lu\n", strlen(match.stadium_name));

    char * buffer;
    buffer = (char *) malloc(2 * sizeof(int) + strlen(match.stadium_name) + 1);
    memcpy(buffer, &match.id, sizeof(int));
    memcpy(&buffer[sizeof(int)], &match.stadium_id, sizeof(int));
    memcpy(&buffer[2 * sizeof(int)], match.stadium_name, strlen(match.stadium_name) + 1);
    
    int * id = (int*)malloc(sizeof(int));
    memcpy(id, buffer, sizeof(int));
    
    int * stadium_id = (int*)malloc(sizeof(int));
    memcpy(stadium_id, buffer + sizeof(int), sizeof(int));
    
    char * stadium_name = (char*)malloc(strlen(match.stadium_name) + 1);
    memcpy(stadium_id, buffer + 2 * sizeof(int), strlen(match.stadium_name) + 1);
    
    printf("id=%d\nstadium_id=%d\nstadium_name=%s\n", *id, *stadium_id, stadium_name);
    
    return 0;
}