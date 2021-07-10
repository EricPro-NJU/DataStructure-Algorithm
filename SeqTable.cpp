//
// Created by gerui on 2021/7/10.
//

#include "SeqTable.h"

void SeqTableDemo(){
    //default construction
    SeqTable table;
    for(int i = 0; i < 5; i++){
        table.pushBack(i);
    }
    cout << table << endl;
    //copy construction
    SeqTable table2(table);
    //inserting
    table2.insertByLoc(2, 9);
    cout << table2 << endl;
    //searching
    cout << table2.searchByLoc(3) <<endl;
    cout << table2[3] << endl;
    cout << table2.searchLoc(4) <<endl;
    //removing
    table2.removeByLoc(3);
    cout << table2 << endl;
    table2.removeByData(3);
    cout << table2 << endl;
    table2.removeByData(-1);
    cout << table2 << endl;
    //empty&clear
    if(table2.empty()) cout << "table2 is empty.\n";
    table2.clear();
    if(table2.empty()) cout << "table2 is empty.\n";
    cout << table2 << endl;
    //operators
    SeqTable table3 = table;
    if(table3 == table) cout << "tables are the same.\n";
    //auto memory expansion
    SeqTable smallTable(2);
    smallTable.pushBack(1);
    cout<<"Size: "<<smallTable.getSize()<<", Length: "<<smallTable.getLength()<<endl;
    smallTable.pushBack(2);
    cout<<"Size: "<<smallTable.getSize()<<", Length: "<<smallTable.getLength()<<endl;
    smallTable.pushBack(3);
    cout<<"Size: "<<smallTable.getSize()<<", Length: "<<smallTable.getLength()<<endl;
    //input data from keyboard
    SeqTable myTable;
    cin >> myTable;
    cout << myTable << endl;

}



bool SeqTable::resize(int size) {
    if(size == maxSize) return true;
    T* newData = new T[size];
    if(newData == NULL) {
        return false;
    }
    length = length < size? length:size;
    maxSize = size;
    int i;
    for(i = 0; i < length; i++) {
        newData[i] = data[i];
    }
    delete[]data;
    data = newData;
    return true;
}

SeqTable::SeqTable(){
    maxSize = defaultSize;
    length = 0;
    data = new T[defaultSize];
}

SeqTable::SeqTable(int size){
    maxSize = size;
    length = 0;
    data = new T[size];
}

SeqTable::SeqTable(SeqTable& table){
    this->maxSize = table.maxSize;
    this->length = table.length;
    this->data = new T[this->maxSize];
    int i;
    for(i = 0; i < this->length; i++) {
        this->data[i] = table.data[i];
    }
}

bool SeqTable::pushBack(T x) {
    if(length == maxSize){
        bool success = resize(maxSize * 2);
        if(!success){
            cerr << "Error when allocating memory.\n";
            return false;
        }
    }
    data[length] = x;
    length ++;
    return true;
}

bool SeqTable::insertByLoc(int loc, T x) {
    if(loc < 0 || loc > length) {
        cerr << "Error when inserting data: Invalid index.\n";
        return false;
    }
    if(length == maxSize){
        bool success = resize(maxSize * 2);
        if(!success){
            cerr << "Error when allocating memory: Allocation failed.\n";
            return false;
        }
    }
    int i;
    for(i = length; i>loc; i--) {
        data[i] = data[i-1];
    }
    data[loc] = x;
    length ++;
    return true;
}

bool SeqTable::removeByLoc(int loc) {
    if(loc < 0 || loc >= length) {
        cerr << "Error when removing data: Invalid index.\n";
        return false;
    }
    int i;
    for(i = loc; i < length-1; i++) {
        data[i] = data[i+1];
    }
    length --;
    return true;
}

int SeqTable::searchLoc(T x) {
    int i;
    for(i = 0; i < length; i++) {
        if(data[i] == x) return i;
    }
    return -1;
}

T SeqTable::searchByLoc(int loc) {
    if(loc < 0 || loc >= length) {
        cerr << "Error when reading data: Invalid index.\n";
        return 0;
    }
    return data[loc];
}

bool SeqTable::removeByData(T x) {
    int loc = searchLoc(x);
    if(loc == -1) return false;
    removeByLoc(loc);
    return true;
}

bool SeqTable::empty() {
    return length == 0;
}

void SeqTable::clear(){
    length = 0;
}

SeqTable &SeqTable::operator=(SeqTable &table) {
    delete[] this->data;
    this->maxSize = table.maxSize;
    this->length = table.length;
    this->data = new T[this->maxSize];
    int i = 0;
    for(i = 0; i < this->length; i++) {
        this->data[i] = table.data[i];
    }
    return *this;
}

T SeqTable::operator[](int loc) {
    return searchByLoc(loc);
}

bool SeqTable::operator==(SeqTable &table) {
    if(table.length != this->length) return false;
    int i;
    for(i = 0; i < this->length; i++) {
        if(table.data[i] != this->data[i]) return false;
    }
    return true;
}

istream &operator>>(istream &in, SeqTable &table) {
    int n;
    T data;
    cout << "Please enter the number of data to be input: ";
    in >> n;
    cout << "Please enter the dataset of " << n <<" numbers (separated by space):\n";
    for(int i = 0; i < n; i++){
        in >> data;
        table.pushBack(data);
    }
    return in;
}

ostream &operator<<(ostream &out, SeqTable &table) {
    out << "SequentialTableInfo: Length " << table.length;
    out << ". [";
    int i;
    for(i = 0; i < table.length; i++) {
        out << table.data[i];
        if(i != table.length - 1) out << ", ";
    }
    out<< "]";
    return out;
}




