// should all of this be in a single file? probably not
// but NPP lets you minimise blocks so its easy enough for me to edit and im lazy

// TODO
// -make inline 4 sounds less shit
// -add ability to toggle differential locking on the fly

class CfgPatches
{
	class Mod_Vehicle_Rework
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Sounds_Effects",
			"DZ_Vehicles_Wheeled"
		};
	};
};

class CfgMods
{
	class Mod_Vehicle_Rework
	{
		dir = "VehicleRework";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 1;
		name = "Vehicle Rework";
		author = "The Gamer Guy";
		authorID = "0"; 
		version = "0.1"; 
		extra = 0;
		type = "mod";
	};
};

class CfgVehicles
{
	class Car;
	class CarScript: Car
	{	
		//this shit needs to be here or else addon builder fails
		class SimulationModule
		{
			class Axles
			{
				class Front
				{
					class Wheels
					{
					}
				}
				class Rear
				{
					class Wheels
					{
					}
				}
			}
		}
	}
	class OffroadHatchback: CarScript
	{
		class SimulationModule: SimulationModule
		{
			class Steering
			{
				maxSteeringAngle=30;
				increaseSpeed[]={0,45,60,23,100,12};
				decreaseSpeed[]={0,80,60,40,90,20};
				centeringSpeed[]={0,0,15,25,60,40,100,60};
			};
			class Throttle
			{
				reactionTime=0.1;
				defaultThrust=0.65;
				gentleThrust=0.5;
				turboCoef=4;
				gentleCoef=0.75;
			};
			class Brake
			{
				pressureBySpeed[]={0,0.4,300,0.4};
				gentleCoef=0.45;
				minPressure=0.2;
				reactionTime=0.30000001;
				driverless=0.1;
			};
			class Aerodynamics
			{
				frontalArea=2.1800001;
				dragCoefficient=0.56;
			};
			drive="DRIVE_AWD";
			class Engine
			{
				torqueCurve[]={650,0,750,40,1400,80,3400,114,5400,95,8000,0};
				inertia=0.10;
				frictionTorque=100;
				rollingFriction=0.5;
				viscousFriction=0.0;
				rpmIdle=800;
				rpmMin=900;
				rpmClutch=1500;
				rpmRedline=6000;
			};
			class Clutch
			{
				maxTorqueTransfer=150;
				uncoupleTime=0.1;
				coupleTime=0.4;
			};
			class Gearbox
			{
				type="GEARBOX_MANUAL";
				reverse=4;
				ratios[]={3.6670001,2.1,1.35,0.935,0.7};
			};
			class CentralDifferential
			{
				ratio=1.5;
				type="DIFFERENTIAL_LOCKED";
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxBrakeTorque=950;
					maxHandbrakeTorque=2500;
					wheelHubMass=5;
					wheelHubRadius=0.15000001;
					class Differential
					{
						ratio=4.0999999;
						type="DIFFERENTIAL_OPEN";
					};
				};
				class Rear: Rear
				{
					maxBrakeTorque=780;
					maxHandbrakeTorque=2500;
					wheelHubMass=5;
					wheelHubRadius=0.15000001;
					class Differential
					{
						ratio=4.0999999;
						type="DIFFERENTIAL_OPEN";
					};
				};
			};
		};
		class Sounds
		{
			thrust=0.5;
			thrustTurbo=1;
			thrustGentle=0.35;
			thrustSmoothCoef=0.05;
			camposSmoothCoef=0.029999999;
			soundSetsFilter[]=
			{
				"offroad_Engine_Offload_Ext_Rpm1_SoundSet",
				"offroad_Engine_Offload_Ext_Rpm2_SoundSet",
				"offroad_Engine_Offload_Ext_Rpm3_SoundSet",
				"offroad_Engine_Offload_Ext_Rpm4_SoundSet",
				"offroad_Engine_Offload_Ext_Rpm5_SoundSet",
				"offroad_Engine_Offload_Ext_Rpm6_SoundSet",
				"offroad_Engine_Ext_Rpm0_SoundSet",
				"offroad_Engine_Ext_Rpm1_SoundSet",
				"offroad_Engine_Ext_Rpm2_SoundSet",
				"offroad_Engine_Ext_Rpm3_SoundSet",
				"offroad_Engine_Ext_Rpm4_SoundSet",
				"offroad_Engine_Ext_Rpm5_SoundSet",
				"offroad_Engine_Ext_Rpm6_SoundSet",
				"offroad_Engine_Ext_Broken_SoundSet",
				"offroad_Tires_rock_slow_Ext_SoundSet",
				"offroad_Tires_rock_fast_Ext_SoundSet",
				"offroad_Tires_grass_slow_Ext_SoundSet",
				"offroad_Tires_grass_fast_Ext_SoundSet",
				"offroad_Tires_gravel_slow_Ext_SoundSet",
				"offroad_Tires_gravel_fast_Ext_SoundSet",
				"offroad_Tires_gravel_dust_fast_Ext_SoundSet",
				"offroad_Tires_asphalt_slow_Ext_SoundSet",
				"offroad_Tires_asphalt_fast_Ext_SoundSet",
				"offroad_Tires_water_slow_Ext_SoundSet",
				"offroad_Tires_water_fast_Ext_SoundSet",
				"Offroad_skid_dirt_SoundSet",
				"offroad_dirt_turn_SoundSet",
				"offroad_Rain_Ext_SoundSet",
				"offroad_damper_left_SoundSet",
				"offroad_damper_right_SoundSet"
			};
		};
	};
	class CivilianSedan: CarScript
	{
		class SimulationModule: SimulationModule
		{
			class Steering
			{
				maxSteeringAngle=35;
				increaseSpeed[]={0,50,10,40,30,30,60,15,100,7,120,4};
				decreaseSpeed[]={0,90,60,60,120,40};
				centeringSpeed[]={0,0,15,30,60,60,100,80};
			};
			class Throttle
			{
				reactionTime=0.1;
				defaultThrust=0.6;
				gentleThrust=0.4;
				turboCoef=6;
				gentleCoef=0.69999999;
			};
			class Brake
			{
				pressureBySpeed[]={0,0.4,300,0.4};
				gentleCoef=0.45;
				minPressure=0.2;
				reactionTime=0.25;
				driverless=0.1;
			};
			class Aerodynamics
			{
				frontalArea=2.2;
				dragCoefficient=0.44999999;
				downforceCoefficient=0.80000001;
				downforceOffset[]={0,0.40000001,-2.2};
			};
			drive="DRIVE_RWD";
			class Engine
			{
				torqueCurve[]={400,0,1000,157,1700,183,2500,187,4500,147,6000,0};
				inertia=0.15;
				frictionTorque=130;
				rollingFriction=0.8;
				viscousFriction=0;
				rpmIdle=800;
				rpmMin=1000;
				rpmClutch=1500;
				rpmRedline=4700;
			};
			class Clutch
			{
				maxTorqueTransfer=200;
				uncoupleTime=0.10;
				coupleTime=0.30;
			};
			class Gearbox
			{
				type="GEARBOX_MANUAL";
				reverse=3.6;
				ratios[]={3.335,2.25,1.5,1.1,0.85};
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxBrakeTorque=1050;
					wheelHubMass=10;
					wheelHubRadius=0.15000001;
				};
				class Rear: Rear
				{
					maxBrakeTorque=1100;
					maxHandbrakeTorque=2200;
					wheelHubMass=10;
					wheelHubRadius=0.15000001;
					class Differential
					{
						ratio=4.0999999;
						type="DIFFERENTIAL_OPEN";
					};
				};
			};
		};
		class Sounds
		{
			thrust=0.5;
			thrustTurbo=1;
			thrustGentle=0.30000001;
			thrustSmoothCoef=0.05;
			camposSmoothCoef=0.029999999;
			soundSetsFilter[]=
			{
				"CivilianSedan_Engine_Offload_Ext_Rpm1_SoundSet",
				"CivilianSedan_Engine_Offload_Ext_Rpm2_SoundSet",
				"CivilianSedan_Engine_Offload_Ext_Rpm3_SoundSet",
				"CivilianSedan_Engine_Offload_Ext_Rpm4_SoundSet",
				"CivilianSedan_Engine_Offload_Ext_Rpm5_SoundSet",
				"CivilianSedan_Engine_Offload_Ext_Rpm6_SoundSet",
				"CivilianSedan_Engine_Ext_Rpm0_SoundSet",
				"CivilianSedan_Engine_Ext_Rpm1_SoundSet",
				"CivilianSedan_Engine_Ext_Rpm2_SoundSet",
				"CivilianSedan_Engine_Ext_Rpm3_SoundSet",
				"CivilianSedan_Engine_Ext_Rpm4_SoundSet",
				"CivilianSedan_Engine_Ext_Rpm5_SoundSet",
				"CivilianSedan_Engine_Ext_Rpm6_SoundSet",
				"CivilianSedan_Engine_Ext_Broken_SoundSet",
				"CivilianSedan_Tires_rock_slow_Ext_SoundSet",
				"CivilianSedan_Tires_rock_fast_Ext_SoundSet",
				"CivilianSedan_Tires_grass_slow_Ext_SoundSet",
				"CivilianSedan_Tires_grass_fast_Ext_SoundSet",
				"CivilianSedan_Tires_gravel_slow_Ext_SoundSet",
				"CivilianSedan_Tires_gravel_fast_Ext_SoundSet",
				"CivilianSedan_Tires_gravel_dust_fast_Ext_SoundSet",
				"CivilianSedan_Tires_asphalt_slow_Ext_SoundSet",
				"CivilianSedan_Tires_asphalt_fast_Ext_SoundSet",
				"CivilianSedan_Tires_water_slow_Ext_SoundSet",
				"CivilianSedan_Tires_water_fast_Ext_SoundSet",
				"CivilianSedan_skid_dirt_SoundSet",
				"CivilianSedan_dirt_turn_SoundSet",
				"CivilianSedan_Rain_Ext_SoundSet",
				"CivilianSedan_damper_left_SoundSet",
				"CivilianSedan_damper_right_SoundSet"
			};
		};
	};
	class Hatchback_02: CarScript
	{
		class SimulationModule: SimulationModule
		{
			class Steering
			{
				maxSteeringAngle=35;
				increaseSpeed[]={0,50,60,30,100,15};
				decreaseSpeed[]={0,90,60,45,100,20};
				centeringSpeed[]={0,0,15,27,60,45,100,63};
			};
			class Throttle
			{
				reactionTime=0.1;
				defaultThrust=0.6;
				gentleThrust=0.4;
				turboCoef=2.2;
				gentleCoef=0.5;
			};
			class Brake
			{
				pressureBySpeed[]={0,0.4,300,0.4};
				gentleCoef=0.6;
				minPressure=0.2;
				reactionTime=0.2;
				driverless=0.1;
			};
			drive="DRIVE_FWD";
			class Engine
			{
				torqueCurve[]={850,0,1150,90,2000,130,4400,186,5800,165,7500,0};
				inertia=0.2;
				frictionTorque=150;
				rollingFriction=1.2;
				viscousFriction=0.0;
				rpmIdle=900;
				rpmMin=1150;
				rpmClutch=1600;
				rpmRedline=6250;
			};
			class Clutch
			{
				maxTorqueTransfer=200;
				uncoupleTime=0.1;
				coupleTime=0.35;
			};
			class Gearbox
			{
				type="GEARBOX_MANUAL";
				reverse=3.667;
				ratios[]={3.667,2.4,1.7,1.25,0.92};
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxBrakeTorque=1030;
					wheelHubMass=5;
					wheelHubRadius=0.125;
					class Differential
					{
						ratio=3.6670001;
						type="DIFFERENTIAL_OPEN";
					};
				};
				class Rear: Rear
				{
					maxBrakeTorque=750;
					maxHandbrakeTorque=2000;
					wheelHubMass=5;
					wheelHubRadius=0.125;
				};
			};
		};
		class Sounds
		{
			thrust=0.5;
			thrustTurbo=1;
			thrustGentle=0.30000001;
			thrustSmoothCoef=0.05;
			camposSmoothCoef=0.029999999;
			soundSetsFilter[]=
			{
				"Hatchback_02_Engine_Offload_Ext_Rpm1_SoundSet",
				"Hatchback_02_Engine_Offload_Ext_Rpm2_SoundSet",
				"Hatchback_02_Engine_Offload_Ext_Rpm3_SoundSet",
				"Hatchback_02_Engine_Offload_Ext_Rpm4_SoundSet",
				"Hatchback_02_Engine_Offload_Ext_Rpm5_SoundSet",
				"Hatchback_02_Engine_Offload_Ext_Rpm6_SoundSet",
				"Hatchback_02_Engine_Ext_Rpm0_SoundSet",
				"Hatchback_02_Engine_Ext_Rpm1_SoundSet",
				"Hatchback_02_Engine_Ext_Rpm2_SoundSet",
				"Hatchback_02_Engine_Ext_Rpm3_SoundSet",
				"Hatchback_02_Engine_Ext_Rpm4_SoundSet",
				"Hatchback_02_Engine_Ext_Rpm5_SoundSet",
				"Hatchback_02_Engine_Ext_Rpm6_SoundSet",
				"Hatchback_02_Engine_Ext_Broken_SoundSet",
				"Hatchback_02_Tires_rock_slow_Ext_SoundSet",
				"Hatchback_02_Tires_rock_fast_Ext_SoundSet",
				"Hatchback_02_Tires_grass_slow_Ext_SoundSet",
				"Hatchback_02_Tires_grass_fast_Ext_SoundSet",
				"Hatchback_02_Tires_gravel_slow_Ext_SoundSet",
				"Hatchback_02_Tires_gravel_fast_Ext_SoundSet",
				"Hatchback_02_Tires_gravel_dust_fast_Ext_SoundSet",
				"Hatchback_02_Tires_asphalt_slow_Ext_SoundSet",
				"Hatchback_02_Tires_asphalt_fast_Ext_SoundSet",
				"Hatchback_02_Tires_water_slow_Ext_SoundSet",
				"Hatchback_02_Tires_water_fast_Ext_SoundSet",
				"Hatchback_02_skid_dirt_SoundSet",
				"Hatchback_02_dirt_turn_SoundSet",
				"Hatchback_02_Rain_Ext_SoundSet",
				"Hatchback_02_damper_left_SoundSet",
				"Hatchback_02_damper_right_SoundSet"
			};
		};
	};
	class Sedan_02: CarScript
	{
		class SimulationModule: SimulationModule
		{
			class Steering
			{
				maxSteeringAngle=30;
				increaseSpeed[]={0,45,60,25,100,10};
				decreaseSpeed[]={0,80,60,40,100,15};
				centeringSpeed[]={0,0,15,25,60,40,100,60};
			};
			class Throttle
			{
				reactionTime=0.1;
				defaultThrust=0.75;
				gentleThrust=0.5;
				turboCoef=3.8;
				gentleCoef=0.5;
			};
			class Brake
			{
				pressureBySpeed[]={0,0.4,300,0.4};
				gentleCoef=0.40;
				minPressure=0.30000001;
				reactionTime=0.20;
				driverless=0.1;
			};
			class Aerodynamics
			{
				frontalArea=2;
				dragCoefficient=0.34999999;
			};
			drive="DRIVE_RWD";
			class Engine
			{
				torqueCurve[]={600,0,990,50,1800,75,3000,82,5000,71,7000,0};
				inertia=0.1;
				frictionTorque=80;
				rollingFriction=0.5;
				viscousFriction=0;
				rpmIdle=800;
				rpmMin=1000;
				rpmClutch=2000;
				rpmRedline=5750;
			};
			class Clutch
			{
				maxTorqueTransfer=100;
				uncoupleTime=0.1;
				coupleTime=0.30;
			};
			class Gearbox
			{
				type="GEARBOX_MANUAL";
				reverse=4;
				ratios[]={3.667,2.1,1.5,1.14,0.855};
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxBrakeTorque=610;
					wheelHubMass=5;
					wheelHubRadius=0.17;
				};
				class Rear: Rear
				{
					maxBrakeTorque=520;
					maxHandbrakeTorque=1200;
					wheelHubMass=5;
					wheelHubRadius=0.17;
					class Differential
					{
						ratio=4.2199998;
						type="DIFFERENTIAL_OPEN";
					};
				};
			};
		};
		class Sounds
		{
			thrust=0.5;
			thrustTurbo=1;
			thrustGentle=0.3;
			thrustSmoothCoef=0.05;
			camposSmoothCoef=0.029999999;
			soundSetsFilter[]=
			{
				"Sedan_02_Engine_Offload_Ext_Rpm1_SoundSet",
				"Sedan_02_Engine_Offload_Ext_Rpm2_SoundSet",
				"Sedan_02_Engine_Offload_Ext_Rpm3_SoundSet",
				"Sedan_02_Engine_Offload_Ext_Rpm4_SoundSet",
				"Sedan_02_Engine_Offload_Ext_Rpm5_SoundSet",
				"Sedan_02_Engine_Offload_Ext_Rpm6_SoundSet",
				"Sedan_02_Engine_Ext_Rpm0_SoundSet",
				"Sedan_02_Engine_Ext_Rpm1_SoundSet",
				"Sedan_02_Engine_Ext_Rpm2_SoundSet",
				"Sedan_02_Engine_Ext_Rpm3_SoundSet",
				"Sedan_02_Engine_Ext_Rpm4_SoundSet",
				"Sedan_02_Engine_Ext_Rpm5_SoundSet",
				"Sedan_02_Engine_Ext_Rpm6_SoundSet",
				"Sedan_02_Engine_Ext_Broken_SoundSet",
				"Sedan_02_Tires_rock_slow_Ext_SoundSet",
				"Sedan_02_Tires_rock_fast_Ext_SoundSet",
				"Sedan_02_Tires_grass_slow_Ext_SoundSet",
				"Sedan_02_Tires_grass_fast_Ext_SoundSet",
				"Sedan_02_Tires_gravel_slow_Ext_SoundSet",
				"Sedan_02_Tires_gravel_fast_Ext_SoundSet",
				"Sedan_02_Tires_gravel_dust_fast_Ext_SoundSet",
				"Sedan_02_Tires_asphalt_slow_Ext_SoundSet",
				"Sedan_02_Tires_asphalt_fast_Ext_SoundSet",
				"Sedan_02_Tires_water_slow_Ext_SoundSet",
				"Sedan_02_Tires_water_fast_Ext_SoundSet",
				"Sedan_02_skid_dirt_SoundSet",
				"Sedan_02_dirt_turn_SoundSet",
				"Sedan_02_Rain_Ext_SoundSet",
				"Sedan_02_damper_left_SoundSet",
				"Sedan_02_damper_right_SoundSet"
			};
		};
	};
	class Truck_01_Base: CarScript
	{
		class SimulationModule: SimulationModule
		{
			class Steering
			{
				maxSteeringAngle=35;
				increaseSpeed[]={0,50,30,40,60,25,120,5};
				decreaseSpeed[]={0,50,60,30,120,10};
				centeringSpeed[]={0,0,15,25,60,40,100,60};
			};
			class Throttle
			{
				reactionTime=0.1;
				defaultThrust=0.80000001;
				gentleThrust=0.60000002;
				turboCoef=1.15;
				gentleCoef=0.5;
			};
			class Brake
			{
				pressureBySpeed[]={0,0.4,300,0.4};
				gentleCoef=0.4;
				minPressure=0.2;
				reactionTime=0.30000001;
				driverless=0.1;
			};
			class Aerodynamics
			{
				frontalArea=5.75;
				dragCoefficient=0.52999997;
			};
			drive="DRIVE_642";
			class Engine
			{
				torqueCurve[]={525,0,1000,330,1400,340,1900,300,2500,100,3000,0};
				inertia=1.00;
				frictionTorque=100;
				rollingFriction=3;
				viscousFriction=2.5;
				rpmIdle=650;
				rpmMin=750;
				rpmClutch=850;
				rpmRedline=2400;
			};
			class Clutch
			{
				maxTorqueTransfer=500;
				uncoupleTime=0.1;
				coupleTime=0.4;
			};
			class Gearbox
			{
				type="GEARBOX_MANUAL";
				reverse=6.28;
				ratios[]={6.28,4,2.8,1.975,1.4,1.05,0.8,0.645};
			};
			class CentralDifferential
			{
				ratio=0.5;
				type="DIFFERENTIAL_LOCKED";
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxBrakeTorque=3500;
					wheelHubMass=25;
					wheelHubRadius=0.30000001;
				};
				class Middle: Rear
				{
					maxBrakeTorque=2500;
					maxHandbrakeTorque=6000;
					wheelHubMass=45;
					wheelHubRadius=0.30000001;
					class Differential
					{
						ratio=8.3500004;
						type="DIFFERENTIAL_OPEN";
					};
				};
				class Rear: Rear
				{
					maxBrakeTorque=2500;
					maxHandbrakeTorque=6000;
					wheelHubMass=45;
					wheelHubRadius=0.30000001;
					class Differential
					{
						ratio=8.3500004;
						type="DIFFERENTIAL_OPEN";
					};
				};
			};
		};
	};
	class Offroad_02: CarScript
	{
		class SimulationModule: SimulationModule
		{
			class Steering
			{
				maxSteeringAngle=30;
				increaseSpeed[]={0,50,30,40,60,25,120,5};
				decreaseSpeed[]={0,50,60,30,120,10};
				centeringSpeed[]={0,0,15,25,60,40,100,60};
			};
			class Throttle
			{
				reactionTime=0.1;
				defaultThrust=0.65;
				gentleThrust=0.45;
				turboCoef=4;
				gentleCoef=0.75;
			};
			class Brake
			{
				pressureBySpeed[]={0,0.4,300,0.4};
				gentleCoef=0.4;
				minPressure=0.2;
				reactionTime=0.15000001;
				driverless=0.1;
			};
			drive="DRIVE_AWD";
			class Engine
			{
				torqueCurve[]={600,225,650,240,2200,383,3550,283,3690,256,3700,0};
				inertia=1.00;
				frictionTorque=200;
				rollingFriction=2.0;
				viscousFriction=2.0;
				rpmIdle=625;
				rpmMin=650;
				rpmClutch=2000;
				rpmRedline=3700;
			};
			class Clutch
			{
				maxTorqueTransfer=425;
				uncoupleTime=0.25;
				coupleTime=0.5;
			};
			class Gearbox
			{
				type="GEARBOX_AUTOMATIC";
				reverse=3.667;
				ratios[]={3.667,2.48,1.48,1,0.75};
			};
			class CentralDifferential
			{
				ratio=2.1210001;
				type="DIFFERENTIAL_LOCKED";
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxBrakeTorque=2350;
					maxHandbrakeTorque=5000;
					wheelHubMass=20;
					wheelHubRadius=0.15000001;
					class Differential
					{
						ratio=2.73;
						type="DIFFERENTIAL_OPEN";
					};
				};
				class Rear: Rear
				{
					maxBrakeTorque=1750;
					maxHandbrakeTorque=5000;
					wheelHubMass=20;
					wheelHubRadius=0.15000001;
					class Differential
					{
						ratio=2.73;
						type="DIFFERENTIAL_OPEN";
					};
				};
			};
		};
		class Sounds
		{
			thrust=0.60000002;
			thrustTurbo=1;
			thrustGentle=0.30000001;
			thrustSmoothCoef=0.05;
			camposSmoothCoef=0.029999999;
			soundSetsFilter[]=
			{
				"offroad_02_Engine_Offload_Ext_Rpm1_SoundSet",
				"offroad_02_Engine_Offload_Ext_Rpm2_SoundSet",
				"offroad_02_Engine_Offload_Ext_Rpm3_SoundSet",
				"offroad_02_Engine_Offload_Ext_Rpm4_SoundSet",
				"offroad_02_Engine_Offload_Ext_Rpm5_SoundSet",
				"offroad_02_Engine_Offload_Ext_Rpm6_SoundSet",
				"offroad_02_Engine_Ext_Rpm0_SoundSet",
				"offroad_02_Engine_Ext_Rpm1_SoundSet",
				"offroad_02_Engine_Ext_Rpm2_SoundSet",
				"offroad_02_Engine_Ext_Rpm3_SoundSet",
				"offroad_02_Engine_Ext_Rpm4_SoundSet",
				"offroad_02_Engine_Ext_Rpm5_SoundSet",
				"offroad_02_Engine_Ext_Rpm6_SoundSet",
				"offroad_02_Engine_Ext_Broken_SoundSet",
				"offroad_Tires_rock_slow_Ext_SoundSet",
				"offroad_Tires_rock_fast_Ext_SoundSet",
				"offroad_Tires_grass_slow_Ext_SoundSet",
				"offroad_Tires_grass_fast_Ext_SoundSet",
				"offroad_Tires_gravel_slow_Ext_SoundSet",
				"offroad_Tires_gravel_fast_Ext_SoundSet",
				"offroad_Tires_gravel_dust_fast_Ext_SoundSet",
				"offroad_Tires_asphalt_slow_Ext_SoundSet",
				"offroad_Tires_asphalt_fast_Ext_SoundSet",
				"offroad_Tires_water_slow_Ext_SoundSet",
				"offroad_Tires_water_fast_Ext_SoundSet",
				"Offroad_skid_dirt_SoundSet",
				"offroad_dirt_turn_SoundSet",
				"offroad_Rain_Ext_SoundSet",
				"offroad_damper_left_SoundSet",
				"offroad_damper_right_SoundSet"
			};
		};
	};
};
class CfgSoundShaders
{
	//offroad hatchback
	class baseEngineOffroad_SoundShader
	{
		range=80;
	};
	class Offroad_Engine_Ext_Rpm0_SoundShader: baseEngineOffroad_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-700rpm-offload",
				1
			}
		};
		frequency="rpm / 750";
		volume="0.8 * 1 * engineOn * 0.4 * ((750 + ((rpm - 750)/(8000/5600))) factor [(((750+1000)/2) + 2.5*50),(((750+1000)/2) - 50)]) * ((1 - 0.25*doors) max campos)";
	};
	class Offroad_Engine_Ext_Rpm1_SoundShader: baseEngineOffroad_SoundShader
	{
	    samples[]=
	    {
		{
		    "\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-1000rpm-load",
		    1
		}
	    };
	    frequency="1 * (rpm / 1000)";
	    volume="engineOn * ((rpm factor [700, 1250]) * (1 - (rpm factor [1150, 1750]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.6 * ((1 - 0.25*doors) max campos)";
	};

	class Offroad_Engine_Offload_Ext_Rpm1_SoundShader: baseEngineOffroad_SoundShader
	{
	    samples[]=
	    {
		{
		    "\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-1000rpm-offload",
		    1
		}
	    };
	    frequency="1 * (rpm / 1000)";
	    volume="engineOn * ((rpm factor [700, 1250]) * (1 - (rpm factor [1150, 1750]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};

	class Offroad_Engine_Ext_Rpm2_SoundShader: baseEngineOffroad_SoundShader
	{
	    samples[]=
	    {
		{
		    "\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-2000rpm-load",
		    1
		}
	    };
	    frequency="1 * (rpm / 2000)";
	    volume="engineOn * ((rpm factor [1150, 1750]) * (1 - (rpm factor [1650, 2750]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.85 * ((1 - 0.25*doors) max campos)";
	};

	class Offroad_Engine_Offload_Ext_Rpm2_SoundShader: baseEngineOffroad_SoundShader
	{
	    samples[]=
	    {
		{
		    "\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-2000rpm-offload",
		    1
		}
	    };
	    frequency="1 * (rpm / 2000)";
	    volume="engineOn * ((rpm factor [1150, 1750]) * (1 - (rpm factor [1650, 2750]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};

	class Offroad_Engine_Ext_Rpm3_SoundShader: baseEngineOffroad_SoundShader
	{
	    samples[]=
	    {
		{
		    "\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-3000rpm-load",
		    1
		}
	    };
	    frequency="1 * (rpm / 3000)";
	    volume="engineOn * ((rpm factor [1650, 2750]) * (1 - (rpm factor [2650, 3750]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1 * ((1 - 0.25*doors) max campos)";
	};

	class Offroad_Engine_Offload_Ext_Rpm3_SoundShader: baseEngineOffroad_SoundShader
	{
	    samples[]=
	    {
		{
		    "\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-3000rpm-offload",
		    1
		}
	    };
	    frequency="1 * (rpm / 3000)";
	    volume="engineOn * ((rpm factor [1650, 2750]) * (1 - (rpm factor [2650, 3750]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};

	class Offroad_Engine_Ext_Rpm4_SoundShader: baseEngineOffroad_SoundShader
	{
	    samples[]=
	    {
		{
		    "\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-4000rpm-load",
		    1
		}
	    };
	    frequency="1 * (rpm / 4000)";
	    volume="engineOn * ((rpm factor [2650, 3750]) * (1 - (rpm factor [3650, 4750]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1 * ((1 - 0.25*doors) max campos)";
	};

	class Offroad_Engine_Offload_Ext_Rpm4_SoundShader: baseEngineOffroad_SoundShader
	{
	    samples[]=
	    {
		{
		    "\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-4000rpm-offload",
		    1
		}
	    };
	    frequency="1 * (rpm / 4000)";
	    volume="engineOn * ((rpm factor [2650, 3750]) * (1 - (rpm factor [3650, 4750]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};

	class Offroad_Engine_Ext_Rpm5_SoundShader: baseEngineOffroad_SoundShader
	{
	    samples[]=
	    {
		{
		    "\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-5000rpm-load",
		    1
		}
	    };
	    frequency="1 * (rpm / 5000)";
	    volume="engineOn * ((rpm factor [3650, 4750]) * (1 - (rpm factor [4650, 5750]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1 * ((1 - 0.25*doors) max campos)";
	};

	class Offroad_Engine_Offload_Ext_Rpm5_SoundShader: baseEngineOffroad_SoundShader
	{
	    samples[]=
	    {
		{
		    "\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-5000rpm-offload",
		    1
		}
	    };
	    frequency="1 * (rpm / 5000)";
	    volume="engineOn * ((rpm factor [3650, 4750]) * (1 - (rpm factor [4650, 5750]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};
	class Offroad_Engine_Ext_Rpm6_SoundShader: baseEngineOffroad_SoundShader
	{
	    samples[]=
	    {
		{
		    "\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-6000rpm-load",
		    1
		}
	    };
	    frequency="1 * (rpm / 6000)";
	    volume="engineOn * (rpm factor [4650, 5750]) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1 * ((1 - 0.25*doors) max campos)";
	};

	class Offroad_Engine_Offload_Ext_Rpm6_SoundShader: baseEngineOffroad_SoundShader
	{
	    samples[]=
	    {
		{
		    "\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-6000rpm-offload",
		    1
		}
	    };
	    frequency="1 * (rpm / 6000)";
	    volume="engineOn * (rpm factor [4650, 5750]) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};
	class Offroad_Engine_Ext_Broken_SoundShader: baseEngineOffroad_SoundShader
	{
		samples[]=
		{
			
			{
				"\DZ\sounds\vehicles\shared\add_layers\Offroad_Engine_Ext_Broken",
				1
			}
		};
		frequency=0.9;
		volume="0.5 * 1 * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((3250+4400)/2) - 2.5*200),(((3250+4400)/2) + 200)]) * ((1 - 0.25*doors) max campos) * (rpm factor[4800,6200])";
	};
	
	//civ sedan--------------------------------------------------------------------------------------
	class baseEngineCivilianSedan_SoundShader
	{
		range=80;
	};
	class CivilianSedan_Engine_Ext_Rpm0_SoundShader: baseEngineCivilianSedan_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-700rpm-offload",
				1
			}
		};
		frequency="rpm / 750";
		volume="0.8 * 1 * engineOn * 0.4 * ((750 + ((rpm - 750)/(8000/5600))) factor [(((750+1000)/2) + 2.5*50),(((750+1000)/2) - 50)]) * ((1 - 0.25*doors) max campos)";
	};
	class CivilianSedan_Engine_Ext_Rpm1_SoundShader: baseEngineCivilianSedan_SoundShader
	{
		samples[]=
		{
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-1000rpm-load",
				1
			}
		};
		frequency="1 * (rpm / 1000)";
		volume="engineOn * ((rpm factor [700, 1250]) * (1 - (rpm factor [1150, 1750]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.6 * ((1 - 0.25*doors) max campos)";
	};
	class CivilianSedan_Engine_Offload_Ext_Rpm1_SoundShader: baseEngineCivilianSedan_SoundShader
	{
		samples[]=
		{
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-1000rpm-offload",
				1
			}
		};
	    frequency="1 * (rpm / 1000)";
	    volume="engineOn * ((rpm factor [700, 1250]) * (1 - (rpm factor [1150, 1750]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};
	class CivilianSedan_Engine_Ext_Rpm2_SoundShader: baseEngineCivilianSedan_SoundShader
	{
		samples[]=
		{
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-2000rpm-load",
				1
			}
		};
		frequency="1 * (rpm / 2000)";
		volume="engineOn * ((rpm factor [1150, 1750]) * (1 - (rpm factor [1650, 2750]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.85 * ((1 - 0.25*doors) max campos)";
	};
	class CivilianSedan_Engine_Offload_Ext_Rpm2_SoundShader: baseEngineCivilianSedan_SoundShader
	{
		samples[]=
		{
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-2000rpm-offload",
				1
			}
		};
		frequency="1 * (rpm / 2000)";
		volume="engineOn * ((rpm factor [1150, 1750]) * (1 - (rpm factor [1650, 2750]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};
	class CivilianSedan_Engine_Ext_Rpm3_SoundShader: baseEngineCivilianSedan_SoundShader
	{
		samples[]=
		{
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-3000rpm-load",
				1
			}
		};
		frequency="1 * (rpm / 3000)";
		volume="engineOn * ((rpm factor [1650, 2750]) * (1 - (rpm factor [2650, 3750]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1 * ((1 - 0.25*doors) max campos)";
	};
	class CivilianSedan_Engine_Offload_Ext_Rpm3_SoundShader: baseEngineCivilianSedan_SoundShader
	{
		samples[]=
		{
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-3000rpm-offload",
				1
			}
		};
		frequency="1 * (rpm / 3000)";
		volume="engineOn * ((rpm factor [1650, 2750]) * (1 - (rpm factor [2650, 3750]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};
	class CivilianSedan_Engine_Ext_Rpm4_SoundShader: baseEngineCivilianSedan_SoundShader
	{
		samples[]=
		{
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-4000rpm-load",
				1
			}
		};
		frequency="1 * (rpm / 4000)";
		volume="engineOn * ((rpm factor [2650, 3750]) * (1 - (rpm factor [3650, 4750]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1 * ((1 - 0.25*doors) max campos)";
	};
	class CivilianSedan_Engine_Offload_Ext_Rpm4_SoundShader: baseEngineCivilianSedan_SoundShader
	{
		samples[]=
		{
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-4000rpm-offload",
				1
			}
		};
		frequency="1 * (rpm / 4000)";
		volume="engineOn * ((rpm factor [2650, 3750]) * (1 - (rpm factor [3650, 4750]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};
	class CivilianSedan_Engine_Ext_Rpm5_SoundShader: baseEngineCivilianSedan_SoundShader
	{
		samples[]=
		{
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-5000rpm-load",
				1
			}
		};
		frequency="1 * (rpm / 5000)";
		volume="engineOn * ((rpm factor [3650, 4750]) * (1 - (rpm factor [4650, 5750]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1 * ((1 - 0.25*doors) max campos)";
	};
	class CivilianSedan_Engine_Offload_Ext_Rpm5_SoundShader: baseEngineCivilianSedan_SoundShader
	{
		samples[]=
		{
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-5000rpm-offload",
				1
			}
		};
		frequency="1 * (rpm / 5000)";
		volume="engineOn * ((rpm factor [3650, 4750]) * (1 - (rpm factor [4650, 5750]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};
	class CivilianSedan_Engine_Ext_Rpm6_SoundShader: baseEngineCivilianSedan_SoundShader
	{
		samples[]=
		{
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-6000rpm-load",
				1
			}
		};
		frequency="1 * (rpm / 6000)";
		volume="engineOn * (rpm factor [4650, 5750]) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1 * ((1 - 0.25*doors) max campos)";
	};
	class CivilianSedan_Engine_Offload_Ext_Rpm6_SoundShader: baseEngineCivilianSedan_SoundShader
	{
		samples[]=
		{
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-6000rpm-offload",
				1
			}
		};
		frequency="1 * (rpm / 6000)";
		volume="engineOn * (rpm factor [4650, 5750]) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};
	class CivilianSedan_Engine_Ext_Broken_SoundShader: baseEngineCivilianSedan_SoundShader
	{
		samples[]=
		{
			
			{
				"\DZ\sounds\vehicles\shared\add_layers\Offroad_Engine_Ext_Broken",
				1
			}
		};
		frequency=0.89999998;
		volume="1.4 * 0.75 * 1 * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((900 + ((rpm - 900)/(5600/5600))) factor [(((3250+4400)/2) - 2.5*200),(((3250+4400)/2) + 200)]) * ((1 - 0.25*doors) max campos) * (rpm factor[4500,5000])";
	};
	
	//hatchback 02
	class baseEngineHatchback_02_SoundShader
	{
		range=80;
	};
	class Hatchback_02_Engine_Ext_Rpm0_SoundShader: baseEngineHatchback_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-700rpm-offload",
				1
			}
		};
		frequency="rpm / 750";
		volume="0.8 * 1 * engineOn * 0.4 * ((750 + ((rpm - 750)/(8000/5600))) factor [(((750+1000)/2) + 2.5*50),(((750+1000)/2) - 50)]) * ((1 - 0.25*doors) max campos)";
	};
	class Hatchback_02_Engine_Ext_Rpm1_SoundShader: baseEngineHatchback_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-1000rpm-load",
				1
			}
		};
		frequency="rpm / 1000";
		volume="engineOn * ((rpm factor [700, 1250]) * (1 - (rpm factor [1150, 1750]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.6 * ((1 - 0.25*doors) max campos)";
	};
	class Hatchback_02_Engine_Offload_Ext_Rpm1_SoundShader: baseEngineHatchback_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-1000rpm-offload",
				1
			}
		};
		frequency="rpm / 1000";
		volume="engineOn * ((rpm factor [700, 1250]) * (1 - (rpm factor [1150, 1750]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};
	class Hatchback_02_Engine_Ext_Rpm2_SoundShader: baseEngineHatchback_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-2000rpm-load",
				1
			}
		};
		frequency="rpm / 2000";
		volume="engineOn * ((rpm factor [1150, 1750]) * (1 - (rpm factor [1650, 2750]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.85 * ((1 - 0.25*doors) max campos)";
	};
	class Hatchback_02_Engine_Offload_Ext_Rpm2_SoundShader: baseEngineHatchback_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-2000rpm-offload",
				1
			}
		};
		frequency="rpm / 2000";
		volume="engineOn * ((rpm factor [1150, 1750]) * (1 - (rpm factor [1650, 2750]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};
	class Hatchback_02_Engine_Ext_Rpm3_SoundShader: baseEngineHatchback_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-3000rpm-load",
				1
			}
		};
		frequency="rpm / 3000";
		volume="engineOn * ((rpm factor [1650, 2750]) * (1 - (rpm factor [2650, 3750]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1 * ((1 - 0.25*doors) max campos)";
	};
	class Hatchback_02_Engine_Offload_Ext_Rpm3_SoundShader: baseEngineHatchback_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-3000rpm-offload",
				1
			}
		};
		frequency="rpm / 3000";
		volume="engineOn * ((rpm factor [1650, 2750]) * (1 - (rpm factor [2650, 3750]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};
	class Hatchback_02_Engine_Ext_Rpm4_SoundShader: baseEngineHatchback_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-4000rpm-load",
				1
			}
		};
		frequency="rpm / 4000";
		volume="engineOn * ((rpm factor [2650, 3750]) * (1 - (rpm factor [3650, 4750]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1 * ((1 - 0.25*doors) max campos)";
	};
	class Hatchback_02_Engine_Offload_Ext_Rpm4_SoundShader: baseEngineHatchback_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-4000rpm-offload",
				1
			}
		};
		frequency="rpm / 4000";
		volume="engineOn * ((rpm factor [2650, 3750]) * (1 - (rpm factor [3650, 4750]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};
	class Hatchback_02_Engine_Ext_Rpm5_SoundShader: baseEngineHatchback_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-5000rpm-load",
				1
			}
		};
		frequency="rpm / 5000";
		volume="engineOn * ((rpm factor [3650, 4750]) * (1 - (rpm factor [4650, 5750]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1 * ((1 - 0.25*doors) max campos)";
	};
	class Hatchback_02_Engine_Offload_Ext_Rpm5_SoundShader: baseEngineHatchback_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-5000rpm-offload",
				1
			}
		};
		frequency="rpm / 5000";
		volume="engineOn * ((rpm factor [3650, 4750]) * (1 - (rpm factor [4650, 5750]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};
	class Hatchback_02_Engine_Ext_Rpm6_SoundShader: baseEngineHatchback_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-6000rpm-load",
				1
			}
		};
		frequency="rpm / 6000";
		volume="engineOn * (rpm factor [4650, 5750]) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1 * ((1 - 0.25*doors) max campos)";
	};
	class Hatchback_02_Engine_Offload_Ext_Rpm6_SoundShader: baseEngineHatchback_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-6000rpm-offload",
				1
			}
		};
		frequency="rpm / 6000";
		volume="engineOn * (rpm factor [4650, 5750]) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};
	class Hatchback_02_Engine_Ext_Broken_SoundShader: baseEngineHatchback_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\DZ\sounds\vehicles\shared\add_layers\Offroad_Engine_Ext_Broken",
				1
			}
		};
		frequency=0.89999998;
		volume="0.9 * 0.75 * 1 * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((900 + ((rpm - 900)/(6200/5600))) factor [(((3250+4400)/2) - 2.5*200),(((3250+4400)/2) + 200)]) * ((1 - 0.25*doors) max campos) * (rpm factor[(6000 - 500),6000])";
	};
	
	//sedan_02
	class baseEngineSedan_02_SoundShader
	{
		range=80;
	};
	class Sedan_02_Engine_Ext_Rpm0_SoundShader: baseEngineSedan_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-700rpm-offload",
				1
			}
		};
		frequency="rpm / 750";
		volume="0.75 * 1 * engineOn * 0.4 * ((750 + ((rpm - 750)/(8000/5600))) factor [(((750+1000)/2) + 2.5*50),(((750+1000)/2) - 50)]) * ((1 - 0.25*doors) max campos)";
	};
	class Sedan_02_Engine_Ext_Rpm1_SoundShader: baseEngineSedan_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-1000rpm-load",
				1
			}
		};
		frequency="rpm / 1000";
		volume="engineOn * ((rpm factor [700, 1250]) * (1 - (rpm factor [1150, 1750]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.6 * ((1 - 0.25*doors) max campos)";
	};
	class Sedan_02_Engine_Offload_Ext_Rpm1_SoundShader: baseEngineSedan_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-1000rpm-offload",
				1
			}
		};
		frequency="rpm / 1000";
		volume="engineOn * ((rpm factor [700, 1250]) * (1 - (rpm factor [1150, 1750]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};
	class Sedan_02_Engine_Ext_Rpm2_SoundShader: baseEngineSedan_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-2000rpm-load",
				1
			}
		};
		frequency="rpm / 2000";
		volume="engineOn * ((rpm factor [1150, 1750]) * (1 - (rpm factor [1650, 2750]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.85 * ((1 - 0.25*doors) max campos)";
	};
	class Sedan_02_Engine_Offload_Ext_Rpm2_SoundShader: baseEngineSedan_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-2000rpm-offload",
				1
			}
		};
		frequency="rpm / 2000";
		volume="engineOn * ((rpm factor [1150, 1750]) * (1 - (rpm factor [1650, 2750]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};
	class Sedan_02_Engine_Ext_Rpm3_SoundShader: baseEngineSedan_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-3000rpm-load",
				1
			}
		};
		frequency="rpm / 3000";
		volume="engineOn * ((rpm factor [1650, 2750]) * (1 - (rpm factor [2650, 3750]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1 * ((1 - 0.25*doors) max campos)";
	};
	class Sedan_02_Engine_Offload_Ext_Rpm3_SoundShader: baseEngineSedan_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-3000rpm-offload",
				1
			}
		};
		frequency="rpm / 3000";
		volume="engineOn * ((rpm factor [1650, 2750]) * (1 - (rpm factor [2650, 3750]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};
	class Sedan_02_Engine_Ext_Rpm4_SoundShader: baseEngineSedan_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-4000rpm-load",
				1
			}
		};
		frequency="rpm / 4000";
		volume="engineOn * ((rpm factor [2650, 3750]) * (1 - (rpm factor [3650, 4750]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1 * ((1 - 0.25*doors) max campos)";
	};
	class Sedan_02_Engine_Offload_Ext_Rpm4_SoundShader: baseEngineSedan_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-4000rpm-offload",
				1
			}
		};
		frequency="rpm / 4000";
		volume="engineOn * ((rpm factor [2650, 3750]) * (1 - (rpm factor [3650, 4750]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)"
	};
	class Sedan_02_Engine_Ext_Rpm5_SoundShader: baseEngineSedan_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-5000rpm-load",
				1
			}
		};
		frequency="rpm / 5000";
		volume="engineOn * ((rpm factor [3650, 4750]) * (1 - (rpm factor [4650, 5750]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1 * ((1 - 0.25*doors) max campos)";
	};
	class Sedan_02_Engine_Offload_Ext_Rpm5_SoundShader: baseEngineSedan_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-5000rpm-offload",
				1
			}
		};
		frequency="rpm / 5000";
		volume="engineOn * ((rpm factor [3650, 4750]) * (1 - (rpm factor [4650, 5750]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};
	class Sedan_02_Engine_Ext_Rpm6_SoundShader: baseEngineSedan_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-6000rpm-load",
				1
			}
		};
		frequency="rpm / 6000";
		volume="engineOn * (rpm factor [4650, 5750]) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1 * ((1 - 0.25*doors) max campos)";
	};
	class Sedan_02_Engine_Offload_Ext_Rpm6_SoundShader: baseEngineSedan_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-i4\i4-6000rpm-offload",
				1
			}
		};
		frequency="rpm / 6000";
		volume="engineOn * (rpm factor [4650, 5750]) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};
	class Sedan_02_Engine_Ext_Broken_SoundShader: baseEngineSedan_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\DZ\sounds\vehicles\shared\add_layers\Offroad_Engine_Ext_Broken",
				1
			}
		};
		frequency=0.89999998;
		volume="1.4 * 0.75 * 1 * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((900 + ((rpm - 900)/(6500/5600))) factor [(((3250+4400)/2) - 2.5*200),(((3250+4400)/2) + 200)]) * ((1 - 0.25*doors) max campos) * (rpm factor[5400,5900])";
	};
	
	//humvee----------------------------------------------------------------------------
	// yes its technically a diesel v8 but but I couldn't 
	// get a quality recording of a v8 diesel so im using gas v8 sounds
	class baseEngineOffroad_02_SoundShader
	{
		range=80;
	};
	class Offroad_02_Engine_Ext_Rpm0_SoundShader: baseEngineOffroad_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-v8\v8-650rpm-offload",
				1
			}
		};
		frequency="rpm / 625";
		volume="1 * engineOn * 0.4 * ((625 + ((rpm - 625)/(8000/5600))) factor [(((625+1000)/2) + 2.5*50),(((620+1000)/2) - 50)]) * ((1 - 0.25*doors) max campos)";
	};
	class Offroad_02_Engine_Ext_Rpm1_SoundShader: baseEngineOffroad_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-v8\v8-1000rpm-load",
				1
			}
		};
		frequency="rpm / 1000";
		volume="engineOn * ((rpm factor [625, 1150]) * (1 - (rpm factor [1050, 1350]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.7 * ((1 - 0.25*doors) max campos)";
	};
	class Offroad_02_Engine_Offload_Ext_Rpm1_SoundShader: baseEngineOffroad_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-v8\v8-1000rpm-offload",
				1
			}
		};
		frequency="rpm / 1000";
		volume="engineOn * ((rpm factor [625, 1150]) * (1 - (rpm factor [1050, 1350]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.9 * ((1 - 0.25*doors) max campos)";
	};
	class Offroad_02_Engine_Ext_Rpm2_SoundShader: baseEngineOffroad_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-v8\v8-1500rpm-load",
				1
			}
		};
		frequency="rpm / 1500";
		volume="engineOn * ((rpm factor [1050, 1350]) * (1 - (rpm factor [1250, 1850]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1 * ((1 - 0.25*doors) max campos)";
	};
	class Offroad_02_Engine_Offload_Ext_Rpm2_SoundShader: baseEngineOffroad_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-v8\v8-1500rpm-offload",
				1
			}
		};
		frequency="rpm / 1500";
		volume="engineOn * ((rpm factor [1050, 1350]) * (1 - (rpm factor [1250, 1850]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.9 * ((1 - 0.25*doors) max campos)";
	};
	class Offroad_02_Engine_Ext_Rpm3_SoundShader: baseEngineOffroad_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-v8\v8-2000rpm-load",
				1
			}
		};
		frequency="rpm / 2000";
		volume="engineOn * ((rpm factor [1250, 1850]) * (1 - (rpm factor [1750, 2350]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1.1 * ((1 - 0.25*doors) max campos)";
	};
	class Offroad_02_Engine_Offload_Ext_Rpm3_SoundShader: baseEngineOffroad_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-v8\v8-2000rpm-offload",
				1
			}
		};
		frequency="rpm / 2000";
		volume="engineOn * ((rpm factor [1250, 1850]) * (1 - (rpm factor [1750, 2350]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.9 * ((1 - 0.25*doors) max campos)";
	};
	class Offroad_02_Engine_Ext_Rpm4_SoundShader: baseEngineOffroad_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-v8\v8-2500rpm-load",
				1
			}
		};
		frequency="rpm / 2500";
		volume="engineOn * ((rpm factor [1750, 2350]) * (1 - (rpm factor [2250, 2850]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1.1 * ((1 - 0.25*doors) max campos)";
	};
	class Offroad_02_Engine_Offload_Ext_Rpm4_SoundShader: baseEngineOffroad_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-v8\v8-2500rpm-offload",
				1
			}
		};
		frequency="rpm / 2500";
		volume="engineOn * ((rpm factor [1750, 2350]) * (1 - (rpm factor [2250, 2850]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.9 * ((1 - 0.25*doors) max campos)";
	};
	class Offroad_02_Engine_Ext_Rpm5_SoundShader: baseEngineOffroad_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-v8\v8-3000rpm-load",
				1
			}
		};
		frequency="rpm / 3000";
		volume="engineOn * ((rpm factor [2250, 2850]) * (1 - (rpm factor [2750, 3350]))) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1.1 * ((1 - 0.25*doors) max campos)";
	};
	class Offroad_02_Engine_Offload_Ext_Rpm5_SoundShader: baseEngineOffroad_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-v8\v8-3000rpm-offload",
				1
			}
		};
		frequency="rpm / 3000";
		volume="engineOn * ((rpm factor [2250, 2850]) * (1 - (rpm factor [2750, 3350]))) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.9 * ((1 - 0.25*doors) max campos)";
	};
	class Offroad_02_Engine_Ext_Rpm6_SoundShader: baseEngineOffroad_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-v8\v8-3500rpm-load",
				1
			}
		};
		frequency="rpm / 3500";
		volume="engineOn * (rpm factor [2750, 3350]) * (thrust factor[0.1, 0.45]) * (0.7 + 0.3 * (speed factor [10, 60])) * 1 * ((1 - 0.25*doors) max campos)";
	};
	class Offroad_02_Engine_Offload_Ext_Rpm6_SoundShader: baseEngineOffroad_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\VehicleRework\sounds\vehicles\engines\gasoline-v8\v8-3500rpm-offload",
				1
			}
		};
		frequency="rpm / 3500";
		volume="engineOn * (rpm factor [2750, 3350]) * (thrust factor[0.6, 0.2]) * (0.7 + 0.3 * (speed factor [10, 60])) * 0.8 * ((1 - 0.25*doors) max campos)";
	};
	//will this ever even be played? i gave it a rev limiter lol
	class Offroad_02_Engine_Ext_Broken_SoundShader: baseEngineOffroad_02_SoundShader
	{
		samples[]=
		{
			
			{
				"\DZ\sounds\vehicles\shared\add_layers\Offroad_02_Engine_Ext_Broken",
				1
			}
		};
		frequency=0.80000001;
		volume="1.35 * 0.75 * 1 * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((3250+4400)/2) - 2.5*200),(((3250+4400)/2) + 200)]) * ((1 - 0.25*doors) max campos) * (rpm factor[4800,6200])";
	};
};
class CfgSoundSets
{
	//offroad hatchback
	class baseEngine_EXT_SoundSet
	{
		sound3DProcessingType="Vehicle_Ext_3DProcessingType";
		distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
		volumeCurve="vehicleEngineAttenuationCurve";
		volumeFactor=1;
		occlusionFactor=0;
		obstructionFactor=0;
		spatial=1;
		loop=1;
		positionOffset[]={0,0,0.30000001};
	};
	class offroad_Engine_Ext_Rpm6_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[]=
		{
			"offroad_Engine_Ext_Rpm6_SoundShader"
		};
		volumeFactor=1;
	};
	class offroad_Engine_Offload_Ext_Rpm6_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[]=
		{
			"offroad_Engine_Offload_Ext_Rpm6_SoundShader"
		};
		volumeFactor=1;
	};
	
	//civ sedan
	class baseEngineCivilianSedan_EXT_SoundSet
	{
		sound3DProcessingType="Vehicle_Ext_3DProcessingType";
		distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
		volumeCurve="vehicleEngineAttenuationCurve";
		volumeFactor=1;
		occlusionFactor=0;
		obstructionFactor=0;
		spatial=1;
		loop=1;
	};
	class CivilianSedan_Engine_Ext_Rpm6_SoundSet: baseEngineCivilianSedan_EXT_SoundSet
	{
		soundShaders[]=
		{
			"CivilianSedan_Engine_Ext_Rpm6_SoundShader"
		};
		volumeFactor=1;
	};
	class CivilianSedan_Engine_Offload_Ext_Rpm6_SoundSet: baseEngineCivilianSedan_EXT_SoundSet
	{
		soundShaders[]=
		{
			"CivilianSedan_Engine_Offload_Ext_Rpm6_SoundShader"
		};
		volumeFactor=1;
	};
	
	//hatchback 02
	class baseEngineHatchback_02_EXT_SoundSet
	{
		sound3DProcessingType="Vehicle_Ext_3DProcessingType";
		distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
		volumeCurve="vehicleEngineAttenuationCurve";
		volumeFactor=1;
		occlusionFactor=0;
		obstructionFactor=0;
		spatial=1;
		loop=1;
	};
	class Hatchback_02_Engine_Ext_Rpm6_SoundSet: baseEngineHatchback_02_EXT_SoundSet
	{
		soundShaders[]=
		{
			"Hatchback_02_Engine_Ext_Rpm6_SoundShader"
		};
		volumeFactor=1;
	};
	class Hatchback_02_Engine_Offload_Ext_Rpm6_SoundSet: baseEngineHatchback_02_EXT_SoundSet
	{
		soundShaders[]=
		{
			"Hatchback_02_Engine_Offload_Ext_Rpm6_SoundShader"
		};
		volumeFactor=1;
	};
	
	//sedan 02
	class baseEngineSedan_02_EXT_SoundSet
	{
		sound3DProcessingType="Vehicle_Ext_3DProcessingType";
		distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
		volumeCurve="vehicleEngineAttenuationCurve";
		volumeFactor=1;
		occlusionFactor=0;
		obstructionFactor=0;
		spatial=1;
		loop=1;
	};
	class Sedan_02_Engine_Ext_Rpm6_SoundSet: baseEngineSedan_02_EXT_SoundSet
	{
		soundShaders[]=
		{
			"Sedan_02_Engine_Ext_Rpm6_SoundShader"
		};
		volumeFactor=1;
	};
	class Sedan_02_Engine_Offload_Ext_Rpm6_SoundSet: baseEngineSedan_02_EXT_SoundSet
	{
		soundShaders[]=
		{
			"Sedan_02_Engine_Offload_Ext_Rpm6_SoundShader"
		};
		volumeFactor=1;
	};
	
	//humvee----------------------------------------------------------------------------
	//uses also baseEngine_EXT_SoundSet for some reason? so no need to define
	class offroad_02_Engine_Ext_Rpm6_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[]=
		{
			"offroad_02_Engine_Ext_Rpm6_SoundShader"
		};
		volumeFactor=1;
	};
	class offroad_02_Engine_Offload_Ext_Rpm6_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[]=
		{
			"offroad_02_Engine_Offload_Ext_Rpm6_SoundShader"
		};
		volumeFactor=1;
	};
};
