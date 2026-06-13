#!/bin/bash

awk -F',' '{print $1, $3}' data.csv
