# QMK Userspace

## Project Structure

Two keyboards share the same `split_3x6_3` (6 columns, 3 rows + 3 thumb keys per side) layout.

### Keyboards
- **Kaly42** (`kaly/kaly42`) - STM32-based split keyboard
- **Cantor Pro v3** (`42keebs/cantor_pro/v3/left`) - RP2040-based split keyboard by 42Keebs

### Shared Keymaps
Keymaps live in `keyboards/6x3_3/keymaps/` and are symlinked to both keyboards:

```
keyboards/6x3_3/keymaps/
├── crafted/    # Feature-rich keymap (dead keys, semantic keys, alt symbols, mod morphs, etc.)
└── zen/        # Minimal QWERTY keymap (3 layers: BASE, CODE, NAV)

keyboards/kaly/kaly42/keymaps/
├── crafted -> ../../../6x3_3/keymaps/crafted
└── zen -> ../../../6x3_3/keymaps/zen

keyboards/42keebs/cantor_pro/v3/left/keymaps/
├── crafted -> ../../../../../6x3_3/keymaps/crafted
└── zen -> ../../../../../6x3_3/keymaps/zen
```

### Build Configuration (`qmk.json`)
```json
{
    "userspace_version": "1.1",
    "build_targets": [
        ["kaly/kaly42", "crafted"],
        ["kaly/kaly42", "zen"],
        ["42keebs/cantor_pro/v3/left", "crafted"],
        ["42keebs/cantor_pro/v3/left", "zen"]
    ]
}
```

## Compile Commands

Build all targets:
```sh
qmk userspace-compile
```

Build a single target:
```sh
qmk compile -kb kaly/kaly42 -km crafted
qmk compile -kb kaly/kaly42 -km zen
qmk compile -kb 42keebs/cantor_pro/v3/left -km crafted
qmk compile -kb 42keebs/cantor_pro/v3/left -km zen
```

## Key Position Reference (split_3x6_3)

```
┌────┬────┬────┬────┬────┬────┐       ┌────┬────┬────┬────┬────┬────┐
│  0 │  1 │  2 │  3 │  4 │  5 │       │  6 │  7 │  8 │  9 │ 10 │ 11 │
├────┼────┼────┼────┼────┼────┤       ├────┼────┼────┼────┼────┼────┤
│ 12 │ 13 │ 14 │ 15 │ 16 │ 17 │       │ 18 │ 19 │ 20 │ 21 │ 22 │ 23 │
├────┼────┼────┼────┼────┼────┤       ├────┼────┼────┼────┼────┼────┤
│ 24 │ 25 │ 26 │ 27 │ 28 │ 29 │       │ 30 │ 31 │ 32 │ 33 │ 34 │ 35 │
└────┴────┴────┴────┴────┴────┘       └────┴────┴────┴────┴────┴────┘
                  ┌────┬────┬────┐ ┌────┬────┬────┐
                  │ 36 │ 37 │ 38 │ │ 39 │ 40 │ 41 │
                  └────┴────┴────┘ └────┴────┴────┘
```

## Notes
- The Cantor Pro keyboard definition files live in the main QMK firmware repo (`~/qmk_firmware/keyboards/42keebs/cantor_pro/`), not in this userspace
- The Cantor Pro v3 uses RP2040 with double-tap reset bootloader
- Firmware output files are `.bin` for Kaly42 and `.uf2` for Cantor Pro
