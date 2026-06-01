class DynamicArray {
private:
    int *array;
    int size;
    int capacity;

public:
    DynamicArray(int capacity) : size(0), capacity(capacity) {
        array = new int[capacity];
    }

    ~DynamicArray() {
        delete[] array;
    }

    int get(int i) {
        return array[i];
    }

    void set(int i, int n) {
        array[i] = n;
    }

    void pushback(int n) {
        if (size == capacity) {
            resize();
        }
        array[size++] = n;
    }

    int popback() {
        return array[--size];
    }

    void resize() {
        int newCapacity = capacity * 2;
        int *newArray = new int[newCapacity];
        for (int i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
