#!/bin/bash
# Builds a landscape PDF from all individual layer YAML files.
# Requires: keymap-drawer (via uvx), ImageMagick (convert), ghostscript (gs)

set -euo pipefail
cd "$(dirname "$0")"

# Output filename derived from the keymap directory name
KEYMAP_NAME="$(basename "$(dirname "$(dirname "$(realpath "$0")")")")"

OUTDIR="$(mktemp -d)"
trap 'rm -rf "$OUTDIR"' EXIT

echo "Generating SVGs..."
for yml in [0-9]*.yml; do
    name="${yml%.yml}"
    uvx --from keymap-drawer keymap draw "$yml" > "$OUTDIR/$name.svg"
    echo "  $yml -> $name.svg"
done

echo "Converting SVGs to PNGs..."
for svg in "$OUTDIR"/*.svg; do
    png="${svg%.svg}.png"
    convert -density 150 "$svg" "$png"
done

echo "Composing landscape A4 pages..."
# A4 landscape at 150 DPI: 1754x1240 pixels
for png in "$OUTDIR"/*.png; do
    convert -size 1754x1240 xc:white \
        "$png" -gravity center -composite \
        "${png%.png}_a4.png"
done

echo "Merging into PDF..."
convert "$OUTDIR"/*_a4.png "$OUTDIR/pages.pdf"
gs -sDEVICE=pdfwrite -dNOPAUSE -dBATCH -dQUIET \
   -dDEVICEWIDTHPOINTS=842 -dDEVICEHEIGHTPOINTS=595 \
   -dFIXEDMEDIA -dPDFFitPage \
   -sOutputFile=${KEYMAP_NAME}.pdf \
   "$OUTDIR/pages.pdf"

echo "Done: ${KEYMAP_NAME}.pdf"
