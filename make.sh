
/usr/local/Cellar/gcc/10.1.0/bin/g++-10 $1/solution.cpp -o $1/main

for i in $1/*.in; do
  echo ===============
  echo $i
  echo ===============
  $1/main < $i
done

rm $1/main