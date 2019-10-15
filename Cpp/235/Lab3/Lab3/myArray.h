#ifndef MYARRAY_H
#define MYARRAY_H
#define MAX_ARRAY_SIZE	1000

template<typename T>
class MyArray
{
private:
   // MyArray data
public:
   MyArray(const size_t maxSize) { /*...*/ }
   void push_back(T item) { /*...*/ }
   class Iterator
   {
   private:
      // Iterator data and private functions
   public:
      Iterator(T* array, size_t size, size_t index) { /*...*/ }
      bool operator!= (const Iterator& other) const { /*...*/ }  // not-equal
      Iterator& operator++ () { /*...*/ }                        // pre-increment ++
      T& operator*() const { /*...*/ }                           // dereference
      std::string toString() const { /*...*/ }
      friend std::ostream& operator<< (std::ostream& os, const Iterator& iter) { /*...*/ }
   };
   Iterator begin() { /*...*/ }             // pointer to first element
   Iterator end() { /*...*/ }               // pointer AFTER last element
   std::string toString() const { /*...*/ }
   friend std::ostream& operator<< (std::ostream& os, const MyArray<T>& myArray) { /*...*/ };
};
#endif // MYARRAY_H
