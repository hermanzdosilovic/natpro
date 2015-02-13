#!/bin/bash
sudo rm -rf ../test/najnaj
mkdir -p ../test/najnaj
gcc -std=c99 najnaj.c -o najnaj.out

for i in {1..3}
do
  cat <<< "5" | ./najnaj.out > ../test/najnaj/najnaj.0$i.in && sleep 1
done

for i in {4..6}
do
  cat <<< "10" | ./najnaj.out > ../test/najnaj/najnaj.0$i.in && sleep 1
done

for i in {7..8}
do
  cat <<< "100" | ./najnaj.out > ../test/najnaj/najnaj.0$i.in && sleep 1
done

for i in {9..10}
do
  i=`printf "%02d" $i`
  cat <<< "1000" | ./najnaj.out > ../test/najnaj/najnaj.$i.in && sleep 1
done
rm najnaj.out

cd ..
g++ najnaj.dosilovic.cpp
for i in {1..10}
do
  i=`printf "%02d" $i`
  ./a.out < test/najnaj/najnaj.$i.in > test/najnaj/najnaj.$i.out
done

rm a.out
