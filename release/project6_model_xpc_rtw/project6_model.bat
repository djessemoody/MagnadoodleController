call "%VS100COMNTOOLS%..\..\VC\vcvarsall.bat" 

cd .
nmake -f project6_model.mk  GENERATE_REPORT=0 EXT_MODE=1
@if errorlevel 1 goto error_exit
exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
