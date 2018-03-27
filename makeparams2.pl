#!/usr/bin/perl
#use strict;
#use warnings;

# make parameter files ######################################################

print "Writing parameter files\n";

#check if counter values are set (otherwise loop is infinite)
#$val1Max != 0 || die "Error: val1max string or 0\n";
#$val2Max != 0 || die "Error: val2max string or 0\n";
$val1increment != 0 || die "Error: val1increment string or 0\n";
$val2increment != 0 || die "Error: val2increment string or 0\n";

#define begining values
my $ctr1=1;
my $ctr2=1;
my $val1=$val1Base;
my $val2=$val2Base;
#loop until values have reached their max
while ( $val1 <= $val1Max )
{

    our $param1 = $val1;

    while ( $val2 <= $val2Max )
    {

        our $param2 = $val2;

        #specific name for each instance that will run
        my $instance_name=$run_name . "." . $ctr1 . "." . $ctr2;
        #pub file name
        my $file_name=$instance_name . "_params.txt";
        #open file for writing and print the following
        #print "$localpath\n";

        if($setCargoMT_dist>=0) {
            if($Rname eq "param1") {
                print "triggered, cz=$cz";
                $cz = $pz1 + $R_MT1 + $setCargoMT_dist + $param1;
                print " after, cz=$cz\n";
            } elsif($Rname eq "param2") {
                print "triggered, cz=$cz";
                $cz = $pz1 + $R_MT1 + $setCargoMT_dist + $param2;
                print " after, cz=$cz\n";
            }
        }
        open (FOOD, ">$file_name" );
        print FOOD << "EOF";
//
// Parameters for
// $instance_name
//
// Generated by makeparams.pl
//
//

//Input parameters------------------------------------------------------------

//Motor Parameters
//entry 1 for kinesins, entry 2 for dynein

N      $$N1name $$N2name //number of motors

//Muller Sim
F_s    $$F_s1name $$F_s2name //stall force (pN) 5
F_d    $$F_d1name $$F_d2name //detachment force (pN) 4
eps_0  $$eps_01name $$eps_02name //base unbinding rate (1/sec) 1
pi_0   $$pi_01name $$pi_02name //base binding rate (1/sec) 5
v_f    $$v_f1name $$v_f2name //unloaded forward velocity (microns/s) 1
v_b    -.006 .006 //max backward velocity (microns/s) .006

//Kunwar Sim
a         $$a1name $$a2name  //superstall parameter 1.07
b         $$b1name $$b2name  //superstall parameter .186
w         $$w1name $$w2name        //force-velocity curve exponent 2
L         $$L1name $$L2name      //motor spring rest length (microns) .1
k_m       $$k_m1name $$k_m2name    //motor spring constant (pN/micron) 320
step_size $$s1name $$s2name  //length of a motor step (microns) .008

//Bovyn Sim
D_m       $$D_m1name $$D_m2name   //diffusion constant of the anchor (microns^2/s) 3-5

//Cargo Parameters

center  $$cxname $$cyname $$czname //initial location of center of Cargo [0 0 0]
R       $$Rname   //Cargo Radius (microns) .25
eta     $$etaname //Dynamic viscosity of surrounding fluid (10x water) 10*8.9E-4

//Microtubule Parameters

n_MTs   $n_MTs    // number of MTs in simulation
kcMT    $$kcMTname  //steric spring to keep cargo out of MT (pN/micron) 40000

//Keyword Arguments------------------------------------------------------------

//Motor Location

InitialLocations $InitialLocations $IL2 $IL3
/*
1:
2: Uniform Random on the surface of the sphere
3: Top
4: Bottom
5: Uniform random, rotate so type0motor0 is on top
6: Uniform random, rotate so motor with most close neighbors is on top
7: Start at a defined elevation (specify in 3rd input in degrees)
8:
9:
10:

second parameter: 1  - kin at bottom, 2 for dyn, 3 - kin on top, 4 for dyn
third parameter used to pass in angle (degrees)
 */

MotorDiffusion $MotorDiffusion
/*
1: no drag - Diffuse all motors by legacy function
2: no drag - Only diffuse non-attached motors by legacy function
3: free motors - deterministic (cargo trans and rot, motor diffusion set to 0)
4: free motors
5: free motors - cargo diffusion (rot and trans) set to 0
6: free motors - cargo rot and anchor diffusion set to 0
7: free motors - cargo trans and anchor diffusion set to 0
8: free motors - debugging case
9: free motors - anchor diffusion set to 0
10: bead motors
11: bead motors - deterministic (cargo trans and rot, motor diffusion set to 0)
12:
13:
14:
15:
 */

//Interaction of motors with MT

InitialBinding $InitialBinding $IB2
/*
1: Bind all in range
2: Bind only 1 Kin
3: Don’t bind
4: Bind 1 dyn
5: Force all motors to bind (debugging)
6:
7:
8:
9:
10:
 */

Binding $Binding $B2
/*
1: set given binding rate if in range
2: motors don’t bind
3: always bind if in range
4: (not implemented yet) set binding rate if between L and inner limit (fraction*L)
5: Normal binding, but excluded in region for 0nm MT crossings
6:
7:
8:
9:
10:
 */

Unbinding $Unbinding
/*
1: Ambarish Unbinding
2: unbind at constant rate eps_0
3: NoUnbinding
4: different between assisting and hindering
5:
6:
7:
8:
9:
10:
 */

Stepping $Stepping $S2
/*
1: Step at rate determined by unloaded velocity
2: Stepping rate depends on force (Ambarish)
3: no stepping
4: override stepping rate with second input (999999999 for always step)
5: Don’t step into excluded in region for 0nm MT crossings
6:
7:
8:
9:
10:
 */

InitialNucleotideBehavior $InitialNucleotideBehavior
/*
1: All start ready
2: All start not ready
3:
4:
5:
6:
7:
8:
9:
10:
 */

NucleotideBehavior $NucleotideBehavior $NB2 $NB3
/*
1: No nucleotide exchange (explicit)
2: set constant nucleotide exchange rate (give in arguments 2 and 3)
3:
4:
5:
6:
7:
8:
9:
10:
second and third arguments are nucleotide exchange rates
if first argument is set to 0, nucleotide exchange is ignored
 */

//Bound motor behavior

MotorLoading $MotorLoading
/*
1: Load by stretch of necks
2: Force always 0
*/

//Cargo Behavior

CargoBehavior $CargoBehavior
/*
1: Cargo moves normally
2: On rail - cargo moves only in x
3: stuck - cargo can’t move at all
4:
5:
6:
7:
8:
9:
10:
 */

ExternalForce $ExternalForce $EF2 $EF3 $EF4
/*
1: no external forces
2: external force given by next three values (x y z)
3: force given by optical trap (not implemented yet)
*/

ExternalTorque $ExternalTorque $ET2 $ET3 $ET4
/*
1: no external torque
2: external torque given by next three values (x y z)

*/

UseSteric $UseSteric
/*
1: Use steric force
0: Don’t use steric force

Note: steric force spring constant specified in kcMT
/*

//Output

ReturnDetails $ReturnDetails $RD2 $RD3 $RD4
/* create text files with records of anchor and head locations
0: Don’t return any details during simulation
1: Return details every step
2: Return details only when something important happens (step, attachment, etc.)
3: Return details every 100 steps
4: Return details every .001 seconds
5:
set second value to 1 to return file with head locations, 0 for no
set third value to 1 to return file with forces, 0 for no
set fourth value to 1 to return file with rotation of cargo
*/

ReturnFinalState $ReturnFinalState
/*
Not implemented

*/

//Simulation end conditions (1=yes,0=no)
RequireAttached $RequireAttached
StopOnMotor2Attach $StopOnMotor2Attach
StopOnAllAttached $StopOnAllAttached
StopOnStep $StopOnStep                //0 for don’t stop, otherwise enter step
StopOnTime $StopOnTime                //0 for don’t stop, otherwise enter time
StopOnDistance $StopOnDistance            //0 for don’t stop, otherwise enter distance in microns
StopBelowThetaC $StopBelowThetaC $SB        //2nd value elevation in radians -pi/2 to pi/2
multiMT_assay $multiMT_assay $$MT_anglename            //1 for switch, 2 for ToW
StopOnBeadDissociation $StopOnBeadDissociation    //stop if bead is > 500nm from all MTs
StopOnCargoBinding $StopOnCargoBinding        //stop when any motor binds

//Success Conditions
Success $Success $SS2
/*success success_mode - if mode=0, success if result==success
0: Nothing counts as success
1: type0motor0 is bound
2: went > 10 microns
3: underwent a tug of war
4:
5:
6:
7:
8:
9:
*/

//debugging
dt_override $dt_override //set this to 0 for no override, otherwise overrides set dt

//check for correct read in
checkbit 732
checkbit2 576

EOF
        close FOOD;
        #MT params file
        my $file_name=$instance_name . "_MT_params.txt";
        #open file for writing and print the following
        open (FOOD, ">$file_name" );
        print FOOD << "EOF";
//
// params for MTs
//

//point (x y z) unit vector (x y z) R_MT
($px1 $py1 $pz1) ($vx1 $vy1 $vz1) $R_MT1
($px2 $py2 $pz2) ($vx2 $vy2 $vz2) $R_MT2

EOF
        close FOOD;
        #done writing

        #increment inner loop values
        $val2 += $val2increment;
        $ctr2++;
        $ctr2 < 100 || die "Woah, made more than 100 files\n";

    }
    #reset loop 2 values
    $val2=$val2Base;
    $ctr2=1;
    #increment loop 1 values
    $val1 += $val1increment;
    $ctr1++;
    $ctr1 < 100 || die "Woah, made more than 100 files\n";
}
