# the-theory-of-parallelism

# Бенчмарк суммы синуса (float vs double)

Программа вычисляет сумму значений синуса на равномерной сетке из 10⁷ точек за один период [0, 2π].

## Сборка

### Double (по умолчанию)
```bash
mkdir build && cd build
cmake ..
make -j
./sine_bench
```
```
mkdir build_float && cd build_float
cmake -DUSE_FLOAT=ON ..
make -j
./sine_bench
```



| Тип    | Сумма   | Память | Точность |
| ------ | ------- | ------ | -------- |
| double | 1.00012 | 80 MB  | Высокая  |
| float  | 0.99987 | 40 MB  | Средняя  |
