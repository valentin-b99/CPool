#!/bin/bash
sed -e "s/theo1/Wile E. Coyote/gi" -e "s/steven1/Daffy Duck/gi" -e "s/arnaud1/Porky Pig/gi" -e "s/pierre-jean/Marvin the Martian/gi" | grep -e "Wile E. Coyote" -e "Daffy Duck" -e "Porky Pig" -e "Marvin the Martian"
