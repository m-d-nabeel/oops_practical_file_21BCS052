# 1. Constructors and Destructors

- **Type and Number of Constructors Called:**

  - Default Constructor (1 time)
  - Parameterized Constructor (1 time)
  - Copy Constructor (1 time)

- **Number of Destructors Called:**
  - Destructor (0 times, as no object goes out of scope)

# 2. Copy Constructor by Value

We can't call a copy constructor by value because doing so would require creating a copy of the object, which in turn would involve invoking the copy constructor, leading to an infinite loop.

# 3. Destructors Overloading

No, destructors cannot be overloaded. In C++, a class can have only one destructor, and its purpose is to clean up resources allocated by the class. When an object goes out of scope or is explicitly deleted, its destructor is automatically called.

# 4. Constructor Execution and Object Creation

If the computer hangs before the constructor can fully execute, the object will not be created. The constructor is responsible for initializing the object, and if it's interrupted, the object remains in an undefined state. To test this, you can use print statements or logging at various points within the constructor and observe the output.

# 5. Copy Constructor and Default Constructor

When only a copy constructor is written, the compiler does not automatically generate a default constructor. If you want to use the default constructor as well, you need to explicitly define it.

**Example:**

```cpp
class Line {
public:
    Line(const Line& other) {
        // Copy constructor implementation
    }
    // No default constructor
}
```

# 6. Normal Constructor Without Copy Constructor

If you write a normal constructor and don't write a copy constructor, the compiler will generate a default copy constructor for you. However, this may lead to unexpected behavior if your class manages resources, and a custom copy constructor may be needed.
