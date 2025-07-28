#include <iostream>
#include <list>
class HashTable
{
    static const int hashGroups = 10;
    //this is an array of linked lists like
    std::list<std::pair<int, std::string>>Table[hashGroups];
    //table[0]= (key,value)=>(key,value)
    //table[1]= (key,value)=>(key,value)=>(key,value)
public:
    bool isEmpty()const
    {
        int sum{};
        for (int i{};i < hashGroups;i++)
        {
            sum += Table[i].size();
            if (sum)
            {
                return false;
            }
        }
        return true;
    }
    int hashFunction(int key)
    {
        return key % hashGroups;
    }
    void insertItem(int key,std::string value)
    {
        int index = hashFunction(key);
        for (auto &pair :Table[index])
        {
            if (pair.first==key)
            {
                pair.second = value;
                return;
            }
        }
        Table[index].emplace_back(key, value);
        //or another approach
        //Table[index].push_back(std::make_pair(key, value));

    }
    void removeItem(int key)
    {
        int index = hashFunction(key);
        auto& cell = Table[index];
        //this equals to
        //std::list<std::pair<int,std::string>>& cell = Table[index];
        for (auto it=cell.begin();it!=cell.end();++it)
        {
            if (it->first==key)
            {
                cell.erase(it);
                return;
            }
        }
    }
    std::string searchTable(int key)
    {
        int index = hashFunction(key);
        auto& cell = Table[index];
        for (auto it = cell.begin();it != cell.end();++it)
        {
            if (it->first==key)
            {
                return it->second;
            }
        }
        return "Key not found";
    }
    void printTable()
    {
        for (int i{};i < hashGroups;i++)
        {
            std::cout << "[" << i << "] : ";
            auto& cell = Table[i];
            for (auto it = cell.begin();it != cell.end();it++)
            {
                std::cout << "(" << it->first << " => " << it->second<<")" << " -> ";
            }
            std::cout << "nullptr" << std::endl;;
        }
    }
};
int main()
{
    HashTable hashTable;
    hashTable.insertItem(5, "raed");
    hashTable.insertItem(3, "khaled");
    hashTable.insertItem(6, "salem");
    hashTable.insertItem(28, "osama");
    hashTable.insertItem(192, "yaqeen");
    hashTable.insertItem(3, "mohammed");
    hashTable.insertItem(13, "basel");
    std::cout << hashTable.isEmpty() << std::endl;
    std::cout << "-----------------------------" << std::endl;
    hashTable.printTable();
    std::cout << "-----------------------------" << std::endl;
    hashTable.removeItem(3);
    hashTable.printTable();
    std::cin.get();
}