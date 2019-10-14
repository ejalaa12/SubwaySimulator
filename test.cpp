//
// Created by El Jawad Alaa on 07/10/2019.
//
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

class Dog{
private:
  std::string mName;
public:
  void setName(const std::string &pName) {
    mName = pName;
  }

  bool operator<(const Dog &pRhs) const {
    return mAge < pRhs.mAge;
  }

  bool operator>(const Dog &pRhs) const {
    return pRhs < *this;
  }

  bool operator<=(const Dog &pRhs) const {
    return !(pRhs < *this);
  }

  bool operator>=(const Dog &pRhs) const {
    return !(*this < pRhs);
  }

private:
  int mAge;
public:
  Dog(std::string pName, int pAge){
    mName = pName;
    mAge = pAge;
  }

  friend std::ostream &operator<<(std::ostream &pOs, const Dog &pDog) {
    pOs << "Dog name: " << pDog.mName << " and age: " << pDog.mAge;
    return pOs;
  }
};

class Owner{
private:
  Dog &mDog;
public:
  Owner(Dog &pDog) : mDog(pDog){
  }

  void setDog(const Dog &pDog) {
    mDog = pDog;
  }

  friend std::ostream &operator<<(std::ostream &pOs, const Owner &pOther) {
    pOs << "Owner has dog: " << pOther.mDog;
    return pOs;
  }

  void renameDog(std::string pNewName){
    mDog.setName(pNewName);
  }
};

int main() {
  // Create dogs
  Dog fox("FOX", 12);
  Dog rex("REX", 2);
  Dog bob("BOB", 4);

  // add dog to list
  std::vector<std::reference_wrapper<Dog>> dogs;
  dogs.push_back(fox);
  dogs.push_back(rex);
  dogs.push_back(bob);

  // Print dogs
  std::cout << "-----------" << std::endl;
  std::cout << "Original list" << std::endl;
  std::cout << "-----------" << std::endl;
  for (Dog d : dogs) {
    std::cout << d << std::endl;
  }

  // Sort list
  std::cout << "-----------" << std::endl;
  std::cout << "Sorted list by age" << std::endl;
  std::cout << "-----------" << std::endl;
  std::sort(dogs.begin(), dogs.end(), std::less<Dog>{});
  for (Dog d : dogs) {
    std::cout << d << std::endl;
  }
  // rename dog
  std::cout << "-----------" << std::endl;
  std::cout << "Renamed fox -> foxie and rex -> rexou" << std::endl;
  std::cout << "-----------" << std::endl;
  fox.setName("foxie");
  dogs[1].get().setName("rexou");

  for (Dog d : dogs) {
    std::cout << d << std::endl;
  }

  // tell owner to rename
  Owner paul(fox);
  std::cout << paul << std::endl;
  paul.renameDog("fux");
  std::cout << paul << std::endl;
  std::cout << fox << std::endl;

}