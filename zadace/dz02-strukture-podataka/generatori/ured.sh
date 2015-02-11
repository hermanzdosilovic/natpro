#!/bin/bash
sudo rm -rf ../test/ured
mkdir -p ../test/ured
g++ ured.cpp -o ured.out
cat <<< "10 5 20" | ./ured.out > ../test/ured/ured.01.in && sleep 1
cat <<< "100 20 50" | ./ured.out > ../test/ured/ured.02.in && sleep 1
cat <<< "100 100 100" | ./ured.out > ../test/ured/ured.03.in && sleep 1
for i in {4..7}
do
  cat <<< "1000 1000 10000" | ./ured.out > ../test/ured/ured.0$i.in && sleep 1
done
for i in {8..9}
do
  cat <<< "10000 10000 1000000" | ./ured.out > ../test/ured/ured.0$i.in && sleep 1
done
cat <<< "100000 100000 10000000" | ./ured.out > ../test/ured/ured.10.in && sleep 1
rm ured.out

cd ..
g++ ured.dosilovic.cpp
for i in {1..10}
do
  i=`printf "%02d" $i`
  ./a.out < test/ured/ured.$i.in > test/ured/ured.$i.out
done
rm a.out
