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
