//////////////////////////////////////////////////////////////////////////////////////////////////////
// OHMS LAW CALCULATOR IN C - DRAFT - Program Developed By Nigel A Williams                         //
// This program is a simple Ohm's Law calculator written in C.                                      //
// It allows the user to calculate voltage, current, and resistance based on Ohm's Law (V = I * R). //
// It provides a simple menu interface for the user to select which calculation to perform.         //
//////////////////////////////////////////////////////////////////////////////////////////////////////

// OhmsLawC - OhmsLawC.c
// A simple Ohm's Law calculator in C
// Developed by Nigel A Williams
// Copyright (c) 2025

#include <stdio.h>
#include <conio.h>

// DECLARATION
int menu_select;
float Current = 0;
float Resistance = 0;
float Voltage = 0;

float amps, curr;
float ohms, resi;
float volts, volt;

void SetCurrent(float);
void SetResistance(float);
void SetVoltage(float);

void CalculateVoltage();
void CalculateCurrent();
void CalculateResistance();

float GetCurrent();
float GetResistance();
float GetVoltage();

// IMPLEMENTATION
void SetCurrent(float current)
{
   Current = current;
}

void SetResistance(float resistance)
{
   Resistance = resistance;
}

void SetVoltage(float voltage)
{
   Voltage = voltage;
}

void CalculateVoltage()
{
	Voltage = Current * Resistance;
}

void CalculateCurrent()
{
	Current = Voltage / Resistance;
}

void CalculateResistance()
{
	Resistance = Voltage / Current;
}

float GetCurrent()
{
   return Current;
}

float GetResistance()
{
   return Resistance;
}

float GetVoltage()
{
   return Voltage;
}

int main()
{
   printf_s("===============================\n");
   printf_s("A BASIC OHMS LAW CALCULATOR IN C\n");
   printf_s("===============================\n");
   printf_s("SELECT CHOICE FROM MENU ITEMS\n");
   printf_s("1. CALCULATE VOLTAGE\n");
   printf_s("2. CALCULATE CURRENT\n");
   printf_s("3. CALCULATE RESISTANCE\n");
   printf_s("===============================\n");
   printf_s("\n");
   printf_s("Press ESC to stop\n");
   printf_s("\n");

   while(1)
   {
	   menu_select = _getch();
	   if (menu_select == 27)
	   {
		   printf_s("ESCAPE KEY PRESSED !!!\n");
		   printf_s("EXITING PROGRAM OHMS LAW IN C !!!\n");
		   break;
	   }
	   

	   switch (menu_select)
	   {
		   case '1':
		   {
			   printf_s("CALCULATING VOLTAGE\n");
			   printf_s("Enter Current: ");
			   scanf_s("%f", &curr);
			   SetCurrent(curr);
			   printf_s("Enter Resistance: ");
			   scanf_s("%f", &resi);
			   SetResistance(resi);
			   CalculateVoltage();
			   volts = GetVoltage();
			   printf_s("Voltage: %f", volts);
			   printf_s("\n\n");
			   break;
		   }

		   case '2':
		   {
			   printf_s("CALCULATING CURRENT\n");
			   printf_s("Enter Voltage: ");
			   scanf_s("%f", &volt);
			   SetVoltage(volt);
			   printf_s("Enter Resistance: ");
			   scanf_s("%f", &resi);
			   SetResistance(resi);
			   CalculateCurrent();
			   amps = GetCurrent();
			   printf_s("Current: %f", amps);
			   printf_s("\n\n");
			   break;
		   }

	       case '3':
		   {
			   printf_s("CALCULATING RESISTANCE\n");
			   printf_s("Enter Voltage: ");
			   scanf_s("%f", &volt);
			   SetVoltage(volt);
			   printf_s("Enter Current: ");
			   scanf_s("%f", &curr);
			   SetCurrent(curr);
			   CalculateResistance();
			   ohms = GetResistance();
			   printf_s("Resistance: %f", ohms);
			   printf_s("\n\n");
			   break;
		   }

	       default:
		   {
			   printf_s("Enter Valid Entry !!!\n\n");
			   break;
		   }
	   }
   }
}