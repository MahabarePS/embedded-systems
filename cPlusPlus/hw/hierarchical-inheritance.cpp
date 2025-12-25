/*
Assignment: Hierarchical Inheritance – Online Shopping System
Problem Statement
Design an online shopping system. The system has one base class Product and three derived classes
representing different product categories:
Product
/ | \
Electronics Clothing Grocery
Class Requirements
1. Product (Base Class)
Data Members:
o string productID;
o string name;
o double price;
Constructor: Initialize all data members.
Method:
o void displayProductInfo(); // Prints: &quot;ID: [productID], Name: [name], Price: [price]&quot;
2. Electronics (Derived Class)
Data Members:
o int warranty; // Warranty in months
Constructor: Initialize base class members and warranty.
Method:
o void displayElectronicsInfo(); // Prints product info + warranty
3. Clothing (Derived Class)
Data Members:
o string size;
o string material;
Constructor: Initialize base class members and size &amp; material.
Method:
o void displayClothingInfo(); // Prints product info + size and material
4. Grocery (Derived Class)
Data Members:

o string expiryDate; // Format: YYYY-MM-DD
Constructor: Initialize base class members and expiryDate.
Method:
o void displayGroceryInfo(); // Prints product info + expiry date

Assignment Tasks
1. Create at least one object of each derived class: Electronics, Clothing, and Grocery.
2. Initialize each object with appropriate details.
3. Call the corresponding display method for each object to show all information.
4. Demonstrate that base class methods are accessible from derived class objects.

Sample Input/Output
Input (user-defined or hardcoded):
Electronics: ID E101, Name: Smartphone, Price: 35000, Warranty: 24 months
Clothing: ID C202, Name: T-Shirt, Price: 799, Size: M, Material: Cotton
Grocery: ID G303, Name: Milk, Price: 60, Expiry: 2025-12-30
Output:
Electronics Product:
ID: E101, Name: Smartphone, Price: 35000
Warranty: 24 months

Clothing Product:
ID: C202, Name: T-Shirt, Price: 799
Size: M, Material: Cotton

Grocery Product:
ID: G303, Name: Milk, Price: 60
Expiry Date: 2025-12-30
Optional Challenges
1. Add discount calculation for each product type and display the discounted price.
2. Add input validation: Price must be positive, warranty non-negative, expiry date valid.
*/
#include<iostream>
using namespace std;
//Base class
class Product{
    protected:
        string productID, name;
        double price;
    public:
        Product(const string &pro, const string &nm, double pri){
            //product ID validation
            if(pro.empty()){
                cout<<"\n[Warning] Product ID cannot be empty! Setting default."<<endl;
                productID="";
            }else{
                productID=pro;
            }
            // name validation
            if(nm.empty()){
                cout<<"\n[Warning] Name cannot be empty! Setting default."<<endl;
                name="";
            }else{
                name=nm;
            }
            // price validation
            if(pri<0.0){
                cout<<"\n[Warning] Invalid Price! Setting default."<<endl;
                price=0.0;
            }else{
                price=pri;
            }
        }
        // Prints: &quot;ID: [productID], Name: [name], Price: [price]&quot;
        const void displayProductionInfo(){
            cout<<"ID: "<<productID
                <<", Name: "<<name
                <<", Price: "<<price<<endl;
        }
};
class Electronics: public Product{\
    protected:
    // in months
        int warranty=0;
    public:
        //Initialize base class members and size &amp; material.
        Electronics(const string &pro, const string &nm, double pri,int warr):Product(pro, nm,pri){
        // warrenty validation
        if(warr<0){
            cout<<"\n[Warning] Invalid Warrenty! Setting default."<<endl;
            warranty=0;
        }else{
            warranty = warr;
        }
        }
        // Prints product info + warranty
        const void displayElectronics(){
            Product::displayProductionInfo();
            cout<<"Warranty: "<<warranty<<endl;
        }
};
class Clothing: public Product{
    protected:
        string size, material;
    public:
        //Initialize base class members and size &amp; material.
        Clothing(const string &pro, const string &nm, double pri, const string &sz, const string &mat)
        :Product(pro,nm,pri){
            //size validation
            if(sz.empty()){
                cout<<"\n[Warning] Size cannot be empty! Setting default."<<endl;
                size="";
            }else{
                size=sz;
            }
            //material validation
            if(mat.empty()){
                cout<<"\n[Warning] Material cannot be empty! Setting default."<<endl;
                material="";
            }else{
                material=mat;
            }
        }
        // Prints product info + size and material
        const void displayClothingInfo(){
            Product::displayProductionInfo();
            cout<<"Size: "<<size
                <<", Material: "<<material<<endl;
        }
};
class Grocery: public Product{
    protected:
        string expiryDate;
    public:
        //Initialize base class members and expiryDate.
        Grocery(const string &pro, const string &nm, double pri, const string &ed)
        :Product(pro, nm, pri){
        //size validation
            if(ed.empty()){
                cout<<"\n[Warning] expiryDate cannot be empty! Setting default."<<endl;
                expiryDate="";
            }else{
                expiryDate=ed;
            }
        }
        // Prints product info + expiry date
        const void displayGroceryInfo(){
            Product::displayProductionInfo();
            cout<<"Expiry Date: "<<expiryDate<<endl;
        }
};
int main(){
    Electronics e("E101","Smartphone",35000.0,24);
    e.displayElectronics();
    //Clothing c("C202",799.0,"M","Cotton");
    Grocery g("G303","Milk",60.0,"2025-12-30");
    g.displayGroceryInfo();
    return 0;
}