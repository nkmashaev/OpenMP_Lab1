# OpenMP_Lab1

## Описание
- - - - - - - - - - - - -
Предназначена для применения на UNIX подобных системах

Программа выполняет сдвиг расчетной области и покрывающей ее сетки в каждом из трех координатных направлений с независимой для каждого направления величиной сдвига.

Разрабатывалась с целью исследования возможностей технологии OpenMP применительно к распараллеливанию вложенных циклов, в которых производятся независимые операции с многомерными массивами.

Рассматривается использование директив OMP FOR и OMP SECTIONS. Изучается использование для OMP FOR аттрибутов COLLAPSE и SCHEDULE. Проводите исследование эффективности распараллеливания программ при помощи увеличения числа нитей от 1 до 8

## Перед запуском программы
- - - - - - - - - - - - -
Необходимо выполнить команды

```Bash
chmod +x lab1_builder.sh
chmod +x lab1_data.sh
```

## Запуск программы
- - - - - - - - - - - - -

Запуск программы осуществляется при помощи команды

```
./lab1_data.sh
```

## Входные данные
- - - - - - - - - - - - -

Входным файлом является структурированная сетка cube.msh в каталоге grids. Формат сетки следующий: в первой строке приводится размер
сетки по трем координатным направлениям i,j,k; далее идет перечисление узлов

## Выходные данные
- - - - - - - - - - - - -

Выходными данными являются файлы lab1_data.txt и grids/cube_new.msh, являющиеся результатом исследования применения различных директив OMP и модифицированной сеткой соответственно
