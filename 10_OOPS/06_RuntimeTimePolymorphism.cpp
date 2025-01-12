/*
Run-Time Polymorphism (Dynamic Polymorphism) in C++
---------------------------------------------------
- Enables function calls to be resolved at runtime based on the actual object type.
- Achieved using inheritance and virtual functions.

Key Concepts in the Code:
1. **Virtual Functions**:
   - Declared using the `virtual` keyword in the base class.
   - Allows derived classes to override the base class method.
   - Example: The `draw()` function in the `Shape` class is overridden by `Circle`, `Rectangle`, and `Triangle`.

2. **Upcasting**:
   - A base class pointer can point to a derived class object.
   - Example: 
     ```cpp
     Shape *s3 = new Circle();
     s3->draw(); // Calls `Circle`'s implementation of `draw()`.
     ```

3. **Downcasting**:
   - Explicitly casting a base class pointer to a derived class pointer.
   - Example:
     ```cpp
     Shape *s2 = new Shape();
     Circle *c2 = (Circle *)s2; // Unsafe and may cause undefined behavior.
     ```

Summary:
This code demonstrates **Run-Time Polymorphism** using virtual functions, upcasting, and the risks of unsafe downcasting.
*/


/*

Here is the extracted text from the image:

---

**Final Keyword**

1. In C++, the final specifier is used in two main contexts: with classes and with virtual member functions.  
2. **Prevents Class Inheritance:** When you declare a class as final, it means that no other class can inherit from it.  
3. **Preventing Virtual Function Overriding:** The final specifier can also be used with virtual functions to prevent them from being overridden in derived classes.  

*/


#include <iostream>

using namespace std;

class Shape
{
public:
    virtual void draw() //final
    {
        cout << "Generic drawing..." << endl;
    }
};

class Circle : public Shape
{
public:
    void draw()
    {
        cout << "Circle drawing..." << endl;
    }
};

class Rectangle : public Shape
{
public:
    void draw()
    {
        cout << "Rectangle drawing..." << endl;
    }
};

class Triangle : public Shape
{
public:
    void draw()
    {
        cout << "Triangle drawing..." << endl;
    }
};

void ShapeDrawing(Shape *s)
{
    s->draw(); // draw is polymorphic
}

int main()
{
    // Circle c;
    // Rectangle r;

    // ShapeDrawing(&c);
    // ShapeDrawing(&r);

    // Triangle *t = new Triangle();
    // ShapeDrawing(t);

    // virtual keyword
    Shape *s = new Shape();
    s->draw();

    // UPCASTING
    Shape *s3 = new Circle();
    s3->draw();

    Circle *c = new Circle();
    c->draw();

    // DOWNCAsTing
    Shape *s2 = new Shape();
    Circle *c2 = (Circle *)s2;
    c2->draw();
    return 0;
}
