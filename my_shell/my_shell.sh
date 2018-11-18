#!/bin/bash
PATH1=`pwd`
FILE_TYPE=h
CMD=`/bin/find $PATH1 -name "*."$FILE_TYPE`
echo $CMD
