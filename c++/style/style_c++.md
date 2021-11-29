# Tree
### _> The #define Guard :_

### _> Forward Declarations :_

### _> Inline Functions :_

### _> Names and Order of Includes :_

### _> Scoping :_
  1. Namespaces
  2. Internal Linkage
  3. Nonmember, Static Member, and Global Functions
  4. Local Variables
  5. Static and Global Variables
  6. Thread_local Variables

### _> Classes:_
  1. Doing Work in Constructors
  2. Implicit Conversions
  3. Copyable and Movable Types

### _> Structs vs. Classes:_

### _> Function :_
  1. Inputs and Outputs
  2. Write Short Functiond
  3. Function Overloading
  4. Default Arguments
  5. Trailing Return Type Syntax

### _> Google-Specific Magic :_
  1. Ownership and Smart Pointers
  2. cpplint

### _> Other C++ Features :_
  1. Rvalue Reference
  2. Friends
  3. Exceptions
  4. noexcept
  5. Run-Time Type Information (RTTI)
  6. Casting
  7. Stream
  8. Preincrement and Predecrement
  9. Use of const :Use of const :
  10. Use of constexpr
  11. Integer Types
  12. 64-bit Portability
  13. Preprocessor Macros
  14. and nullptr/NULL
  15. sizeof
  16. Type Deduction (including auto)
  17. Class Template Argument Deduction
  18. Designated Initializers
  19. Lambda Expressions
  20. Template Metaprogramming
  21. Boost
  22. Other C++ Features
  23. Nonstandard Extensions
  24. Aliases
  25. Inclusive Language

### _> Naming_
  1. General Naming Rules
  2. File Names
  3. Variable Names
  4. Constant Names
  5. Function Names
  6. Namespace Names
  7. Enumerator Names
  8. Macro Names
  9. Exceptions to Naming Rules
  10. Comment
      - Comment Style
      - File Comments
      - Class Comments
      - Function Comments
      - Variable Comments
      - Implementation Comments
      - Function Argument Comments
      - Function Argument Comments
      - Don'ts
      - Punctuation, Spelling, and Grammar
      - TODO Comments

### _> Formatting_
  1. Line Length
  2. Non-ASCII Characters
  3. Spaces vs. Tabs
  4. Function Declarations and Definitions
  5. Lambda Expressions
  6. Floating-point Literals
  7. Function Calls
  8. Braced Initializer List Format
  9. Conditionals
  10. Loops and Switch Statements
  11. Pointer and Reference Expressions
  12. Boolean Expressions
  13. Return Values
  14. Variable and Array Initialization
  15. Preprocessor Directives
  16. Class Formart
  17. Constructor Initializer Lists
  18. Namespace Formatting
  19. Horizontal Whitespace
  20. Vertical Whitespace
  21. Exceptions to the Rules

# Google C++ Style Guide
## _The #define Guard :_
### Tất cả các các heder file nên được #define guards , Formart symbol name nêm theo mẫu .
```sh
<PROJECT>_<PATH>_<FILE>_H_
```
- Ví dụ file foo/src/bar/baz.h nên có following guard như dưới đây:
  ```sh
  #ifndef FOO_BAR_BAZ_H_
  #define FOO_BAR_BAZ_H_

  ...

  #endif  // FOO_BAR_BAZ_H_
  ```
```sh
```
## _Forward Declarations :_
### Tránh sử dụng Forward Declarations nếu có thể, thay vào đó include file header cần
  > Forward Declarations : Giả sử có 2 class là ClassA và ClassB, mỗi class đều có file .h và .cpp tương ứng và bạn muốn sử dụng ClassA trong ClassB. Theo cách thông thường, bạn sẽ phải include header file của ClassA trong cả file .h và .cpp của ClassB . Forward Declarations sẽ thay thế chuyện đó.
```sh
```
## _Inline Functions :_
### Define inline function khi và khi khi số lượng dòng code là 10 dòng hoặc ít hơn.
  > Inline function : là một chức năng trong ngôn ngữ lập trình C++. Hàm inline là hàm được định nghĩa bằng từ khóa inline. Hàm inline được sử dụng để yêu cầu trình biên dịch (compiler) thay thế lời gọi hàm bằng toàn bộ mã code của hàm nhằm mục đích giảm thời gian chạy chương trình.
```sh
```
## _Names and Order of Includes :_
### Include file header theo nguyên tắc : Related header, C system headers, C++ standard library headers, other libraries' headers, your project's headers.

  1. dir2/foo2.h.
  2. A blank line
  3. C system headers (more precisely: headers in angle brackets with the .h extension), e.g., <unistd.h>, <stdlib.h>.
  4. A blank line
  5. C++ standard library headers (without file extension), e.g., <algorithm>, <cstddef>.
  6. A blank line
  7. Other libraries' .h files.
  8. A blank line
  9. Your project's .h files.
  - the includes trong google-awesome-project/src/foo/internal/fooserver.cc
    ```sh
    #include "foo/server/fooserver.h"

    #include <sys/types.h>
    #include <unistd.h>

    #include <string>
    #include <vector>

    #include "base/basictypes.h"
    #include "base/commandlineflags.h"
    #include "foo/server/bar.h"
    ```
  - Đôi khi system-specific code cần thêm điều kiện includes. Giữ syctem-specific của bạn small and localized
    ```sh
    #include "foo/public/fooserver.h"

    #include "base/port.h"  // For LANG_CXX11.

    #ifdef LANG_CXX11
    #include <initializer_list>
    #endif  // LANG_CXX11
    ```
```sh
```
## _Scoping :_
### <> _Namespaces_
Namespaces chia nhỏ global scope thành những scope riêng biệt , tránh việc trùng lặp tên biến, function trong global scope.
  - Ví dụ :
    ```sh
    namespace first_space {
      void func() {
        cout << "Inside first_space" << endl;
        }
    }

    namespace second_space {
      void func() {
          cout << "Inside second_space" << endl;
      }
    }

    int main () {
      // Calls function from first name space.
      first_space::func();

      // Calls function from second name space.
      second_space::func();

      return 0;
    }
    ```
Namespaces nên được sử dụng như sau :
  - In the .h file
    ```sh
    namespace mynamespace {

      // All declarations are within the namespace scope.
      // Notice the lack of indentation.
      class MyClass {
      public:
        ...
        void Foo();
      };
    }  // namespace mynamespace
    ```
  - In the .cc file
    ```sh
    namespace mynamespace {

      // Definition of functions is within scope of the namespace.
      void MyClass::Foo() {
        ...
      }
    }  // namespace mynamespace
    ```
  - Phức tạp hơn .cc file có thể có flags and using-declarations
    ```sh
    #include "a.h"

    ABSL_FLAG(bool, someflag, false, "dummy flag");

    namespace mynamespace {

    using ::foo::Bar;

    ...code for mynamespace...    // Code goes against the left margin.

    }  // namespace mynamespace
    ```
  - Tuyệt đối không sử dụng :
    ```sh
    using namespace foo;
    ```
```sh
```
### <> _Internal Linkage_
Khi định nghĩa trong file .cc  không cần được tham chiếu tới các file bên ngoài , Đặt nó trong vùng namespaces chưa đặt tên hoặc static. Không dùng Internal Linkage trong file .h
  - Ví dụ:
    ```sh
    namespace {
      ...const int SIZE_OF_ARRAY_X;
      const int SIZE_OF_ARRAY_Y;
      bool getState(userType*,otherUserType*);
    }  // namespace
    ```
```sh
```
### <> _Nonmember, Static Member, and Global Functions_

  - Non-member function : luôn luôn appears bên ngoài class
  Member function : nếu muốn appears bên ngoài class thì cần thêm tên class phía trước.

    ```SH
    // No-member function
      int myfunction (int a, int b)
      {
        ..//details of this implementation
      }
      // Member function
      int myarray::myfunction(int a, int b)
      {
        ...//details of this implementation
          //note: you need the protype of myfunction in the body of myarray
      }

      int main()
      {
        int i;
        myarray a;  //declare a myarray object

        i=myfunction(3,2);  //invoking the non-member function
        i=a.myfunction(3,2); //invoking the member function
      }
    ```

```sh
```
### <> _Local Variables_
Đặt vị trí các biến ở phạm vi hẹp nhất nếu có thể

  - Bad -- initialization separate from declaration.
    ```sh
      int i;
      i = f();
    ```
  - Prefer -- initializing using brace initialization.
    ```sh
      std::vector<int> v;
      v.push_back(1);
      v.push_back(2);
    ```
  - Good -- v starts initialized.
    ```sh
      std::vecter<int> v = {1, 2};
    ```

Các biến dùng trong câu lệnh If, while, for được define ở trong câu lệnh để phạm vi của biến ở trong câu lệnh đó

  ```sh
    while (const char* p = strchr(str, '/')) str = p + 1;
  ```

Nếu biến là object , khởi tạo nó trước khi gọi và sau khi kết thúc qúa trình xử lý trả vể gía trị ban đầu của object đó .

  - Inefficient( Không hiệu qủa ) implementation:
    ```sh
      for (int i = 0; i < 1000000; ++i) {
        Foo f;  // My ctor and dtor get called 1000000 times each.
        f.DoSomething(i);
      }
    ```
  - Efficient( Hiệu qủa ) implementation
    ```sh
      Foo f;  // My ctor and dtor get called once each.
      for (int i = 0; i < 1000000; ++i) {
        f.DoSomething(i);
      }
    ```

```sh
```
### <> _Static and Global Variables_
Decision on destruction( Sự phá hủy )
- Allowed :
  ```sh
    const int kNum = 10;  // allowed

    struct X { int n; };
    const X kX[] = {{1}, {2}, {3}};  // allowed

    void foo() {
      static const char* const kMessages[] = {"hello", "world"};  // allowed
    }

    // allowed: constexpr guarantees trivial destructor
    constexpr std::array<int, 3> kArray = {{1, 2, 3}};
  ```
- Bad: non-trivial destructor
  ```sh
    const std::string kFoo = "foo";

    // bad for the same reason, even though kBar is a reference (the
    // rule also applies to lifetime-extended temporary objects)
    const std::string& kBar = StrCat("a", "b", "c");

    void bar() {
      // bad: non-trivial destructor
      static std::map<int, int> kData = {{1, 0}, {2, 0}, {3, 0}};
    }
  ```
Decision on initialization( Sự khởi tạo )
- Khởi tạo indeterminate ̣(không xác định) : ( Trừ khởi tạo đầu tiên ).
  ```sh
    int n = 5;    // fine
    int m = f();  // ? (depends on f)
    Foo x;        // ? (depends on Foo::Foo)
    Bar y = g();  // ? (depends on g and on Bar::Bar)`
  ```
- Khời tạo constant ( Xác định ).
  ```sh
    struct Foo { constexpr Foo(int) {} };

    int n = 5;  // fine, 5 is a constant expression
    Foo x(2);   // fine, 2 is a constant expression and the chosen    constructor is constexpr
    Foo a[] = { Foo(1), Foo(2), Foo(3) };  // fine
  ```
- Khởi tạo có vấn đề .
  ```sh
    // Some declarations used below.
    time_t time(time_t*);      // not constexpr!
    int f();                   // not constexpr!
    struct Bar { Bar() {} };

    // Problematic initializations.
    time_t m = time(nullptr);  // initializing expression not a constant expression
    Foo y(f());                // ditto
    Bar b;                     // chosen constructor Bar::Bar() not constexpr
  ```
- Khởi tạo biến động ( Không khuyến khích khởi tạo biến động, nối chung là cấm , tuy nhiên cho phép khởi tạo động nếu nếu qúa trình khởi tạo của nó không ảnh hưởng tới các khởi tạo khác )
  ```sh
    int p = getpid();  // allowed, as long as no other static variable
      // uses p in its own initialization
  ```
```sh
```
### <> _Thread_local Variables_
Các biến thread_local không được khai báo bên trong một hàm mà được khởi tạo bằng mộ́t hằng số thời gian biên dịch thực sự và điều này thực thi bằng việc sử dụng các thuộc tính ABSL_CONST_INIT.
  ```sh
    ABSL_CONST_INIT thread_local Foo foo = ...;
  ```
```sh
```

## _Classes:_
### <> _Doing Work in Constructors_
  - Có thể thực hiện khởi tạo tuỳ ý ở bất kì đâu trong Constructors .
    > Constructor :  là một loại hàm thành viên đặc biệt của class, được gọi tự động khi một đối tượng của class đó được khởi tạo. Các constructors thường được sử dụng để khởi tạo các biến thành viên của class theo các giá trị mặc định phù hợp hoặc do người dùng cung cấp, hoặc để thực hiện bất kỳ các bước thiết lập cần thiết nào cho class (ví dụ: Mở file hoặc cơ sở dữ liệu).
```sh
```
### <> _Implicit Conversions_
  - Implicit Conversions ̣(Chuyển đổi ngầm định) : Cho phép Một đối tưởđng của một lọai (called the source type)  được sử dụng một loạui khác (called the destination type) . Giống như truyền cho một số kiểu số int cho function chứa biến double.
  > Read more: https://google.github.io/styleguide/cppguide.html#Implicit_Conversions
```sh
```
### <> _Copyable and Movable Types_
  - <>
    > Read more : https://google.github.io/styleguide/cppguide.html#Copyable_Movable_Types
```sh
```

## _Structs vs. Classes:_
Struct được sử dụng cho object thụ động để chứa data. Struct and Class hoạt động giống nhau trong c++.
  - Define naming rules :
    ```sh
      std::string table_name;  // OK - lowercase with underscore.
      std::string tableName;   // Bad - mixed case.
    ```
### <> _Structs vs. Pairs and Tuples_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Structs_vs._Tuples
### <> _Inheritance_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Inheritance
### <> _Operator Overloading_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Operator_Overloading
### <> _Access Control_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Access_Control
### <> _Declaration Order_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Declaration_Order

## _Function :_
### <> _Inputs and Outputs_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Inputs_and_Outputs
### <> _Write Short Functiond_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Write_Short_Functions
### <> _Function Overloading_
Bạn có thể viết function có const std::String& và overload với const char*
  - Ví dụ:
    ```sh
      class MyClass {
      public:
        void Analyze(const std::string &text);
        void Analyze(const char *text, size_t textlen);
      };
    ```
    > Read more : https://google.github.io/styleguide/cppguide.html#Function_Overloading
### <> _Default Arguments_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Default_Arguments
### <> _Trailing Return Type Syntax_
C++ chấp nhận hai different forms of function declarations
  - Ví dụ :
    ```sh
      int foo(int x);
      // Tương đương với <>
      auto foo(int x) -> int;

      // template:
      template <typename T, typename U>
      auto add(T t, U u) -> decltype(t + u);

      template <typename T, typename U>
      decltype(declval<T&>() + declval<U&>()) add(T t, U u);
    ```
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#trailing_return

## _Google-Specific Magic :_
### <> _Ownership and Smart Pointers_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Ownership_and_Smart_Pointers
### <> _cpplint_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#cpplint



## _Other C++ Features :_
### <> _Rvalue References_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Rvalue_references
### <> _Friends_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Friends
### <> _Exceptions_
  - <>
    > read more: https://google.github.io/styleguide/cppguide.html#Exceptions
### <> _noexcept_
  - <>
    > read more: https://google.github.io/styleguide/cppguide.html#noexcept
### <> _Run-Time Type Information (RTTI)_
  - Wrong track
    ```sh
      if (typeid(*data) == typeid(D1)) {
        ...
      } else if (typeid(*data) == typeid(D2)) {
        ...
      } else if (typeid(*data) == typeid(D3)) {
        ...
    ```
  - <>
    > read more: https://google.github.io/styleguide/cppguide.html#Run-Time_Type_Information__RTTI_
### <> _Casting_
  - <>
    > read more: https://google.github.io/styleguide/cppguide.html#Casting
### <> _Stream_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Streams
### <> _Preincrement and Predecrement_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Preincrement_and_Predecrement
### <> _Use of const :_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Use_of_const
### <> _Use of constexpr_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Use_of_constexpr
### <> _Integer Types_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Integer_Types
### <> _64-bit Portability_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#64-bit_Portability
### <> _Preprocessor Macros_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Preprocessor_Macros
### <> _and nullptr/NULL_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#0_and_nullptr/NULL
### <> _sizeof_
Ưu tiên thay thế sizeof(varname) bằng sizeof(type)
  - Sizeof(varname): Sử dụng khi cần lấy kích thước của một biến cụ thể,  sizeof(varname) sẽ update lại nếu có bấy kì thay đổi nào về type cũa biết hiện hành hoặc sau đó .
  - Sizeof(type): Sử dụng cho code không liên quan tới biến cụ thể nào.
  - ví dụ :
    ```sh
      // it ok
      MyStruct data;
      memset(&data, 0, sizeof(data));

      // not ok
      memset(&data, 0, sizeof(MyStruct));

      if (raw_size < sizeof(int)) {
        LOG(ERROR) << "compressed record not big enough for count: " << raw_size;
        return false;
      }
    ```
```sh
```
### <> _Type Deduction (including auto)_
Sử dụng khi và chỉ khi nó giúp code trở nên dễ đọc hơn chi người đọc hoặc giúp code được safer, traśnh sử dụng đơn thuần tránh viết một cách không rõ ràng.
  - Function template argument deduction: Hàm vẫn dc gọi với không có đối số rõ ràng
    ```sh
      template <typename T>
      void f(T t);

      f(0);  // Invokes f<int>(0)
    ```
  - Auto variable declarations : Khởi tạo biến động với đối số tự động theo rules.
    ```sh
      auto a = 42;  // a is an int
      auto& b = a;  // b is an int&
      auto c = b;   // c is an int
      auto d{42};   // d is an int, not a std::initializer_list<int>
    ```
  - Function return type deduction: Return kiểu dữ liệu tự động
    ```sh
      auto f() { return 0; }  // The return type of f is int
    ```
  - Generic lambdas:
    > A lambda : Lambda hay còn gọi là hàm nặc danh, nó có thể dùng để truyền vào 1 hàm khác và sử dụng 1 lần. Khác với các cách thông thường, định nghĩa hàm sau đó dùng tên hàm truyền vào 1 hàm khác.
   thức lambda (hàm) vào hàm khác
      >> Read more : https://www.stdio.vn/modern-cpp/c-11-lambda-8kmLy1
    ```sh
      // Sort `vec` in decreasing order
      std::sort(vec.begin(), vec.end(), [](auto lhs, auto rhs) { return lhs > rhs; });
    ```
  - Lambda init captures :
    > Capture:
      1. "[]"	 Không được phép sử dụng bất kỳ biến bên ngoài
      2. "[=]"	Được phép sử dụng các biến bên ngoài, nhưng là dạng sao chép giá trị của 3.biến đó (by value)
      3. "[&]"	Được phép sử dụng chính biến đó (by reference)
      4. "[=,&a]"	Đây là 1 dạng nâng cao, có thể cho phép tất cả các biến khác được sử dụng giá trị, và chỉ định thêm cho biến a được sử dụng chính nó (by reference)
      5. "[this]"	Cho phép sử dụng this (OOP) như 1 bản sao, có thể thử các dạng capture trên
    ```sh
      [x = 42, y = "foo"] { ... }  // x is an int, and y is a const char*
    ```
  - Class template argument deduction and Structured bindings
     ```sh
      auto [iter, success] = my_map.insert({key, value});
      if (!success) {
        iter->second = value;
      }
     ```
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Type_deduction
### <> _Class Template Argument Deduction_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#CTAD
### <> _Designated Initializers_
  - <>
  ```sh
    struct Point {
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
    };

    Point p = {
      .x = 1.0,
      .y = 2.0,
      // z will be 0.0
    };
  ```
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Designated_initializers
### <> _Lambda Expressions_
  - <>
    > read more: https://google.github.io/styleguide/cppguide.html#Lambda_expressions
### <> _Template Metaprogramming_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Template_metaprogramming
### <> _Boost_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Boost
### <> _Other C++ Features_
  - <>
    > read more: https://google.github.io/styleguide/cppguide.html#Other_Features
### <> _Nonstandard Extensions_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Nonstandard_Extensions
### <> _Aliases_
Đặt tên theo bí danh của thực thể khác
  - Ví dụ :
    ```sh
      typedef Foo Bar;
      using Bar = Foo;
      using other_namespace::Foo;
    ```
  - Vị dụ :
    ```sh
      // It is OK
      namespace mynamespace {
      // Used to store field measurements. DataPoint may change from Bar* to some internal type.
      // Client code should treat it as an opaque pointer.
      using DataPoint = ::foo::Bar*;

      // A set of measurements. Just an alias for user convenience.
      using TimeSeries = std::unordered_set<DataPoint, std::hash<DataPoint>, DataPointComparator>;
      }  // namespace mynamespace

      // Not ok
      namespace mynamespace {
      // Bad: none of these say how they should be used.
      using DataPoint = ::foo::Bar*;
      using ::std::unordered_set;  // Bad: just for local convenience
      using ::std::hash;           // Bad: just for local convenience
      typedef unordered_set<DataPoint, hash<DataPoint>, DataPointComparator> TimeSeries;
      }  // namespace mynamespace
    ```
  - Using in .cc file
    ```sh
      // In a .cc file
      using ::foo::Bar;
    ```
### <> _Inclusive Language_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Inclusive_Language
```sh
```

## _Naming_
### <> _General Naming Rules_
  - Do
    ```sh
      class MyClass {
      public:
        int CountFooErrors(const std::vector<Foo>& foos) {
          int n = 0;  // Clear meaning given limited scope and context
          for (const auto& foo : foos) {
            ...
            ++n;
          }
          return n;
        }
        void DoSomethingImportant() {
          std::string fqdn = ...;  // Well-known abbreviation for Fully Qualified Domain Name
        }
      private:
        const int kMaxAllowedConnections = ...;  // Clear meaning within context
      };
    ```
  - Not Do
    ```sh
      class MyClass {
      public:
        int CountFooErrors(const std::vector<Foo>& foos) {
          int total_number_of_foo_errors = 0;  // Overly verbose given limited scope and context
          for (int foo_index = 0; foo_index < foos.size(); ++foo_index) {  // Use idiomatic `i`
            ...
            ++total_number_of_foo_errors;
          }
          return total_number_of_foo_errors;
        }
        void DoSomethingImportant() {
          int cstmr_id = ...;  // Deletes internal letters
        }
      private:
        const int kNum = ...;  // Unclear meaning within broad scope
      };
    ```
  - <>
    > Read More: https://google.github.io/styleguide/cppguide.html#General_Naming_Rules
### <> _File Names_
  - Do
    ```sh
      // classes and structs
      class UrlTable { ...
      class UrlTableTester { ...
      struct UrlTableProperties { ...

      // typedefs
      typedef hash_map<UrlTableProperties *, std::string> PropertiesMap;

      // using aliases
      using PropertiesMap = hash_map<UrlTableProperties *, std::string>;

      // enums
      enum class UrlTableError { ...
          ```
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Type_Names
### <> _Variable Names_
  - Common Variable names
    ```sh
      // OK - lowercase with underscore.
      std::string table_name;

      // Bad - mixed case.
      std::string tableName;
          ```
  - Class Data Members
    ```sh
      class TableInfo {
        ...
      private:
        std::string table_name_;  // OK - underscore at end.
        static Pool<TableInfo>* pool_;  // OK.
      };
    ```
  - Struct Data Members
    ```sh
      struct UrlTableProperties {
        std::string name;
        int num_entries;
        static Pool<UrlTableProperties>* pool;
      };
    ```
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Variable_Names
```sh
```
### <> _Constant Names_
  - <>
    ```sh
      const int kDaysInAWeek = 7;
      const int kAndroid8_0_0 = 24;  // Android 8.0.0
    ```
### <> _Function Names_
  - <>
    ```sh
      AddTableEntry()
      DeleteUrl()
      OpenFileOrDie()
    ```
### <> _Namespace Names_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Namespace_Names
### <> _Enumerator Names_
  - Do
    ```sh
      enum class UrlTableError {
        kOk = 0,
        kOutOfMemory,
        kMalformedInput,
      };
    ```
  - Not Do
    ```sh
      enum class AlternateUrlTableError {
        OK = 0,
        OUT_OF_MEMORY = 1,
        MALFORMED_INPUT = 2,
      };
    ```
### <> _Macro Names_
  - <>
    ```sh
      #define ROUND(x) ...
      #define PI_ROUNDED 3.0
    ```
### <> _Exceptions to Naming Rules_
  - <>
    ```sh
      bigopen()
      function name, follows form of open()
      uint
      typedef
      bigpos
      struct or class, follows form of pos
      sparse_hash_map
      STL-like entity; follows STL naming conventions
      LONGLONG_MAX
      a constant, as in INT_MAX
    ```
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Exceptions_to_Naming_Rules
### <> _Comments_
  - Comment Style
    > Read more : https://google.github.io/styleguide/cppguide.html#Comment_Style
  - File Comments
    - File Comments
    - File Contents
    > Read more: https://google.github.io/styleguide/cppguide.html#File_Comments
  - Class Comments
    ```sh
      // Iterates over the contents of a GargantuanTable.
      // Example:
      //    std::unique_ptr<GargantuanTableIterator> iter = table->NewIterator();
      //    for (iter->Seek("foo"); !iter->done(); iter->Next()) {
      //      process(iter->key(), iter->value());
      //    }
      class GargantuanTableIterator {
        ...
      };
    ```
    > Read more: https://google.github.io/styleguide/cppguide.html#Class_Comments
  - Function Comments
    - Function Declarations
    - Function Definitions
    > Read more: https://google.github.io/styleguide/cppguide.html#Function_Comments
  - Variable Comments
    - Class Data Members
    - Class Data Members
    > read more: https://google.github.io/styleguide/cppguide.html#Variable_Comments
  - Implementation Comments
    - Explanatory Comments
    > Read more: https://google.github.io/styleguide/cppguide.html#Implementation_Comments
  - Function Argument Comments
    > Read more: https://google.github.io/styleguide/cppguide.html#Function_Argument_Comments
  - Don'ts
    > Read more: https://google.github.io/styleguide/cppguide.html#Implementation_Comment_Donts
  - Punctuation, Spelling, and Grammar
    > Read more: https://google.github.io/styleguide/cppguide.html#Punctuation,_Spelling_and_Grammar
  - TODO Comments
    > Read more: https://google.github.io/styleguide/cppguide.html#TODO_Comments
  - <>
    > read more: https://google.github.io/styleguide/cppguide.html#Comments

## _Formatting_
### <> _Line Length_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Line_Length
### <> _Non-ASCII Characters_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Non-ASCII_Characters
### <> _Spaces vs. Tabs_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Spaces_vs._Tabs
### <> _Function Declarations and Definitions_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Function_Declarations_and_Definitions
### <> _Lambda Expressions_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Formatting_Lambda_Expressions
### <> _Floating-point Literals_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Floating_Literals
### <> _Function Calls_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Function_Calls
### <> _Braced Initializer List Format_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Braced_Initializer_List_Format
### <> _Conditionals_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Conditionals
### <> _Loops and Switch Statements_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Loops_and_Switch_Statements
### <> _Pointer and Reference Expressions_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Pointer_and_Reference_Expressions
### <> _Boolean Expressions_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Boolean_Expressions
### <> _Return Values_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Return_Values
### <> _Variable and Array Initialization_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Variable_and_Array_Initialization
### <> _Preprocessor Directives_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Preprocessor_Directives
### <> _Class Formart_
  - <>
    > Read more:  https://google.github.io/styleguide/cppguide.html#Class_Format
### <> _Constructor Initializer Lists_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Constructor_Initializer_Lists
### <> _Namespace Formatting_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Namespace_Formatting
### <> _Horizontal Whitespace_
  - General
    ```sh
      int i = 0;  // Two spaces before end-of-line comments.

      void f(bool b) {  // Open braces should always have a space before them.
        ...
      int i = 0;  // Semicolons usually have no space before them.
      // Spaces inside braces for braced-init-list are optional.  If you use them,
      // put them on both sides!
      int x[] = { 0 };
      int x[] = {0};

      // Spaces around the colon in inheritance and initializer lists.
      class Foo : public Bar {
      public:
        // For inline function implementations, put spaces between the braces
        // and the implementation itself.
        Foo(int b) : Bar(), baz_(b) {}  // No spaces inside empty braces.
    ```
  - Loops and Conditionals
    ```sh
      if (b) {          // Space after the keyword in conditions and loops.
      } else {          // Spaces around else.
      }
      while (test) {}   // There is usually no space inside parentheses.
      switch (i) {
      for (int i = 0; i < 5; ++i) {
      // Loops and conditions may have spaces inside parentheses, but this
      // is rare.  Be consistent.
      switch ( i ) {
      if ( test ) {
      for ( int i = 0; i < 5; ++i ) {
      // For loops always have a space after the semicolon.  They may have a space
      // before the semicolon, but this is rare.
      for ( ; i < 5 ; ++i) {
        ...

      // Range-based for loops always have a space before and after the colon.
      for (auto x : counts) {
        ...
      }
      switch (i) {
        case 1:         // No space before colon in a switch case.
          ...
        case 2: break;  // Use a space after a colon if there's code after it.
    ```
  - Operators
    ```sh
      // Assignment operators always have spaces around them.
      x = 0;

      // Other binary operators usually have spaces around them, but it's
      // OK to remove spaces around factors.  Parentheses should have no
      // internal padding.
      v = w * x + y / z;
      v = w*x + y/z;
      v = w * (x + z);

      // No spaces separating unary operators and their arguments.
      x = -5;
      ++x;
      if (x && !y)
        ...
    ```
  - Templates and Casts
    ```sh
      // No spaces inside the angle brackets (< and >), before
      // <, or between >( in a cast
      std::vector<std::string> x;
      y = static_cast<char*>(x);

      // Spaces between type and pointer are OK, but be consistent.
      std::vector<char *> x;
    ```
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Horizontal_Whitespace
### <> _Vertical Whitespace_
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Vertical_Whitespace
### <> _Exceptions to the Rules_
  - Existing Non-conformant Code
    > Read more: https://google.github.io/styleguide/cppguide.html#Existing_Non-conformant_Code
  - Windows Code
    > read more: https://google.github.io/styleguide/cppguide.html#Windows_Code
  - <>
    > Read more: https://google.github.io/styleguide/cppguide.html#Exceptions_to_the_Rules