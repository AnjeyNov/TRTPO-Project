# Поток событий
---

# Содержание
1 [Актеры](#actors) 
2 [Варианты использования](#use_cases) 
2.1 [Добавить группу](#add_group) 
2.2 [Удалить группу](#delete_group) 
2.3 [Сменить группу](#change_group) 
2.4 [Сменить подгруппу](#change_subgroup) 
2.5 [Сменить вид представдения](#change_view_type) 
2.6 [Отобразить расписание](#display_schedule) 
2.7 [Отобразить расписание на день](#display_day_schedule) 
2.8 [Отобразить расписание на неделю](#display_week_schedule) 
2.9 [Сменить неделю](#change_week) 
2.10 [Сменить день](#change_day) 
2.11 [Обнивить расписание](#update_schedule) 
2.12 [Загрузить расписание](#download_schedule)  


<a name="actors"/>

# Актеры

| Актёр | Описание |
|:--|:--|
| Пользователь | Человек, использующий систему |
| Интернет-ресурс | Web-сайт, информация с которого анализируется приложением |

<a name="use_cases"/>

# 2 Варианты использования

<a name="add_group"/>

## 2.1 Добавить группу

**Описание.** Вариант использования "Добавить группу" позволяет пользователю добавить группу в список сохраненных расписаний.  
**Предусловиe.** Приложение имеет доступ к сети-интернет.  
**Основной поток.**
1. Пользователь вводит номер группы в соответсвующее поле;
2. Пользователь подтверждает ввод номера группы;
3. Приложение проверят введённый номер группы на совпадение с уже сохрененными номерами групп. Если совпадение выявлено, то вариант использования завершается;
4. Приложение выполняет вариант использования [Загрузить расписание](#download_schedule);
5. При недуачном ваполнении варианта использования [Загрузить расписание](#download_schedule) выполняется альтернативный поток А1;
6. Приложение добавляет номер группы в список загруженных групп и выполняет вариант использования [Отобразить расписание](#display_schedule) 
для этой группы;
7. Вариант использования завершается.

**Альтернативный поток А1.**
1. Приложение сообщает пользователю соответствующее сообщение об ошибке;
2. Вариант использования завершается.

<a name="delete_group"/>

## 2.2 Удалить группу

**Описание.** Вариант использования "Удалить группу" позволяет пользователю удалить группу из списка сохраненных расписаний.
**Предусловие.** Наличие хотябы одной группы в списке сохранненных групп.
**Основной поток.**
1. Пользователь наводит курсор на необходимую группу и нажимает правой кнопкой мыши;
2. Пользователь выбирает поле удалить в появившемся контекстном меню;
3. Пользователь подтверждает удаление группы;
4. Приложение удаляет файл с расписанием для соответсвующей группы на компьютере пользователя;
5. Приложение удаляет группу из списка сохранненных групп;
6. Если список сохраненных групп пуст то выполняется альтернативный поток А2;
7. Приложение выполняет вариант использования [Отобразить расписание](#display_schedule) для группы находящейся в верху списка сохраненных групп;
8. Вариант использования завершается.

**Альтернативный поток А2.**
1. Приложение в поле для отображения расписания выводит соответсвующее сообщение;
2. Вариант использования завершается.

<a name="change_group"/>

## 2.3 Сменить группу

**Описание.** Вариант использования "Сменить группу" позволяет пользователю сменить отображаемое расписание на необходимое.
**Предусловие.** Наличие в списке сохранненных групп двух и более групп.
**Основной поток.**
1. Пользователь наводит курсор на необходимую группу и нажимает левой кнопкой мыши;
2. Приложение выполняет вариант использования [Отобразить расписание](#display_schedule) для выбранной группы;
3. Вариант использования завершается.

<a name="change_subgroup"/>

## 2.4 Сменить подгруппу

**Описание.** Вариант использования "Сменить подгруппу" позволяет пользователю сменить отображаемое расписание на необходимое.
**Предусловие.** Наличие у необходимой группы двух подгрупп.
**Основной поток.**
1. Пользователь наводит курсор на необходимую группу и нажимает левой кнопкой мыши на соответствующую подгруппу;
2. Приложение выполняет вариант использования [Отобразить расписание](#display_schedule) для выбранной группы;
3. Вариант использования завершается.

<a name="change_view_type"/>

## 2.5 Сменить вид представдения

**Описание.** Вариант использования "Сменить вид представдения" позволяет пользователю сменить вид представления отображаемого расписания.
**Предусловие.** Наличие в списке сохранненных групп двух и более групп.
**Основной поток.**
1. Пользователь наводит курсор на необходимый вид предствления в поле отображения расписания и нажимает левой кнопкой мыши на соответствующую подгруппу;
2. Приложение выполняет вариант использования [Отобразить расписание](#display_schedule);
3. Вариант использования завершается.

<a name="display_schedule"/>

## 2.6 Отобразить расписание

**Описание.** Вариант использования "Отобразить расписание" помещает запрошенное расписание в поле для отображения расписания.
**Основной поток.**
1. Приложение открывает файл с расписанием для соответсвующей группы; 
2. Приложение в соответствии с указанными параметрами выполняет вариант использования [Отобразить расписание на день](#display_day_schedule) или [Отобразить расписание на неделю](#display_day_schedule);
3. Вариант использования завершается.

<a name="display_day_schedule"/>

## 2.7 Отобразить расписание на день

**Описание.** Вариант использования "Отобразить расписание на день" помещает запрошенное расписание в поле для отображения расписания.
**Основной поток.**
1. Приложение выводит расписание на указанный день на соответсвующую форму;
2. Вариант использования завершается.

<a name="display_week_schedule"/>

## 2.8 Отобразить расписание на неделю

**Описание.** Вариант использования "Отобразить расписание на неделю" помещает запрошенное расписание в поле для отображения расписания.
**Основной поток.**
1. Приложение выводит расписание на указанную неделю на соответсвующую форму;
2. Вариант использования завершается.

<a name="change_week"/>

## 2.9 Cменить неделю 

**Описание.** Вариант использования "Сменить неделю" позволяет пользователью сменить отображаемое расписание на необходимое.
**Основной поток.**
1. Пользователь наводит курсор на соответсвующий элемент интерфейса и нажимает на левую кнопку мыши; 
1. Приложение выполняет вариант использования [Отобразить расписание](#display_schedule) с соответсвующими параметрами;
2. Вариант использования завершается.

<a name="change_day"/>

## 2.10 Cменить день 

**Описание.** Вариант использования "Сменить день" позволяет пользователью сменить отображаемое расписание на необходимое.
**Основной поток.**
1. Пользователь наводит курсор на соответсвующий элемент интерфейса и нажимает на левую кнопку мыши; 
1. Приложение выполняет вариант использования [Отобразить расписание](#display_schedule) с соответсвующими параметрами;
2. Вариант использования завершается.

<a name="update_schedule"/>

## 2.11 Обновить расписание 

**Описание.** Вариант использования "Обновить расписание" обновляет расписание сохраненное на компьютере на актуальное.
**Предусловиe** Приложение имеет выход с сеть интернет.
**Основной поток.**
1. Вариант использования начинается, когда пользователь запускает приложение.
1. Приложение выполняет вариант использования [Загрузить расписание](#download_schedule) для каждой группы в списке сохраненных групп;
2. Вариант использования завершается.

<a name="download_schedule"/>

## 2.11 Загрузить расписание 

**Описание.** Вариант использования "Загрузить расписание" загружает расписание сохраненное с .
**Предусловиe** Приложение имеет выход с сеть интернет.
**Основной поток.**
1. Вариант использования начинается, когда пользователь запускает приложение.
2. Приложение выполняет запрос на интрернет-ресурс iis.bsuir.by с соответсвующими параметрами;
3. Полученные данные он записывает в соответсвующий файл;
2. Вариант использования завершается.

