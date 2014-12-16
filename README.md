# supergameherm

## What is this?
A GB emulator that aims to not suck so bad.

## What do you mean "not suck so bad"?
Well, most Gameboy emulators suck horribly:
* Most have terrible compatibility (there are exceptions of course)
* They're riced in wrong/bad ways or use invalid/outdated assumptions
* They're horrible on the inside and impossible to maintain and fix
* There are very few pure C emulators that aren't crap
* Lack of good linking support (none of them get this right)

## WTF is up with the name?
Our emulator's a herm. Deal with it.

## Who made this?
[awilfox](http://github.com/awilfox) and [Elizafox](http://github.com/Elizafox)
are the principal authors.

You can find us on IRC at irc.interlinked.me in #supergameherm. Those who act
like they're 12 will be promptly given a boot to the head. All others are
welcome.

## What is it written in?
It's written in a subset of C11 (alternatively, a superset of C99).

The major features we use in C11 are anonymous structs and unions. Most
sensible compilers have supported these as extensions for many years
now, so it should not be any trouble. Systems where they do not work
are probably too slow to run SuperGameHerm, anyway.

## What systems does this run on?
Compilers we have tested SuperGameHerm with (others may or may not work,
your mileage may vary):
* [GCC](https://gcc.gnu.org/)
* [clang](http://clang.llvm.org/)
* [MSVC](http://www.visualstudio.com/downloads/download-visual-studio-vs)

Platforms we have tested SuperGameHerm with:
* Linux ~3.13 kernel (x86, amd64, and PowerPC)
* FreeBSD 10 (i386 and amd64)
* Windows NT 4 (x86, but we've seen snails run faster)
* Windows 10 (x64, kinda slow)
* NetBSD 6 (i386)

Currently supported frontends (they work wherever the given frontends
work):
* [SDL2](https://www.libsdl.org/download-2.0.php)
* Win32 API (slow)
* [libcaca](http://caca.zoy.org/) (no sound, obviously)

Please report to us if your platform doesn't work, or your favourite frontend
isn't supported! If you want to write one yourself, look at the null pseudo-
frontend.

### Technical portability notes 
Note we rely on a union of two uint8\_t's being equivalent to a uint16\_t in
size without padding. This is used for registers to avoid the need to do a
write-back of every register on every execution cycle. This should be okay on
all of the tested compilers and systems, but if it breaks, let us know and we
will try to make a workaround.

We use restrict to ensure the compiler knows we don't alias certain pointers,
which causes it to generate better code. A huge speedup is possible when the
compiler is apprised of this (up to 3x faster, surprisingly).

### You should write this in C++!
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

## Does this work as a practical emulator?
Not yet. There's no sound, and only limited graphics support. We're working on
it.

Interestingly, we do pass all of Blargg's CPU tests. Many emulators can't
manage to do that. :)

## Why does it (X, Y, Z)?  Why /doesn't/ it (A, B, C)?
Because it's still being worked on.

Bugs that involve "you should/shouldn't do X and Y and Z" without any 
justification will be closed without comment.

## How fast is it?
It presently runs at approximately 8x Gameboy speed on Linux and FreeBSD on
most modern systems (basically any i7 or newer).

We are aiming for native speed on at least a Pentium III or newer. Use a
different emulator if you care about older machines.

## It crashed/segfaulted/broke my system/skinned my cat/pooed on the floor!
Then report an issue! But first, read 
[this](http://www.chiark.greenend.org.uk/~sgtatham/bugs.html).
