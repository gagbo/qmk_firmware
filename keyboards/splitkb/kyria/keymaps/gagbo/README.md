# Kyria BÉPO layout

Kyria construit avec des clones de ProMicro (utilise avrdude pour le flash).

## Features

- Home row mods (GACS)

3 extra layers:

- Lower = symboles/numéros sans shift
- Raise = Media keys
- Adjust = RGB + tapmod adjust

## Flash

``` sh
qmk flash -kb splitkb/kyria -km gagbo -bl avrdude-split-left
qmk flash -kb splitkb/kyria -km gagbo -bl avrdude-split-right
```

## TODO

- [ ] Idées écrans
- [ ] Meilleure utilisation de touche en pinky gauche
- [ ] Changer les touches de la bottom row
- [ ] Rendre lower/raise symétriques sur la bottom row ?
