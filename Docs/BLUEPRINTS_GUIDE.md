# Гид по созданию Blueprints в Unreal Engine 5

Все C++ классы уже написаны. Теперь в редакторе UE5 создай Blueprint-классы на их основе:

## Игрок
- **BP_EchoCharacter** (наследуй от `AEchoCharacter`) — добавь на него компоненты:
  - `UStealthManager`
  - `UEchoLayerComponent`
  - `UAlarmSystem`
  - `UInventoryComponent`
  - `UPerkTree`
  - `UContractManager`
  - `UBaseHubManager`

## Оружие
- **BP_Weapon_Osa** (от `AWeaponModular`) — ПП «Оса», глушитель, тихий.
- **BP_Weapon_Klinok** (от `AWeaponModular`) — штурмовая винтовка «Клинок».
- **BP_Weapon_Molot** (от `AWeaponModular`) — дробовик «Молот».
- **BP_Weapon_Igla** (от `AWeaponModular`) — снайперская «Игла».
- **BP_Weapon_Ten** (от `AWeaponModular`) — пистолет «Тень».
- **BP_Weapon_Razryv** (от `AWeaponModular`) — ЭМИ-винтовка «Разрыв».

## Гаджеты
- **BP_Gadget_EchoScanner** (от `AEchoScanner`)
- **BP_Gadget_SensorJammer** (от `ASensorJammer`)
- **BP_Gadget_ReconDrone** (от `AReconDrone`)
- **BP_Gadget_RealityAnchor** (от `ARealityAnchor`)
- **BP_Gadget_FalseSignal** (от `AFalseSignal`)
- **BP_Gadget_HackerTool** (от `AHackerTool`)
- **BP_Gadget_Medkit** (от `AMedkit`)

## Враги (Pawn + Controller)
- **BP_AI_Patrol** (контроллер от `AAI_Patrol`, pawn от Character)
- **BP_AI_Drone** (контроллер от `AAI_Drone`, pawn от Pawn с летающим движением)
- **BP_AI_Phantom** (контроллер от `AAI_Phantom`)
- **BP_AI_Turret** (контроллер от `AAI_Turret`, стационарный актер)
- **BP_AI_Sniper** (контроллер от `AAI_Sniper`)
- **BP_AI_Swarm** (контроллер от `AAI_Swarm`, несколько актеров)
- **BP_AI_Titan** (контроллер от `AAI_Titan`, большой босс-актер)

## Лут
- **BP_Loot_DataStick** (от `ADataStick`)
- **BP_Loot_Terminal** (от `ATerminal`)
- **BP_Loot_Corpse** (от `ACorpse`)
- **BP_Loot_Keycard**, **BP_Loot_Document** (от `ALootItemBase`)

## Эвакуация
- **BP_ExtractionPoint** (от `AExtractionPoint`) —ставь на карте, активируй через AlarmSystem.

## Процедурная генерация
- **BP_Anchor_ServerRoom**, **BP_Anchor_GuardRoom**, **BP_Anchor_Lift**, **BP_Anchor_Armory** (от `AAnchorRoom`)
- **BP_Room_Corridor**, **BP_Room_Hall** (от `AProceduralRoom`)
- **BP_DungeonGenerator** (от `AProceduralDungeonGenerator`) — запусти на старте уровня.

## UI / HUD
- Создай **UMG** виджеты:
  - `WBP_HUD` — здоровье, броня, патроны, тревога, Эхо-заряд, цели, компас.
  - `WBP_HUD_EchoLayer` — фиолетовая сетка, глитчи, ложные метки.
  - `WBP_Briefing` — карта, чек-лист целей, разведданные.
  - `WBP_HubMenu` — база, верстак, медотсек, архив, оружейная.
  - `WBP_PerkTree` — дерево перков.

## Настройка в редакторе
1. Открой `ECHO_PROTOCOL.uproject` в UE5.
2. В **Content Browser** создай папки по структуре `Content/Blueprints`, `Content/Maps`, `Content/Materials`.
3. Создай вышеописанные Blueprints.
4. Настрой **DefaultGameMode** на `AEchoGameModeBase` в `DefaultGame.ini` или через Project Settings.
5. Настрой **DefaultPawnClass** на `BP_EchoCharacter`.
6. Настрой **PlayerControllerClass** на `AEchoPlayerController`.
7. Настрой **PlayerStateClass** на `AEchoPlayerState`.
8. В **Project Settings → Input** добавь действия: Fire, Reload, Crouch, Prone, Slide, EchoToggle, Interact, UseGadget.
9. Собери проект в Visual Studio (Development Editor).
10. Создай карты: `M_Hub`, `M_Cobalt`, `M_Sigma`, `M_Depths`, `M_Quartz`, `M_EchoCore`.
