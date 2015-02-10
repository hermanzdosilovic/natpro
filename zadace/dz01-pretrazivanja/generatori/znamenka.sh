#!/bin/bash
sudo rm -rf ../test/znamenka
mkdir -p ../test/znamenka
cat <<< "10" | python znamenka.py > ../test/znamenka/znamenka.01.in && sleep 1
cat <<< "100" | python znamenka.py > ../test/znamenka/znamenka.02.in && sleep 1
cat <<< "1000" | python znamenka.py > ../test/znamenka/znamenka.03.in && sleep 1
cat <<< "10000" | python znamenka.py > ../test/znamenka/znamenka.04.in && sleep 1
cat <<< "100000" | python znamenka.py > ../test/znamenka/znamenka.05.in && sleep 1
cat <<< "1000000" | python znamenka.py > ../test/znamenka/znamenka.06.in && sleep 1
cat <<< "10000000" | python znamenka.py > ../test/znamenka/znamenka.07.in && sleep 1
cat <<< "100000000" | python znamenka.py > ../test/znamenka/znamenka.08.in && sleep 1
cat <<< "1000000000" | python znamenka.py > ../test/znamenka/znamenka.09.in && sleep 1
cat <<< "10000000000" | python znamenka.py > ../test/znamenka/znamenka.10.in && sleep 1
cat <<< "100000000000" | python znamenka.py > ../test/znamenka/znamenka.11.in && sleep 1
cat <<< "1000000000000" | python znamenka.py > ../test/znamenka/znamenka.12.in && sleep 1
cat <<< "10000000000000" | python znamenka.py > ../test/znamenka/znamenka.13.in && sleep 1
cat <<< "100000000000000" | python znamenka.py > ../test/znamenka/znamenka.14.in && sleep 1
cat <<< "1000000000000000" | python znamenka.py > ../test/znamenka/znamenka.15.in && sleep 1
cat <<< "10000000000000000" | python znamenka.py > ../test/znamenka/znamenka.16.in && sleep 1
cat <<< "100000000000000000" | python znamenka.py > ../test/znamenka/znamenka.17.in && sleep 1
cat <<< "1000000000000000000" | python znamenka.py > ../test/znamenka/znamenka.18.in && sleep 1

cd ..
g++ znamenka.dosilovic.cpp
for i in {1..18}
do
  i=`printf "%02d" $i`
  ./a.out < test/znamenka/znamenka.$i.in > test/znamenka/znamenka.$i.out
done
rm a.out
