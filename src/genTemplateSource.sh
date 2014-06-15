#!/bin/bash

templateFile=$1    # template file is the input.
sourceFile=$2      # source file is the output
                     # but this script will only generate it to stdout.

# convert path/filename_datasuffix.ext  -->  datasuffix
suffix=${sourceFile%.*}  # remove extension.
suffix=${suffix##*_}     # remote up to and including last _

case "_${suffix}" in 

_f) 
        type=float ;;
_u8)
        type=uint8_t ;;
*)
        type=unknown_suffix_in_genTemplateSource_sh ;;

esac

cat ${templateFile} \
    | sed "s/_DATASUFFIX/_${suffix}/" \
    | sed "s/DATATYPE/${type}/" 


