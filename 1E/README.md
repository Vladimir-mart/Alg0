# Решение задачи 1E

Условие можно найти [тут](https://contest.yandex.ru/contest/28699/problems/E/)

Для решения этой задачи, мне потребовалось:
дополнительный масив,
пару переменных,
вспомнить, что такое логарифмы,
посмотреть при каких формулах, в возведение в степень число не будет выподать, 
две пары рук и экспонента.
Для начала с помощь логарифмоф мы записываем префексно все элементы, после избавляемся от магического числа магическим образом 7 = 2 + 2 + 2 + 1.
А дальше:
pow(exp(1.0), (special_arr[arr_index_r] - special_arr[arr_index_l - 1]) / (arr_index_r - arr_index_l + 1)),
это мы логарифмы отнимаем, следовательно делим то число, а после возводим в степень.

