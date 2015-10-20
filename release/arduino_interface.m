% this needs to be done beforehand
% myduino = arduino('COM3');

function arduino_interface(myduino,goalValue)
% myduino    arduino object
% goalValue  position setpoint on SoftPot (range 0 to 1023)
maxpower = 255;
minpower = 80;
pinMode(myduino, 12, 'output');
pinMode(myduino, 9, 'output');
myduino.digitalWrite(9, 1);
analogWrite(myduino, 3, maxpower);
tolerance = 30;
tolerance2 = 3;

done = 0;

while (done == 0)
    sensorValue = myduino.analogRead(4);
    if ((sensorValue < 240) && (goalValue <= sensorValue)) || ((sensorValue > 990 && sensorValue < goalValue))
        myduino.digitalWrite(9,1);
        done = 1;
        break;
    elseif (sensorValue < goalValue + tolerance && sensorValue > goalValue - tolerance)
        myduino.digitalWrite(9,1);
        
        sensorValue = myduino.analogRead(4);
        if (sensorValue < goalValue + tolerance2 && sensorValue > goalValue - tolerance2)
            done = 1;
            break; 
        else 
            tolerance = tolerance2;
            analogWrite(myduino, 3, minpower);
        end;
        
    elseif (sensorValue > goalValue) && (goalValue ~= -1)
        myduino.digitalWrite(12,1);
        myduino.digitalWrite(9,0);
    elseif (sensorValue < goalValue) && (goalValue ~= -1)
        myduino.digitalWrite(12,0);
        myduino.digitalWrite(9,0);
    end
end

