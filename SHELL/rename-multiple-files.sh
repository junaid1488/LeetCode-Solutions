#!/bin/bash

for file in *.txt
do
    mv "$file" "new_$file"
done
