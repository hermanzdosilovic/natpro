#!/bin/bash
sudo rm -rf ../test/slicice
mkdir -p ../test/slicice

let k=1
for i in $(seq 10 20 60)
do
  cat <<< "$i $i" | python slicice.py > ../test/slicice/slicice.0$k.in
  let k++
done

for i in {4..7}
do
  cat <<< "60 1000" | python slicice.py > ../test/slicice/slicice.0$i.in
done

for i in {8..9}
do
  cat <<< "60 10000" | python slicice.py > ../test/slicice/slicice.0$i.in
done

for i in {10..12}
do
  cat <<< "60 100000" | python slicice.py > ../test/slicice/slicice.$i.in
done

for i in {13..15}
do
  cat <<< "60 1000000" | python slicice.py > ../test/slicice/slicice.$i.in
done

cd ..
g++ slicice.dosilovic.cpp
for i in {1..15}
do
  i=`printf "%02d" $i`
  ./a.out < test/slicice/slicice.$i.in > test/slicice/slicice.$i.out
done
rm a.out
