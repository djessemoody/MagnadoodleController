  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (project6_model_P)
    ;%
      section.nData     = 53;
      section.data(53)  = dumData; %prealloc
      
	  ;% project6_model_P.Anglesetpoint_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% project6_model_P.gain_Gain
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P1_Size
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P2_Size
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P2
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P3_Size
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P3
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 10;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P4_Size
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 11;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P4
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P5_Size
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P5
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 16;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P6_Size
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 17;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P6
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 19;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P7_Size
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 20;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P7
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 22;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P8_Size
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 23;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P8
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 25;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P9_Size
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 26;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P9
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 28;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P10_Siz
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 29;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P10
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 31;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P11_Siz
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 32;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P11
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 34;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P12_Siz
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 35;
	
	  ;% project6_model_P.Channel0ofEncoderInputs_P12
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 37;
	
	  ;% project6_model_P.angular_positionrelative_countC
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 38;
	
	  ;% project6_model_P.Kp_Gain
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 39;
	
	  ;% project6_model_P.Integrator1_IC
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 40;
	
	  ;% project6_model_P.Ki_Gain
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 41;
	
	  ;% project6_model_P.Kd_Gain
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 42;
	
	  ;% project6_model_P.Saturation_UpperSat
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 43;
	
	  ;% project6_model_P.Saturation_LowerSat
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 44;
	
	  ;% project6_model_P.Darknesssetpoint_Value
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 45;
	
	  ;% project6_model_P.Channel0Controlsignaltomotorthr
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 46;
	
	  ;% project6_model_P.Channel0Controlsignaltomotort_p
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 48;
	
	  ;% project6_model_P.Channel0Controlsignaltomotort_a
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 49;
	
	  ;% project6_model_P.Channel0Controlsignaltomotort_n
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 51;
	
	  ;% project6_model_P.Channel0Controlsignaltomotort_l
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 53;
	
	  ;% project6_model_P.Channel0Controlsignaltomotort_c
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 55;
	
	  ;% project6_model_P.Channel0Controlsignaltomotort_b
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 57;
	
	  ;% project6_model_P.Channel0Controlsignaltomotort_i
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 59;
	
	  ;% project6_model_P.Channel0Controlsignaltomotort_f
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 60;
	
	  ;% project6_model_P.Channel0Controlsignaltomotort_m
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 62;
	
	  ;% project6_model_P.Channel0Controlsignaltomotor_pp
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 64;
	
	  ;% project6_model_P.Channel0Controlsignaltomotort_j
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 66;
	
	  ;% project6_model_P.Channel0Controlsignaltomotort_h
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 68;
	
	  ;% project6_model_P.Channel0Controlsignaltomotor_l1
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 70;
	
	  ;% project6_model_P.Channel0Controlsignaltomotort_d
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 71;
	
	  ;% project6_model_P.Channel0Controlsignaltomotor_co
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 73;
	
	  ;% project6_model_P.Channel0Controlsignaltomotor_np
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 74;
	
	  ;% project6_model_P.Channel0Controlsignaltomotort_e
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 76;
	
	  ;% project6_model_P.Gain_Gain
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 77;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (project6_model_B)
    ;%
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% project6_model_B.Setpoint
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% project6_model_B.Channel0ofEncoderInputs
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% project6_model_B.MotorPosition
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% project6_model_B.ErrorSignal
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% project6_model_B.Kp
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% project6_model_B.Integrator1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% project6_model_B.Ki
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% project6_model_B.Derivative1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% project6_model_B.Kd
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% project6_model_B.Sum4
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% project6_model_B.Saturation
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% project6_model_B.Gain
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (project6_model_DWork)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% project6_model_DWork.Derivative1_RWORK.TimeStampA
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% project6_model_DWork.Channel0Controlsignaltomotorthr
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% project6_model_DWork.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% project6_model_DWork.Channel0ofEncoderInputs_IWORK
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% project6_model_DWork.Channel0Controlsignaltomotort_j
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 3;
	
	  ;% project6_model_DWork.SFunction_IWORK.AcquireOK
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 4;
	
	  ;% project6_model_DWork.SFunction_IWORK_e.AcquireOK
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 5;
	
	  ;% project6_model_DWork.SFunction_IWORK_a.AcquireOK
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 6;
	
	  ;% project6_model_DWork.SFunction_IWORK_aj.AcquireOK
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 129339729;
  targMap.checksum1 = 1760856200;
  targMap.checksum2 = 2524941749;
  targMap.checksum3 = 2094873264;

