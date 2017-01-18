//prototypes
void getInputParams( void );

void getInputParams( void )
{

    /************ Model and numerical parameters FROM FILE *******************/

    //open the parameter file (name specified in drive_motors.c)
    //fParams initialized in motors.h

    //open the MT file
    strcpy(MTparamFileName,paramFileName);
    strcat(MTparamFileName,"_MT_params");
    strcat(MTparamFileName,".txt");
    fMTParams = fopen(MTparamFileName, "r");

    //open the param file
    strcat(paramFileName,"_params");
    strcat(paramFileName,".txt");
    fParams = fopen(paramFileName, "r");

    //My approach: use fgets() to scan each line into the temporary string
    //then use sscanf() to find the values
    //learned the pattern must include the first thing on the line
    //(here stored to string called blah)
    //this lets us have comments in the file
    //(using fscanf didn't like having extra text after the numbers)

    //Go through each line and find the values of the input paramters
    //skip the first few
    for(int n_lines=1;n_lines<=13;n_lines++)
    {
      fgets(tmpString, 100, fParams);
    }

    //motor parameters

    fgets(tmpString, 100, fParams);
    if(isnan(N[0]) || N[0]==0){
        sscanf(tmpString,"%s %ld %ld", blah,&N[0], &N[1]);
    }else{//if not NAN, the value was set in command line so trash it
        sscanf(tmpString,"%s %lf %ld", blah,&trash, &N[1]);
    }
    fgets(tmpString, 100, fParams);
    fgets(tmpString, 100, fParams);
    //Muller
    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %lf %lf", blah,&F_s[0], &F_s[1]);
    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %lf %lf", blah,&F_d[0], &F_d[1]);
    fgets(tmpString, 100, fParams);
    //Can input eps_0[0] from command line
    //only read if its still set to default nan value
    if(isnan(eps_0[0]) || eps_0[0]==0){
        sscanf(tmpString,"%s %lf %lf", blah,&eps_0[0], &eps_0[1]);
    }
    else{//if not NAN, the value was set in command line so trash it
        sscanf(tmpString,"%s %lf %lf", blah,&trash, &eps_0[1]);
    }
    fgets(tmpString, 100, fParams);
    if(isnan(pi_0[0]) || pi_0[0]==0){
        sscanf(tmpString,"%s %lf %lf", blah,&pi_0[0], &pi_0[1]);
    }
    else{//if not NAN, the value was set in command line so trash it
        sscanf(tmpString,"%s %lf %lf", blah,&trash, &pi_0[1]);
    }
    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %lf %lf", blah,&v_f[0], &v_f[1]);
    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %lf %lf", blah,&v_b[0], &v_b[1]);
    fgets(tmpString, 100, fParams);
    fgets(tmpString, 100, fParams);
    //Kunwar
    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %lf %lf", blah,&a_param[0], &a_param[1]);
    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %lf %lf", blah,&b[0], &b[1]);
    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %lf %lf", blah,&w[0], &w[1]);
    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %lf %lf", blah,&L[0], &L[1]);
    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %lf %lf", blah,&k_m[0], &k_m[1]);
    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %lf %lf", blah,&step_size[0], &step_size[1]);
    fgets(tmpString, 100, fParams);
    fgets(tmpString, 100, fParams);
    //Bovyn
    fgets(tmpString, 100, fParams);
    //Can input D_m[0] from command line
    //only read if its still set to default nan value
    if(isnan(D_m[0]) || D_m[0]==0){
        sscanf(tmpString,"%s %lf %lf", blah,&D_m[0], &D_m[1]);
    }
    else{//if not NAN, the value was set in command line so trash it
        sscanf(tmpString,"%s %lf %lf", blah,&trash, &D_m[1]);
    }
    fgets(tmpString, 100, fParams);
    fgets(tmpString, 100, fParams);
    fgets(tmpString, 100, fParams);

    //Cargo Parameters

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %lf %lf %lf", blah,
        &center_initial[0], &center_initial[1],&center_initial[2]);
    if(verboseTF>1){
        printf("Initial cargo center is(%g,%g,%g)\n",center_initial[0],center_initial[1],center_initial[2]);
    }
    fgets(tmpString, 100, fParams);
    if(isnan(R) || R==0){
        sscanf(tmpString,"%s %lf", blah,&R);
    }
    else{//if not NAN, the value was set in command line so trash it
        sscanf(tmpString,"%s %lf", blah,&trash);
    }

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %lf", blah,&eta);

    fgets(tmpString, 100, fParams);
    fgets(tmpString, 100, fParams);
    fgets(tmpString, 100, fParams);

    //Microtubule Parameters

    //number of MTs
    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d", blah,&n_MTs);
    //MT-cargo steric spring constant
    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %lf", blah,&kcMT);

    //make sure we have the right values
    //printf("Read in motor numbers as %ld %ld\n",N[0],N[1]);
    //printf("Read in kcMT as %lf\n",kcMT);


    // Consequent parameters

    muCargoTranslation=1/(6*pi*eta*R);    //Sphere mobility from Stokes-Einstein-Southerland
    muCargoRotation=1/(8*pi*eta*pow(R,3));
    for(m=0;m<2;m++){
      mu_m[m]=D_m[m]/kBT;
    }
    DCargoRotation=kBT*muCargoRotation;
    DCargoTranslation=kBT*muCargoTranslation;

    //find maximum time step for attached motors
    //set to satisfy
    if(verboseTF>1){
        printf("Choosing Timesteps:\n");
    }

    dt_max_Motor=0;
    if(N[0]>0){
        dt_max_Motor=.9*1/(k_m[0]*muCargoTranslation);
    }
    if( N[1]>0 && (k_m[1]*muCargoTranslation) > (k_m[0]*muCargoTranslation) ){
        dt_max_Motor=.9*1/(k_m[1]*muCargoTranslation);
    }
    if(dt_max_Motor==0){
        if(verboseTF>2){
            printf("dt_max for motor springs is 0 (no motors?) - setting to default.\n");
        }
        dt_max_Motor=dt_default;
    }

    //find maximum time step for steric spring that keeps cargo out of MT
    dt_max_Steric=.9*1/(muCargoTranslation*kcMT);
    if(verboseTF>1){
        printf("     Max time step for steric spring is %g\n",dt_max_Steric);
    }

    //find max time step for just diffusion of the motors
    //set to satisfy sqrt(D*dt)<<R
    dt_max_Diffusion=0;
    if(N[0]>0){
        dt_max_Diffusion=.01*pow(R,2)/D_m[0];
    }
    if(N[1]>0 && D_m[1]>D_m[0]){
        dt_max_Diffusion=.01*pow(R,2)/D_m[1];
    }
    if(dt_max_Diffusion==0){
        if(verboseTF>2){
            printf("dt_max for diffusion is 0 (no motors?) - setting to default.\n");
        }
        dt_max_Diffusion=dt_default;
    }

    //the default max is the smaller of the two maximum dt's
    if(dt_max_Diffusion<dt_max_Motor){
        dt_max_base=dt_max_Diffusion;
        if(verboseTF>1){
            printf("     Choosing max time step based on motor diffusion, dt=%g\n",dt_max_base);
        }
    }
    else{
        dt_max_base=dt_max_Motor;
        if(verboseTF>1){
            printf("     Choosing max time step based on motor spring, dt=%g\n",dt_max_base);
        }
    }

    //overrule time step manually if too large
    if(dt_max_base>dt_default){
        dt_max_base=dt_default;
        if(verboseTF>1){
            printf("     Time step too large, overruling. dt=%f\n",dt_max_base);
        }
    }




    //all of this may not have been necessay since dt_max_Motor is also a
    //function of D_m. May always be lower at measured k_m of 320 pN/micron

    for(m=0;m<2;m++){
      unloaded_step_rate[m]=fabs(v_f[m]/step_size[m]);
    }

    /************ Simulation Keywords FROM FILE *******************/

    for(int n_lines=1;n_lines<=5;n_lines++)
      fgets(tmpString, 100, fParams);

    //Initial Locations

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d %d %lf",blah,&InitialLocations,&SetAtBottom,&InitAngle);

    for(int n_lines=1;n_lines<=16;n_lines++)
      fgets(tmpString, 100, fParams);

    //Motor Diffusion

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d",blah,&MotorDiffusion);

    if(MotorDiffusion<10){
        if(N[0]+N[1] > available_motors_free){
            printf("\n\n\nError! Exiting!\nAsked for unsupported number of free motors\nCompile with different keyword to include more\n\n\n");
            exit(0);
        }
    }else{
        if((N[0]+N[1] > available_motors_bead)
        || ((available_motors_bead==101 && (N[0]+N[1]-1)%10!=0) && !(N[0]+N[1]==0))){
            printf("\n\n\nError! Exiting!\nAsked for unsupported number of bead motors\nCompile with different keyword\n\n\n");
            exit(0);
        }
    }

    for(int n_lines=1;n_lines<=20;n_lines++)
      fgets(tmpString, 100, fParams);

    //InitialBinding

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d %lf",blah,&InitialBinding,&initial_head);

    for(int n_lines=1;n_lines<=13;n_lines++)
    fgets(tmpString, 100, fParams);

    //Binding

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d %lf",blah,&Binding,&innerlimit);

    for(int n_lines=1;n_lines<=13;n_lines++)
    fgets(tmpString, 100, fParams);

    //Unbinding

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d",blah,&Unbinding);

    for(int n_lines=1;n_lines<=13;n_lines++)
      fgets(tmpString, 100, fParams);

    //Stepping

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d %lf",blah,&Stepping,&input_step_rate);

    for(int n_lines=1;n_lines<=13;n_lines++)
        fgets(tmpString, 100, fParams);

    //initial nucleotide Behavior

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d",blah,&InitialNucleotideBehavior);

    for(int n_lines=1;n_lines<=13;n_lines++)
        fgets(tmpString, 100, fParams);

    //Nucleotide

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d %lf %lf",blah,&NucleotideBehavior,&base_exchange_rate[0],&base_exchange_rate[1]);

    for(int n_lines=1;n_lines<=17;n_lines++)
        fgets(tmpString, 100, fParams);

    //Motor Loading

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d",blah,&MotorLoading);

    for(int n_lines=1;n_lines<=7;n_lines++)
      fgets(tmpString, 100, fParams);

    //CargoBehavior

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d",blah,&CargoBehavior);

    for(int n_lines=1;n_lines<=13;n_lines++)
    fgets(tmpString, 100, fParams);

    //External Force

    fgets(tmpString, 100, fParams);
    if(isnan(Ftrap[0]) || Ftrap[0]==0){
        sscanf(tmpString,"%s %d %lf %lf %lf",blah,&external_force,&Ftrap[0],&Ftrap[1],&Ftrap[2]);
    }
    else{//if not NAN, the value was set in command line so trash it
        sscanf(tmpString,"%s %d %lf %lf %lf",blah,&external_force,&trash,&Ftrap[1],&Ftrap[2]);
    }

    for(int n_lines=1;n_lines<=6;n_lines++)
      fgets(tmpString, 100, fParams);

    //ExternalTorque

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d %lf %lf %lf",blah,&external_torque,&TorqeExt[0],&TorqeExt[1],&TorqeExt[2]);

    for(int n_lines=1;n_lines<=6;n_lines++)
      fgets(tmpString, 100, fParams);

    //Use Steric

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d",blah,&UseSteric);

    for(int n_lines=1;n_lines<=9;n_lines++)
    fgets(tmpString, 100, fParams);

    //ReturnDetails

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d %d %d %d",blah,&ReturnDetails,&ReturnHeads,&ReturnForces,&ReturnOmega);

    for(int n_lines=1;n_lines<=12;n_lines++)
      fgets(tmpString, 100, fParams);

    //ReturnFinalState

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d",blah,&ReturnFinalState);

    for(int n_lines=1;n_lines<=6;n_lines++)
      fgets(tmpString, 100, fParams);

    //End conditions
    if(verboseTF>1){
        printf("Stopping on:\n");
    }

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d",blah,&Requirebound);

    if(Requirebound && verboseTF>1){
        printf("     All motors unbound\n");
    }

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d",blah,&StopOnMotor2Attach);

    if(StopOnMotor2Attach && verboseTF>1){
        printf("     type0motor1 attach\n");
    }

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d",blah,&StopOnAllbound);

    if(StopOnAllbound && verboseTF>1){
        printf("     All motors bound\n");
    }

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %ld",blah,&StopOnStep);

    if(StopOnStep && verboseTF>1){
        printf("     Step %ld\n",StopOnStep);
    }

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %lf",blah,&StopOnTime);

    if(StopOnTime && verboseTF>1){
        printf("     After %g seconds\n",StopOnTime);
    }

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %lf",blah,&StopOnDistance);

    if(StopOnDistance && verboseTF>1){
        printf("     Cargo x location > %g microns\n",StopOnDistance);
    }

    fgets(tmpString, 100, fParams);
    if(isnan(theta_c)){
        sscanf(tmpString,"%s %d %lf",blah,&StopBelowThetaC,&theta_c);
    }
    else{//if not NAN, the value was set in command line so trash it
        sscanf(tmpString,"%s %d %lf", blah,&StopBelowThetaC,&trash);
        //StopBelowThetaC=1;
    }

    if(StopBelowThetaC && verboseTF>1){
        printf("     Motor below critical angle of %g\n",theta_c);
    }

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d",blah,&MultiMTassay);

    if(MultiMTassay && verboseTF>1){
        printf("     MT assay conditions\n");
    }

    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d",blah,&StopOnBeadDissociation);

    if(StopOnBeadDissociation && verboseTF>1){
        printf("     Bead > .5 microns from all MTs\n");
    }

    //success condition

    fgets(tmpString, 100, fParams);
    fgets(tmpString, 100, fParams);
    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d %d",blah,&success,&success_mode);

    //debugging

    for(int n_lines=1;n_lines<=15;n_lines++)
      fgets(tmpString, 100, fParams);

    sscanf(tmpString,"%s %lf",blah,&dt_override);

    if(dt_override){
        dt_max_base=dt_override;
        if(verboseTF>0){
            printf("Overriding dt. Now %g\n",dt_override);
        }
    }

    //check bit

    fgets(tmpString, 100, fParams);
    fgets(tmpString, 100, fParams);
    fgets(tmpString, 100, fParams);
    sscanf(tmpString,"%s %d",blah,&check_bit);

    if(check_bit!=732){
        printf("\n\n\nError! Exiting!\n\n\nCheck bit incorrect, mismatch between paramers file and read in code\n");
        exit(0);
    }

    //close file
    fclose(fParams);

    if(verboseTF>4){
        printf("read in all params from params file\n");
    }

    //Read in MT params from MTparams file

    //skip the header lines
    for(int n_lines=1;n_lines<=5;n_lines++)
    {
      fgets(tmpString, 100, fMTParams);
    }

    //the parameters of each MT
    for(i=0;i<n_MTs;i++){
        fgets(tmpString, 100, fMTParams);
        sscanf(tmpString,"(%lf %lf %lf) (%lf %lf %lf) %lf",
            &MTpoint[i][0],&MTpoint[i][1],&MTpoint[i][2],
            &MTvec[i][0],&MTvec[i][1],&MTvec[i][2],
            &R_MT[i]);
    }

    //set offset if one is input
    if(!isnan(z_MT_offset)){
        MTpoint[0][2]+=z_MT_offset;
    }

    //print out what we have
    if(verboseTF>2){
        printf("Running with %d MTs, with locations, unit vectors and radii:\n",n_MTs);
        for(i=0;i<n_MTs;i++){
            printf("     (%g,%g,%g) (%g,%g,%g) %g\n",
            MTpoint[i][0],MTpoint[i][1],MTpoint[i][2],
            MTvec[i][0],MTvec[i][1],MTvec[i][2],
            R_MT[i]);
        }
    }

    fclose(fMTParams);



}
