#ifndef ITER_H
#define ITER_H

template <typename T, typename L>
void iter(T *array, L length, void (*f)(T &)) {
  if (!array || !f) return;
  for (L i = 0; i < length; i++) {
    f(array[i]);
  }
}

template <typename T, typename L>
void iter(const T *array, L length, void (*f)(const T &)) {
  if (!array || !f) return;
  for (L i = 0; i < length; i++) {
    f(array[i]);
  }
}

#endif  // !ITER_H
