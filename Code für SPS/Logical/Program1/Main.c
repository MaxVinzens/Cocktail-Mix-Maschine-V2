#include <bur/plctypes.h>
#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

_GLOBAL int r_pv;
int rand(void);
void srand(unsigned int seed);
//y = 0,072g/z*x-460g 4cl mit Berücksichtigung des Nachlaufs ca. 530
//1->Tequila 2->Vodka 3->Gin 4->Rum 5->Limettensaft 6->Orangensaft 7->Zitronensaft 8->Tonic Water
//ALTERNATIV 1->Tequila 2->Vodka 3->Gin 4->Rum 5->Limettensaft 6->Orangensaft 7->Ananassaft 8->Tonic Water
void _INIT ProgramInit(void)
{
	Zustand = 1;
	ShotFertig = 1;
	CocktailFertig = 1;
	Cocktail = 0;
	Shot = 0;
	OutLampeGruen = 1;
	Groessenfaktor = 1;
	FuellstandB1 = 9275;
	FuellstandB2 = 9275;
	FuellstandB3 = 9275;
	FuellstandB4 = 9275;
	FuellstandB5 = 9938;
	FuellstandB6 = 53000;
	FuellstandB7 = 53000;
	FuellstandB8 = 53000;
	Nachfuellen = 0;
	srand(12);
	Zufall = 0;
	ZufallsZutatG = 0;
	Durchgang = 1;
	ZufallZufall = 0;
	RButtonCock1 = 1;
	RButtonBKEis = 1;
	RButtonBGross = 1;
	RButtonShot1 = 1;
	FlagMotor = 0;
	Reinigung_1 = 0;
	Reinigung_2 = 0;
	Reinigung_3 = 0;
	Reinigung_4 = 0;
	Reinigung_5 = 0;
	Reinigung_6 = 0;
	Reinigung_7 = 0;
	Reinigung_8 = 0;
	Motor_Hand = 0;
}

void _CYCLIC ProgramCyclic(void)
{
	if(ButtonReset)
	{
		OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
		OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 0; OutLampeGruen = 1; OutPumpe = 0; OutMotorEis = 0;
		FuellstandB1 = 9275;
		FuellstandB2 = 9275;
		FuellstandB3 = 9275;
		FuellstandB4 = 9275;
		FuellstandB5 = 9938;
		FuellstandB6 = 53000;
		FuellstandB7 = 53000;
		FuellstandB8 = 53000;
		Zutat1Fertig = 0;
		Zutat2Fertig = 0;
		Zutat3Fertig = 0;
		Zutat4Fertig = 0;
		CocktailFertig = 1;
		ShotFertig = 1;
		IstGewicht = 0;
		StartGewicht = 0;
		Groessenfaktor = 1;
		ButtonReset = 0;
		Zustand = 1;
		Nachfuellen = 0;
		Zufall = 0;
		Durchgang = 1;
		ZufallZufall = 0;
		FlagMotor = 0;
		EisFertig = 0;
		Reinigung_1 = 0;
		Reinigung_2 = 0;
		Reinigung_3 = 0;
		Reinigung_4 = 0;
		Reinigung_5 = 0;
		Reinigung_6 = 0;
		Reinigung_7 = 0;
		Reinigung_8 = 0;
		Motor_Hand = 0;
	}
	// Durchlauf der verschiedenen Zustände
	if(Zustand == 1)
	{
		OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
		OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 0; OutLampeGruen = 1; OutPumpe = 0; OutMotorEis = 0;
		CocktailFertig = 1;
		ShotFertig = 1;
	}
	else if(Zustand == 2)
	{
		//Wahl des Shots
		if((!ShotFertig && RButtonShot1 && !Nachfuellen && InLichtschranke) || Zufall == 1)
		{
			OutVentil1 = 1; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
			OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
			IstGewicht = InAnalogWaage;
			if(IstGewicht - StartGewicht >= 530)
			{
				OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
				OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 0; OutLampeGruen = 1; OutPumpe = 0; OutMotorEis = 0;
				ShotFertig = 1;
				FuellstandB1 -= 530;
				Zufall = 0;
			}
			Shot = 1;
		}
		if((!ShotFertig && RButtonShot2 && !Nachfuellen && InLichtschranke) || Zufall == 2)
		{
			OutVentil1 = 0; OutVentil2 = 1; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
			OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
			IstGewicht = InAnalogWaage;
			if(IstGewicht - StartGewicht >= 530)
			{
				OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
				OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 0; OutLampeGruen = 1; OutPumpe = 0; OutMotorEis = 0;
				ShotFertig = 1;
				FuellstandB2 -= 530;
				Zufall = 0;
			}
			Shot = 2;
		}
		if((!ShotFertig && RButtonShot3 && !Nachfuellen && InLichtschranke) || Zufall == 3)
		{
			OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 1; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
			OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
			IstGewicht = InAnalogWaage;
			if(IstGewicht - StartGewicht >= 530)
			{
				OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
				OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 0; OutLampeGruen = 1; OutPumpe = 0; OutMotorEis = 0;
				ShotFertig = 1;
				FuellstandB3 -= 530;
				Zufall = 0;
			}
			Shot = 3;
		}
		if((!ShotFertig && RButtonShot4 && !Nachfuellen && InLichtschranke) || Zufall == 4)
		{
			OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 1; OutVentil5 = 0; OutVentil6 = 0;
			OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
			IstGewicht = InAnalogWaage;
			if(IstGewicht - StartGewicht >= 530)
			{
				OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
				OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 0; OutLampeGruen = 1; OutPumpe = 0; OutMotorEis = 0;
				ShotFertig = 1;
				FuellstandB4 -= 530;
				Zufall = 0;
			}
			Shot = 4;
		}
		if(!ShotFertig && RButtonShot5 && !Nachfuellen && InLichtschranke && Zufall == 0)
		{
			//Zufallsshot
			Zufall = rand() % 4 + 1;	
		}
	}
	else if(Zustand == 3)
	{	//Legspreader
		//Wahl des Cocktails
		if((!CocktailFertig && RButtonCock1 && !Nachfuellen && InLichtschranke) || Zufall == 1)
		{
			Cocktail = 1;
			//Massenanpassungsfaktor bei Größenwahl
			if(RButtonBKlein)
			{
				Groessenfaktor = 0.5;
			}
			if(RButtonBGross)
			{
				Groessenfaktor = 1;
			}
			//Das erste If wird so lange durchlaufen, bis der Motor für das Eis seine Endlage erreicht hat.
			//Oder es wird gar nicht durchlaufen, falls der Benutzer ohne Eis gklickt hat
			if(RButtonBEis && !EisFertig)
			{
				OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
				OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 0; OutMotorEis = 1;
				if(InEndlageMotor2)
				{
					FlagMotor = 1;
				}
				if(InEndlageMotor && FlagMotor)
				{
					OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
					OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 0; OutMotorEis = 0;
					EisFertig = 1;
					FlagMotor = 0;
					StartGewicht = InAnalogWaage;
				}
			}
			else
			{
				//Der If Zweig wird so lange durchlaufen, bis die erste Zutat fertig ist.
				//Anschließend wird nur noch der Else Zweig durchlaufen
				if(!Zutat1Fertig)
				{
					OutVentil1 = 1; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
					OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
					IstGewicht = InAnalogWaage;
					if(IstGewicht - StartGewicht >= 530 * Groessenfaktor)
					{
						OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
						OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
						Zutat1Fertig = 1;
						StartGewicht = InAnalogWaage;
					}
				}
				else
				{
					//Der If Zweig wird so lange durchlaufen, bis die zweite Zutat fertig ist.
					//Anschließend wird nur noch der Else Zweig durchlaufen
					if(!Zutat2Fertig)
					{
						OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 1; OutVentil5 = 0; OutVentil6 = 0;
						OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
						IstGewicht = InAnalogWaage;
						if(IstGewicht - StartGewicht >= 530 * Groessenfaktor)
						{
							OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
							OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
							Zutat2Fertig = 1;
							StartGewicht = InAnalogWaage;
						}
					}
					else
					{
						//Der If Zweig wird so lange durchlaufen, bis die dritte Zutat fertig ist.
						//Anschließend wird nur noch der Else Zweig durchlaufen
						if(!Zutat3Fertig)
						{
							OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 1;
							OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
							IstGewicht = InAnalogWaage;
							if(IstGewicht - StartGewicht >= 2000 * Groessenfaktor)
							{
								OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
								OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
								Zutat3Fertig = 1;
								StartGewicht = InAnalogWaage;
							}	
						}
						else
						{
							//Der If Zweig wird so lange durchlaufen, bis die vierte Zutat fertig ist.
							//Anschließend wird nur noch der Else Zweig durchlaufen
							if(!Zutat4Fertig)
							{
								OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 1; OutVentil6 = 0;
								OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
								IstGewicht = InAnalogWaage;
								if(IstGewicht - StartGewicht >= 265 * Groessenfaktor)
								{
									OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
									OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 0; OutLampeGruen = 1; OutPumpe = 0; OutMotorEis = 0;
									Zutat4Fertig = 1;
									CocktailFertig = 1;
									FuellstandB1 -= 530; FuellstandB4 -= 530; FuellstandB6 -= 2000; FuellstandB5 -= 265;
									Zufall = 0;
								}
							}		
						}
					}			
				}
			}
		}	
		if((!CocktailFertig && RButtonCock2 && !Nachfuellen && InLichtschranke) || Zufall == 2)
		{
			Cocktail = 2;
			//Scrumdriver
			//Massenanpassungsfaktor bei Größenwahl
			if(RButtonBKlein)
			{
				Groessenfaktor = 0.5;
			}
			if(RButtonBGross)
			{
				Groessenfaktor = 1;
			}
			//Das erste If wird so lange durchlaufen, bis der Motor für das Eis seine Endlage erreicht hat.
			//Oder es wird gar nicht durchlaufen, falls der Benutzer ohne Eis gklickt hat
			if(RButtonBEis && !EisFertig)
			{
				OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
				OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 0; OutMotorEis = 1;
				if(InEndlageMotor2)
				{
					FlagMotor = 1;
				}
				if(InEndlageMotor && FlagMotor)
				{
					OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
					OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 0; OutMotorEis = 0;
					EisFertig = 1;
					FlagMotor = 0;
					StartGewicht = InAnalogWaage;
				}
			}
			else
			{
				//Der If Zweig wird so lange durchlaufen, bis die erste Zutat fertig ist.
				//Anschließend wird nur noch der Else Zweig durchlaufen
				if(!Zutat1Fertig)
				{
					OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 1; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
					OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
					IstGewicht = InAnalogWaage;
					if(IstGewicht - StartGewicht >= 660 * Groessenfaktor)
					{
						OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
						OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
						Zutat1Fertig = 1;
						StartGewicht = InAnalogWaage;
					}
				}
				else
				{
					//Der If Zweig wird so lange durchlaufen, bis die zweite Zutat fertig ist.
					//Anschließend wird nur noch der Else Zweig durchlaufen
					if(!Zutat2Fertig)
					{
						OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
						OutVentil7 = 0; OutVentil8 = 1; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
						IstGewicht = InAnalogWaage;
						if(IstGewicht - StartGewicht >= 2385 * Groessenfaktor)
						{
							OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
							OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
							Zutat2Fertig = 1;
							StartGewicht = InAnalogWaage;
						}
					}
					else
					{
						//Der If Zweig wird so lange durchlaufen, bis die dritte Zutat fertig ist.
						//Anschließend wird nur noch der Else Zweig durchlaufen
						if(!Zutat3Fertig)
						{
							OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 1; OutVentil6 = 0;
							OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
							IstGewicht = InAnalogWaage;
							if(IstGewicht - StartGewicht >= 265 * Groessenfaktor)
							{
								OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
								OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 0; OutLampeGruen = 1; OutPumpe = 0; OutMotorEis = 0;
								Zutat3Fertig = 1;
								CocktailFertig = 1;
								FuellstandB3 -= 660; FuellstandB8 -= 2385; FuellstandB2 -= 265;
								Zufall = 0;
							}	
						}
					}			
				}
			}
		}
		if((!CocktailFertig && RButtonCock3 && !Nachfuellen && InLichtschranke) || Zufall == 3)
		{
			Cocktail = 3;
			//Gentle Ben
			//Massenanpassungsfaktor bei Größenwahl
			if(RButtonBKlein)
			{
				Groessenfaktor = 0.5;
			}
			if(RButtonBGross)
			{
				Groessenfaktor = 1;
			}
			//Das erste If wird so lange durchlaufen, bis der Motor für das Eis seine Endlage erreicht hat.
			//Oder es wird gar nicht durchlaufen, falls der Benutzer ohne Eis gklickt hat
			if(RButtonBEis && !EisFertig)
			{
				OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
				OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 0; OutMotorEis = 1;
				if(InEndlageMotor2)
				{
					FlagMotor = 1;
				}
				if(InEndlageMotor && FlagMotor)
				{
					OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
					OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 0; OutMotorEis = 0;
					EisFertig = 1;
					FlagMotor = 0;
					StartGewicht = InAnalogWaage;
				}
			}
			else
			{
				//Der If Zweig wird so lange durchlaufen, bis die erste Zutat fertig ist.
				//Anschließend wird nur noch der Else Zweig durchlaufen
				if(!Zutat1Fertig)
				{
					OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 1; OutVentil5 = 0; OutVentil6 = 0;
					OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
					IstGewicht = InAnalogWaage;
					if(IstGewicht - StartGewicht >= 660 * Groessenfaktor)
					{
						OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
						OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
						Zutat1Fertig = 1;
						StartGewicht = InAnalogWaage;
					}
				}
				else
				{
					//Der If Zweig wird so lange durchlaufen, bis die zweite Zutat fertig ist.
					//Anschließend wird nur noch der Else Zweig durchlaufen
					if(!Zutat2Fertig)
					{
						OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 1; OutVentil6 = 0;
						OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
						IstGewicht = InAnalogWaage;
						if(IstGewicht - StartGewicht >= 265 * Groessenfaktor)
						{
							OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
							OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
							Zutat2Fertig = 1;
							StartGewicht = InAnalogWaage;
						}
					}
					else
					{
						//Der If Zweig wird so lange durchlaufen, bis die dritte Zutat fertig ist.
						//Anschließend wird nur noch der Else Zweig durchlaufen
						if(!Zutat3Fertig)
						{
							OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
							OutVentil7 = 1; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
							IstGewicht = InAnalogWaage;
							if(IstGewicht - StartGewicht >= 1722 * Groessenfaktor)
							{
								OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
								OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
								Zutat3Fertig = 1;
								StartGewicht = InAnalogWaage;
							}	
						}
						else
						{
							//Der If Zweig wird so lange durchlaufen, bis die vierte Zutat fertig ist.
							//Anschließend wird nur noch der Else Zweig durchlaufen
							if(!Zutat4Fertig)
							{
								OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
								OutVentil7 = 0; OutVentil8 = 1; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
								IstGewicht = InAnalogWaage;
								if(IstGewicht - StartGewicht >= 660 * Groessenfaktor)
								{
									OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
									OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 0; OutLampeGruen = 1; OutPumpe = 0; OutMotorEis = 0;
									Zutat4Fertig = 1;
									CocktailFertig = 1;
									FuellstandB4 -= 660; FuellstandB5 -= 265; FuellstandB7 -= 1722; FuellstandB8 -= 660;
									Zufall = 0;
								}
							}		
						}
					}			
				}
			}
		}
		if((!CocktailFertig && RButtonCock4 && !Nachfuellen && InLichtschranke) || Zufall == 4)
		{
			Cocktail = 4;
			//Carl Oehl
			//Massenanpassungsfaktor bei Größenwahl
			if(RButtonBKlein)
			{
				Groessenfaktor = 0.5;
			}
			if(RButtonBGross)
			{
				Groessenfaktor = 1;
			}
			//Das erste If wird so lange durchlaufen, bis der Motor für das Eis seine Endlage erreicht hat.
			//Oder es wird gar nicht durchlaufen, falls der Benutzer ohne Eis gklickt hat
			if(RButtonBEis && !EisFertig)
			{
				OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
				OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 0; OutMotorEis = 1;
				if(InEndlageMotor2)
				{
					FlagMotor = 1;
				}
				if(InEndlageMotor && FlagMotor)
				{
					OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
					OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 0; OutMotorEis = 0;
					EisFertig = 1;
					FlagMotor = 0;
					StartGewicht = InAnalogWaage;
				}
			}
			else
			{
				//Der If Zweig wird so lange durchlaufen, bis die erste Zutat fertig ist.
				//Anschließend wird nur noch der Else Zweig durchlaufen
				if(!Zutat1Fertig)
				{
					OutVentil1 = 0; OutVentil2 = 1; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
					OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
					IstGewicht = InAnalogWaage;
					if(IstGewicht - StartGewicht >= 265 * Groessenfaktor)
					{
						OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
						OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
						Zutat1Fertig = 1;
						StartGewicht = InAnalogWaage;
					}
				}
				else
				{
					//Der If Zweig wird so lange durchlaufen, bis die zweite Zutat fertig ist.
					//Anschließend wird nur noch der Else Zweig durchlaufen
					if(!Zutat2Fertig)
					{
						OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 1;
						OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
						IstGewicht = InAnalogWaage;
						if(IstGewicht - StartGewicht >= 1590 * Groessenfaktor)
						{
							OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
							OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
							Zutat2Fertig = 1;
							StartGewicht = InAnalogWaage;
						}
					}
					else
					{
						//Der If Zweig wird so lange durchlaufen, bis die dritte Zutat fertig ist.
						//Anschließend wird nur noch der Else Zweig durchlaufen
						if(!Zutat3Fertig)
						{
							OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
							OutVentil7 = 1; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
							IstGewicht = InAnalogWaage;
							if(IstGewicht - StartGewicht >= 1200 * Groessenfaktor)
							{
								OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
								OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
								Zutat3Fertig = 1;
								StartGewicht = InAnalogWaage;
							}	
						}
						else
						{
							//Der If Zweig wird so lange durchlaufen, bis die vierte Zutat fertig ist.
							//Anschließend wird nur noch der Else Zweig durchlaufen
							if(!Zutat4Fertig)
							{
								OutVentil1 = 1; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
								OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
								IstGewicht = InAnalogWaage;
								if(IstGewicht - StartGewicht >= 265 * Groessenfaktor)
								{
									OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
									OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 0; OutLampeGruen = 1; OutPumpe = 0; OutMotorEis = 0;
									Zutat4Fertig = 1;
									CocktailFertig = 1;
									FuellstandB2 -= 400; FuellstandB6 -= 1330; FuellstandB7 -= 1200; FuellstandB1 -= 400;
									Zufall = 0;
								}
							}		
						}
					}			
				}
			}
		}
		if(!CocktailFertig && RButtonCock5 && !Nachfuellen && InLichtschranke && Zufall == 0)
		{
			//Zufälliger Cocktail
			Zufall = rand() % 4 + 1;	
		}
		if(!CocktailFertig && RButtonCock6 && !Nachfuellen && InLichtschranke)
		{
			//Richtig zufälliger Cocktail
			Cocktail = 6;
			//Massenanpassungsfaktor bei Größenwahl
			if(RButtonBKlein)
			{
				Groessenfaktor = 0.5;
			}
			if(RButtonBGross)
			{
				Groessenfaktor = 1;
			}
			//Das erste If wird so lange durchlaufen, bis der Motor für das Eis seine Endlage erreicht hat.
			//Oder es wird gar nicht durchlaufen, falls der Benutzer ohne Eis gklickt hat
			if(RButtonBEis && !EisFertig)
			{
				OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
				OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 0; OutMotorEis = 1;
				if(InEndlageMotor2)
				{
					FlagMotor = 1;
				}
				if(InEndlageMotor && FlagMotor)
				{
					OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
					OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 0; OutMotorEis = 0;
					EisFertig = 1;
					FlagMotor = 0;
					StartGewicht = InAnalogWaage;
				}
			}
			else
			{
				if(ZufallZufall == 0)
				{
					ZufallZufall = rand() % 8 + 1;
				}
				else
				{
					switch(ZufallZufall)
					{
						case 1:
							OutVentil1 = 1; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
							OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
							break;
						case 2:
							OutVentil1 = 0; OutVentil2 = 1; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
							OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
							break;
						case 3:
							OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 1; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
							OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
							break;
						case 4:
							OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 1; OutVentil5 = 0; OutVentil6 = 0;
							OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
							break;
						case 5:
							OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 1; OutVentil6 = 0;
							OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
							break;
						case 6:
							OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 1;
							OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
							break;
						case 7:
							OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
							OutVentil7 = 1; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
							break;
						case 8:
							OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
							OutVentil7 = 0; OutVentil8 = 1; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
							break;
						default:
							break;
					}
				}
				IstGewicht = InAnalogWaage;
				if(IstGewicht - StartGewicht >= 1000 * Groessenfaktor)
				{
					OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
					OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
					StartGewicht = InAnalogWaage;
					switch(ZufallZufall)
					{
						case 1: FuellstandB1-=1000*Groessenfaktor;break;
						case 2: FuellstandB2-=1000*Groessenfaktor;break;
						case 3: FuellstandB3-=1000*Groessenfaktor;break;
						case 4: FuellstandB4-=1000*Groessenfaktor;break;
						case 5: FuellstandB5-=1000*Groessenfaktor;break;
						case 6: FuellstandB6-=1000*Groessenfaktor;break;
						case 7: FuellstandB7-=1000*Groessenfaktor;break;
						case 8: FuellstandB8-=1000*Groessenfaktor;break;
					}
					ZufallZufall = 0;
					Durchgang++;
				}
				if(Durchgang == 5)
				{
					CocktailFertig = 1;
					OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
					OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 0; OutLampeGruen = 1; OutPumpe = 0; OutMotorEis = 0;
					Durchgang = 1;
				}
			}
		}
	}
	
	//Zustandswechsel
	if(ButtonSStart && ShotFertig && !Nachfuellen && InLichtschranke)
	{
		Zustand = 2;
		ShotFertig = 0;
		StartGewicht = InAnalogWaage;
		ButtonSStart = 0;
	}
	if(ButtonCStart && CocktailFertig && !Nachfuellen && InLichtschranke)
	{
		Zustand = 3;
		CocktailFertig = 0;
		StartGewicht = InAnalogWaage;
		ButtonCStart = 0;
		Zutat1Fertig = 0;
		Zutat2Fertig = 0;
		Zutat3Fertig = 0;
		Zutat4Fertig = 0;
		EisFertig = 0;
	}
	//Abziehen der Massen
	if(FuellstandB1 <= 1000 || FuellstandB3 <= 1000 || FuellstandB3 <= 1000 || FuellstandB4 <= 1000 || 
		FuellstandB5 <= 1000 || FuellstandB6 <= 3000 || FuellstandB7 <= 3000 || FuellstandB8 <= 3000)
	{
		Nachfuellen = 1;
	}
	
	if(Reinigung_1){
		OutVentil1 = 1; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
		OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
	}
	if(Reinigung_2){
		OutVentil1 = 0; OutVentil2 = 1; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
		OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
	}
	if(Reinigung_3){
		OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 1; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
		OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
	}
	if(Reinigung_4){
		OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 1; OutVentil5 = 0; OutVentil6 = 0;
		OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
	}
	if(Reinigung_5){
		OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 1; OutVentil6 = 0;
		OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
	}
	if(Reinigung_6){
		OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 1;
		OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
	}
	if(Reinigung_7){
		OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
		OutVentil7 = 1; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
	}
	if(Reinigung_8){
		OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
		OutVentil7 = 0; OutVentil8 = 1; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 1; OutMotorEis = 0;
	}
	if(Motor_Hand){
		OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
		OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 0; OutMotorEis = 1;
	}
	if(Motor_Ausgang){
		if(InEndlageMotor){
			OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
			OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 0; OutLampeGruen = 1; OutPumpe = 0; OutMotorEis = 0;
			Motor_Ausgang = 0;
		}
		else{
			OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
			OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 1; OutLampeGruen = 0; OutPumpe = 0; OutMotorEis = 1;
		}
	}
	if(Reinigung_Stopp){
		OutVentil1 = 0; OutVentil2 = 0; OutVentil3 = 0; OutVentil4 = 0; OutVentil5 = 0; OutVentil6 = 0;
		OutVentil7 = 0; OutVentil8 = 0; OutLampeRot = 0; OutLampeGruen = 1; OutPumpe = 0; OutMotorEis = 0;
		Reinigung_1 = 0;
		Reinigung_2 = 0;
		Reinigung_3 = 0;
		Reinigung_4 = 0;
		Reinigung_5 = 0;
		Reinigung_6 = 0;
		Reinigung_7 = 0;
		Reinigung_8 = 0;
		Motor_Hand = 0;
	}
	ButtonSStart = 0;
	ButtonCStart = 0;
	Reinigung_Stopp = 0;
}

void _EXIT ProgramExit(void)
{

}

