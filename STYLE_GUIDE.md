## Header Files:
  -use #define guards
  -use prototyping
  -include system libraries, then project header files

## Scope:
  - ok to use static variables
  - no global variables
  - ok to initialize variables
  - ok to use functions as parameters to other functions unless line is too long
  - no namespace declation

## Classes:
  - only use classes
  - use inheritance instead of composition
  - use multiple inheritence sparingly
  - access specifiers flush with rest of code
  - declare variables, then constructors, then function
  - private, protected, then public variables and functions

## Functions:
  - use output parameters sparingly
  - put output parameter after the input parameters
  - perfer references over pointers
  - use default arguments instead of overloaded functions

## Syntax:
  - 4 spaces
  - 1 empty line between each function definition
  - open brace on same line
  - 1 space between conditional and condition
  - 1 space between condition and open brace
  - no 1 line conditionals
  - spaces on either side of insertion/ extraction operator
  - function headers for every function (high-level description of function)
  - references attached to variable name
  - declare loop variable inside for loop
  - 1 space after commas
  - spaces before and after binary operators
  - no curley braces for one single line conditionals
  - lower camel case for functions and variables, upper camel case for classes/structs
  - use //TODO for unfinished code
