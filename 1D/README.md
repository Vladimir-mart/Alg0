# Решение задачи 1D

Условие можно найти [тут](https://contest.yandex.ru/contest/28699/problems/D/)

Для решения этой задачи потребовалось вспомнить что такое бин поиск и как он работает, после посмотреть условие и определиться как работает указатели если их отнять друг от друга, выяснилось что они показывают расстояние, сразу было решено сделать так что функция получает указатель на первый элемент + индекс, получаем что в функции есть уже нужный нам указатель, а после с помощью бин поиска можно проверить есть ли нужный элемент в массиве.