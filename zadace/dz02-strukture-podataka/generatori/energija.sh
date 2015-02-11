#!/bin/bash
sudo rm -rf ../test/energija
mkdir -p ../test/energija
g++ energija.cpp -o energija.out
cat <<< "10 7 20 300" | ./energija.out > ../test/energija/energija.01.in && sleep 1
cat <<< "20 10 30 400" | ./energija.out > ../test/energija/energija.02.in && sleep 1
cat <<< "100 20 40 500" | ./energija.out > ../test/energija/energija.03.in && sleep 1
cat <<< "500 100 100 2000" | ./energija.out > ../test/energija/energija.04.in && sleep 1
cat <<< "1000 700 4000 50000" | ./energija.out > ../test/energija/energija.05.in && sleep 1
for i in {6..8}
do
  cat <<< "10000 7000 4000 50000" | ./energija.out > ../test/energija/energija.0$i.in && sleep 1
done
cat <<< "10000 7000 40000 50000000000" | ./energija.out > ../test/energija/energija.09.in && sleep 1
cat <<< "100000 99999 400000 1000000000000000" | ./energija.out > ../test/energija/energija.10.in && sleep 1
rm energija.out

cd ..
g++ energija.dosilovic.cpp
for i in {1..10}
do
  i=`printf "%02d" $i`
  ./a.out < test/energija/energija.$i.in > test/energija/energija.$i.out
done
rm a.out
