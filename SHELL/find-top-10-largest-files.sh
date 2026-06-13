#!/bin/bash

find . -type f -exec du -h {} + | sort -rh | head -10
