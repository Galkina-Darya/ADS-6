// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
 private:
    T arr[size] = { 0 };
    int b, l;
 public:
    void push(T temp) {
    int a = l;
    for (; (a >= b) && arr[a % size].prior < temp.prior; --a) {
      arr[(a + 1) % size] = arr[a % size];
    }
    arr[(a + 1) % size] = temp;
      ++l;
    }
    T pop() {
      return arr[(b++) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
