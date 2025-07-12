#!/bin/bash
pandoc general_info/dev_tricks.md -o pages/build/dev_tricks.html --standalone --css=../style.css
pandoc general_info/docker.md -o pages/build/docker.html --standalone --css=../style.css