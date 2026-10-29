# Чек-лист импорта ассетов в Unreal Engine 5

## Перед импортом
1. Установить UE5 (5.3+) через Epic Games Launcher
2. Создать пустой проект Third Person или Blank
3. Скопировать `Source/` из этого репозитория в проект
4. Запустить `GenerateProjectFiles.bat`
5. Открыть `.sln` в Visual Studio 2022, собрать

## Импорт моделей (FBX)
```
Для каждой модели:
1. Content Browser → Import → выбрать .fbx
2. Skeletal Mesh: для оружия, врагов, игрока
3. Static Mesh: для окружения, реквизита
4. Normal Import Method: Import Normalals
5. Сгенерировать LODs (Auto) для моделей > 2000 полигонов
6. Сохранить в соответствующей папке Content/Models/
```

## Импорт текстур
```
Для каждой текстуры:
1. Content Browser → Import → выбрать .png/.tga
2. Texture Group: World (окружение), Character (персонажи), UI (интерфейс)
3. Compression: BC7 (Albedo/Roughness), BC5 (Normal)
4. Mip Gen Settings: Off for UI, On for 3D
5. Сохранить в Content/Textures/
```

## Создание материалов
```
1. Правый клик → Material → Название
2. Подключить текстуры: BaseColor, Normal, Roughness, Metallic
3. Для Эхо-слоя: Emissive + Post Process Material
4. Сохранить в Content/Materials/
```

## Создание звуков
```
1. Content Browser → Import → .wav
2. Right-click → Create Cue (Sound Cue)
3. Настроить Attenuation (затухание с расстоянием)
4. Сохранить в Content/Sounds/
```

## Создание Blueprint-классов
```
1. Content Browser → Blueprint Class
2. Выбрать базовый класс из списка (Character, Actor, Component)
3. Наследовать от соответствующего C++ класса
4. Добавить компоненты, настроить переменные
5. Скомпилировать и сохранить
```

## Упаковка игры
```
1. File → Package Project → Windows → No Editor (для теста) или Shipping (для релиза)
2. Выбрать папку для сборки
3. Дождаться завершения (10-30 мин)
4. Архивировать папку в .zip
5. Положить в Builds/
6. git add Builds/ && git commit && git push
```

## Оптимизация размера
- Удалить неиспользуемые ассеты (File → Audit → Size Map)
- Включить Texture Streaming
- Использовать Pak-файлы (UsePakFile=True в DefaultEngine.ini)
- Сжать текстуры перед импортом
