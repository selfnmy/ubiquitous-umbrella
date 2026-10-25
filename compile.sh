#!/bin/bash

rm -f *.pdf
python3 build_contents.py > contents.tex
xelatex -jobname=icpc-trd main.tex
xelatex -jobname=icpc-trd main.tex
xelatex -jobname=icpc-trd main.tex
find . -type f -regextype posix-extended -regex '^.+\.(aux|toc|bcf|blg|bbl|log|xml|out)$' -delete
rm -f contents.tex
