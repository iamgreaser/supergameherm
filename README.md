# supergameherm

## What is this?
A GB emulator that aims to not suck so bad.

## Who made this?
We did (@awilfox and @Elizafox on GitHub).

## Why does it (X, Y, Z)?  Why /doesn't/ it (A, B, C)?
Because it's still being worked on.

## What systems does this run on?
It's mostly written in ANSI C99. There are some portability shims for lesser
systems, but results cannot be guaranteed, and it may run slower.

Tested compilers include [ICC](https://software.intel.com/en-us/c-compilers), 
[GCC](https://gcc.gnu.org/), [clang](http://clang.llvm.org/), and
[MSVC](http://www.visualstudio.com/downloads/download-visual-studio-vs). Others
may or may not work, but we presently make an effort.

Tested platforms include Linux/x86, Linux/amd64, Linux/ppc32, FreeBSD/amd64, 
Windows 10/x64, and Windows NT/x86. Please report to us if your platform
doesn't work or has missing functionality!

Three frontends are supported at the moment: SDL2, libcaca, and win32.
The code needed to support a new one is rather minimal and easy to write. Take
a look at the null pseudo-frontend for an example.

### Technical portability notes 
Note we rely on a union of two uint8\_t's being equivalent to a uint16\_t in
size without padding. This is used for registers to avoid the need to do a
write-back of every register on every execution cycle. This should be okay on
all of the tested compilers and systems, but if it breaks, let us know and we
will try to make a workaround.

We use restrict to ensure the compiler knows we obey strict-aliasing rules,
which causes it to generate better code. A huge speedup results when the
compiler can be promised of this.

## Does this work as a practical emulator?
Not yet. There's no sound, and only limited graphics support. We're working on
it.

Interestingly, we do pass all of Blargg's CPU tests. Many emulators can't
manage to do that. :)

## How fast is it?
It presently runs at approximately 8x Gameboy speed on Linux and FreeBSD on most modern systems (basically any i7 or newer).

## It crashed/segfaulted/broke my system/skinned my cat/pooed on the floor!
Then report an issue! But first, read [this](http://www.chiark.greenend.org.uk/~sgtatham/bugs.html).

Bugs that involve "you should/shouldn't do X and Y and Z" without any 
justification will be closed without comment.

## You should write this in C++!
No, we will not write it in C++. No, C++ will not make the code go any faster,
no matter what your CS101 professor with a degree in History told you, or what
some person on the Internet told you.

The overhead of classes is not worth the trouble, and the use of complex data
structures in supergameherm is relatively limited - not to mention the overhead
of v-tables, RTTI, exceptions, the bloat that templates and the STL cause for
little gain (see also: the use of complex data structures in supergameherm is
relatively limited), and the lack of things such as restrict qualifiers.

With this in mind, although supergameherm is written in a subset of C11 (or a
superset of C99, depending on your perspective), any C++ compiler worth
anything should be able to compile supergameherm. We aim to avoid conflicts
with C++ identifiers in our code to ensure compatibility with older MSVC.
