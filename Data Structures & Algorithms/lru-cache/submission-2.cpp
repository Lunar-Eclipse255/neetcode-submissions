struct Node{
    int key;
    int value;
    struct Node* next;
    struct Node* prev;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};
class DoubleList {
public:
    
    Node* head;
    Node* tail;

    DoubleList() : head(nullptr), tail(nullptr) {}
    void addFront(Node* node) {
        node->prev = nullptr;
        node->next = head;
        if (head != nullptr) {
            head->prev = node;
        }
        else{
            tail = node;
        }
        head = node;
    }
    void remove(Node* node) {
        if (node->prev) {
            node->prev->next = node->next;
        }
        else{
            head = node->next;
        }
        if (node->next) {
            node->next->prev = node->prev;
        }
        else{
            tail = node->prev;
        }
    } 
    void moveToFront(Node* node) {
        remove(node);
        addFront(node);
    }
    Node* removeLast() {
        if (!tail) return nullptr;
        Node* node = tail;
        remove(node);
        return node;

    }

};
class LRUCache {
public:
    int capacity;
    DoubleList dll;
    unordered_map<int, Node*> map; 
    Node* head; 
    Node* tail;

    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        Node* node = map[key];
        dll.moveToFront(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            node->value = value;
            dll.moveToFront(node);
            return;
        }
        Node* node = new Node (key, value);
        if (map.size()==capacity){
            Node* lru = dll.removeLast();
            map.erase(lru->key);
            delete lru;
        }
        dll.addFront(node);
        map[key] = node;

    }
};
