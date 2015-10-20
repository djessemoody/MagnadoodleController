
=serial('COM3','BaudRate',9600)% s=serial('COM1','BaudRate',9600)
%set(s, ‘ Terminator’, ‘LF’); % Default terminator is \n
set(s,‘DataBits’, 8);
set(s,‘StopBits’, 1);

fopen(s);
for i = 1:50
  fwrite(s, i, 'uint8', 'sync');
  rx(i) = fread(s, 1);
end

fclose(s);