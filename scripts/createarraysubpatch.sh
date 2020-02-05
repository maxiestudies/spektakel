intropatch=intro_arrs.pd
hp=heart_arrs.pd
ep=extro_arrs.pd
arrsize=160163

touch $intropatch
y_axis=50
x_axis=115

echo "#N canvas 435 209 450 300 12;" > $intropatch

for j in {1..3}
do
  for i in {1..10}
  do
    echo "#X obj $x_axis $y_axis array define ${j}_Intro-$i $arrsize;" >> $intropatch
    y_axis=$((y_axis+30))
  done
  y_axis=50
  x_axis=$((x_axis+220))
done

touch $hp
y_axis=50
x_axis=115

echo "#N canvas 435 209 450 300 12;" > $hp

for j in {1..2}
do
  for i in {1..10}
  do
    echo "#X obj $x_axis $y_axis array define ${j}_Heart-$i $arrsize;" >> $hp
    y_axis=$((y_axis+30))
  done
  y_axis=50
  x_axis=$((x_axis+220))
done

touch $ep
y_axis=50
x_axis=115

echo "#N canvas 435 209 450 300 12;" > $ep

for j in {1..3}
do
  for i in {1..10}
  do
    echo "#X obj $x_axis $y_axis array define ${j}_Extro-$i $arrsize;" >> $ep
    y_axis=$((y_axis+30))
  done
  y_axis=50
  x_axis=$((x_axis+220))
done
