#!/bin/bash
sudo rm -rf ../test/brojevi
mkdir -p ../test/brojevi
let k=1
for i in {1..5}
do
    K=`printf "%02d" $k`
    cat <<< "$i" | python brojevi.py > ../test/brojevi/brojevi.$K.in
    let k++
done
for i in $(seq 10 10 50)
do
    K=`printf "%02d" $k`
    cat <<< "$i" | python brojevi.py > ../test/brojevi/brojevi.$K.in
    let k++
done

cd ..
g++ brojevi.dosilovic.cpp
for i in {1..10}
do
    K=`printf "%02d" $i`
    ./a.out < test/brojevi/brojevi.$K.in > test/brojevi/brojevi.$K.out
done
rm a.out

