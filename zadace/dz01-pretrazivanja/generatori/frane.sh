#!/bin/bash
sudo rm -rf ..test/frane
mkdir -p ../test/frane
gcc -std=c99 frane.c -o frane.out
cat <<< "10 20" | ./frane.out > ../test/frane/frane.01.in && sleep 1
cat <<< "10 30" | ./frane.out > ../test/frane/frane.02.in && sleep 1
cat <<< "100 150" | ./frane.out > ../test/frane/frane.03.in && sleep 1
for i in {4..6}
do
  cat <<< "1000 5000" | ./frane.out > ../test/frane/frane.0$i.in && sleep 1
done
for i in {7..9}
do
  cat <<< "10000 15000" | ./frane.out > ../test/frane/frane.0$i.in && sleep 1
done
cat <<< "100000 100000" | ./frane.out > ../test/frane/frane.10.in
rm frane.out

cd ..
g++ frane.dosilovic.cpp
for i in {1..10}
do
  i=`printf "%02d" $i`
  ./a.out < test/frane/frane.$i.in > test/frane/frane.$i.out
done
rm a.out
