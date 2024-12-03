# "Hello, Godbolt!"

## Compiling Online

The ability to quickly test and prototype software is extremely useful however, doing so
in C++ is not so easy. There's a lot of steps that need to be taken to setup a project
correctly which is good for building robust software but slows the speed of prototyping
down to a halt. Luckily there exists a tool that makes this processes much easier. It is
online C++ compiler known as Godbolt. This site allows you to compile C++ using many
different compilers; even at the same time, as well as execute the resulting binary and
even see the assembly generated from the compiler. It also allows you to share your
session with others so they can see not only the code you wrote but the exact
compiler(s), and flags you have set. It is a massively useful tool that is invaluable to
the C++ community. Here is an [example "Hello, world!" on Godbolt](https://www.godbolt.org/z/oPsdebsrh)
which shows the generated assembly as well as the output from the executed binary. You
can also see the godbolt instance embedded below.

<iframe width="800px" height="400px" src="https://www.godbolt.org/e#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:2,endLineNumber:7,positionColumn:2,positionLineNumber:7,selectionStartColumn:2,selectionStartLineNumber:7,startColumn:2,startLineNumber:7),source:'%23include+%3Ciostream%3E%0A%0Aauto+main()+-%3E+int%0A%7B%0A++++std::cout+%3C%3C+%22Hello,+world!!%5Cn%22%3B%0A++++return+0%3B%0A%7D'),l:'5',n:'0',o:'C%2B%2B+source+%231',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((g:!((h:compiler,i:(compiler:g132,filters:(b:'0',binary:'1',binaryObject:'1',commentOnly:'0',debugCalls:'1',demangle:'0',directives:'0',execute:'0',intel:'0',libraryCode:'0',trim:'1'),flagsViewOpen:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!(),options:'-std%3Dc%2B%2B20',overrides:!(),selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:1),l:'5',n:'0',o:'+x86-64+gcc+13.2+(Editor+%231)',t:'0')),k:50,l:'4',m:50,n:'0',o:'',s:0,t:'0'),(g:!((h:output,i:(compilerName:'x86-64+gcc+13.2',editorid:1,fontScale:14,fontUsePx:'0',j:1,wrap:'1'),l:'5',n:'0',o:'Output+of+x86-64+gcc+13.2+(Compiler+%231)',t:'0')),header:(),l:'4',m:50,n:'0',o:'',s:0,t:'0')),k:50,l:'3',n:'0',o:'',t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>

