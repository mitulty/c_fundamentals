/**
 * @author: Mitul Tyagi
 * @description: Attributes in C
 */
/*
- GCC provides a rich set of function, variable, and type attributes that allow developers to specify various properties and behaviors beyond what's available
  in standard C. GCC Attributes are used to add various annotations to code outside of the basic source language that assist the compiler.
- The keyword __attribute__ allows to specify special attributes when making a declaration. This keyword is followed by an attribute specification inside
  double parentheses.
- The attributes can be specified with __ preceding and following each keyword. This allows to use them in header files without being concerned
  about a possible macro of the same name. Also the attributes can be placed freely. There is also a user attribute that is not interpreted by the compiler
  but can be used by plugins and static analyses.
- The following attributes are currently defined for functions on all targets: noreturn, noinline, always_inline, pure, const, nothrow,
  format, format_arg, no_instrument_function, section, constructor, destructor, used, unused, deprecated, weak, malloc, alias, warn_unused_result and nonnull.
- Several other attributes are defined for functions on particular target systems. Other attributes, including section are supported for variables declarations
  and for types.
- Some of the common attributes for the functions are:
        - The noreturn keyword tells the compiler to assume that fatal cannot return. It can then optimize without regard to what would happen if fatal ever
          did return. This makes slightly better code. More importantly, it helps avoid spurious warnings of uninitialized variables.
        - noinline: This function attribute prevents a function from being considered for inlining.
        - always_inline: Generally, functions are not inlined unless optimization is specified. For functions declared inline, this attribute inlines the
          function even if no optimization level was specified.
        - pure: Many functions have no effects except the return value and their return value depends only on the parameters and/or global variables. Such a
          function can be subject to common subexpression elimination and loop optimization just as an arithmetic operator would be. These functions should be
          declared with the attribute pure. For example:
                                                        int square (int) __attribute__ ((pure));
          says that the hypothetical function square is safe to call fewer times than the program says. Some of common examples of pure functions are strlen or
          memcmp. Interesting non-pure functions are functions with infinite loops or those depending on volatile memory or other system resource, that may
          change between two consecutive calls (such as feof in a multithreading environment).
        - section("section-name"): Normally, the compiler places the code it generates in the text section. Sometimes, however, code need additional sections or
          certain particular functions to appear in special sections. The section attribute specifies that a function lives in a particular section. For
          example, the declaration:
                        extern void foobar (void) __attribute__ ((section ("bar")));
          puts the function foobar in the bar section.
        - unused: This attribute, attached to a function, means that the function is meant to be possibly unused. GCC will not produce a warning for this
          function.
        - used: This attribute, attached to a function, means that code must be emitted for the function even if it appears that the function is not referenced.
          This is useful, for example, when the function is referenced only in inline assembly.
        - deprecated: The deprecated attribute results in a warning if the function is used anywhere in the source file. This is useful when identifying
          functions that are expected to be removed in a future version of a program. The warning also includes the location of the declaration of the
          deprecated function, to enable users to easily find further information about why the function is deprecated, or what they should do instead.
          Note that the warnings only occurs for uses:
                                int old_fn () __attribute__ ((deprecated));
                                int old_fn ();
                                int (*fn_ptr)() = old_fn;
          results in a warning on line 3 but not line 2.
        - weak: The weak attribute causes the declaration to be emitted as a weak symbol rather than a global. This is primarily useful in defining library
          functions which can be overridden in user code, though it can also be used with non-function declarations. Weak symbols are supported for ELF targets,
          and also for a.out targets when using the GNU assembler and linker.
        - naked: Use this attribute on the ARM, AVR, C4x and IP2K ports to indicate that the specified function does not need prologue/epilogue sequences
          generated by the compiler. It is up to the programmer to provide these sequences.
- Attributes can be used to specify various special properties of types. Some type attributes apply only to structure and union types, and in C++, also class
  types, while others can apply to any type defined via a typedef declaration. Unless otherwise specified, the same restrictions and effects apply to attributes
  regardless of whether a type is a trivial structure or a C++ class with user-defined constructors, destructors, or a copy assignment.
- Programmer may specify type attributes in an enum, struct or union type declaration or definition by placing them immediately after the struct, union or enum
  keyword. Programmer can also place them just past the closing curly brace of the definition, but this is less preferred because logically the type should be
  fully defined at the closing brace. Programmer can also include type attributes in a typedef declaration.
- The following type attributes are supported on most targets:
        - aligned (alignement): The aligned attribute specifies a minimum alignment (in bytes) for variables of the specified type. When specified, alignment
          must be a power of 2. Specifying no alignment argument implies the maximum alignment for the target, which is often, but by no means always, 8 or 16
          bytes. For example, the declarations:
                                struct __attribute__ ((aligned (8))) S { short f[3]; };
                                typedef int more_aligned_int __attribute__ ((aligned (8)));
          force the compiler to ensure (as far as it can) that each variable whose type is struct S or more_aligned_int is allocated and aligned at least on
          a 8-byte boundary. On a SPARC, having all variables of type struct S aligned to 8-byte boundaries allows the compiler to use the ldd and std
          (doubleword load and store) instructions when copying one variable of type struct S to another, thus improving run-time efficiency. The alignment of
          any given struct or union type is required by the ISO C standard to be at least a perfect multiple of the lowest common multiple of the alignments of
          all of the members of the struct or union in question. This means that you can effectively adjust the alignment of a struct or union type by attaching
          an aligned attribute to any one of the members of such a type, but the notation illustrated in the example above is a more obvious, intuitive, and
          readable way to request the compiler to adjust the alignment of an entire struct or union type.
        - packed: This attribute, attached to a struct, union, or C++ class type definition, specifies that each of its members (other than zero-width
          bit-fields) is placed to minimize the memory required. This is equivalent to specifying the packed attribute on each of the members. When attached to
          an enum definition, the packed attribute indicates that the smallest integral type should be used. Specifying the -fshort-enums flag on the command
          line is equivalent to specifying the packed attribute on all enum definitions.
        - designated_init: This attribute may only be applied to structure types. It indicates that any initialization of an object of this type must use
          designated initializers rather than positional initializers. The intent of this attribute is to allow the programmer to indicate that a structure’s
          layout may change, and that therefore relying on positional initialization will result in future breakage. GCC emits warnings based on this attribute
          by default; use -Wno-designated-init to suppress them.
        - deprecated (msg): The deprecated attribute results in a warning if the type is used anywhere in the source file.
        - unavailable (msg): The unavailable attribute behaves in the same manner as the deprecated one, but emits an error rather than a warning. It is used
          to indicate that a (perhaps previously deprecated) type is no longer usable. The unavailable attribute can also be used for functions and variables.
        - unused: When attached to a type (including a union or a struct), this attribute means that variables of that type are meant to appear possibly unused.
          GCC does not produce a warning for any variables of that type, even if the variable appears to do nothing. This is often the case with lock or thread
          classes, which are usually defined and then not referenced, but contain constructors and destructors that have nontrivial bookkeeping functions.
- Attributes can be used to specify properties for variables too. Some of the common variable attributes supported on all platforms are:
        - alias ("target"): The alias variable attribute causes the declaration to be emitted as an alias for another symbol known as an alias target. Except
          for top-level qualifiers the alias target must have the same type as the alias.
        - aligned (alignment): The aligned attribute specifies a minimum alignment for the variable or structure field, measured in bytes. When specified,
          alignment must be an integer constant power of 2. Specifying no alignment argument implies the maximum alignment for the target, which is often, but
          by no means always, 8 or 16 bytes. Programmer can also specify the alignment of structure fields. GCC also provides a target specific macro
          __BIGGEST_ALIGNMENT__, which is the largest alignment ever used for any data type on the target machine you are compiling for.
        - deprecated (msg): The deprecated attribute results in a warning if the variable is used anywhere in the source file. This is useful when identifying
          variables that are expected to be removed in a future version of a program. The warning also includes the location of the declaration of the
          deprecated variable, to enable users to easily find further information about why the variable is deprecated, or what they should do instead.
        - packed: The packed attribute specifies that a structure member should have the smallest possible alignment—one bit for a bit-field and one byte
          otherwise, unless a larger value is specified with the aligned attribute. The attribute does not apply to non-member objects.
        - section ("section-name"): Normally, the compiler places the objects it generates in sections like data and bss. Sometimes, however, programmer needs
          additional sections, or certain particular variables to appear in special sections, for example to map to special hardware. The section attribute
          specifies that a variable (or function) lives in a particular section.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int x __attribute__((aligned(16))) = 0; /*causes the compiler to allocate the global variable x on a 16-byte boundary.*/
int var_target;
extern int __attribute__((alias("var_target"))) var_alias;
short array[3] __attribute__((aligned(__BIGGEST_ALIGNMENT__)));
extern int old_var __attribute__((deprecated));
extern int old_var;
int new_fn() { return old_var; }
struct foo
{
  int x[2] __attribute__((aligned(8)));
};
int a __attribute__((section("DUART_A"))) = 0;
int b __attribute__((section("DUART_B"))) = 0;
char stack[10000] __attribute__((section("STACK"))) = {0};
int init_data __attribute__((section("INITDATA")));
struct bar
{
  char a;
  int x[2] __attribute__((packed));
};
__attribute__((user("foo"))) int f();
int __attribute__((user("foo"))) g();
int h() __attribute__((user("foo")));

__attribute__((user("foo"))) int n;
int __attribute__((user("foo"))) m;
int o __attribute__((user("foo")));
void fatal() __attribute__((noreturn));
void fatal()
{
  exit(1);
}
struct __attribute__((aligned)) S
{
  short f[3];
};

struct __attribute__((aligned(8))) T
{
  short f[3];
};
typedef int more_aligned_int __attribute__((aligned(8)));

struct my_unpacked_struct
{
  char c;
  int i;
};

struct __attribute__((__packed__)) my_packed_struct
{
  char c;
  int i;
  struct my_unpacked_struct s;
};

int main(int argc, char const *argv[])
{
  /* Initialize stack pointer */
  init_sp(stack + sizeof(stack));
}