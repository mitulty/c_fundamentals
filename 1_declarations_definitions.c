/**
 * @author: Mitul Tyagi
 * @description: Declarations and Defintions in C
 */
/*
- In C, declarations are used to define the type and the scope of variables,
functions, and other identifiers. Declarations are typically made before using
the identifier, but can also be made after if the identifier is not used before
the declaration. There are two main types of declarations in C: type
declarations and function declarations. Type declarations specify the type of an
identifier, while function declarations specify the name, return type, and
parameters of a function.
        -> Type declarations can be made using int, char, float, double, struct,
           union, and enum keywords.
        -> Function declarations can be made using void, int, char, float,
           double, struct, union, and enum keywords, followed by the name of
           the function, a list of parameters, and a return type.
- Declaration is for the compiler to accept a name (to tell the compiler that
the name is legal, the name is introduced with intention not a typo). Definition
is where a name and its content is associated. The definition is used by the
linker to link a name reference to the content of the name.
- A declaration provides basic attributes of a symbol: its type and its name. A
definition provides all of the details of that symbol-- if it's a function, what
it does; if it's a class, what fields and methods it has; if it's a variable,
where that variable is stored. Often, the compiler only needs to have a
declaration for something in order to compile a file into an object file,
expecting that the linker can find the definition from another file. If no
source file ever defines a symbol, but it is declared, errors will be raised at
the linking time complaining about the undefined symbols.
- To use a function across multiple source files, declare the function in one
header file (.h) and then put the function definition in one source file
(.c or .cpp). All code that uses the function should include just the .h file,
and should link the resulting object files with the object file from compiling
the source file.
- To use a class/structure in multiple files, put its definition in a header
file and define the class methods in a corresponding source file.
- To use a variable in multiple files, put the declaration of the variable using
the extern keyword in one header file, and then include that header file in all
source files that need that variable. Then put the definition of that variable
in one source file that is linked with all the object files that use that
variable.
- Initialization is the process of assigning initial values to the variables. It
is also possible to initialize values to the variables in the declaration. It
goes only with the defintion.
- Variables and constant are the basic data objects manipulated in a program.
The variable names are made up of letters and digits, the first character must
be a letter. The underscore "_" counts as a letter. Uppercase and lowercase
letters are distinct.
- Atleast the first 31 characters of an internal names are significant. Keywords
can not be used as names and are reserved. They are always in lower case.
- A C program consits of a set of external objects, which are either variables
or functions. External variables are defined outside of any function, and are
thus potentially available to many functions. Functions themselves are
external, because C does not allow functions to be defined inside other
functions. By default, external variables and functions have the property that
all references to them by the same name, even from functions compiled
separately, are refrences to the same things. This is called external linkage.
They have greater scope and lifetime.
- The scope of a name is the part of the program within which the name can be
used. For an automatic variable declared at the beginning of a function, the
scope is the function in which the name is declared. Local variables of the same
name in different functions are unrelated. The scope of an external variable or
a function starts from the point at which it is declared to the end of the file
being compiled.
- If an external variable is to be referred to before it is defined, or it is
defined in a different source file from the one where it is being used, then an
extern declaration is mandatory.
- The static declaration, applied to an external variable or function, limits
the scope of that object to the rest of the source file being compiled. Internal
static variables are local to a particular function and remain in existence.
The internal static variables provide private, permanent storage within a single
function.
- A register declaration advises the compiler that the variable will be used
heavily. Thus they are placed in machine registers. It is not possible to take
the address of a register variable.
- External and static variables are guaranteed to be intialized zero in the
absence of explicit initialization. Automatic and register variables have
undefined intial values.
- For external and staic variables, the intializer must be a constant
expression; the initialization is done once, conceptually before the program
begins execution.
- For automatic and register variables, it is done each time the function or
block is entered. For automatic and register variables, the initializer is not
restricted to being a constant: it may be any expression involving previously
defined values, even function calls.
- A function declared as a static can not be used in multiple source files using
a common header file. If the static function defintion and declaration is in the
header file then that function can be used in multiple source files. In this
case each source file has a separate function object at different locations. But
if the header file only contains the declaration and not the definition then
this will result in the error.
*/
#include <stdint.h>
#include <stdio.h>

int x;        // Both a decalaration and a definition.
extern int y; // declaration
extern int z; // declaration
int main(int argc, char const *argv[])
{
   x = 10;
   y = 35;
   int za = 123;
   // z = 100; // Error: undefined reference to 'z'
   printf("%d, %d, %d & %d\n", x, y, za, z);
   return 0;
}

int y; // Both a declaration and a definition
int z = 10; // Both a declaration and a definition