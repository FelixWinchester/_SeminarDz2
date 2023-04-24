// Конструктор копирования
    List(const List &other) {
        // Копируем размер списка
        size = other.size;
        // Создаем новый массив для элементов списка
        elem = new int[size];
        // Копируем элементы списка
        for (int i = 0; i < size; i++) {
            elem[i] = other.elem[i];
        }
    }
private:
    int *elem; // Массив элементов списка
    int size; // Размер списка
};
