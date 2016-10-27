#!/bin/bash
find . -iwholename '*cmake*' -not -name CMakeLists.txt \
	                     -not -name cmake_clean.sh -delete
