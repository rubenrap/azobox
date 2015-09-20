//
//  stringMask.c
//
//  Created by rubenrap on 9/20/15.
//  Copyright (c) 2015 rubenrap. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE 128   //1024
#define WS " \n"
#define UPPERCASE 1

int main(int argc, const char * argv[]) {
   
    FILE *fp;
    char *word, *mask, *line;
    int word_size, acode, mcode, aflag_upper;
    
    fp = fopen(argv[1], "r");
    line = (char*) malloc(sizeof(char) * LINE);
    
    while(fgets(line, LINE, fp) != NULL)
    {
        word = strtok(line, WS);
        word_size = (int) strlen(word);
        mask = strtok(NULL, WS);
        
        if(word_size != strlen(mask))
            return -1;
        
        aflag_upper = 0;
        for(int i = 0; i < word_size; i++)
        {
            acode = *(word+i);
            if(acode > 64 && acode < 91)
                aflag_upper = 1;
            
            mcode = ((int) *(mask+i)) - 48;
            if(mcode != aflag_upper)
                
                if(mcode == UPPERCASE)
                    printf("%c", (acode - 32));
                else
                    printf("%c", (acode + 32));
            
            else
                printf("%c", *(word+i));
        }
        printf("\n");
    }
    
    free(line);
    fclose(fp);
    
    return 0;
}


