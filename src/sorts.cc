#include <iostream>
#include<ctime>


void insertion_sort(int* array, int length)
{
  for(int i = 1; i < length; i++)
  {
    int key = array[i];
    int j = i-1;

    while(j >= 0 && array[j] > key)
    {
      // push to the right
      array[j+1] = array[j];

      // advance
      j--;
    }

    // insert key into correct position of the sorted portion
    array[j+1] = key; 

  }
}

void heapify(int* array, int length, int position)
{
  int index = position;
  int value = array[position];

  // exit recursion if leaf node
  if(index > (length/2) + 1)
  {
    return;
  }

  int lci = position*2 + 1;
  int rci = position*2 + 2;

   if(rci < length) // must consider both children
   {
     int lcv = array[lci];
     int rcv = array[rci];

     // find greater of the two children
     int gci = lci;
     if(lcv < rcv) 
     {
       gci = rci;
     }      
     int gcv = array[gci];

   // check if we need to swap with the greater child
   if(gcv > value)
   {
     // swap and recursively reheapify at child
     std::swap(array[index], array[gci]);
     heapify(array, length, gci);
   }
  }
  else if (lci < length) // must only consider left child
  {
    int lcv = array[lci];

    // check if we need to swap with the single child
    if(lcv > value)
    {
      // swap and recursively reheapify at child
      std::swap(array[index], array[lci]);
      heapify(array, length, lci);
    }
  }
  
}

void heap_sort(int* array, int length)
{
  /*
  Determining the first non-leaf node based on length

          0
       1     2
      3 4   5 6 

  len 7 -> start 2
  len 6 -> start 2
  len 5 -> start 1
  len 4 -> start 1
  len 3 -> start 0
  len 2 -> start 0
   
  therefore first non-leaf is at (int)(length/2) - 1
  */

  // O(n log n)
  // build max heap
  for(int i = length/2 - 1; i >= 0; i--)
  {
    heapify(array, length, i);
  }

  // O(n log n)
  // add top of heap to sorted portion at end and reheapify
  for(int i = length - 1; i > 0; i--)
  {
    std::swap(array[0], array[i]);
    heapify(array, i, 0);
  }
}

void print_array (int* array, int length)
{
  for(int i = 0; i < length; i++)
  {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl; 
} 

int main()
{
  srand(time(0));
  
  int length = 20;

  // inclusive
  int lower_lim = 100;
  int upper_lim = -100;
  
  // initialize source array
  int* source_array = new int[length];
  for(int i = 0; i < length; i++)
  {
    source_array[i] = rand() % (upper_lim - lower_lim + 1) - lower_lim;
  }

  // allocate memory array to be sorted
  int* array = new int[length];

  // insertion sort
  std::cout << "\ntesting insertion sort" << std::endl;
  memcpy(array, source_array, length*sizeof(int));
  print_array(array, length);
  insertion_sort(array, length);
  print_array(array, length);


  // heap sort
  std::cout << "\ntesting heap sort" << std::endl;
  memcpy(array, source_array, length*sizeof(int));
  print_array(array, length);
  heap_sort(array, length);
  print_array(array, length);

  // free memory
  delete [] source_array;
  delete [] array; 

  return 0;
}