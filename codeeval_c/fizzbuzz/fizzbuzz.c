//
//  fizzbuzz.c
//
//  Created by rubenrap on 8/25/15.
//  Copyright (c) 2015 rubenrap. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    FILE *fp;
    char *input_str, *input_arg;
    int buffer[3];
    input_str = (char*) malloc(sizeof(char) * 100);
    
    fp = fopen(argv[1], "r");
    
    while(fgets(input_str, 10, fp) != NULL){
        
        input_arg = (char*) malloc(sizeof(char) * 10);
        int ref = 0;
        
        input_arg = strtok(input_str, " ");
        while (input_arg != NULL)
        {
            buffer[ref] = atoi(input_arg);
            input_arg = strtok (NULL, " ");
            ref++;
        }
        
        free(input_arg);
        for(int i=1; i<=buffer[2];i++){
        
            if((i % buffer[0] != 0) && (i % buffer[1] != 0))
            
                printf("%d", i);
            
            else{
            
                if(i % buffer[0] == 0)
                    printf("F");
            
                if(i % buffer[1] == 0)
                    printf("B");
            }
            printf(" ");
        }
        printf("\n");
    }
    
    free(input_str);
    fclose(fp);
    return 0;
}
