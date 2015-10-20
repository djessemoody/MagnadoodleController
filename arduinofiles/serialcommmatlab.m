arduino=serial('COM3','BaudRate',9600); % create serial communication object on port COM4

global goalvalue;
goalvalue=int8(1000);
done = 0;

fopen(arduino);
%fprintf(arduino, '%d', cast(goalvalue,'uint8'));
fwrite(arduino, goalvalue,'int8');

fprintf('Moving...\n');
while done ~= 1
    done = fread(arduino,1);
    fprintf('Value is %d\n',done);
end
fprintf('Done!\n');

fclose(arduino);