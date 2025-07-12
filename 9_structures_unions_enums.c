/**
 * @author: Mitul Tyagi
 * @description: Structures, Unions and Enums in C
 */
/*
- A structure is a collection of one or more variables, possibly of different
types, grouped together under a single name for convenient handling. The keyword
struct introduces a structure declaration, which is a list of declarations
enclosed in braces. An optional name called a structure tag may follow the word
struct. The tag names this kind of structure, and can be used subsequently as
a shorthand for the part of the declaration in braces. The variables named in a
structure are called members. A struct declaration defines a type. The right
brace that ends the list of members may be followed by a list of variables.
            struct {..........} x,y,z;
- A structure declaration that is not followed by a list of variables reserves
no storage; it merely describes a template or the shape of a structure. If the
declaration is tagged, however, the tag can be used later in definitions of
instances of the structure. A structure can be intialized by following its
definition with a list of intializers, each a constant expression. An
automatic structure may also be intialized by assignment or by calling a
function that returns a structure of the right type.
- A member of a particular structure is referred to in an expression by the dot
operator. The syntax is "structure_name.member"
- Structers can be nested. C language allows us to insert one structure into
another as a member. This process is called nesting and such structures are
called nested structures. There are two ways in which we can nest one structure
into another:
    1. Embedded Structure Nesting: In this method, the structure being nested is
       also declared inside the parent structure.
    2. Separate Structure Nesting: In this method, two structures are declared
       separately and then the member structure is nested inside the parent
       structure.
- To access the nested members use the (.) dot operator two times.
                        str_parent.str_child.member;
- The only legal operations on a structure are copying it or assigning to it as
a unit, taking its address with &, and accessing its members. Copy and
assignment include passing arguments to functions and returning values from
functions as well. They may not be compared. A structure may be initialized by a
list of constant member values; an automatic structure may also be intialized
by an assignment.
- Structure parameters are passed by value. If a large structure is to be passed
to a function, it is generally more efficient to pass a pointer than to copy the
whole structure. A structure can contain an array as one of its member. Also an
array of structures can be formed.
- Size of a structure need not be equal to the sum of the size of individual
arrays. Because of alignment requirements for different architectures, there may be
unnamed "holes" in a structure. The sizeof operator returns the proper value.
- The self-referential structures in C are those structures that contain
references to the same type as themselves i.e. they contain a member of the type
pointer pointing to the same structurebtype.
                            struct structure_name {
                                data_type member1;
                                data_type member2;
                                struct structure_name* str;
                            };
- Technically, the size of the structure in C should be the sum of the sizes of
its members. But it may not be true for most cases. The reason for this is
Structure Padding. Structure padding is the concept of adding multiple empty
bytes in the structure to naturally align the data members in the memory. It is
done to minimize the CPU read cycles to retrieve different data members in the
structure. There are some situations where we need to pack the structure tightly
by removing the empty bytes. In such cases, we use Structure Packing. C language
provides two ways for structure packing:
                    -> Using #pragma pack(1)
                    -> Using __attribute((packed))__
- Bit Fields are used to specify the length of the structure members in bits. If
the maximum length of the member is known, then the bit fields can be used to
specify the size and reduce memory consumption. The address of the bit field cannot
be taken using the &. The syntax for defining a bit field is:
                            struct structure_name {
                                data_type member_name: width_of_bit-field;
                            };
- The Union is a user-defined data type in C language that can contain elements
of the different data types just like structure. But unlike structures, all the
members in the C union are stored in the same memory location. Due to this, only
one member can store data at the given instance.
                            union union_name {
                                datatype member1; datatype member2;
                                ...
                            };
- To access the members of a union the (.) dot operator is used, just like
structures. This works for nested unions.
- The initialization of a union is the initialization of its members by simply
assigning the value to it. Only one member can obtain some value at a given
instance of time.
                    var1.member1 = some_value;
- The size of the union will always be equal to the size of the largest member
of the array. All the less-sized elements can store the data in the same space
without any overflow.
- Enumeration (or enum) is a user defined data type in C. It is mainly used to
assign names to integral constants, the names make a program easy to read and
maintain.
                  enum flag{constant1, constant2, constant3, ....... };
- Variables of type enum can also be defined. Enums follow scope rules. Enum
variables are automatically assigned values.
- Two enum names can have same value.
- If no values are explicitly assigned to enum names, then the compiler by
default assigns values starting from 0.
- Values can be assigned to some name in any order. All unassigned names get
value as a value of previous name plus one.
- The value assigned to enum names must be some integral constant, i.e., the
value must be in range from minimum possible integer value to maximum possible
integer value.
- All enum constants must be unique in their scope.
*/
#include <stdint.h>
#include <stdio.h>
// child structure declaration
struct child
{
        int x;
        char c;
};

// parent structure declaration
struct parent
{
        int a;
        struct child b;
};
// declaring structure with name str1
struct str1
{
        int i;
        char c;
        float f;
        char s[30];
};

// declaring structure with name str2
struct str2
{
        int ii;
        char cc;
        float ff;
} var; // variable declaration with structure template

// defining structure
struct str3
{
        int a;
};

// defining new name for str3
typedef struct str3 strthree;

// another way of using typedef with structures
typedef struct str4
{
        int x;
} str4;
// structure with padding
struct str5
{
        char c;
        int i;
};

struct str6
{
        char c;
        int i;
} __attribute((packed)) __; // using structure packing

// structure with bit fields
struct str7
{
        int a : 24; // size of 'a' is 3 bytes = 24 bits
        char c;
};

// union template or declaration
union un
{
        int member1;
        char member2;
        float member3;
};
// declaring multiple unions
union test1
{
        int x;
        int y;
} Test1;

union test2
{
        int x;
        char y;
} Test2;

union test3
{
        int arr[10];
        char y;
} Test3;
enum week
{
        Mon,
        Tue,
        Wed,
        Thur,
        Fri,
        Sat,
        Sun
};

enum state
{
        Working = 2,
        Failed = 3,
        Idle = 2,
        Freezed = 0,
        Ready // Value of ready will be 1
};
int main(int argc, char const *argv[])
{
        // variable declaration after structure template
        // initialization with initializer list and designated
        //    initializer list
        struct str1 var1 = {1, 'A', 1.00, "GeeksforGeeks"}, var2;
        struct str2 var3 = {.ff = 5.00, .ii = 5, .cc = 'a'};

        // copying structure using assignment operator
        var2 = var1;

        printf("Struct 1:\n\ti = %d, c = %c, f = %f, s = %s\n", var1.i, var1.c,
               var1.f, var1.s);
        printf("Struct 2:\n\ti = %d, c = %c, f = %f, s = %s\n", var2.i, var2.c,
               var2.f, var2.s);
        printf("Struct 3\n\ti = %d, c = %c, f = %f\n", var3.ii, var3.cc, var3.ff);
        // creating structure variables using new names
        strthree var4 = {20};
        str4 var5 = {314};

        printf("var4.a = %d\n", var4.a);
        printf("var5.x = %d\n", var5.x);
        struct parent var6 = {25, 195, 'A'};

        // accessing and printing nested members
        printf("var6.a = %d\n", var6.a);
        printf("var6.b.x = %d\n", var6.b.x);
        printf("var6.b.c = %c\n", var6.b.c);
        printf("Size of str5: %lu\n", sizeof(struct str5));
        printf("Size of str6: %lu\n", sizeof(struct str6));
        printf("Size of Str7: %lu\n", sizeof(struct str7));

        // defining a union variable
        union un varun1;

        // initializing the union member
        varun1.member1 = 297;

        printf("The value stored in member1 = %d\n", varun1.member1);
        printf("The value stored in member2 = %c\n", varun1.member2);
        printf("The value stored in member3 = %f\n", varun1.member3);

        // initializing the union member
        varun1.member3 = 97.00;

        printf("The value stored in member1 = %d\n", varun1.member1);
        printf("The value stored in member2 = %c\n", varun1.member2);
        printf("The value stored in member3 = %f\n", varun1.member3);
        // finding size using sizeof() operator
        int size1 = sizeof(Test1);
        int size2 = sizeof(Test2);
        int size3 = sizeof(Test3);

        printf("Sizeof test1: %d\n", size1);
        printf("Sizeof test2: %d\n", size2);
        printf("Sizeof test3: %d\n", size3);

        enum week day;
        day = Wed;
        printf("day: %d\n", day);

        return 0;
}
/*
Struct 1:
        i = 1, c = A, f = 1.000000, s = GeeksforGeeks
Struct 2:
        i = 1, c = A, f = 1.000000, s = GeeksforGeeks
Struct 3
        i = 5, c = a, f = 5.000000
var4.a = 20
var5.x = 314
var6.a = 25
var6.b.x = 195
var6.b.c = A
Size of str5: 8
Size of str6: 5
Size of Str7: 4
The value stored in member1 = 297
The value stored in member2 = )
The value stored in member3 = 0.000000
The value stored in member1 = 1120010240
The value stored in member2 =
The value stored in member3 = 97.000000
Sizeof test1: 4
Sizeof test2: 4
Sizeof test3: 40
day: 2
*/
