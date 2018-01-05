int genFormula(atom *pAtom,int **output,int *size);

int genFormula(atom *pAtom,int **output,int *size){
  
  int tracker = 0;
  int counter = 0;
  int found = 0;
  int speciesNumber = 0;
  int* species;
  int* sortedSpecies;
  atom *temp;
  atom *temp1;
  int tempCounter = 1;
  bondNode * bonder = NULL;
  int totalAtoms = 0;
  int j;
  int i;
  int x;
  temp1 = pAtom;
  temp = pAtom;
  
  
  /*find the number of species*/
  
  
  
  while (temp1!= NULL){
  
    while (temp1 != NULL){

    
    printf("Atomic Num=%d\n",temp1->atomicNumber);
    totalAtoms ++;
    /*species[counter] = temp1 -> atomicNumber;*/
    
    if(temp1->bondList == NULL){
      
      break;
    }
    
    temp1 = temp1->bondList->pAtom;
 
    counter++;
    
    }
    
  printf("Reached the end of this bondlist\n");
  
  temp1 = temp;
  bonder = temp1->bondList;
  
  
  
  for (x = 0; x < tempCounter; x++)
  {
  bonder = bonder->pNext;
  }
  
  if (bonder == NULL){
    
    break;
  }

  temp1 = bonder->pAtom;
  
  
  tempCounter = tempCounter + 1;
  }
  
  
/*we can now malloc the tasty array*/
printf("\nTotal atoms: %d\n",totalAtoms);
species = (int*)malloc(sizeof(int)*totalAtoms);


/*we can now assign values to the tasty array*/

  tracker = 0;
  counter = 0;
  found = 0;
  speciesNumber = 0;
  
  temp1 = pAtom;
  temp = pAtom;
  tempCounter = 1;
  bonder = NULL;
  
printf ("\nBegin assigning\n\r");
while (temp1!= NULL){
  
    while (temp1 != NULL){

    species[counter] = temp1 -> atomicNumber;
    printf("Atomic Num=%d\n",temp1->atomicNumber);
   
    
    
    if(temp1->bondList == NULL){
      
      break;
    }
    
    temp1 = temp1->bondList->pAtom;
 
    counter++;
    
    }
    
    counter++;

  
  temp1 = temp;
  bonder = temp1->bondList;
  
  
  
  for (x = 0; x < tempCounter; x++)
  {
  bonder = bonder->pNext;
  }
  
  if (bonder == NULL){
    
    break;
  }

  temp1 = bonder->pAtom;
  
  
  tempCounter = tempCounter + 1;
  }



/*test print the array*/

for ( x = 0; x < totalAtoms; x++){
  printf("\rAll atoms: %d\n",species[x]);
}


/*get the total number of unique elements*/

   for(i = 0; i < totalAtoms; i++) {
     
    for (j =0; j<i; j++){
      
      if (species[i] == species[j])
       break;
       }
      
     if (i == j){
      /*spooky duplicate*/
      printf("Unique found: %d\n ", species[i]);
      speciesNumber ++;
      
  }
 }
  
  /*this is the total number of unique atoms*/
  printf("\rTotal Unique Atoms: %d\n\r",speciesNumber);




 
/*malloc the output array*/
(*output) = (int *)malloc(sizeof(int)*speciesNumber*2);
sortedSpecies = (int*)malloc(sizeof(int)*speciesNumber);


/*put the unique elements into the output array*/
counter = 0;

for(i = 0; i < totalAtoms; i++) {
     
    for (j =0; j<i; j++){
      
      if (species[i] == species[j])
       break;
       }
      
     if (i == j){
      /*spooky duplicate*/
      printf("Unique found: %d\n ", species[i]);
      sortedSpecies[counter] = species[i];
      counter = counter + 1;
      
  }
 }
 
 for (x = 0; x<speciesNumber; x++){
  printf("%d\n",sortedSpecies[x]);
}



 /*bubble sort the tasty*/
 /*already sorted*/
  if (speciesNumber == 1){
   return 0; 
  }
  
  
  for (i = 0; i < (speciesNumber-1); i++){
    
    for (j = 0; j < (speciesNumber-1-i); j++){
      if (sortedSpecies [j] > sortedSpecies[j+1]){
       tracker = sortedSpecies[j];
        sortedSpecies[j] = sortedSpecies[j+1];
        sortedSpecies[j+1] = tracker;
      }
    }
  }
  
  
  
for (x = 0; x < speciesNumber; x++){
  printf("Sorted: %d\n",sortedSpecies[x]);
}
  
  /*shift all the elements so that its staggered by empty spots*/
  for (i = 0; i < speciesNumber;i++)
  {
    
    (*output)[i*2] = sortedSpecies[i];

  }
  
for (x = 0; x < speciesNumber*2; x++){
  printf("Output: %d\n",(*output)[x]);
}

counter = 0;


/*count up how many of each atom there are and input*/
for (i = 0; i<speciesNumber*2; i = i+2)
{
 printf("Testing for: %d\r",(*output)[i]);
 
  for (j = 0; j<totalAtoms; j=j+1)
  {

  if (species[j] == (*output)[i]){
    printf("Found a match. Adding.\n");
    counter = counter + 1;
  }
  
  }
  
   (*output)[i+1] = counter;
  counter = 0;
}



for (x = 0; x < speciesNumber*2; x++){
  printf("Final output: %d\n",(*output)[x]);
}

*size = speciesNumber*2;
printf("Size of output array: %d\n",*size);

free(species);
  free(sortedSpecies);

    return 0;
  
}
