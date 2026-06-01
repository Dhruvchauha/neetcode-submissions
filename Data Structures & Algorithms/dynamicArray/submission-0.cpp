class DynamicArray {
private:
    int *arr;
    int capacity;
    int size;

    void resize() {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        int *newArr = new int[newCapacity];
        for (int i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    DynamicArray(int initialCapacity) : arr(new int[initialCapacity]), capacity(initialCapacity), size(0) {}

    ~DynamicArray() {
        delete[] arr;
    }

    int get(int i) {
        if (i < 0 || i >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[i];
    }

    void set(int i, int n) {
        if (i < 0 || i >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        arr[i] = n;
    }

    void pushback(int n) {
        if (size >= capacity) {
            resize();
        }
        arr[size++] = n;
    }

    int popback() {
        if (size <= 0) {
            throw std::out_of_range("Array is empty");
        }
        return arr[--size];
    }

    void resize(int newCapacity) {
        int *newArr = new int[newCapacity];
        int elementsToCopy = (newCapacity < size) ? newCapacity : size;
        for (int i = 0; i < elementsToCopy; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
        size = elementsToCopy;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }
};
