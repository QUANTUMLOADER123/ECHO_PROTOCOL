# Инструкция по сборке ECHO PROTOCOL (Unreal Engine 5)

## 1. Подготовка компьютера
- Установи **Unreal Engine 5** (5.3+) через Epic Games Launcher.
- Установи **Visual Studio 2022** с нагрузкой "Разработка игр на C++".
- Установи Windows SDK 10.0.

## 2. Клонирование репозитория
```bash
git clone https://github.com/QUANTUMLOADER123/ECHO_PROTOCOL.git
cd ECHO_PROTOCOL
git checkout arena/559294b5-echo-protocol
```

## 3. Генерация файлов Visual Studio
Способ А (через редактор UE):
1. Запусти Unreal Editor.
2. Выбери `ECHO_PROTOCOL.uproject`.
3. Редактор спросит: "Would you like to build now?" — нажми **Yes**.
4. Дождись генерации `.sln` и `.vcxproj`.

Способ Б (через командную строку):
```
"C:\Program Files\Epic Games\UE_5.3\Engine\Build\BatchFiles\GenerateProjectFiles.bat"
```

## 4. Компиляция в Visual Studio
1. Открой `ECHO_PROTOCOL.sln` в Visual Studio 2022.
2. Выбери конфигурацию: **Development Editor** или **Shipping**, платформа **x64**.
3. Нажми **Build → Build Solution**.
4. Дождись окончания компиляции.

## 5. Создание контента в редакторе
1. Запусти UE Editor с проектом.
2. Создай Blueprints по гайду `Docs/BLUEPRINTS_GUIDE.md`.
3. Создай карты: `M_Hub`, `M_Cobalt`, `M_Sigma`, `M_Depths`, `M_Quartz`, `M_EchoCore`.
4. Настрой материалы, освещение, постпроцесс для Эхо-слоя.
5. Настрой NavMesh для ИИ.
6. Расставь `BP_ExtractionPoint`, враги, лут, якоря.

## 6. Упаковка игры (Package Project)
1. В редакторе: **File → Package Project → Windows → No Editor** (или Shipping).
2. Выбери папку для результата.
3. Дождись завершения (может занять 10–30 минут).

## 7. Архивация и пуш на GitHub
1. Архивируй папку со сборкой в `.zip`:
   ```
   Builds/ECHO_PROTOCOL_Windows_0.1.zip
   ```
2. Запушь в репозиторий:
   ```bash
   git add Builds/ECHO_PROTOCOL_Windows_0.1.zip
   git commit -m "Add game build v0.1"
   git push origin arena/559294b5-echo-protocol
   ```

## 8. Релиз на GitHub
1. Зайди на [github.com/QUANTUMLOADER123/ECHO_PROTOCOL/releases](https://github.com/QUANTUMLOADER123/ECHO_PROTOCOL/releases).
2. Создай новый Release, прикрепи `.zip` со сборкой.

## Оптимизация (меньше места + чёткий графон)
- Используй **URP / Mobile** или **Scalability** — для ПК поставь средние настройки.
- Включи **Texture Streaming** и **Occlusion Culling**.
- Убери неиспользуемые ассеты из `Content/` перед пакетом.
- В `DefaultEngine.ini` поставь `UsePakFile=True` и `bCompressCookedData=True`.
