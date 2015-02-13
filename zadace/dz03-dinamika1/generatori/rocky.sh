#!/bin/bash
sudo rm -rf ../test/rocky
mkdir -p ../test/rocky

let k=1
for i in $(seq 10 20 100)
do
  K=`printf "%02d" $k`
  cat <<< "$i" | python rocky.py > ../test/rocky/rocky.$K.in
  let k++
done

for i in $(seq 1000 2000 10000)
do
  K=`printf "%02d" $k`
  cat <<< "$i" | python rocky.py > ../test/rocky/rocky.$K.in
  let k++
done

for i in $(seq 10000 20000 100000)
do
  K=`printf "%02d" $k`
  cat <<< "$i" | python rocky.py > ../test/rocky/rocky.$K.in
  let k++
done

for i in $(seq 100000 200000 1000000)
do
  K=`printf "%02d" $k`
  cat <<< "$i" | python rocky.py > ../test/rocky/rocky.$K.in
  let k++
done

K=`printf "%02d" $k`
echo "1000000" > ../test/rocky/rocky.$K.in

cd ..
g++ rocky.dosilovic.cpp
for i in $(seq 1 $k)
do
  i=`printf "%02d" $i`
  ./a.out < test/rocky/rocky.$i.in > test/rocky/rocky.$i.out
done
rm a.out
