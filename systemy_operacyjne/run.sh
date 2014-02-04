#!/bin/bash

make
# mainProdCust $a $b $c $d
#  ($a, $b) - range of customer delay
#  ($c, $d) - range of producer delay

echo "Slow customer, instant producer"
./mainProdCust 2 4 0 0

echo "Instant customer, slow producer"
./mainProdCust 0 0 2 4

a=$RANDOM
b=$RANDOM
RANGE=5
let "a %= $RANGE"
let "b %= $RANGE"

echo "Customer delay: $a sec. Producer delay: $b sec."

./mainProdCust $a $a $b $b
