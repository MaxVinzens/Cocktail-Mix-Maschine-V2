PROGRAM _CYCLIC	
	IF Zustand = TRUE THEN		
		//Hier kommt der Befehl zum Anzeigen dert Startseite hin
		OutVentil1 := FALSE;OutVentil2 := FALSE;OutVentil3 := FALSE;OutVentil4 := FALSE;OutVentil5 := FALSE;OutVentil6 := FALSE;
		OutVentil7 := FALSE;OutVentil8 := FALSE;OutLampeRot := FALSE;OutLampeGruen := FALSE;OutPumpe := FALSE;OutMotorEis := FALSE;
		//Wenn Softbutton für die Shots gedrückt wird wird in Zustand 2 gesprungen
		IF ButtonHShot = TRUE THEN
			Zustand := 2;
		END_IF
		//Wenn Softbutton für die Cocktails gedrückt wird wird in Zustand 4 gesprungen
		IF ButtonHCock = TRUE THEN
			Zustand := 4;
		END_IF
	END_IF
END_PROGRAM
