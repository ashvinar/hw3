#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  int m_;

  PComparator comp_;

  std::vector<T> elements_;

  void heapifyUp(size_t index);

  void heapifyDown(size_t index);
};

template <typename T, typename PComparator>
Heap <T, PComparator>::Heap(int m, PComparator c)
        : m_(m), comp_(c)
        {

          if (m < 2){
            throw std::invalid_argument({"m-ary heap must have m >= 2"});
          }
        }

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{

}
// Add implementation of member functions here
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return elements_.size();
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
    return elements_.empty();
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
      throw std::underflow_error("Heap is empty. No top element");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return elements_[0];  


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================

  throw std::underflow_error("Heap is empty. No element to pop");

  }

  std::swap(elements_[0], elements_[elements_.size() - 1]);

  elements_.pop_back();

  if (!elements_.empty()){
    heapifyDown(0);
  }

}


template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  // Insert at the end
  elements_.push_back(item);
  // Bubble up to restore the heap property
  heapifyUp(elements_.size() - 1);
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(size_t index){
  
  while (index > 0){
    size_t parent = (index -1 ) / m_;

    if (comp_(elements_[index], elements_[parent])) {
      std::swap(elements_[index], elements_[parent]);
      index = parent;
    }else{
      break;
    }
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(size_t index){

  while(true){
    size_t top = index;

    for (int i = 1; i <= m_; i++){
      size_t child = m_ * index + i;
      if (child < elements_.size()){

          if (comp_(elements_[child], elements_[top])){
            top = child;
          }
      }else{
        break;
      }
    }

    if (top == index){
      break;
    }

    std::swap(elements_[index], elements_[top]);
    index = top;
  }
}

#endif

