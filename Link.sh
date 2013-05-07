#!/bin/bash
g++ -c -o main.o main.cpp -lboost_unit_test_framework 
g++ -o ./main.out main.o -lboost_unit_test_framework
