
// catalog.hpp
// CSUF CPSC 131, Fall 2016, Project 1
//
// Classes that define a catalog of supermarket products.

#pragma once

#include <stdexcept>
#include <string>

// A product represents one particular kind of product, such as apples
// or cereal.
class Product {
public:
  //Default constructor
  Product() : code(""), name(""), price(0) {}
  
  // Create a product with a given code, name, and price.
  //
  // code is intended to be a UPC code (bar code) or PLU code in a
  // string.
  //
  // name may be any string.
  //
  // price is in units of dollars. It must be positive, or else this
  // function throws std::invalid_argument.
  Product(const std::string& _code,
          const std::string& _name,
          double _price) : code(_code), name(_name), price(_price) {
    if (_price < 0) throw std::invalid_argument("price must be positive");
  }

  ~Product() { }

  // Accessors.
  const std::string& getCode() const { return code; }
  const std::string& getName() const { return name; }
  double getPrice() const { return price; }

private:
  std::string code, name;
  double price;
};

// A catalog represents a collection of all of the products available
// at a store.
class Catalog {
public:
  //default constructor
  Catalog() : size(0), numOfElem(0), a(NULL) {}
 
  // Create a new catalog.
  //
  // maxProducts is the maximum number of products that can be
  // stored. It must be positive, or else this function throws
  // std::invalid_argument.
  Catalog(int maxProducts) {
    // TODO: implement this function properly

    //throw std::logic_error("not implemented yet");
    if (maxProducts <= 0) throw std::invalid_argument("the maximum number of products must be postive");
    size = maxProducts;
    a = new Product[size];
    numOfElem = 0;
  }

  ~Catalog() {
    delete [] a;
  }

  // Accessors.
  int getMaxProducts() const {
    return size;
  }

  int getNumProducts() const {
    return numOfElem;
  }

  // Return true when the catalog cannot fit any more products.
  bool isFull() const {
    return (numOfElem == size);
  }

  // Add a new product to the catalog with a given code and name.
  //
  // code, name, and price have the same meaning as in a Product. If
  // price is invalid, throw std::invalid_argument.
  //
  // If this catalog is already full, throw overflow_error.
  //
  // Code must be different from all the product codes already in the
  // database. If it's not, throw std::invalid_argument.
  void addProduct(const std::string& code,
                  const std::string& name,
                  double price) {
    if (this->isFull()) throw std::overflow_error("catalog is already full");
    
    for (int i = 0; i <= numOfElem; i++)
      if (a[i].getCode() == code) throw std::invalid_argument("duplicated code");

    a[numOfElem] = Product(code, name, price);
    numOfElem++;
  }

  // Find a product by its code.
  //
  // code is a product code.
  //
  // Returns a const reference to the product with the matching code.
  //
  // Throw std::invalid_argument if no product with that code exists
  // in the catalog.
  const Product& findCode(const std::string& code) const {
    bool found = false;
    int i = 0;
    while (!found && i <= numOfElem)
    {
      if (a[i].getCode() == code)
      {
        found = true;
        i--;
      }
      i++;
    }
    if (!found) throw std::invalid_argument("no product with that code exists");
    return a[i];
  }
private:
  Product* a;
  int size;
  int numOfElem;
};
