#!/bin/bash

readonly target=527

exp=1
for i in $(seq 1 16); do

  ((2**i > target)) && break

  exp=$i

done

echo final $exp is $((2**exp))

