#!/bin/bash
sudo rm -rf ../test/kopirka
mkdir -p ../test/kopirka
gcc -std=c99 kopirka.c -o kopirka.out
cat <<< "8 100" | ./kopirka.out > ../test/kopirka/kopirka.01.in && sleep 1
cat <<< "10 1000" | ./kopirka.out > ../test/kopirka/kopirka.02.in && sleep 1
cat <<< "15 1000" | ./kopirka.out > ../test/kopirka/kopirka.03.in && sleep 1
cat <<< "20 1000" | ./kopirka.out > ../test/kopirka/kopirka.04.in && sleep 1
for i in {5..7}
do
  cat <<< "100 10000" | ./kopirka.out > ../test/kopirka/kopirka.0$i.in && sleep 1
done
cat <<< "200 100000" | ./kopirka.out > ../test/kopirka/kopirka.08.in && sleep 1
cat <<< "300 1000000" | ./kopirka.out > ../test/kopirka/kopirka.09.in && sleep 1
cat <<< "500 10000000" | ./kopirka.out > ../test/kopirka/kopirka.10.in && sleep 1
rm kopirka.out

cd ..
g++ kopirka.dosilovic.cpp
for i in {1..10}
do
  i=`printf "%02d" $i`
  ./a.out < test/kopirka/kopirka.$i.in > test/kopirka/kopirka.$i.out
done
rm a.out
