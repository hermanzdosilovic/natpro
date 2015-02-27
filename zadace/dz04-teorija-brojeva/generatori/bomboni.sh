#!/bin/bash
sudo rm -rf ../test/bomboni
mkdir -p ../test/bomboni
let k=1
let p=10
let m=10
for j in {1..5}
do
    K=`printf "%02d" $k`
    cat <<< "$p" | python bomboni.py > ../test/bomboni/bomboni.$K.in
    let k++
    p=$(($p*$m))
done
for j in {1..5}
do
   K=`printf "%02d" $k`
   cat <<< "200000" | python bomboni.py > ../test/bomboni/bomboni.$K.in
   let k++
done
cd ..
g++ bomboni.dosilovic.cpp
for i in {1..10} 
do
    i=`printf "%02d" $i`
    ./a.out < test/bomboni/bomboni.$i.in > test/bomboni/bomboni.$i.out
done
rm a.out
