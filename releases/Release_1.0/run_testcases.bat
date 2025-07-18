@echo off
echo Running all test cases...

copy /Y testcases\case1\case1.csv testcases\case_input.csv > nul
app\app.exe
copy /Y app\output\output.csv testcases\case1\case1_outputs.csv > nul

copy /Y testcases\case2\case2.csv testcases\case_input.csv > nul
app\app.exe
copy /Y app\output\output.csv testcases\case2\case2_outputs.csv > nul

copy /Y testcases\case3\case3.csv testcases\case_input.csv > nul
app\app.exe
copy /Y app\output\output.csv testcases\case3\case3_outputs.csv > nul

del testcases\case_input.csv > nul

echo Done.
