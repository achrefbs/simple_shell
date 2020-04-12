#!/bin/bash
SHELL="./hsh"
EXPECTED="checker_output"
OUTPUT="output"

# test : /bin/ls

COMMAND="/bin/ls"
echo "$COMMAND" | sh > $EXPECTED
echo "$COMMAND" | $SHELL > $OUTPUT
echo "---------------"
echo "expected output"
echo "---------------"
cat $EXPECTED
echo "---------------"
sleep 1
echo "your output"
echo "---------------"
cat $OUTPUT
if   [[ $(cat $EXPECTED) == $(cat $OUTPUT) ]]; then
        echo -e "[\033[32m-----OK-----\033[37m]"
else
        echo -e "[\033[31m-----WRONG-----\033[37m]"
fi
sleep 1

# test : /bin/ls manu times with spaces
COMMAND="/bin/ls
     /bin/ls
/bin/ls     
  /bin/ls     "
echo "$COMMAND" | sh > $EXPECTED
echo "$COMMAND" | $SHELL > $OUTPUT
echo "---------------"
echo "expected output"
echo "---------------"
cat $EXPECTED
echo "---------------"
sleep 1
echo "your output"
echo "---------------"
cat $OUTPUT
if   [[ $(cat $EXPECTED) == $(cat $OUTPUT) ]]; then
        echo -e "[\033[32m-----OK-----\033[37m]"
else
        echo -e "[\033[31m-----WRONG-----\033[37m]"
fi
sleep 1

# test : /bin/ls 3 times
COMMAND="/bin/ls
/bin/ls
/bin/ls"
echo "$COMMAND" | sh > $EXPECTED
echo "$COMMAND" | $SHELL > $OUTPUT
echo "---------------"
echo "expected output"
echo "---------------"
cat $EXPECTED
echo "---------------"
sleep 1
echo "your output"
echo "---------------"
cat $OUTPUT
if   [[ $(cat $EXPECTED) == $(cat $OUTPUT) ]]; then
        echo -e "[\033[32m-----OK-----\033[37m]"
else
        echo -e "[\033[31m-----WRONG-----\033[37m]"
fi
sleep 1

# test : medium size command
COMMAND="                                       /bin/ls                                                                                                                                                                                                                                                                                                                                                                                                                                                     "
echo "$COMMAND" | sh > $EXPECTED
echo "$COMMAND" | $SHELL > $OUTPUT
echo "---------------"
echo "expected output"
echo "---------------"
cat $EXPECTED
echo "---------------"
sleep 1
echo "your output"
echo "---------------"
cat $OUTPUT
if   [[ $(cat $EXPECTED) == $(cat $OUTPUT) ]]; then
        echo -e "[\033[32m-----OK-----\033[37m]"
else
        echo -e "[\033[31m-----WRONG-----\033[37m]"
fi
sleep 1

# test : ls with argumants
COMMAND="/bin/ls -la $outputdir/"
echo "$COMMAND" | sh > $EXPECTED
echo "$COMMAND" | $SHELL > $OUTPUT
echo "---------------"
echo "expected output"
echo "---------------"
cat $EXPECTED
echo "---------------"
sleep 1
echo "your output"
echo "---------------"
cat $OUTPUT
if   [[ $(cat $EXPECTED) == $(cat $OUTPUT) ]]; then
        echo -e "[\033[32m-----OK-----\033[37m]"
else
        echo -e "[\033[31m-----WRONG-----\033[37m]"
fi
sleep 1