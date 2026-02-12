# Access Modifiers

Access modifiers allow you to control which members of a structure can be accessed by
other parts of a program. The three access categories for members are `public`, `private`
and `protected`.

## Public

<!-- Description -->
<!-- example -->
ABC

## Private

ABC

## Protected

ABC

## The `class` keyword

Up until this point, anyone who already knows a bit about C++ is likely questioning when
I'll bring up classes in C++; after all, "C++ is just C with classes" no? From a certain
perspective this is true but as with many things, it is more nuanced.

C++ does have a keyword `class` which is used to define a (class) type however, this
keyword and the resulting defined type are functionally equivalent those declared using
the `struct` keyword ... baring a few differences in how members are access by default.

Types declared with the `struct` keyword are *open* or `public` by default meaning all
members can be freely accessed and modified (provided the member is not `const`). Types
declared with the `class` keyword are *closed* or `private` by default, with members only
being accessible within the type itself.

> [!NOTE]
> You can still specify certain sections of a type definition to be `public`, `private`
> or `protected` as discussed in the open section of this page; regardless of whether
> it was declared using `struct` or `class`. Just remember that the default access
> category is applied to all parts of the type declaration until the first explicit
> access modifier is set.
>
> ```cxx
> struct A {
> // public
>      int x;
>      int y;
>      int z;
>
>  private:
>      int z;
> };
>
> // vs ...
>
> class B {
> // private
>      int x;
>      int y;
>      int z;
>
>  public:
>      int z;
> };
> ```
