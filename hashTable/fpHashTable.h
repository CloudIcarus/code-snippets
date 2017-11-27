

class FPHashTable {
private:
  size_t elems;
  size_t size;

  std::pair<K, V>** table;
  bool* should_probe; // not sure if needed

  inline bool shouldResize() const {
    return static_cast<double>(elems) / size >= 0.7;
  }

  const size_t init_tsize = 20;

public:

  // Constructor
  LPHashTable();
  FPHashTable(size_t tsize);
  ~LPHashTable();

  // mutators
  void insert(const string key, const int value);
  bool remove(const K& key);

  // accessors
  int find(const K& key);
  bool keyExists(const K& key);
  void print();


}