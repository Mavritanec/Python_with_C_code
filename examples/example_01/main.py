import ctypes
import os

if __name__ == '__main__':
    # указываем полный путь до библиотеки
    # lib_path = os.getcwd()  # работает не всегда
    # lib_path = os.path.dirname(os.path.abspath(__file__))
    lib_path = os.path.dirname(__file__)
    lib_path = os.path.join(lib_path, 'libcadd.so')

    # инициализируем объект библиотеки
    c_lib = ctypes.CDLL(lib_path)
    # определяем возвращаемый тип данных для функции cadd
    c_lib.cadd.restype = ctypes.c_float

    x, y = 6, 2.3
    # для переменной y также определяем тип данных
    # (переменную x можно не трогать, т.к. по умолчанию тип данных: int)
    res = c_lib.cadd(x, ctypes.c_float(y))

    print(f'In Python: int: {x} float {y:.1f} return val {res:.1f}')
