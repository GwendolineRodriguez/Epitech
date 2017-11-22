cat passwd | cut -d: -f 5 | grep -e 'theo1' -e 'steven1' -e 'arnaud1' -e 'pierre-jean' | sed -e 's/theo1/Wile E.Coyote'
