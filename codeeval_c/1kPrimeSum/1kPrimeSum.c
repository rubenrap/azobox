//
//  1kPrimeSum.c
//  codeeval_c
//
//  Created by rubenrap on 8/17/16.
//  Copyright © 2016 rubenrap. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]){
    int sum = 2;
    int factors[999];
    int n=3, fac_index=0;
    factors[0]=2;
    
    while(fac_index < 999){ //1000
        int max_factor = (int) round(sqrt(n));
        
        printf("%d - Factors (max - %d): \n", n, max_factor);
        for(int index=0; index <= fac_index; index++){
            printf("#%d \n", factors[index]);
            
            if(index == fac_index || factors[index] > max_factor){
                sum += n; //add prime
                factors[fac_index+1] = n;
                
                
                //check factors
                //for(int i=0; i<=fac_index; i++)
                //    printf("%d, ", factors[i]);
                //printf("\n");
                
                fac_index++;
                break;
            }
            
            if(n % factors[index] != 0)
                continue;
            else
                break; //not prime
        }
        n++;
    }
    
    printf("total sum: %d", sum);
}

