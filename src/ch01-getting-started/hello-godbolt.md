# "Hello, Godbolt!"

The ability to quickly test and prototype software is extremely useful however, doing so
in C++ is not so easy. There's a lot of steps that need to be taken to setup a project
correctly which is good for building robust software but can slow the speed of
prototyping down to a halt. Luckily there exists a platform called Compiler Explorer also
known as Godbolt; which allows you to build sharable C++ programs in the browser. Here is
an [example "Hello, world!" on Godbolt](https://www.godbolt.org/z/zxdYnKWqd) which shows
the generated assembly as well as the output from the executed binary. You can also see
the godbolt instance embedded below.

<iframe width="800px" height="400px" src="https://www.godbolt.org/e#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:20,endLineNumber:3,positionColumn:20,positionLineNumber:3,selectionStartColumn:20,selectionStartLineNumber:3,startColumn:20,startLineNumber:3),source:'%23include+%3Ciostream%3E%0A%0Aauto+main()+-%3E+int+%7B%0A++++std::cout+%3C%3C+%22Hello,+world!!%5Cn%22%3B%0A++++return+0%3B%0A%7D'),l:'5',n:'0',o:'C%2B%2B+source+%231',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((g:!((h:compiler,i:(compiler:g143,filters:(b:'0',binary:'1',binaryObject:'1',commentOnly:'0',debugCalls:'1',demangle:'0',directives:'0',execute:'0',intel:'0',libraryCode:'0',trim:'1',verboseDemangling:'0'),flagsViewOpen:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!(),options:'-std%3Dc%2B%2B17',overrides:!(),selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:1),l:'5',n:'0',o:'+x86-64+gcc+14.3+(Editor+%231)',t:'0')),k:50,l:'4',m:50,n:'0',o:'',s:0,t:'0'),(g:!((h:output,i:(compilerName:'x86-64+gcc+13.2',editorid:1,fontScale:14,fontUsePx:'0',j:1,wrap:'1'),l:'5',n:'0',o:'Output+of+x86-64+gcc+14.3+(Compiler+%231)',t:'0')),header:(),l:'4',m:50,n:'0',o:'',s:0,t:'0')),k:50,l:'3',n:'0',o:'',t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>
