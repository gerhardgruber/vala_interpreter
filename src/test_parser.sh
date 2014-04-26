#!/bin/bash

. init_test.sh

export MY_RC=0

echo "Testing the parser..."
pushd ../tests/parser
for test_case in ./*; do
  echo -n "Running testcase $test_case... "
  ../../src/parser_test $test_case/input 1>$test_case/test_output 2>tmp_err
  export RC=$?

  export EXPECTED_RC="`cat $test_case/return_code`"
  if [ "$RC" != "$EXPECTED_RC" ]; then
    echo "[0;31m${bold}NOT OK${normal}[00m"
    echo "Wrong return code for testcase $test_case! Expected $EXPECTED_RC but was $RC!"
    cat tmp_err
    export MY_RC=1
  else
    diff $test_case/output $test_case/test_output
    export RC=$?
    if [ "$RC" != "0" ]; then
      echo "[0;31m${bold}NOT OK${normal}[00m"
      echo "Wrong output for testcase $test_case! Expected following output:"
      cat $test_case/output
      echo "But got:"
      cat $test_case/test_output
      export MY_RC=1
    else
      echo "[0;32m${bold}OK${normal}[00m"
    fi
  fi

  rm $test_case/test_output
  rm tmp_err
done
popd

exit $MY_RC

