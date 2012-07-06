#!/bin/bash

iter=0
while [ $iter -lt 50000 ]; do
	echo $RANDOM >> data
	iter=$((iter+1))
done
