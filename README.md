# What is ESFM ?
<br>
When you are doing work and you need to create an executable bash/python/prel script, you have to
create a file and then add ```#!/usr/bin...``` line at the bigging of the file and change file 
permission to executable. Which is repetitive and waste of time. 

<b>
So, to solve this problem here comes ESFM (Executable Script File Maker) to help you make executable scripts in one step.
</b>

# How to use it.


```bash
~/ $ mkex

Usage: mkex [OPTION...] [FILENAME]
CLI tool for making executable files

      --bash=FILE            For bash interpreter
  -c, --custom=EXE_NAME      For custom interpreter
      --php=FILE             For php interpreter
      --prel=FILE            For prel interpreter
      --py2=FILE             For python2 interpreter
      --py3=FILE             For python3 interpreter
      --sh=FILE              For sh interpreter
  -?, --help                 Give this help list
      --usage                Give a short usage message
  -V, --version              Print program version

Mandatory or optional arguments to long options are also mandatory or optional
for any corresponding short options.

Report bugs to <sanaf@0x30c4.dev>.
```
