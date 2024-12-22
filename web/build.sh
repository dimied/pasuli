#!/bin/bash

while true; do
    sleep 2
    cat codegen.js main_src.js > main.js
done
