//
//  TrainAndTest.c
//  MLCoursework
//
//  This is a fairly inefficient implentation that does not use any dynamic memory allocation
// because that wouldnot be safe on the DEWIS marking system
//
//  Created by Jim Smith on 06/02/2017.
//  Copyright © 2017 Jim SmithJim Smith. All rights reserved.
//


#include "TrainAndTest.h"
#include <math.h>
#include <stdlib.h>



int main(int argc, char **argv)
{
    extern int Xmain(int argc, char **argv);
    Xmain(argc,argv);
}
//declare this array as static but make it available to any function in this file
//in case we want to store the training examples  and use them later
static    double myModel[NUM_TRAINING_SAMPLES][ NUM_FEATURES];
//even if each item in the training set is from a diffferent class we know how many there are
static char myModelLabels[NUM_TRAINING_SAMPLES];

static int labelUsed[256];

static int trainingSetSize=0;

int  train( double **trainingSamples, char *trainingLabels, int numSamples, int numFeatures)
{
    int returnval = 1;
    int sample, feature;
    char thisLabel;
    int ithisLabel;
  
    
    //clean the model because C leaves whatever is in the memory
    for (sample=0; sample < NUM_TRAINING_SAMPLES; sample++)
    {
        for (feature=0; feature<NUM_FEATURES; feature++)
        {
            myModel[sample][feature] = 0.0;
        }
    }
    for (sample=0; sample<256; sample++)
    {
        labelUsed[sample] = 0;
    }
    
    //sanity checking
    if ( numFeatures > NUM_FEATURES || numSamples > NUM_TRAINING_SAMPLES) {
        fprintf(stdout,"error: called train with data set larger than spaced allocated to store it");
        returnval=0;
    }
    
    //this is a silly trivial train()_ function
    fprintf(stdout,"no ML algorithm implemented yet\n");
    
    
    //make a simple copy of the data we are being passed but don't do anything with it
    //I'm just giving you this for the sake of people less familiar with pointers etc.
    
     
     if(returnval==1) {
        //store the labels and the feature values
        trainingSetSize = numSamples;
        int index,feature;
        for (index=0; index < numSamples; index++)
        {
            myModelLabels[index] = trainingLabels[index];
            for (feature=0; feature < numFeatures; feature++)
            {
                myModel[index][feature] = trainingSamples[index][feature];
            }
            
            thisLabel = trainingLabels[index];
            ithisLabel = (int) thisLabel;
            labelUsed[ithisLabel] ++ ;
            
            
        }
        fprintf(stdout,"data stored locally \n");
    }//end else
    
    
    //now you could do whatever you like with the data
    //for example,  you could populate some rules etc.
    //you were given pseudocode in semester 1 to do this
    // you could also normalise the data to remove scaling effects if you want to use something like a MLP or kNN
    //just remember that anything that you want to acess in your predictLabel() function
    //needs to be declared static at the top of this file - as I have done for the "myModel"  and myModelLabels data .
    
    
    
    return returnval;
}


/* this is a really trivial classifier that just returns any valid label.
 So it assumes that the features are all irrelevant,
 and even ignores  the relative frequency that values occur in training
 */
char  predictLabel(double *sample, int numFeatures)
{
    
    char prediction= (char)NULL;
    int  choice, validChoiceMade=0;
    
    while (validChoiceMade == 0)
    {
        choice = rand() %256;
        if ( labelUsed[choice] >0 )
        {
            prediction = (char) choice;
            validChoiceMade = 1;
            
        }
    }
    return prediction;
    
}


