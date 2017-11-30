#include<iostream>
#include<string>
#include<vector>

using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~ assertions ~~~~~~~~~~~~~~~
void assertTrue(string testName, string query, bool statement) {
  cout << testName << ": " << query << ": expect true: " << (statement ? "SUCCESS" : "FAIL") << endl;
}

void assertFalse(string testName, string query, bool statement) {
  cout << testName << ": " << query << ": expect false: " << (statement ? "FAIL" : "SUCCESS") << endl;
}

void assertEquals(string testName, string query, int a, int b) {
  cout << testName << ": " << query << ": expect equals: " << (a == b ? "SUCCESS" : "FAIL") << endl;
}

void assertEquals(string testName, string query, unsigned int a, unsigned int b) {
  cout << testName << ": " << query << ": expect equals: " << (a == b ? "SUCCESS" : "FAIL") << endl;
}

void assertEquals(string testName, string query, string a, string b) {
  cout << testName << ": " << query << ": expect equals: " << (a == b ? "SUCCESS" : "FAIL") << endl;
}

void assertEquals(string testName, string query, char a, char b) {
  cout << testName << ": " << query << ": expect equals: " << (a == b ? "SUCCESS" : "FAIL") << endl;
}

template <typename Exp>
void expectExp(string testName, string query, Exp e) {
  cout << testName << ": " << query << ": caught (" << e.what() << "): SUCCESS" << endl;
}

void assertFail(string testName, string query) {
  cout << testName << ": " << query << ": " << "FAIL" << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void printVec(vector<int> &a);
void printArr(int arr[], int n);
int SIZE = 0;

/**
 * Has GLOBAL sorted subarray
 * Has best case, avg case and worst case n^2
 */
void selectionSort(int* arr, int size) {
  int smallest = 0;
  int temp = 0;

  for(int i = 0; i < size; i++) {
    smallest = i;

    for(int k = i; k < size; k++) {

      if(arr[smallest] > arr[k])
        smallest = k;

    }

    temp          = arr[i];
    arr[i]        = arr[smallest];
    arr[smallest] = temp;
  }
}

/**
 * Has LOCAL sorted subarray
 * Has best case, avg case and worst case n^2
 */
void insertionSort(int* arr, int size) {
  int temp;
  int k;

  for(int i = 1; i < size; i++) {
    temp = arr[i];
    k    = i;

    while(k > 0 && arr[k-1] > temp) {
      arr[k] = arr[k-1];
      k--;
    }

    arr[k] = temp;
  }
}

void bubblesort(int* arr, int size) {
  int temp;
  bool swapped;
  int j = 1;

  do {
    swapped = false;
    for(int i = 0; i < size - j; i++) {
      if(arr[i] > arr[i + 1]) {
        temp = arr[i + 1];
        arr[i + 1] = arr[i];
        arr[i] = temp;
        swapped = true;
      }
    }

    j++;
  } while(swapped);
}

void divySort(vector<int> &a) {
  printVec(a);

  int n = a.size();
  int count = 0;
  for(int i = n/2; i > 0; i = i/2) {
    for(int j = i; j < n; j++) {
      for(int k = j; (k-i) >= 0; k = k - i) {
        if(a[k] < a[k-i]) {
          swap(a[k], a[k-i]);
          printVec(a);
        }
        //cout << "C loop end" << endl;
      }
      //cout << "B loop end" << endl;
    }
    //cout << "A loop end" << endl;
  }
}

void merge(int arr[], int begin, int middle, int end) {
  int cpArr[end];
  int i = begin;
  int j = middle;

  // sort original array into new array
  for(int k = begin; k < end; k++) {
    if( i < middle ) {
      if(j == end || arr[i] < arr[j]) {
        cpArr[k] = arr[i];
        i++;
      } else { 
        // j < end && arr[i] >= arr[j]
        cpArr[k] = arr[j];
        j++;
      }
    } else { // i == middle
      cpArr[k] = arr[j];
      j++;
    }
  }

  // copy new array back to original array
  for(int k = begin; k < end; k++) {
    arr[k] = cpArr[k];
  }
}

/**
 * is O(nlog n) for all cases
 */
void mergeSortHelper(int arr[], int begin, int end) {
  if(end - begin < 2 ) return; //trivial case
  
  int middle = (begin + end) / 2;
  
  mergeSortHelper(arr, begin, middle);
  
  mergeSortHelper(arr, middle, end);

  merge(arr, begin, middle, end);

}

void mergeSort(int arr[], int n) {
  mergeSortHelper(arr, 0, n);
}

int partition(int arr[], int begin, int end) {
  int bIter = begin + 1;
  int eIter  = end;

  //cout << "DEBUG: pivot=" << begin << endl; 
  //cout << "DEBUG: "; printArr(arr, SIZE);

  do {
    while(/*begin + 1 < eIter && */arr[begin] <= arr[eIter] && bIter <= eIter) {
      eIter--;
    }
    while(/*bIter < end && */arr[bIter] <= arr[begin] && bIter <= eIter) {
      bIter++;
    }

    if(bIter < eIter) {
      int temp   = arr[bIter];
      arr[bIter] = arr[eIter];
      arr[eIter] = temp;
    } else {
      int temp   = arr[begin];
      arr[begin] = arr[eIter];
      arr[eIter] = temp;
    }

    //cout << "DEBUG: "; printArr(arr, SIZE);
  } while( bIter < eIter );

  return bIter;
}

void quickSortHelper(int arr[], int begin, int end) {
  if(end - begin < 1) return; // trivial case

  int middle = partition(arr, begin, end);

  //cout << "DEBUG: begin=" << begin << " middle=" << middle << " end=" << end << endl;

  quickSortHelper(arr, begin, middle - 1);

  quickSortHelper(arr, middle, end);
}

/**
 * best and avg case is O(nlog n)
 * worst case is O(n^2)
 */
void quickSort(int arr[], int n) {
  quickSortHelper(arr, 0, n - 1);  
}

void printVec(vector<int> &a) {
  int size = a.size();
  for(int i = 0; i < size; i++)
    cout << a[i] << " ";
  cout << endl;
}

void printArr(int arr[], int n) {
  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void testDivySort() {
  vector<int> a;

  cout << 15 / 2 << endl;
  cout << 7 / 2 << endl;

  a.push_back(6);
  a.push_back(5);
  a.push_back(4);
  a.push_back(3);
  a.push_back(2);
  a.push_back(1);

  divySort(a);
}

void testSort( void (*sort)(int[],int), string testName ) {
  SIZE = 12;
  int arr1[SIZE] = {3, 5, 2, 7, 8, -1, 4, 1, 0, 10, -2, -10};
  cout << testName << ": before: "; printArr(arr1, SIZE);
  sort(arr1, SIZE);
  cout << testName << ": after:  "; printArr(arr1, SIZE);

  SIZE = 8;
  int arr2[SIZE] = {2, 1, 5, 0, 2, 3, -1, 0};
  cout << testName << ": before: "; printArr(arr2, SIZE);
  sort(arr2, SIZE);
  cout << testName << ": after:  "; printArr(arr2, SIZE);

  SIZE = 9;
  int arr3[SIZE] = {0, 1, 0, 1, -1, 2, -1, 0, 0};
  cout << testName << ": before: "; printArr(arr3, SIZE);
  sort(arr3, SIZE);
  cout << testName << ": after:  "; printArr(arr3, SIZE);

  SIZE = 12;
  int arr4[SIZE] = {1, 2, 0, 1, 2, 3, -1, 0, 0, 2, -1, 0};
  cout << testName << ": before: "; printArr(arr4, SIZE);
  sort(arr4, SIZE);
  cout << testName << ": after:  "; printArr(arr4, SIZE);

  SIZE = 12;
  int arr5[SIZE] = {1, 4, 5, 8, 2, 6, -1, 7, 2, 0, -1, 0};
  cout << testName << ": before: "; printArr(arr5, SIZE);
  sort(arr5, SIZE);
  cout << testName << ": after:  "; printArr(arr5, SIZE);

  SIZE = 2;
  int arr6[SIZE] = {1, 0};
  cout << testName << ": before: "; printArr(arr6, SIZE);
  sort(arr6, SIZE);
  cout << testName << ": after:  "; printArr(arr6, SIZE);
}

void testQuickSort() {
  testSort(quickSort, "testQuickSort");
}

void testMergeSort() {
  testSort(mergeSort, "testMergeSort");
}

/* general testing

g++ -std=c++11 -o sorting sortingAlgors.cpp
*/
int main() {

  //testQuickSort();
  testMergeSort();

  return 0;
}