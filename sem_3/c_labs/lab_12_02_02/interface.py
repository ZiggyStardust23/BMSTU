from tkinter import Entry, Label, Button, Tk, messagebox, END
import ctypes

lib = ctypes.CDLL('./lib/lib_array_func.dll')

_fill_fibonaci = lib.fill_fibonaci
_fill_fibonaci.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_fill_fibonaci.restype = None

_add_first_find_elem = lib.add_first_find_elem
_add_first_find_elem.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int,
    ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_add_first_find_elem.restype = ctypes.c_int

_find_num_of_first_find_elems = lib.find_num_of_first_find_elems
_find_num_of_first_find_elems.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_find_num_of_first_find_elems.restype = ctypes.c_int

def fill_fibonaci(size):

    array = (ctypes.c_int * size)()
    _fill_fibonaci(array, size)

    return list(array)

def add_first_find_elem(array, size):
    array = (ctypes.c_int * size)(*array)
    new_array = []

## 1 способ
## Максимально возможный размер - если все числа входят 1 раз
##  count = size
            
##  if (count > 0):
##       new_array = (ctypes.c_int * count)(*new_array)
##    new_len = _add_first_find_elem(array, size, new_array, count + new_size) 

## 2 способ
    count = _find_num_of_first_find_elems(array, size);
    new_array = (ctypes.c_int * count)(*new_array)
    new_len =_add_first_find_elem(array, size, new_array, count)
    
    return new_len, list(new_array)

def arr_of_fibonaci():

    try:
        number = int(entry_field_1.get())

    except:
        messagebox.showerror("Ошибка ввода", "Кол-во эллементов - целое число")
        return

    if (number < 1):
        messagebox.showerror("Ошибка ввода", "Некорректное колво элементов")
        return

    array = fill_fibonaci(number)
    str_array = ' '.join(str(number) for number in array)

    output_field_1.delete(0, END)
    output_field_1.insert(0, str_array)

def read_arr_and_create_new():

    str_array = entry_field_2.get()

    try:
        array = [int(i) for i in str_array.split()]

    except:
        messagebox.showerror("Ошибка ввода", "Еще символы помимо чисел")


    new_len, new_array = add_first_find_elem(array, len(array))

    new_str_arr = []
    for i in range(new_len):
        new_str_arr.append(str(new_array[i]))

    str_array = ' '.join(new_str_arr)

    output_field_2.delete(0, END)
    output_field_2.insert(0, str_array)


window = Tk()
window['bg'] = 'light gray'
window.title('Lab_12_03_02')
window.geometry("460x430")

txt_input_1 = Label(window, text = 'Кол-во элементов массива:', bg = 'light gray',
    font = ('Courier New', 16))
txt_input_1.place(x = 20, y = 15, width = 350, height = 30)

entry_field_1 = Entry(window, width = 5, font = ('Courier New', 16))
entry_field_1.place(x = 350, y = 15, width = 70, height = 30)
entry_field_1.focus()    

btn_fill_array_1 = Button(window, text = 'Вывести массив из\n N чисел Фибоначчи',
    font = ('Courier New', 16), activebackground = '#555555', command = arr_of_fibonaci)

btn_fill_array_1.place(x = 60, y = 60, width = 270, height = 45)

output_field_1 = Entry(window, width = 5, font = ('Courier New', 16))
output_field_1.place(x = 20, y = 120, width = 360, height = 30)

txt_input_2 = Label(window, text = 'Заполните массив', bg = 'light gray',
    font = ('Courier New', 16))
txt_input_2.place(x = 20, y = 170, width = 400, height = 30)

entry_field_2 = Entry(window, width = 35, font = ('Courier New', 16))
entry_field_2.place(x = 20, y = 205, width = 360, height = 30)

btn_add_elem = Button(window, text = 'Создать новый массив из первых\nвхождений чисел старого массива',
    font = ('Courier New', 16), activebackground = '#555555', command = read_arr_and_create_new)

btn_add_elem.place(x = 20, y = 290, width = 400, height = 45)

txt_output = Label(window, text = 'Полученный массив:', bg = 'light gray',
    font = ('Courier New', 16))
txt_output.place(x = 20, y = 345, width = 360, height = 30)

output_field_2 = Entry(window, width = 5, font = ('Courier New', 16))
output_field_2.place(x = 20, y = 375, width = 360, height = 30)

window.mainloop()