class IntList {
public:
    IntList();

    IntList(const IntList &other);

    IntList &operator=(const IntList &other);

    ~IntList();

    int getCount();

    bool isEmpty();

    void print();

    void insert(int element, int position);

    void remove(int position);

    int getElement(int position);

private:
    struct IntListElem {
        IntListElem *next;
        int value;
    };
    int count;
    IntListElem *first;

    IntListElem *findElement(int position);
};