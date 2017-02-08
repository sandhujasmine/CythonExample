# CythonExample #

[![Build Status](https://travis-ci.org/sandhujasmine/CythonExample.svg?branch=master)](https://travis-ci.org/sandhujasmine/CythonExample)

[![Coverage Status](https://coveralls.io/repos/sandhujasmine/CythonExample/badge.svg?branch=master&service=github)](https://coveralls.io/github/sandhujasmine/CythonExample?branch=master)

Example of C++ wrapped by cython and built using setup.py. Create a conda
environment and use conda to install dependencies.

The netcdf4 dependency is built against libcurl.4.dylib (compatibility version 8.0.0,
current version 8.0.0); however, OSX Yosemite's system libraries contains libcurl.4.dylib
(compatibility version 7.0.0, current version 8.0.0)

On OS X, during building and linking in the conda environment, the environment's libcurl is found.
However, the path to the libcurl to load at runtime is not contained in executable so it tries to load
libcurl from system path and things break.

Using conda develop with --build_ext option invokes setup.py to build extensions in place.
It then looks in source dir for compiled extensions and ensures they link against libraries
found in conda "env" by embedding the path to the environment's library into the executable.

## Dependencies ##

Using miniconda with python 2.7, cython and pytest. Added netcdf4
to illustrate above problem.

* Python - tested against 2.7
* Cython
* netcdf4   # only used to illustrate above problem
* pytest


Dependencies are also listed in environment.yml:

```
conda evn create   # create env from environment.yml
```

## Building in develop mode ##

Two options for building in develop mode:

1. use conda develop

```sh
$ conda develop --build_ext .  # builds then adds path to conda.pth and fixes linkages
$ conda develop --uninstall .  # uninstall by removing path from conda.pth
```

2. run setup.py with develop option followed by conda develop to correct linkages.
   conda develop will invoke install_name_tool to correct linkages for all extensions
   (*.so) in specified path. This is only for OS X.

```sh
$ ./setup.py develop		    # builds in develop mode	
$ conda develop --no-pth-file . # does not add path to conda.pth but does correct linkages
```


## Testing ##

run ./tests/test_polygon.py to test

```sh
$ py.test -v ./tests/test_polygon.py  # test
```
