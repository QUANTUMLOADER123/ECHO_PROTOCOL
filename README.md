# ECHO PROTOCOL

Стелс-экстракшн PvE от первого лица с элементами иммерсив-сима.  
Движок: **Unreal Engine 5** (C++).

## Что в репозитории
- `Docs/GDD.md` — полный дизайн-документ игры
- `Source/` — игровой код на C++ (системы стелса, Эхо-слой, тревога, эвакуация, ИИ)
- `Content/` — структура папок под ассеты (BP, карты, материалы, звуки — создаются в редакторе UE)
- `Builds/` — сюда клади готовые архивы со сборкой (.zip / .pak) для пуша на GitHub

## Как открыть и собрать (на твоём ПК)

1. Установи **Unreal Engine 5** через Epic Games Launcher.
2. Скалонируй репозиторий:
   ```bash
   git clone https://github.com/QUANTUMLOADER123/ECHO_PROTOCOL.git
   cd ECHO_PROTOCOL
   ```
3. Запусти **UE Editor**, выбери файлик `ECHO_PROTOCOL.uproject`.
4. Если редактор предложит «Build now» — согласись (сгенерируются файлы Visual Studio).
5. Открой `ECHO_PROTOCOL.sln` в Visual Studio 2022 и собери (Development Editor / Shipping).
6. В редакторе: **File → Package Project → Windows** → получишь готовую папку с игрой.
7. Архивируй папку со сборкой в `.zip`, положи в `Builds/` и запушь на GitHub.

## Ветка разработки
`arena/559294b5-echo-protocol`

## Лицензия
Внутренний проект.
