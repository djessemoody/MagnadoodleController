function bio=project6_modelbio
bio = [];
bio(1).blkName='Derivative1';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[1,1];
bio(1).sigWidth=1;
bio(1).sigAddress='&project6_model_B.Derivative1';
bio(1).ndims=2;
bio(1).size=[];

bio(getlenBIO) = bio(1);

bio(2).blkName='Gain';
bio(2).sigName='';
bio(2).portIdx=0;
bio(2).dim=[3,1];
bio(2).sigWidth=3;
bio(2).sigAddress='&project6_model_B.Gain[0]';
bio(2).ndims=2;
bio(2).size=[];


bio(3).blkName='Kd';
bio(3).sigName='';
bio(3).portIdx=0;
bio(3).dim=[1,1];
bio(3).sigWidth=1;
bio(3).sigAddress='&project6_model_B.Kd';
bio(3).ndims=2;
bio(3).size=[];


bio(4).blkName='Ki';
bio(4).sigName='';
bio(4).portIdx=0;
bio(4).dim=[1,1];
bio(4).sigWidth=1;
bio(4).sigAddress='&project6_model_B.Ki';
bio(4).ndims=2;
bio(4).size=[];


bio(5).blkName='Kp';
bio(5).sigName='';
bio(5).portIdx=0;
bio(5).dim=[1,1];
bio(5).sigWidth=1;
bio(5).sigAddress='&project6_model_B.Kp';
bio(5).ndims=2;
bio(5).size=[];


bio(6).blkName='angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees';
bio(6).sigName='Motor Position';
bio(6).portIdx=0;
bio(6).dim=[1,1];
bio(6).sigWidth=1;
bio(6).sigAddress='&project6_model_B.MotorPosition';
bio(6).ndims=2;
bio(6).size=[];


bio(7).blkName='gain';
bio(7).sigName='Setpoint';
bio(7).portIdx=0;
bio(7).dim=[1,1];
bio(7).sigWidth=1;
bio(7).sigAddress='&project6_model_B.Setpoint';
bio(7).ndims=2;
bio(7).size=[];


bio(8).blkName='Integrator1';
bio(8).sigName='';
bio(8).portIdx=0;
bio(8).dim=[1,1];
bio(8).sigWidth=1;
bio(8).sigAddress='&project6_model_B.Integrator1';
bio(8).ndims=2;
bio(8).size=[];


bio(9).blkName='Saturation';
bio(9).sigName='';
bio(9).portIdx=0;
bio(9).dim=[1,1];
bio(9).sigWidth=1;
bio(9).sigAddress='&project6_model_B.Saturation';
bio(9).ndims=2;
bio(9).size=[];


bio(10).blkName='Channel 0 of  Encoder Inputs ';
bio(10).sigName='';
bio(10).portIdx=0;
bio(10).dim=[1,1];
bio(10).sigWidth=1;
bio(10).sigAddress='&project6_model_B.Channel0ofEncoderInputs';
bio(10).ndims=2;
bio(10).size=[];


bio(11).blkName='Sum1';
bio(11).sigName='Error Signal';
bio(11).portIdx=0;
bio(11).dim=[1,1];
bio(11).sigWidth=1;
bio(11).sigAddress='&project6_model_B.ErrorSignal';
bio(11).ndims=2;
bio(11).size=[];


bio(12).blkName='Sum4';
bio(12).sigName='';
bio(12).portIdx=0;
bio(12).dim=[1,1];
bio(12).sigWidth=1;
bio(12).sigAddress='&project6_model_B.Sum4';
bio(12).ndims=2;
bio(12).size=[];


function len = getlenBIO
len = 12;

