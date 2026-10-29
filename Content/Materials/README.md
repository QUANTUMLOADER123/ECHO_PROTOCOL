# Content/Materials

PBR-материалы под стиль «чистый милитари-техно»:

- `M_Metal_Industrial` — ржавчина, сталь, конвейеры (Завод «Кобальт»)
- `M_Tile_White` — белый кафель, стерильность (Лаборатория «Сигма»)
- `M_Concrete_Dark` — бетон метро, вода, фонари (Метро «Глубина»)
- `M_Apartment_Ruined` — неон, дождь, destroyed квартиры (Жилой сектор «Кварц»)
- `M_Glitch_Abstract` — чёрно-белые переходы, глитчи (Ядро «ЭХО»)
- `M_EchoLayer_PostProcess` — фиолетовая сетка, контуры, глитч-линии (постпроцесс Эхо-слоя)

Настройка постпроцесса для Эхо-слоя:
1. Создай `PP_EchoLayer` (Post Process Volume).
2. Включи Chromatic Aberration, Vignette, Color Grading.
3. Активируй/деактивируй через Blueprint при переключении `UEchoLayerComponent`.
