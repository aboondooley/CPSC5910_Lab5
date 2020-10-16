//
// Created by Alie on 10/15/2020.
//

#ifndef LAB5_LISTTEMPLATE_LINKEDLIST_H
#define LAB5_LISTTEMPLATE_LINKEDLIST_H
#include <string>
#include <iostream>

/**
 * LinkedList template class
 * The payload is a string
 * You can use any type that you want as the key! As long as this type
 * can be compared to zero
 * Can return the last negative number in the LinkedList object
 * @tparam T the data type of the key in the map/dictionary
 */
template<typename T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList &other);
    LinkedList<T> &operator=(const LinkedList<T> &rhs);

    void add(T key, std::string payload);  // lightning fast!!
    void remove(T key);  // not so fast -- linear search
    std::string search(T key) const;  // not so fast -- linear search
    /**
     * Returns the last negative key that is present in the LinkedList object
     * @return the last negative key in the LinkedList
     */
    T getLastNegative() const; // returns the last negative value in the LL

private:
    struct ListElem {
        T key;
        std::string payload;
        ListElem *next;

        // convenience ctor
        ListElem(T k, std::string p, ListElem *n) {
            key = k;
            payload = p;
            next = n;
        }
    };
    ListElem *head;

    void clear();
    /**
     * Helper function for getLastNegative()
     * @param neg the lsat negative key this far
     * @param n the next element in the LinkedList to check
     * @return returns the last negative number after checking the next node
     */
    T getLastNegative(T neg, ListElem *n) const; // recursive helper
    static ListElem *copy(ListElem *headToCopy);

};
// New methods!! Lab 5 methods!!
template<typename T>
T LinkedList<T>::getLastNegative() const {
    T neg = 0;
    return getLastNegative(neg, head);
}
template<typename T>
T LinkedList<T>::getLastNegative(T neg, ListElem *n) const { // recursive helper
    if (n == nullptr) return neg;
    if (n->key < 0) neg = n->key;
    return getLastNegative(neg, n->next);
}

// Old methods
template<typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}
template<typename T>
LinkedList<T>::~LinkedList() {
    clear();
}
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &other) {
    head = copy(other.head);
}
template<typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs) {
    if (&rhs != this) {
        clear();
        head = copy(rhs.head);
    }
    return *this;
}
template<typename T>
void LinkedList<T>::clear() {
    while (head != nullptr) {
        ListElem *toDelete = head;
        head = head->next;
        delete toDelete;
    }
}
template<typename T>
void LinkedList<T>::add(T key, std::string payload) {
    if (payload == "")
        throw std::invalid_argument("Cannot have a payload of empty string "
                                  "(means "
                               "not found when returned from search)");
    head = new ListElem(key, payload, head);
}
template<typename T>
std::string LinkedList<T>::search(T key) const {
    for (ListElem *cur = head; cur != nullptr; cur = cur->next) {
        if (cur->key == key)
            return cur->payload;
    }
    return ""; // Empty string means not found
}
template<typename T>
void LinkedList<T>::remove(T key) {
    if (head == nullptr)
        return;

    // special case if found at head of list
    if (head->key == key) {
        ListElem *toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    // normal case is to find later down the list
    ListElem *prior = head;
    for (ListElem *cur = head->next; cur != nullptr; cur = cur->next) {
        if (cur->key == key) {
            prior->next = cur->next;
            delete cur;
            return;
        }
        prior = prior->next;
    }
}
template<typename T>
typename LinkedList<T>::ListElem *LinkedList<T>::copy(LinkedList<T>::ListElem *headToCopy) {
    ListElem anchor(0, "", nullptr), *source, *tail;
    tail = &anchor;
    for (source = headToCopy; source != nullptr; source = source->next) {
        tail->next = new ListElem(source->key, source->payload, nullptr);
        tail = tail->next;
    }
    return anchor.next;
}


#endif //LAB5_LISTTEMPLATE_LINKEDLIST_H
