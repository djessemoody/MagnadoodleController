delete ( instrfind ( { 'Port' } , { 'COM3' } ) ) ;
arduino = serial ( 'COM3','BaudRate',9600 ) ;
lnum = 1;

fopen(arduino);

fprintf(arduino, 'a' + (lnum - 1));

fclose(arduino);