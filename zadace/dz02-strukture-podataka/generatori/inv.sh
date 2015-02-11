#!/bin/bash
sudo rm -rf ../test/inv
mkdir -p ../test/inv
g++ inv.cpp -o inv.out
cat <<< "10 20" | ./inv.out > ../test/inv/inv.01.in && sleep 1
cat <<< "10 30" | ./inv.out > ../test/inv/inv.02.in && sleep 1
cat <<< "100 200" | ./inv.out > ../test/inv/inv.03.in && sleep 1
for i in {4..6}
do
  cat <<< "1000 10000" | ./inv.out > ../test/inv/inv.0$i.in && sleep 1
done
for i in {7..8}
do
  cat <<< "10000 20000" | ./inv.out > ../test/inv/inv.0$i.in && sleep 1
done
cat <<< "100000 200000" | ./inv.out > ../test/inv/inv.09.in && sleep 1
cat <<< "1000000 10000000" | ./inv.out > ../test/inv/inv.10.in && sleep 1
rm inv.out

cd ..
g++ inv.dosilovic.cpp
for i in {1..10}
do
  i=`printf "%02d" $i`
  ./a.out < test/inv/inv.$i.in > test/inv/inv.$i.out
done
rm a.out
