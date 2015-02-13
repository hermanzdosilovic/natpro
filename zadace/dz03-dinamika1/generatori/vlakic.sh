#!/bin/bash
sudo rm -rf ../test/vlakic
mkdir -p ../test/vlakic
let k=1
for i in $(seq 5 5 20)
do
  for j in {1..5}
  do
    K=`printf "%02d" $k`
    cat <<< "$i" | python vlakic.py > ../test/vlakic/vlakic.$K.in
    let k++
  done
done

echo "20 20 20" >> ../test/vlakic/vlakic.$k.in

cd ..
g++ vlakic.dosilovic.cpp
for i in $(seq 1 $k)
do
  i=`printf "%02d" $i`
  ./a.out < test/vlakic/vlakic.$i.in > test/vlakic/vlakic.$i.out
done
rm a.out
