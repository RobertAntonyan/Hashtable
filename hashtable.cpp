#include <iostream>
#include <list>

class HashTable
{

public:
  HashTable();
  ~HashTable();
  HashTable(int);
  void insertItem(int);
  void deleteItem(int);
  int hashFunction(int);
  void printHash();

private:
  int bucket;
  std::list<int> *table;
};

HashTable::HashTable()
{
}

HashTable::~HashTable()
{
}

HashTable::HashTable(int value) : bucket{}
{
  this->bucket = value;
  table = new std::list<int>[bucket];
}
int HashTable::hashFunction(int x)
{
  return (x % bucket);
}

void HashTable::insertItem(int key)
{
  int index = hashFunction(key);
  table[index].push_back(key);
}

void HashTable::deleteItem(int key)
{
  int index = hashFunction(key);
  std::list<int>::iterator i;
  for (i = table[index].begin(); i != table[index].end(); ++i)
  {
    if (*i == key)
      break;
  }
  if (i != table[index].end())
    table[index].erase(i);
}

void HashTable::printHash()
{
  for (int i = 0; i < bucket; ++i)
  {
    std::cout << i;
    for (auto x : table[i])
      std::cout << "-->" << x;
    std::cout << std::endl;
  }
}

int main()
{
  int arr[]{15, 11, 27, 8, 12,28,29};

  int n = sizeof(arr) / sizeof(arr[0]);
  HashTable hb(5);

  for (int i = 0; i < n; ++i)
  {
    hb.insertItem(arr[i]);
  }
  hb.printHash();
}