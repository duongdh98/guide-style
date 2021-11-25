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
