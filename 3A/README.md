# Решение задачи 3A

Условие можно найти [тут](https://contest.yandex.ru/contest/30154/problems/A/)

Для решение этой задачи можно не делать изначально дерево(На узлах). По точкам можно по-любому построить декардово дерево (На плоскости). Для этого можно отсортировать по самому благоприятному сыну с лева и справа и записать узлы в массив, а после по массиву можно построить само дерево. Создадим массив указателей и будем сортировать его, прыжок с указателя на указатель будем делать с помощью счетчика, таким образом мы получим массив отсортиртированных узлов. После этого в методе MakeTree мы будем определять дерево уже с помощью 'y'. Получили дерево и в методе ResultsDisplay выводим построеное дерево.
