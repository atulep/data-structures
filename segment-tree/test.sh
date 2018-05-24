#!/bin/sh

export GTEST_PATH
make && ./segment_tree_test && make clean
