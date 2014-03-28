#!/bin/bash

export MY_RC=0

echo "Testing the lexer..."
pushd ../tests/lexer
for test_case in ./*; do
  echo "Running testcase $test_case..."
  ../../src/lexer_test $test_case/input 1>/dev/null 2>tmp_err
  export RC=$?

  export EXPECTED_RC="`cat $test_case/return_code`"
  if [ "$RC" != "$EXPECTED_RC" ]; then
    echo "Wrong return code for testcase $test_case! Expected $EXPECTED_RC but was $RC!"
    cat tmp_err
    export MY_RC=1
  fi

  rm tmp_err
done
popd

exit $MY_RC

