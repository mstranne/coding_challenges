
class LinkedList {
    private:
        struct Node{
            Node* next  = nullptr;
            int value   = 0;
        };

        Node* m_head  = nullptr;
        int size    = 0;
    public:
        void Add(int val);
        // removes all with val
        bool Remove(int val);
        bool RemoveIdx(int idx);
        int Get(int idx);
        int Size() { return size; };
};