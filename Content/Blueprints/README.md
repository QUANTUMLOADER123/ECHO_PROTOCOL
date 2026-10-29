# Content/Blueprints

Здесь создаются Blueprints в редакторе Unreal Engine 5:

- `BP_EchoCharacter` — класс игрока (наследуется от `AEchoCharacter`)
- `BP_StealthManager` — добавлен как компонент на персонажа
- `BP_EchoLayerComponent` — компонент переключения слоёв реальности
- `BP_AlarmSystem` — компонент шкалы тревоги (на GameState или отдельном акторе)
- `BP_ExtractionPoint` — точка эвакуации
- `BP_AI_Patrol`, `BP_AI_Drone`, `BP_AI_Phantom`, `BP_AI_Turret`, `BP_AI_Sniper`, `BP_AI_Swarm`, `BP_AI_Titan` — враги (наследуются от `AAIControllerBase` + свои pawn-классы)
- `BP_Item_DataStick`, `BP_Item_Terminal`, `BP_Item_Loot` — предметы лута

Создавай их через окно **Content Browser → Blueprint Class**.
