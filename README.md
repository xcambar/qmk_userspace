# Luz — keymap conventions for 3x6+3 keyboards

![](./header.jpeg)

**Luz** (Spanish: *luz* /luθ/, "light") completes your favourite alpha layout (Graphite, Focal, Canary... or QWERTY if you will) and turns it into a ready-to-use keymap. Since an alpha layout typically only dictates where the letters go, Luz supplies everything else to actually be productive (symbols, numbers, navigation, editing, modifiers, accents) as one consistent, ready-made set of conventions and features.

Luz isn't itself a layout; it's the *framework* a layout drops into. Each concrete keymap is a
**variant**:

| Variant | Letters | Keymap |
|---------|---------|--------|
| **Luz for Gallium** | Gallium East | [`luz_for_gallium`](./keyboards/6x3_3/keymaps/luz_for_gallium/README.md) |
| **Luz for Enthium** | Enthium | [`luz_for_enthium`](./keyboards/6x3_3/keymaps/luz_for_enthium/README.md) |
| **Luz for Colemak-DH** | Colemak Mod-DH (matrix) | [`luz_for_colemak_dh`](./keyboards/6x3_3/keymaps/luz_for_colemak_dh/README.md) |
| **Luz for QWERTY** | QWERTY | [`luz_for_qwerty`](./keyboards/6x3_3/keymaps/luz_for_qwerty/README.md) |

New variants are very welcome - see [Contributing variants](#contributing-variants).

(Another keymap, `zen`, is also in the repository but unrelated to Luz: a minimal QWERTY fallback for early bring-up or recovery. It might be deprecated eventually.)

## What you get, out of the box

> [!NOTE]
> The diagrams below are simplified to highlight each feature; they don't show every key. For a complete overview, see each variant's README ([Luz for Gallium](./keyboards/6x3_3/keymaps/luz_for_gallium/README.md) · [Luz for Enthium](./keyboards/6x3_3/keymaps/luz_for_enthium/README.md) · [Luz for Colemak-DH](./keyboards/6x3_3/keymaps/luz_for_colemak_dh/README.md) · [Luz for QWERTY](./keyboards/6x3_3/keymaps/luz_for_qwerty/README.md)).

### BASE layer — alphas, mods & layers

- **Bottom-row mods** Mods sit under the less frequent letters.
- **A lightweight thumb cluster** Plain Shift with Caps Word on double tap, layer holds, Enter, Space.
- **OS-dependent Cmd/Ctrl key** (`⌘C` on macOS, `Ctrl-C` on Linux) sits on the inner index column, the lightest pair in any layout. The home row itself carries no dual-function keys at all.

![BASE — the Luz frame](./keyboards/6x3_3/luz/keymap_drawer/BASE.svg)

### Numbers & Symbols

- **A rethought symbol vocabulary.** The symbol set is redesigned for mnemonics and frequency, and every symbol's Shift gives a *related* glyph (`(` shifts to `<`, `{` to `[`, `=` to `+`).
- **Digits on the left hand.** The symbols layer turns the left hand into a number pad: `1 2 3` across the home row with `0` beside them, `4 5 6` below, `7 8 9` above. Arranged so that the digits you reach for most sit under your fingers.
- **Modifiers that stay put while you're on the symbols layer.** Hold `Ctrl` (or `Alt`, or `Cmd`) on the base layer, enter the symbols layer, and the modifiers stay held until you leave the layer. Shift is the exception, because it's first-class on the symbols layer. No finger stays pinned on a modifier while the rest of that hand works the number pad. Releasing the layer releases everything.

![SYMBOLS — numbers & symbols](./keyboards/6x3_3/luz/keymap_drawer/SYMBOLS.svg)

### Navigation & Editing

- **A cursor cluster that doubles as an editor.** The right hand is a modifier-free inverted-T of arrows, with distance-from-home meaning distance-moved (character, word, line, page). **Triggers on the left hand** add extra modes onto that same cluster: one turns the motions into **select**, one into **delete** (by character/word/line), one drives **browser tabs**: the right hand keeps moving, the left hand picks the mode.

![EXTEND — navigation & editing](./keyboards/6x3_3/luz/keymap_drawer/EXTEND.svg)
![Navigation modes](./keyboards/6x3_3/keymaps/luz_for_gallium/keymap_drawer/04_MODES.svg)

### Compose — accents, without a layer of its own

Not a layer: a chord armed from BASE, consumed by the next key.

- **Diacritics through Compose.** Press `Shift` then `Space` — both thumbs, the same two keys on every variant — and the next key adds an accent (`é à ü ô ñ`, plus `ç` and `€` outright), so writing beyond plain ASCII is first-class, not an afterthought. Whatever Compose doesn't cover stays reachable on AltGr, for completeness.

![Compose & diacritics](./keyboards/6x3_3/keymaps/luz_for_gallium/keymap_drawer/05_DIACRITICS.svg)

---

## Make it personal

Luz fills the keys you actually need, but it **deliberately leaves blanks** on
several layers. Those are yours: map whatever suits
your workflow onto them, on any layer, without disturbing the shared frame.

Go further whenever you like — swap the editing commands on the navigation layer, privilege
different symbols onto your base layer, tuck something under the navigation thumb. And if you
ever want to check that a change still leaves you compatible with the other variants,
[`LUZ.spec.md`](./LUZ.spec.md) opens with a short checklist you can read in a minute. It's
there to keep your keymap portable, not to fence it in.

---

## Contributing variants

Luz is built to grow, and **new variants are very welcome.** If your favourite alpha layout (Graphite, Focal, Canary, Dvorak…) doesn't have one yet, take the existing variants as working examples to copy, and [`LUZ.spec.md`](./LUZ.spec.md) is the contract a variant follows.

Open an issue to discuss, or send a pull request: community-driven variants are exactly how Luz is meant to spread.

---

## Building

I have run these keymaps on:

| MCU | Example keyboard |
|-----|------------------|
| STM32 | **Kaly42** (`kaly/kaly42`) |
| RP2040 | **Cantor Pro v3** (`42keebs/cantor_pro/v3/left`) |

Build a single target, or all of them at once:

```bash
qmk compile -kb 42keebs/cantor_pro/v3/left -km luz_for_gallium
qmk userspace-compile
```

## Going further

- [`LUZ.spec.md`](./LUZ.spec.md) — the exact, implementation-facing contract: every layer, keycode, position, and rule.
- [`TUNING.md`](./TUNING.md) — four tap-hold settings left deliberately open, with the arguments on each side.
- The variant READMEs ([Luz for Gallium](./keyboards/6x3_3/keymaps/luz_for_gallium/README.md), [Luz for Enthium](./keyboards/6x3_3/keymaps/luz_for_enthium/README.md), [Luz for Colemak-DH](./keyboards/6x3_3/keymaps/luz_for_colemak_dh/README.md)) — diagrams and per-layout specifics.
- [`keyboards/6x3_3/luz/`](./keyboards/6x3_3/luz/) — the shared code the variants compile against.

## Inspiration

- **[HandsDown](https://sites.google.com/alanreiser.com/handsdown)** — semantic, platform-aware editing commands
- **[Miryoku](https://github.com/manna-harbour/miryoku)** — minimal, consistent layers built on home-row mods
- **[Seniply](https://stevep99.github.io/seniply/)** — the Extend layer: one-handed navigation and editing without leaving home
- **[Anymak](https://github.com/rpnfan/Anymak/)** — a complete keymap designed to sit on top of any alpha layout
- **[Gallium](https://github.com/GalileoBlues/Gallium) East** & **[Enthium](https://github.com/sunaku/enthium)** — the alpha layouts
- **Pascal Getreuer's QMK work** — Chordal Hold, Caps Word, and the wider tap-hold tuning vocabulary
- **Callum-style oneshot modifiers** — an early influence, since fully replaced by layer-scoped latches and plain momentary mods
- **[keymap-drawer](https://github.com/caksoylar/keymap-drawer)** — the layer diagrams

## License

GPL-2.0-or-later (following QMK licensing)
