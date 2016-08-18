//
//  main.c
//  MultiTables
//
//  Created by rubenrap on 8/18/16.
//  Copyright © 2016 rubenrap. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    const int LIMIT = 12;
    const int MAX_LEN = 4;

    for(int i=1; i<=LIMIT; i++){
        for(int k=1, prod=0; k<=LIMIT; k++){
            prod = i * k;
            
            int cdecim = 1, spaces=0;
            for(int prodiv = prod; prodiv / 10 != 0; prodiv = prodiv / 10, cdecim++);
            
            spaces = MAX_LEN - cdecim;
            for(int k=0; k<spaces; k++)
                printf(" ");
            printf("%d", prod);
            
            if(k == LIMIT)
                printf("\n");
        }
    }
     
    return 0;
}
