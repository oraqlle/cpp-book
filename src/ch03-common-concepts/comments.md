# Comments

Comments are a way to document code for other people, and yourself. In C++ there are two
types of comments, single line and multi-line. We've seen single line comments in many of
the previous examples but to reiterate, a single line comment is started with `//` and
any text written after it until a newline is ignored by the compiler.

```cpp,icon=%cplusplus
// Comment on its own line

const auto x = 5; // Comment
```

Multi-line comments are specified using `/* */` *quoting* ie. the comment extends from
`/*` comment opener and continues until `*/`. This allows comments to extend multiple
lines or be nested amongst code (if you really want).

```cpp,icon=%cplusplus
/*
multi-line comment
another line
*/

const auto /* int */ x = 5;
```

