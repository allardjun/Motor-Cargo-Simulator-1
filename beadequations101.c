//prototypes
void bead_equations();

void bead_equations(){
    switch(total_motors){
        case 1:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmTangential[0][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmTangential[0][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmTangential[0][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] + c[2]*FmTangential[0][1] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] - c[2]*FmTangential[0][0] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] + c[1]*FmTangential[0][0] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            break;

        case 11:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmRadial[10][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmRadial[10][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmRadial[10][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2] + FmTangential[10][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2] - a[10][2]*FmTangential[10][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1]) - c[1]*FmTangential[10][2] + a[10][1]*FmTangential[10][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2] + a[10][2]*FmTangential[10][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0]) + c[0]*FmTangential[10][2] - a[10][0]*FmTangential[10][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1] - a[10][1]*FmTangential[10][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0]) - c[0]*FmTangential[10][1] + a[10][0]*FmTangential[10][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            a1[10][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[10][0] + theta[2]*a[10][1] - theta1[2]*a[10][1] - theta[1]*a[10][2] + theta1[1]*a[10][2];

            a1[10][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[10][0] + theta1[2]*a[10][0] + a[10][1] + theta[0]*a[10][2] - theta1[0]*a[10][2];

            a1[10][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[10][0] - theta1[1]*a[10][0] - theta[0]*a[10][1] + theta1[0]*a[10][1] + a[10][2];

            break;

        case 21:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmRadial[10][0] + FmRadial[11][0] + FmRadial[12][0] + FmRadial[13][0] + FmRadial[14][0] + FmRadial[15][0] + FmRadial[16][0] + FmRadial[17][0] + FmRadial[18][0] + FmRadial[19][0] + FmRadial[20][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmRadial[10][1] + FmRadial[11][1] + FmRadial[12][1] + FmRadial[13][1] + FmRadial[14][1] + FmRadial[15][1] + FmRadial[16][1] + FmRadial[17][1] + FmRadial[18][1] + FmRadial[19][1] + FmRadial[20][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1] + FmTangential[19][1] + FmTangential[20][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmRadial[10][2] + FmRadial[11][2] + FmRadial[12][2] + FmRadial[13][2] + FmRadial[14][2] + FmRadial[15][2] + FmRadial[16][2] + FmRadial[17][2] + FmRadial[18][2] + FmRadial[19][2] + FmRadial[20][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2] + FmTangential[10][2] + FmTangential[11][2] + FmTangential[12][2] + FmTangential[13][2] + FmTangential[14][2] + FmTangential[15][2] + FmTangential[16][2] + FmTangential[17][2] + FmTangential[18][2] + FmTangential[19][2] + FmTangential[20][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2] - a[10][2]*FmTangential[10][1] - c[1]*FmTangential[10][2] + a[10][1]*FmTangential[10][2] - a[11][2]*FmTangential[11][1] - c[1]*FmTangential[11][2] + a[11][1]*FmTangential[11][2] - a[12][2]*FmTangential[12][1] - c[1]*FmTangential[12][2] + a[12][1]*FmTangential[12][2] - a[13][2]*FmTangential[13][1] - c[1]*FmTangential[13][2] + a[13][1]*FmTangential[13][2] - a[14][2]*FmTangential[14][1] - c[1]*FmTangential[14][2] + a[14][1]*FmTangential[14][2] - a[15][2]*FmTangential[15][1] - c[1]*FmTangential[15][2] + a[15][1]*FmTangential[15][2] - a[16][2]*FmTangential[16][1] - c[1]*FmTangential[16][2] + a[16][1]*FmTangential[16][2] - a[17][2]*FmTangential[17][1] - c[1]*FmTangential[17][2] + a[17][1]*FmTangential[17][2] - a[18][2]*FmTangential[18][1] - c[1]*FmTangential[18][2] + a[18][1]*FmTangential[18][2] - a[19][2]*FmTangential[19][1] - c[1]*FmTangential[19][2] + a[19][1]*FmTangential[19][2] - a[20][2]*FmTangential[20][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1] + FmTangential[19][1] + FmTangential[20][1]) - c[1]*FmTangential[20][2] + a[20][1]*FmTangential[20][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2] + a[10][2]*FmTangential[10][0] + c[0]*FmTangential[10][2] - a[10][0]*FmTangential[10][2] + a[11][2]*FmTangential[11][0] + c[0]*FmTangential[11][2] - a[11][0]*FmTangential[11][2] + a[12][2]*FmTangential[12][0] + c[0]*FmTangential[12][2] - a[12][0]*FmTangential[12][2] + a[13][2]*FmTangential[13][0] + c[0]*FmTangential[13][2] - a[13][0]*FmTangential[13][2] + a[14][2]*FmTangential[14][0] + c[0]*FmTangential[14][2] - a[14][0]*FmTangential[14][2] + a[15][2]*FmTangential[15][0] + c[0]*FmTangential[15][2] - a[15][0]*FmTangential[15][2] + a[16][2]*FmTangential[16][0] + c[0]*FmTangential[16][2] - a[16][0]*FmTangential[16][2] + a[17][2]*FmTangential[17][0] + c[0]*FmTangential[17][2] - a[17][0]*FmTangential[17][2] + a[18][2]*FmTangential[18][0] + c[0]*FmTangential[18][2] - a[18][0]*FmTangential[18][2] + a[19][2]*FmTangential[19][0] + c[0]*FmTangential[19][2] - a[19][0]*FmTangential[19][2] + a[20][2]*FmTangential[20][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0]) + c[0]*FmTangential[20][2] - a[20][0]*FmTangential[20][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1] - a[10][1]*FmTangential[10][0] - c[0]*FmTangential[10][1] + a[10][0]*FmTangential[10][1] - a[11][1]*FmTangential[11][0] - c[0]*FmTangential[11][1] + a[11][0]*FmTangential[11][1] - a[12][1]*FmTangential[12][0] - c[0]*FmTangential[12][1] + a[12][0]*FmTangential[12][1] - a[13][1]*FmTangential[13][0] - c[0]*FmTangential[13][1] + a[13][0]*FmTangential[13][1] - a[14][1]*FmTangential[14][0] - c[0]*FmTangential[14][1] + a[14][0]*FmTangential[14][1] - a[15][1]*FmTangential[15][0] - c[0]*FmTangential[15][1] + a[15][0]*FmTangential[15][1] - a[16][1]*FmTangential[16][0] - c[0]*FmTangential[16][1] + a[16][0]*FmTangential[16][1] - a[17][1]*FmTangential[17][0] - c[0]*FmTangential[17][1] + a[17][0]*FmTangential[17][1] - a[18][1]*FmTangential[18][0] - c[0]*FmTangential[18][1] + a[18][0]*FmTangential[18][1] - a[19][1]*FmTangential[19][0] - c[0]*FmTangential[19][1] + a[19][0]*FmTangential[19][1] - a[20][1]*FmTangential[20][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0]) - c[0]*FmTangential[20][1] + a[20][0]*FmTangential[20][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            a1[10][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[10][0] + theta[2]*a[10][1] - theta1[2]*a[10][1] - theta[1]*a[10][2] + theta1[1]*a[10][2];

            a1[10][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[10][0] + theta1[2]*a[10][0] + a[10][1] + theta[0]*a[10][2] - theta1[0]*a[10][2];

            a1[10][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[10][0] - theta1[1]*a[10][0] - theta[0]*a[10][1] + theta1[0]*a[10][1] + a[10][2];

            a1[11][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[11][0] + theta[2]*a[11][1] - theta1[2]*a[11][1] - theta[1]*a[11][2] + theta1[1]*a[11][2];

            a1[11][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[11][0] + theta1[2]*a[11][0] + a[11][1] + theta[0]*a[11][2] - theta1[0]*a[11][2];

            a1[11][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[11][0] - theta1[1]*a[11][0] - theta[0]*a[11][1] + theta1[0]*a[11][1] + a[11][2];

            a1[12][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[12][0] + theta[2]*a[12][1] - theta1[2]*a[12][1] - theta[1]*a[12][2] + theta1[1]*a[12][2];

            a1[12][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[12][0] + theta1[2]*a[12][0] + a[12][1] + theta[0]*a[12][2] - theta1[0]*a[12][2];

            a1[12][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[12][0] - theta1[1]*a[12][0] - theta[0]*a[12][1] + theta1[0]*a[12][1] + a[12][2];

            a1[13][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[13][0] + theta[2]*a[13][1] - theta1[2]*a[13][1] - theta[1]*a[13][2] + theta1[1]*a[13][2];

            a1[13][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[13][0] + theta1[2]*a[13][0] + a[13][1] + theta[0]*a[13][2] - theta1[0]*a[13][2];

            a1[13][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[13][0] - theta1[1]*a[13][0] - theta[0]*a[13][1] + theta1[0]*a[13][1] + a[13][2];

            a1[14][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[14][0] + theta[2]*a[14][1] - theta1[2]*a[14][1] - theta[1]*a[14][2] + theta1[1]*a[14][2];

            a1[14][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[14][0] + theta1[2]*a[14][0] + a[14][1] + theta[0]*a[14][2] - theta1[0]*a[14][2];

            a1[14][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[14][0] - theta1[1]*a[14][0] - theta[0]*a[14][1] + theta1[0]*a[14][1] + a[14][2];

            a1[15][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[15][0] + theta[2]*a[15][1] - theta1[2]*a[15][1] - theta[1]*a[15][2] + theta1[1]*a[15][2];

            a1[15][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[15][0] + theta1[2]*a[15][0] + a[15][1] + theta[0]*a[15][2] - theta1[0]*a[15][2];

            a1[15][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[15][0] - theta1[1]*a[15][0] - theta[0]*a[15][1] + theta1[0]*a[15][1] + a[15][2];

            a1[16][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[16][0] + theta[2]*a[16][1] - theta1[2]*a[16][1] - theta[1]*a[16][2] + theta1[1]*a[16][2];

            a1[16][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[16][0] + theta1[2]*a[16][0] + a[16][1] + theta[0]*a[16][2] - theta1[0]*a[16][2];

            a1[16][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[16][0] - theta1[1]*a[16][0] - theta[0]*a[16][1] + theta1[0]*a[16][1] + a[16][2];

            a1[17][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[17][0] + theta[2]*a[17][1] - theta1[2]*a[17][1] - theta[1]*a[17][2] + theta1[1]*a[17][2];

            a1[17][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[17][0] + theta1[2]*a[17][0] + a[17][1] + theta[0]*a[17][2] - theta1[0]*a[17][2];

            a1[17][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[17][0] - theta1[1]*a[17][0] - theta[0]*a[17][1] + theta1[0]*a[17][1] + a[17][2];

            a1[18][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[18][0] + theta[2]*a[18][1] - theta1[2]*a[18][1] - theta[1]*a[18][2] + theta1[1]*a[18][2];

            a1[18][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[18][0] + theta1[2]*a[18][0] + a[18][1] + theta[0]*a[18][2] - theta1[0]*a[18][2];

            a1[18][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[18][0] - theta1[1]*a[18][0] - theta[0]*a[18][1] + theta1[0]*a[18][1] + a[18][2];

            a1[19][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[19][0] + theta[2]*a[19][1] - theta1[2]*a[19][1] - theta[1]*a[19][2] + theta1[1]*a[19][2];

            a1[19][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[19][0] + theta1[2]*a[19][0] + a[19][1] + theta[0]*a[19][2] - theta1[0]*a[19][2];

            a1[19][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[19][0] - theta1[1]*a[19][0] - theta[0]*a[19][1] + theta1[0]*a[19][1] + a[19][2];

            a1[20][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[20][0] + theta[2]*a[20][1] - theta1[2]*a[20][1] - theta[1]*a[20][2] + theta1[1]*a[20][2];

            a1[20][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[20][0] + theta1[2]*a[20][0] + a[20][1] + theta[0]*a[20][2] - theta1[0]*a[20][2];

            a1[20][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[20][0] - theta1[1]*a[20][0] - theta[0]*a[20][1] + theta1[0]*a[20][1] + a[20][2];

            break;

        case 31:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmRadial[10][0] + FmRadial[11][0] + FmRadial[12][0] + FmRadial[13][0] + FmRadial[14][0] + FmRadial[15][0] + FmRadial[16][0] + FmRadial[17][0] + FmRadial[18][0] + FmRadial[19][0] + FmRadial[20][0] + FmRadial[21][0] + FmRadial[22][0] + FmRadial[23][0] + FmRadial[24][0] + FmRadial[25][0] + FmRadial[26][0] + FmRadial[27][0] + FmRadial[28][0] + FmRadial[29][0] + FmRadial[30][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmRadial[10][1] + FmRadial[11][1] + FmRadial[12][1] + FmRadial[13][1] + FmRadial[14][1] + FmRadial[15][1] + FmRadial[16][1] + FmRadial[17][1] + FmRadial[18][1] + FmRadial[19][1] + FmRadial[20][1] + FmRadial[21][1] + FmRadial[22][1] + FmRadial[23][1] + FmRadial[24][1] + FmRadial[25][1] + FmRadial[26][1] + FmRadial[27][1] + FmRadial[28][1] + FmRadial[29][1] + FmRadial[30][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1] + FmTangential[19][1] + FmTangential[20][1] + FmTangential[21][1] + FmTangential[22][1] + FmTangential[23][1] + FmTangential[24][1] + FmTangential[25][1] + FmTangential[26][1] + FmTangential[27][1] + FmTangential[28][1] + FmTangential[29][1] + FmTangential[30][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmRadial[10][2] + FmRadial[11][2] + FmRadial[12][2] + FmRadial[13][2] + FmRadial[14][2] + FmRadial[15][2] + FmRadial[16][2] + FmRadial[17][2] + FmRadial[18][2] + FmRadial[19][2] + FmRadial[20][2] + FmRadial[21][2] + FmRadial[22][2] + FmRadial[23][2] + FmRadial[24][2] + FmRadial[25][2] + FmRadial[26][2] + FmRadial[27][2] + FmRadial[28][2] + FmRadial[29][2] + FmRadial[30][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2] + FmTangential[10][2] + FmTangential[11][2] + FmTangential[12][2] + FmTangential[13][2] + FmTangential[14][2] + FmTangential[15][2] + FmTangential[16][2] + FmTangential[17][2] + FmTangential[18][2] + FmTangential[19][2] + FmTangential[20][2] + FmTangential[21][2] + FmTangential[22][2] + FmTangential[23][2] + FmTangential[24][2] + FmTangential[25][2] + FmTangential[26][2] + FmTangential[27][2] + FmTangential[28][2] + FmTangential[29][2] + FmTangential[30][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2] - a[10][2]*FmTangential[10][1] - c[1]*FmTangential[10][2] + a[10][1]*FmTangential[10][2] - a[11][2]*FmTangential[11][1] - c[1]*FmTangential[11][2] + a[11][1]*FmTangential[11][2] - a[12][2]*FmTangential[12][1] - c[1]*FmTangential[12][2] + a[12][1]*FmTangential[12][2] - a[13][2]*FmTangential[13][1] - c[1]*FmTangential[13][2] + a[13][1]*FmTangential[13][2] - a[14][2]*FmTangential[14][1] - c[1]*FmTangential[14][2] + a[14][1]*FmTangential[14][2] - a[15][2]*FmTangential[15][1] - c[1]*FmTangential[15][2] + a[15][1]*FmTangential[15][2] - a[16][2]*FmTangential[16][1] - c[1]*FmTangential[16][2] + a[16][1]*FmTangential[16][2] - a[17][2]*FmTangential[17][1] - c[1]*FmTangential[17][2] + a[17][1]*FmTangential[17][2] - a[18][2]*FmTangential[18][1] - c[1]*FmTangential[18][2] + a[18][1]*FmTangential[18][2] - a[19][2]*FmTangential[19][1] - c[1]*FmTangential[19][2] + a[19][1]*FmTangential[19][2] - a[20][2]*FmTangential[20][1] - c[1]*FmTangential[20][2] + a[20][1]*FmTangential[20][2] - a[21][2]*FmTangential[21][1] - c[1]*FmTangential[21][2] + a[21][1]*FmTangential[21][2] - a[22][2]*FmTangential[22][1] - c[1]*FmTangential[22][2] + a[22][1]*FmTangential[22][2] - a[23][2]*FmTangential[23][1] - c[1]*FmTangential[23][2] + a[23][1]*FmTangential[23][2] - a[24][2]*FmTangential[24][1] - c[1]*FmTangential[24][2] + a[24][1]*FmTangential[24][2] - a[25][2]*FmTangential[25][1] - c[1]*FmTangential[25][2] + a[25][1]*FmTangential[25][2] - a[26][2]*FmTangential[26][1] - c[1]*FmTangential[26][2] + a[26][1]*FmTangential[26][2] - a[27][2]*FmTangential[27][1] - c[1]*FmTangential[27][2] + a[27][1]*FmTangential[27][2] - a[28][2]*FmTangential[28][1] - c[1]*FmTangential[28][2] + a[28][1]*FmTangential[28][2] - a[29][2]*FmTangential[29][1] - c[1]*FmTangential[29][2] + a[29][1]*FmTangential[29][2] - a[30][2]*FmTangential[30][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1] + FmTangential[19][1] + FmTangential[20][1] + FmTangential[21][1] + FmTangential[22][1] + FmTangential[23][1] + FmTangential[24][1] + FmTangential[25][1] + FmTangential[26][1] + FmTangential[27][1] + FmTangential[28][1] + FmTangential[29][1] + FmTangential[30][1]) - c[1]*FmTangential[30][2] + a[30][1]*FmTangential[30][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2] + a[10][2]*FmTangential[10][0] + c[0]*FmTangential[10][2] - a[10][0]*FmTangential[10][2] + a[11][2]*FmTangential[11][0] + c[0]*FmTangential[11][2] - a[11][0]*FmTangential[11][2] + a[12][2]*FmTangential[12][0] + c[0]*FmTangential[12][2] - a[12][0]*FmTangential[12][2] + a[13][2]*FmTangential[13][0] + c[0]*FmTangential[13][2] - a[13][0]*FmTangential[13][2] + a[14][2]*FmTangential[14][0] + c[0]*FmTangential[14][2] - a[14][0]*FmTangential[14][2] + a[15][2]*FmTangential[15][0] + c[0]*FmTangential[15][2] - a[15][0]*FmTangential[15][2] + a[16][2]*FmTangential[16][0] + c[0]*FmTangential[16][2] - a[16][0]*FmTangential[16][2] + a[17][2]*FmTangential[17][0] + c[0]*FmTangential[17][2] - a[17][0]*FmTangential[17][2] + a[18][2]*FmTangential[18][0] + c[0]*FmTangential[18][2] - a[18][0]*FmTangential[18][2] + a[19][2]*FmTangential[19][0] + c[0]*FmTangential[19][2] - a[19][0]*FmTangential[19][2] + a[20][2]*FmTangential[20][0] + c[0]*FmTangential[20][2] - a[20][0]*FmTangential[20][2] + a[21][2]*FmTangential[21][0] + c[0]*FmTangential[21][2] - a[21][0]*FmTangential[21][2] + a[22][2]*FmTangential[22][0] + c[0]*FmTangential[22][2] - a[22][0]*FmTangential[22][2] + a[23][2]*FmTangential[23][0] + c[0]*FmTangential[23][2] - a[23][0]*FmTangential[23][2] + a[24][2]*FmTangential[24][0] + c[0]*FmTangential[24][2] - a[24][0]*FmTangential[24][2] + a[25][2]*FmTangential[25][0] + c[0]*FmTangential[25][2] - a[25][0]*FmTangential[25][2] + a[26][2]*FmTangential[26][0] + c[0]*FmTangential[26][2] - a[26][0]*FmTangential[26][2] + a[27][2]*FmTangential[27][0] + c[0]*FmTangential[27][2] - a[27][0]*FmTangential[27][2] + a[28][2]*FmTangential[28][0] + c[0]*FmTangential[28][2] - a[28][0]*FmTangential[28][2] + a[29][2]*FmTangential[29][0] + c[0]*FmTangential[29][2] - a[29][0]*FmTangential[29][2] + a[30][2]*FmTangential[30][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0]) + c[0]*FmTangential[30][2] - a[30][0]*FmTangential[30][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1] - a[10][1]*FmTangential[10][0] - c[0]*FmTangential[10][1] + a[10][0]*FmTangential[10][1] - a[11][1]*FmTangential[11][0] - c[0]*FmTangential[11][1] + a[11][0]*FmTangential[11][1] - a[12][1]*FmTangential[12][0] - c[0]*FmTangential[12][1] + a[12][0]*FmTangential[12][1] - a[13][1]*FmTangential[13][0] - c[0]*FmTangential[13][1] + a[13][0]*FmTangential[13][1] - a[14][1]*FmTangential[14][0] - c[0]*FmTangential[14][1] + a[14][0]*FmTangential[14][1] - a[15][1]*FmTangential[15][0] - c[0]*FmTangential[15][1] + a[15][0]*FmTangential[15][1] - a[16][1]*FmTangential[16][0] - c[0]*FmTangential[16][1] + a[16][0]*FmTangential[16][1] - a[17][1]*FmTangential[17][0] - c[0]*FmTangential[17][1] + a[17][0]*FmTangential[17][1] - a[18][1]*FmTangential[18][0] - c[0]*FmTangential[18][1] + a[18][0]*FmTangential[18][1] - a[19][1]*FmTangential[19][0] - c[0]*FmTangential[19][1] + a[19][0]*FmTangential[19][1] - a[20][1]*FmTangential[20][0] - c[0]*FmTangential[20][1] + a[20][0]*FmTangential[20][1] - a[21][1]*FmTangential[21][0] - c[0]*FmTangential[21][1] + a[21][0]*FmTangential[21][1] - a[22][1]*FmTangential[22][0] - c[0]*FmTangential[22][1] + a[22][0]*FmTangential[22][1] - a[23][1]*FmTangential[23][0] - c[0]*FmTangential[23][1] + a[23][0]*FmTangential[23][1] - a[24][1]*FmTangential[24][0] - c[0]*FmTangential[24][1] + a[24][0]*FmTangential[24][1] - a[25][1]*FmTangential[25][0] - c[0]*FmTangential[25][1] + a[25][0]*FmTangential[25][1] - a[26][1]*FmTangential[26][0] - c[0]*FmTangential[26][1] + a[26][0]*FmTangential[26][1] - a[27][1]*FmTangential[27][0] - c[0]*FmTangential[27][1] + a[27][0]*FmTangential[27][1] - a[28][1]*FmTangential[28][0] - c[0]*FmTangential[28][1] + a[28][0]*FmTangential[28][1] - a[29][1]*FmTangential[29][0] - c[0]*FmTangential[29][1] + a[29][0]*FmTangential[29][1] - a[30][1]*FmTangential[30][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0]) - c[0]*FmTangential[30][1] + a[30][0]*FmTangential[30][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            a1[10][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[10][0] + theta[2]*a[10][1] - theta1[2]*a[10][1] - theta[1]*a[10][2] + theta1[1]*a[10][2];

            a1[10][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[10][0] + theta1[2]*a[10][0] + a[10][1] + theta[0]*a[10][2] - theta1[0]*a[10][2];

            a1[10][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[10][0] - theta1[1]*a[10][0] - theta[0]*a[10][1] + theta1[0]*a[10][1] + a[10][2];

            a1[11][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[11][0] + theta[2]*a[11][1] - theta1[2]*a[11][1] - theta[1]*a[11][2] + theta1[1]*a[11][2];

            a1[11][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[11][0] + theta1[2]*a[11][0] + a[11][1] + theta[0]*a[11][2] - theta1[0]*a[11][2];

            a1[11][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[11][0] - theta1[1]*a[11][0] - theta[0]*a[11][1] + theta1[0]*a[11][1] + a[11][2];

            a1[12][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[12][0] + theta[2]*a[12][1] - theta1[2]*a[12][1] - theta[1]*a[12][2] + theta1[1]*a[12][2];

            a1[12][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[12][0] + theta1[2]*a[12][0] + a[12][1] + theta[0]*a[12][2] - theta1[0]*a[12][2];

            a1[12][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[12][0] - theta1[1]*a[12][0] - theta[0]*a[12][1] + theta1[0]*a[12][1] + a[12][2];

            a1[13][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[13][0] + theta[2]*a[13][1] - theta1[2]*a[13][1] - theta[1]*a[13][2] + theta1[1]*a[13][2];

            a1[13][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[13][0] + theta1[2]*a[13][0] + a[13][1] + theta[0]*a[13][2] - theta1[0]*a[13][2];

            a1[13][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[13][0] - theta1[1]*a[13][0] - theta[0]*a[13][1] + theta1[0]*a[13][1] + a[13][2];

            a1[14][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[14][0] + theta[2]*a[14][1] - theta1[2]*a[14][1] - theta[1]*a[14][2] + theta1[1]*a[14][2];

            a1[14][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[14][0] + theta1[2]*a[14][0] + a[14][1] + theta[0]*a[14][2] - theta1[0]*a[14][2];

            a1[14][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[14][0] - theta1[1]*a[14][0] - theta[0]*a[14][1] + theta1[0]*a[14][1] + a[14][2];

            a1[15][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[15][0] + theta[2]*a[15][1] - theta1[2]*a[15][1] - theta[1]*a[15][2] + theta1[1]*a[15][2];

            a1[15][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[15][0] + theta1[2]*a[15][0] + a[15][1] + theta[0]*a[15][2] - theta1[0]*a[15][2];

            a1[15][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[15][0] - theta1[1]*a[15][0] - theta[0]*a[15][1] + theta1[0]*a[15][1] + a[15][2];

            a1[16][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[16][0] + theta[2]*a[16][1] - theta1[2]*a[16][1] - theta[1]*a[16][2] + theta1[1]*a[16][2];

            a1[16][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[16][0] + theta1[2]*a[16][0] + a[16][1] + theta[0]*a[16][2] - theta1[0]*a[16][2];

            a1[16][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[16][0] - theta1[1]*a[16][0] - theta[0]*a[16][1] + theta1[0]*a[16][1] + a[16][2];

            a1[17][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[17][0] + theta[2]*a[17][1] - theta1[2]*a[17][1] - theta[1]*a[17][2] + theta1[1]*a[17][2];

            a1[17][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[17][0] + theta1[2]*a[17][0] + a[17][1] + theta[0]*a[17][2] - theta1[0]*a[17][2];

            a1[17][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[17][0] - theta1[1]*a[17][0] - theta[0]*a[17][1] + theta1[0]*a[17][1] + a[17][2];

            a1[18][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[18][0] + theta[2]*a[18][1] - theta1[2]*a[18][1] - theta[1]*a[18][2] + theta1[1]*a[18][2];

            a1[18][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[18][0] + theta1[2]*a[18][0] + a[18][1] + theta[0]*a[18][2] - theta1[0]*a[18][2];

            a1[18][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[18][0] - theta1[1]*a[18][0] - theta[0]*a[18][1] + theta1[0]*a[18][1] + a[18][2];

            a1[19][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[19][0] + theta[2]*a[19][1] - theta1[2]*a[19][1] - theta[1]*a[19][2] + theta1[1]*a[19][2];

            a1[19][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[19][0] + theta1[2]*a[19][0] + a[19][1] + theta[0]*a[19][2] - theta1[0]*a[19][2];

            a1[19][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[19][0] - theta1[1]*a[19][0] - theta[0]*a[19][1] + theta1[0]*a[19][1] + a[19][2];

            a1[20][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[20][0] + theta[2]*a[20][1] - theta1[2]*a[20][1] - theta[1]*a[20][2] + theta1[1]*a[20][2];

            a1[20][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[20][0] + theta1[2]*a[20][0] + a[20][1] + theta[0]*a[20][2] - theta1[0]*a[20][2];

            a1[20][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[20][0] - theta1[1]*a[20][0] - theta[0]*a[20][1] + theta1[0]*a[20][1] + a[20][2];

            a1[21][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[21][0] + theta[2]*a[21][1] - theta1[2]*a[21][1] - theta[1]*a[21][2] + theta1[1]*a[21][2];

            a1[21][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[21][0] + theta1[2]*a[21][0] + a[21][1] + theta[0]*a[21][2] - theta1[0]*a[21][2];

            a1[21][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[21][0] - theta1[1]*a[21][0] - theta[0]*a[21][1] + theta1[0]*a[21][1] + a[21][2];

            a1[22][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[22][0] + theta[2]*a[22][1] - theta1[2]*a[22][1] - theta[1]*a[22][2] + theta1[1]*a[22][2];

            a1[22][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[22][0] + theta1[2]*a[22][0] + a[22][1] + theta[0]*a[22][2] - theta1[0]*a[22][2];

            a1[22][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[22][0] - theta1[1]*a[22][0] - theta[0]*a[22][1] + theta1[0]*a[22][1] + a[22][2];

            a1[23][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[23][0] + theta[2]*a[23][1] - theta1[2]*a[23][1] - theta[1]*a[23][2] + theta1[1]*a[23][2];

            a1[23][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[23][0] + theta1[2]*a[23][0] + a[23][1] + theta[0]*a[23][2] - theta1[0]*a[23][2];

            a1[23][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[23][0] - theta1[1]*a[23][0] - theta[0]*a[23][1] + theta1[0]*a[23][1] + a[23][2];

            a1[24][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[24][0] + theta[2]*a[24][1] - theta1[2]*a[24][1] - theta[1]*a[24][2] + theta1[1]*a[24][2];

            a1[24][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[24][0] + theta1[2]*a[24][0] + a[24][1] + theta[0]*a[24][2] - theta1[0]*a[24][2];

            a1[24][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[24][0] - theta1[1]*a[24][0] - theta[0]*a[24][1] + theta1[0]*a[24][1] + a[24][2];

            a1[25][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[25][0] + theta[2]*a[25][1] - theta1[2]*a[25][1] - theta[1]*a[25][2] + theta1[1]*a[25][2];

            a1[25][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[25][0] + theta1[2]*a[25][0] + a[25][1] + theta[0]*a[25][2] - theta1[0]*a[25][2];

            a1[25][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[25][0] - theta1[1]*a[25][0] - theta[0]*a[25][1] + theta1[0]*a[25][1] + a[25][2];

            a1[26][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[26][0] + theta[2]*a[26][1] - theta1[2]*a[26][1] - theta[1]*a[26][2] + theta1[1]*a[26][2];

            a1[26][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[26][0] + theta1[2]*a[26][0] + a[26][1] + theta[0]*a[26][2] - theta1[0]*a[26][2];

            a1[26][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[26][0] - theta1[1]*a[26][0] - theta[0]*a[26][1] + theta1[0]*a[26][1] + a[26][2];

            a1[27][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[27][0] + theta[2]*a[27][1] - theta1[2]*a[27][1] - theta[1]*a[27][2] + theta1[1]*a[27][2];

            a1[27][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[27][0] + theta1[2]*a[27][0] + a[27][1] + theta[0]*a[27][2] - theta1[0]*a[27][2];

            a1[27][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[27][0] - theta1[1]*a[27][0] - theta[0]*a[27][1] + theta1[0]*a[27][1] + a[27][2];

            a1[28][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[28][0] + theta[2]*a[28][1] - theta1[2]*a[28][1] - theta[1]*a[28][2] + theta1[1]*a[28][2];

            a1[28][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[28][0] + theta1[2]*a[28][0] + a[28][1] + theta[0]*a[28][2] - theta1[0]*a[28][2];

            a1[28][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[28][0] - theta1[1]*a[28][0] - theta[0]*a[28][1] + theta1[0]*a[28][1] + a[28][2];

            a1[29][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[29][0] + theta[2]*a[29][1] - theta1[2]*a[29][1] - theta[1]*a[29][2] + theta1[1]*a[29][2];

            a1[29][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[29][0] + theta1[2]*a[29][0] + a[29][1] + theta[0]*a[29][2] - theta1[0]*a[29][2];

            a1[29][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[29][0] - theta1[1]*a[29][0] - theta[0]*a[29][1] + theta1[0]*a[29][1] + a[29][2];

            a1[30][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[30][0] + theta[2]*a[30][1] - theta1[2]*a[30][1] - theta[1]*a[30][2] + theta1[1]*a[30][2];

            a1[30][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[30][0] + theta1[2]*a[30][0] + a[30][1] + theta[0]*a[30][2] - theta1[0]*a[30][2];

            a1[30][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[30][0] - theta1[1]*a[30][0] - theta[0]*a[30][1] + theta1[0]*a[30][1] + a[30][2];

            break;

        case 41:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmRadial[10][0] + FmRadial[11][0] + FmRadial[12][0] + FmRadial[13][0] + FmRadial[14][0] + FmRadial[15][0] + FmRadial[16][0] + FmRadial[17][0] + FmRadial[18][0] + FmRadial[19][0] + FmRadial[20][0] + FmRadial[21][0] + FmRadial[22][0] + FmRadial[23][0] + FmRadial[24][0] + FmRadial[25][0] + FmRadial[26][0] + FmRadial[27][0] + FmRadial[28][0] + FmRadial[29][0] + FmRadial[30][0] + FmRadial[31][0] + FmRadial[32][0] + FmRadial[33][0] + FmRadial[34][0] + FmRadial[35][0] + FmRadial[36][0] + FmRadial[37][0] + FmRadial[38][0] + FmRadial[39][0] + FmRadial[40][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmRadial[10][1] + FmRadial[11][1] + FmRadial[12][1] + FmRadial[13][1] + FmRadial[14][1] + FmRadial[15][1] + FmRadial[16][1] + FmRadial[17][1] + FmRadial[18][1] + FmRadial[19][1] + FmRadial[20][1] + FmRadial[21][1] + FmRadial[22][1] + FmRadial[23][1] + FmRadial[24][1] + FmRadial[25][1] + FmRadial[26][1] + FmRadial[27][1] + FmRadial[28][1] + FmRadial[29][1] + FmRadial[30][1] + FmRadial[31][1] + FmRadial[32][1] + FmRadial[33][1] + FmRadial[34][1] + FmRadial[35][1] + FmRadial[36][1] + FmRadial[37][1] + FmRadial[38][1] + FmRadial[39][1] + FmRadial[40][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1] + FmTangential[19][1] + FmTangential[20][1] + FmTangential[21][1] + FmTangential[22][1] + FmTangential[23][1] + FmTangential[24][1] + FmTangential[25][1] + FmTangential[26][1] + FmTangential[27][1] + FmTangential[28][1] + FmTangential[29][1] + FmTangential[30][1] + FmTangential[31][1] + FmTangential[32][1] + FmTangential[33][1] + FmTangential[34][1] + FmTangential[35][1] + FmTangential[36][1] + FmTangential[37][1] + FmTangential[38][1] + FmTangential[39][1] + FmTangential[40][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmRadial[10][2] + FmRadial[11][2] + FmRadial[12][2] + FmRadial[13][2] + FmRadial[14][2] + FmRadial[15][2] + FmRadial[16][2] + FmRadial[17][2] + FmRadial[18][2] + FmRadial[19][2] + FmRadial[20][2] + FmRadial[21][2] + FmRadial[22][2] + FmRadial[23][2] + FmRadial[24][2] + FmRadial[25][2] + FmRadial[26][2] + FmRadial[27][2] + FmRadial[28][2] + FmRadial[29][2] + FmRadial[30][2] + FmRadial[31][2] + FmRadial[32][2] + FmRadial[33][2] + FmRadial[34][2] + FmRadial[35][2] + FmRadial[36][2] + FmRadial[37][2] + FmRadial[38][2] + FmRadial[39][2] + FmRadial[40][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2] + FmTangential[10][2] + FmTangential[11][2] + FmTangential[12][2] + FmTangential[13][2] + FmTangential[14][2] + FmTangential[15][2] + FmTangential[16][2] + FmTangential[17][2] + FmTangential[18][2] + FmTangential[19][2] + FmTangential[20][2] + FmTangential[21][2] + FmTangential[22][2] + FmTangential[23][2] + FmTangential[24][2] + FmTangential[25][2] + FmTangential[26][2] + FmTangential[27][2] + FmTangential[28][2] + FmTangential[29][2] + FmTangential[30][2] + FmTangential[31][2] + FmTangential[32][2] + FmTangential[33][2] + FmTangential[34][2] + FmTangential[35][2] + FmTangential[36][2] + FmTangential[37][2] + FmTangential[38][2] + FmTangential[39][2] + FmTangential[40][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2] - a[10][2]*FmTangential[10][1] - c[1]*FmTangential[10][2] + a[10][1]*FmTangential[10][2] - a[11][2]*FmTangential[11][1] - c[1]*FmTangential[11][2] + a[11][1]*FmTangential[11][2] - a[12][2]*FmTangential[12][1] - c[1]*FmTangential[12][2] + a[12][1]*FmTangential[12][2] - a[13][2]*FmTangential[13][1] - c[1]*FmTangential[13][2] + a[13][1]*FmTangential[13][2] - a[14][2]*FmTangential[14][1] - c[1]*FmTangential[14][2] + a[14][1]*FmTangential[14][2] - a[15][2]*FmTangential[15][1] - c[1]*FmTangential[15][2] + a[15][1]*FmTangential[15][2] - a[16][2]*FmTangential[16][1] - c[1]*FmTangential[16][2] + a[16][1]*FmTangential[16][2] - a[17][2]*FmTangential[17][1] - c[1]*FmTangential[17][2] + a[17][1]*FmTangential[17][2] - a[18][2]*FmTangential[18][1] - c[1]*FmTangential[18][2] + a[18][1]*FmTangential[18][2] - a[19][2]*FmTangential[19][1] - c[1]*FmTangential[19][2] + a[19][1]*FmTangential[19][2] - a[20][2]*FmTangential[20][1] - c[1]*FmTangential[20][2] + a[20][1]*FmTangential[20][2] - a[21][2]*FmTangential[21][1] - c[1]*FmTangential[21][2] + a[21][1]*FmTangential[21][2] - a[22][2]*FmTangential[22][1] - c[1]*FmTangential[22][2] + a[22][1]*FmTangential[22][2] - a[23][2]*FmTangential[23][1] - c[1]*FmTangential[23][2] + a[23][1]*FmTangential[23][2] - a[24][2]*FmTangential[24][1] - c[1]*FmTangential[24][2] + a[24][1]*FmTangential[24][2] - a[25][2]*FmTangential[25][1] - c[1]*FmTangential[25][2] + a[25][1]*FmTangential[25][2] - a[26][2]*FmTangential[26][1] - c[1]*FmTangential[26][2] + a[26][1]*FmTangential[26][2] - a[27][2]*FmTangential[27][1] - c[1]*FmTangential[27][2] + a[27][1]*FmTangential[27][2] - a[28][2]*FmTangential[28][1] - c[1]*FmTangential[28][2] + a[28][1]*FmTangential[28][2] - a[29][2]*FmTangential[29][1] - c[1]*FmTangential[29][2] + a[29][1]*FmTangential[29][2] - a[30][2]*FmTangential[30][1] - c[1]*FmTangential[30][2] + a[30][1]*FmTangential[30][2] - a[31][2]*FmTangential[31][1] - c[1]*FmTangential[31][2] + a[31][1]*FmTangential[31][2] - a[32][2]*FmTangential[32][1] - c[1]*FmTangential[32][2] + a[32][1]*FmTangential[32][2] - a[33][2]*FmTangential[33][1] - c[1]*FmTangential[33][2] + a[33][1]*FmTangential[33][2] - a[34][2]*FmTangential[34][1] - c[1]*FmTangential[34][2] + a[34][1]*FmTangential[34][2] - a[35][2]*FmTangential[35][1] - c[1]*FmTangential[35][2] + a[35][1]*FmTangential[35][2] - a[36][2]*FmTangential[36][1] - c[1]*FmTangential[36][2] + a[36][1]*FmTangential[36][2] - a[37][2]*FmTangential[37][1] - c[1]*FmTangential[37][2] + a[37][1]*FmTangential[37][2] - a[38][2]*FmTangential[38][1] - c[1]*FmTangential[38][2] + a[38][1]*FmTangential[38][2] - a[39][2]*FmTangential[39][1] - c[1]*FmTangential[39][2] + a[39][1]*FmTangential[39][2] - a[40][2]*FmTangential[40][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1] + FmTangential[19][1] + FmTangential[20][1] + FmTangential[21][1] + FmTangential[22][1] + FmTangential[23][1] + FmTangential[24][1] + FmTangential[25][1] + FmTangential[26][1] + FmTangential[27][1] + FmTangential[28][1] + FmTangential[29][1] + FmTangential[30][1] + FmTangential[31][1] + FmTangential[32][1] + FmTangential[33][1] + FmTangential[34][1] + FmTangential[35][1] + FmTangential[36][1] + FmTangential[37][1] + FmTangential[38][1] + FmTangential[39][1] + FmTangential[40][1]) - c[1]*FmTangential[40][2] + a[40][1]*FmTangential[40][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2] + a[10][2]*FmTangential[10][0] + c[0]*FmTangential[10][2] - a[10][0]*FmTangential[10][2] + a[11][2]*FmTangential[11][0] + c[0]*FmTangential[11][2] - a[11][0]*FmTangential[11][2] + a[12][2]*FmTangential[12][0] + c[0]*FmTangential[12][2] - a[12][0]*FmTangential[12][2] + a[13][2]*FmTangential[13][0] + c[0]*FmTangential[13][2] - a[13][0]*FmTangential[13][2] + a[14][2]*FmTangential[14][0] + c[0]*FmTangential[14][2] - a[14][0]*FmTangential[14][2] + a[15][2]*FmTangential[15][0] + c[0]*FmTangential[15][2] - a[15][0]*FmTangential[15][2] + a[16][2]*FmTangential[16][0] + c[0]*FmTangential[16][2] - a[16][0]*FmTangential[16][2] + a[17][2]*FmTangential[17][0] + c[0]*FmTangential[17][2] - a[17][0]*FmTangential[17][2] + a[18][2]*FmTangential[18][0] + c[0]*FmTangential[18][2] - a[18][0]*FmTangential[18][2] + a[19][2]*FmTangential[19][0] + c[0]*FmTangential[19][2] - a[19][0]*FmTangential[19][2] + a[20][2]*FmTangential[20][0] + c[0]*FmTangential[20][2] - a[20][0]*FmTangential[20][2] + a[21][2]*FmTangential[21][0] + c[0]*FmTangential[21][2] - a[21][0]*FmTangential[21][2] + a[22][2]*FmTangential[22][0] + c[0]*FmTangential[22][2] - a[22][0]*FmTangential[22][2] + a[23][2]*FmTangential[23][0] + c[0]*FmTangential[23][2] - a[23][0]*FmTangential[23][2] + a[24][2]*FmTangential[24][0] + c[0]*FmTangential[24][2] - a[24][0]*FmTangential[24][2] + a[25][2]*FmTangential[25][0] + c[0]*FmTangential[25][2] - a[25][0]*FmTangential[25][2] + a[26][2]*FmTangential[26][0] + c[0]*FmTangential[26][2] - a[26][0]*FmTangential[26][2] + a[27][2]*FmTangential[27][0] + c[0]*FmTangential[27][2] - a[27][0]*FmTangential[27][2] + a[28][2]*FmTangential[28][0] + c[0]*FmTangential[28][2] - a[28][0]*FmTangential[28][2] + a[29][2]*FmTangential[29][0] + c[0]*FmTangential[29][2] - a[29][0]*FmTangential[29][2] + a[30][2]*FmTangential[30][0] + c[0]*FmTangential[30][2] - a[30][0]*FmTangential[30][2] + a[31][2]*FmTangential[31][0] + c[0]*FmTangential[31][2] - a[31][0]*FmTangential[31][2] + a[32][2]*FmTangential[32][0] + c[0]*FmTangential[32][2] - a[32][0]*FmTangential[32][2] + a[33][2]*FmTangential[33][0] + c[0]*FmTangential[33][2] - a[33][0]*FmTangential[33][2] + a[34][2]*FmTangential[34][0] + c[0]*FmTangential[34][2] - a[34][0]*FmTangential[34][2] + a[35][2]*FmTangential[35][0] + c[0]*FmTangential[35][2] - a[35][0]*FmTangential[35][2] + a[36][2]*FmTangential[36][0] + c[0]*FmTangential[36][2] - a[36][0]*FmTangential[36][2] + a[37][2]*FmTangential[37][0] + c[0]*FmTangential[37][2] - a[37][0]*FmTangential[37][2] + a[38][2]*FmTangential[38][0] + c[0]*FmTangential[38][2] - a[38][0]*FmTangential[38][2] + a[39][2]*FmTangential[39][0] + c[0]*FmTangential[39][2] - a[39][0]*FmTangential[39][2] + a[40][2]*FmTangential[40][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0]) + c[0]*FmTangential[40][2] - a[40][0]*FmTangential[40][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1] - a[10][1]*FmTangential[10][0] - c[0]*FmTangential[10][1] + a[10][0]*FmTangential[10][1] - a[11][1]*FmTangential[11][0] - c[0]*FmTangential[11][1] + a[11][0]*FmTangential[11][1] - a[12][1]*FmTangential[12][0] - c[0]*FmTangential[12][1] + a[12][0]*FmTangential[12][1] - a[13][1]*FmTangential[13][0] - c[0]*FmTangential[13][1] + a[13][0]*FmTangential[13][1] - a[14][1]*FmTangential[14][0] - c[0]*FmTangential[14][1] + a[14][0]*FmTangential[14][1] - a[15][1]*FmTangential[15][0] - c[0]*FmTangential[15][1] + a[15][0]*FmTangential[15][1] - a[16][1]*FmTangential[16][0] - c[0]*FmTangential[16][1] + a[16][0]*FmTangential[16][1] - a[17][1]*FmTangential[17][0] - c[0]*FmTangential[17][1] + a[17][0]*FmTangential[17][1] - a[18][1]*FmTangential[18][0] - c[0]*FmTangential[18][1] + a[18][0]*FmTangential[18][1] - a[19][1]*FmTangential[19][0] - c[0]*FmTangential[19][1] + a[19][0]*FmTangential[19][1] - a[20][1]*FmTangential[20][0] - c[0]*FmTangential[20][1] + a[20][0]*FmTangential[20][1] - a[21][1]*FmTangential[21][0] - c[0]*FmTangential[21][1] + a[21][0]*FmTangential[21][1] - a[22][1]*FmTangential[22][0] - c[0]*FmTangential[22][1] + a[22][0]*FmTangential[22][1] - a[23][1]*FmTangential[23][0] - c[0]*FmTangential[23][1] + a[23][0]*FmTangential[23][1] - a[24][1]*FmTangential[24][0] - c[0]*FmTangential[24][1] + a[24][0]*FmTangential[24][1] - a[25][1]*FmTangential[25][0] - c[0]*FmTangential[25][1] + a[25][0]*FmTangential[25][1] - a[26][1]*FmTangential[26][0] - c[0]*FmTangential[26][1] + a[26][0]*FmTangential[26][1] - a[27][1]*FmTangential[27][0] - c[0]*FmTangential[27][1] + a[27][0]*FmTangential[27][1] - a[28][1]*FmTangential[28][0] - c[0]*FmTangential[28][1] + a[28][0]*FmTangential[28][1] - a[29][1]*FmTangential[29][0] - c[0]*FmTangential[29][1] + a[29][0]*FmTangential[29][1] - a[30][1]*FmTangential[30][0] - c[0]*FmTangential[30][1] + a[30][0]*FmTangential[30][1] - a[31][1]*FmTangential[31][0] - c[0]*FmTangential[31][1] + a[31][0]*FmTangential[31][1] - a[32][1]*FmTangential[32][0] - c[0]*FmTangential[32][1] + a[32][0]*FmTangential[32][1] - a[33][1]*FmTangential[33][0] - c[0]*FmTangential[33][1] + a[33][0]*FmTangential[33][1] - a[34][1]*FmTangential[34][0] - c[0]*FmTangential[34][1] + a[34][0]*FmTangential[34][1] - a[35][1]*FmTangential[35][0] - c[0]*FmTangential[35][1] + a[35][0]*FmTangential[35][1] - a[36][1]*FmTangential[36][0] - c[0]*FmTangential[36][1] + a[36][0]*FmTangential[36][1] - a[37][1]*FmTangential[37][0] - c[0]*FmTangential[37][1] + a[37][0]*FmTangential[37][1] - a[38][1]*FmTangential[38][0] - c[0]*FmTangential[38][1] + a[38][0]*FmTangential[38][1] - a[39][1]*FmTangential[39][0] - c[0]*FmTangential[39][1] + a[39][0]*FmTangential[39][1] - a[40][1]*FmTangential[40][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0]) - c[0]*FmTangential[40][1] + a[40][0]*FmTangential[40][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            a1[10][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[10][0] + theta[2]*a[10][1] - theta1[2]*a[10][1] - theta[1]*a[10][2] + theta1[1]*a[10][2];

            a1[10][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[10][0] + theta1[2]*a[10][0] + a[10][1] + theta[0]*a[10][2] - theta1[0]*a[10][2];

            a1[10][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[10][0] - theta1[1]*a[10][0] - theta[0]*a[10][1] + theta1[0]*a[10][1] + a[10][2];

            a1[11][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[11][0] + theta[2]*a[11][1] - theta1[2]*a[11][1] - theta[1]*a[11][2] + theta1[1]*a[11][2];

            a1[11][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[11][0] + theta1[2]*a[11][0] + a[11][1] + theta[0]*a[11][2] - theta1[0]*a[11][2];

            a1[11][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[11][0] - theta1[1]*a[11][0] - theta[0]*a[11][1] + theta1[0]*a[11][1] + a[11][2];

            a1[12][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[12][0] + theta[2]*a[12][1] - theta1[2]*a[12][1] - theta[1]*a[12][2] + theta1[1]*a[12][2];

            a1[12][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[12][0] + theta1[2]*a[12][0] + a[12][1] + theta[0]*a[12][2] - theta1[0]*a[12][2];

            a1[12][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[12][0] - theta1[1]*a[12][0] - theta[0]*a[12][1] + theta1[0]*a[12][1] + a[12][2];

            a1[13][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[13][0] + theta[2]*a[13][1] - theta1[2]*a[13][1] - theta[1]*a[13][2] + theta1[1]*a[13][2];

            a1[13][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[13][0] + theta1[2]*a[13][0] + a[13][1] + theta[0]*a[13][2] - theta1[0]*a[13][2];

            a1[13][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[13][0] - theta1[1]*a[13][0] - theta[0]*a[13][1] + theta1[0]*a[13][1] + a[13][2];

            a1[14][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[14][0] + theta[2]*a[14][1] - theta1[2]*a[14][1] - theta[1]*a[14][2] + theta1[1]*a[14][2];

            a1[14][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[14][0] + theta1[2]*a[14][0] + a[14][1] + theta[0]*a[14][2] - theta1[0]*a[14][2];

            a1[14][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[14][0] - theta1[1]*a[14][0] - theta[0]*a[14][1] + theta1[0]*a[14][1] + a[14][2];

            a1[15][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[15][0] + theta[2]*a[15][1] - theta1[2]*a[15][1] - theta[1]*a[15][2] + theta1[1]*a[15][2];

            a1[15][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[15][0] + theta1[2]*a[15][0] + a[15][1] + theta[0]*a[15][2] - theta1[0]*a[15][2];

            a1[15][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[15][0] - theta1[1]*a[15][0] - theta[0]*a[15][1] + theta1[0]*a[15][1] + a[15][2];

            a1[16][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[16][0] + theta[2]*a[16][1] - theta1[2]*a[16][1] - theta[1]*a[16][2] + theta1[1]*a[16][2];

            a1[16][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[16][0] + theta1[2]*a[16][0] + a[16][1] + theta[0]*a[16][2] - theta1[0]*a[16][2];

            a1[16][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[16][0] - theta1[1]*a[16][0] - theta[0]*a[16][1] + theta1[0]*a[16][1] + a[16][2];

            a1[17][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[17][0] + theta[2]*a[17][1] - theta1[2]*a[17][1] - theta[1]*a[17][2] + theta1[1]*a[17][2];

            a1[17][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[17][0] + theta1[2]*a[17][0] + a[17][1] + theta[0]*a[17][2] - theta1[0]*a[17][2];

            a1[17][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[17][0] - theta1[1]*a[17][0] - theta[0]*a[17][1] + theta1[0]*a[17][1] + a[17][2];

            a1[18][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[18][0] + theta[2]*a[18][1] - theta1[2]*a[18][1] - theta[1]*a[18][2] + theta1[1]*a[18][2];

            a1[18][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[18][0] + theta1[2]*a[18][0] + a[18][1] + theta[0]*a[18][2] - theta1[0]*a[18][2];

            a1[18][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[18][0] - theta1[1]*a[18][0] - theta[0]*a[18][1] + theta1[0]*a[18][1] + a[18][2];

            a1[19][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[19][0] + theta[2]*a[19][1] - theta1[2]*a[19][1] - theta[1]*a[19][2] + theta1[1]*a[19][2];

            a1[19][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[19][0] + theta1[2]*a[19][0] + a[19][1] + theta[0]*a[19][2] - theta1[0]*a[19][2];

            a1[19][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[19][0] - theta1[1]*a[19][0] - theta[0]*a[19][1] + theta1[0]*a[19][1] + a[19][2];

            a1[20][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[20][0] + theta[2]*a[20][1] - theta1[2]*a[20][1] - theta[1]*a[20][2] + theta1[1]*a[20][2];

            a1[20][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[20][0] + theta1[2]*a[20][0] + a[20][1] + theta[0]*a[20][2] - theta1[0]*a[20][2];

            a1[20][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[20][0] - theta1[1]*a[20][0] - theta[0]*a[20][1] + theta1[0]*a[20][1] + a[20][2];

            a1[21][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[21][0] + theta[2]*a[21][1] - theta1[2]*a[21][1] - theta[1]*a[21][2] + theta1[1]*a[21][2];

            a1[21][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[21][0] + theta1[2]*a[21][0] + a[21][1] + theta[0]*a[21][2] - theta1[0]*a[21][2];

            a1[21][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[21][0] - theta1[1]*a[21][0] - theta[0]*a[21][1] + theta1[0]*a[21][1] + a[21][2];

            a1[22][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[22][0] + theta[2]*a[22][1] - theta1[2]*a[22][1] - theta[1]*a[22][2] + theta1[1]*a[22][2];

            a1[22][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[22][0] + theta1[2]*a[22][0] + a[22][1] + theta[0]*a[22][2] - theta1[0]*a[22][2];

            a1[22][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[22][0] - theta1[1]*a[22][0] - theta[0]*a[22][1] + theta1[0]*a[22][1] + a[22][2];

            a1[23][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[23][0] + theta[2]*a[23][1] - theta1[2]*a[23][1] - theta[1]*a[23][2] + theta1[1]*a[23][2];

            a1[23][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[23][0] + theta1[2]*a[23][0] + a[23][1] + theta[0]*a[23][2] - theta1[0]*a[23][2];

            a1[23][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[23][0] - theta1[1]*a[23][0] - theta[0]*a[23][1] + theta1[0]*a[23][1] + a[23][2];

            a1[24][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[24][0] + theta[2]*a[24][1] - theta1[2]*a[24][1] - theta[1]*a[24][2] + theta1[1]*a[24][2];

            a1[24][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[24][0] + theta1[2]*a[24][0] + a[24][1] + theta[0]*a[24][2] - theta1[0]*a[24][2];

            a1[24][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[24][0] - theta1[1]*a[24][0] - theta[0]*a[24][1] + theta1[0]*a[24][1] + a[24][2];

            a1[25][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[25][0] + theta[2]*a[25][1] - theta1[2]*a[25][1] - theta[1]*a[25][2] + theta1[1]*a[25][2];

            a1[25][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[25][0] + theta1[2]*a[25][0] + a[25][1] + theta[0]*a[25][2] - theta1[0]*a[25][2];

            a1[25][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[25][0] - theta1[1]*a[25][0] - theta[0]*a[25][1] + theta1[0]*a[25][1] + a[25][2];

            a1[26][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[26][0] + theta[2]*a[26][1] - theta1[2]*a[26][1] - theta[1]*a[26][2] + theta1[1]*a[26][2];

            a1[26][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[26][0] + theta1[2]*a[26][0] + a[26][1] + theta[0]*a[26][2] - theta1[0]*a[26][2];

            a1[26][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[26][0] - theta1[1]*a[26][0] - theta[0]*a[26][1] + theta1[0]*a[26][1] + a[26][2];

            a1[27][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[27][0] + theta[2]*a[27][1] - theta1[2]*a[27][1] - theta[1]*a[27][2] + theta1[1]*a[27][2];

            a1[27][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[27][0] + theta1[2]*a[27][0] + a[27][1] + theta[0]*a[27][2] - theta1[0]*a[27][2];

            a1[27][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[27][0] - theta1[1]*a[27][0] - theta[0]*a[27][1] + theta1[0]*a[27][1] + a[27][2];

            a1[28][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[28][0] + theta[2]*a[28][1] - theta1[2]*a[28][1] - theta[1]*a[28][2] + theta1[1]*a[28][2];

            a1[28][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[28][0] + theta1[2]*a[28][0] + a[28][1] + theta[0]*a[28][2] - theta1[0]*a[28][2];

            a1[28][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[28][0] - theta1[1]*a[28][0] - theta[0]*a[28][1] + theta1[0]*a[28][1] + a[28][2];

            a1[29][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[29][0] + theta[2]*a[29][1] - theta1[2]*a[29][1] - theta[1]*a[29][2] + theta1[1]*a[29][2];

            a1[29][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[29][0] + theta1[2]*a[29][0] + a[29][1] + theta[0]*a[29][2] - theta1[0]*a[29][2];

            a1[29][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[29][0] - theta1[1]*a[29][0] - theta[0]*a[29][1] + theta1[0]*a[29][1] + a[29][2];

            a1[30][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[30][0] + theta[2]*a[30][1] - theta1[2]*a[30][1] - theta[1]*a[30][2] + theta1[1]*a[30][2];

            a1[30][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[30][0] + theta1[2]*a[30][0] + a[30][1] + theta[0]*a[30][2] - theta1[0]*a[30][2];

            a1[30][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[30][0] - theta1[1]*a[30][0] - theta[0]*a[30][1] + theta1[0]*a[30][1] + a[30][2];

            a1[31][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[31][0] + theta[2]*a[31][1] - theta1[2]*a[31][1] - theta[1]*a[31][2] + theta1[1]*a[31][2];

            a1[31][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[31][0] + theta1[2]*a[31][0] + a[31][1] + theta[0]*a[31][2] - theta1[0]*a[31][2];

            a1[31][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[31][0] - theta1[1]*a[31][0] - theta[0]*a[31][1] + theta1[0]*a[31][1] + a[31][2];

            a1[32][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[32][0] + theta[2]*a[32][1] - theta1[2]*a[32][1] - theta[1]*a[32][2] + theta1[1]*a[32][2];

            a1[32][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[32][0] + theta1[2]*a[32][0] + a[32][1] + theta[0]*a[32][2] - theta1[0]*a[32][2];

            a1[32][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[32][0] - theta1[1]*a[32][0] - theta[0]*a[32][1] + theta1[0]*a[32][1] + a[32][2];

            a1[33][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[33][0] + theta[2]*a[33][1] - theta1[2]*a[33][1] - theta[1]*a[33][2] + theta1[1]*a[33][2];

            a1[33][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[33][0] + theta1[2]*a[33][0] + a[33][1] + theta[0]*a[33][2] - theta1[0]*a[33][2];

            a1[33][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[33][0] - theta1[1]*a[33][0] - theta[0]*a[33][1] + theta1[0]*a[33][1] + a[33][2];

            a1[34][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[34][0] + theta[2]*a[34][1] - theta1[2]*a[34][1] - theta[1]*a[34][2] + theta1[1]*a[34][2];

            a1[34][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[34][0] + theta1[2]*a[34][0] + a[34][1] + theta[0]*a[34][2] - theta1[0]*a[34][2];

            a1[34][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[34][0] - theta1[1]*a[34][0] - theta[0]*a[34][1] + theta1[0]*a[34][1] + a[34][2];

            a1[35][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[35][0] + theta[2]*a[35][1] - theta1[2]*a[35][1] - theta[1]*a[35][2] + theta1[1]*a[35][2];

            a1[35][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[35][0] + theta1[2]*a[35][0] + a[35][1] + theta[0]*a[35][2] - theta1[0]*a[35][2];

            a1[35][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[35][0] - theta1[1]*a[35][0] - theta[0]*a[35][1] + theta1[0]*a[35][1] + a[35][2];

            a1[36][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[36][0] + theta[2]*a[36][1] - theta1[2]*a[36][1] - theta[1]*a[36][2] + theta1[1]*a[36][2];

            a1[36][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[36][0] + theta1[2]*a[36][0] + a[36][1] + theta[0]*a[36][2] - theta1[0]*a[36][2];

            a1[36][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[36][0] - theta1[1]*a[36][0] - theta[0]*a[36][1] + theta1[0]*a[36][1] + a[36][2];

            a1[37][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[37][0] + theta[2]*a[37][1] - theta1[2]*a[37][1] - theta[1]*a[37][2] + theta1[1]*a[37][2];

            a1[37][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[37][0] + theta1[2]*a[37][0] + a[37][1] + theta[0]*a[37][2] - theta1[0]*a[37][2];

            a1[37][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[37][0] - theta1[1]*a[37][0] - theta[0]*a[37][1] + theta1[0]*a[37][1] + a[37][2];

            a1[38][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[38][0] + theta[2]*a[38][1] - theta1[2]*a[38][1] - theta[1]*a[38][2] + theta1[1]*a[38][2];

            a1[38][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[38][0] + theta1[2]*a[38][0] + a[38][1] + theta[0]*a[38][2] - theta1[0]*a[38][2];

            a1[38][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[38][0] - theta1[1]*a[38][0] - theta[0]*a[38][1] + theta1[0]*a[38][1] + a[38][2];

            a1[39][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[39][0] + theta[2]*a[39][1] - theta1[2]*a[39][1] - theta[1]*a[39][2] + theta1[1]*a[39][2];

            a1[39][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[39][0] + theta1[2]*a[39][0] + a[39][1] + theta[0]*a[39][2] - theta1[0]*a[39][2];

            a1[39][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[39][0] - theta1[1]*a[39][0] - theta[0]*a[39][1] + theta1[0]*a[39][1] + a[39][2];

            a1[40][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[40][0] + theta[2]*a[40][1] - theta1[2]*a[40][1] - theta[1]*a[40][2] + theta1[1]*a[40][2];

            a1[40][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[40][0] + theta1[2]*a[40][0] + a[40][1] + theta[0]*a[40][2] - theta1[0]*a[40][2];

            a1[40][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[40][0] - theta1[1]*a[40][0] - theta[0]*a[40][1] + theta1[0]*a[40][1] + a[40][2];

            break;

        case 51:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmRadial[10][0] + FmRadial[11][0] + FmRadial[12][0] + FmRadial[13][0] + FmRadial[14][0] + FmRadial[15][0] + FmRadial[16][0] + FmRadial[17][0] + FmRadial[18][0] + FmRadial[19][0] + FmRadial[20][0] + FmRadial[21][0] + FmRadial[22][0] + FmRadial[23][0] + FmRadial[24][0] + FmRadial[25][0] + FmRadial[26][0] + FmRadial[27][0] + FmRadial[28][0] + FmRadial[29][0] + FmRadial[30][0] + FmRadial[31][0] + FmRadial[32][0] + FmRadial[33][0] + FmRadial[34][0] + FmRadial[35][0] + FmRadial[36][0] + FmRadial[37][0] + FmRadial[38][0] + FmRadial[39][0] + FmRadial[40][0] + FmRadial[41][0] + FmRadial[42][0] + FmRadial[43][0] + FmRadial[44][0] + FmRadial[45][0] + FmRadial[46][0] + FmRadial[47][0] + FmRadial[48][0] + FmRadial[49][0] + FmRadial[50][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0] + FmTangential[41][0] + FmTangential[42][0] + FmTangential[43][0] + FmTangential[44][0] + FmTangential[45][0] + FmTangential[46][0] + FmTangential[47][0] + FmTangential[48][0] + FmTangential[49][0] + FmTangential[50][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmRadial[10][1] + FmRadial[11][1] + FmRadial[12][1] + FmRadial[13][1] + FmRadial[14][1] + FmRadial[15][1] + FmRadial[16][1] + FmRadial[17][1] + FmRadial[18][1] + FmRadial[19][1] + FmRadial[20][1] + FmRadial[21][1] + FmRadial[22][1] + FmRadial[23][1] + FmRadial[24][1] + FmRadial[25][1] + FmRadial[26][1] + FmRadial[27][1] + FmRadial[28][1] + FmRadial[29][1] + FmRadial[30][1] + FmRadial[31][1] + FmRadial[32][1] + FmRadial[33][1] + FmRadial[34][1] + FmRadial[35][1] + FmRadial[36][1] + FmRadial[37][1] + FmRadial[38][1] + FmRadial[39][1] + FmRadial[40][1] + FmRadial[41][1] + FmRadial[42][1] + FmRadial[43][1] + FmRadial[44][1] + FmRadial[45][1] + FmRadial[46][1] + FmRadial[47][1] + FmRadial[48][1] + FmRadial[49][1] + FmRadial[50][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1] + FmTangential[19][1] + FmTangential[20][1] + FmTangential[21][1] + FmTangential[22][1] + FmTangential[23][1] + FmTangential[24][1] + FmTangential[25][1] + FmTangential[26][1] + FmTangential[27][1] + FmTangential[28][1] + FmTangential[29][1] + FmTangential[30][1] + FmTangential[31][1] + FmTangential[32][1] + FmTangential[33][1] + FmTangential[34][1] + FmTangential[35][1] + FmTangential[36][1] + FmTangential[37][1] + FmTangential[38][1] + FmTangential[39][1] + FmTangential[40][1] + FmTangential[41][1] + FmTangential[42][1] + FmTangential[43][1] + FmTangential[44][1] + FmTangential[45][1] + FmTangential[46][1] + FmTangential[47][1] + FmTangential[48][1] + FmTangential[49][1] + FmTangential[50][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmRadial[10][2] + FmRadial[11][2] + FmRadial[12][2] + FmRadial[13][2] + FmRadial[14][2] + FmRadial[15][2] + FmRadial[16][2] + FmRadial[17][2] + FmRadial[18][2] + FmRadial[19][2] + FmRadial[20][2] + FmRadial[21][2] + FmRadial[22][2] + FmRadial[23][2] + FmRadial[24][2] + FmRadial[25][2] + FmRadial[26][2] + FmRadial[27][2] + FmRadial[28][2] + FmRadial[29][2] + FmRadial[30][2] + FmRadial[31][2] + FmRadial[32][2] + FmRadial[33][2] + FmRadial[34][2] + FmRadial[35][2] + FmRadial[36][2] + FmRadial[37][2] + FmRadial[38][2] + FmRadial[39][2] + FmRadial[40][2] + FmRadial[41][2] + FmRadial[42][2] + FmRadial[43][2] + FmRadial[44][2] + FmRadial[45][2] + FmRadial[46][2] + FmRadial[47][2] + FmRadial[48][2] + FmRadial[49][2] + FmRadial[50][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2] + FmTangential[10][2] + FmTangential[11][2] + FmTangential[12][2] + FmTangential[13][2] + FmTangential[14][2] + FmTangential[15][2] + FmTangential[16][2] + FmTangential[17][2] + FmTangential[18][2] + FmTangential[19][2] + FmTangential[20][2] + FmTangential[21][2] + FmTangential[22][2] + FmTangential[23][2] + FmTangential[24][2] + FmTangential[25][2] + FmTangential[26][2] + FmTangential[27][2] + FmTangential[28][2] + FmTangential[29][2] + FmTangential[30][2] + FmTangential[31][2] + FmTangential[32][2] + FmTangential[33][2] + FmTangential[34][2] + FmTangential[35][2] + FmTangential[36][2] + FmTangential[37][2] + FmTangential[38][2] + FmTangential[39][2] + FmTangential[40][2] + FmTangential[41][2] + FmTangential[42][2] + FmTangential[43][2] + FmTangential[44][2] + FmTangential[45][2] + FmTangential[46][2] + FmTangential[47][2] + FmTangential[48][2] + FmTangential[49][2] + FmTangential[50][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2] - a[10][2]*FmTangential[10][1] - c[1]*FmTangential[10][2] + a[10][1]*FmTangential[10][2] - a[11][2]*FmTangential[11][1] - c[1]*FmTangential[11][2] + a[11][1]*FmTangential[11][2] - a[12][2]*FmTangential[12][1] - c[1]*FmTangential[12][2] + a[12][1]*FmTangential[12][2] - a[13][2]*FmTangential[13][1] - c[1]*FmTangential[13][2] + a[13][1]*FmTangential[13][2] - a[14][2]*FmTangential[14][1] - c[1]*FmTangential[14][2] + a[14][1]*FmTangential[14][2] - a[15][2]*FmTangential[15][1] - c[1]*FmTangential[15][2] + a[15][1]*FmTangential[15][2] - a[16][2]*FmTangential[16][1] - c[1]*FmTangential[16][2] + a[16][1]*FmTangential[16][2] - a[17][2]*FmTangential[17][1] - c[1]*FmTangential[17][2] + a[17][1]*FmTangential[17][2] - a[18][2]*FmTangential[18][1] - c[1]*FmTangential[18][2] + a[18][1]*FmTangential[18][2] - a[19][2]*FmTangential[19][1] - c[1]*FmTangential[19][2] + a[19][1]*FmTangential[19][2] - a[20][2]*FmTangential[20][1] - c[1]*FmTangential[20][2] + a[20][1]*FmTangential[20][2] - a[21][2]*FmTangential[21][1] - c[1]*FmTangential[21][2] + a[21][1]*FmTangential[21][2] - a[22][2]*FmTangential[22][1] - c[1]*FmTangential[22][2] + a[22][1]*FmTangential[22][2] - a[23][2]*FmTangential[23][1] - c[1]*FmTangential[23][2] + a[23][1]*FmTangential[23][2] - a[24][2]*FmTangential[24][1] - c[1]*FmTangential[24][2] + a[24][1]*FmTangential[24][2] - a[25][2]*FmTangential[25][1] - c[1]*FmTangential[25][2] + a[25][1]*FmTangential[25][2] - a[26][2]*FmTangential[26][1] - c[1]*FmTangential[26][2] + a[26][1]*FmTangential[26][2] - a[27][2]*FmTangential[27][1] - c[1]*FmTangential[27][2] + a[27][1]*FmTangential[27][2] - a[28][2]*FmTangential[28][1] - c[1]*FmTangential[28][2] + a[28][1]*FmTangential[28][2] - a[29][2]*FmTangential[29][1] - c[1]*FmTangential[29][2] + a[29][1]*FmTangential[29][2] - a[30][2]*FmTangential[30][1] - c[1]*FmTangential[30][2] + a[30][1]*FmTangential[30][2] - a[31][2]*FmTangential[31][1] - c[1]*FmTangential[31][2] + a[31][1]*FmTangential[31][2] - a[32][2]*FmTangential[32][1] - c[1]*FmTangential[32][2] + a[32][1]*FmTangential[32][2] - a[33][2]*FmTangential[33][1] - c[1]*FmTangential[33][2] + a[33][1]*FmTangential[33][2] - a[34][2]*FmTangential[34][1] - c[1]*FmTangential[34][2] + a[34][1]*FmTangential[34][2] - a[35][2]*FmTangential[35][1] - c[1]*FmTangential[35][2] + a[35][1]*FmTangential[35][2] - a[36][2]*FmTangential[36][1] - c[1]*FmTangential[36][2] + a[36][1]*FmTangential[36][2] - a[37][2]*FmTangential[37][1] - c[1]*FmTangential[37][2] + a[37][1]*FmTangential[37][2] - a[38][2]*FmTangential[38][1] - c[1]*FmTangential[38][2] + a[38][1]*FmTangential[38][2] - a[39][2]*FmTangential[39][1] - c[1]*FmTangential[39][2] + a[39][1]*FmTangential[39][2] - a[40][2]*FmTangential[40][1] - c[1]*FmTangential[40][2] + a[40][1]*FmTangential[40][2] - a[41][2]*FmTangential[41][1] - c[1]*FmTangential[41][2] + a[41][1]*FmTangential[41][2] - a[42][2]*FmTangential[42][1] - c[1]*FmTangential[42][2] + a[42][1]*FmTangential[42][2] - a[43][2]*FmTangential[43][1] - c[1]*FmTangential[43][2] + a[43][1]*FmTangential[43][2] - a[44][2]*FmTangential[44][1] - c[1]*FmTangential[44][2] + a[44][1]*FmTangential[44][2] - a[45][2]*FmTangential[45][1] - c[1]*FmTangential[45][2] + a[45][1]*FmTangential[45][2] - a[46][2]*FmTangential[46][1] - c[1]*FmTangential[46][2] + a[46][1]*FmTangential[46][2] - a[47][2]*FmTangential[47][1] - c[1]*FmTangential[47][2] + a[47][1]*FmTangential[47][2] - a[48][2]*FmTangential[48][1] - c[1]*FmTangential[48][2] + a[48][1]*FmTangential[48][2] - a[49][2]*FmTangential[49][1] - c[1]*FmTangential[49][2] + a[49][1]*FmTangential[49][2] - a[50][2]*FmTangential[50][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1] + FmTangential[19][1] + FmTangential[20][1] + FmTangential[21][1] + FmTangential[22][1] + FmTangential[23][1] + FmTangential[24][1] + FmTangential[25][1] + FmTangential[26][1] + FmTangential[27][1] + FmTangential[28][1] + FmTangential[29][1] + FmTangential[30][1] + FmTangential[31][1] + FmTangential[32][1] + FmTangential[33][1] + FmTangential[34][1] + FmTangential[35][1] + FmTangential[36][1] + FmTangential[37][1] + FmTangential[38][1] + FmTangential[39][1] + FmTangential[40][1] + FmTangential[41][1] + FmTangential[42][1] + FmTangential[43][1] + FmTangential[44][1] + FmTangential[45][1] + FmTangential[46][1] + FmTangential[47][1] + FmTangential[48][1] + FmTangential[49][1] + FmTangential[50][1]) - c[1]*FmTangential[50][2] + a[50][1]*FmTangential[50][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2] + a[10][2]*FmTangential[10][0] + c[0]*FmTangential[10][2] - a[10][0]*FmTangential[10][2] + a[11][2]*FmTangential[11][0] + c[0]*FmTangential[11][2] - a[11][0]*FmTangential[11][2] + a[12][2]*FmTangential[12][0] + c[0]*FmTangential[12][2] - a[12][0]*FmTangential[12][2] + a[13][2]*FmTangential[13][0] + c[0]*FmTangential[13][2] - a[13][0]*FmTangential[13][2] + a[14][2]*FmTangential[14][0] + c[0]*FmTangential[14][2] - a[14][0]*FmTangential[14][2] + a[15][2]*FmTangential[15][0] + c[0]*FmTangential[15][2] - a[15][0]*FmTangential[15][2] + a[16][2]*FmTangential[16][0] + c[0]*FmTangential[16][2] - a[16][0]*FmTangential[16][2] + a[17][2]*FmTangential[17][0] + c[0]*FmTangential[17][2] - a[17][0]*FmTangential[17][2] + a[18][2]*FmTangential[18][0] + c[0]*FmTangential[18][2] - a[18][0]*FmTangential[18][2] + a[19][2]*FmTangential[19][0] + c[0]*FmTangential[19][2] - a[19][0]*FmTangential[19][2] + a[20][2]*FmTangential[20][0] + c[0]*FmTangential[20][2] - a[20][0]*FmTangential[20][2] + a[21][2]*FmTangential[21][0] + c[0]*FmTangential[21][2] - a[21][0]*FmTangential[21][2] + a[22][2]*FmTangential[22][0] + c[0]*FmTangential[22][2] - a[22][0]*FmTangential[22][2] + a[23][2]*FmTangential[23][0] + c[0]*FmTangential[23][2] - a[23][0]*FmTangential[23][2] + a[24][2]*FmTangential[24][0] + c[0]*FmTangential[24][2] - a[24][0]*FmTangential[24][2] + a[25][2]*FmTangential[25][0] + c[0]*FmTangential[25][2] - a[25][0]*FmTangential[25][2] + a[26][2]*FmTangential[26][0] + c[0]*FmTangential[26][2] - a[26][0]*FmTangential[26][2] + a[27][2]*FmTangential[27][0] + c[0]*FmTangential[27][2] - a[27][0]*FmTangential[27][2] + a[28][2]*FmTangential[28][0] + c[0]*FmTangential[28][2] - a[28][0]*FmTangential[28][2] + a[29][2]*FmTangential[29][0] + c[0]*FmTangential[29][2] - a[29][0]*FmTangential[29][2] + a[30][2]*FmTangential[30][0] + c[0]*FmTangential[30][2] - a[30][0]*FmTangential[30][2] + a[31][2]*FmTangential[31][0] + c[0]*FmTangential[31][2] - a[31][0]*FmTangential[31][2] + a[32][2]*FmTangential[32][0] + c[0]*FmTangential[32][2] - a[32][0]*FmTangential[32][2] + a[33][2]*FmTangential[33][0] + c[0]*FmTangential[33][2] - a[33][0]*FmTangential[33][2] + a[34][2]*FmTangential[34][0] + c[0]*FmTangential[34][2] - a[34][0]*FmTangential[34][2] + a[35][2]*FmTangential[35][0] + c[0]*FmTangential[35][2] - a[35][0]*FmTangential[35][2] + a[36][2]*FmTangential[36][0] + c[0]*FmTangential[36][2] - a[36][0]*FmTangential[36][2] + a[37][2]*FmTangential[37][0] + c[0]*FmTangential[37][2] - a[37][0]*FmTangential[37][2] + a[38][2]*FmTangential[38][0] + c[0]*FmTangential[38][2] - a[38][0]*FmTangential[38][2] + a[39][2]*FmTangential[39][0] + c[0]*FmTangential[39][2] - a[39][0]*FmTangential[39][2] + a[40][2]*FmTangential[40][0] + c[0]*FmTangential[40][2] - a[40][0]*FmTangential[40][2] + a[41][2]*FmTangential[41][0] + c[0]*FmTangential[41][2] - a[41][0]*FmTangential[41][2] + a[42][2]*FmTangential[42][0] + c[0]*FmTangential[42][2] - a[42][0]*FmTangential[42][2] + a[43][2]*FmTangential[43][0] + c[0]*FmTangential[43][2] - a[43][0]*FmTangential[43][2] + a[44][2]*FmTangential[44][0] + c[0]*FmTangential[44][2] - a[44][0]*FmTangential[44][2] + a[45][2]*FmTangential[45][0] + c[0]*FmTangential[45][2] - a[45][0]*FmTangential[45][2] + a[46][2]*FmTangential[46][0] + c[0]*FmTangential[46][2] - a[46][0]*FmTangential[46][2] + a[47][2]*FmTangential[47][0] + c[0]*FmTangential[47][2] - a[47][0]*FmTangential[47][2] + a[48][2]*FmTangential[48][0] + c[0]*FmTangential[48][2] - a[48][0]*FmTangential[48][2] + a[49][2]*FmTangential[49][0] + c[0]*FmTangential[49][2] - a[49][0]*FmTangential[49][2] + a[50][2]*FmTangential[50][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0] + FmTangential[41][0] + FmTangential[42][0] + FmTangential[43][0] + FmTangential[44][0] + FmTangential[45][0] + FmTangential[46][0] + FmTangential[47][0] + FmTangential[48][0] + FmTangential[49][0] + FmTangential[50][0]) + c[0]*FmTangential[50][2] - a[50][0]*FmTangential[50][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1] - a[10][1]*FmTangential[10][0] - c[0]*FmTangential[10][1] + a[10][0]*FmTangential[10][1] - a[11][1]*FmTangential[11][0] - c[0]*FmTangential[11][1] + a[11][0]*FmTangential[11][1] - a[12][1]*FmTangential[12][0] - c[0]*FmTangential[12][1] + a[12][0]*FmTangential[12][1] - a[13][1]*FmTangential[13][0] - c[0]*FmTangential[13][1] + a[13][0]*FmTangential[13][1] - a[14][1]*FmTangential[14][0] - c[0]*FmTangential[14][1] + a[14][0]*FmTangential[14][1] - a[15][1]*FmTangential[15][0] - c[0]*FmTangential[15][1] + a[15][0]*FmTangential[15][1] - a[16][1]*FmTangential[16][0] - c[0]*FmTangential[16][1] + a[16][0]*FmTangential[16][1] - a[17][1]*FmTangential[17][0] - c[0]*FmTangential[17][1] + a[17][0]*FmTangential[17][1] - a[18][1]*FmTangential[18][0] - c[0]*FmTangential[18][1] + a[18][0]*FmTangential[18][1] - a[19][1]*FmTangential[19][0] - c[0]*FmTangential[19][1] + a[19][0]*FmTangential[19][1] - a[20][1]*FmTangential[20][0] - c[0]*FmTangential[20][1] + a[20][0]*FmTangential[20][1] - a[21][1]*FmTangential[21][0] - c[0]*FmTangential[21][1] + a[21][0]*FmTangential[21][1] - a[22][1]*FmTangential[22][0] - c[0]*FmTangential[22][1] + a[22][0]*FmTangential[22][1] - a[23][1]*FmTangential[23][0] - c[0]*FmTangential[23][1] + a[23][0]*FmTangential[23][1] - a[24][1]*FmTangential[24][0] - c[0]*FmTangential[24][1] + a[24][0]*FmTangential[24][1] - a[25][1]*FmTangential[25][0] - c[0]*FmTangential[25][1] + a[25][0]*FmTangential[25][1] - a[26][1]*FmTangential[26][0] - c[0]*FmTangential[26][1] + a[26][0]*FmTangential[26][1] - a[27][1]*FmTangential[27][0] - c[0]*FmTangential[27][1] + a[27][0]*FmTangential[27][1] - a[28][1]*FmTangential[28][0] - c[0]*FmTangential[28][1] + a[28][0]*FmTangential[28][1] - a[29][1]*FmTangential[29][0] - c[0]*FmTangential[29][1] + a[29][0]*FmTangential[29][1] - a[30][1]*FmTangential[30][0] - c[0]*FmTangential[30][1] + a[30][0]*FmTangential[30][1] - a[31][1]*FmTangential[31][0] - c[0]*FmTangential[31][1] + a[31][0]*FmTangential[31][1] - a[32][1]*FmTangential[32][0] - c[0]*FmTangential[32][1] + a[32][0]*FmTangential[32][1] - a[33][1]*FmTangential[33][0] - c[0]*FmTangential[33][1] + a[33][0]*FmTangential[33][1] - a[34][1]*FmTangential[34][0] - c[0]*FmTangential[34][1] + a[34][0]*FmTangential[34][1] - a[35][1]*FmTangential[35][0] - c[0]*FmTangential[35][1] + a[35][0]*FmTangential[35][1] - a[36][1]*FmTangential[36][0] - c[0]*FmTangential[36][1] + a[36][0]*FmTangential[36][1] - a[37][1]*FmTangential[37][0] - c[0]*FmTangential[37][1] + a[37][0]*FmTangential[37][1] - a[38][1]*FmTangential[38][0] - c[0]*FmTangential[38][1] + a[38][0]*FmTangential[38][1] - a[39][1]*FmTangential[39][0] - c[0]*FmTangential[39][1] + a[39][0]*FmTangential[39][1] - a[40][1]*FmTangential[40][0] - c[0]*FmTangential[40][1] + a[40][0]*FmTangential[40][1] - a[41][1]*FmTangential[41][0] - c[0]*FmTangential[41][1] + a[41][0]*FmTangential[41][1] - a[42][1]*FmTangential[42][0] - c[0]*FmTangential[42][1] + a[42][0]*FmTangential[42][1] - a[43][1]*FmTangential[43][0] - c[0]*FmTangential[43][1] + a[43][0]*FmTangential[43][1] - a[44][1]*FmTangential[44][0] - c[0]*FmTangential[44][1] + a[44][0]*FmTangential[44][1] - a[45][1]*FmTangential[45][0] - c[0]*FmTangential[45][1] + a[45][0]*FmTangential[45][1] - a[46][1]*FmTangential[46][0] - c[0]*FmTangential[46][1] + a[46][0]*FmTangential[46][1] - a[47][1]*FmTangential[47][0] - c[0]*FmTangential[47][1] + a[47][0]*FmTangential[47][1] - a[48][1]*FmTangential[48][0] - c[0]*FmTangential[48][1] + a[48][0]*FmTangential[48][1] - a[49][1]*FmTangential[49][0] - c[0]*FmTangential[49][1] + a[49][0]*FmTangential[49][1] - a[50][1]*FmTangential[50][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0] + FmTangential[41][0] + FmTangential[42][0] + FmTangential[43][0] + FmTangential[44][0] + FmTangential[45][0] + FmTangential[46][0] + FmTangential[47][0] + FmTangential[48][0] + FmTangential[49][0] + FmTangential[50][0]) - c[0]*FmTangential[50][1] + a[50][0]*FmTangential[50][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            a1[10][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[10][0] + theta[2]*a[10][1] - theta1[2]*a[10][1] - theta[1]*a[10][2] + theta1[1]*a[10][2];

            a1[10][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[10][0] + theta1[2]*a[10][0] + a[10][1] + theta[0]*a[10][2] - theta1[0]*a[10][2];

            a1[10][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[10][0] - theta1[1]*a[10][0] - theta[0]*a[10][1] + theta1[0]*a[10][1] + a[10][2];

            a1[11][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[11][0] + theta[2]*a[11][1] - theta1[2]*a[11][1] - theta[1]*a[11][2] + theta1[1]*a[11][2];

            a1[11][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[11][0] + theta1[2]*a[11][0] + a[11][1] + theta[0]*a[11][2] - theta1[0]*a[11][2];

            a1[11][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[11][0] - theta1[1]*a[11][0] - theta[0]*a[11][1] + theta1[0]*a[11][1] + a[11][2];

            a1[12][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[12][0] + theta[2]*a[12][1] - theta1[2]*a[12][1] - theta[1]*a[12][2] + theta1[1]*a[12][2];

            a1[12][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[12][0] + theta1[2]*a[12][0] + a[12][1] + theta[0]*a[12][2] - theta1[0]*a[12][2];

            a1[12][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[12][0] - theta1[1]*a[12][0] - theta[0]*a[12][1] + theta1[0]*a[12][1] + a[12][2];

            a1[13][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[13][0] + theta[2]*a[13][1] - theta1[2]*a[13][1] - theta[1]*a[13][2] + theta1[1]*a[13][2];

            a1[13][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[13][0] + theta1[2]*a[13][0] + a[13][1] + theta[0]*a[13][2] - theta1[0]*a[13][2];

            a1[13][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[13][0] - theta1[1]*a[13][0] - theta[0]*a[13][1] + theta1[0]*a[13][1] + a[13][2];

            a1[14][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[14][0] + theta[2]*a[14][1] - theta1[2]*a[14][1] - theta[1]*a[14][2] + theta1[1]*a[14][2];

            a1[14][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[14][0] + theta1[2]*a[14][0] + a[14][1] + theta[0]*a[14][2] - theta1[0]*a[14][2];

            a1[14][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[14][0] - theta1[1]*a[14][0] - theta[0]*a[14][1] + theta1[0]*a[14][1] + a[14][2];

            a1[15][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[15][0] + theta[2]*a[15][1] - theta1[2]*a[15][1] - theta[1]*a[15][2] + theta1[1]*a[15][2];

            a1[15][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[15][0] + theta1[2]*a[15][0] + a[15][1] + theta[0]*a[15][2] - theta1[0]*a[15][2];

            a1[15][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[15][0] - theta1[1]*a[15][0] - theta[0]*a[15][1] + theta1[0]*a[15][1] + a[15][2];

            a1[16][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[16][0] + theta[2]*a[16][1] - theta1[2]*a[16][1] - theta[1]*a[16][2] + theta1[1]*a[16][2];

            a1[16][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[16][0] + theta1[2]*a[16][0] + a[16][1] + theta[0]*a[16][2] - theta1[0]*a[16][2];

            a1[16][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[16][0] - theta1[1]*a[16][0] - theta[0]*a[16][1] + theta1[0]*a[16][1] + a[16][2];

            a1[17][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[17][0] + theta[2]*a[17][1] - theta1[2]*a[17][1] - theta[1]*a[17][2] + theta1[1]*a[17][2];

            a1[17][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[17][0] + theta1[2]*a[17][0] + a[17][1] + theta[0]*a[17][2] - theta1[0]*a[17][2];

            a1[17][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[17][0] - theta1[1]*a[17][0] - theta[0]*a[17][1] + theta1[0]*a[17][1] + a[17][2];

            a1[18][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[18][0] + theta[2]*a[18][1] - theta1[2]*a[18][1] - theta[1]*a[18][2] + theta1[1]*a[18][2];

            a1[18][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[18][0] + theta1[2]*a[18][0] + a[18][1] + theta[0]*a[18][2] - theta1[0]*a[18][2];

            a1[18][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[18][0] - theta1[1]*a[18][0] - theta[0]*a[18][1] + theta1[0]*a[18][1] + a[18][2];

            a1[19][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[19][0] + theta[2]*a[19][1] - theta1[2]*a[19][1] - theta[1]*a[19][2] + theta1[1]*a[19][2];

            a1[19][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[19][0] + theta1[2]*a[19][0] + a[19][1] + theta[0]*a[19][2] - theta1[0]*a[19][2];

            a1[19][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[19][0] - theta1[1]*a[19][0] - theta[0]*a[19][1] + theta1[0]*a[19][1] + a[19][2];

            a1[20][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[20][0] + theta[2]*a[20][1] - theta1[2]*a[20][1] - theta[1]*a[20][2] + theta1[1]*a[20][2];

            a1[20][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[20][0] + theta1[2]*a[20][0] + a[20][1] + theta[0]*a[20][2] - theta1[0]*a[20][2];

            a1[20][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[20][0] - theta1[1]*a[20][0] - theta[0]*a[20][1] + theta1[0]*a[20][1] + a[20][2];

            a1[21][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[21][0] + theta[2]*a[21][1] - theta1[2]*a[21][1] - theta[1]*a[21][2] + theta1[1]*a[21][2];

            a1[21][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[21][0] + theta1[2]*a[21][0] + a[21][1] + theta[0]*a[21][2] - theta1[0]*a[21][2];

            a1[21][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[21][0] - theta1[1]*a[21][0] - theta[0]*a[21][1] + theta1[0]*a[21][1] + a[21][2];

            a1[22][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[22][0] + theta[2]*a[22][1] - theta1[2]*a[22][1] - theta[1]*a[22][2] + theta1[1]*a[22][2];

            a1[22][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[22][0] + theta1[2]*a[22][0] + a[22][1] + theta[0]*a[22][2] - theta1[0]*a[22][2];

            a1[22][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[22][0] - theta1[1]*a[22][0] - theta[0]*a[22][1] + theta1[0]*a[22][1] + a[22][2];

            a1[23][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[23][0] + theta[2]*a[23][1] - theta1[2]*a[23][1] - theta[1]*a[23][2] + theta1[1]*a[23][2];

            a1[23][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[23][0] + theta1[2]*a[23][0] + a[23][1] + theta[0]*a[23][2] - theta1[0]*a[23][2];

            a1[23][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[23][0] - theta1[1]*a[23][0] - theta[0]*a[23][1] + theta1[0]*a[23][1] + a[23][2];

            a1[24][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[24][0] + theta[2]*a[24][1] - theta1[2]*a[24][1] - theta[1]*a[24][2] + theta1[1]*a[24][2];

            a1[24][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[24][0] + theta1[2]*a[24][0] + a[24][1] + theta[0]*a[24][2] - theta1[0]*a[24][2];

            a1[24][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[24][0] - theta1[1]*a[24][0] - theta[0]*a[24][1] + theta1[0]*a[24][1] + a[24][2];

            a1[25][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[25][0] + theta[2]*a[25][1] - theta1[2]*a[25][1] - theta[1]*a[25][2] + theta1[1]*a[25][2];

            a1[25][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[25][0] + theta1[2]*a[25][0] + a[25][1] + theta[0]*a[25][2] - theta1[0]*a[25][2];

            a1[25][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[25][0] - theta1[1]*a[25][0] - theta[0]*a[25][1] + theta1[0]*a[25][1] + a[25][2];

            a1[26][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[26][0] + theta[2]*a[26][1] - theta1[2]*a[26][1] - theta[1]*a[26][2] + theta1[1]*a[26][2];

            a1[26][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[26][0] + theta1[2]*a[26][0] + a[26][1] + theta[0]*a[26][2] - theta1[0]*a[26][2];

            a1[26][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[26][0] - theta1[1]*a[26][0] - theta[0]*a[26][1] + theta1[0]*a[26][1] + a[26][2];

            a1[27][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[27][0] + theta[2]*a[27][1] - theta1[2]*a[27][1] - theta[1]*a[27][2] + theta1[1]*a[27][2];

            a1[27][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[27][0] + theta1[2]*a[27][0] + a[27][1] + theta[0]*a[27][2] - theta1[0]*a[27][2];

            a1[27][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[27][0] - theta1[1]*a[27][0] - theta[0]*a[27][1] + theta1[0]*a[27][1] + a[27][2];

            a1[28][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[28][0] + theta[2]*a[28][1] - theta1[2]*a[28][1] - theta[1]*a[28][2] + theta1[1]*a[28][2];

            a1[28][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[28][0] + theta1[2]*a[28][0] + a[28][1] + theta[0]*a[28][2] - theta1[0]*a[28][2];

            a1[28][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[28][0] - theta1[1]*a[28][0] - theta[0]*a[28][1] + theta1[0]*a[28][1] + a[28][2];

            a1[29][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[29][0] + theta[2]*a[29][1] - theta1[2]*a[29][1] - theta[1]*a[29][2] + theta1[1]*a[29][2];

            a1[29][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[29][0] + theta1[2]*a[29][0] + a[29][1] + theta[0]*a[29][2] - theta1[0]*a[29][2];

            a1[29][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[29][0] - theta1[1]*a[29][0] - theta[0]*a[29][1] + theta1[0]*a[29][1] + a[29][2];

            a1[30][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[30][0] + theta[2]*a[30][1] - theta1[2]*a[30][1] - theta[1]*a[30][2] + theta1[1]*a[30][2];

            a1[30][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[30][0] + theta1[2]*a[30][0] + a[30][1] + theta[0]*a[30][2] - theta1[0]*a[30][2];

            a1[30][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[30][0] - theta1[1]*a[30][0] - theta[0]*a[30][1] + theta1[0]*a[30][1] + a[30][2];

            a1[31][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[31][0] + theta[2]*a[31][1] - theta1[2]*a[31][1] - theta[1]*a[31][2] + theta1[1]*a[31][2];

            a1[31][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[31][0] + theta1[2]*a[31][0] + a[31][1] + theta[0]*a[31][2] - theta1[0]*a[31][2];

            a1[31][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[31][0] - theta1[1]*a[31][0] - theta[0]*a[31][1] + theta1[0]*a[31][1] + a[31][2];

            a1[32][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[32][0] + theta[2]*a[32][1] - theta1[2]*a[32][1] - theta[1]*a[32][2] + theta1[1]*a[32][2];

            a1[32][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[32][0] + theta1[2]*a[32][0] + a[32][1] + theta[0]*a[32][2] - theta1[0]*a[32][2];

            a1[32][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[32][0] - theta1[1]*a[32][0] - theta[0]*a[32][1] + theta1[0]*a[32][1] + a[32][2];

            a1[33][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[33][0] + theta[2]*a[33][1] - theta1[2]*a[33][1] - theta[1]*a[33][2] + theta1[1]*a[33][2];

            a1[33][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[33][0] + theta1[2]*a[33][0] + a[33][1] + theta[0]*a[33][2] - theta1[0]*a[33][2];

            a1[33][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[33][0] - theta1[1]*a[33][0] - theta[0]*a[33][1] + theta1[0]*a[33][1] + a[33][2];

            a1[34][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[34][0] + theta[2]*a[34][1] - theta1[2]*a[34][1] - theta[1]*a[34][2] + theta1[1]*a[34][2];

            a1[34][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[34][0] + theta1[2]*a[34][0] + a[34][1] + theta[0]*a[34][2] - theta1[0]*a[34][2];

            a1[34][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[34][0] - theta1[1]*a[34][0] - theta[0]*a[34][1] + theta1[0]*a[34][1] + a[34][2];

            a1[35][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[35][0] + theta[2]*a[35][1] - theta1[2]*a[35][1] - theta[1]*a[35][2] + theta1[1]*a[35][2];

            a1[35][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[35][0] + theta1[2]*a[35][0] + a[35][1] + theta[0]*a[35][2] - theta1[0]*a[35][2];

            a1[35][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[35][0] - theta1[1]*a[35][0] - theta[0]*a[35][1] + theta1[0]*a[35][1] + a[35][2];

            a1[36][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[36][0] + theta[2]*a[36][1] - theta1[2]*a[36][1] - theta[1]*a[36][2] + theta1[1]*a[36][2];

            a1[36][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[36][0] + theta1[2]*a[36][0] + a[36][1] + theta[0]*a[36][2] - theta1[0]*a[36][2];

            a1[36][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[36][0] - theta1[1]*a[36][0] - theta[0]*a[36][1] + theta1[0]*a[36][1] + a[36][2];

            a1[37][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[37][0] + theta[2]*a[37][1] - theta1[2]*a[37][1] - theta[1]*a[37][2] + theta1[1]*a[37][2];

            a1[37][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[37][0] + theta1[2]*a[37][0] + a[37][1] + theta[0]*a[37][2] - theta1[0]*a[37][2];

            a1[37][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[37][0] - theta1[1]*a[37][0] - theta[0]*a[37][1] + theta1[0]*a[37][1] + a[37][2];

            a1[38][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[38][0] + theta[2]*a[38][1] - theta1[2]*a[38][1] - theta[1]*a[38][2] + theta1[1]*a[38][2];

            a1[38][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[38][0] + theta1[2]*a[38][0] + a[38][1] + theta[0]*a[38][2] - theta1[0]*a[38][2];

            a1[38][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[38][0] - theta1[1]*a[38][0] - theta[0]*a[38][1] + theta1[0]*a[38][1] + a[38][2];

            a1[39][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[39][0] + theta[2]*a[39][1] - theta1[2]*a[39][1] - theta[1]*a[39][2] + theta1[1]*a[39][2];

            a1[39][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[39][0] + theta1[2]*a[39][0] + a[39][1] + theta[0]*a[39][2] - theta1[0]*a[39][2];

            a1[39][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[39][0] - theta1[1]*a[39][0] - theta[0]*a[39][1] + theta1[0]*a[39][1] + a[39][2];

            a1[40][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[40][0] + theta[2]*a[40][1] - theta1[2]*a[40][1] - theta[1]*a[40][2] + theta1[1]*a[40][2];

            a1[40][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[40][0] + theta1[2]*a[40][0] + a[40][1] + theta[0]*a[40][2] - theta1[0]*a[40][2];

            a1[40][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[40][0] - theta1[1]*a[40][0] - theta[0]*a[40][1] + theta1[0]*a[40][1] + a[40][2];

            a1[41][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[41][0] + theta[2]*a[41][1] - theta1[2]*a[41][1] - theta[1]*a[41][2] + theta1[1]*a[41][2];

            a1[41][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[41][0] + theta1[2]*a[41][0] + a[41][1] + theta[0]*a[41][2] - theta1[0]*a[41][2];

            a1[41][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[41][0] - theta1[1]*a[41][0] - theta[0]*a[41][1] + theta1[0]*a[41][1] + a[41][2];

            a1[42][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[42][0] + theta[2]*a[42][1] - theta1[2]*a[42][1] - theta[1]*a[42][2] + theta1[1]*a[42][2];

            a1[42][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[42][0] + theta1[2]*a[42][0] + a[42][1] + theta[0]*a[42][2] - theta1[0]*a[42][2];

            a1[42][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[42][0] - theta1[1]*a[42][0] - theta[0]*a[42][1] + theta1[0]*a[42][1] + a[42][2];

            a1[43][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[43][0] + theta[2]*a[43][1] - theta1[2]*a[43][1] - theta[1]*a[43][2] + theta1[1]*a[43][2];

            a1[43][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[43][0] + theta1[2]*a[43][0] + a[43][1] + theta[0]*a[43][2] - theta1[0]*a[43][2];

            a1[43][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[43][0] - theta1[1]*a[43][0] - theta[0]*a[43][1] + theta1[0]*a[43][1] + a[43][2];

            a1[44][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[44][0] + theta[2]*a[44][1] - theta1[2]*a[44][1] - theta[1]*a[44][2] + theta1[1]*a[44][2];

            a1[44][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[44][0] + theta1[2]*a[44][0] + a[44][1] + theta[0]*a[44][2] - theta1[0]*a[44][2];

            a1[44][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[44][0] - theta1[1]*a[44][0] - theta[0]*a[44][1] + theta1[0]*a[44][1] + a[44][2];

            a1[45][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[45][0] + theta[2]*a[45][1] - theta1[2]*a[45][1] - theta[1]*a[45][2] + theta1[1]*a[45][2];

            a1[45][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[45][0] + theta1[2]*a[45][0] + a[45][1] + theta[0]*a[45][2] - theta1[0]*a[45][2];

            a1[45][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[45][0] - theta1[1]*a[45][0] - theta[0]*a[45][1] + theta1[0]*a[45][1] + a[45][2];

            a1[46][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[46][0] + theta[2]*a[46][1] - theta1[2]*a[46][1] - theta[1]*a[46][2] + theta1[1]*a[46][2];

            a1[46][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[46][0] + theta1[2]*a[46][0] + a[46][1] + theta[0]*a[46][2] - theta1[0]*a[46][2];

            a1[46][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[46][0] - theta1[1]*a[46][0] - theta[0]*a[46][1] + theta1[0]*a[46][1] + a[46][2];

            a1[47][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[47][0] + theta[2]*a[47][1] - theta1[2]*a[47][1] - theta[1]*a[47][2] + theta1[1]*a[47][2];

            a1[47][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[47][0] + theta1[2]*a[47][0] + a[47][1] + theta[0]*a[47][2] - theta1[0]*a[47][2];

            a1[47][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[47][0] - theta1[1]*a[47][0] - theta[0]*a[47][1] + theta1[0]*a[47][1] + a[47][2];

            a1[48][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[48][0] + theta[2]*a[48][1] - theta1[2]*a[48][1] - theta[1]*a[48][2] + theta1[1]*a[48][2];

            a1[48][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[48][0] + theta1[2]*a[48][0] + a[48][1] + theta[0]*a[48][2] - theta1[0]*a[48][2];

            a1[48][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[48][0] - theta1[1]*a[48][0] - theta[0]*a[48][1] + theta1[0]*a[48][1] + a[48][2];

            a1[49][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[49][0] + theta[2]*a[49][1] - theta1[2]*a[49][1] - theta[1]*a[49][2] + theta1[1]*a[49][2];

            a1[49][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[49][0] + theta1[2]*a[49][0] + a[49][1] + theta[0]*a[49][2] - theta1[0]*a[49][2];

            a1[49][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[49][0] - theta1[1]*a[49][0] - theta[0]*a[49][1] + theta1[0]*a[49][1] + a[49][2];

            a1[50][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[50][0] + theta[2]*a[50][1] - theta1[2]*a[50][1] - theta[1]*a[50][2] + theta1[1]*a[50][2];

            a1[50][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[50][0] + theta1[2]*a[50][0] + a[50][1] + theta[0]*a[50][2] - theta1[0]*a[50][2];

            a1[50][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[50][0] - theta1[1]*a[50][0] - theta[0]*a[50][1] + theta1[0]*a[50][1] + a[50][2];

            break;

        case 61:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmRadial[10][0] + FmRadial[11][0] + FmRadial[12][0] + FmRadial[13][0] + FmRadial[14][0] + FmRadial[15][0] + FmRadial[16][0] + FmRadial[17][0] + FmRadial[18][0] + FmRadial[19][0] + FmRadial[20][0] + FmRadial[21][0] + FmRadial[22][0] + FmRadial[23][0] + FmRadial[24][0] + FmRadial[25][0] + FmRadial[26][0] + FmRadial[27][0] + FmRadial[28][0] + FmRadial[29][0] + FmRadial[30][0] + FmRadial[31][0] + FmRadial[32][0] + FmRadial[33][0] + FmRadial[34][0] + FmRadial[35][0] + FmRadial[36][0] + FmRadial[37][0] + FmRadial[38][0] + FmRadial[39][0] + FmRadial[40][0] + FmRadial[41][0] + FmRadial[42][0] + FmRadial[43][0] + FmRadial[44][0] + FmRadial[45][0] + FmRadial[46][0] + FmRadial[47][0] + FmRadial[48][0] + FmRadial[49][0] + FmRadial[50][0] + FmRadial[51][0] + FmRadial[52][0] + FmRadial[53][0] + FmRadial[54][0] + FmRadial[55][0] + FmRadial[56][0] + FmRadial[57][0] + FmRadial[58][0] + FmRadial[59][0] + FmRadial[60][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0] + FmTangential[41][0] + FmTangential[42][0] + FmTangential[43][0] + FmTangential[44][0] + FmTangential[45][0] + FmTangential[46][0] + FmTangential[47][0] + FmTangential[48][0] + FmTangential[49][0] + FmTangential[50][0] + FmTangential[51][0] + FmTangential[52][0] + FmTangential[53][0] + FmTangential[54][0] + FmTangential[55][0] + FmTangential[56][0] + FmTangential[57][0] + FmTangential[58][0] + FmTangential[59][0] + FmTangential[60][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmRadial[10][1] + FmRadial[11][1] + FmRadial[12][1] + FmRadial[13][1] + FmRadial[14][1] + FmRadial[15][1] + FmRadial[16][1] + FmRadial[17][1] + FmRadial[18][1] + FmRadial[19][1] + FmRadial[20][1] + FmRadial[21][1] + FmRadial[22][1] + FmRadial[23][1] + FmRadial[24][1] + FmRadial[25][1] + FmRadial[26][1] + FmRadial[27][1] + FmRadial[28][1] + FmRadial[29][1] + FmRadial[30][1] + FmRadial[31][1] + FmRadial[32][1] + FmRadial[33][1] + FmRadial[34][1] + FmRadial[35][1] + FmRadial[36][1] + FmRadial[37][1] + FmRadial[38][1] + FmRadial[39][1] + FmRadial[40][1] + FmRadial[41][1] + FmRadial[42][1] + FmRadial[43][1] + FmRadial[44][1] + FmRadial[45][1] + FmRadial[46][1] + FmRadial[47][1] + FmRadial[48][1] + FmRadial[49][1] + FmRadial[50][1] + FmRadial[51][1] + FmRadial[52][1] + FmRadial[53][1] + FmRadial[54][1] + FmRadial[55][1] + FmRadial[56][1] + FmRadial[57][1] + FmRadial[58][1] + FmRadial[59][1] + FmRadial[60][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1] + FmTangential[19][1] + FmTangential[20][1] + FmTangential[21][1] + FmTangential[22][1] + FmTangential[23][1] + FmTangential[24][1] + FmTangential[25][1] + FmTangential[26][1] + FmTangential[27][1] + FmTangential[28][1] + FmTangential[29][1] + FmTangential[30][1] + FmTangential[31][1] + FmTangential[32][1] + FmTangential[33][1] + FmTangential[34][1] + FmTangential[35][1] + FmTangential[36][1] + FmTangential[37][1] + FmTangential[38][1] + FmTangential[39][1] + FmTangential[40][1] + FmTangential[41][1] + FmTangential[42][1] + FmTangential[43][1] + FmTangential[44][1] + FmTangential[45][1] + FmTangential[46][1] + FmTangential[47][1] + FmTangential[48][1] + FmTangential[49][1] + FmTangential[50][1] + FmTangential[51][1] + FmTangential[52][1] + FmTangential[53][1] + FmTangential[54][1] + FmTangential[55][1] + FmTangential[56][1] + FmTangential[57][1] + FmTangential[58][1] + FmTangential[59][1] + FmTangential[60][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmRadial[10][2] + FmRadial[11][2] + FmRadial[12][2] + FmRadial[13][2] + FmRadial[14][2] + FmRadial[15][2] + FmRadial[16][2] + FmRadial[17][2] + FmRadial[18][2] + FmRadial[19][2] + FmRadial[20][2] + FmRadial[21][2] + FmRadial[22][2] + FmRadial[23][2] + FmRadial[24][2] + FmRadial[25][2] + FmRadial[26][2] + FmRadial[27][2] + FmRadial[28][2] + FmRadial[29][2] + FmRadial[30][2] + FmRadial[31][2] + FmRadial[32][2] + FmRadial[33][2] + FmRadial[34][2] + FmRadial[35][2] + FmRadial[36][2] + FmRadial[37][2] + FmRadial[38][2] + FmRadial[39][2] + FmRadial[40][2] + FmRadial[41][2] + FmRadial[42][2] + FmRadial[43][2] + FmRadial[44][2] + FmRadial[45][2] + FmRadial[46][2] + FmRadial[47][2] + FmRadial[48][2] + FmRadial[49][2] + FmRadial[50][2] + FmRadial[51][2] + FmRadial[52][2] + FmRadial[53][2] + FmRadial[54][2] + FmRadial[55][2] + FmRadial[56][2] + FmRadial[57][2] + FmRadial[58][2] + FmRadial[59][2] + FmRadial[60][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2] + FmTangential[10][2] + FmTangential[11][2] + FmTangential[12][2] + FmTangential[13][2] + FmTangential[14][2] + FmTangential[15][2] + FmTangential[16][2] + FmTangential[17][2] + FmTangential[18][2] + FmTangential[19][2] + FmTangential[20][2] + FmTangential[21][2] + FmTangential[22][2] + FmTangential[23][2] + FmTangential[24][2] + FmTangential[25][2] + FmTangential[26][2] + FmTangential[27][2] + FmTangential[28][2] + FmTangential[29][2] + FmTangential[30][2] + FmTangential[31][2] + FmTangential[32][2] + FmTangential[33][2] + FmTangential[34][2] + FmTangential[35][2] + FmTangential[36][2] + FmTangential[37][2] + FmTangential[38][2] + FmTangential[39][2] + FmTangential[40][2] + FmTangential[41][2] + FmTangential[42][2] + FmTangential[43][2] + FmTangential[44][2] + FmTangential[45][2] + FmTangential[46][2] + FmTangential[47][2] + FmTangential[48][2] + FmTangential[49][2] + FmTangential[50][2] + FmTangential[51][2] + FmTangential[52][2] + FmTangential[53][2] + FmTangential[54][2] + FmTangential[55][2] + FmTangential[56][2] + FmTangential[57][2] + FmTangential[58][2] + FmTangential[59][2] + FmTangential[60][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2] - a[10][2]*FmTangential[10][1] - c[1]*FmTangential[10][2] + a[10][1]*FmTangential[10][2] - a[11][2]*FmTangential[11][1] - c[1]*FmTangential[11][2] + a[11][1]*FmTangential[11][2] - a[12][2]*FmTangential[12][1] - c[1]*FmTangential[12][2] + a[12][1]*FmTangential[12][2] - a[13][2]*FmTangential[13][1] - c[1]*FmTangential[13][2] + a[13][1]*FmTangential[13][2] - a[14][2]*FmTangential[14][1] - c[1]*FmTangential[14][2] + a[14][1]*FmTangential[14][2] - a[15][2]*FmTangential[15][1] - c[1]*FmTangential[15][2] + a[15][1]*FmTangential[15][2] - a[16][2]*FmTangential[16][1] - c[1]*FmTangential[16][2] + a[16][1]*FmTangential[16][2] - a[17][2]*FmTangential[17][1] - c[1]*FmTangential[17][2] + a[17][1]*FmTangential[17][2] - a[18][2]*FmTangential[18][1] - c[1]*FmTangential[18][2] + a[18][1]*FmTangential[18][2] - a[19][2]*FmTangential[19][1] - c[1]*FmTangential[19][2] + a[19][1]*FmTangential[19][2] - a[20][2]*FmTangential[20][1] - c[1]*FmTangential[20][2] + a[20][1]*FmTangential[20][2] - a[21][2]*FmTangential[21][1] - c[1]*FmTangential[21][2] + a[21][1]*FmTangential[21][2] - a[22][2]*FmTangential[22][1] - c[1]*FmTangential[22][2] + a[22][1]*FmTangential[22][2] - a[23][2]*FmTangential[23][1] - c[1]*FmTangential[23][2] + a[23][1]*FmTangential[23][2] - a[24][2]*FmTangential[24][1] - c[1]*FmTangential[24][2] + a[24][1]*FmTangential[24][2] - a[25][2]*FmTangential[25][1] - c[1]*FmTangential[25][2] + a[25][1]*FmTangential[25][2] - a[26][2]*FmTangential[26][1] - c[1]*FmTangential[26][2] + a[26][1]*FmTangential[26][2] - a[27][2]*FmTangential[27][1] - c[1]*FmTangential[27][2] + a[27][1]*FmTangential[27][2] - a[28][2]*FmTangential[28][1] - c[1]*FmTangential[28][2] + a[28][1]*FmTangential[28][2] - a[29][2]*FmTangential[29][1] - c[1]*FmTangential[29][2] + a[29][1]*FmTangential[29][2] - a[30][2]*FmTangential[30][1] - c[1]*FmTangential[30][2] + a[30][1]*FmTangential[30][2] - a[31][2]*FmTangential[31][1] - c[1]*FmTangential[31][2] + a[31][1]*FmTangential[31][2] - a[32][2]*FmTangential[32][1] - c[1]*FmTangential[32][2] + a[32][1]*FmTangential[32][2] - a[33][2]*FmTangential[33][1] - c[1]*FmTangential[33][2] + a[33][1]*FmTangential[33][2] - a[34][2]*FmTangential[34][1] - c[1]*FmTangential[34][2] + a[34][1]*FmTangential[34][2] - a[35][2]*FmTangential[35][1] - c[1]*FmTangential[35][2] + a[35][1]*FmTangential[35][2] - a[36][2]*FmTangential[36][1] - c[1]*FmTangential[36][2] + a[36][1]*FmTangential[36][2] - a[37][2]*FmTangential[37][1] - c[1]*FmTangential[37][2] + a[37][1]*FmTangential[37][2] - a[38][2]*FmTangential[38][1] - c[1]*FmTangential[38][2] + a[38][1]*FmTangential[38][2] - a[39][2]*FmTangential[39][1] - c[1]*FmTangential[39][2] + a[39][1]*FmTangential[39][2] - a[40][2]*FmTangential[40][1] - c[1]*FmTangential[40][2] + a[40][1]*FmTangential[40][2] - a[41][2]*FmTangential[41][1] - c[1]*FmTangential[41][2] + a[41][1]*FmTangential[41][2] - a[42][2]*FmTangential[42][1] - c[1]*FmTangential[42][2] + a[42][1]*FmTangential[42][2] - a[43][2]*FmTangential[43][1] - c[1]*FmTangential[43][2] + a[43][1]*FmTangential[43][2] - a[44][2]*FmTangential[44][1] - c[1]*FmTangential[44][2] + a[44][1]*FmTangential[44][2] - a[45][2]*FmTangential[45][1] - c[1]*FmTangential[45][2] + a[45][1]*FmTangential[45][2] - a[46][2]*FmTangential[46][1] - c[1]*FmTangential[46][2] + a[46][1]*FmTangential[46][2] - a[47][2]*FmTangential[47][1] - c[1]*FmTangential[47][2] + a[47][1]*FmTangential[47][2] - a[48][2]*FmTangential[48][1] - c[1]*FmTangential[48][2] + a[48][1]*FmTangential[48][2] - a[49][2]*FmTangential[49][1] - c[1]*FmTangential[49][2] + a[49][1]*FmTangential[49][2] - a[50][2]*FmTangential[50][1] - c[1]*FmTangential[50][2] + a[50][1]*FmTangential[50][2] - a[51][2]*FmTangential[51][1] - c[1]*FmTangential[51][2] + a[51][1]*FmTangential[51][2] - a[52][2]*FmTangential[52][1] - c[1]*FmTangential[52][2] + a[52][1]*FmTangential[52][2] - a[53][2]*FmTangential[53][1] - c[1]*FmTangential[53][2] + a[53][1]*FmTangential[53][2] - a[54][2]*FmTangential[54][1] - c[1]*FmTangential[54][2] + a[54][1]*FmTangential[54][2] - a[55][2]*FmTangential[55][1] - c[1]*FmTangential[55][2] + a[55][1]*FmTangential[55][2] - a[56][2]*FmTangential[56][1] - c[1]*FmTangential[56][2] + a[56][1]*FmTangential[56][2] - a[57][2]*FmTangential[57][1] - c[1]*FmTangential[57][2] + a[57][1]*FmTangential[57][2] - a[58][2]*FmTangential[58][1] - c[1]*FmTangential[58][2] + a[58][1]*FmTangential[58][2] - a[59][2]*FmTangential[59][1] - c[1]*FmTangential[59][2] + a[59][1]*FmTangential[59][2] - a[60][2]*FmTangential[60][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1] + FmTangential[19][1] + FmTangential[20][1] + FmTangential[21][1] + FmTangential[22][1] + FmTangential[23][1] + FmTangential[24][1] + FmTangential[25][1] + FmTangential[26][1] + FmTangential[27][1] + FmTangential[28][1] + FmTangential[29][1] + FmTangential[30][1] + FmTangential[31][1] + FmTangential[32][1] + FmTangential[33][1] + FmTangential[34][1] + FmTangential[35][1] + FmTangential[36][1] + FmTangential[37][1] + FmTangential[38][1] + FmTangential[39][1] + FmTangential[40][1] + FmTangential[41][1] + FmTangential[42][1] + FmTangential[43][1] + FmTangential[44][1] + FmTangential[45][1] + FmTangential[46][1] + FmTangential[47][1] + FmTangential[48][1] + FmTangential[49][1] + FmTangential[50][1] + FmTangential[51][1] + FmTangential[52][1] + FmTangential[53][1] + FmTangential[54][1] + FmTangential[55][1] + FmTangential[56][1] + FmTangential[57][1] + FmTangential[58][1] + FmTangential[59][1] + FmTangential[60][1]) - c[1]*FmTangential[60][2] + a[60][1]*FmTangential[60][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2] + a[10][2]*FmTangential[10][0] + c[0]*FmTangential[10][2] - a[10][0]*FmTangential[10][2] + a[11][2]*FmTangential[11][0] + c[0]*FmTangential[11][2] - a[11][0]*FmTangential[11][2] + a[12][2]*FmTangential[12][0] + c[0]*FmTangential[12][2] - a[12][0]*FmTangential[12][2] + a[13][2]*FmTangential[13][0] + c[0]*FmTangential[13][2] - a[13][0]*FmTangential[13][2] + a[14][2]*FmTangential[14][0] + c[0]*FmTangential[14][2] - a[14][0]*FmTangential[14][2] + a[15][2]*FmTangential[15][0] + c[0]*FmTangential[15][2] - a[15][0]*FmTangential[15][2] + a[16][2]*FmTangential[16][0] + c[0]*FmTangential[16][2] - a[16][0]*FmTangential[16][2] + a[17][2]*FmTangential[17][0] + c[0]*FmTangential[17][2] - a[17][0]*FmTangential[17][2] + a[18][2]*FmTangential[18][0] + c[0]*FmTangential[18][2] - a[18][0]*FmTangential[18][2] + a[19][2]*FmTangential[19][0] + c[0]*FmTangential[19][2] - a[19][0]*FmTangential[19][2] + a[20][2]*FmTangential[20][0] + c[0]*FmTangential[20][2] - a[20][0]*FmTangential[20][2] + a[21][2]*FmTangential[21][0] + c[0]*FmTangential[21][2] - a[21][0]*FmTangential[21][2] + a[22][2]*FmTangential[22][0] + c[0]*FmTangential[22][2] - a[22][0]*FmTangential[22][2] + a[23][2]*FmTangential[23][0] + c[0]*FmTangential[23][2] - a[23][0]*FmTangential[23][2] + a[24][2]*FmTangential[24][0] + c[0]*FmTangential[24][2] - a[24][0]*FmTangential[24][2] + a[25][2]*FmTangential[25][0] + c[0]*FmTangential[25][2] - a[25][0]*FmTangential[25][2] + a[26][2]*FmTangential[26][0] + c[0]*FmTangential[26][2] - a[26][0]*FmTangential[26][2] + a[27][2]*FmTangential[27][0] + c[0]*FmTangential[27][2] - a[27][0]*FmTangential[27][2] + a[28][2]*FmTangential[28][0] + c[0]*FmTangential[28][2] - a[28][0]*FmTangential[28][2] + a[29][2]*FmTangential[29][0] + c[0]*FmTangential[29][2] - a[29][0]*FmTangential[29][2] + a[30][2]*FmTangential[30][0] + c[0]*FmTangential[30][2] - a[30][0]*FmTangential[30][2] + a[31][2]*FmTangential[31][0] + c[0]*FmTangential[31][2] - a[31][0]*FmTangential[31][2] + a[32][2]*FmTangential[32][0] + c[0]*FmTangential[32][2] - a[32][0]*FmTangential[32][2] + a[33][2]*FmTangential[33][0] + c[0]*FmTangential[33][2] - a[33][0]*FmTangential[33][2] + a[34][2]*FmTangential[34][0] + c[0]*FmTangential[34][2] - a[34][0]*FmTangential[34][2] + a[35][2]*FmTangential[35][0] + c[0]*FmTangential[35][2] - a[35][0]*FmTangential[35][2] + a[36][2]*FmTangential[36][0] + c[0]*FmTangential[36][2] - a[36][0]*FmTangential[36][2] + a[37][2]*FmTangential[37][0] + c[0]*FmTangential[37][2] - a[37][0]*FmTangential[37][2] + a[38][2]*FmTangential[38][0] + c[0]*FmTangential[38][2] - a[38][0]*FmTangential[38][2] + a[39][2]*FmTangential[39][0] + c[0]*FmTangential[39][2] - a[39][0]*FmTangential[39][2] + a[40][2]*FmTangential[40][0] + c[0]*FmTangential[40][2] - a[40][0]*FmTangential[40][2] + a[41][2]*FmTangential[41][0] + c[0]*FmTangential[41][2] - a[41][0]*FmTangential[41][2] + a[42][2]*FmTangential[42][0] + c[0]*FmTangential[42][2] - a[42][0]*FmTangential[42][2] + a[43][2]*FmTangential[43][0] + c[0]*FmTangential[43][2] - a[43][0]*FmTangential[43][2] + a[44][2]*FmTangential[44][0] + c[0]*FmTangential[44][2] - a[44][0]*FmTangential[44][2] + a[45][2]*FmTangential[45][0] + c[0]*FmTangential[45][2] - a[45][0]*FmTangential[45][2] + a[46][2]*FmTangential[46][0] + c[0]*FmTangential[46][2] - a[46][0]*FmTangential[46][2] + a[47][2]*FmTangential[47][0] + c[0]*FmTangential[47][2] - a[47][0]*FmTangential[47][2] + a[48][2]*FmTangential[48][0] + c[0]*FmTangential[48][2] - a[48][0]*FmTangential[48][2] + a[49][2]*FmTangential[49][0] + c[0]*FmTangential[49][2] - a[49][0]*FmTangential[49][2] + a[50][2]*FmTangential[50][0] + c[0]*FmTangential[50][2] - a[50][0]*FmTangential[50][2] + a[51][2]*FmTangential[51][0] + c[0]*FmTangential[51][2] - a[51][0]*FmTangential[51][2] + a[52][2]*FmTangential[52][0] + c[0]*FmTangential[52][2] - a[52][0]*FmTangential[52][2] + a[53][2]*FmTangential[53][0] + c[0]*FmTangential[53][2] - a[53][0]*FmTangential[53][2] + a[54][2]*FmTangential[54][0] + c[0]*FmTangential[54][2] - a[54][0]*FmTangential[54][2] + a[55][2]*FmTangential[55][0] + c[0]*FmTangential[55][2] - a[55][0]*FmTangential[55][2] + a[56][2]*FmTangential[56][0] + c[0]*FmTangential[56][2] - a[56][0]*FmTangential[56][2] + a[57][2]*FmTangential[57][0] + c[0]*FmTangential[57][2] - a[57][0]*FmTangential[57][2] + a[58][2]*FmTangential[58][0] + c[0]*FmTangential[58][2] - a[58][0]*FmTangential[58][2] + a[59][2]*FmTangential[59][0] + c[0]*FmTangential[59][2] - a[59][0]*FmTangential[59][2] + a[60][2]*FmTangential[60][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0] + FmTangential[41][0] + FmTangential[42][0] + FmTangential[43][0] + FmTangential[44][0] + FmTangential[45][0] + FmTangential[46][0] + FmTangential[47][0] + FmTangential[48][0] + FmTangential[49][0] + FmTangential[50][0] + FmTangential[51][0] + FmTangential[52][0] + FmTangential[53][0] + FmTangential[54][0] + FmTangential[55][0] + FmTangential[56][0] + FmTangential[57][0] + FmTangential[58][0] + FmTangential[59][0] + FmTangential[60][0]) + c[0]*FmTangential[60][2] - a[60][0]*FmTangential[60][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1] - a[10][1]*FmTangential[10][0] - c[0]*FmTangential[10][1] + a[10][0]*FmTangential[10][1] - a[11][1]*FmTangential[11][0] - c[0]*FmTangential[11][1] + a[11][0]*FmTangential[11][1] - a[12][1]*FmTangential[12][0] - c[0]*FmTangential[12][1] + a[12][0]*FmTangential[12][1] - a[13][1]*FmTangential[13][0] - c[0]*FmTangential[13][1] + a[13][0]*FmTangential[13][1] - a[14][1]*FmTangential[14][0] - c[0]*FmTangential[14][1] + a[14][0]*FmTangential[14][1] - a[15][1]*FmTangential[15][0] - c[0]*FmTangential[15][1] + a[15][0]*FmTangential[15][1] - a[16][1]*FmTangential[16][0] - c[0]*FmTangential[16][1] + a[16][0]*FmTangential[16][1] - a[17][1]*FmTangential[17][0] - c[0]*FmTangential[17][1] + a[17][0]*FmTangential[17][1] - a[18][1]*FmTangential[18][0] - c[0]*FmTangential[18][1] + a[18][0]*FmTangential[18][1] - a[19][1]*FmTangential[19][0] - c[0]*FmTangential[19][1] + a[19][0]*FmTangential[19][1] - a[20][1]*FmTangential[20][0] - c[0]*FmTangential[20][1] + a[20][0]*FmTangential[20][1] - a[21][1]*FmTangential[21][0] - c[0]*FmTangential[21][1] + a[21][0]*FmTangential[21][1] - a[22][1]*FmTangential[22][0] - c[0]*FmTangential[22][1] + a[22][0]*FmTangential[22][1] - a[23][1]*FmTangential[23][0] - c[0]*FmTangential[23][1] + a[23][0]*FmTangential[23][1] - a[24][1]*FmTangential[24][0] - c[0]*FmTangential[24][1] + a[24][0]*FmTangential[24][1] - a[25][1]*FmTangential[25][0] - c[0]*FmTangential[25][1] + a[25][0]*FmTangential[25][1] - a[26][1]*FmTangential[26][0] - c[0]*FmTangential[26][1] + a[26][0]*FmTangential[26][1] - a[27][1]*FmTangential[27][0] - c[0]*FmTangential[27][1] + a[27][0]*FmTangential[27][1] - a[28][1]*FmTangential[28][0] - c[0]*FmTangential[28][1] + a[28][0]*FmTangential[28][1] - a[29][1]*FmTangential[29][0] - c[0]*FmTangential[29][1] + a[29][0]*FmTangential[29][1] - a[30][1]*FmTangential[30][0] - c[0]*FmTangential[30][1] + a[30][0]*FmTangential[30][1] - a[31][1]*FmTangential[31][0] - c[0]*FmTangential[31][1] + a[31][0]*FmTangential[31][1] - a[32][1]*FmTangential[32][0] - c[0]*FmTangential[32][1] + a[32][0]*FmTangential[32][1] - a[33][1]*FmTangential[33][0] - c[0]*FmTangential[33][1] + a[33][0]*FmTangential[33][1] - a[34][1]*FmTangential[34][0] - c[0]*FmTangential[34][1] + a[34][0]*FmTangential[34][1] - a[35][1]*FmTangential[35][0] - c[0]*FmTangential[35][1] + a[35][0]*FmTangential[35][1] - a[36][1]*FmTangential[36][0] - c[0]*FmTangential[36][1] + a[36][0]*FmTangential[36][1] - a[37][1]*FmTangential[37][0] - c[0]*FmTangential[37][1] + a[37][0]*FmTangential[37][1] - a[38][1]*FmTangential[38][0] - c[0]*FmTangential[38][1] + a[38][0]*FmTangential[38][1] - a[39][1]*FmTangential[39][0] - c[0]*FmTangential[39][1] + a[39][0]*FmTangential[39][1] - a[40][1]*FmTangential[40][0] - c[0]*FmTangential[40][1] + a[40][0]*FmTangential[40][1] - a[41][1]*FmTangential[41][0] - c[0]*FmTangential[41][1] + a[41][0]*FmTangential[41][1] - a[42][1]*FmTangential[42][0] - c[0]*FmTangential[42][1] + a[42][0]*FmTangential[42][1] - a[43][1]*FmTangential[43][0] - c[0]*FmTangential[43][1] + a[43][0]*FmTangential[43][1] - a[44][1]*FmTangential[44][0] - c[0]*FmTangential[44][1] + a[44][0]*FmTangential[44][1] - a[45][1]*FmTangential[45][0] - c[0]*FmTangential[45][1] + a[45][0]*FmTangential[45][1] - a[46][1]*FmTangential[46][0] - c[0]*FmTangential[46][1] + a[46][0]*FmTangential[46][1] - a[47][1]*FmTangential[47][0] - c[0]*FmTangential[47][1] + a[47][0]*FmTangential[47][1] - a[48][1]*FmTangential[48][0] - c[0]*FmTangential[48][1] + a[48][0]*FmTangential[48][1] - a[49][1]*FmTangential[49][0] - c[0]*FmTangential[49][1] + a[49][0]*FmTangential[49][1] - a[50][1]*FmTangential[50][0] - c[0]*FmTangential[50][1] + a[50][0]*FmTangential[50][1] - a[51][1]*FmTangential[51][0] - c[0]*FmTangential[51][1] + a[51][0]*FmTangential[51][1] - a[52][1]*FmTangential[52][0] - c[0]*FmTangential[52][1] + a[52][0]*FmTangential[52][1] - a[53][1]*FmTangential[53][0] - c[0]*FmTangential[53][1] + a[53][0]*FmTangential[53][1] - a[54][1]*FmTangential[54][0] - c[0]*FmTangential[54][1] + a[54][0]*FmTangential[54][1] - a[55][1]*FmTangential[55][0] - c[0]*FmTangential[55][1] + a[55][0]*FmTangential[55][1] - a[56][1]*FmTangential[56][0] - c[0]*FmTangential[56][1] + a[56][0]*FmTangential[56][1] - a[57][1]*FmTangential[57][0] - c[0]*FmTangential[57][1] + a[57][0]*FmTangential[57][1] - a[58][1]*FmTangential[58][0] - c[0]*FmTangential[58][1] + a[58][0]*FmTangential[58][1] - a[59][1]*FmTangential[59][0] - c[0]*FmTangential[59][1] + a[59][0]*FmTangential[59][1] - a[60][1]*FmTangential[60][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0] + FmTangential[41][0] + FmTangential[42][0] + FmTangential[43][0] + FmTangential[44][0] + FmTangential[45][0] + FmTangential[46][0] + FmTangential[47][0] + FmTangential[48][0] + FmTangential[49][0] + FmTangential[50][0] + FmTangential[51][0] + FmTangential[52][0] + FmTangential[53][0] + FmTangential[54][0] + FmTangential[55][0] + FmTangential[56][0] + FmTangential[57][0] + FmTangential[58][0] + FmTangential[59][0] + FmTangential[60][0]) - c[0]*FmTangential[60][1] + a[60][0]*FmTangential[60][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            a1[10][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[10][0] + theta[2]*a[10][1] - theta1[2]*a[10][1] - theta[1]*a[10][2] + theta1[1]*a[10][2];

            a1[10][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[10][0] + theta1[2]*a[10][0] + a[10][1] + theta[0]*a[10][2] - theta1[0]*a[10][2];

            a1[10][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[10][0] - theta1[1]*a[10][0] - theta[0]*a[10][1] + theta1[0]*a[10][1] + a[10][2];

            a1[11][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[11][0] + theta[2]*a[11][1] - theta1[2]*a[11][1] - theta[1]*a[11][2] + theta1[1]*a[11][2];

            a1[11][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[11][0] + theta1[2]*a[11][0] + a[11][1] + theta[0]*a[11][2] - theta1[0]*a[11][2];

            a1[11][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[11][0] - theta1[1]*a[11][0] - theta[0]*a[11][1] + theta1[0]*a[11][1] + a[11][2];

            a1[12][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[12][0] + theta[2]*a[12][1] - theta1[2]*a[12][1] - theta[1]*a[12][2] + theta1[1]*a[12][2];

            a1[12][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[12][0] + theta1[2]*a[12][0] + a[12][1] + theta[0]*a[12][2] - theta1[0]*a[12][2];

            a1[12][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[12][0] - theta1[1]*a[12][0] - theta[0]*a[12][1] + theta1[0]*a[12][1] + a[12][2];

            a1[13][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[13][0] + theta[2]*a[13][1] - theta1[2]*a[13][1] - theta[1]*a[13][2] + theta1[1]*a[13][2];

            a1[13][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[13][0] + theta1[2]*a[13][0] + a[13][1] + theta[0]*a[13][2] - theta1[0]*a[13][2];

            a1[13][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[13][0] - theta1[1]*a[13][0] - theta[0]*a[13][1] + theta1[0]*a[13][1] + a[13][2];

            a1[14][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[14][0] + theta[2]*a[14][1] - theta1[2]*a[14][1] - theta[1]*a[14][2] + theta1[1]*a[14][2];

            a1[14][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[14][0] + theta1[2]*a[14][0] + a[14][1] + theta[0]*a[14][2] - theta1[0]*a[14][2];

            a1[14][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[14][0] - theta1[1]*a[14][0] - theta[0]*a[14][1] + theta1[0]*a[14][1] + a[14][2];

            a1[15][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[15][0] + theta[2]*a[15][1] - theta1[2]*a[15][1] - theta[1]*a[15][2] + theta1[1]*a[15][2];

            a1[15][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[15][0] + theta1[2]*a[15][0] + a[15][1] + theta[0]*a[15][2] - theta1[0]*a[15][2];

            a1[15][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[15][0] - theta1[1]*a[15][0] - theta[0]*a[15][1] + theta1[0]*a[15][1] + a[15][2];

            a1[16][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[16][0] + theta[2]*a[16][1] - theta1[2]*a[16][1] - theta[1]*a[16][2] + theta1[1]*a[16][2];

            a1[16][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[16][0] + theta1[2]*a[16][0] + a[16][1] + theta[0]*a[16][2] - theta1[0]*a[16][2];

            a1[16][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[16][0] - theta1[1]*a[16][0] - theta[0]*a[16][1] + theta1[0]*a[16][1] + a[16][2];

            a1[17][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[17][0] + theta[2]*a[17][1] - theta1[2]*a[17][1] - theta[1]*a[17][2] + theta1[1]*a[17][2];

            a1[17][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[17][0] + theta1[2]*a[17][0] + a[17][1] + theta[0]*a[17][2] - theta1[0]*a[17][2];

            a1[17][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[17][0] - theta1[1]*a[17][0] - theta[0]*a[17][1] + theta1[0]*a[17][1] + a[17][2];

            a1[18][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[18][0] + theta[2]*a[18][1] - theta1[2]*a[18][1] - theta[1]*a[18][2] + theta1[1]*a[18][2];

            a1[18][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[18][0] + theta1[2]*a[18][0] + a[18][1] + theta[0]*a[18][2] - theta1[0]*a[18][2];

            a1[18][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[18][0] - theta1[1]*a[18][0] - theta[0]*a[18][1] + theta1[0]*a[18][1] + a[18][2];

            a1[19][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[19][0] + theta[2]*a[19][1] - theta1[2]*a[19][1] - theta[1]*a[19][2] + theta1[1]*a[19][2];

            a1[19][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[19][0] + theta1[2]*a[19][0] + a[19][1] + theta[0]*a[19][2] - theta1[0]*a[19][2];

            a1[19][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[19][0] - theta1[1]*a[19][0] - theta[0]*a[19][1] + theta1[0]*a[19][1] + a[19][2];

            a1[20][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[20][0] + theta[2]*a[20][1] - theta1[2]*a[20][1] - theta[1]*a[20][2] + theta1[1]*a[20][2];

            a1[20][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[20][0] + theta1[2]*a[20][0] + a[20][1] + theta[0]*a[20][2] - theta1[0]*a[20][2];

            a1[20][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[20][0] - theta1[1]*a[20][0] - theta[0]*a[20][1] + theta1[0]*a[20][1] + a[20][2];

            a1[21][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[21][0] + theta[2]*a[21][1] - theta1[2]*a[21][1] - theta[1]*a[21][2] + theta1[1]*a[21][2];

            a1[21][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[21][0] + theta1[2]*a[21][0] + a[21][1] + theta[0]*a[21][2] - theta1[0]*a[21][2];

            a1[21][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[21][0] - theta1[1]*a[21][0] - theta[0]*a[21][1] + theta1[0]*a[21][1] + a[21][2];

            a1[22][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[22][0] + theta[2]*a[22][1] - theta1[2]*a[22][1] - theta[1]*a[22][2] + theta1[1]*a[22][2];

            a1[22][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[22][0] + theta1[2]*a[22][0] + a[22][1] + theta[0]*a[22][2] - theta1[0]*a[22][2];

            a1[22][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[22][0] - theta1[1]*a[22][0] - theta[0]*a[22][1] + theta1[0]*a[22][1] + a[22][2];

            a1[23][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[23][0] + theta[2]*a[23][1] - theta1[2]*a[23][1] - theta[1]*a[23][2] + theta1[1]*a[23][2];

            a1[23][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[23][0] + theta1[2]*a[23][0] + a[23][1] + theta[0]*a[23][2] - theta1[0]*a[23][2];

            a1[23][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[23][0] - theta1[1]*a[23][0] - theta[0]*a[23][1] + theta1[0]*a[23][1] + a[23][2];

            a1[24][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[24][0] + theta[2]*a[24][1] - theta1[2]*a[24][1] - theta[1]*a[24][2] + theta1[1]*a[24][2];

            a1[24][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[24][0] + theta1[2]*a[24][0] + a[24][1] + theta[0]*a[24][2] - theta1[0]*a[24][2];

            a1[24][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[24][0] - theta1[1]*a[24][0] - theta[0]*a[24][1] + theta1[0]*a[24][1] + a[24][2];

            a1[25][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[25][0] + theta[2]*a[25][1] - theta1[2]*a[25][1] - theta[1]*a[25][2] + theta1[1]*a[25][2];

            a1[25][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[25][0] + theta1[2]*a[25][0] + a[25][1] + theta[0]*a[25][2] - theta1[0]*a[25][2];

            a1[25][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[25][0] - theta1[1]*a[25][0] - theta[0]*a[25][1] + theta1[0]*a[25][1] + a[25][2];

            a1[26][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[26][0] + theta[2]*a[26][1] - theta1[2]*a[26][1] - theta[1]*a[26][2] + theta1[1]*a[26][2];

            a1[26][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[26][0] + theta1[2]*a[26][0] + a[26][1] + theta[0]*a[26][2] - theta1[0]*a[26][2];

            a1[26][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[26][0] - theta1[1]*a[26][0] - theta[0]*a[26][1] + theta1[0]*a[26][1] + a[26][2];

            a1[27][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[27][0] + theta[2]*a[27][1] - theta1[2]*a[27][1] - theta[1]*a[27][2] + theta1[1]*a[27][2];

            a1[27][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[27][0] + theta1[2]*a[27][0] + a[27][1] + theta[0]*a[27][2] - theta1[0]*a[27][2];

            a1[27][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[27][0] - theta1[1]*a[27][0] - theta[0]*a[27][1] + theta1[0]*a[27][1] + a[27][2];

            a1[28][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[28][0] + theta[2]*a[28][1] - theta1[2]*a[28][1] - theta[1]*a[28][2] + theta1[1]*a[28][2];

            a1[28][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[28][0] + theta1[2]*a[28][0] + a[28][1] + theta[0]*a[28][2] - theta1[0]*a[28][2];

            a1[28][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[28][0] - theta1[1]*a[28][0] - theta[0]*a[28][1] + theta1[0]*a[28][1] + a[28][2];

            a1[29][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[29][0] + theta[2]*a[29][1] - theta1[2]*a[29][1] - theta[1]*a[29][2] + theta1[1]*a[29][2];

            a1[29][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[29][0] + theta1[2]*a[29][0] + a[29][1] + theta[0]*a[29][2] - theta1[0]*a[29][2];

            a1[29][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[29][0] - theta1[1]*a[29][0] - theta[0]*a[29][1] + theta1[0]*a[29][1] + a[29][2];

            a1[30][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[30][0] + theta[2]*a[30][1] - theta1[2]*a[30][1] - theta[1]*a[30][2] + theta1[1]*a[30][2];

            a1[30][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[30][0] + theta1[2]*a[30][0] + a[30][1] + theta[0]*a[30][2] - theta1[0]*a[30][2];

            a1[30][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[30][0] - theta1[1]*a[30][0] - theta[0]*a[30][1] + theta1[0]*a[30][1] + a[30][2];

            a1[31][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[31][0] + theta[2]*a[31][1] - theta1[2]*a[31][1] - theta[1]*a[31][2] + theta1[1]*a[31][2];

            a1[31][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[31][0] + theta1[2]*a[31][0] + a[31][1] + theta[0]*a[31][2] - theta1[0]*a[31][2];

            a1[31][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[31][0] - theta1[1]*a[31][0] - theta[0]*a[31][1] + theta1[0]*a[31][1] + a[31][2];

            a1[32][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[32][0] + theta[2]*a[32][1] - theta1[2]*a[32][1] - theta[1]*a[32][2] + theta1[1]*a[32][2];

            a1[32][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[32][0] + theta1[2]*a[32][0] + a[32][1] + theta[0]*a[32][2] - theta1[0]*a[32][2];

            a1[32][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[32][0] - theta1[1]*a[32][0] - theta[0]*a[32][1] + theta1[0]*a[32][1] + a[32][2];

            a1[33][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[33][0] + theta[2]*a[33][1] - theta1[2]*a[33][1] - theta[1]*a[33][2] + theta1[1]*a[33][2];

            a1[33][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[33][0] + theta1[2]*a[33][0] + a[33][1] + theta[0]*a[33][2] - theta1[0]*a[33][2];

            a1[33][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[33][0] - theta1[1]*a[33][0] - theta[0]*a[33][1] + theta1[0]*a[33][1] + a[33][2];

            a1[34][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[34][0] + theta[2]*a[34][1] - theta1[2]*a[34][1] - theta[1]*a[34][2] + theta1[1]*a[34][2];

            a1[34][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[34][0] + theta1[2]*a[34][0] + a[34][1] + theta[0]*a[34][2] - theta1[0]*a[34][2];

            a1[34][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[34][0] - theta1[1]*a[34][0] - theta[0]*a[34][1] + theta1[0]*a[34][1] + a[34][2];

            a1[35][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[35][0] + theta[2]*a[35][1] - theta1[2]*a[35][1] - theta[1]*a[35][2] + theta1[1]*a[35][2];

            a1[35][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[35][0] + theta1[2]*a[35][0] + a[35][1] + theta[0]*a[35][2] - theta1[0]*a[35][2];

            a1[35][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[35][0] - theta1[1]*a[35][0] - theta[0]*a[35][1] + theta1[0]*a[35][1] + a[35][2];

            a1[36][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[36][0] + theta[2]*a[36][1] - theta1[2]*a[36][1] - theta[1]*a[36][2] + theta1[1]*a[36][2];

            a1[36][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[36][0] + theta1[2]*a[36][0] + a[36][1] + theta[0]*a[36][2] - theta1[0]*a[36][2];

            a1[36][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[36][0] - theta1[1]*a[36][0] - theta[0]*a[36][1] + theta1[0]*a[36][1] + a[36][2];

            a1[37][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[37][0] + theta[2]*a[37][1] - theta1[2]*a[37][1] - theta[1]*a[37][2] + theta1[1]*a[37][2];

            a1[37][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[37][0] + theta1[2]*a[37][0] + a[37][1] + theta[0]*a[37][2] - theta1[0]*a[37][2];

            a1[37][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[37][0] - theta1[1]*a[37][0] - theta[0]*a[37][1] + theta1[0]*a[37][1] + a[37][2];

            a1[38][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[38][0] + theta[2]*a[38][1] - theta1[2]*a[38][1] - theta[1]*a[38][2] + theta1[1]*a[38][2];

            a1[38][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[38][0] + theta1[2]*a[38][0] + a[38][1] + theta[0]*a[38][2] - theta1[0]*a[38][2];

            a1[38][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[38][0] - theta1[1]*a[38][0] - theta[0]*a[38][1] + theta1[0]*a[38][1] + a[38][2];

            a1[39][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[39][0] + theta[2]*a[39][1] - theta1[2]*a[39][1] - theta[1]*a[39][2] + theta1[1]*a[39][2];

            a1[39][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[39][0] + theta1[2]*a[39][0] + a[39][1] + theta[0]*a[39][2] - theta1[0]*a[39][2];

            a1[39][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[39][0] - theta1[1]*a[39][0] - theta[0]*a[39][1] + theta1[0]*a[39][1] + a[39][2];

            a1[40][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[40][0] + theta[2]*a[40][1] - theta1[2]*a[40][1] - theta[1]*a[40][2] + theta1[1]*a[40][2];

            a1[40][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[40][0] + theta1[2]*a[40][0] + a[40][1] + theta[0]*a[40][2] - theta1[0]*a[40][2];

            a1[40][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[40][0] - theta1[1]*a[40][0] - theta[0]*a[40][1] + theta1[0]*a[40][1] + a[40][2];

            a1[41][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[41][0] + theta[2]*a[41][1] - theta1[2]*a[41][1] - theta[1]*a[41][2] + theta1[1]*a[41][2];

            a1[41][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[41][0] + theta1[2]*a[41][0] + a[41][1] + theta[0]*a[41][2] - theta1[0]*a[41][2];

            a1[41][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[41][0] - theta1[1]*a[41][0] - theta[0]*a[41][1] + theta1[0]*a[41][1] + a[41][2];

            a1[42][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[42][0] + theta[2]*a[42][1] - theta1[2]*a[42][1] - theta[1]*a[42][2] + theta1[1]*a[42][2];

            a1[42][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[42][0] + theta1[2]*a[42][0] + a[42][1] + theta[0]*a[42][2] - theta1[0]*a[42][2];

            a1[42][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[42][0] - theta1[1]*a[42][0] - theta[0]*a[42][1] + theta1[0]*a[42][1] + a[42][2];

            a1[43][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[43][0] + theta[2]*a[43][1] - theta1[2]*a[43][1] - theta[1]*a[43][2] + theta1[1]*a[43][2];

            a1[43][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[43][0] + theta1[2]*a[43][0] + a[43][1] + theta[0]*a[43][2] - theta1[0]*a[43][2];

            a1[43][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[43][0] - theta1[1]*a[43][0] - theta[0]*a[43][1] + theta1[0]*a[43][1] + a[43][2];

            a1[44][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[44][0] + theta[2]*a[44][1] - theta1[2]*a[44][1] - theta[1]*a[44][2] + theta1[1]*a[44][2];

            a1[44][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[44][0] + theta1[2]*a[44][0] + a[44][1] + theta[0]*a[44][2] - theta1[0]*a[44][2];

            a1[44][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[44][0] - theta1[1]*a[44][0] - theta[0]*a[44][1] + theta1[0]*a[44][1] + a[44][2];

            a1[45][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[45][0] + theta[2]*a[45][1] - theta1[2]*a[45][1] - theta[1]*a[45][2] + theta1[1]*a[45][2];

            a1[45][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[45][0] + theta1[2]*a[45][0] + a[45][1] + theta[0]*a[45][2] - theta1[0]*a[45][2];

            a1[45][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[45][0] - theta1[1]*a[45][0] - theta[0]*a[45][1] + theta1[0]*a[45][1] + a[45][2];

            a1[46][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[46][0] + theta[2]*a[46][1] - theta1[2]*a[46][1] - theta[1]*a[46][2] + theta1[1]*a[46][2];

            a1[46][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[46][0] + theta1[2]*a[46][0] + a[46][1] + theta[0]*a[46][2] - theta1[0]*a[46][2];

            a1[46][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[46][0] - theta1[1]*a[46][0] - theta[0]*a[46][1] + theta1[0]*a[46][1] + a[46][2];

            a1[47][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[47][0] + theta[2]*a[47][1] - theta1[2]*a[47][1] - theta[1]*a[47][2] + theta1[1]*a[47][2];

            a1[47][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[47][0] + theta1[2]*a[47][0] + a[47][1] + theta[0]*a[47][2] - theta1[0]*a[47][2];

            a1[47][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[47][0] - theta1[1]*a[47][0] - theta[0]*a[47][1] + theta1[0]*a[47][1] + a[47][2];

            a1[48][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[48][0] + theta[2]*a[48][1] - theta1[2]*a[48][1] - theta[1]*a[48][2] + theta1[1]*a[48][2];

            a1[48][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[48][0] + theta1[2]*a[48][0] + a[48][1] + theta[0]*a[48][2] - theta1[0]*a[48][2];

            a1[48][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[48][0] - theta1[1]*a[48][0] - theta[0]*a[48][1] + theta1[0]*a[48][1] + a[48][2];

            a1[49][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[49][0] + theta[2]*a[49][1] - theta1[2]*a[49][1] - theta[1]*a[49][2] + theta1[1]*a[49][2];

            a1[49][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[49][0] + theta1[2]*a[49][0] + a[49][1] + theta[0]*a[49][2] - theta1[0]*a[49][2];

            a1[49][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[49][0] - theta1[1]*a[49][0] - theta[0]*a[49][1] + theta1[0]*a[49][1] + a[49][2];

            a1[50][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[50][0] + theta[2]*a[50][1] - theta1[2]*a[50][1] - theta[1]*a[50][2] + theta1[1]*a[50][2];

            a1[50][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[50][0] + theta1[2]*a[50][0] + a[50][1] + theta[0]*a[50][2] - theta1[0]*a[50][2];

            a1[50][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[50][0] - theta1[1]*a[50][0] - theta[0]*a[50][1] + theta1[0]*a[50][1] + a[50][2];

            a1[51][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[51][0] + theta[2]*a[51][1] - theta1[2]*a[51][1] - theta[1]*a[51][2] + theta1[1]*a[51][2];

            a1[51][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[51][0] + theta1[2]*a[51][0] + a[51][1] + theta[0]*a[51][2] - theta1[0]*a[51][2];

            a1[51][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[51][0] - theta1[1]*a[51][0] - theta[0]*a[51][1] + theta1[0]*a[51][1] + a[51][2];

            a1[52][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[52][0] + theta[2]*a[52][1] - theta1[2]*a[52][1] - theta[1]*a[52][2] + theta1[1]*a[52][2];

            a1[52][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[52][0] + theta1[2]*a[52][0] + a[52][1] + theta[0]*a[52][2] - theta1[0]*a[52][2];

            a1[52][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[52][0] - theta1[1]*a[52][0] - theta[0]*a[52][1] + theta1[0]*a[52][1] + a[52][2];

            a1[53][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[53][0] + theta[2]*a[53][1] - theta1[2]*a[53][1] - theta[1]*a[53][2] + theta1[1]*a[53][2];

            a1[53][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[53][0] + theta1[2]*a[53][0] + a[53][1] + theta[0]*a[53][2] - theta1[0]*a[53][2];

            a1[53][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[53][0] - theta1[1]*a[53][0] - theta[0]*a[53][1] + theta1[0]*a[53][1] + a[53][2];

            a1[54][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[54][0] + theta[2]*a[54][1] - theta1[2]*a[54][1] - theta[1]*a[54][2] + theta1[1]*a[54][2];

            a1[54][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[54][0] + theta1[2]*a[54][0] + a[54][1] + theta[0]*a[54][2] - theta1[0]*a[54][2];

            a1[54][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[54][0] - theta1[1]*a[54][0] - theta[0]*a[54][1] + theta1[0]*a[54][1] + a[54][2];

            a1[55][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[55][0] + theta[2]*a[55][1] - theta1[2]*a[55][1] - theta[1]*a[55][2] + theta1[1]*a[55][2];

            a1[55][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[55][0] + theta1[2]*a[55][0] + a[55][1] + theta[0]*a[55][2] - theta1[0]*a[55][2];

            a1[55][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[55][0] - theta1[1]*a[55][0] - theta[0]*a[55][1] + theta1[0]*a[55][1] + a[55][2];

            a1[56][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[56][0] + theta[2]*a[56][1] - theta1[2]*a[56][1] - theta[1]*a[56][2] + theta1[1]*a[56][2];

            a1[56][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[56][0] + theta1[2]*a[56][0] + a[56][1] + theta[0]*a[56][2] - theta1[0]*a[56][2];

            a1[56][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[56][0] - theta1[1]*a[56][0] - theta[0]*a[56][1] + theta1[0]*a[56][1] + a[56][2];

            a1[57][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[57][0] + theta[2]*a[57][1] - theta1[2]*a[57][1] - theta[1]*a[57][2] + theta1[1]*a[57][2];

            a1[57][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[57][0] + theta1[2]*a[57][0] + a[57][1] + theta[0]*a[57][2] - theta1[0]*a[57][2];

            a1[57][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[57][0] - theta1[1]*a[57][0] - theta[0]*a[57][1] + theta1[0]*a[57][1] + a[57][2];

            a1[58][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[58][0] + theta[2]*a[58][1] - theta1[2]*a[58][1] - theta[1]*a[58][2] + theta1[1]*a[58][2];

            a1[58][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[58][0] + theta1[2]*a[58][0] + a[58][1] + theta[0]*a[58][2] - theta1[0]*a[58][2];

            a1[58][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[58][0] - theta1[1]*a[58][0] - theta[0]*a[58][1] + theta1[0]*a[58][1] + a[58][2];

            a1[59][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[59][0] + theta[2]*a[59][1] - theta1[2]*a[59][1] - theta[1]*a[59][2] + theta1[1]*a[59][2];

            a1[59][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[59][0] + theta1[2]*a[59][0] + a[59][1] + theta[0]*a[59][2] - theta1[0]*a[59][2];

            a1[59][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[59][0] - theta1[1]*a[59][0] - theta[0]*a[59][1] + theta1[0]*a[59][1] + a[59][2];

            a1[60][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[60][0] + theta[2]*a[60][1] - theta1[2]*a[60][1] - theta[1]*a[60][2] + theta1[1]*a[60][2];

            a1[60][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[60][0] + theta1[2]*a[60][0] + a[60][1] + theta[0]*a[60][2] - theta1[0]*a[60][2];

            a1[60][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[60][0] - theta1[1]*a[60][0] - theta[0]*a[60][1] + theta1[0]*a[60][1] + a[60][2];

            break;

        case 71:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmRadial[10][0] + FmRadial[11][0] + FmRadial[12][0] + FmRadial[13][0] + FmRadial[14][0] + FmRadial[15][0] + FmRadial[16][0] + FmRadial[17][0] + FmRadial[18][0] + FmRadial[19][0] + FmRadial[20][0] + FmRadial[21][0] + FmRadial[22][0] + FmRadial[23][0] + FmRadial[24][0] + FmRadial[25][0] + FmRadial[26][0] + FmRadial[27][0] + FmRadial[28][0] + FmRadial[29][0] + FmRadial[30][0] + FmRadial[31][0] + FmRadial[32][0] + FmRadial[33][0] + FmRadial[34][0] + FmRadial[35][0] + FmRadial[36][0] + FmRadial[37][0] + FmRadial[38][0] + FmRadial[39][0] + FmRadial[40][0] + FmRadial[41][0] + FmRadial[42][0] + FmRadial[43][0] + FmRadial[44][0] + FmRadial[45][0] + FmRadial[46][0] + FmRadial[47][0] + FmRadial[48][0] + FmRadial[49][0] + FmRadial[50][0] + FmRadial[51][0] + FmRadial[52][0] + FmRadial[53][0] + FmRadial[54][0] + FmRadial[55][0] + FmRadial[56][0] + FmRadial[57][0] + FmRadial[58][0] + FmRadial[59][0] + FmRadial[60][0] + FmRadial[61][0] + FmRadial[62][0] + FmRadial[63][0] + FmRadial[64][0] + FmRadial[65][0] + FmRadial[66][0] + FmRadial[67][0] + FmRadial[68][0] + FmRadial[69][0] + FmRadial[70][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0] + FmTangential[41][0] + FmTangential[42][0] + FmTangential[43][0] + FmTangential[44][0] + FmTangential[45][0] + FmTangential[46][0] + FmTangential[47][0] + FmTangential[48][0] + FmTangential[49][0] + FmTangential[50][0] + FmTangential[51][0] + FmTangential[52][0] + FmTangential[53][0] + FmTangential[54][0] + FmTangential[55][0] + FmTangential[56][0] + FmTangential[57][0] + FmTangential[58][0] + FmTangential[59][0] + FmTangential[60][0] + FmTangential[61][0] + FmTangential[62][0] + FmTangential[63][0] + FmTangential[64][0] + FmTangential[65][0] + FmTangential[66][0] + FmTangential[67][0] + FmTangential[68][0] + FmTangential[69][0] + FmTangential[70][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmRadial[10][1] + FmRadial[11][1] + FmRadial[12][1] + FmRadial[13][1] + FmRadial[14][1] + FmRadial[15][1] + FmRadial[16][1] + FmRadial[17][1] + FmRadial[18][1] + FmRadial[19][1] + FmRadial[20][1] + FmRadial[21][1] + FmRadial[22][1] + FmRadial[23][1] + FmRadial[24][1] + FmRadial[25][1] + FmRadial[26][1] + FmRadial[27][1] + FmRadial[28][1] + FmRadial[29][1] + FmRadial[30][1] + FmRadial[31][1] + FmRadial[32][1] + FmRadial[33][1] + FmRadial[34][1] + FmRadial[35][1] + FmRadial[36][1] + FmRadial[37][1] + FmRadial[38][1] + FmRadial[39][1] + FmRadial[40][1] + FmRadial[41][1] + FmRadial[42][1] + FmRadial[43][1] + FmRadial[44][1] + FmRadial[45][1] + FmRadial[46][1] + FmRadial[47][1] + FmRadial[48][1] + FmRadial[49][1] + FmRadial[50][1] + FmRadial[51][1] + FmRadial[52][1] + FmRadial[53][1] + FmRadial[54][1] + FmRadial[55][1] + FmRadial[56][1] + FmRadial[57][1] + FmRadial[58][1] + FmRadial[59][1] + FmRadial[60][1] + FmRadial[61][1] + FmRadial[62][1] + FmRadial[63][1] + FmRadial[64][1] + FmRadial[65][1] + FmRadial[66][1] + FmRadial[67][1] + FmRadial[68][1] + FmRadial[69][1] + FmRadial[70][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1] + FmTangential[19][1] + FmTangential[20][1] + FmTangential[21][1] + FmTangential[22][1] + FmTangential[23][1] + FmTangential[24][1] + FmTangential[25][1] + FmTangential[26][1] + FmTangential[27][1] + FmTangential[28][1] + FmTangential[29][1] + FmTangential[30][1] + FmTangential[31][1] + FmTangential[32][1] + FmTangential[33][1] + FmTangential[34][1] + FmTangential[35][1] + FmTangential[36][1] + FmTangential[37][1] + FmTangential[38][1] + FmTangential[39][1] + FmTangential[40][1] + FmTangential[41][1] + FmTangential[42][1] + FmTangential[43][1] + FmTangential[44][1] + FmTangential[45][1] + FmTangential[46][1] + FmTangential[47][1] + FmTangential[48][1] + FmTangential[49][1] + FmTangential[50][1] + FmTangential[51][1] + FmTangential[52][1] + FmTangential[53][1] + FmTangential[54][1] + FmTangential[55][1] + FmTangential[56][1] + FmTangential[57][1] + FmTangential[58][1] + FmTangential[59][1] + FmTangential[60][1] + FmTangential[61][1] + FmTangential[62][1] + FmTangential[63][1] + FmTangential[64][1] + FmTangential[65][1] + FmTangential[66][1] + FmTangential[67][1] + FmTangential[68][1] + FmTangential[69][1] + FmTangential[70][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmRadial[10][2] + FmRadial[11][2] + FmRadial[12][2] + FmRadial[13][2] + FmRadial[14][2] + FmRadial[15][2] + FmRadial[16][2] + FmRadial[17][2] + FmRadial[18][2] + FmRadial[19][2] + FmRadial[20][2] + FmRadial[21][2] + FmRadial[22][2] + FmRadial[23][2] + FmRadial[24][2] + FmRadial[25][2] + FmRadial[26][2] + FmRadial[27][2] + FmRadial[28][2] + FmRadial[29][2] + FmRadial[30][2] + FmRadial[31][2] + FmRadial[32][2] + FmRadial[33][2] + FmRadial[34][2] + FmRadial[35][2] + FmRadial[36][2] + FmRadial[37][2] + FmRadial[38][2] + FmRadial[39][2] + FmRadial[40][2] + FmRadial[41][2] + FmRadial[42][2] + FmRadial[43][2] + FmRadial[44][2] + FmRadial[45][2] + FmRadial[46][2] + FmRadial[47][2] + FmRadial[48][2] + FmRadial[49][2] + FmRadial[50][2] + FmRadial[51][2] + FmRadial[52][2] + FmRadial[53][2] + FmRadial[54][2] + FmRadial[55][2] + FmRadial[56][2] + FmRadial[57][2] + FmRadial[58][2] + FmRadial[59][2] + FmRadial[60][2] + FmRadial[61][2] + FmRadial[62][2] + FmRadial[63][2] + FmRadial[64][2] + FmRadial[65][2] + FmRadial[66][2] + FmRadial[67][2] + FmRadial[68][2] + FmRadial[69][2] + FmRadial[70][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2] + FmTangential[10][2] + FmTangential[11][2] + FmTangential[12][2] + FmTangential[13][2] + FmTangential[14][2] + FmTangential[15][2] + FmTangential[16][2] + FmTangential[17][2] + FmTangential[18][2] + FmTangential[19][2] + FmTangential[20][2] + FmTangential[21][2] + FmTangential[22][2] + FmTangential[23][2] + FmTangential[24][2] + FmTangential[25][2] + FmTangential[26][2] + FmTangential[27][2] + FmTangential[28][2] + FmTangential[29][2] + FmTangential[30][2] + FmTangential[31][2] + FmTangential[32][2] + FmTangential[33][2] + FmTangential[34][2] + FmTangential[35][2] + FmTangential[36][2] + FmTangential[37][2] + FmTangential[38][2] + FmTangential[39][2] + FmTangential[40][2] + FmTangential[41][2] + FmTangential[42][2] + FmTangential[43][2] + FmTangential[44][2] + FmTangential[45][2] + FmTangential[46][2] + FmTangential[47][2] + FmTangential[48][2] + FmTangential[49][2] + FmTangential[50][2] + FmTangential[51][2] + FmTangential[52][2] + FmTangential[53][2] + FmTangential[54][2] + FmTangential[55][2] + FmTangential[56][2] + FmTangential[57][2] + FmTangential[58][2] + FmTangential[59][2] + FmTangential[60][2] + FmTangential[61][2] + FmTangential[62][2] + FmTangential[63][2] + FmTangential[64][2] + FmTangential[65][2] + FmTangential[66][2] + FmTangential[67][2] + FmTangential[68][2] + FmTangential[69][2] + FmTangential[70][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2] - a[10][2]*FmTangential[10][1] - c[1]*FmTangential[10][2] + a[10][1]*FmTangential[10][2] - a[11][2]*FmTangential[11][1] - c[1]*FmTangential[11][2] + a[11][1]*FmTangential[11][2] - a[12][2]*FmTangential[12][1] - c[1]*FmTangential[12][2] + a[12][1]*FmTangential[12][2] - a[13][2]*FmTangential[13][1] - c[1]*FmTangential[13][2] + a[13][1]*FmTangential[13][2] - a[14][2]*FmTangential[14][1] - c[1]*FmTangential[14][2] + a[14][1]*FmTangential[14][2] - a[15][2]*FmTangential[15][1] - c[1]*FmTangential[15][2] + a[15][1]*FmTangential[15][2] - a[16][2]*FmTangential[16][1] - c[1]*FmTangential[16][2] + a[16][1]*FmTangential[16][2] - a[17][2]*FmTangential[17][1] - c[1]*FmTangential[17][2] + a[17][1]*FmTangential[17][2] - a[18][2]*FmTangential[18][1] - c[1]*FmTangential[18][2] + a[18][1]*FmTangential[18][2] - a[19][2]*FmTangential[19][1] - c[1]*FmTangential[19][2] + a[19][1]*FmTangential[19][2] - a[20][2]*FmTangential[20][1] - c[1]*FmTangential[20][2] + a[20][1]*FmTangential[20][2] - a[21][2]*FmTangential[21][1] - c[1]*FmTangential[21][2] + a[21][1]*FmTangential[21][2] - a[22][2]*FmTangential[22][1] - c[1]*FmTangential[22][2] + a[22][1]*FmTangential[22][2] - a[23][2]*FmTangential[23][1] - c[1]*FmTangential[23][2] + a[23][1]*FmTangential[23][2] - a[24][2]*FmTangential[24][1] - c[1]*FmTangential[24][2] + a[24][1]*FmTangential[24][2] - a[25][2]*FmTangential[25][1] - c[1]*FmTangential[25][2] + a[25][1]*FmTangential[25][2] - a[26][2]*FmTangential[26][1] - c[1]*FmTangential[26][2] + a[26][1]*FmTangential[26][2] - a[27][2]*FmTangential[27][1] - c[1]*FmTangential[27][2] + a[27][1]*FmTangential[27][2] - a[28][2]*FmTangential[28][1] - c[1]*FmTangential[28][2] + a[28][1]*FmTangential[28][2] - a[29][2]*FmTangential[29][1] - c[1]*FmTangential[29][2] + a[29][1]*FmTangential[29][2] - a[30][2]*FmTangential[30][1] - c[1]*FmTangential[30][2] + a[30][1]*FmTangential[30][2] - a[31][2]*FmTangential[31][1] - c[1]*FmTangential[31][2] + a[31][1]*FmTangential[31][2] - a[32][2]*FmTangential[32][1] - c[1]*FmTangential[32][2] + a[32][1]*FmTangential[32][2] - a[33][2]*FmTangential[33][1] - c[1]*FmTangential[33][2] + a[33][1]*FmTangential[33][2] - a[34][2]*FmTangential[34][1] - c[1]*FmTangential[34][2] + a[34][1]*FmTangential[34][2] - a[35][2]*FmTangential[35][1] - c[1]*FmTangential[35][2] + a[35][1]*FmTangential[35][2] - a[36][2]*FmTangential[36][1] - c[1]*FmTangential[36][2] + a[36][1]*FmTangential[36][2] - a[37][2]*FmTangential[37][1] - c[1]*FmTangential[37][2] + a[37][1]*FmTangential[37][2] - a[38][2]*FmTangential[38][1] - c[1]*FmTangential[38][2] + a[38][1]*FmTangential[38][2] - a[39][2]*FmTangential[39][1] - c[1]*FmTangential[39][2] + a[39][1]*FmTangential[39][2] - a[40][2]*FmTangential[40][1] - c[1]*FmTangential[40][2] + a[40][1]*FmTangential[40][2] - a[41][2]*FmTangential[41][1] - c[1]*FmTangential[41][2] + a[41][1]*FmTangential[41][2] - a[42][2]*FmTangential[42][1] - c[1]*FmTangential[42][2] + a[42][1]*FmTangential[42][2] - a[43][2]*FmTangential[43][1] - c[1]*FmTangential[43][2] + a[43][1]*FmTangential[43][2] - a[44][2]*FmTangential[44][1] - c[1]*FmTangential[44][2] + a[44][1]*FmTangential[44][2] - a[45][2]*FmTangential[45][1] - c[1]*FmTangential[45][2] + a[45][1]*FmTangential[45][2] - a[46][2]*FmTangential[46][1] - c[1]*FmTangential[46][2] + a[46][1]*FmTangential[46][2] - a[47][2]*FmTangential[47][1] - c[1]*FmTangential[47][2] + a[47][1]*FmTangential[47][2] - a[48][2]*FmTangential[48][1] - c[1]*FmTangential[48][2] + a[48][1]*FmTangential[48][2] - a[49][2]*FmTangential[49][1] - c[1]*FmTangential[49][2] + a[49][1]*FmTangential[49][2] - a[50][2]*FmTangential[50][1] - c[1]*FmTangential[50][2] + a[50][1]*FmTangential[50][2] - a[51][2]*FmTangential[51][1] - c[1]*FmTangential[51][2] + a[51][1]*FmTangential[51][2] - a[52][2]*FmTangential[52][1] - c[1]*FmTangential[52][2] + a[52][1]*FmTangential[52][2] - a[53][2]*FmTangential[53][1] - c[1]*FmTangential[53][2] + a[53][1]*FmTangential[53][2] - a[54][2]*FmTangential[54][1] - c[1]*FmTangential[54][2] + a[54][1]*FmTangential[54][2] - a[55][2]*FmTangential[55][1] - c[1]*FmTangential[55][2] + a[55][1]*FmTangential[55][2] - a[56][2]*FmTangential[56][1] - c[1]*FmTangential[56][2] + a[56][1]*FmTangential[56][2] - a[57][2]*FmTangential[57][1] - c[1]*FmTangential[57][2] + a[57][1]*FmTangential[57][2] - a[58][2]*FmTangential[58][1] - c[1]*FmTangential[58][2] + a[58][1]*FmTangential[58][2] - a[59][2]*FmTangential[59][1] - c[1]*FmTangential[59][2] + a[59][1]*FmTangential[59][2] - a[60][2]*FmTangential[60][1] - c[1]*FmTangential[60][2] + a[60][1]*FmTangential[60][2] - a[61][2]*FmTangential[61][1] - c[1]*FmTangential[61][2] + a[61][1]*FmTangential[61][2] - a[62][2]*FmTangential[62][1] - c[1]*FmTangential[62][2] + a[62][1]*FmTangential[62][2] - a[63][2]*FmTangential[63][1] - c[1]*FmTangential[63][2] + a[63][1]*FmTangential[63][2] - a[64][2]*FmTangential[64][1] - c[1]*FmTangential[64][2] + a[64][1]*FmTangential[64][2] - a[65][2]*FmTangential[65][1] - c[1]*FmTangential[65][2] + a[65][1]*FmTangential[65][2] - a[66][2]*FmTangential[66][1] - c[1]*FmTangential[66][2] + a[66][1]*FmTangential[66][2] - a[67][2]*FmTangential[67][1] - c[1]*FmTangential[67][2] + a[67][1]*FmTangential[67][2] - a[68][2]*FmTangential[68][1] - c[1]*FmTangential[68][2] + a[68][1]*FmTangential[68][2] - a[69][2]*FmTangential[69][1] - c[1]*FmTangential[69][2] + a[69][1]*FmTangential[69][2] - a[70][2]*FmTangential[70][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1] + FmTangential[19][1] + FmTangential[20][1] + FmTangential[21][1] + FmTangential[22][1] + FmTangential[23][1] + FmTangential[24][1] + FmTangential[25][1] + FmTangential[26][1] + FmTangential[27][1] + FmTangential[28][1] + FmTangential[29][1] + FmTangential[30][1] + FmTangential[31][1] + FmTangential[32][1] + FmTangential[33][1] + FmTangential[34][1] + FmTangential[35][1] + FmTangential[36][1] + FmTangential[37][1] + FmTangential[38][1] + FmTangential[39][1] + FmTangential[40][1] + FmTangential[41][1] + FmTangential[42][1] + FmTangential[43][1] + FmTangential[44][1] + FmTangential[45][1] + FmTangential[46][1] + FmTangential[47][1] + FmTangential[48][1] + FmTangential[49][1] + FmTangential[50][1] + FmTangential[51][1] + FmTangential[52][1] + FmTangential[53][1] + FmTangential[54][1] + FmTangential[55][1] + FmTangential[56][1] + FmTangential[57][1] + FmTangential[58][1] + FmTangential[59][1] + FmTangential[60][1] + FmTangential[61][1] + FmTangential[62][1] + FmTangential[63][1] + FmTangential[64][1] + FmTangential[65][1] + FmTangential[66][1] + FmTangential[67][1] + FmTangential[68][1] + FmTangential[69][1] + FmTangential[70][1]) - c[1]*FmTangential[70][2] + a[70][1]*FmTangential[70][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2] + a[10][2]*FmTangential[10][0] + c[0]*FmTangential[10][2] - a[10][0]*FmTangential[10][2] + a[11][2]*FmTangential[11][0] + c[0]*FmTangential[11][2] - a[11][0]*FmTangential[11][2] + a[12][2]*FmTangential[12][0] + c[0]*FmTangential[12][2] - a[12][0]*FmTangential[12][2] + a[13][2]*FmTangential[13][0] + c[0]*FmTangential[13][2] - a[13][0]*FmTangential[13][2] + a[14][2]*FmTangential[14][0] + c[0]*FmTangential[14][2] - a[14][0]*FmTangential[14][2] + a[15][2]*FmTangential[15][0] + c[0]*FmTangential[15][2] - a[15][0]*FmTangential[15][2] + a[16][2]*FmTangential[16][0] + c[0]*FmTangential[16][2] - a[16][0]*FmTangential[16][2] + a[17][2]*FmTangential[17][0] + c[0]*FmTangential[17][2] - a[17][0]*FmTangential[17][2] + a[18][2]*FmTangential[18][0] + c[0]*FmTangential[18][2] - a[18][0]*FmTangential[18][2] + a[19][2]*FmTangential[19][0] + c[0]*FmTangential[19][2] - a[19][0]*FmTangential[19][2] + a[20][2]*FmTangential[20][0] + c[0]*FmTangential[20][2] - a[20][0]*FmTangential[20][2] + a[21][2]*FmTangential[21][0] + c[0]*FmTangential[21][2] - a[21][0]*FmTangential[21][2] + a[22][2]*FmTangential[22][0] + c[0]*FmTangential[22][2] - a[22][0]*FmTangential[22][2] + a[23][2]*FmTangential[23][0] + c[0]*FmTangential[23][2] - a[23][0]*FmTangential[23][2] + a[24][2]*FmTangential[24][0] + c[0]*FmTangential[24][2] - a[24][0]*FmTangential[24][2] + a[25][2]*FmTangential[25][0] + c[0]*FmTangential[25][2] - a[25][0]*FmTangential[25][2] + a[26][2]*FmTangential[26][0] + c[0]*FmTangential[26][2] - a[26][0]*FmTangential[26][2] + a[27][2]*FmTangential[27][0] + c[0]*FmTangential[27][2] - a[27][0]*FmTangential[27][2] + a[28][2]*FmTangential[28][0] + c[0]*FmTangential[28][2] - a[28][0]*FmTangential[28][2] + a[29][2]*FmTangential[29][0] + c[0]*FmTangential[29][2] - a[29][0]*FmTangential[29][2] + a[30][2]*FmTangential[30][0] + c[0]*FmTangential[30][2] - a[30][0]*FmTangential[30][2] + a[31][2]*FmTangential[31][0] + c[0]*FmTangential[31][2] - a[31][0]*FmTangential[31][2] + a[32][2]*FmTangential[32][0] + c[0]*FmTangential[32][2] - a[32][0]*FmTangential[32][2] + a[33][2]*FmTangential[33][0] + c[0]*FmTangential[33][2] - a[33][0]*FmTangential[33][2] + a[34][2]*FmTangential[34][0] + c[0]*FmTangential[34][2] - a[34][0]*FmTangential[34][2] + a[35][2]*FmTangential[35][0] + c[0]*FmTangential[35][2] - a[35][0]*FmTangential[35][2] + a[36][2]*FmTangential[36][0] + c[0]*FmTangential[36][2] - a[36][0]*FmTangential[36][2] + a[37][2]*FmTangential[37][0] + c[0]*FmTangential[37][2] - a[37][0]*FmTangential[37][2] + a[38][2]*FmTangential[38][0] + c[0]*FmTangential[38][2] - a[38][0]*FmTangential[38][2] + a[39][2]*FmTangential[39][0] + c[0]*FmTangential[39][2] - a[39][0]*FmTangential[39][2] + a[40][2]*FmTangential[40][0] + c[0]*FmTangential[40][2] - a[40][0]*FmTangential[40][2] + a[41][2]*FmTangential[41][0] + c[0]*FmTangential[41][2] - a[41][0]*FmTangential[41][2] + a[42][2]*FmTangential[42][0] + c[0]*FmTangential[42][2] - a[42][0]*FmTangential[42][2] + a[43][2]*FmTangential[43][0] + c[0]*FmTangential[43][2] - a[43][0]*FmTangential[43][2] + a[44][2]*FmTangential[44][0] + c[0]*FmTangential[44][2] - a[44][0]*FmTangential[44][2] + a[45][2]*FmTangential[45][0] + c[0]*FmTangential[45][2] - a[45][0]*FmTangential[45][2] + a[46][2]*FmTangential[46][0] + c[0]*FmTangential[46][2] - a[46][0]*FmTangential[46][2] + a[47][2]*FmTangential[47][0] + c[0]*FmTangential[47][2] - a[47][0]*FmTangential[47][2] + a[48][2]*FmTangential[48][0] + c[0]*FmTangential[48][2] - a[48][0]*FmTangential[48][2] + a[49][2]*FmTangential[49][0] + c[0]*FmTangential[49][2] - a[49][0]*FmTangential[49][2] + a[50][2]*FmTangential[50][0] + c[0]*FmTangential[50][2] - a[50][0]*FmTangential[50][2] + a[51][2]*FmTangential[51][0] + c[0]*FmTangential[51][2] - a[51][0]*FmTangential[51][2] + a[52][2]*FmTangential[52][0] + c[0]*FmTangential[52][2] - a[52][0]*FmTangential[52][2] + a[53][2]*FmTangential[53][0] + c[0]*FmTangential[53][2] - a[53][0]*FmTangential[53][2] + a[54][2]*FmTangential[54][0] + c[0]*FmTangential[54][2] - a[54][0]*FmTangential[54][2] + a[55][2]*FmTangential[55][0] + c[0]*FmTangential[55][2] - a[55][0]*FmTangential[55][2] + a[56][2]*FmTangential[56][0] + c[0]*FmTangential[56][2] - a[56][0]*FmTangential[56][2] + a[57][2]*FmTangential[57][0] + c[0]*FmTangential[57][2] - a[57][0]*FmTangential[57][2] + a[58][2]*FmTangential[58][0] + c[0]*FmTangential[58][2] - a[58][0]*FmTangential[58][2] + a[59][2]*FmTangential[59][0] + c[0]*FmTangential[59][2] - a[59][0]*FmTangential[59][2] + a[60][2]*FmTangential[60][0] + c[0]*FmTangential[60][2] - a[60][0]*FmTangential[60][2] + a[61][2]*FmTangential[61][0] + c[0]*FmTangential[61][2] - a[61][0]*FmTangential[61][2] + a[62][2]*FmTangential[62][0] + c[0]*FmTangential[62][2] - a[62][0]*FmTangential[62][2] + a[63][2]*FmTangential[63][0] + c[0]*FmTangential[63][2] - a[63][0]*FmTangential[63][2] + a[64][2]*FmTangential[64][0] + c[0]*FmTangential[64][2] - a[64][0]*FmTangential[64][2] + a[65][2]*FmTangential[65][0] + c[0]*FmTangential[65][2] - a[65][0]*FmTangential[65][2] + a[66][2]*FmTangential[66][0] + c[0]*FmTangential[66][2] - a[66][0]*FmTangential[66][2] + a[67][2]*FmTangential[67][0] + c[0]*FmTangential[67][2] - a[67][0]*FmTangential[67][2] + a[68][2]*FmTangential[68][0] + c[0]*FmTangential[68][2] - a[68][0]*FmTangential[68][2] + a[69][2]*FmTangential[69][0] + c[0]*FmTangential[69][2] - a[69][0]*FmTangential[69][2] + a[70][2]*FmTangential[70][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0] + FmTangential[41][0] + FmTangential[42][0] + FmTangential[43][0] + FmTangential[44][0] + FmTangential[45][0] + FmTangential[46][0] + FmTangential[47][0] + FmTangential[48][0] + FmTangential[49][0] + FmTangential[50][0] + FmTangential[51][0] + FmTangential[52][0] + FmTangential[53][0] + FmTangential[54][0] + FmTangential[55][0] + FmTangential[56][0] + FmTangential[57][0] + FmTangential[58][0] + FmTangential[59][0] + FmTangential[60][0] + FmTangential[61][0] + FmTangential[62][0] + FmTangential[63][0] + FmTangential[64][0] + FmTangential[65][0] + FmTangential[66][0] + FmTangential[67][0] + FmTangential[68][0] + FmTangential[69][0] + FmTangential[70][0]) + c[0]*FmTangential[70][2] - a[70][0]*FmTangential[70][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1] - a[10][1]*FmTangential[10][0] - c[0]*FmTangential[10][1] + a[10][0]*FmTangential[10][1] - a[11][1]*FmTangential[11][0] - c[0]*FmTangential[11][1] + a[11][0]*FmTangential[11][1] - a[12][1]*FmTangential[12][0] - c[0]*FmTangential[12][1] + a[12][0]*FmTangential[12][1] - a[13][1]*FmTangential[13][0] - c[0]*FmTangential[13][1] + a[13][0]*FmTangential[13][1] - a[14][1]*FmTangential[14][0] - c[0]*FmTangential[14][1] + a[14][0]*FmTangential[14][1] - a[15][1]*FmTangential[15][0] - c[0]*FmTangential[15][1] + a[15][0]*FmTangential[15][1] - a[16][1]*FmTangential[16][0] - c[0]*FmTangential[16][1] + a[16][0]*FmTangential[16][1] - a[17][1]*FmTangential[17][0] - c[0]*FmTangential[17][1] + a[17][0]*FmTangential[17][1] - a[18][1]*FmTangential[18][0] - c[0]*FmTangential[18][1] + a[18][0]*FmTangential[18][1] - a[19][1]*FmTangential[19][0] - c[0]*FmTangential[19][1] + a[19][0]*FmTangential[19][1] - a[20][1]*FmTangential[20][0] - c[0]*FmTangential[20][1] + a[20][0]*FmTangential[20][1] - a[21][1]*FmTangential[21][0] - c[0]*FmTangential[21][1] + a[21][0]*FmTangential[21][1] - a[22][1]*FmTangential[22][0] - c[0]*FmTangential[22][1] + a[22][0]*FmTangential[22][1] - a[23][1]*FmTangential[23][0] - c[0]*FmTangential[23][1] + a[23][0]*FmTangential[23][1] - a[24][1]*FmTangential[24][0] - c[0]*FmTangential[24][1] + a[24][0]*FmTangential[24][1] - a[25][1]*FmTangential[25][0] - c[0]*FmTangential[25][1] + a[25][0]*FmTangential[25][1] - a[26][1]*FmTangential[26][0] - c[0]*FmTangential[26][1] + a[26][0]*FmTangential[26][1] - a[27][1]*FmTangential[27][0] - c[0]*FmTangential[27][1] + a[27][0]*FmTangential[27][1] - a[28][1]*FmTangential[28][0] - c[0]*FmTangential[28][1] + a[28][0]*FmTangential[28][1] - a[29][1]*FmTangential[29][0] - c[0]*FmTangential[29][1] + a[29][0]*FmTangential[29][1] - a[30][1]*FmTangential[30][0] - c[0]*FmTangential[30][1] + a[30][0]*FmTangential[30][1] - a[31][1]*FmTangential[31][0] - c[0]*FmTangential[31][1] + a[31][0]*FmTangential[31][1] - a[32][1]*FmTangential[32][0] - c[0]*FmTangential[32][1] + a[32][0]*FmTangential[32][1] - a[33][1]*FmTangential[33][0] - c[0]*FmTangential[33][1] + a[33][0]*FmTangential[33][1] - a[34][1]*FmTangential[34][0] - c[0]*FmTangential[34][1] + a[34][0]*FmTangential[34][1] - a[35][1]*FmTangential[35][0] - c[0]*FmTangential[35][1] + a[35][0]*FmTangential[35][1] - a[36][1]*FmTangential[36][0] - c[0]*FmTangential[36][1] + a[36][0]*FmTangential[36][1] - a[37][1]*FmTangential[37][0] - c[0]*FmTangential[37][1] + a[37][0]*FmTangential[37][1] - a[38][1]*FmTangential[38][0] - c[0]*FmTangential[38][1] + a[38][0]*FmTangential[38][1] - a[39][1]*FmTangential[39][0] - c[0]*FmTangential[39][1] + a[39][0]*FmTangential[39][1] - a[40][1]*FmTangential[40][0] - c[0]*FmTangential[40][1] + a[40][0]*FmTangential[40][1] - a[41][1]*FmTangential[41][0] - c[0]*FmTangential[41][1] + a[41][0]*FmTangential[41][1] - a[42][1]*FmTangential[42][0] - c[0]*FmTangential[42][1] + a[42][0]*FmTangential[42][1] - a[43][1]*FmTangential[43][0] - c[0]*FmTangential[43][1] + a[43][0]*FmTangential[43][1] - a[44][1]*FmTangential[44][0] - c[0]*FmTangential[44][1] + a[44][0]*FmTangential[44][1] - a[45][1]*FmTangential[45][0] - c[0]*FmTangential[45][1] + a[45][0]*FmTangential[45][1] - a[46][1]*FmTangential[46][0] - c[0]*FmTangential[46][1] + a[46][0]*FmTangential[46][1] - a[47][1]*FmTangential[47][0] - c[0]*FmTangential[47][1] + a[47][0]*FmTangential[47][1] - a[48][1]*FmTangential[48][0] - c[0]*FmTangential[48][1] + a[48][0]*FmTangential[48][1] - a[49][1]*FmTangential[49][0] - c[0]*FmTangential[49][1] + a[49][0]*FmTangential[49][1] - a[50][1]*FmTangential[50][0] - c[0]*FmTangential[50][1] + a[50][0]*FmTangential[50][1] - a[51][1]*FmTangential[51][0] - c[0]*FmTangential[51][1] + a[51][0]*FmTangential[51][1] - a[52][1]*FmTangential[52][0] - c[0]*FmTangential[52][1] + a[52][0]*FmTangential[52][1] - a[53][1]*FmTangential[53][0] - c[0]*FmTangential[53][1] + a[53][0]*FmTangential[53][1] - a[54][1]*FmTangential[54][0] - c[0]*FmTangential[54][1] + a[54][0]*FmTangential[54][1] - a[55][1]*FmTangential[55][0] - c[0]*FmTangential[55][1] + a[55][0]*FmTangential[55][1] - a[56][1]*FmTangential[56][0] - c[0]*FmTangential[56][1] + a[56][0]*FmTangential[56][1] - a[57][1]*FmTangential[57][0] - c[0]*FmTangential[57][1] + a[57][0]*FmTangential[57][1] - a[58][1]*FmTangential[58][0] - c[0]*FmTangential[58][1] + a[58][0]*FmTangential[58][1] - a[59][1]*FmTangential[59][0] - c[0]*FmTangential[59][1] + a[59][0]*FmTangential[59][1] - a[60][1]*FmTangential[60][0] - c[0]*FmTangential[60][1] + a[60][0]*FmTangential[60][1] - a[61][1]*FmTangential[61][0] - c[0]*FmTangential[61][1] + a[61][0]*FmTangential[61][1] - a[62][1]*FmTangential[62][0] - c[0]*FmTangential[62][1] + a[62][0]*FmTangential[62][1] - a[63][1]*FmTangential[63][0] - c[0]*FmTangential[63][1] + a[63][0]*FmTangential[63][1] - a[64][1]*FmTangential[64][0] - c[0]*FmTangential[64][1] + a[64][0]*FmTangential[64][1] - a[65][1]*FmTangential[65][0] - c[0]*FmTangential[65][1] + a[65][0]*FmTangential[65][1] - a[66][1]*FmTangential[66][0] - c[0]*FmTangential[66][1] + a[66][0]*FmTangential[66][1] - a[67][1]*FmTangential[67][0] - c[0]*FmTangential[67][1] + a[67][0]*FmTangential[67][1] - a[68][1]*FmTangential[68][0] - c[0]*FmTangential[68][1] + a[68][0]*FmTangential[68][1] - a[69][1]*FmTangential[69][0] - c[0]*FmTangential[69][1] + a[69][0]*FmTangential[69][1] - a[70][1]*FmTangential[70][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0] + FmTangential[41][0] + FmTangential[42][0] + FmTangential[43][0] + FmTangential[44][0] + FmTangential[45][0] + FmTangential[46][0] + FmTangential[47][0] + FmTangential[48][0] + FmTangential[49][0] + FmTangential[50][0] + FmTangential[51][0] + FmTangential[52][0] + FmTangential[53][0] + FmTangential[54][0] + FmTangential[55][0] + FmTangential[56][0] + FmTangential[57][0] + FmTangential[58][0] + FmTangential[59][0] + FmTangential[60][0] + FmTangential[61][0] + FmTangential[62][0] + FmTangential[63][0] + FmTangential[64][0] + FmTangential[65][0] + FmTangential[66][0] + FmTangential[67][0] + FmTangential[68][0] + FmTangential[69][0] + FmTangential[70][0]) - c[0]*FmTangential[70][1] + a[70][0]*FmTangential[70][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            a1[10][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[10][0] + theta[2]*a[10][1] - theta1[2]*a[10][1] - theta[1]*a[10][2] + theta1[1]*a[10][2];

            a1[10][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[10][0] + theta1[2]*a[10][0] + a[10][1] + theta[0]*a[10][2] - theta1[0]*a[10][2];

            a1[10][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[10][0] - theta1[1]*a[10][0] - theta[0]*a[10][1] + theta1[0]*a[10][1] + a[10][2];

            a1[11][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[11][0] + theta[2]*a[11][1] - theta1[2]*a[11][1] - theta[1]*a[11][2] + theta1[1]*a[11][2];

            a1[11][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[11][0] + theta1[2]*a[11][0] + a[11][1] + theta[0]*a[11][2] - theta1[0]*a[11][2];

            a1[11][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[11][0] - theta1[1]*a[11][0] - theta[0]*a[11][1] + theta1[0]*a[11][1] + a[11][2];

            a1[12][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[12][0] + theta[2]*a[12][1] - theta1[2]*a[12][1] - theta[1]*a[12][2] + theta1[1]*a[12][2];

            a1[12][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[12][0] + theta1[2]*a[12][0] + a[12][1] + theta[0]*a[12][2] - theta1[0]*a[12][2];

            a1[12][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[12][0] - theta1[1]*a[12][0] - theta[0]*a[12][1] + theta1[0]*a[12][1] + a[12][2];

            a1[13][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[13][0] + theta[2]*a[13][1] - theta1[2]*a[13][1] - theta[1]*a[13][2] + theta1[1]*a[13][2];

            a1[13][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[13][0] + theta1[2]*a[13][0] + a[13][1] + theta[0]*a[13][2] - theta1[0]*a[13][2];

            a1[13][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[13][0] - theta1[1]*a[13][0] - theta[0]*a[13][1] + theta1[0]*a[13][1] + a[13][2];

            a1[14][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[14][0] + theta[2]*a[14][1] - theta1[2]*a[14][1] - theta[1]*a[14][2] + theta1[1]*a[14][2];

            a1[14][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[14][0] + theta1[2]*a[14][0] + a[14][1] + theta[0]*a[14][2] - theta1[0]*a[14][2];

            a1[14][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[14][0] - theta1[1]*a[14][0] - theta[0]*a[14][1] + theta1[0]*a[14][1] + a[14][2];

            a1[15][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[15][0] + theta[2]*a[15][1] - theta1[2]*a[15][1] - theta[1]*a[15][2] + theta1[1]*a[15][2];

            a1[15][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[15][0] + theta1[2]*a[15][0] + a[15][1] + theta[0]*a[15][2] - theta1[0]*a[15][2];

            a1[15][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[15][0] - theta1[1]*a[15][0] - theta[0]*a[15][1] + theta1[0]*a[15][1] + a[15][2];

            a1[16][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[16][0] + theta[2]*a[16][1] - theta1[2]*a[16][1] - theta[1]*a[16][2] + theta1[1]*a[16][2];

            a1[16][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[16][0] + theta1[2]*a[16][0] + a[16][1] + theta[0]*a[16][2] - theta1[0]*a[16][2];

            a1[16][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[16][0] - theta1[1]*a[16][0] - theta[0]*a[16][1] + theta1[0]*a[16][1] + a[16][2];

            a1[17][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[17][0] + theta[2]*a[17][1] - theta1[2]*a[17][1] - theta[1]*a[17][2] + theta1[1]*a[17][2];

            a1[17][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[17][0] + theta1[2]*a[17][0] + a[17][1] + theta[0]*a[17][2] - theta1[0]*a[17][2];

            a1[17][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[17][0] - theta1[1]*a[17][0] - theta[0]*a[17][1] + theta1[0]*a[17][1] + a[17][2];

            a1[18][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[18][0] + theta[2]*a[18][1] - theta1[2]*a[18][1] - theta[1]*a[18][2] + theta1[1]*a[18][2];

            a1[18][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[18][0] + theta1[2]*a[18][0] + a[18][1] + theta[0]*a[18][2] - theta1[0]*a[18][2];

            a1[18][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[18][0] - theta1[1]*a[18][0] - theta[0]*a[18][1] + theta1[0]*a[18][1] + a[18][2];

            a1[19][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[19][0] + theta[2]*a[19][1] - theta1[2]*a[19][1] - theta[1]*a[19][2] + theta1[1]*a[19][2];

            a1[19][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[19][0] + theta1[2]*a[19][0] + a[19][1] + theta[0]*a[19][2] - theta1[0]*a[19][2];

            a1[19][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[19][0] - theta1[1]*a[19][0] - theta[0]*a[19][1] + theta1[0]*a[19][1] + a[19][2];

            a1[20][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[20][0] + theta[2]*a[20][1] - theta1[2]*a[20][1] - theta[1]*a[20][2] + theta1[1]*a[20][2];

            a1[20][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[20][0] + theta1[2]*a[20][0] + a[20][1] + theta[0]*a[20][2] - theta1[0]*a[20][2];

            a1[20][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[20][0] - theta1[1]*a[20][0] - theta[0]*a[20][1] + theta1[0]*a[20][1] + a[20][2];

            a1[21][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[21][0] + theta[2]*a[21][1] - theta1[2]*a[21][1] - theta[1]*a[21][2] + theta1[1]*a[21][2];

            a1[21][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[21][0] + theta1[2]*a[21][0] + a[21][1] + theta[0]*a[21][2] - theta1[0]*a[21][2];

            a1[21][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[21][0] - theta1[1]*a[21][0] - theta[0]*a[21][1] + theta1[0]*a[21][1] + a[21][2];

            a1[22][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[22][0] + theta[2]*a[22][1] - theta1[2]*a[22][1] - theta[1]*a[22][2] + theta1[1]*a[22][2];

            a1[22][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[22][0] + theta1[2]*a[22][0] + a[22][1] + theta[0]*a[22][2] - theta1[0]*a[22][2];

            a1[22][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[22][0] - theta1[1]*a[22][0] - theta[0]*a[22][1] + theta1[0]*a[22][1] + a[22][2];

            a1[23][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[23][0] + theta[2]*a[23][1] - theta1[2]*a[23][1] - theta[1]*a[23][2] + theta1[1]*a[23][2];

            a1[23][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[23][0] + theta1[2]*a[23][0] + a[23][1] + theta[0]*a[23][2] - theta1[0]*a[23][2];

            a1[23][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[23][0] - theta1[1]*a[23][0] - theta[0]*a[23][1] + theta1[0]*a[23][1] + a[23][2];

            a1[24][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[24][0] + theta[2]*a[24][1] - theta1[2]*a[24][1] - theta[1]*a[24][2] + theta1[1]*a[24][2];

            a1[24][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[24][0] + theta1[2]*a[24][0] + a[24][1] + theta[0]*a[24][2] - theta1[0]*a[24][2];

            a1[24][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[24][0] - theta1[1]*a[24][0] - theta[0]*a[24][1] + theta1[0]*a[24][1] + a[24][2];

            a1[25][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[25][0] + theta[2]*a[25][1] - theta1[2]*a[25][1] - theta[1]*a[25][2] + theta1[1]*a[25][2];

            a1[25][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[25][0] + theta1[2]*a[25][0] + a[25][1] + theta[0]*a[25][2] - theta1[0]*a[25][2];

            a1[25][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[25][0] - theta1[1]*a[25][0] - theta[0]*a[25][1] + theta1[0]*a[25][1] + a[25][2];

            a1[26][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[26][0] + theta[2]*a[26][1] - theta1[2]*a[26][1] - theta[1]*a[26][2] + theta1[1]*a[26][2];

            a1[26][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[26][0] + theta1[2]*a[26][0] + a[26][1] + theta[0]*a[26][2] - theta1[0]*a[26][2];

            a1[26][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[26][0] - theta1[1]*a[26][0] - theta[0]*a[26][1] + theta1[0]*a[26][1] + a[26][2];

            a1[27][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[27][0] + theta[2]*a[27][1] - theta1[2]*a[27][1] - theta[1]*a[27][2] + theta1[1]*a[27][2];

            a1[27][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[27][0] + theta1[2]*a[27][0] + a[27][1] + theta[0]*a[27][2] - theta1[0]*a[27][2];

            a1[27][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[27][0] - theta1[1]*a[27][0] - theta[0]*a[27][1] + theta1[0]*a[27][1] + a[27][2];

            a1[28][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[28][0] + theta[2]*a[28][1] - theta1[2]*a[28][1] - theta[1]*a[28][2] + theta1[1]*a[28][2];

            a1[28][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[28][0] + theta1[2]*a[28][0] + a[28][1] + theta[0]*a[28][2] - theta1[0]*a[28][2];

            a1[28][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[28][0] - theta1[1]*a[28][0] - theta[0]*a[28][1] + theta1[0]*a[28][1] + a[28][2];

            a1[29][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[29][0] + theta[2]*a[29][1] - theta1[2]*a[29][1] - theta[1]*a[29][2] + theta1[1]*a[29][2];

            a1[29][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[29][0] + theta1[2]*a[29][0] + a[29][1] + theta[0]*a[29][2] - theta1[0]*a[29][2];

            a1[29][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[29][0] - theta1[1]*a[29][0] - theta[0]*a[29][1] + theta1[0]*a[29][1] + a[29][2];

            a1[30][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[30][0] + theta[2]*a[30][1] - theta1[2]*a[30][1] - theta[1]*a[30][2] + theta1[1]*a[30][2];

            a1[30][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[30][0] + theta1[2]*a[30][0] + a[30][1] + theta[0]*a[30][2] - theta1[0]*a[30][2];

            a1[30][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[30][0] - theta1[1]*a[30][0] - theta[0]*a[30][1] + theta1[0]*a[30][1] + a[30][2];

            a1[31][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[31][0] + theta[2]*a[31][1] - theta1[2]*a[31][1] - theta[1]*a[31][2] + theta1[1]*a[31][2];

            a1[31][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[31][0] + theta1[2]*a[31][0] + a[31][1] + theta[0]*a[31][2] - theta1[0]*a[31][2];

            a1[31][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[31][0] - theta1[1]*a[31][0] - theta[0]*a[31][1] + theta1[0]*a[31][1] + a[31][2];

            a1[32][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[32][0] + theta[2]*a[32][1] - theta1[2]*a[32][1] - theta[1]*a[32][2] + theta1[1]*a[32][2];

            a1[32][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[32][0] + theta1[2]*a[32][0] + a[32][1] + theta[0]*a[32][2] - theta1[0]*a[32][2];

            a1[32][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[32][0] - theta1[1]*a[32][0] - theta[0]*a[32][1] + theta1[0]*a[32][1] + a[32][2];

            a1[33][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[33][0] + theta[2]*a[33][1] - theta1[2]*a[33][1] - theta[1]*a[33][2] + theta1[1]*a[33][2];

            a1[33][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[33][0] + theta1[2]*a[33][0] + a[33][1] + theta[0]*a[33][2] - theta1[0]*a[33][2];

            a1[33][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[33][0] - theta1[1]*a[33][0] - theta[0]*a[33][1] + theta1[0]*a[33][1] + a[33][2];

            a1[34][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[34][0] + theta[2]*a[34][1] - theta1[2]*a[34][1] - theta[1]*a[34][2] + theta1[1]*a[34][2];

            a1[34][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[34][0] + theta1[2]*a[34][0] + a[34][1] + theta[0]*a[34][2] - theta1[0]*a[34][2];

            a1[34][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[34][0] - theta1[1]*a[34][0] - theta[0]*a[34][1] + theta1[0]*a[34][1] + a[34][2];

            a1[35][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[35][0] + theta[2]*a[35][1] - theta1[2]*a[35][1] - theta[1]*a[35][2] + theta1[1]*a[35][2];

            a1[35][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[35][0] + theta1[2]*a[35][0] + a[35][1] + theta[0]*a[35][2] - theta1[0]*a[35][2];

            a1[35][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[35][0] - theta1[1]*a[35][0] - theta[0]*a[35][1] + theta1[0]*a[35][1] + a[35][2];

            a1[36][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[36][0] + theta[2]*a[36][1] - theta1[2]*a[36][1] - theta[1]*a[36][2] + theta1[1]*a[36][2];

            a1[36][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[36][0] + theta1[2]*a[36][0] + a[36][1] + theta[0]*a[36][2] - theta1[0]*a[36][2];

            a1[36][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[36][0] - theta1[1]*a[36][0] - theta[0]*a[36][1] + theta1[0]*a[36][1] + a[36][2];

            a1[37][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[37][0] + theta[2]*a[37][1] - theta1[2]*a[37][1] - theta[1]*a[37][2] + theta1[1]*a[37][2];

            a1[37][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[37][0] + theta1[2]*a[37][0] + a[37][1] + theta[0]*a[37][2] - theta1[0]*a[37][2];

            a1[37][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[37][0] - theta1[1]*a[37][0] - theta[0]*a[37][1] + theta1[0]*a[37][1] + a[37][2];

            a1[38][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[38][0] + theta[2]*a[38][1] - theta1[2]*a[38][1] - theta[1]*a[38][2] + theta1[1]*a[38][2];

            a1[38][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[38][0] + theta1[2]*a[38][0] + a[38][1] + theta[0]*a[38][2] - theta1[0]*a[38][2];

            a1[38][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[38][0] - theta1[1]*a[38][0] - theta[0]*a[38][1] + theta1[0]*a[38][1] + a[38][2];

            a1[39][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[39][0] + theta[2]*a[39][1] - theta1[2]*a[39][1] - theta[1]*a[39][2] + theta1[1]*a[39][2];

            a1[39][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[39][0] + theta1[2]*a[39][0] + a[39][1] + theta[0]*a[39][2] - theta1[0]*a[39][2];

            a1[39][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[39][0] - theta1[1]*a[39][0] - theta[0]*a[39][1] + theta1[0]*a[39][1] + a[39][2];

            a1[40][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[40][0] + theta[2]*a[40][1] - theta1[2]*a[40][1] - theta[1]*a[40][2] + theta1[1]*a[40][2];

            a1[40][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[40][0] + theta1[2]*a[40][0] + a[40][1] + theta[0]*a[40][2] - theta1[0]*a[40][2];

            a1[40][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[40][0] - theta1[1]*a[40][0] - theta[0]*a[40][1] + theta1[0]*a[40][1] + a[40][2];

            a1[41][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[41][0] + theta[2]*a[41][1] - theta1[2]*a[41][1] - theta[1]*a[41][2] + theta1[1]*a[41][2];

            a1[41][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[41][0] + theta1[2]*a[41][0] + a[41][1] + theta[0]*a[41][2] - theta1[0]*a[41][2];

            a1[41][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[41][0] - theta1[1]*a[41][0] - theta[0]*a[41][1] + theta1[0]*a[41][1] + a[41][2];

            a1[42][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[42][0] + theta[2]*a[42][1] - theta1[2]*a[42][1] - theta[1]*a[42][2] + theta1[1]*a[42][2];

            a1[42][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[42][0] + theta1[2]*a[42][0] + a[42][1] + theta[0]*a[42][2] - theta1[0]*a[42][2];

            a1[42][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[42][0] - theta1[1]*a[42][0] - theta[0]*a[42][1] + theta1[0]*a[42][1] + a[42][2];

            a1[43][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[43][0] + theta[2]*a[43][1] - theta1[2]*a[43][1] - theta[1]*a[43][2] + theta1[1]*a[43][2];

            a1[43][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[43][0] + theta1[2]*a[43][0] + a[43][1] + theta[0]*a[43][2] - theta1[0]*a[43][2];

            a1[43][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[43][0] - theta1[1]*a[43][0] - theta[0]*a[43][1] + theta1[0]*a[43][1] + a[43][2];

            a1[44][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[44][0] + theta[2]*a[44][1] - theta1[2]*a[44][1] - theta[1]*a[44][2] + theta1[1]*a[44][2];

            a1[44][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[44][0] + theta1[2]*a[44][0] + a[44][1] + theta[0]*a[44][2] - theta1[0]*a[44][2];

            a1[44][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[44][0] - theta1[1]*a[44][0] - theta[0]*a[44][1] + theta1[0]*a[44][1] + a[44][2];

            a1[45][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[45][0] + theta[2]*a[45][1] - theta1[2]*a[45][1] - theta[1]*a[45][2] + theta1[1]*a[45][2];

            a1[45][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[45][0] + theta1[2]*a[45][0] + a[45][1] + theta[0]*a[45][2] - theta1[0]*a[45][2];

            a1[45][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[45][0] - theta1[1]*a[45][0] - theta[0]*a[45][1] + theta1[0]*a[45][1] + a[45][2];

            a1[46][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[46][0] + theta[2]*a[46][1] - theta1[2]*a[46][1] - theta[1]*a[46][2] + theta1[1]*a[46][2];

            a1[46][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[46][0] + theta1[2]*a[46][0] + a[46][1] + theta[0]*a[46][2] - theta1[0]*a[46][2];

            a1[46][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[46][0] - theta1[1]*a[46][0] - theta[0]*a[46][1] + theta1[0]*a[46][1] + a[46][2];

            a1[47][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[47][0] + theta[2]*a[47][1] - theta1[2]*a[47][1] - theta[1]*a[47][2] + theta1[1]*a[47][2];

            a1[47][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[47][0] + theta1[2]*a[47][0] + a[47][1] + theta[0]*a[47][2] - theta1[0]*a[47][2];

            a1[47][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[47][0] - theta1[1]*a[47][0] - theta[0]*a[47][1] + theta1[0]*a[47][1] + a[47][2];

            a1[48][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[48][0] + theta[2]*a[48][1] - theta1[2]*a[48][1] - theta[1]*a[48][2] + theta1[1]*a[48][2];

            a1[48][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[48][0] + theta1[2]*a[48][0] + a[48][1] + theta[0]*a[48][2] - theta1[0]*a[48][2];

            a1[48][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[48][0] - theta1[1]*a[48][0] - theta[0]*a[48][1] + theta1[0]*a[48][1] + a[48][2];

            a1[49][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[49][0] + theta[2]*a[49][1] - theta1[2]*a[49][1] - theta[1]*a[49][2] + theta1[1]*a[49][2];

            a1[49][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[49][0] + theta1[2]*a[49][0] + a[49][1] + theta[0]*a[49][2] - theta1[0]*a[49][2];

            a1[49][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[49][0] - theta1[1]*a[49][0] - theta[0]*a[49][1] + theta1[0]*a[49][1] + a[49][2];

            a1[50][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[50][0] + theta[2]*a[50][1] - theta1[2]*a[50][1] - theta[1]*a[50][2] + theta1[1]*a[50][2];

            a1[50][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[50][0] + theta1[2]*a[50][0] + a[50][1] + theta[0]*a[50][2] - theta1[0]*a[50][2];

            a1[50][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[50][0] - theta1[1]*a[50][0] - theta[0]*a[50][1] + theta1[0]*a[50][1] + a[50][2];

            a1[51][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[51][0] + theta[2]*a[51][1] - theta1[2]*a[51][1] - theta[1]*a[51][2] + theta1[1]*a[51][2];

            a1[51][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[51][0] + theta1[2]*a[51][0] + a[51][1] + theta[0]*a[51][2] - theta1[0]*a[51][2];

            a1[51][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[51][0] - theta1[1]*a[51][0] - theta[0]*a[51][1] + theta1[0]*a[51][1] + a[51][2];

            a1[52][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[52][0] + theta[2]*a[52][1] - theta1[2]*a[52][1] - theta[1]*a[52][2] + theta1[1]*a[52][2];

            a1[52][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[52][0] + theta1[2]*a[52][0] + a[52][1] + theta[0]*a[52][2] - theta1[0]*a[52][2];

            a1[52][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[52][0] - theta1[1]*a[52][0] - theta[0]*a[52][1] + theta1[0]*a[52][1] + a[52][2];

            a1[53][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[53][0] + theta[2]*a[53][1] - theta1[2]*a[53][1] - theta[1]*a[53][2] + theta1[1]*a[53][2];

            a1[53][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[53][0] + theta1[2]*a[53][0] + a[53][1] + theta[0]*a[53][2] - theta1[0]*a[53][2];

            a1[53][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[53][0] - theta1[1]*a[53][0] - theta[0]*a[53][1] + theta1[0]*a[53][1] + a[53][2];

            a1[54][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[54][0] + theta[2]*a[54][1] - theta1[2]*a[54][1] - theta[1]*a[54][2] + theta1[1]*a[54][2];

            a1[54][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[54][0] + theta1[2]*a[54][0] + a[54][1] + theta[0]*a[54][2] - theta1[0]*a[54][2];

            a1[54][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[54][0] - theta1[1]*a[54][0] - theta[0]*a[54][1] + theta1[0]*a[54][1] + a[54][2];

            a1[55][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[55][0] + theta[2]*a[55][1] - theta1[2]*a[55][1] - theta[1]*a[55][2] + theta1[1]*a[55][2];

            a1[55][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[55][0] + theta1[2]*a[55][0] + a[55][1] + theta[0]*a[55][2] - theta1[0]*a[55][2];

            a1[55][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[55][0] - theta1[1]*a[55][0] - theta[0]*a[55][1] + theta1[0]*a[55][1] + a[55][2];

            a1[56][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[56][0] + theta[2]*a[56][1] - theta1[2]*a[56][1] - theta[1]*a[56][2] + theta1[1]*a[56][2];

            a1[56][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[56][0] + theta1[2]*a[56][0] + a[56][1] + theta[0]*a[56][2] - theta1[0]*a[56][2];

            a1[56][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[56][0] - theta1[1]*a[56][0] - theta[0]*a[56][1] + theta1[0]*a[56][1] + a[56][2];

            a1[57][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[57][0] + theta[2]*a[57][1] - theta1[2]*a[57][1] - theta[1]*a[57][2] + theta1[1]*a[57][2];

            a1[57][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[57][0] + theta1[2]*a[57][0] + a[57][1] + theta[0]*a[57][2] - theta1[0]*a[57][2];

            a1[57][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[57][0] - theta1[1]*a[57][0] - theta[0]*a[57][1] + theta1[0]*a[57][1] + a[57][2];

            a1[58][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[58][0] + theta[2]*a[58][1] - theta1[2]*a[58][1] - theta[1]*a[58][2] + theta1[1]*a[58][2];

            a1[58][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[58][0] + theta1[2]*a[58][0] + a[58][1] + theta[0]*a[58][2] - theta1[0]*a[58][2];

            a1[58][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[58][0] - theta1[1]*a[58][0] - theta[0]*a[58][1] + theta1[0]*a[58][1] + a[58][2];

            a1[59][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[59][0] + theta[2]*a[59][1] - theta1[2]*a[59][1] - theta[1]*a[59][2] + theta1[1]*a[59][2];

            a1[59][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[59][0] + theta1[2]*a[59][0] + a[59][1] + theta[0]*a[59][2] - theta1[0]*a[59][2];

            a1[59][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[59][0] - theta1[1]*a[59][0] - theta[0]*a[59][1] + theta1[0]*a[59][1] + a[59][2];

            a1[60][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[60][0] + theta[2]*a[60][1] - theta1[2]*a[60][1] - theta[1]*a[60][2] + theta1[1]*a[60][2];

            a1[60][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[60][0] + theta1[2]*a[60][0] + a[60][1] + theta[0]*a[60][2] - theta1[0]*a[60][2];

            a1[60][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[60][0] - theta1[1]*a[60][0] - theta[0]*a[60][1] + theta1[0]*a[60][1] + a[60][2];

            a1[61][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[61][0] + theta[2]*a[61][1] - theta1[2]*a[61][1] - theta[1]*a[61][2] + theta1[1]*a[61][2];

            a1[61][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[61][0] + theta1[2]*a[61][0] + a[61][1] + theta[0]*a[61][2] - theta1[0]*a[61][2];

            a1[61][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[61][0] - theta1[1]*a[61][0] - theta[0]*a[61][1] + theta1[0]*a[61][1] + a[61][2];

            a1[62][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[62][0] + theta[2]*a[62][1] - theta1[2]*a[62][1] - theta[1]*a[62][2] + theta1[1]*a[62][2];

            a1[62][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[62][0] + theta1[2]*a[62][0] + a[62][1] + theta[0]*a[62][2] - theta1[0]*a[62][2];

            a1[62][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[62][0] - theta1[1]*a[62][0] - theta[0]*a[62][1] + theta1[0]*a[62][1] + a[62][2];

            a1[63][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[63][0] + theta[2]*a[63][1] - theta1[2]*a[63][1] - theta[1]*a[63][2] + theta1[1]*a[63][2];

            a1[63][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[63][0] + theta1[2]*a[63][0] + a[63][1] + theta[0]*a[63][2] - theta1[0]*a[63][2];

            a1[63][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[63][0] - theta1[1]*a[63][0] - theta[0]*a[63][1] + theta1[0]*a[63][1] + a[63][2];

            a1[64][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[64][0] + theta[2]*a[64][1] - theta1[2]*a[64][1] - theta[1]*a[64][2] + theta1[1]*a[64][2];

            a1[64][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[64][0] + theta1[2]*a[64][0] + a[64][1] + theta[0]*a[64][2] - theta1[0]*a[64][2];

            a1[64][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[64][0] - theta1[1]*a[64][0] - theta[0]*a[64][1] + theta1[0]*a[64][1] + a[64][2];

            a1[65][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[65][0] + theta[2]*a[65][1] - theta1[2]*a[65][1] - theta[1]*a[65][2] + theta1[1]*a[65][2];

            a1[65][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[65][0] + theta1[2]*a[65][0] + a[65][1] + theta[0]*a[65][2] - theta1[0]*a[65][2];

            a1[65][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[65][0] - theta1[1]*a[65][0] - theta[0]*a[65][1] + theta1[0]*a[65][1] + a[65][2];

            a1[66][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[66][0] + theta[2]*a[66][1] - theta1[2]*a[66][1] - theta[1]*a[66][2] + theta1[1]*a[66][2];

            a1[66][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[66][0] + theta1[2]*a[66][0] + a[66][1] + theta[0]*a[66][2] - theta1[0]*a[66][2];

            a1[66][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[66][0] - theta1[1]*a[66][0] - theta[0]*a[66][1] + theta1[0]*a[66][1] + a[66][2];

            a1[67][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[67][0] + theta[2]*a[67][1] - theta1[2]*a[67][1] - theta[1]*a[67][2] + theta1[1]*a[67][2];

            a1[67][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[67][0] + theta1[2]*a[67][0] + a[67][1] + theta[0]*a[67][2] - theta1[0]*a[67][2];

            a1[67][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[67][0] - theta1[1]*a[67][0] - theta[0]*a[67][1] + theta1[0]*a[67][1] + a[67][2];

            a1[68][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[68][0] + theta[2]*a[68][1] - theta1[2]*a[68][1] - theta[1]*a[68][2] + theta1[1]*a[68][2];

            a1[68][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[68][0] + theta1[2]*a[68][0] + a[68][1] + theta[0]*a[68][2] - theta1[0]*a[68][2];

            a1[68][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[68][0] - theta1[1]*a[68][0] - theta[0]*a[68][1] + theta1[0]*a[68][1] + a[68][2];

            a1[69][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[69][0] + theta[2]*a[69][1] - theta1[2]*a[69][1] - theta[1]*a[69][2] + theta1[1]*a[69][2];

            a1[69][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[69][0] + theta1[2]*a[69][0] + a[69][1] + theta[0]*a[69][2] - theta1[0]*a[69][2];

            a1[69][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[69][0] - theta1[1]*a[69][0] - theta[0]*a[69][1] + theta1[0]*a[69][1] + a[69][2];

            a1[70][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[70][0] + theta[2]*a[70][1] - theta1[2]*a[70][1] - theta[1]*a[70][2] + theta1[1]*a[70][2];

            a1[70][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[70][0] + theta1[2]*a[70][0] + a[70][1] + theta[0]*a[70][2] - theta1[0]*a[70][2];

            a1[70][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[70][0] - theta1[1]*a[70][0] - theta[0]*a[70][1] + theta1[0]*a[70][1] + a[70][2];

            break;

        case 81:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmRadial[10][0] + FmRadial[11][0] + FmRadial[12][0] + FmRadial[13][0] + FmRadial[14][0] + FmRadial[15][0] + FmRadial[16][0] + FmRadial[17][0] + FmRadial[18][0] + FmRadial[19][0] + FmRadial[20][0] + FmRadial[21][0] + FmRadial[22][0] + FmRadial[23][0] + FmRadial[24][0] + FmRadial[25][0] + FmRadial[26][0] + FmRadial[27][0] + FmRadial[28][0] + FmRadial[29][0] + FmRadial[30][0] + FmRadial[31][0] + FmRadial[32][0] + FmRadial[33][0] + FmRadial[34][0] + FmRadial[35][0] + FmRadial[36][0] + FmRadial[37][0] + FmRadial[38][0] + FmRadial[39][0] + FmRadial[40][0] + FmRadial[41][0] + FmRadial[42][0] + FmRadial[43][0] + FmRadial[44][0] + FmRadial[45][0] + FmRadial[46][0] + FmRadial[47][0] + FmRadial[48][0] + FmRadial[49][0] + FmRadial[50][0] + FmRadial[51][0] + FmRadial[52][0] + FmRadial[53][0] + FmRadial[54][0] + FmRadial[55][0] + FmRadial[56][0] + FmRadial[57][0] + FmRadial[58][0] + FmRadial[59][0] + FmRadial[60][0] + FmRadial[61][0] + FmRadial[62][0] + FmRadial[63][0] + FmRadial[64][0] + FmRadial[65][0] + FmRadial[66][0] + FmRadial[67][0] + FmRadial[68][0] + FmRadial[69][0] + FmRadial[70][0] + FmRadial[71][0] + FmRadial[72][0] + FmRadial[73][0] + FmRadial[74][0] + FmRadial[75][0] + FmRadial[76][0] + FmRadial[77][0] + FmRadial[78][0] + FmRadial[79][0] + FmRadial[80][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0] + FmTangential[41][0] + FmTangential[42][0] + FmTangential[43][0] + FmTangential[44][0] + FmTangential[45][0] + FmTangential[46][0] + FmTangential[47][0] + FmTangential[48][0] + FmTangential[49][0] + FmTangential[50][0] + FmTangential[51][0] + FmTangential[52][0] + FmTangential[53][0] + FmTangential[54][0] + FmTangential[55][0] + FmTangential[56][0] + FmTangential[57][0] + FmTangential[58][0] + FmTangential[59][0] + FmTangential[60][0] + FmTangential[61][0] + FmTangential[62][0] + FmTangential[63][0] + FmTangential[64][0] + FmTangential[65][0] + FmTangential[66][0] + FmTangential[67][0] + FmTangential[68][0] + FmTangential[69][0] + FmTangential[70][0] + FmTangential[71][0] + FmTangential[72][0] + FmTangential[73][0] + FmTangential[74][0] + FmTangential[75][0] + FmTangential[76][0] + FmTangential[77][0] + FmTangential[78][0] + FmTangential[79][0] + FmTangential[80][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmRadial[10][1] + FmRadial[11][1] + FmRadial[12][1] + FmRadial[13][1] + FmRadial[14][1] + FmRadial[15][1] + FmRadial[16][1] + FmRadial[17][1] + FmRadial[18][1] + FmRadial[19][1] + FmRadial[20][1] + FmRadial[21][1] + FmRadial[22][1] + FmRadial[23][1] + FmRadial[24][1] + FmRadial[25][1] + FmRadial[26][1] + FmRadial[27][1] + FmRadial[28][1] + FmRadial[29][1] + FmRadial[30][1] + FmRadial[31][1] + FmRadial[32][1] + FmRadial[33][1] + FmRadial[34][1] + FmRadial[35][1] + FmRadial[36][1] + FmRadial[37][1] + FmRadial[38][1] + FmRadial[39][1] + FmRadial[40][1] + FmRadial[41][1] + FmRadial[42][1] + FmRadial[43][1] + FmRadial[44][1] + FmRadial[45][1] + FmRadial[46][1] + FmRadial[47][1] + FmRadial[48][1] + FmRadial[49][1] + FmRadial[50][1] + FmRadial[51][1] + FmRadial[52][1] + FmRadial[53][1] + FmRadial[54][1] + FmRadial[55][1] + FmRadial[56][1] + FmRadial[57][1] + FmRadial[58][1] + FmRadial[59][1] + FmRadial[60][1] + FmRadial[61][1] + FmRadial[62][1] + FmRadial[63][1] + FmRadial[64][1] + FmRadial[65][1] + FmRadial[66][1] + FmRadial[67][1] + FmRadial[68][1] + FmRadial[69][1] + FmRadial[70][1] + FmRadial[71][1] + FmRadial[72][1] + FmRadial[73][1] + FmRadial[74][1] + FmRadial[75][1] + FmRadial[76][1] + FmRadial[77][1] + FmRadial[78][1] + FmRadial[79][1] + FmRadial[80][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1] + FmTangential[19][1] + FmTangential[20][1] + FmTangential[21][1] + FmTangential[22][1] + FmTangential[23][1] + FmTangential[24][1] + FmTangential[25][1] + FmTangential[26][1] + FmTangential[27][1] + FmTangential[28][1] + FmTangential[29][1] + FmTangential[30][1] + FmTangential[31][1] + FmTangential[32][1] + FmTangential[33][1] + FmTangential[34][1] + FmTangential[35][1] + FmTangential[36][1] + FmTangential[37][1] + FmTangential[38][1] + FmTangential[39][1] + FmTangential[40][1] + FmTangential[41][1] + FmTangential[42][1] + FmTangential[43][1] + FmTangential[44][1] + FmTangential[45][1] + FmTangential[46][1] + FmTangential[47][1] + FmTangential[48][1] + FmTangential[49][1] + FmTangential[50][1] + FmTangential[51][1] + FmTangential[52][1] + FmTangential[53][1] + FmTangential[54][1] + FmTangential[55][1] + FmTangential[56][1] + FmTangential[57][1] + FmTangential[58][1] + FmTangential[59][1] + FmTangential[60][1] + FmTangential[61][1] + FmTangential[62][1] + FmTangential[63][1] + FmTangential[64][1] + FmTangential[65][1] + FmTangential[66][1] + FmTangential[67][1] + FmTangential[68][1] + FmTangential[69][1] + FmTangential[70][1] + FmTangential[71][1] + FmTangential[72][1] + FmTangential[73][1] + FmTangential[74][1] + FmTangential[75][1] + FmTangential[76][1] + FmTangential[77][1] + FmTangential[78][1] + FmTangential[79][1] + FmTangential[80][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmRadial[10][2] + FmRadial[11][2] + FmRadial[12][2] + FmRadial[13][2] + FmRadial[14][2] + FmRadial[15][2] + FmRadial[16][2] + FmRadial[17][2] + FmRadial[18][2] + FmRadial[19][2] + FmRadial[20][2] + FmRadial[21][2] + FmRadial[22][2] + FmRadial[23][2] + FmRadial[24][2] + FmRadial[25][2] + FmRadial[26][2] + FmRadial[27][2] + FmRadial[28][2] + FmRadial[29][2] + FmRadial[30][2] + FmRadial[31][2] + FmRadial[32][2] + FmRadial[33][2] + FmRadial[34][2] + FmRadial[35][2] + FmRadial[36][2] + FmRadial[37][2] + FmRadial[38][2] + FmRadial[39][2] + FmRadial[40][2] + FmRadial[41][2] + FmRadial[42][2] + FmRadial[43][2] + FmRadial[44][2] + FmRadial[45][2] + FmRadial[46][2] + FmRadial[47][2] + FmRadial[48][2] + FmRadial[49][2] + FmRadial[50][2] + FmRadial[51][2] + FmRadial[52][2] + FmRadial[53][2] + FmRadial[54][2] + FmRadial[55][2] + FmRadial[56][2] + FmRadial[57][2] + FmRadial[58][2] + FmRadial[59][2] + FmRadial[60][2] + FmRadial[61][2] + FmRadial[62][2] + FmRadial[63][2] + FmRadial[64][2] + FmRadial[65][2] + FmRadial[66][2] + FmRadial[67][2] + FmRadial[68][2] + FmRadial[69][2] + FmRadial[70][2] + FmRadial[71][2] + FmRadial[72][2] + FmRadial[73][2] + FmRadial[74][2] + FmRadial[75][2] + FmRadial[76][2] + FmRadial[77][2] + FmRadial[78][2] + FmRadial[79][2] + FmRadial[80][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2] + FmTangential[10][2] + FmTangential[11][2] + FmTangential[12][2] + FmTangential[13][2] + FmTangential[14][2] + FmTangential[15][2] + FmTangential[16][2] + FmTangential[17][2] + FmTangential[18][2] + FmTangential[19][2] + FmTangential[20][2] + FmTangential[21][2] + FmTangential[22][2] + FmTangential[23][2] + FmTangential[24][2] + FmTangential[25][2] + FmTangential[26][2] + FmTangential[27][2] + FmTangential[28][2] + FmTangential[29][2] + FmTangential[30][2] + FmTangential[31][2] + FmTangential[32][2] + FmTangential[33][2] + FmTangential[34][2] + FmTangential[35][2] + FmTangential[36][2] + FmTangential[37][2] + FmTangential[38][2] + FmTangential[39][2] + FmTangential[40][2] + FmTangential[41][2] + FmTangential[42][2] + FmTangential[43][2] + FmTangential[44][2] + FmTangential[45][2] + FmTangential[46][2] + FmTangential[47][2] + FmTangential[48][2] + FmTangential[49][2] + FmTangential[50][2] + FmTangential[51][2] + FmTangential[52][2] + FmTangential[53][2] + FmTangential[54][2] + FmTangential[55][2] + FmTangential[56][2] + FmTangential[57][2] + FmTangential[58][2] + FmTangential[59][2] + FmTangential[60][2] + FmTangential[61][2] + FmTangential[62][2] + FmTangential[63][2] + FmTangential[64][2] + FmTangential[65][2] + FmTangential[66][2] + FmTangential[67][2] + FmTangential[68][2] + FmTangential[69][2] + FmTangential[70][2] + FmTangential[71][2] + FmTangential[72][2] + FmTangential[73][2] + FmTangential[74][2] + FmTangential[75][2] + FmTangential[76][2] + FmTangential[77][2] + FmTangential[78][2] + FmTangential[79][2] + FmTangential[80][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2] - a[10][2]*FmTangential[10][1] - c[1]*FmTangential[10][2] + a[10][1]*FmTangential[10][2] - a[11][2]*FmTangential[11][1] - c[1]*FmTangential[11][2] + a[11][1]*FmTangential[11][2] - a[12][2]*FmTangential[12][1] - c[1]*FmTangential[12][2] + a[12][1]*FmTangential[12][2] - a[13][2]*FmTangential[13][1] - c[1]*FmTangential[13][2] + a[13][1]*FmTangential[13][2] - a[14][2]*FmTangential[14][1] - c[1]*FmTangential[14][2] + a[14][1]*FmTangential[14][2] - a[15][2]*FmTangential[15][1] - c[1]*FmTangential[15][2] + a[15][1]*FmTangential[15][2] - a[16][2]*FmTangential[16][1] - c[1]*FmTangential[16][2] + a[16][1]*FmTangential[16][2] - a[17][2]*FmTangential[17][1] - c[1]*FmTangential[17][2] + a[17][1]*FmTangential[17][2] - a[18][2]*FmTangential[18][1] - c[1]*FmTangential[18][2] + a[18][1]*FmTangential[18][2] - a[19][2]*FmTangential[19][1] - c[1]*FmTangential[19][2] + a[19][1]*FmTangential[19][2] - a[20][2]*FmTangential[20][1] - c[1]*FmTangential[20][2] + a[20][1]*FmTangential[20][2] - a[21][2]*FmTangential[21][1] - c[1]*FmTangential[21][2] + a[21][1]*FmTangential[21][2] - a[22][2]*FmTangential[22][1] - c[1]*FmTangential[22][2] + a[22][1]*FmTangential[22][2] - a[23][2]*FmTangential[23][1] - c[1]*FmTangential[23][2] + a[23][1]*FmTangential[23][2] - a[24][2]*FmTangential[24][1] - c[1]*FmTangential[24][2] + a[24][1]*FmTangential[24][2] - a[25][2]*FmTangential[25][1] - c[1]*FmTangential[25][2] + a[25][1]*FmTangential[25][2] - a[26][2]*FmTangential[26][1] - c[1]*FmTangential[26][2] + a[26][1]*FmTangential[26][2] - a[27][2]*FmTangential[27][1] - c[1]*FmTangential[27][2] + a[27][1]*FmTangential[27][2] - a[28][2]*FmTangential[28][1] - c[1]*FmTangential[28][2] + a[28][1]*FmTangential[28][2] - a[29][2]*FmTangential[29][1] - c[1]*FmTangential[29][2] + a[29][1]*FmTangential[29][2] - a[30][2]*FmTangential[30][1] - c[1]*FmTangential[30][2] + a[30][1]*FmTangential[30][2] - a[31][2]*FmTangential[31][1] - c[1]*FmTangential[31][2] + a[31][1]*FmTangential[31][2] - a[32][2]*FmTangential[32][1] - c[1]*FmTangential[32][2] + a[32][1]*FmTangential[32][2] - a[33][2]*FmTangential[33][1] - c[1]*FmTangential[33][2] + a[33][1]*FmTangential[33][2] - a[34][2]*FmTangential[34][1] - c[1]*FmTangential[34][2] + a[34][1]*FmTangential[34][2] - a[35][2]*FmTangential[35][1] - c[1]*FmTangential[35][2] + a[35][1]*FmTangential[35][2] - a[36][2]*FmTangential[36][1] - c[1]*FmTangential[36][2] + a[36][1]*FmTangential[36][2] - a[37][2]*FmTangential[37][1] - c[1]*FmTangential[37][2] + a[37][1]*FmTangential[37][2] - a[38][2]*FmTangential[38][1] - c[1]*FmTangential[38][2] + a[38][1]*FmTangential[38][2] - a[39][2]*FmTangential[39][1] - c[1]*FmTangential[39][2] + a[39][1]*FmTangential[39][2] - a[40][2]*FmTangential[40][1] - c[1]*FmTangential[40][2] + a[40][1]*FmTangential[40][2] - a[41][2]*FmTangential[41][1] - c[1]*FmTangential[41][2] + a[41][1]*FmTangential[41][2] - a[42][2]*FmTangential[42][1] - c[1]*FmTangential[42][2] + a[42][1]*FmTangential[42][2] - a[43][2]*FmTangential[43][1] - c[1]*FmTangential[43][2] + a[43][1]*FmTangential[43][2] - a[44][2]*FmTangential[44][1] - c[1]*FmTangential[44][2] + a[44][1]*FmTangential[44][2] - a[45][2]*FmTangential[45][1] - c[1]*FmTangential[45][2] + a[45][1]*FmTangential[45][2] - a[46][2]*FmTangential[46][1] - c[1]*FmTangential[46][2] + a[46][1]*FmTangential[46][2] - a[47][2]*FmTangential[47][1] - c[1]*FmTangential[47][2] + a[47][1]*FmTangential[47][2] - a[48][2]*FmTangential[48][1] - c[1]*FmTangential[48][2] + a[48][1]*FmTangential[48][2] - a[49][2]*FmTangential[49][1] - c[1]*FmTangential[49][2] + a[49][1]*FmTangential[49][2] - a[50][2]*FmTangential[50][1] - c[1]*FmTangential[50][2] + a[50][1]*FmTangential[50][2] - a[51][2]*FmTangential[51][1] - c[1]*FmTangential[51][2] + a[51][1]*FmTangential[51][2] - a[52][2]*FmTangential[52][1] - c[1]*FmTangential[52][2] + a[52][1]*FmTangential[52][2] - a[53][2]*FmTangential[53][1] - c[1]*FmTangential[53][2] + a[53][1]*FmTangential[53][2] - a[54][2]*FmTangential[54][1] - c[1]*FmTangential[54][2] + a[54][1]*FmTangential[54][2] - a[55][2]*FmTangential[55][1] - c[1]*FmTangential[55][2] + a[55][1]*FmTangential[55][2] - a[56][2]*FmTangential[56][1] - c[1]*FmTangential[56][2] + a[56][1]*FmTangential[56][2] - a[57][2]*FmTangential[57][1] - c[1]*FmTangential[57][2] + a[57][1]*FmTangential[57][2] - a[58][2]*FmTangential[58][1] - c[1]*FmTangential[58][2] + a[58][1]*FmTangential[58][2] - a[59][2]*FmTangential[59][1] - c[1]*FmTangential[59][2] + a[59][1]*FmTangential[59][2] - a[60][2]*FmTangential[60][1] - c[1]*FmTangential[60][2] + a[60][1]*FmTangential[60][2] - a[61][2]*FmTangential[61][1] - c[1]*FmTangential[61][2] + a[61][1]*FmTangential[61][2] - a[62][2]*FmTangential[62][1] - c[1]*FmTangential[62][2] + a[62][1]*FmTangential[62][2] - a[63][2]*FmTangential[63][1] - c[1]*FmTangential[63][2] + a[63][1]*FmTangential[63][2] - a[64][2]*FmTangential[64][1] - c[1]*FmTangential[64][2] + a[64][1]*FmTangential[64][2] - a[65][2]*FmTangential[65][1] - c[1]*FmTangential[65][2] + a[65][1]*FmTangential[65][2] - a[66][2]*FmTangential[66][1] - c[1]*FmTangential[66][2] + a[66][1]*FmTangential[66][2] - a[67][2]*FmTangential[67][1] - c[1]*FmTangential[67][2] + a[67][1]*FmTangential[67][2] - a[68][2]*FmTangential[68][1] - c[1]*FmTangential[68][2] + a[68][1]*FmTangential[68][2] - a[69][2]*FmTangential[69][1] - c[1]*FmTangential[69][2] + a[69][1]*FmTangential[69][2] - a[70][2]*FmTangential[70][1] - c[1]*FmTangential[70][2] + a[70][1]*FmTangential[70][2] - a[71][2]*FmTangential[71][1] - c[1]*FmTangential[71][2] + a[71][1]*FmTangential[71][2] - a[72][2]*FmTangential[72][1] - c[1]*FmTangential[72][2] + a[72][1]*FmTangential[72][2] - a[73][2]*FmTangential[73][1] - c[1]*FmTangential[73][2] + a[73][1]*FmTangential[73][2] - a[74][2]*FmTangential[74][1] - c[1]*FmTangential[74][2] + a[74][1]*FmTangential[74][2] - a[75][2]*FmTangential[75][1] - c[1]*FmTangential[75][2] + a[75][1]*FmTangential[75][2] - a[76][2]*FmTangential[76][1] - c[1]*FmTangential[76][2] + a[76][1]*FmTangential[76][2] - a[77][2]*FmTangential[77][1] - c[1]*FmTangential[77][2] + a[77][1]*FmTangential[77][2] - a[78][2]*FmTangential[78][1] - c[1]*FmTangential[78][2] + a[78][1]*FmTangential[78][2] - a[79][2]*FmTangential[79][1] - c[1]*FmTangential[79][2] + a[79][1]*FmTangential[79][2] - a[80][2]*FmTangential[80][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1] + FmTangential[19][1] + FmTangential[20][1] + FmTangential[21][1] + FmTangential[22][1] + FmTangential[23][1] + FmTangential[24][1] + FmTangential[25][1] + FmTangential[26][1] + FmTangential[27][1] + FmTangential[28][1] + FmTangential[29][1] + FmTangential[30][1] + FmTangential[31][1] + FmTangential[32][1] + FmTangential[33][1] + FmTangential[34][1] + FmTangential[35][1] + FmTangential[36][1] + FmTangential[37][1] + FmTangential[38][1] + FmTangential[39][1] + FmTangential[40][1] + FmTangential[41][1] + FmTangential[42][1] + FmTangential[43][1] + FmTangential[44][1] + FmTangential[45][1] + FmTangential[46][1] + FmTangential[47][1] + FmTangential[48][1] + FmTangential[49][1] + FmTangential[50][1] + FmTangential[51][1] + FmTangential[52][1] + FmTangential[53][1] + FmTangential[54][1] + FmTangential[55][1] + FmTangential[56][1] + FmTangential[57][1] + FmTangential[58][1] + FmTangential[59][1] + FmTangential[60][1] + FmTangential[61][1] + FmTangential[62][1] + FmTangential[63][1] + FmTangential[64][1] + FmTangential[65][1] + FmTangential[66][1] + FmTangential[67][1] + FmTangential[68][1] + FmTangential[69][1] + FmTangential[70][1] + FmTangential[71][1] + FmTangential[72][1] + FmTangential[73][1] + FmTangential[74][1] + FmTangential[75][1] + FmTangential[76][1] + FmTangential[77][1] + FmTangential[78][1] + FmTangential[79][1] + FmTangential[80][1]) - c[1]*FmTangential[80][2] + a[80][1]*FmTangential[80][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2] + a[10][2]*FmTangential[10][0] + c[0]*FmTangential[10][2] - a[10][0]*FmTangential[10][2] + a[11][2]*FmTangential[11][0] + c[0]*FmTangential[11][2] - a[11][0]*FmTangential[11][2] + a[12][2]*FmTangential[12][0] + c[0]*FmTangential[12][2] - a[12][0]*FmTangential[12][2] + a[13][2]*FmTangential[13][0] + c[0]*FmTangential[13][2] - a[13][0]*FmTangential[13][2] + a[14][2]*FmTangential[14][0] + c[0]*FmTangential[14][2] - a[14][0]*FmTangential[14][2] + a[15][2]*FmTangential[15][0] + c[0]*FmTangential[15][2] - a[15][0]*FmTangential[15][2] + a[16][2]*FmTangential[16][0] + c[0]*FmTangential[16][2] - a[16][0]*FmTangential[16][2] + a[17][2]*FmTangential[17][0] + c[0]*FmTangential[17][2] - a[17][0]*FmTangential[17][2] + a[18][2]*FmTangential[18][0] + c[0]*FmTangential[18][2] - a[18][0]*FmTangential[18][2] + a[19][2]*FmTangential[19][0] + c[0]*FmTangential[19][2] - a[19][0]*FmTangential[19][2] + a[20][2]*FmTangential[20][0] + c[0]*FmTangential[20][2] - a[20][0]*FmTangential[20][2] + a[21][2]*FmTangential[21][0] + c[0]*FmTangential[21][2] - a[21][0]*FmTangential[21][2] + a[22][2]*FmTangential[22][0] + c[0]*FmTangential[22][2] - a[22][0]*FmTangential[22][2] + a[23][2]*FmTangential[23][0] + c[0]*FmTangential[23][2] - a[23][0]*FmTangential[23][2] + a[24][2]*FmTangential[24][0] + c[0]*FmTangential[24][2] - a[24][0]*FmTangential[24][2] + a[25][2]*FmTangential[25][0] + c[0]*FmTangential[25][2] - a[25][0]*FmTangential[25][2] + a[26][2]*FmTangential[26][0] + c[0]*FmTangential[26][2] - a[26][0]*FmTangential[26][2] + a[27][2]*FmTangential[27][0] + c[0]*FmTangential[27][2] - a[27][0]*FmTangential[27][2] + a[28][2]*FmTangential[28][0] + c[0]*FmTangential[28][2] - a[28][0]*FmTangential[28][2] + a[29][2]*FmTangential[29][0] + c[0]*FmTangential[29][2] - a[29][0]*FmTangential[29][2] + a[30][2]*FmTangential[30][0] + c[0]*FmTangential[30][2] - a[30][0]*FmTangential[30][2] + a[31][2]*FmTangential[31][0] + c[0]*FmTangential[31][2] - a[31][0]*FmTangential[31][2] + a[32][2]*FmTangential[32][0] + c[0]*FmTangential[32][2] - a[32][0]*FmTangential[32][2] + a[33][2]*FmTangential[33][0] + c[0]*FmTangential[33][2] - a[33][0]*FmTangential[33][2] + a[34][2]*FmTangential[34][0] + c[0]*FmTangential[34][2] - a[34][0]*FmTangential[34][2] + a[35][2]*FmTangential[35][0] + c[0]*FmTangential[35][2] - a[35][0]*FmTangential[35][2] + a[36][2]*FmTangential[36][0] + c[0]*FmTangential[36][2] - a[36][0]*FmTangential[36][2] + a[37][2]*FmTangential[37][0] + c[0]*FmTangential[37][2] - a[37][0]*FmTangential[37][2] + a[38][2]*FmTangential[38][0] + c[0]*FmTangential[38][2] - a[38][0]*FmTangential[38][2] + a[39][2]*FmTangential[39][0] + c[0]*FmTangential[39][2] - a[39][0]*FmTangential[39][2] + a[40][2]*FmTangential[40][0] + c[0]*FmTangential[40][2] - a[40][0]*FmTangential[40][2] + a[41][2]*FmTangential[41][0] + c[0]*FmTangential[41][2] - a[41][0]*FmTangential[41][2] + a[42][2]*FmTangential[42][0] + c[0]*FmTangential[42][2] - a[42][0]*FmTangential[42][2] + a[43][2]*FmTangential[43][0] + c[0]*FmTangential[43][2] - a[43][0]*FmTangential[43][2] + a[44][2]*FmTangential[44][0] + c[0]*FmTangential[44][2] - a[44][0]*FmTangential[44][2] + a[45][2]*FmTangential[45][0] + c[0]*FmTangential[45][2] - a[45][0]*FmTangential[45][2] + a[46][2]*FmTangential[46][0] + c[0]*FmTangential[46][2] - a[46][0]*FmTangential[46][2] + a[47][2]*FmTangential[47][0] + c[0]*FmTangential[47][2] - a[47][0]*FmTangential[47][2] + a[48][2]*FmTangential[48][0] + c[0]*FmTangential[48][2] - a[48][0]*FmTangential[48][2] + a[49][2]*FmTangential[49][0] + c[0]*FmTangential[49][2] - a[49][0]*FmTangential[49][2] + a[50][2]*FmTangential[50][0] + c[0]*FmTangential[50][2] - a[50][0]*FmTangential[50][2] + a[51][2]*FmTangential[51][0] + c[0]*FmTangential[51][2] - a[51][0]*FmTangential[51][2] + a[52][2]*FmTangential[52][0] + c[0]*FmTangential[52][2] - a[52][0]*FmTangential[52][2] + a[53][2]*FmTangential[53][0] + c[0]*FmTangential[53][2] - a[53][0]*FmTangential[53][2] + a[54][2]*FmTangential[54][0] + c[0]*FmTangential[54][2] - a[54][0]*FmTangential[54][2] + a[55][2]*FmTangential[55][0] + c[0]*FmTangential[55][2] - a[55][0]*FmTangential[55][2] + a[56][2]*FmTangential[56][0] + c[0]*FmTangential[56][2] - a[56][0]*FmTangential[56][2] + a[57][2]*FmTangential[57][0] + c[0]*FmTangential[57][2] - a[57][0]*FmTangential[57][2] + a[58][2]*FmTangential[58][0] + c[0]*FmTangential[58][2] - a[58][0]*FmTangential[58][2] + a[59][2]*FmTangential[59][0] + c[0]*FmTangential[59][2] - a[59][0]*FmTangential[59][2] + a[60][2]*FmTangential[60][0] + c[0]*FmTangential[60][2] - a[60][0]*FmTangential[60][2] + a[61][2]*FmTangential[61][0] + c[0]*FmTangential[61][2] - a[61][0]*FmTangential[61][2] + a[62][2]*FmTangential[62][0] + c[0]*FmTangential[62][2] - a[62][0]*FmTangential[62][2] + a[63][2]*FmTangential[63][0] + c[0]*FmTangential[63][2] - a[63][0]*FmTangential[63][2] + a[64][2]*FmTangential[64][0] + c[0]*FmTangential[64][2] - a[64][0]*FmTangential[64][2] + a[65][2]*FmTangential[65][0] + c[0]*FmTangential[65][2] - a[65][0]*FmTangential[65][2] + a[66][2]*FmTangential[66][0] + c[0]*FmTangential[66][2] - a[66][0]*FmTangential[66][2] + a[67][2]*FmTangential[67][0] + c[0]*FmTangential[67][2] - a[67][0]*FmTangential[67][2] + a[68][2]*FmTangential[68][0] + c[0]*FmTangential[68][2] - a[68][0]*FmTangential[68][2] + a[69][2]*FmTangential[69][0] + c[0]*FmTangential[69][2] - a[69][0]*FmTangential[69][2] + a[70][2]*FmTangential[70][0] + c[0]*FmTangential[70][2] - a[70][0]*FmTangential[70][2] + a[71][2]*FmTangential[71][0] + c[0]*FmTangential[71][2] - a[71][0]*FmTangential[71][2] + a[72][2]*FmTangential[72][0] + c[0]*FmTangential[72][2] - a[72][0]*FmTangential[72][2] + a[73][2]*FmTangential[73][0] + c[0]*FmTangential[73][2] - a[73][0]*FmTangential[73][2] + a[74][2]*FmTangential[74][0] + c[0]*FmTangential[74][2] - a[74][0]*FmTangential[74][2] + a[75][2]*FmTangential[75][0] + c[0]*FmTangential[75][2] - a[75][0]*FmTangential[75][2] + a[76][2]*FmTangential[76][0] + c[0]*FmTangential[76][2] - a[76][0]*FmTangential[76][2] + a[77][2]*FmTangential[77][0] + c[0]*FmTangential[77][2] - a[77][0]*FmTangential[77][2] + a[78][2]*FmTangential[78][0] + c[0]*FmTangential[78][2] - a[78][0]*FmTangential[78][2] + a[79][2]*FmTangential[79][0] + c[0]*FmTangential[79][2] - a[79][0]*FmTangential[79][2] + a[80][2]*FmTangential[80][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0] + FmTangential[41][0] + FmTangential[42][0] + FmTangential[43][0] + FmTangential[44][0] + FmTangential[45][0] + FmTangential[46][0] + FmTangential[47][0] + FmTangential[48][0] + FmTangential[49][0] + FmTangential[50][0] + FmTangential[51][0] + FmTangential[52][0] + FmTangential[53][0] + FmTangential[54][0] + FmTangential[55][0] + FmTangential[56][0] + FmTangential[57][0] + FmTangential[58][0] + FmTangential[59][0] + FmTangential[60][0] + FmTangential[61][0] + FmTangential[62][0] + FmTangential[63][0] + FmTangential[64][0] + FmTangential[65][0] + FmTangential[66][0] + FmTangential[67][0] + FmTangential[68][0] + FmTangential[69][0] + FmTangential[70][0] + FmTangential[71][0] + FmTangential[72][0] + FmTangential[73][0] + FmTangential[74][0] + FmTangential[75][0] + FmTangential[76][0] + FmTangential[77][0] + FmTangential[78][0] + FmTangential[79][0] + FmTangential[80][0]) + c[0]*FmTangential[80][2] - a[80][0]*FmTangential[80][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1] - a[10][1]*FmTangential[10][0] - c[0]*FmTangential[10][1] + a[10][0]*FmTangential[10][1] - a[11][1]*FmTangential[11][0] - c[0]*FmTangential[11][1] + a[11][0]*FmTangential[11][1] - a[12][1]*FmTangential[12][0] - c[0]*FmTangential[12][1] + a[12][0]*FmTangential[12][1] - a[13][1]*FmTangential[13][0] - c[0]*FmTangential[13][1] + a[13][0]*FmTangential[13][1] - a[14][1]*FmTangential[14][0] - c[0]*FmTangential[14][1] + a[14][0]*FmTangential[14][1] - a[15][1]*FmTangential[15][0] - c[0]*FmTangential[15][1] + a[15][0]*FmTangential[15][1] - a[16][1]*FmTangential[16][0] - c[0]*FmTangential[16][1] + a[16][0]*FmTangential[16][1] - a[17][1]*FmTangential[17][0] - c[0]*FmTangential[17][1] + a[17][0]*FmTangential[17][1] - a[18][1]*FmTangential[18][0] - c[0]*FmTangential[18][1] + a[18][0]*FmTangential[18][1] - a[19][1]*FmTangential[19][0] - c[0]*FmTangential[19][1] + a[19][0]*FmTangential[19][1] - a[20][1]*FmTangential[20][0] - c[0]*FmTangential[20][1] + a[20][0]*FmTangential[20][1] - a[21][1]*FmTangential[21][0] - c[0]*FmTangential[21][1] + a[21][0]*FmTangential[21][1] - a[22][1]*FmTangential[22][0] - c[0]*FmTangential[22][1] + a[22][0]*FmTangential[22][1] - a[23][1]*FmTangential[23][0] - c[0]*FmTangential[23][1] + a[23][0]*FmTangential[23][1] - a[24][1]*FmTangential[24][0] - c[0]*FmTangential[24][1] + a[24][0]*FmTangential[24][1] - a[25][1]*FmTangential[25][0] - c[0]*FmTangential[25][1] + a[25][0]*FmTangential[25][1] - a[26][1]*FmTangential[26][0] - c[0]*FmTangential[26][1] + a[26][0]*FmTangential[26][1] - a[27][1]*FmTangential[27][0] - c[0]*FmTangential[27][1] + a[27][0]*FmTangential[27][1] - a[28][1]*FmTangential[28][0] - c[0]*FmTangential[28][1] + a[28][0]*FmTangential[28][1] - a[29][1]*FmTangential[29][0] - c[0]*FmTangential[29][1] + a[29][0]*FmTangential[29][1] - a[30][1]*FmTangential[30][0] - c[0]*FmTangential[30][1] + a[30][0]*FmTangential[30][1] - a[31][1]*FmTangential[31][0] - c[0]*FmTangential[31][1] + a[31][0]*FmTangential[31][1] - a[32][1]*FmTangential[32][0] - c[0]*FmTangential[32][1] + a[32][0]*FmTangential[32][1] - a[33][1]*FmTangential[33][0] - c[0]*FmTangential[33][1] + a[33][0]*FmTangential[33][1] - a[34][1]*FmTangential[34][0] - c[0]*FmTangential[34][1] + a[34][0]*FmTangential[34][1] - a[35][1]*FmTangential[35][0] - c[0]*FmTangential[35][1] + a[35][0]*FmTangential[35][1] - a[36][1]*FmTangential[36][0] - c[0]*FmTangential[36][1] + a[36][0]*FmTangential[36][1] - a[37][1]*FmTangential[37][0] - c[0]*FmTangential[37][1] + a[37][0]*FmTangential[37][1] - a[38][1]*FmTangential[38][0] - c[0]*FmTangential[38][1] + a[38][0]*FmTangential[38][1] - a[39][1]*FmTangential[39][0] - c[0]*FmTangential[39][1] + a[39][0]*FmTangential[39][1] - a[40][1]*FmTangential[40][0] - c[0]*FmTangential[40][1] + a[40][0]*FmTangential[40][1] - a[41][1]*FmTangential[41][0] - c[0]*FmTangential[41][1] + a[41][0]*FmTangential[41][1] - a[42][1]*FmTangential[42][0] - c[0]*FmTangential[42][1] + a[42][0]*FmTangential[42][1] - a[43][1]*FmTangential[43][0] - c[0]*FmTangential[43][1] + a[43][0]*FmTangential[43][1] - a[44][1]*FmTangential[44][0] - c[0]*FmTangential[44][1] + a[44][0]*FmTangential[44][1] - a[45][1]*FmTangential[45][0] - c[0]*FmTangential[45][1] + a[45][0]*FmTangential[45][1] - a[46][1]*FmTangential[46][0] - c[0]*FmTangential[46][1] + a[46][0]*FmTangential[46][1] - a[47][1]*FmTangential[47][0] - c[0]*FmTangential[47][1] + a[47][0]*FmTangential[47][1] - a[48][1]*FmTangential[48][0] - c[0]*FmTangential[48][1] + a[48][0]*FmTangential[48][1] - a[49][1]*FmTangential[49][0] - c[0]*FmTangential[49][1] + a[49][0]*FmTangential[49][1] - a[50][1]*FmTangential[50][0] - c[0]*FmTangential[50][1] + a[50][0]*FmTangential[50][1] - a[51][1]*FmTangential[51][0] - c[0]*FmTangential[51][1] + a[51][0]*FmTangential[51][1] - a[52][1]*FmTangential[52][0] - c[0]*FmTangential[52][1] + a[52][0]*FmTangential[52][1] - a[53][1]*FmTangential[53][0] - c[0]*FmTangential[53][1] + a[53][0]*FmTangential[53][1] - a[54][1]*FmTangential[54][0] - c[0]*FmTangential[54][1] + a[54][0]*FmTangential[54][1] - a[55][1]*FmTangential[55][0] - c[0]*FmTangential[55][1] + a[55][0]*FmTangential[55][1] - a[56][1]*FmTangential[56][0] - c[0]*FmTangential[56][1] + a[56][0]*FmTangential[56][1] - a[57][1]*FmTangential[57][0] - c[0]*FmTangential[57][1] + a[57][0]*FmTangential[57][1] - a[58][1]*FmTangential[58][0] - c[0]*FmTangential[58][1] + a[58][0]*FmTangential[58][1] - a[59][1]*FmTangential[59][0] - c[0]*FmTangential[59][1] + a[59][0]*FmTangential[59][1] - a[60][1]*FmTangential[60][0] - c[0]*FmTangential[60][1] + a[60][0]*FmTangential[60][1] - a[61][1]*FmTangential[61][0] - c[0]*FmTangential[61][1] + a[61][0]*FmTangential[61][1] - a[62][1]*FmTangential[62][0] - c[0]*FmTangential[62][1] + a[62][0]*FmTangential[62][1] - a[63][1]*FmTangential[63][0] - c[0]*FmTangential[63][1] + a[63][0]*FmTangential[63][1] - a[64][1]*FmTangential[64][0] - c[0]*FmTangential[64][1] + a[64][0]*FmTangential[64][1] - a[65][1]*FmTangential[65][0] - c[0]*FmTangential[65][1] + a[65][0]*FmTangential[65][1] - a[66][1]*FmTangential[66][0] - c[0]*FmTangential[66][1] + a[66][0]*FmTangential[66][1] - a[67][1]*FmTangential[67][0] - c[0]*FmTangential[67][1] + a[67][0]*FmTangential[67][1] - a[68][1]*FmTangential[68][0] - c[0]*FmTangential[68][1] + a[68][0]*FmTangential[68][1] - a[69][1]*FmTangential[69][0] - c[0]*FmTangential[69][1] + a[69][0]*FmTangential[69][1] - a[70][1]*FmTangential[70][0] - c[0]*FmTangential[70][1] + a[70][0]*FmTangential[70][1] - a[71][1]*FmTangential[71][0] - c[0]*FmTangential[71][1] + a[71][0]*FmTangential[71][1] - a[72][1]*FmTangential[72][0] - c[0]*FmTangential[72][1] + a[72][0]*FmTangential[72][1] - a[73][1]*FmTangential[73][0] - c[0]*FmTangential[73][1] + a[73][0]*FmTangential[73][1] - a[74][1]*FmTangential[74][0] - c[0]*FmTangential[74][1] + a[74][0]*FmTangential[74][1] - a[75][1]*FmTangential[75][0] - c[0]*FmTangential[75][1] + a[75][0]*FmTangential[75][1] - a[76][1]*FmTangential[76][0] - c[0]*FmTangential[76][1] + a[76][0]*FmTangential[76][1] - a[77][1]*FmTangential[77][0] - c[0]*FmTangential[77][1] + a[77][0]*FmTangential[77][1] - a[78][1]*FmTangential[78][0] - c[0]*FmTangential[78][1] + a[78][0]*FmTangential[78][1] - a[79][1]*FmTangential[79][0] - c[0]*FmTangential[79][1] + a[79][0]*FmTangential[79][1] - a[80][1]*FmTangential[80][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0] + FmTangential[41][0] + FmTangential[42][0] + FmTangential[43][0] + FmTangential[44][0] + FmTangential[45][0] + FmTangential[46][0] + FmTangential[47][0] + FmTangential[48][0] + FmTangential[49][0] + FmTangential[50][0] + FmTangential[51][0] + FmTangential[52][0] + FmTangential[53][0] + FmTangential[54][0] + FmTangential[55][0] + FmTangential[56][0] + FmTangential[57][0] + FmTangential[58][0] + FmTangential[59][0] + FmTangential[60][0] + FmTangential[61][0] + FmTangential[62][0] + FmTangential[63][0] + FmTangential[64][0] + FmTangential[65][0] + FmTangential[66][0] + FmTangential[67][0] + FmTangential[68][0] + FmTangential[69][0] + FmTangential[70][0] + FmTangential[71][0] + FmTangential[72][0] + FmTangential[73][0] + FmTangential[74][0] + FmTangential[75][0] + FmTangential[76][0] + FmTangential[77][0] + FmTangential[78][0] + FmTangential[79][0] + FmTangential[80][0]) - c[0]*FmTangential[80][1] + a[80][0]*FmTangential[80][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            a1[10][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[10][0] + theta[2]*a[10][1] - theta1[2]*a[10][1] - theta[1]*a[10][2] + theta1[1]*a[10][2];

            a1[10][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[10][0] + theta1[2]*a[10][0] + a[10][1] + theta[0]*a[10][2] - theta1[0]*a[10][2];

            a1[10][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[10][0] - theta1[1]*a[10][0] - theta[0]*a[10][1] + theta1[0]*a[10][1] + a[10][2];

            a1[11][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[11][0] + theta[2]*a[11][1] - theta1[2]*a[11][1] - theta[1]*a[11][2] + theta1[1]*a[11][2];

            a1[11][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[11][0] + theta1[2]*a[11][0] + a[11][1] + theta[0]*a[11][2] - theta1[0]*a[11][2];

            a1[11][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[11][0] - theta1[1]*a[11][0] - theta[0]*a[11][1] + theta1[0]*a[11][1] + a[11][2];

            a1[12][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[12][0] + theta[2]*a[12][1] - theta1[2]*a[12][1] - theta[1]*a[12][2] + theta1[1]*a[12][2];

            a1[12][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[12][0] + theta1[2]*a[12][0] + a[12][1] + theta[0]*a[12][2] - theta1[0]*a[12][2];

            a1[12][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[12][0] - theta1[1]*a[12][0] - theta[0]*a[12][1] + theta1[0]*a[12][1] + a[12][2];

            a1[13][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[13][0] + theta[2]*a[13][1] - theta1[2]*a[13][1] - theta[1]*a[13][2] + theta1[1]*a[13][2];

            a1[13][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[13][0] + theta1[2]*a[13][0] + a[13][1] + theta[0]*a[13][2] - theta1[0]*a[13][2];

            a1[13][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[13][0] - theta1[1]*a[13][0] - theta[0]*a[13][1] + theta1[0]*a[13][1] + a[13][2];

            a1[14][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[14][0] + theta[2]*a[14][1] - theta1[2]*a[14][1] - theta[1]*a[14][2] + theta1[1]*a[14][2];

            a1[14][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[14][0] + theta1[2]*a[14][0] + a[14][1] + theta[0]*a[14][2] - theta1[0]*a[14][2];

            a1[14][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[14][0] - theta1[1]*a[14][0] - theta[0]*a[14][1] + theta1[0]*a[14][1] + a[14][2];

            a1[15][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[15][0] + theta[2]*a[15][1] - theta1[2]*a[15][1] - theta[1]*a[15][2] + theta1[1]*a[15][2];

            a1[15][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[15][0] + theta1[2]*a[15][0] + a[15][1] + theta[0]*a[15][2] - theta1[0]*a[15][2];

            a1[15][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[15][0] - theta1[1]*a[15][0] - theta[0]*a[15][1] + theta1[0]*a[15][1] + a[15][2];

            a1[16][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[16][0] + theta[2]*a[16][1] - theta1[2]*a[16][1] - theta[1]*a[16][2] + theta1[1]*a[16][2];

            a1[16][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[16][0] + theta1[2]*a[16][0] + a[16][1] + theta[0]*a[16][2] - theta1[0]*a[16][2];

            a1[16][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[16][0] - theta1[1]*a[16][0] - theta[0]*a[16][1] + theta1[0]*a[16][1] + a[16][2];

            a1[17][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[17][0] + theta[2]*a[17][1] - theta1[2]*a[17][1] - theta[1]*a[17][2] + theta1[1]*a[17][2];

            a1[17][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[17][0] + theta1[2]*a[17][0] + a[17][1] + theta[0]*a[17][2] - theta1[0]*a[17][2];

            a1[17][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[17][0] - theta1[1]*a[17][0] - theta[0]*a[17][1] + theta1[0]*a[17][1] + a[17][2];

            a1[18][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[18][0] + theta[2]*a[18][1] - theta1[2]*a[18][1] - theta[1]*a[18][2] + theta1[1]*a[18][2];

            a1[18][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[18][0] + theta1[2]*a[18][0] + a[18][1] + theta[0]*a[18][2] - theta1[0]*a[18][2];

            a1[18][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[18][0] - theta1[1]*a[18][0] - theta[0]*a[18][1] + theta1[0]*a[18][1] + a[18][2];

            a1[19][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[19][0] + theta[2]*a[19][1] - theta1[2]*a[19][1] - theta[1]*a[19][2] + theta1[1]*a[19][2];

            a1[19][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[19][0] + theta1[2]*a[19][0] + a[19][1] + theta[0]*a[19][2] - theta1[0]*a[19][2];

            a1[19][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[19][0] - theta1[1]*a[19][0] - theta[0]*a[19][1] + theta1[0]*a[19][1] + a[19][2];

            a1[20][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[20][0] + theta[2]*a[20][1] - theta1[2]*a[20][1] - theta[1]*a[20][2] + theta1[1]*a[20][2];

            a1[20][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[20][0] + theta1[2]*a[20][0] + a[20][1] + theta[0]*a[20][2] - theta1[0]*a[20][2];

            a1[20][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[20][0] - theta1[1]*a[20][0] - theta[0]*a[20][1] + theta1[0]*a[20][1] + a[20][2];

            a1[21][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[21][0] + theta[2]*a[21][1] - theta1[2]*a[21][1] - theta[1]*a[21][2] + theta1[1]*a[21][2];

            a1[21][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[21][0] + theta1[2]*a[21][0] + a[21][1] + theta[0]*a[21][2] - theta1[0]*a[21][2];

            a1[21][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[21][0] - theta1[1]*a[21][0] - theta[0]*a[21][1] + theta1[0]*a[21][1] + a[21][2];

            a1[22][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[22][0] + theta[2]*a[22][1] - theta1[2]*a[22][1] - theta[1]*a[22][2] + theta1[1]*a[22][2];

            a1[22][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[22][0] + theta1[2]*a[22][0] + a[22][1] + theta[0]*a[22][2] - theta1[0]*a[22][2];

            a1[22][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[22][0] - theta1[1]*a[22][0] - theta[0]*a[22][1] + theta1[0]*a[22][1] + a[22][2];

            a1[23][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[23][0] + theta[2]*a[23][1] - theta1[2]*a[23][1] - theta[1]*a[23][2] + theta1[1]*a[23][2];

            a1[23][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[23][0] + theta1[2]*a[23][0] + a[23][1] + theta[0]*a[23][2] - theta1[0]*a[23][2];

            a1[23][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[23][0] - theta1[1]*a[23][0] - theta[0]*a[23][1] + theta1[0]*a[23][1] + a[23][2];

            a1[24][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[24][0] + theta[2]*a[24][1] - theta1[2]*a[24][1] - theta[1]*a[24][2] + theta1[1]*a[24][2];

            a1[24][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[24][0] + theta1[2]*a[24][0] + a[24][1] + theta[0]*a[24][2] - theta1[0]*a[24][2];

            a1[24][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[24][0] - theta1[1]*a[24][0] - theta[0]*a[24][1] + theta1[0]*a[24][1] + a[24][2];

            a1[25][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[25][0] + theta[2]*a[25][1] - theta1[2]*a[25][1] - theta[1]*a[25][2] + theta1[1]*a[25][2];

            a1[25][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[25][0] + theta1[2]*a[25][0] + a[25][1] + theta[0]*a[25][2] - theta1[0]*a[25][2];

            a1[25][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[25][0] - theta1[1]*a[25][0] - theta[0]*a[25][1] + theta1[0]*a[25][1] + a[25][2];

            a1[26][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[26][0] + theta[2]*a[26][1] - theta1[2]*a[26][1] - theta[1]*a[26][2] + theta1[1]*a[26][2];

            a1[26][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[26][0] + theta1[2]*a[26][0] + a[26][1] + theta[0]*a[26][2] - theta1[0]*a[26][2];

            a1[26][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[26][0] - theta1[1]*a[26][0] - theta[0]*a[26][1] + theta1[0]*a[26][1] + a[26][2];

            a1[27][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[27][0] + theta[2]*a[27][1] - theta1[2]*a[27][1] - theta[1]*a[27][2] + theta1[1]*a[27][2];

            a1[27][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[27][0] + theta1[2]*a[27][0] + a[27][1] + theta[0]*a[27][2] - theta1[0]*a[27][2];

            a1[27][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[27][0] - theta1[1]*a[27][0] - theta[0]*a[27][1] + theta1[0]*a[27][1] + a[27][2];

            a1[28][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[28][0] + theta[2]*a[28][1] - theta1[2]*a[28][1] - theta[1]*a[28][2] + theta1[1]*a[28][2];

            a1[28][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[28][0] + theta1[2]*a[28][0] + a[28][1] + theta[0]*a[28][2] - theta1[0]*a[28][2];

            a1[28][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[28][0] - theta1[1]*a[28][0] - theta[0]*a[28][1] + theta1[0]*a[28][1] + a[28][2];

            a1[29][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[29][0] + theta[2]*a[29][1] - theta1[2]*a[29][1] - theta[1]*a[29][2] + theta1[1]*a[29][2];

            a1[29][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[29][0] + theta1[2]*a[29][0] + a[29][1] + theta[0]*a[29][2] - theta1[0]*a[29][2];

            a1[29][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[29][0] - theta1[1]*a[29][0] - theta[0]*a[29][1] + theta1[0]*a[29][1] + a[29][2];

            a1[30][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[30][0] + theta[2]*a[30][1] - theta1[2]*a[30][1] - theta[1]*a[30][2] + theta1[1]*a[30][2];

            a1[30][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[30][0] + theta1[2]*a[30][0] + a[30][1] + theta[0]*a[30][2] - theta1[0]*a[30][2];

            a1[30][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[30][0] - theta1[1]*a[30][0] - theta[0]*a[30][1] + theta1[0]*a[30][1] + a[30][2];

            a1[31][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[31][0] + theta[2]*a[31][1] - theta1[2]*a[31][1] - theta[1]*a[31][2] + theta1[1]*a[31][2];

            a1[31][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[31][0] + theta1[2]*a[31][0] + a[31][1] + theta[0]*a[31][2] - theta1[0]*a[31][2];

            a1[31][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[31][0] - theta1[1]*a[31][0] - theta[0]*a[31][1] + theta1[0]*a[31][1] + a[31][2];

            a1[32][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[32][0] + theta[2]*a[32][1] - theta1[2]*a[32][1] - theta[1]*a[32][2] + theta1[1]*a[32][2];

            a1[32][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[32][0] + theta1[2]*a[32][0] + a[32][1] + theta[0]*a[32][2] - theta1[0]*a[32][2];

            a1[32][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[32][0] - theta1[1]*a[32][0] - theta[0]*a[32][1] + theta1[0]*a[32][1] + a[32][2];

            a1[33][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[33][0] + theta[2]*a[33][1] - theta1[2]*a[33][1] - theta[1]*a[33][2] + theta1[1]*a[33][2];

            a1[33][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[33][0] + theta1[2]*a[33][0] + a[33][1] + theta[0]*a[33][2] - theta1[0]*a[33][2];

            a1[33][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[33][0] - theta1[1]*a[33][0] - theta[0]*a[33][1] + theta1[0]*a[33][1] + a[33][2];

            a1[34][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[34][0] + theta[2]*a[34][1] - theta1[2]*a[34][1] - theta[1]*a[34][2] + theta1[1]*a[34][2];

            a1[34][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[34][0] + theta1[2]*a[34][0] + a[34][1] + theta[0]*a[34][2] - theta1[0]*a[34][2];

            a1[34][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[34][0] - theta1[1]*a[34][0] - theta[0]*a[34][1] + theta1[0]*a[34][1] + a[34][2];

            a1[35][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[35][0] + theta[2]*a[35][1] - theta1[2]*a[35][1] - theta[1]*a[35][2] + theta1[1]*a[35][2];

            a1[35][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[35][0] + theta1[2]*a[35][0] + a[35][1] + theta[0]*a[35][2] - theta1[0]*a[35][2];

            a1[35][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[35][0] - theta1[1]*a[35][0] - theta[0]*a[35][1] + theta1[0]*a[35][1] + a[35][2];

            a1[36][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[36][0] + theta[2]*a[36][1] - theta1[2]*a[36][1] - theta[1]*a[36][2] + theta1[1]*a[36][2];

            a1[36][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[36][0] + theta1[2]*a[36][0] + a[36][1] + theta[0]*a[36][2] - theta1[0]*a[36][2];

            a1[36][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[36][0] - theta1[1]*a[36][0] - theta[0]*a[36][1] + theta1[0]*a[36][1] + a[36][2];

            a1[37][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[37][0] + theta[2]*a[37][1] - theta1[2]*a[37][1] - theta[1]*a[37][2] + theta1[1]*a[37][2];

            a1[37][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[37][0] + theta1[2]*a[37][0] + a[37][1] + theta[0]*a[37][2] - theta1[0]*a[37][2];

            a1[37][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[37][0] - theta1[1]*a[37][0] - theta[0]*a[37][1] + theta1[0]*a[37][1] + a[37][2];

            a1[38][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[38][0] + theta[2]*a[38][1] - theta1[2]*a[38][1] - theta[1]*a[38][2] + theta1[1]*a[38][2];

            a1[38][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[38][0] + theta1[2]*a[38][0] + a[38][1] + theta[0]*a[38][2] - theta1[0]*a[38][2];

            a1[38][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[38][0] - theta1[1]*a[38][0] - theta[0]*a[38][1] + theta1[0]*a[38][1] + a[38][2];

            a1[39][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[39][0] + theta[2]*a[39][1] - theta1[2]*a[39][1] - theta[1]*a[39][2] + theta1[1]*a[39][2];

            a1[39][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[39][0] + theta1[2]*a[39][0] + a[39][1] + theta[0]*a[39][2] - theta1[0]*a[39][2];

            a1[39][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[39][0] - theta1[1]*a[39][0] - theta[0]*a[39][1] + theta1[0]*a[39][1] + a[39][2];

            a1[40][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[40][0] + theta[2]*a[40][1] - theta1[2]*a[40][1] - theta[1]*a[40][2] + theta1[1]*a[40][2];

            a1[40][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[40][0] + theta1[2]*a[40][0] + a[40][1] + theta[0]*a[40][2] - theta1[0]*a[40][2];

            a1[40][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[40][0] - theta1[1]*a[40][0] - theta[0]*a[40][1] + theta1[0]*a[40][1] + a[40][2];

            a1[41][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[41][0] + theta[2]*a[41][1] - theta1[2]*a[41][1] - theta[1]*a[41][2] + theta1[1]*a[41][2];

            a1[41][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[41][0] + theta1[2]*a[41][0] + a[41][1] + theta[0]*a[41][2] - theta1[0]*a[41][2];

            a1[41][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[41][0] - theta1[1]*a[41][0] - theta[0]*a[41][1] + theta1[0]*a[41][1] + a[41][2];

            a1[42][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[42][0] + theta[2]*a[42][1] - theta1[2]*a[42][1] - theta[1]*a[42][2] + theta1[1]*a[42][2];

            a1[42][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[42][0] + theta1[2]*a[42][0] + a[42][1] + theta[0]*a[42][2] - theta1[0]*a[42][2];

            a1[42][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[42][0] - theta1[1]*a[42][0] - theta[0]*a[42][1] + theta1[0]*a[42][1] + a[42][2];

            a1[43][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[43][0] + theta[2]*a[43][1] - theta1[2]*a[43][1] - theta[1]*a[43][2] + theta1[1]*a[43][2];

            a1[43][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[43][0] + theta1[2]*a[43][0] + a[43][1] + theta[0]*a[43][2] - theta1[0]*a[43][2];

            a1[43][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[43][0] - theta1[1]*a[43][0] - theta[0]*a[43][1] + theta1[0]*a[43][1] + a[43][2];

            a1[44][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[44][0] + theta[2]*a[44][1] - theta1[2]*a[44][1] - theta[1]*a[44][2] + theta1[1]*a[44][2];

            a1[44][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[44][0] + theta1[2]*a[44][0] + a[44][1] + theta[0]*a[44][2] - theta1[0]*a[44][2];

            a1[44][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[44][0] - theta1[1]*a[44][0] - theta[0]*a[44][1] + theta1[0]*a[44][1] + a[44][2];

            a1[45][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[45][0] + theta[2]*a[45][1] - theta1[2]*a[45][1] - theta[1]*a[45][2] + theta1[1]*a[45][2];

            a1[45][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[45][0] + theta1[2]*a[45][0] + a[45][1] + theta[0]*a[45][2] - theta1[0]*a[45][2];

            a1[45][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[45][0] - theta1[1]*a[45][0] - theta[0]*a[45][1] + theta1[0]*a[45][1] + a[45][2];

            a1[46][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[46][0] + theta[2]*a[46][1] - theta1[2]*a[46][1] - theta[1]*a[46][2] + theta1[1]*a[46][2];

            a1[46][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[46][0] + theta1[2]*a[46][0] + a[46][1] + theta[0]*a[46][2] - theta1[0]*a[46][2];

            a1[46][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[46][0] - theta1[1]*a[46][0] - theta[0]*a[46][1] + theta1[0]*a[46][1] + a[46][2];

            a1[47][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[47][0] + theta[2]*a[47][1] - theta1[2]*a[47][1] - theta[1]*a[47][2] + theta1[1]*a[47][2];

            a1[47][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[47][0] + theta1[2]*a[47][0] + a[47][1] + theta[0]*a[47][2] - theta1[0]*a[47][2];

            a1[47][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[47][0] - theta1[1]*a[47][0] - theta[0]*a[47][1] + theta1[0]*a[47][1] + a[47][2];

            a1[48][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[48][0] + theta[2]*a[48][1] - theta1[2]*a[48][1] - theta[1]*a[48][2] + theta1[1]*a[48][2];

            a1[48][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[48][0] + theta1[2]*a[48][0] + a[48][1] + theta[0]*a[48][2] - theta1[0]*a[48][2];

            a1[48][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[48][0] - theta1[1]*a[48][0] - theta[0]*a[48][1] + theta1[0]*a[48][1] + a[48][2];

            a1[49][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[49][0] + theta[2]*a[49][1] - theta1[2]*a[49][1] - theta[1]*a[49][2] + theta1[1]*a[49][2];

            a1[49][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[49][0] + theta1[2]*a[49][0] + a[49][1] + theta[0]*a[49][2] - theta1[0]*a[49][2];

            a1[49][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[49][0] - theta1[1]*a[49][0] - theta[0]*a[49][1] + theta1[0]*a[49][1] + a[49][2];

            a1[50][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[50][0] + theta[2]*a[50][1] - theta1[2]*a[50][1] - theta[1]*a[50][2] + theta1[1]*a[50][2];

            a1[50][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[50][0] + theta1[2]*a[50][0] + a[50][1] + theta[0]*a[50][2] - theta1[0]*a[50][2];

            a1[50][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[50][0] - theta1[1]*a[50][0] - theta[0]*a[50][1] + theta1[0]*a[50][1] + a[50][2];

            a1[51][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[51][0] + theta[2]*a[51][1] - theta1[2]*a[51][1] - theta[1]*a[51][2] + theta1[1]*a[51][2];

            a1[51][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[51][0] + theta1[2]*a[51][0] + a[51][1] + theta[0]*a[51][2] - theta1[0]*a[51][2];

            a1[51][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[51][0] - theta1[1]*a[51][0] - theta[0]*a[51][1] + theta1[0]*a[51][1] + a[51][2];

            a1[52][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[52][0] + theta[2]*a[52][1] - theta1[2]*a[52][1] - theta[1]*a[52][2] + theta1[1]*a[52][2];

            a1[52][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[52][0] + theta1[2]*a[52][0] + a[52][1] + theta[0]*a[52][2] - theta1[0]*a[52][2];

            a1[52][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[52][0] - theta1[1]*a[52][0] - theta[0]*a[52][1] + theta1[0]*a[52][1] + a[52][2];

            a1[53][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[53][0] + theta[2]*a[53][1] - theta1[2]*a[53][1] - theta[1]*a[53][2] + theta1[1]*a[53][2];

            a1[53][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[53][0] + theta1[2]*a[53][0] + a[53][1] + theta[0]*a[53][2] - theta1[0]*a[53][2];

            a1[53][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[53][0] - theta1[1]*a[53][0] - theta[0]*a[53][1] + theta1[0]*a[53][1] + a[53][2];

            a1[54][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[54][0] + theta[2]*a[54][1] - theta1[2]*a[54][1] - theta[1]*a[54][2] + theta1[1]*a[54][2];

            a1[54][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[54][0] + theta1[2]*a[54][0] + a[54][1] + theta[0]*a[54][2] - theta1[0]*a[54][2];

            a1[54][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[54][0] - theta1[1]*a[54][0] - theta[0]*a[54][1] + theta1[0]*a[54][1] + a[54][2];

            a1[55][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[55][0] + theta[2]*a[55][1] - theta1[2]*a[55][1] - theta[1]*a[55][2] + theta1[1]*a[55][2];

            a1[55][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[55][0] + theta1[2]*a[55][0] + a[55][1] + theta[0]*a[55][2] - theta1[0]*a[55][2];

            a1[55][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[55][0] - theta1[1]*a[55][0] - theta[0]*a[55][1] + theta1[0]*a[55][1] + a[55][2];

            a1[56][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[56][0] + theta[2]*a[56][1] - theta1[2]*a[56][1] - theta[1]*a[56][2] + theta1[1]*a[56][2];

            a1[56][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[56][0] + theta1[2]*a[56][0] + a[56][1] + theta[0]*a[56][2] - theta1[0]*a[56][2];

            a1[56][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[56][0] - theta1[1]*a[56][0] - theta[0]*a[56][1] + theta1[0]*a[56][1] + a[56][2];

            a1[57][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[57][0] + theta[2]*a[57][1] - theta1[2]*a[57][1] - theta[1]*a[57][2] + theta1[1]*a[57][2];

            a1[57][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[57][0] + theta1[2]*a[57][0] + a[57][1] + theta[0]*a[57][2] - theta1[0]*a[57][2];

            a1[57][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[57][0] - theta1[1]*a[57][0] - theta[0]*a[57][1] + theta1[0]*a[57][1] + a[57][2];

            a1[58][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[58][0] + theta[2]*a[58][1] - theta1[2]*a[58][1] - theta[1]*a[58][2] + theta1[1]*a[58][2];

            a1[58][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[58][0] + theta1[2]*a[58][0] + a[58][1] + theta[0]*a[58][2] - theta1[0]*a[58][2];

            a1[58][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[58][0] - theta1[1]*a[58][0] - theta[0]*a[58][1] + theta1[0]*a[58][1] + a[58][2];

            a1[59][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[59][0] + theta[2]*a[59][1] - theta1[2]*a[59][1] - theta[1]*a[59][2] + theta1[1]*a[59][2];

            a1[59][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[59][0] + theta1[2]*a[59][0] + a[59][1] + theta[0]*a[59][2] - theta1[0]*a[59][2];

            a1[59][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[59][0] - theta1[1]*a[59][0] - theta[0]*a[59][1] + theta1[0]*a[59][1] + a[59][2];

            a1[60][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[60][0] + theta[2]*a[60][1] - theta1[2]*a[60][1] - theta[1]*a[60][2] + theta1[1]*a[60][2];

            a1[60][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[60][0] + theta1[2]*a[60][0] + a[60][1] + theta[0]*a[60][2] - theta1[0]*a[60][2];

            a1[60][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[60][0] - theta1[1]*a[60][0] - theta[0]*a[60][1] + theta1[0]*a[60][1] + a[60][2];

            a1[61][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[61][0] + theta[2]*a[61][1] - theta1[2]*a[61][1] - theta[1]*a[61][2] + theta1[1]*a[61][2];

            a1[61][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[61][0] + theta1[2]*a[61][0] + a[61][1] + theta[0]*a[61][2] - theta1[0]*a[61][2];

            a1[61][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[61][0] - theta1[1]*a[61][0] - theta[0]*a[61][1] + theta1[0]*a[61][1] + a[61][2];

            a1[62][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[62][0] + theta[2]*a[62][1] - theta1[2]*a[62][1] - theta[1]*a[62][2] + theta1[1]*a[62][2];

            a1[62][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[62][0] + theta1[2]*a[62][0] + a[62][1] + theta[0]*a[62][2] - theta1[0]*a[62][2];

            a1[62][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[62][0] - theta1[1]*a[62][0] - theta[0]*a[62][1] + theta1[0]*a[62][1] + a[62][2];

            a1[63][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[63][0] + theta[2]*a[63][1] - theta1[2]*a[63][1] - theta[1]*a[63][2] + theta1[1]*a[63][2];

            a1[63][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[63][0] + theta1[2]*a[63][0] + a[63][1] + theta[0]*a[63][2] - theta1[0]*a[63][2];

            a1[63][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[63][0] - theta1[1]*a[63][0] - theta[0]*a[63][1] + theta1[0]*a[63][1] + a[63][2];

            a1[64][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[64][0] + theta[2]*a[64][1] - theta1[2]*a[64][1] - theta[1]*a[64][2] + theta1[1]*a[64][2];

            a1[64][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[64][0] + theta1[2]*a[64][0] + a[64][1] + theta[0]*a[64][2] - theta1[0]*a[64][2];

            a1[64][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[64][0] - theta1[1]*a[64][0] - theta[0]*a[64][1] + theta1[0]*a[64][1] + a[64][2];

            a1[65][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[65][0] + theta[2]*a[65][1] - theta1[2]*a[65][1] - theta[1]*a[65][2] + theta1[1]*a[65][2];

            a1[65][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[65][0] + theta1[2]*a[65][0] + a[65][1] + theta[0]*a[65][2] - theta1[0]*a[65][2];

            a1[65][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[65][0] - theta1[1]*a[65][0] - theta[0]*a[65][1] + theta1[0]*a[65][1] + a[65][2];

            a1[66][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[66][0] + theta[2]*a[66][1] - theta1[2]*a[66][1] - theta[1]*a[66][2] + theta1[1]*a[66][2];

            a1[66][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[66][0] + theta1[2]*a[66][0] + a[66][1] + theta[0]*a[66][2] - theta1[0]*a[66][2];

            a1[66][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[66][0] - theta1[1]*a[66][0] - theta[0]*a[66][1] + theta1[0]*a[66][1] + a[66][2];

            a1[67][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[67][0] + theta[2]*a[67][1] - theta1[2]*a[67][1] - theta[1]*a[67][2] + theta1[1]*a[67][2];

            a1[67][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[67][0] + theta1[2]*a[67][0] + a[67][1] + theta[0]*a[67][2] - theta1[0]*a[67][2];

            a1[67][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[67][0] - theta1[1]*a[67][0] - theta[0]*a[67][1] + theta1[0]*a[67][1] + a[67][2];

            a1[68][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[68][0] + theta[2]*a[68][1] - theta1[2]*a[68][1] - theta[1]*a[68][2] + theta1[1]*a[68][2];

            a1[68][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[68][0] + theta1[2]*a[68][0] + a[68][1] + theta[0]*a[68][2] - theta1[0]*a[68][2];

            a1[68][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[68][0] - theta1[1]*a[68][0] - theta[0]*a[68][1] + theta1[0]*a[68][1] + a[68][2];

            a1[69][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[69][0] + theta[2]*a[69][1] - theta1[2]*a[69][1] - theta[1]*a[69][2] + theta1[1]*a[69][2];

            a1[69][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[69][0] + theta1[2]*a[69][0] + a[69][1] + theta[0]*a[69][2] - theta1[0]*a[69][2];

            a1[69][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[69][0] - theta1[1]*a[69][0] - theta[0]*a[69][1] + theta1[0]*a[69][1] + a[69][2];

            a1[70][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[70][0] + theta[2]*a[70][1] - theta1[2]*a[70][1] - theta[1]*a[70][2] + theta1[1]*a[70][2];

            a1[70][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[70][0] + theta1[2]*a[70][0] + a[70][1] + theta[0]*a[70][2] - theta1[0]*a[70][2];

            a1[70][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[70][0] - theta1[1]*a[70][0] - theta[0]*a[70][1] + theta1[0]*a[70][1] + a[70][2];

            a1[71][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[71][0] + theta[2]*a[71][1] - theta1[2]*a[71][1] - theta[1]*a[71][2] + theta1[1]*a[71][2];

            a1[71][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[71][0] + theta1[2]*a[71][0] + a[71][1] + theta[0]*a[71][2] - theta1[0]*a[71][2];

            a1[71][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[71][0] - theta1[1]*a[71][0] - theta[0]*a[71][1] + theta1[0]*a[71][1] + a[71][2];

            a1[72][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[72][0] + theta[2]*a[72][1] - theta1[2]*a[72][1] - theta[1]*a[72][2] + theta1[1]*a[72][2];

            a1[72][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[72][0] + theta1[2]*a[72][0] + a[72][1] + theta[0]*a[72][2] - theta1[0]*a[72][2];

            a1[72][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[72][0] - theta1[1]*a[72][0] - theta[0]*a[72][1] + theta1[0]*a[72][1] + a[72][2];

            a1[73][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[73][0] + theta[2]*a[73][1] - theta1[2]*a[73][1] - theta[1]*a[73][2] + theta1[1]*a[73][2];

            a1[73][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[73][0] + theta1[2]*a[73][0] + a[73][1] + theta[0]*a[73][2] - theta1[0]*a[73][2];

            a1[73][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[73][0] - theta1[1]*a[73][0] - theta[0]*a[73][1] + theta1[0]*a[73][1] + a[73][2];

            a1[74][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[74][0] + theta[2]*a[74][1] - theta1[2]*a[74][1] - theta[1]*a[74][2] + theta1[1]*a[74][2];

            a1[74][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[74][0] + theta1[2]*a[74][0] + a[74][1] + theta[0]*a[74][2] - theta1[0]*a[74][2];

            a1[74][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[74][0] - theta1[1]*a[74][0] - theta[0]*a[74][1] + theta1[0]*a[74][1] + a[74][2];

            a1[75][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[75][0] + theta[2]*a[75][1] - theta1[2]*a[75][1] - theta[1]*a[75][2] + theta1[1]*a[75][2];

            a1[75][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[75][0] + theta1[2]*a[75][0] + a[75][1] + theta[0]*a[75][2] - theta1[0]*a[75][2];

            a1[75][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[75][0] - theta1[1]*a[75][0] - theta[0]*a[75][1] + theta1[0]*a[75][1] + a[75][2];

            a1[76][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[76][0] + theta[2]*a[76][1] - theta1[2]*a[76][1] - theta[1]*a[76][2] + theta1[1]*a[76][2];

            a1[76][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[76][0] + theta1[2]*a[76][0] + a[76][1] + theta[0]*a[76][2] - theta1[0]*a[76][2];

            a1[76][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[76][0] - theta1[1]*a[76][0] - theta[0]*a[76][1] + theta1[0]*a[76][1] + a[76][2];

            a1[77][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[77][0] + theta[2]*a[77][1] - theta1[2]*a[77][1] - theta[1]*a[77][2] + theta1[1]*a[77][2];

            a1[77][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[77][0] + theta1[2]*a[77][0] + a[77][1] + theta[0]*a[77][2] - theta1[0]*a[77][2];

            a1[77][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[77][0] - theta1[1]*a[77][0] - theta[0]*a[77][1] + theta1[0]*a[77][1] + a[77][2];

            a1[78][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[78][0] + theta[2]*a[78][1] - theta1[2]*a[78][1] - theta[1]*a[78][2] + theta1[1]*a[78][2];

            a1[78][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[78][0] + theta1[2]*a[78][0] + a[78][1] + theta[0]*a[78][2] - theta1[0]*a[78][2];

            a1[78][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[78][0] - theta1[1]*a[78][0] - theta[0]*a[78][1] + theta1[0]*a[78][1] + a[78][2];

            a1[79][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[79][0] + theta[2]*a[79][1] - theta1[2]*a[79][1] - theta[1]*a[79][2] + theta1[1]*a[79][2];

            a1[79][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[79][0] + theta1[2]*a[79][0] + a[79][1] + theta[0]*a[79][2] - theta1[0]*a[79][2];

            a1[79][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[79][0] - theta1[1]*a[79][0] - theta[0]*a[79][1] + theta1[0]*a[79][1] + a[79][2];

            a1[80][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[80][0] + theta[2]*a[80][1] - theta1[2]*a[80][1] - theta[1]*a[80][2] + theta1[1]*a[80][2];

            a1[80][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[80][0] + theta1[2]*a[80][0] + a[80][1] + theta[0]*a[80][2] - theta1[0]*a[80][2];

            a1[80][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[80][0] - theta1[1]*a[80][0] - theta[0]*a[80][1] + theta1[0]*a[80][1] + a[80][2];

            break;

        case 91:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmRadial[10][0] + FmRadial[11][0] + FmRadial[12][0] + FmRadial[13][0] + FmRadial[14][0] + FmRadial[15][0] + FmRadial[16][0] + FmRadial[17][0] + FmRadial[18][0] + FmRadial[19][0] + FmRadial[20][0] + FmRadial[21][0] + FmRadial[22][0] + FmRadial[23][0] + FmRadial[24][0] + FmRadial[25][0] + FmRadial[26][0] + FmRadial[27][0] + FmRadial[28][0] + FmRadial[29][0] + FmRadial[30][0] + FmRadial[31][0] + FmRadial[32][0] + FmRadial[33][0] + FmRadial[34][0] + FmRadial[35][0] + FmRadial[36][0] + FmRadial[37][0] + FmRadial[38][0] + FmRadial[39][0] + FmRadial[40][0] + FmRadial[41][0] + FmRadial[42][0] + FmRadial[43][0] + FmRadial[44][0] + FmRadial[45][0] + FmRadial[46][0] + FmRadial[47][0] + FmRadial[48][0] + FmRadial[49][0] + FmRadial[50][0] + FmRadial[51][0] + FmRadial[52][0] + FmRadial[53][0] + FmRadial[54][0] + FmRadial[55][0] + FmRadial[56][0] + FmRadial[57][0] + FmRadial[58][0] + FmRadial[59][0] + FmRadial[60][0] + FmRadial[61][0] + FmRadial[62][0] + FmRadial[63][0] + FmRadial[64][0] + FmRadial[65][0] + FmRadial[66][0] + FmRadial[67][0] + FmRadial[68][0] + FmRadial[69][0] + FmRadial[70][0] + FmRadial[71][0] + FmRadial[72][0] + FmRadial[73][0] + FmRadial[74][0] + FmRadial[75][0] + FmRadial[76][0] + FmRadial[77][0] + FmRadial[78][0] + FmRadial[79][0] + FmRadial[80][0] + FmRadial[81][0] + FmRadial[82][0] + FmRadial[83][0] + FmRadial[84][0] + FmRadial[85][0] + FmRadial[86][0] + FmRadial[87][0] + FmRadial[88][0] + FmRadial[89][0] + FmRadial[90][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0] + FmTangential[41][0] + FmTangential[42][0] + FmTangential[43][0] + FmTangential[44][0] + FmTangential[45][0] + FmTangential[46][0] + FmTangential[47][0] + FmTangential[48][0] + FmTangential[49][0] + FmTangential[50][0] + FmTangential[51][0] + FmTangential[52][0] + FmTangential[53][0] + FmTangential[54][0] + FmTangential[55][0] + FmTangential[56][0] + FmTangential[57][0] + FmTangential[58][0] + FmTangential[59][0] + FmTangential[60][0] + FmTangential[61][0] + FmTangential[62][0] + FmTangential[63][0] + FmTangential[64][0] + FmTangential[65][0] + FmTangential[66][0] + FmTangential[67][0] + FmTangential[68][0] + FmTangential[69][0] + FmTangential[70][0] + FmTangential[71][0] + FmTangential[72][0] + FmTangential[73][0] + FmTangential[74][0] + FmTangential[75][0] + FmTangential[76][0] + FmTangential[77][0] + FmTangential[78][0] + FmTangential[79][0] + FmTangential[80][0] + FmTangential[81][0] + FmTangential[82][0] + FmTangential[83][0] + FmTangential[84][0] + FmTangential[85][0] + FmTangential[86][0] + FmTangential[87][0] + FmTangential[88][0] + FmTangential[89][0] + FmTangential[90][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmRadial[10][1] + FmRadial[11][1] + FmRadial[12][1] + FmRadial[13][1] + FmRadial[14][1] + FmRadial[15][1] + FmRadial[16][1] + FmRadial[17][1] + FmRadial[18][1] + FmRadial[19][1] + FmRadial[20][1] + FmRadial[21][1] + FmRadial[22][1] + FmRadial[23][1] + FmRadial[24][1] + FmRadial[25][1] + FmRadial[26][1] + FmRadial[27][1] + FmRadial[28][1] + FmRadial[29][1] + FmRadial[30][1] + FmRadial[31][1] + FmRadial[32][1] + FmRadial[33][1] + FmRadial[34][1] + FmRadial[35][1] + FmRadial[36][1] + FmRadial[37][1] + FmRadial[38][1] + FmRadial[39][1] + FmRadial[40][1] + FmRadial[41][1] + FmRadial[42][1] + FmRadial[43][1] + FmRadial[44][1] + FmRadial[45][1] + FmRadial[46][1] + FmRadial[47][1] + FmRadial[48][1] + FmRadial[49][1] + FmRadial[50][1] + FmRadial[51][1] + FmRadial[52][1] + FmRadial[53][1] + FmRadial[54][1] + FmRadial[55][1] + FmRadial[56][1] + FmRadial[57][1] + FmRadial[58][1] + FmRadial[59][1] + FmRadial[60][1] + FmRadial[61][1] + FmRadial[62][1] + FmRadial[63][1] + FmRadial[64][1] + FmRadial[65][1] + FmRadial[66][1] + FmRadial[67][1] + FmRadial[68][1] + FmRadial[69][1] + FmRadial[70][1] + FmRadial[71][1] + FmRadial[72][1] + FmRadial[73][1] + FmRadial[74][1] + FmRadial[75][1] + FmRadial[76][1] + FmRadial[77][1] + FmRadial[78][1] + FmRadial[79][1] + FmRadial[80][1] + FmRadial[81][1] + FmRadial[82][1] + FmRadial[83][1] + FmRadial[84][1] + FmRadial[85][1] + FmRadial[86][1] + FmRadial[87][1] + FmRadial[88][1] + FmRadial[89][1] + FmRadial[90][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1] + FmTangential[19][1] + FmTangential[20][1] + FmTangential[21][1] + FmTangential[22][1] + FmTangential[23][1] + FmTangential[24][1] + FmTangential[25][1] + FmTangential[26][1] + FmTangential[27][1] + FmTangential[28][1] + FmTangential[29][1] + FmTangential[30][1] + FmTangential[31][1] + FmTangential[32][1] + FmTangential[33][1] + FmTangential[34][1] + FmTangential[35][1] + FmTangential[36][1] + FmTangential[37][1] + FmTangential[38][1] + FmTangential[39][1] + FmTangential[40][1] + FmTangential[41][1] + FmTangential[42][1] + FmTangential[43][1] + FmTangential[44][1] + FmTangential[45][1] + FmTangential[46][1] + FmTangential[47][1] + FmTangential[48][1] + FmTangential[49][1] + FmTangential[50][1] + FmTangential[51][1] + FmTangential[52][1] + FmTangential[53][1] + FmTangential[54][1] + FmTangential[55][1] + FmTangential[56][1] + FmTangential[57][1] + FmTangential[58][1] + FmTangential[59][1] + FmTangential[60][1] + FmTangential[61][1] + FmTangential[62][1] + FmTangential[63][1] + FmTangential[64][1] + FmTangential[65][1] + FmTangential[66][1] + FmTangential[67][1] + FmTangential[68][1] + FmTangential[69][1] + FmTangential[70][1] + FmTangential[71][1] + FmTangential[72][1] + FmTangential[73][1] + FmTangential[74][1] + FmTangential[75][1] + FmTangential[76][1] + FmTangential[77][1] + FmTangential[78][1] + FmTangential[79][1] + FmTangential[80][1] + FmTangential[81][1] + FmTangential[82][1] + FmTangential[83][1] + FmTangential[84][1] + FmTangential[85][1] + FmTangential[86][1] + FmTangential[87][1] + FmTangential[88][1] + FmTangential[89][1] + FmTangential[90][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmRadial[10][2] + FmRadial[11][2] + FmRadial[12][2] + FmRadial[13][2] + FmRadial[14][2] + FmRadial[15][2] + FmRadial[16][2] + FmRadial[17][2] + FmRadial[18][2] + FmRadial[19][2] + FmRadial[20][2] + FmRadial[21][2] + FmRadial[22][2] + FmRadial[23][2] + FmRadial[24][2] + FmRadial[25][2] + FmRadial[26][2] + FmRadial[27][2] + FmRadial[28][2] + FmRadial[29][2] + FmRadial[30][2] + FmRadial[31][2] + FmRadial[32][2] + FmRadial[33][2] + FmRadial[34][2] + FmRadial[35][2] + FmRadial[36][2] + FmRadial[37][2] + FmRadial[38][2] + FmRadial[39][2] + FmRadial[40][2] + FmRadial[41][2] + FmRadial[42][2] + FmRadial[43][2] + FmRadial[44][2] + FmRadial[45][2] + FmRadial[46][2] + FmRadial[47][2] + FmRadial[48][2] + FmRadial[49][2] + FmRadial[50][2] + FmRadial[51][2] + FmRadial[52][2] + FmRadial[53][2] + FmRadial[54][2] + FmRadial[55][2] + FmRadial[56][2] + FmRadial[57][2] + FmRadial[58][2] + FmRadial[59][2] + FmRadial[60][2] + FmRadial[61][2] + FmRadial[62][2] + FmRadial[63][2] + FmRadial[64][2] + FmRadial[65][2] + FmRadial[66][2] + FmRadial[67][2] + FmRadial[68][2] + FmRadial[69][2] + FmRadial[70][2] + FmRadial[71][2] + FmRadial[72][2] + FmRadial[73][2] + FmRadial[74][2] + FmRadial[75][2] + FmRadial[76][2] + FmRadial[77][2] + FmRadial[78][2] + FmRadial[79][2] + FmRadial[80][2] + FmRadial[81][2] + FmRadial[82][2] + FmRadial[83][2] + FmRadial[84][2] + FmRadial[85][2] + FmRadial[86][2] + FmRadial[87][2] + FmRadial[88][2] + FmRadial[89][2] + FmRadial[90][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2] + FmTangential[10][2] + FmTangential[11][2] + FmTangential[12][2] + FmTangential[13][2] + FmTangential[14][2] + FmTangential[15][2] + FmTangential[16][2] + FmTangential[17][2] + FmTangential[18][2] + FmTangential[19][2] + FmTangential[20][2] + FmTangential[21][2] + FmTangential[22][2] + FmTangential[23][2] + FmTangential[24][2] + FmTangential[25][2] + FmTangential[26][2] + FmTangential[27][2] + FmTangential[28][2] + FmTangential[29][2] + FmTangential[30][2] + FmTangential[31][2] + FmTangential[32][2] + FmTangential[33][2] + FmTangential[34][2] + FmTangential[35][2] + FmTangential[36][2] + FmTangential[37][2] + FmTangential[38][2] + FmTangential[39][2] + FmTangential[40][2] + FmTangential[41][2] + FmTangential[42][2] + FmTangential[43][2] + FmTangential[44][2] + FmTangential[45][2] + FmTangential[46][2] + FmTangential[47][2] + FmTangential[48][2] + FmTangential[49][2] + FmTangential[50][2] + FmTangential[51][2] + FmTangential[52][2] + FmTangential[53][2] + FmTangential[54][2] + FmTangential[55][2] + FmTangential[56][2] + FmTangential[57][2] + FmTangential[58][2] + FmTangential[59][2] + FmTangential[60][2] + FmTangential[61][2] + FmTangential[62][2] + FmTangential[63][2] + FmTangential[64][2] + FmTangential[65][2] + FmTangential[66][2] + FmTangential[67][2] + FmTangential[68][2] + FmTangential[69][2] + FmTangential[70][2] + FmTangential[71][2] + FmTangential[72][2] + FmTangential[73][2] + FmTangential[74][2] + FmTangential[75][2] + FmTangential[76][2] + FmTangential[77][2] + FmTangential[78][2] + FmTangential[79][2] + FmTangential[80][2] + FmTangential[81][2] + FmTangential[82][2] + FmTangential[83][2] + FmTangential[84][2] + FmTangential[85][2] + FmTangential[86][2] + FmTangential[87][2] + FmTangential[88][2] + FmTangential[89][2] + FmTangential[90][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2] - a[10][2]*FmTangential[10][1] - c[1]*FmTangential[10][2] + a[10][1]*FmTangential[10][2] - a[11][2]*FmTangential[11][1] - c[1]*FmTangential[11][2] + a[11][1]*FmTangential[11][2] - a[12][2]*FmTangential[12][1] - c[1]*FmTangential[12][2] + a[12][1]*FmTangential[12][2] - a[13][2]*FmTangential[13][1] - c[1]*FmTangential[13][2] + a[13][1]*FmTangential[13][2] - a[14][2]*FmTangential[14][1] - c[1]*FmTangential[14][2] + a[14][1]*FmTangential[14][2] - a[15][2]*FmTangential[15][1] - c[1]*FmTangential[15][2] + a[15][1]*FmTangential[15][2] - a[16][2]*FmTangential[16][1] - c[1]*FmTangential[16][2] + a[16][1]*FmTangential[16][2] - a[17][2]*FmTangential[17][1] - c[1]*FmTangential[17][2] + a[17][1]*FmTangential[17][2] - a[18][2]*FmTangential[18][1] - c[1]*FmTangential[18][2] + a[18][1]*FmTangential[18][2] - a[19][2]*FmTangential[19][1] - c[1]*FmTangential[19][2] + a[19][1]*FmTangential[19][2] - a[20][2]*FmTangential[20][1] - c[1]*FmTangential[20][2] + a[20][1]*FmTangential[20][2] - a[21][2]*FmTangential[21][1] - c[1]*FmTangential[21][2] + a[21][1]*FmTangential[21][2] - a[22][2]*FmTangential[22][1] - c[1]*FmTangential[22][2] + a[22][1]*FmTangential[22][2] - a[23][2]*FmTangential[23][1] - c[1]*FmTangential[23][2] + a[23][1]*FmTangential[23][2] - a[24][2]*FmTangential[24][1] - c[1]*FmTangential[24][2] + a[24][1]*FmTangential[24][2] - a[25][2]*FmTangential[25][1] - c[1]*FmTangential[25][2] + a[25][1]*FmTangential[25][2] - a[26][2]*FmTangential[26][1] - c[1]*FmTangential[26][2] + a[26][1]*FmTangential[26][2] - a[27][2]*FmTangential[27][1] - c[1]*FmTangential[27][2] + a[27][1]*FmTangential[27][2] - a[28][2]*FmTangential[28][1] - c[1]*FmTangential[28][2] + a[28][1]*FmTangential[28][2] - a[29][2]*FmTangential[29][1] - c[1]*FmTangential[29][2] + a[29][1]*FmTangential[29][2] - a[30][2]*FmTangential[30][1] - c[1]*FmTangential[30][2] + a[30][1]*FmTangential[30][2] - a[31][2]*FmTangential[31][1] - c[1]*FmTangential[31][2] + a[31][1]*FmTangential[31][2] - a[32][2]*FmTangential[32][1] - c[1]*FmTangential[32][2] + a[32][1]*FmTangential[32][2] - a[33][2]*FmTangential[33][1] - c[1]*FmTangential[33][2] + a[33][1]*FmTangential[33][2] - a[34][2]*FmTangential[34][1] - c[1]*FmTangential[34][2] + a[34][1]*FmTangential[34][2] - a[35][2]*FmTangential[35][1] - c[1]*FmTangential[35][2] + a[35][1]*FmTangential[35][2] - a[36][2]*FmTangential[36][1] - c[1]*FmTangential[36][2] + a[36][1]*FmTangential[36][2] - a[37][2]*FmTangential[37][1] - c[1]*FmTangential[37][2] + a[37][1]*FmTangential[37][2] - a[38][2]*FmTangential[38][1] - c[1]*FmTangential[38][2] + a[38][1]*FmTangential[38][2] - a[39][2]*FmTangential[39][1] - c[1]*FmTangential[39][2] + a[39][1]*FmTangential[39][2] - a[40][2]*FmTangential[40][1] - c[1]*FmTangential[40][2] + a[40][1]*FmTangential[40][2] - a[41][2]*FmTangential[41][1] - c[1]*FmTangential[41][2] + a[41][1]*FmTangential[41][2] - a[42][2]*FmTangential[42][1] - c[1]*FmTangential[42][2] + a[42][1]*FmTangential[42][2] - a[43][2]*FmTangential[43][1] - c[1]*FmTangential[43][2] + a[43][1]*FmTangential[43][2] - a[44][2]*FmTangential[44][1] - c[1]*FmTangential[44][2] + a[44][1]*FmTangential[44][2] - a[45][2]*FmTangential[45][1] - c[1]*FmTangential[45][2] + a[45][1]*FmTangential[45][2] - a[46][2]*FmTangential[46][1] - c[1]*FmTangential[46][2] + a[46][1]*FmTangential[46][2] - a[47][2]*FmTangential[47][1] - c[1]*FmTangential[47][2] + a[47][1]*FmTangential[47][2] - a[48][2]*FmTangential[48][1] - c[1]*FmTangential[48][2] + a[48][1]*FmTangential[48][2] - a[49][2]*FmTangential[49][1] - c[1]*FmTangential[49][2] + a[49][1]*FmTangential[49][2] - a[50][2]*FmTangential[50][1] - c[1]*FmTangential[50][2] + a[50][1]*FmTangential[50][2] - a[51][2]*FmTangential[51][1] - c[1]*FmTangential[51][2] + a[51][1]*FmTangential[51][2] - a[52][2]*FmTangential[52][1] - c[1]*FmTangential[52][2] + a[52][1]*FmTangential[52][2] - a[53][2]*FmTangential[53][1] - c[1]*FmTangential[53][2] + a[53][1]*FmTangential[53][2] - a[54][2]*FmTangential[54][1] - c[1]*FmTangential[54][2] + a[54][1]*FmTangential[54][2] - a[55][2]*FmTangential[55][1] - c[1]*FmTangential[55][2] + a[55][1]*FmTangential[55][2] - a[56][2]*FmTangential[56][1] - c[1]*FmTangential[56][2] + a[56][1]*FmTangential[56][2] - a[57][2]*FmTangential[57][1] - c[1]*FmTangential[57][2] + a[57][1]*FmTangential[57][2] - a[58][2]*FmTangential[58][1] - c[1]*FmTangential[58][2] + a[58][1]*FmTangential[58][2] - a[59][2]*FmTangential[59][1] - c[1]*FmTangential[59][2] + a[59][1]*FmTangential[59][2] - a[60][2]*FmTangential[60][1] - c[1]*FmTangential[60][2] + a[60][1]*FmTangential[60][2] - a[61][2]*FmTangential[61][1] - c[1]*FmTangential[61][2] + a[61][1]*FmTangential[61][2] - a[62][2]*FmTangential[62][1] - c[1]*FmTangential[62][2] + a[62][1]*FmTangential[62][2] - a[63][2]*FmTangential[63][1] - c[1]*FmTangential[63][2] + a[63][1]*FmTangential[63][2] - a[64][2]*FmTangential[64][1] - c[1]*FmTangential[64][2] + a[64][1]*FmTangential[64][2] - a[65][2]*FmTangential[65][1] - c[1]*FmTangential[65][2] + a[65][1]*FmTangential[65][2] - a[66][2]*FmTangential[66][1] - c[1]*FmTangential[66][2] + a[66][1]*FmTangential[66][2] - a[67][2]*FmTangential[67][1] - c[1]*FmTangential[67][2] + a[67][1]*FmTangential[67][2] - a[68][2]*FmTangential[68][1] - c[1]*FmTangential[68][2] + a[68][1]*FmTangential[68][2] - a[69][2]*FmTangential[69][1] - c[1]*FmTangential[69][2] + a[69][1]*FmTangential[69][2] - a[70][2]*FmTangential[70][1] - c[1]*FmTangential[70][2] + a[70][1]*FmTangential[70][2] - a[71][2]*FmTangential[71][1] - c[1]*FmTangential[71][2] + a[71][1]*FmTangential[71][2] - a[72][2]*FmTangential[72][1] - c[1]*FmTangential[72][2] + a[72][1]*FmTangential[72][2] - a[73][2]*FmTangential[73][1] - c[1]*FmTangential[73][2] + a[73][1]*FmTangential[73][2] - a[74][2]*FmTangential[74][1] - c[1]*FmTangential[74][2] + a[74][1]*FmTangential[74][2] - a[75][2]*FmTangential[75][1] - c[1]*FmTangential[75][2] + a[75][1]*FmTangential[75][2] - a[76][2]*FmTangential[76][1] - c[1]*FmTangential[76][2] + a[76][1]*FmTangential[76][2] - a[77][2]*FmTangential[77][1] - c[1]*FmTangential[77][2] + a[77][1]*FmTangential[77][2] - a[78][2]*FmTangential[78][1] - c[1]*FmTangential[78][2] + a[78][1]*FmTangential[78][2] - a[79][2]*FmTangential[79][1] - c[1]*FmTangential[79][2] + a[79][1]*FmTangential[79][2] - a[80][2]*FmTangential[80][1] - c[1]*FmTangential[80][2] + a[80][1]*FmTangential[80][2] - a[81][2]*FmTangential[81][1] - c[1]*FmTangential[81][2] + a[81][1]*FmTangential[81][2] - a[82][2]*FmTangential[82][1] - c[1]*FmTangential[82][2] + a[82][1]*FmTangential[82][2] - a[83][2]*FmTangential[83][1] - c[1]*FmTangential[83][2] + a[83][1]*FmTangential[83][2] - a[84][2]*FmTangential[84][1] - c[1]*FmTangential[84][2] + a[84][1]*FmTangential[84][2] - a[85][2]*FmTangential[85][1] - c[1]*FmTangential[85][2] + a[85][1]*FmTangential[85][2] - a[86][2]*FmTangential[86][1] - c[1]*FmTangential[86][2] + a[86][1]*FmTangential[86][2] - a[87][2]*FmTangential[87][1] - c[1]*FmTangential[87][2] + a[87][1]*FmTangential[87][2] - a[88][2]*FmTangential[88][1] - c[1]*FmTangential[88][2] + a[88][1]*FmTangential[88][2] - a[89][2]*FmTangential[89][1] - c[1]*FmTangential[89][2] + a[89][1]*FmTangential[89][2] - a[90][2]*FmTangential[90][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1] + FmTangential[19][1] + FmTangential[20][1] + FmTangential[21][1] + FmTangential[22][1] + FmTangential[23][1] + FmTangential[24][1] + FmTangential[25][1] + FmTangential[26][1] + FmTangential[27][1] + FmTangential[28][1] + FmTangential[29][1] + FmTangential[30][1] + FmTangential[31][1] + FmTangential[32][1] + FmTangential[33][1] + FmTangential[34][1] + FmTangential[35][1] + FmTangential[36][1] + FmTangential[37][1] + FmTangential[38][1] + FmTangential[39][1] + FmTangential[40][1] + FmTangential[41][1] + FmTangential[42][1] + FmTangential[43][1] + FmTangential[44][1] + FmTangential[45][1] + FmTangential[46][1] + FmTangential[47][1] + FmTangential[48][1] + FmTangential[49][1] + FmTangential[50][1] + FmTangential[51][1] + FmTangential[52][1] + FmTangential[53][1] + FmTangential[54][1] + FmTangential[55][1] + FmTangential[56][1] + FmTangential[57][1] + FmTangential[58][1] + FmTangential[59][1] + FmTangential[60][1] + FmTangential[61][1] + FmTangential[62][1] + FmTangential[63][1] + FmTangential[64][1] + FmTangential[65][1] + FmTangential[66][1] + FmTangential[67][1] + FmTangential[68][1] + FmTangential[69][1] + FmTangential[70][1] + FmTangential[71][1] + FmTangential[72][1] + FmTangential[73][1] + FmTangential[74][1] + FmTangential[75][1] + FmTangential[76][1] + FmTangential[77][1] + FmTangential[78][1] + FmTangential[79][1] + FmTangential[80][1] + FmTangential[81][1] + FmTangential[82][1] + FmTangential[83][1] + FmTangential[84][1] + FmTangential[85][1] + FmTangential[86][1] + FmTangential[87][1] + FmTangential[88][1] + FmTangential[89][1] + FmTangential[90][1]) - c[1]*FmTangential[90][2] + a[90][1]*FmTangential[90][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2] + a[10][2]*FmTangential[10][0] + c[0]*FmTangential[10][2] - a[10][0]*FmTangential[10][2] + a[11][2]*FmTangential[11][0] + c[0]*FmTangential[11][2] - a[11][0]*FmTangential[11][2] + a[12][2]*FmTangential[12][0] + c[0]*FmTangential[12][2] - a[12][0]*FmTangential[12][2] + a[13][2]*FmTangential[13][0] + c[0]*FmTangential[13][2] - a[13][0]*FmTangential[13][2] + a[14][2]*FmTangential[14][0] + c[0]*FmTangential[14][2] - a[14][0]*FmTangential[14][2] + a[15][2]*FmTangential[15][0] + c[0]*FmTangential[15][2] - a[15][0]*FmTangential[15][2] + a[16][2]*FmTangential[16][0] + c[0]*FmTangential[16][2] - a[16][0]*FmTangential[16][2] + a[17][2]*FmTangential[17][0] + c[0]*FmTangential[17][2] - a[17][0]*FmTangential[17][2] + a[18][2]*FmTangential[18][0] + c[0]*FmTangential[18][2] - a[18][0]*FmTangential[18][2] + a[19][2]*FmTangential[19][0] + c[0]*FmTangential[19][2] - a[19][0]*FmTangential[19][2] + a[20][2]*FmTangential[20][0] + c[0]*FmTangential[20][2] - a[20][0]*FmTangential[20][2] + a[21][2]*FmTangential[21][0] + c[0]*FmTangential[21][2] - a[21][0]*FmTangential[21][2] + a[22][2]*FmTangential[22][0] + c[0]*FmTangential[22][2] - a[22][0]*FmTangential[22][2] + a[23][2]*FmTangential[23][0] + c[0]*FmTangential[23][2] - a[23][0]*FmTangential[23][2] + a[24][2]*FmTangential[24][0] + c[0]*FmTangential[24][2] - a[24][0]*FmTangential[24][2] + a[25][2]*FmTangential[25][0] + c[0]*FmTangential[25][2] - a[25][0]*FmTangential[25][2] + a[26][2]*FmTangential[26][0] + c[0]*FmTangential[26][2] - a[26][0]*FmTangential[26][2] + a[27][2]*FmTangential[27][0] + c[0]*FmTangential[27][2] - a[27][0]*FmTangential[27][2] + a[28][2]*FmTangential[28][0] + c[0]*FmTangential[28][2] - a[28][0]*FmTangential[28][2] + a[29][2]*FmTangential[29][0] + c[0]*FmTangential[29][2] - a[29][0]*FmTangential[29][2] + a[30][2]*FmTangential[30][0] + c[0]*FmTangential[30][2] - a[30][0]*FmTangential[30][2] + a[31][2]*FmTangential[31][0] + c[0]*FmTangential[31][2] - a[31][0]*FmTangential[31][2] + a[32][2]*FmTangential[32][0] + c[0]*FmTangential[32][2] - a[32][0]*FmTangential[32][2] + a[33][2]*FmTangential[33][0] + c[0]*FmTangential[33][2] - a[33][0]*FmTangential[33][2] + a[34][2]*FmTangential[34][0] + c[0]*FmTangential[34][2] - a[34][0]*FmTangential[34][2] + a[35][2]*FmTangential[35][0] + c[0]*FmTangential[35][2] - a[35][0]*FmTangential[35][2] + a[36][2]*FmTangential[36][0] + c[0]*FmTangential[36][2] - a[36][0]*FmTangential[36][2] + a[37][2]*FmTangential[37][0] + c[0]*FmTangential[37][2] - a[37][0]*FmTangential[37][2] + a[38][2]*FmTangential[38][0] + c[0]*FmTangential[38][2] - a[38][0]*FmTangential[38][2] + a[39][2]*FmTangential[39][0] + c[0]*FmTangential[39][2] - a[39][0]*FmTangential[39][2] + a[40][2]*FmTangential[40][0] + c[0]*FmTangential[40][2] - a[40][0]*FmTangential[40][2] + a[41][2]*FmTangential[41][0] + c[0]*FmTangential[41][2] - a[41][0]*FmTangential[41][2] + a[42][2]*FmTangential[42][0] + c[0]*FmTangential[42][2] - a[42][0]*FmTangential[42][2] + a[43][2]*FmTangential[43][0] + c[0]*FmTangential[43][2] - a[43][0]*FmTangential[43][2] + a[44][2]*FmTangential[44][0] + c[0]*FmTangential[44][2] - a[44][0]*FmTangential[44][2] + a[45][2]*FmTangential[45][0] + c[0]*FmTangential[45][2] - a[45][0]*FmTangential[45][2] + a[46][2]*FmTangential[46][0] + c[0]*FmTangential[46][2] - a[46][0]*FmTangential[46][2] + a[47][2]*FmTangential[47][0] + c[0]*FmTangential[47][2] - a[47][0]*FmTangential[47][2] + a[48][2]*FmTangential[48][0] + c[0]*FmTangential[48][2] - a[48][0]*FmTangential[48][2] + a[49][2]*FmTangential[49][0] + c[0]*FmTangential[49][2] - a[49][0]*FmTangential[49][2] + a[50][2]*FmTangential[50][0] + c[0]*FmTangential[50][2] - a[50][0]*FmTangential[50][2] + a[51][2]*FmTangential[51][0] + c[0]*FmTangential[51][2] - a[51][0]*FmTangential[51][2] + a[52][2]*FmTangential[52][0] + c[0]*FmTangential[52][2] - a[52][0]*FmTangential[52][2] + a[53][2]*FmTangential[53][0] + c[0]*FmTangential[53][2] - a[53][0]*FmTangential[53][2] + a[54][2]*FmTangential[54][0] + c[0]*FmTangential[54][2] - a[54][0]*FmTangential[54][2] + a[55][2]*FmTangential[55][0] + c[0]*FmTangential[55][2] - a[55][0]*FmTangential[55][2] + a[56][2]*FmTangential[56][0] + c[0]*FmTangential[56][2] - a[56][0]*FmTangential[56][2] + a[57][2]*FmTangential[57][0] + c[0]*FmTangential[57][2] - a[57][0]*FmTangential[57][2] + a[58][2]*FmTangential[58][0] + c[0]*FmTangential[58][2] - a[58][0]*FmTangential[58][2] + a[59][2]*FmTangential[59][0] + c[0]*FmTangential[59][2] - a[59][0]*FmTangential[59][2] + a[60][2]*FmTangential[60][0] + c[0]*FmTangential[60][2] - a[60][0]*FmTangential[60][2] + a[61][2]*FmTangential[61][0] + c[0]*FmTangential[61][2] - a[61][0]*FmTangential[61][2] + a[62][2]*FmTangential[62][0] + c[0]*FmTangential[62][2] - a[62][0]*FmTangential[62][2] + a[63][2]*FmTangential[63][0] + c[0]*FmTangential[63][2] - a[63][0]*FmTangential[63][2] + a[64][2]*FmTangential[64][0] + c[0]*FmTangential[64][2] - a[64][0]*FmTangential[64][2] + a[65][2]*FmTangential[65][0] + c[0]*FmTangential[65][2] - a[65][0]*FmTangential[65][2] + a[66][2]*FmTangential[66][0] + c[0]*FmTangential[66][2] - a[66][0]*FmTangential[66][2] + a[67][2]*FmTangential[67][0] + c[0]*FmTangential[67][2] - a[67][0]*FmTangential[67][2] + a[68][2]*FmTangential[68][0] + c[0]*FmTangential[68][2] - a[68][0]*FmTangential[68][2] + a[69][2]*FmTangential[69][0] + c[0]*FmTangential[69][2] - a[69][0]*FmTangential[69][2] + a[70][2]*FmTangential[70][0] + c[0]*FmTangential[70][2] - a[70][0]*FmTangential[70][2] + a[71][2]*FmTangential[71][0] + c[0]*FmTangential[71][2] - a[71][0]*FmTangential[71][2] + a[72][2]*FmTangential[72][0] + c[0]*FmTangential[72][2] - a[72][0]*FmTangential[72][2] + a[73][2]*FmTangential[73][0] + c[0]*FmTangential[73][2] - a[73][0]*FmTangential[73][2] + a[74][2]*FmTangential[74][0] + c[0]*FmTangential[74][2] - a[74][0]*FmTangential[74][2] + a[75][2]*FmTangential[75][0] + c[0]*FmTangential[75][2] - a[75][0]*FmTangential[75][2] + a[76][2]*FmTangential[76][0] + c[0]*FmTangential[76][2] - a[76][0]*FmTangential[76][2] + a[77][2]*FmTangential[77][0] + c[0]*FmTangential[77][2] - a[77][0]*FmTangential[77][2] + a[78][2]*FmTangential[78][0] + c[0]*FmTangential[78][2] - a[78][0]*FmTangential[78][2] + a[79][2]*FmTangential[79][0] + c[0]*FmTangential[79][2] - a[79][0]*FmTangential[79][2] + a[80][2]*FmTangential[80][0] + c[0]*FmTangential[80][2] - a[80][0]*FmTangential[80][2] + a[81][2]*FmTangential[81][0] + c[0]*FmTangential[81][2] - a[81][0]*FmTangential[81][2] + a[82][2]*FmTangential[82][0] + c[0]*FmTangential[82][2] - a[82][0]*FmTangential[82][2] + a[83][2]*FmTangential[83][0] + c[0]*FmTangential[83][2] - a[83][0]*FmTangential[83][2] + a[84][2]*FmTangential[84][0] + c[0]*FmTangential[84][2] - a[84][0]*FmTangential[84][2] + a[85][2]*FmTangential[85][0] + c[0]*FmTangential[85][2] - a[85][0]*FmTangential[85][2] + a[86][2]*FmTangential[86][0] + c[0]*FmTangential[86][2] - a[86][0]*FmTangential[86][2] + a[87][2]*FmTangential[87][0] + c[0]*FmTangential[87][2] - a[87][0]*FmTangential[87][2] + a[88][2]*FmTangential[88][0] + c[0]*FmTangential[88][2] - a[88][0]*FmTangential[88][2] + a[89][2]*FmTangential[89][0] + c[0]*FmTangential[89][2] - a[89][0]*FmTangential[89][2] + a[90][2]*FmTangential[90][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0] + FmTangential[41][0] + FmTangential[42][0] + FmTangential[43][0] + FmTangential[44][0] + FmTangential[45][0] + FmTangential[46][0] + FmTangential[47][0] + FmTangential[48][0] + FmTangential[49][0] + FmTangential[50][0] + FmTangential[51][0] + FmTangential[52][0] + FmTangential[53][0] + FmTangential[54][0] + FmTangential[55][0] + FmTangential[56][0] + FmTangential[57][0] + FmTangential[58][0] + FmTangential[59][0] + FmTangential[60][0] + FmTangential[61][0] + FmTangential[62][0] + FmTangential[63][0] + FmTangential[64][0] + FmTangential[65][0] + FmTangential[66][0] + FmTangential[67][0] + FmTangential[68][0] + FmTangential[69][0] + FmTangential[70][0] + FmTangential[71][0] + FmTangential[72][0] + FmTangential[73][0] + FmTangential[74][0] + FmTangential[75][0] + FmTangential[76][0] + FmTangential[77][0] + FmTangential[78][0] + FmTangential[79][0] + FmTangential[80][0] + FmTangential[81][0] + FmTangential[82][0] + FmTangential[83][0] + FmTangential[84][0] + FmTangential[85][0] + FmTangential[86][0] + FmTangential[87][0] + FmTangential[88][0] + FmTangential[89][0] + FmTangential[90][0]) + c[0]*FmTangential[90][2] - a[90][0]*FmTangential[90][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1] - a[10][1]*FmTangential[10][0] - c[0]*FmTangential[10][1] + a[10][0]*FmTangential[10][1] - a[11][1]*FmTangential[11][0] - c[0]*FmTangential[11][1] + a[11][0]*FmTangential[11][1] - a[12][1]*FmTangential[12][0] - c[0]*FmTangential[12][1] + a[12][0]*FmTangential[12][1] - a[13][1]*FmTangential[13][0] - c[0]*FmTangential[13][1] + a[13][0]*FmTangential[13][1] - a[14][1]*FmTangential[14][0] - c[0]*FmTangential[14][1] + a[14][0]*FmTangential[14][1] - a[15][1]*FmTangential[15][0] - c[0]*FmTangential[15][1] + a[15][0]*FmTangential[15][1] - a[16][1]*FmTangential[16][0] - c[0]*FmTangential[16][1] + a[16][0]*FmTangential[16][1] - a[17][1]*FmTangential[17][0] - c[0]*FmTangential[17][1] + a[17][0]*FmTangential[17][1] - a[18][1]*FmTangential[18][0] - c[0]*FmTangential[18][1] + a[18][0]*FmTangential[18][1] - a[19][1]*FmTangential[19][0] - c[0]*FmTangential[19][1] + a[19][0]*FmTangential[19][1] - a[20][1]*FmTangential[20][0] - c[0]*FmTangential[20][1] + a[20][0]*FmTangential[20][1] - a[21][1]*FmTangential[21][0] - c[0]*FmTangential[21][1] + a[21][0]*FmTangential[21][1] - a[22][1]*FmTangential[22][0] - c[0]*FmTangential[22][1] + a[22][0]*FmTangential[22][1] - a[23][1]*FmTangential[23][0] - c[0]*FmTangential[23][1] + a[23][0]*FmTangential[23][1] - a[24][1]*FmTangential[24][0] - c[0]*FmTangential[24][1] + a[24][0]*FmTangential[24][1] - a[25][1]*FmTangential[25][0] - c[0]*FmTangential[25][1] + a[25][0]*FmTangential[25][1] - a[26][1]*FmTangential[26][0] - c[0]*FmTangential[26][1] + a[26][0]*FmTangential[26][1] - a[27][1]*FmTangential[27][0] - c[0]*FmTangential[27][1] + a[27][0]*FmTangential[27][1] - a[28][1]*FmTangential[28][0] - c[0]*FmTangential[28][1] + a[28][0]*FmTangential[28][1] - a[29][1]*FmTangential[29][0] - c[0]*FmTangential[29][1] + a[29][0]*FmTangential[29][1] - a[30][1]*FmTangential[30][0] - c[0]*FmTangential[30][1] + a[30][0]*FmTangential[30][1] - a[31][1]*FmTangential[31][0] - c[0]*FmTangential[31][1] + a[31][0]*FmTangential[31][1] - a[32][1]*FmTangential[32][0] - c[0]*FmTangential[32][1] + a[32][0]*FmTangential[32][1] - a[33][1]*FmTangential[33][0] - c[0]*FmTangential[33][1] + a[33][0]*FmTangential[33][1] - a[34][1]*FmTangential[34][0] - c[0]*FmTangential[34][1] + a[34][0]*FmTangential[34][1] - a[35][1]*FmTangential[35][0] - c[0]*FmTangential[35][1] + a[35][0]*FmTangential[35][1] - a[36][1]*FmTangential[36][0] - c[0]*FmTangential[36][1] + a[36][0]*FmTangential[36][1] - a[37][1]*FmTangential[37][0] - c[0]*FmTangential[37][1] + a[37][0]*FmTangential[37][1] - a[38][1]*FmTangential[38][0] - c[0]*FmTangential[38][1] + a[38][0]*FmTangential[38][1] - a[39][1]*FmTangential[39][0] - c[0]*FmTangential[39][1] + a[39][0]*FmTangential[39][1] - a[40][1]*FmTangential[40][0] - c[0]*FmTangential[40][1] + a[40][0]*FmTangential[40][1] - a[41][1]*FmTangential[41][0] - c[0]*FmTangential[41][1] + a[41][0]*FmTangential[41][1] - a[42][1]*FmTangential[42][0] - c[0]*FmTangential[42][1] + a[42][0]*FmTangential[42][1] - a[43][1]*FmTangential[43][0] - c[0]*FmTangential[43][1] + a[43][0]*FmTangential[43][1] - a[44][1]*FmTangential[44][0] - c[0]*FmTangential[44][1] + a[44][0]*FmTangential[44][1] - a[45][1]*FmTangential[45][0] - c[0]*FmTangential[45][1] + a[45][0]*FmTangential[45][1] - a[46][1]*FmTangential[46][0] - c[0]*FmTangential[46][1] + a[46][0]*FmTangential[46][1] - a[47][1]*FmTangential[47][0] - c[0]*FmTangential[47][1] + a[47][0]*FmTangential[47][1] - a[48][1]*FmTangential[48][0] - c[0]*FmTangential[48][1] + a[48][0]*FmTangential[48][1] - a[49][1]*FmTangential[49][0] - c[0]*FmTangential[49][1] + a[49][0]*FmTangential[49][1] - a[50][1]*FmTangential[50][0] - c[0]*FmTangential[50][1] + a[50][0]*FmTangential[50][1] - a[51][1]*FmTangential[51][0] - c[0]*FmTangential[51][1] + a[51][0]*FmTangential[51][1] - a[52][1]*FmTangential[52][0] - c[0]*FmTangential[52][1] + a[52][0]*FmTangential[52][1] - a[53][1]*FmTangential[53][0] - c[0]*FmTangential[53][1] + a[53][0]*FmTangential[53][1] - a[54][1]*FmTangential[54][0] - c[0]*FmTangential[54][1] + a[54][0]*FmTangential[54][1] - a[55][1]*FmTangential[55][0] - c[0]*FmTangential[55][1] + a[55][0]*FmTangential[55][1] - a[56][1]*FmTangential[56][0] - c[0]*FmTangential[56][1] + a[56][0]*FmTangential[56][1] - a[57][1]*FmTangential[57][0] - c[0]*FmTangential[57][1] + a[57][0]*FmTangential[57][1] - a[58][1]*FmTangential[58][0] - c[0]*FmTangential[58][1] + a[58][0]*FmTangential[58][1] - a[59][1]*FmTangential[59][0] - c[0]*FmTangential[59][1] + a[59][0]*FmTangential[59][1] - a[60][1]*FmTangential[60][0] - c[0]*FmTangential[60][1] + a[60][0]*FmTangential[60][1] - a[61][1]*FmTangential[61][0] - c[0]*FmTangential[61][1] + a[61][0]*FmTangential[61][1] - a[62][1]*FmTangential[62][0] - c[0]*FmTangential[62][1] + a[62][0]*FmTangential[62][1] - a[63][1]*FmTangential[63][0] - c[0]*FmTangential[63][1] + a[63][0]*FmTangential[63][1] - a[64][1]*FmTangential[64][0] - c[0]*FmTangential[64][1] + a[64][0]*FmTangential[64][1] - a[65][1]*FmTangential[65][0] - c[0]*FmTangential[65][1] + a[65][0]*FmTangential[65][1] - a[66][1]*FmTangential[66][0] - c[0]*FmTangential[66][1] + a[66][0]*FmTangential[66][1] - a[67][1]*FmTangential[67][0] - c[0]*FmTangential[67][1] + a[67][0]*FmTangential[67][1] - a[68][1]*FmTangential[68][0] - c[0]*FmTangential[68][1] + a[68][0]*FmTangential[68][1] - a[69][1]*FmTangential[69][0] - c[0]*FmTangential[69][1] + a[69][0]*FmTangential[69][1] - a[70][1]*FmTangential[70][0] - c[0]*FmTangential[70][1] + a[70][0]*FmTangential[70][1] - a[71][1]*FmTangential[71][0] - c[0]*FmTangential[71][1] + a[71][0]*FmTangential[71][1] - a[72][1]*FmTangential[72][0] - c[0]*FmTangential[72][1] + a[72][0]*FmTangential[72][1] - a[73][1]*FmTangential[73][0] - c[0]*FmTangential[73][1] + a[73][0]*FmTangential[73][1] - a[74][1]*FmTangential[74][0] - c[0]*FmTangential[74][1] + a[74][0]*FmTangential[74][1] - a[75][1]*FmTangential[75][0] - c[0]*FmTangential[75][1] + a[75][0]*FmTangential[75][1] - a[76][1]*FmTangential[76][0] - c[0]*FmTangential[76][1] + a[76][0]*FmTangential[76][1] - a[77][1]*FmTangential[77][0] - c[0]*FmTangential[77][1] + a[77][0]*FmTangential[77][1] - a[78][1]*FmTangential[78][0] - c[0]*FmTangential[78][1] + a[78][0]*FmTangential[78][1] - a[79][1]*FmTangential[79][0] - c[0]*FmTangential[79][1] + a[79][0]*FmTangential[79][1] - a[80][1]*FmTangential[80][0] - c[0]*FmTangential[80][1] + a[80][0]*FmTangential[80][1] - a[81][1]*FmTangential[81][0] - c[0]*FmTangential[81][1] + a[81][0]*FmTangential[81][1] - a[82][1]*FmTangential[82][0] - c[0]*FmTangential[82][1] + a[82][0]*FmTangential[82][1] - a[83][1]*FmTangential[83][0] - c[0]*FmTangential[83][1] + a[83][0]*FmTangential[83][1] - a[84][1]*FmTangential[84][0] - c[0]*FmTangential[84][1] + a[84][0]*FmTangential[84][1] - a[85][1]*FmTangential[85][0] - c[0]*FmTangential[85][1] + a[85][0]*FmTangential[85][1] - a[86][1]*FmTangential[86][0] - c[0]*FmTangential[86][1] + a[86][0]*FmTangential[86][1] - a[87][1]*FmTangential[87][0] - c[0]*FmTangential[87][1] + a[87][0]*FmTangential[87][1] - a[88][1]*FmTangential[88][0] - c[0]*FmTangential[88][1] + a[88][0]*FmTangential[88][1] - a[89][1]*FmTangential[89][0] - c[0]*FmTangential[89][1] + a[89][0]*FmTangential[89][1] - a[90][1]*FmTangential[90][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0] + FmTangential[41][0] + FmTangential[42][0] + FmTangential[43][0] + FmTangential[44][0] + FmTangential[45][0] + FmTangential[46][0] + FmTangential[47][0] + FmTangential[48][0] + FmTangential[49][0] + FmTangential[50][0] + FmTangential[51][0] + FmTangential[52][0] + FmTangential[53][0] + FmTangential[54][0] + FmTangential[55][0] + FmTangential[56][0] + FmTangential[57][0] + FmTangential[58][0] + FmTangential[59][0] + FmTangential[60][0] + FmTangential[61][0] + FmTangential[62][0] + FmTangential[63][0] + FmTangential[64][0] + FmTangential[65][0] + FmTangential[66][0] + FmTangential[67][0] + FmTangential[68][0] + FmTangential[69][0] + FmTangential[70][0] + FmTangential[71][0] + FmTangential[72][0] + FmTangential[73][0] + FmTangential[74][0] + FmTangential[75][0] + FmTangential[76][0] + FmTangential[77][0] + FmTangential[78][0] + FmTangential[79][0] + FmTangential[80][0] + FmTangential[81][0] + FmTangential[82][0] + FmTangential[83][0] + FmTangential[84][0] + FmTangential[85][0] + FmTangential[86][0] + FmTangential[87][0] + FmTangential[88][0] + FmTangential[89][0] + FmTangential[90][0]) - c[0]*FmTangential[90][1] + a[90][0]*FmTangential[90][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            a1[10][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[10][0] + theta[2]*a[10][1] - theta1[2]*a[10][1] - theta[1]*a[10][2] + theta1[1]*a[10][2];

            a1[10][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[10][0] + theta1[2]*a[10][0] + a[10][1] + theta[0]*a[10][2] - theta1[0]*a[10][2];

            a1[10][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[10][0] - theta1[1]*a[10][0] - theta[0]*a[10][1] + theta1[0]*a[10][1] + a[10][2];

            a1[11][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[11][0] + theta[2]*a[11][1] - theta1[2]*a[11][1] - theta[1]*a[11][2] + theta1[1]*a[11][2];

            a1[11][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[11][0] + theta1[2]*a[11][0] + a[11][1] + theta[0]*a[11][2] - theta1[0]*a[11][2];

            a1[11][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[11][0] - theta1[1]*a[11][0] - theta[0]*a[11][1] + theta1[0]*a[11][1] + a[11][2];

            a1[12][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[12][0] + theta[2]*a[12][1] - theta1[2]*a[12][1] - theta[1]*a[12][2] + theta1[1]*a[12][2];

            a1[12][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[12][0] + theta1[2]*a[12][0] + a[12][1] + theta[0]*a[12][2] - theta1[0]*a[12][2];

            a1[12][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[12][0] - theta1[1]*a[12][0] - theta[0]*a[12][1] + theta1[0]*a[12][1] + a[12][2];

            a1[13][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[13][0] + theta[2]*a[13][1] - theta1[2]*a[13][1] - theta[1]*a[13][2] + theta1[1]*a[13][2];

            a1[13][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[13][0] + theta1[2]*a[13][0] + a[13][1] + theta[0]*a[13][2] - theta1[0]*a[13][2];

            a1[13][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[13][0] - theta1[1]*a[13][0] - theta[0]*a[13][1] + theta1[0]*a[13][1] + a[13][2];

            a1[14][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[14][0] + theta[2]*a[14][1] - theta1[2]*a[14][1] - theta[1]*a[14][2] + theta1[1]*a[14][2];

            a1[14][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[14][0] + theta1[2]*a[14][0] + a[14][1] + theta[0]*a[14][2] - theta1[0]*a[14][2];

            a1[14][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[14][0] - theta1[1]*a[14][0] - theta[0]*a[14][1] + theta1[0]*a[14][1] + a[14][2];

            a1[15][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[15][0] + theta[2]*a[15][1] - theta1[2]*a[15][1] - theta[1]*a[15][2] + theta1[1]*a[15][2];

            a1[15][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[15][0] + theta1[2]*a[15][0] + a[15][1] + theta[0]*a[15][2] - theta1[0]*a[15][2];

            a1[15][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[15][0] - theta1[1]*a[15][0] - theta[0]*a[15][1] + theta1[0]*a[15][1] + a[15][2];

            a1[16][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[16][0] + theta[2]*a[16][1] - theta1[2]*a[16][1] - theta[1]*a[16][2] + theta1[1]*a[16][2];

            a1[16][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[16][0] + theta1[2]*a[16][0] + a[16][1] + theta[0]*a[16][2] - theta1[0]*a[16][2];

            a1[16][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[16][0] - theta1[1]*a[16][0] - theta[0]*a[16][1] + theta1[0]*a[16][1] + a[16][2];

            a1[17][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[17][0] + theta[2]*a[17][1] - theta1[2]*a[17][1] - theta[1]*a[17][2] + theta1[1]*a[17][2];

            a1[17][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[17][0] + theta1[2]*a[17][0] + a[17][1] + theta[0]*a[17][2] - theta1[0]*a[17][2];

            a1[17][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[17][0] - theta1[1]*a[17][0] - theta[0]*a[17][1] + theta1[0]*a[17][1] + a[17][2];

            a1[18][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[18][0] + theta[2]*a[18][1] - theta1[2]*a[18][1] - theta[1]*a[18][2] + theta1[1]*a[18][2];

            a1[18][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[18][0] + theta1[2]*a[18][0] + a[18][1] + theta[0]*a[18][2] - theta1[0]*a[18][2];

            a1[18][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[18][0] - theta1[1]*a[18][0] - theta[0]*a[18][1] + theta1[0]*a[18][1] + a[18][2];

            a1[19][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[19][0] + theta[2]*a[19][1] - theta1[2]*a[19][1] - theta[1]*a[19][2] + theta1[1]*a[19][2];

            a1[19][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[19][0] + theta1[2]*a[19][0] + a[19][1] + theta[0]*a[19][2] - theta1[0]*a[19][2];

            a1[19][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[19][0] - theta1[1]*a[19][0] - theta[0]*a[19][1] + theta1[0]*a[19][1] + a[19][2];

            a1[20][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[20][0] + theta[2]*a[20][1] - theta1[2]*a[20][1] - theta[1]*a[20][2] + theta1[1]*a[20][2];

            a1[20][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[20][0] + theta1[2]*a[20][0] + a[20][1] + theta[0]*a[20][2] - theta1[0]*a[20][2];

            a1[20][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[20][0] - theta1[1]*a[20][0] - theta[0]*a[20][1] + theta1[0]*a[20][1] + a[20][2];

            a1[21][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[21][0] + theta[2]*a[21][1] - theta1[2]*a[21][1] - theta[1]*a[21][2] + theta1[1]*a[21][2];

            a1[21][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[21][0] + theta1[2]*a[21][0] + a[21][1] + theta[0]*a[21][2] - theta1[0]*a[21][2];

            a1[21][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[21][0] - theta1[1]*a[21][0] - theta[0]*a[21][1] + theta1[0]*a[21][1] + a[21][2];

            a1[22][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[22][0] + theta[2]*a[22][1] - theta1[2]*a[22][1] - theta[1]*a[22][2] + theta1[1]*a[22][2];

            a1[22][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[22][0] + theta1[2]*a[22][0] + a[22][1] + theta[0]*a[22][2] - theta1[0]*a[22][2];

            a1[22][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[22][0] - theta1[1]*a[22][0] - theta[0]*a[22][1] + theta1[0]*a[22][1] + a[22][2];

            a1[23][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[23][0] + theta[2]*a[23][1] - theta1[2]*a[23][1] - theta[1]*a[23][2] + theta1[1]*a[23][2];

            a1[23][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[23][0] + theta1[2]*a[23][0] + a[23][1] + theta[0]*a[23][2] - theta1[0]*a[23][2];

            a1[23][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[23][0] - theta1[1]*a[23][0] - theta[0]*a[23][1] + theta1[0]*a[23][1] + a[23][2];

            a1[24][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[24][0] + theta[2]*a[24][1] - theta1[2]*a[24][1] - theta[1]*a[24][2] + theta1[1]*a[24][2];

            a1[24][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[24][0] + theta1[2]*a[24][0] + a[24][1] + theta[0]*a[24][2] - theta1[0]*a[24][2];

            a1[24][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[24][0] - theta1[1]*a[24][0] - theta[0]*a[24][1] + theta1[0]*a[24][1] + a[24][2];

            a1[25][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[25][0] + theta[2]*a[25][1] - theta1[2]*a[25][1] - theta[1]*a[25][2] + theta1[1]*a[25][2];

            a1[25][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[25][0] + theta1[2]*a[25][0] + a[25][1] + theta[0]*a[25][2] - theta1[0]*a[25][2];

            a1[25][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[25][0] - theta1[1]*a[25][0] - theta[0]*a[25][1] + theta1[0]*a[25][1] + a[25][2];

            a1[26][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[26][0] + theta[2]*a[26][1] - theta1[2]*a[26][1] - theta[1]*a[26][2] + theta1[1]*a[26][2];

            a1[26][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[26][0] + theta1[2]*a[26][0] + a[26][1] + theta[0]*a[26][2] - theta1[0]*a[26][2];

            a1[26][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[26][0] - theta1[1]*a[26][0] - theta[0]*a[26][1] + theta1[0]*a[26][1] + a[26][2];

            a1[27][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[27][0] + theta[2]*a[27][1] - theta1[2]*a[27][1] - theta[1]*a[27][2] + theta1[1]*a[27][2];

            a1[27][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[27][0] + theta1[2]*a[27][0] + a[27][1] + theta[0]*a[27][2] - theta1[0]*a[27][2];

            a1[27][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[27][0] - theta1[1]*a[27][0] - theta[0]*a[27][1] + theta1[0]*a[27][1] + a[27][2];

            a1[28][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[28][0] + theta[2]*a[28][1] - theta1[2]*a[28][1] - theta[1]*a[28][2] + theta1[1]*a[28][2];

            a1[28][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[28][0] + theta1[2]*a[28][0] + a[28][1] + theta[0]*a[28][2] - theta1[0]*a[28][2];

            a1[28][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[28][0] - theta1[1]*a[28][0] - theta[0]*a[28][1] + theta1[0]*a[28][1] + a[28][2];

            a1[29][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[29][0] + theta[2]*a[29][1] - theta1[2]*a[29][1] - theta[1]*a[29][2] + theta1[1]*a[29][2];

            a1[29][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[29][0] + theta1[2]*a[29][0] + a[29][1] + theta[0]*a[29][2] - theta1[0]*a[29][2];

            a1[29][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[29][0] - theta1[1]*a[29][0] - theta[0]*a[29][1] + theta1[0]*a[29][1] + a[29][2];

            a1[30][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[30][0] + theta[2]*a[30][1] - theta1[2]*a[30][1] - theta[1]*a[30][2] + theta1[1]*a[30][2];

            a1[30][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[30][0] + theta1[2]*a[30][0] + a[30][1] + theta[0]*a[30][2] - theta1[0]*a[30][2];

            a1[30][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[30][0] - theta1[1]*a[30][0] - theta[0]*a[30][1] + theta1[0]*a[30][1] + a[30][2];

            a1[31][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[31][0] + theta[2]*a[31][1] - theta1[2]*a[31][1] - theta[1]*a[31][2] + theta1[1]*a[31][2];

            a1[31][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[31][0] + theta1[2]*a[31][0] + a[31][1] + theta[0]*a[31][2] - theta1[0]*a[31][2];

            a1[31][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[31][0] - theta1[1]*a[31][0] - theta[0]*a[31][1] + theta1[0]*a[31][1] + a[31][2];

            a1[32][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[32][0] + theta[2]*a[32][1] - theta1[2]*a[32][1] - theta[1]*a[32][2] + theta1[1]*a[32][2];

            a1[32][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[32][0] + theta1[2]*a[32][0] + a[32][1] + theta[0]*a[32][2] - theta1[0]*a[32][2];

            a1[32][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[32][0] - theta1[1]*a[32][0] - theta[0]*a[32][1] + theta1[0]*a[32][1] + a[32][2];

            a1[33][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[33][0] + theta[2]*a[33][1] - theta1[2]*a[33][1] - theta[1]*a[33][2] + theta1[1]*a[33][2];

            a1[33][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[33][0] + theta1[2]*a[33][0] + a[33][1] + theta[0]*a[33][2] - theta1[0]*a[33][2];

            a1[33][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[33][0] - theta1[1]*a[33][0] - theta[0]*a[33][1] + theta1[0]*a[33][1] + a[33][2];

            a1[34][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[34][0] + theta[2]*a[34][1] - theta1[2]*a[34][1] - theta[1]*a[34][2] + theta1[1]*a[34][2];

            a1[34][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[34][0] + theta1[2]*a[34][0] + a[34][1] + theta[0]*a[34][2] - theta1[0]*a[34][2];

            a1[34][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[34][0] - theta1[1]*a[34][0] - theta[0]*a[34][1] + theta1[0]*a[34][1] + a[34][2];

            a1[35][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[35][0] + theta[2]*a[35][1] - theta1[2]*a[35][1] - theta[1]*a[35][2] + theta1[1]*a[35][2];

            a1[35][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[35][0] + theta1[2]*a[35][0] + a[35][1] + theta[0]*a[35][2] - theta1[0]*a[35][2];

            a1[35][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[35][0] - theta1[1]*a[35][0] - theta[0]*a[35][1] + theta1[0]*a[35][1] + a[35][2];

            a1[36][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[36][0] + theta[2]*a[36][1] - theta1[2]*a[36][1] - theta[1]*a[36][2] + theta1[1]*a[36][2];

            a1[36][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[36][0] + theta1[2]*a[36][0] + a[36][1] + theta[0]*a[36][2] - theta1[0]*a[36][2];

            a1[36][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[36][0] - theta1[1]*a[36][0] - theta[0]*a[36][1] + theta1[0]*a[36][1] + a[36][2];

            a1[37][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[37][0] + theta[2]*a[37][1] - theta1[2]*a[37][1] - theta[1]*a[37][2] + theta1[1]*a[37][2];

            a1[37][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[37][0] + theta1[2]*a[37][0] + a[37][1] + theta[0]*a[37][2] - theta1[0]*a[37][2];

            a1[37][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[37][0] - theta1[1]*a[37][0] - theta[0]*a[37][1] + theta1[0]*a[37][1] + a[37][2];

            a1[38][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[38][0] + theta[2]*a[38][1] - theta1[2]*a[38][1] - theta[1]*a[38][2] + theta1[1]*a[38][2];

            a1[38][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[38][0] + theta1[2]*a[38][0] + a[38][1] + theta[0]*a[38][2] - theta1[0]*a[38][2];

            a1[38][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[38][0] - theta1[1]*a[38][0] - theta[0]*a[38][1] + theta1[0]*a[38][1] + a[38][2];

            a1[39][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[39][0] + theta[2]*a[39][1] - theta1[2]*a[39][1] - theta[1]*a[39][2] + theta1[1]*a[39][2];

            a1[39][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[39][0] + theta1[2]*a[39][0] + a[39][1] + theta[0]*a[39][2] - theta1[0]*a[39][2];

            a1[39][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[39][0] - theta1[1]*a[39][0] - theta[0]*a[39][1] + theta1[0]*a[39][1] + a[39][2];

            a1[40][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[40][0] + theta[2]*a[40][1] - theta1[2]*a[40][1] - theta[1]*a[40][2] + theta1[1]*a[40][2];

            a1[40][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[40][0] + theta1[2]*a[40][0] + a[40][1] + theta[0]*a[40][2] - theta1[0]*a[40][2];

            a1[40][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[40][0] - theta1[1]*a[40][0] - theta[0]*a[40][1] + theta1[0]*a[40][1] + a[40][2];

            a1[41][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[41][0] + theta[2]*a[41][1] - theta1[2]*a[41][1] - theta[1]*a[41][2] + theta1[1]*a[41][2];

            a1[41][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[41][0] + theta1[2]*a[41][0] + a[41][1] + theta[0]*a[41][2] - theta1[0]*a[41][2];

            a1[41][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[41][0] - theta1[1]*a[41][0] - theta[0]*a[41][1] + theta1[0]*a[41][1] + a[41][2];

            a1[42][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[42][0] + theta[2]*a[42][1] - theta1[2]*a[42][1] - theta[1]*a[42][2] + theta1[1]*a[42][2];

            a1[42][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[42][0] + theta1[2]*a[42][0] + a[42][1] + theta[0]*a[42][2] - theta1[0]*a[42][2];

            a1[42][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[42][0] - theta1[1]*a[42][0] - theta[0]*a[42][1] + theta1[0]*a[42][1] + a[42][2];

            a1[43][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[43][0] + theta[2]*a[43][1] - theta1[2]*a[43][1] - theta[1]*a[43][2] + theta1[1]*a[43][2];

            a1[43][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[43][0] + theta1[2]*a[43][0] + a[43][1] + theta[0]*a[43][2] - theta1[0]*a[43][2];

            a1[43][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[43][0] - theta1[1]*a[43][0] - theta[0]*a[43][1] + theta1[0]*a[43][1] + a[43][2];

            a1[44][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[44][0] + theta[2]*a[44][1] - theta1[2]*a[44][1] - theta[1]*a[44][2] + theta1[1]*a[44][2];

            a1[44][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[44][0] + theta1[2]*a[44][0] + a[44][1] + theta[0]*a[44][2] - theta1[0]*a[44][2];

            a1[44][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[44][0] - theta1[1]*a[44][0] - theta[0]*a[44][1] + theta1[0]*a[44][1] + a[44][2];

            a1[45][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[45][0] + theta[2]*a[45][1] - theta1[2]*a[45][1] - theta[1]*a[45][2] + theta1[1]*a[45][2];

            a1[45][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[45][0] + theta1[2]*a[45][0] + a[45][1] + theta[0]*a[45][2] - theta1[0]*a[45][2];

            a1[45][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[45][0] - theta1[1]*a[45][0] - theta[0]*a[45][1] + theta1[0]*a[45][1] + a[45][2];

            a1[46][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[46][0] + theta[2]*a[46][1] - theta1[2]*a[46][1] - theta[1]*a[46][2] + theta1[1]*a[46][2];

            a1[46][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[46][0] + theta1[2]*a[46][0] + a[46][1] + theta[0]*a[46][2] - theta1[0]*a[46][2];

            a1[46][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[46][0] - theta1[1]*a[46][0] - theta[0]*a[46][1] + theta1[0]*a[46][1] + a[46][2];

            a1[47][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[47][0] + theta[2]*a[47][1] - theta1[2]*a[47][1] - theta[1]*a[47][2] + theta1[1]*a[47][2];

            a1[47][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[47][0] + theta1[2]*a[47][0] + a[47][1] + theta[0]*a[47][2] - theta1[0]*a[47][2];

            a1[47][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[47][0] - theta1[1]*a[47][0] - theta[0]*a[47][1] + theta1[0]*a[47][1] + a[47][2];

            a1[48][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[48][0] + theta[2]*a[48][1] - theta1[2]*a[48][1] - theta[1]*a[48][2] + theta1[1]*a[48][2];

            a1[48][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[48][0] + theta1[2]*a[48][0] + a[48][1] + theta[0]*a[48][2] - theta1[0]*a[48][2];

            a1[48][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[48][0] - theta1[1]*a[48][0] - theta[0]*a[48][1] + theta1[0]*a[48][1] + a[48][2];

            a1[49][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[49][0] + theta[2]*a[49][1] - theta1[2]*a[49][1] - theta[1]*a[49][2] + theta1[1]*a[49][2];

            a1[49][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[49][0] + theta1[2]*a[49][0] + a[49][1] + theta[0]*a[49][2] - theta1[0]*a[49][2];

            a1[49][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[49][0] - theta1[1]*a[49][0] - theta[0]*a[49][1] + theta1[0]*a[49][1] + a[49][2];

            a1[50][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[50][0] + theta[2]*a[50][1] - theta1[2]*a[50][1] - theta[1]*a[50][2] + theta1[1]*a[50][2];

            a1[50][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[50][0] + theta1[2]*a[50][0] + a[50][1] + theta[0]*a[50][2] - theta1[0]*a[50][2];

            a1[50][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[50][0] - theta1[1]*a[50][0] - theta[0]*a[50][1] + theta1[0]*a[50][1] + a[50][2];

            a1[51][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[51][0] + theta[2]*a[51][1] - theta1[2]*a[51][1] - theta[1]*a[51][2] + theta1[1]*a[51][2];

            a1[51][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[51][0] + theta1[2]*a[51][0] + a[51][1] + theta[0]*a[51][2] - theta1[0]*a[51][2];

            a1[51][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[51][0] - theta1[1]*a[51][0] - theta[0]*a[51][1] + theta1[0]*a[51][1] + a[51][2];

            a1[52][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[52][0] + theta[2]*a[52][1] - theta1[2]*a[52][1] - theta[1]*a[52][2] + theta1[1]*a[52][2];

            a1[52][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[52][0] + theta1[2]*a[52][0] + a[52][1] + theta[0]*a[52][2] - theta1[0]*a[52][2];

            a1[52][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[52][0] - theta1[1]*a[52][0] - theta[0]*a[52][1] + theta1[0]*a[52][1] + a[52][2];

            a1[53][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[53][0] + theta[2]*a[53][1] - theta1[2]*a[53][1] - theta[1]*a[53][2] + theta1[1]*a[53][2];

            a1[53][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[53][0] + theta1[2]*a[53][0] + a[53][1] + theta[0]*a[53][2] - theta1[0]*a[53][2];

            a1[53][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[53][0] - theta1[1]*a[53][0] - theta[0]*a[53][1] + theta1[0]*a[53][1] + a[53][2];

            a1[54][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[54][0] + theta[2]*a[54][1] - theta1[2]*a[54][1] - theta[1]*a[54][2] + theta1[1]*a[54][2];

            a1[54][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[54][0] + theta1[2]*a[54][0] + a[54][1] + theta[0]*a[54][2] - theta1[0]*a[54][2];

            a1[54][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[54][0] - theta1[1]*a[54][0] - theta[0]*a[54][1] + theta1[0]*a[54][1] + a[54][2];

            a1[55][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[55][0] + theta[2]*a[55][1] - theta1[2]*a[55][1] - theta[1]*a[55][2] + theta1[1]*a[55][2];

            a1[55][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[55][0] + theta1[2]*a[55][0] + a[55][1] + theta[0]*a[55][2] - theta1[0]*a[55][2];

            a1[55][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[55][0] - theta1[1]*a[55][0] - theta[0]*a[55][1] + theta1[0]*a[55][1] + a[55][2];

            a1[56][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[56][0] + theta[2]*a[56][1] - theta1[2]*a[56][1] - theta[1]*a[56][2] + theta1[1]*a[56][2];

            a1[56][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[56][0] + theta1[2]*a[56][0] + a[56][1] + theta[0]*a[56][2] - theta1[0]*a[56][2];

            a1[56][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[56][0] - theta1[1]*a[56][0] - theta[0]*a[56][1] + theta1[0]*a[56][1] + a[56][2];

            a1[57][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[57][0] + theta[2]*a[57][1] - theta1[2]*a[57][1] - theta[1]*a[57][2] + theta1[1]*a[57][2];

            a1[57][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[57][0] + theta1[2]*a[57][0] + a[57][1] + theta[0]*a[57][2] - theta1[0]*a[57][2];

            a1[57][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[57][0] - theta1[1]*a[57][0] - theta[0]*a[57][1] + theta1[0]*a[57][1] + a[57][2];

            a1[58][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[58][0] + theta[2]*a[58][1] - theta1[2]*a[58][1] - theta[1]*a[58][2] + theta1[1]*a[58][2];

            a1[58][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[58][0] + theta1[2]*a[58][0] + a[58][1] + theta[0]*a[58][2] - theta1[0]*a[58][2];

            a1[58][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[58][0] - theta1[1]*a[58][0] - theta[0]*a[58][1] + theta1[0]*a[58][1] + a[58][2];

            a1[59][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[59][0] + theta[2]*a[59][1] - theta1[2]*a[59][1] - theta[1]*a[59][2] + theta1[1]*a[59][2];

            a1[59][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[59][0] + theta1[2]*a[59][0] + a[59][1] + theta[0]*a[59][2] - theta1[0]*a[59][2];

            a1[59][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[59][0] - theta1[1]*a[59][0] - theta[0]*a[59][1] + theta1[0]*a[59][1] + a[59][2];

            a1[60][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[60][0] + theta[2]*a[60][1] - theta1[2]*a[60][1] - theta[1]*a[60][2] + theta1[1]*a[60][2];

            a1[60][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[60][0] + theta1[2]*a[60][0] + a[60][1] + theta[0]*a[60][2] - theta1[0]*a[60][2];

            a1[60][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[60][0] - theta1[1]*a[60][0] - theta[0]*a[60][1] + theta1[0]*a[60][1] + a[60][2];

            a1[61][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[61][0] + theta[2]*a[61][1] - theta1[2]*a[61][1] - theta[1]*a[61][2] + theta1[1]*a[61][2];

            a1[61][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[61][0] + theta1[2]*a[61][0] + a[61][1] + theta[0]*a[61][2] - theta1[0]*a[61][2];

            a1[61][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[61][0] - theta1[1]*a[61][0] - theta[0]*a[61][1] + theta1[0]*a[61][1] + a[61][2];

            a1[62][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[62][0] + theta[2]*a[62][1] - theta1[2]*a[62][1] - theta[1]*a[62][2] + theta1[1]*a[62][2];

            a1[62][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[62][0] + theta1[2]*a[62][0] + a[62][1] + theta[0]*a[62][2] - theta1[0]*a[62][2];

            a1[62][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[62][0] - theta1[1]*a[62][0] - theta[0]*a[62][1] + theta1[0]*a[62][1] + a[62][2];

            a1[63][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[63][0] + theta[2]*a[63][1] - theta1[2]*a[63][1] - theta[1]*a[63][2] + theta1[1]*a[63][2];

            a1[63][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[63][0] + theta1[2]*a[63][0] + a[63][1] + theta[0]*a[63][2] - theta1[0]*a[63][2];

            a1[63][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[63][0] - theta1[1]*a[63][0] - theta[0]*a[63][1] + theta1[0]*a[63][1] + a[63][2];

            a1[64][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[64][0] + theta[2]*a[64][1] - theta1[2]*a[64][1] - theta[1]*a[64][2] + theta1[1]*a[64][2];

            a1[64][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[64][0] + theta1[2]*a[64][0] + a[64][1] + theta[0]*a[64][2] - theta1[0]*a[64][2];

            a1[64][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[64][0] - theta1[1]*a[64][0] - theta[0]*a[64][1] + theta1[0]*a[64][1] + a[64][2];

            a1[65][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[65][0] + theta[2]*a[65][1] - theta1[2]*a[65][1] - theta[1]*a[65][2] + theta1[1]*a[65][2];

            a1[65][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[65][0] + theta1[2]*a[65][0] + a[65][1] + theta[0]*a[65][2] - theta1[0]*a[65][2];

            a1[65][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[65][0] - theta1[1]*a[65][0] - theta[0]*a[65][1] + theta1[0]*a[65][1] + a[65][2];

            a1[66][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[66][0] + theta[2]*a[66][1] - theta1[2]*a[66][1] - theta[1]*a[66][2] + theta1[1]*a[66][2];

            a1[66][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[66][0] + theta1[2]*a[66][0] + a[66][1] + theta[0]*a[66][2] - theta1[0]*a[66][2];

            a1[66][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[66][0] - theta1[1]*a[66][0] - theta[0]*a[66][1] + theta1[0]*a[66][1] + a[66][2];

            a1[67][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[67][0] + theta[2]*a[67][1] - theta1[2]*a[67][1] - theta[1]*a[67][2] + theta1[1]*a[67][2];

            a1[67][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[67][0] + theta1[2]*a[67][0] + a[67][1] + theta[0]*a[67][2] - theta1[0]*a[67][2];

            a1[67][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[67][0] - theta1[1]*a[67][0] - theta[0]*a[67][1] + theta1[0]*a[67][1] + a[67][2];

            a1[68][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[68][0] + theta[2]*a[68][1] - theta1[2]*a[68][1] - theta[1]*a[68][2] + theta1[1]*a[68][2];

            a1[68][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[68][0] + theta1[2]*a[68][0] + a[68][1] + theta[0]*a[68][2] - theta1[0]*a[68][2];

            a1[68][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[68][0] - theta1[1]*a[68][0] - theta[0]*a[68][1] + theta1[0]*a[68][1] + a[68][2];

            a1[69][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[69][0] + theta[2]*a[69][1] - theta1[2]*a[69][1] - theta[1]*a[69][2] + theta1[1]*a[69][2];

            a1[69][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[69][0] + theta1[2]*a[69][0] + a[69][1] + theta[0]*a[69][2] - theta1[0]*a[69][2];

            a1[69][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[69][0] - theta1[1]*a[69][0] - theta[0]*a[69][1] + theta1[0]*a[69][1] + a[69][2];

            a1[70][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[70][0] + theta[2]*a[70][1] - theta1[2]*a[70][1] - theta[1]*a[70][2] + theta1[1]*a[70][2];

            a1[70][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[70][0] + theta1[2]*a[70][0] + a[70][1] + theta[0]*a[70][2] - theta1[0]*a[70][2];

            a1[70][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[70][0] - theta1[1]*a[70][0] - theta[0]*a[70][1] + theta1[0]*a[70][1] + a[70][2];

            a1[71][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[71][0] + theta[2]*a[71][1] - theta1[2]*a[71][1] - theta[1]*a[71][2] + theta1[1]*a[71][2];

            a1[71][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[71][0] + theta1[2]*a[71][0] + a[71][1] + theta[0]*a[71][2] - theta1[0]*a[71][2];

            a1[71][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[71][0] - theta1[1]*a[71][0] - theta[0]*a[71][1] + theta1[0]*a[71][1] + a[71][2];

            a1[72][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[72][0] + theta[2]*a[72][1] - theta1[2]*a[72][1] - theta[1]*a[72][2] + theta1[1]*a[72][2];

            a1[72][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[72][0] + theta1[2]*a[72][0] + a[72][1] + theta[0]*a[72][2] - theta1[0]*a[72][2];

            a1[72][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[72][0] - theta1[1]*a[72][0] - theta[0]*a[72][1] + theta1[0]*a[72][1] + a[72][2];

            a1[73][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[73][0] + theta[2]*a[73][1] - theta1[2]*a[73][1] - theta[1]*a[73][2] + theta1[1]*a[73][2];

            a1[73][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[73][0] + theta1[2]*a[73][0] + a[73][1] + theta[0]*a[73][2] - theta1[0]*a[73][2];

            a1[73][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[73][0] - theta1[1]*a[73][0] - theta[0]*a[73][1] + theta1[0]*a[73][1] + a[73][2];

            a1[74][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[74][0] + theta[2]*a[74][1] - theta1[2]*a[74][1] - theta[1]*a[74][2] + theta1[1]*a[74][2];

            a1[74][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[74][0] + theta1[2]*a[74][0] + a[74][1] + theta[0]*a[74][2] - theta1[0]*a[74][2];

            a1[74][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[74][0] - theta1[1]*a[74][0] - theta[0]*a[74][1] + theta1[0]*a[74][1] + a[74][2];

            a1[75][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[75][0] + theta[2]*a[75][1] - theta1[2]*a[75][1] - theta[1]*a[75][2] + theta1[1]*a[75][2];

            a1[75][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[75][0] + theta1[2]*a[75][0] + a[75][1] + theta[0]*a[75][2] - theta1[0]*a[75][2];

            a1[75][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[75][0] - theta1[1]*a[75][0] - theta[0]*a[75][1] + theta1[0]*a[75][1] + a[75][2];

            a1[76][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[76][0] + theta[2]*a[76][1] - theta1[2]*a[76][1] - theta[1]*a[76][2] + theta1[1]*a[76][2];

            a1[76][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[76][0] + theta1[2]*a[76][0] + a[76][1] + theta[0]*a[76][2] - theta1[0]*a[76][2];

            a1[76][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[76][0] - theta1[1]*a[76][0] - theta[0]*a[76][1] + theta1[0]*a[76][1] + a[76][2];

            a1[77][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[77][0] + theta[2]*a[77][1] - theta1[2]*a[77][1] - theta[1]*a[77][2] + theta1[1]*a[77][2];

            a1[77][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[77][0] + theta1[2]*a[77][0] + a[77][1] + theta[0]*a[77][2] - theta1[0]*a[77][2];

            a1[77][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[77][0] - theta1[1]*a[77][0] - theta[0]*a[77][1] + theta1[0]*a[77][1] + a[77][2];

            a1[78][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[78][0] + theta[2]*a[78][1] - theta1[2]*a[78][1] - theta[1]*a[78][2] + theta1[1]*a[78][2];

            a1[78][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[78][0] + theta1[2]*a[78][0] + a[78][1] + theta[0]*a[78][2] - theta1[0]*a[78][2];

            a1[78][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[78][0] - theta1[1]*a[78][0] - theta[0]*a[78][1] + theta1[0]*a[78][1] + a[78][2];

            a1[79][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[79][0] + theta[2]*a[79][1] - theta1[2]*a[79][1] - theta[1]*a[79][2] + theta1[1]*a[79][2];

            a1[79][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[79][0] + theta1[2]*a[79][0] + a[79][1] + theta[0]*a[79][2] - theta1[0]*a[79][2];

            a1[79][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[79][0] - theta1[1]*a[79][0] - theta[0]*a[79][1] + theta1[0]*a[79][1] + a[79][2];

            a1[80][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[80][0] + theta[2]*a[80][1] - theta1[2]*a[80][1] - theta[1]*a[80][2] + theta1[1]*a[80][2];

            a1[80][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[80][0] + theta1[2]*a[80][0] + a[80][1] + theta[0]*a[80][2] - theta1[0]*a[80][2];

            a1[80][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[80][0] - theta1[1]*a[80][0] - theta[0]*a[80][1] + theta1[0]*a[80][1] + a[80][2];

            a1[81][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[81][0] + theta[2]*a[81][1] - theta1[2]*a[81][1] - theta[1]*a[81][2] + theta1[1]*a[81][2];

            a1[81][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[81][0] + theta1[2]*a[81][0] + a[81][1] + theta[0]*a[81][2] - theta1[0]*a[81][2];

            a1[81][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[81][0] - theta1[1]*a[81][0] - theta[0]*a[81][1] + theta1[0]*a[81][1] + a[81][2];

            a1[82][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[82][0] + theta[2]*a[82][1] - theta1[2]*a[82][1] - theta[1]*a[82][2] + theta1[1]*a[82][2];

            a1[82][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[82][0] + theta1[2]*a[82][0] + a[82][1] + theta[0]*a[82][2] - theta1[0]*a[82][2];

            a1[82][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[82][0] - theta1[1]*a[82][0] - theta[0]*a[82][1] + theta1[0]*a[82][1] + a[82][2];

            a1[83][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[83][0] + theta[2]*a[83][1] - theta1[2]*a[83][1] - theta[1]*a[83][2] + theta1[1]*a[83][2];

            a1[83][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[83][0] + theta1[2]*a[83][0] + a[83][1] + theta[0]*a[83][2] - theta1[0]*a[83][2];

            a1[83][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[83][0] - theta1[1]*a[83][0] - theta[0]*a[83][1] + theta1[0]*a[83][1] + a[83][2];

            a1[84][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[84][0] + theta[2]*a[84][1] - theta1[2]*a[84][1] - theta[1]*a[84][2] + theta1[1]*a[84][2];

            a1[84][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[84][0] + theta1[2]*a[84][0] + a[84][1] + theta[0]*a[84][2] - theta1[0]*a[84][2];

            a1[84][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[84][0] - theta1[1]*a[84][0] - theta[0]*a[84][1] + theta1[0]*a[84][1] + a[84][2];

            a1[85][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[85][0] + theta[2]*a[85][1] - theta1[2]*a[85][1] - theta[1]*a[85][2] + theta1[1]*a[85][2];

            a1[85][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[85][0] + theta1[2]*a[85][0] + a[85][1] + theta[0]*a[85][2] - theta1[0]*a[85][2];

            a1[85][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[85][0] - theta1[1]*a[85][0] - theta[0]*a[85][1] + theta1[0]*a[85][1] + a[85][2];

            a1[86][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[86][0] + theta[2]*a[86][1] - theta1[2]*a[86][1] - theta[1]*a[86][2] + theta1[1]*a[86][2];

            a1[86][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[86][0] + theta1[2]*a[86][0] + a[86][1] + theta[0]*a[86][2] - theta1[0]*a[86][2];

            a1[86][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[86][0] - theta1[1]*a[86][0] - theta[0]*a[86][1] + theta1[0]*a[86][1] + a[86][2];

            a1[87][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[87][0] + theta[2]*a[87][1] - theta1[2]*a[87][1] - theta[1]*a[87][2] + theta1[1]*a[87][2];

            a1[87][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[87][0] + theta1[2]*a[87][0] + a[87][1] + theta[0]*a[87][2] - theta1[0]*a[87][2];

            a1[87][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[87][0] - theta1[1]*a[87][0] - theta[0]*a[87][1] + theta1[0]*a[87][1] + a[87][2];

            a1[88][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[88][0] + theta[2]*a[88][1] - theta1[2]*a[88][1] - theta[1]*a[88][2] + theta1[1]*a[88][2];

            a1[88][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[88][0] + theta1[2]*a[88][0] + a[88][1] + theta[0]*a[88][2] - theta1[0]*a[88][2];

            a1[88][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[88][0] - theta1[1]*a[88][0] - theta[0]*a[88][1] + theta1[0]*a[88][1] + a[88][2];

            a1[89][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[89][0] + theta[2]*a[89][1] - theta1[2]*a[89][1] - theta[1]*a[89][2] + theta1[1]*a[89][2];

            a1[89][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[89][0] + theta1[2]*a[89][0] + a[89][1] + theta[0]*a[89][2] - theta1[0]*a[89][2];

            a1[89][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[89][0] - theta1[1]*a[89][0] - theta[0]*a[89][1] + theta1[0]*a[89][1] + a[89][2];

            a1[90][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[90][0] + theta[2]*a[90][1] - theta1[2]*a[90][1] - theta[1]*a[90][2] + theta1[1]*a[90][2];

            a1[90][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[90][0] + theta1[2]*a[90][0] + a[90][1] + theta[0]*a[90][2] - theta1[0]*a[90][2];

            a1[90][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[90][0] - theta1[1]*a[90][0] - theta[0]*a[90][1] + theta1[0]*a[90][1] + a[90][2];

            break;

        case 101:
            c1[0] = c[0] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[0] + dt*muCargoTranslation*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0] + FmRadial[2][0] + FmRadial[3][0] + FmRadial[4][0] + FmRadial[5][0] + FmRadial[6][0] + FmRadial[7][0] + FmRadial[8][0] + FmRadial[9][0] + FmRadial[10][0] + FmRadial[11][0] + FmRadial[12][0] + FmRadial[13][0] + FmRadial[14][0] + FmRadial[15][0] + FmRadial[16][0] + FmRadial[17][0] + FmRadial[18][0] + FmRadial[19][0] + FmRadial[20][0] + FmRadial[21][0] + FmRadial[22][0] + FmRadial[23][0] + FmRadial[24][0] + FmRadial[25][0] + FmRadial[26][0] + FmRadial[27][0] + FmRadial[28][0] + FmRadial[29][0] + FmRadial[30][0] + FmRadial[31][0] + FmRadial[32][0] + FmRadial[33][0] + FmRadial[34][0] + FmRadial[35][0] + FmRadial[36][0] + FmRadial[37][0] + FmRadial[38][0] + FmRadial[39][0] + FmRadial[40][0] + FmRadial[41][0] + FmRadial[42][0] + FmRadial[43][0] + FmRadial[44][0] + FmRadial[45][0] + FmRadial[46][0] + FmRadial[47][0] + FmRadial[48][0] + FmRadial[49][0] + FmRadial[50][0] + FmRadial[51][0] + FmRadial[52][0] + FmRadial[53][0] + FmRadial[54][0] + FmRadial[55][0] + FmRadial[56][0] + FmRadial[57][0] + FmRadial[58][0] + FmRadial[59][0] + FmRadial[60][0] + FmRadial[61][0] + FmRadial[62][0] + FmRadial[63][0] + FmRadial[64][0] + FmRadial[65][0] + FmRadial[66][0] + FmRadial[67][0] + FmRadial[68][0] + FmRadial[69][0] + FmRadial[70][0] + FmRadial[71][0] + FmRadial[72][0] + FmRadial[73][0] + FmRadial[74][0] + FmRadial[75][0] + FmRadial[76][0] + FmRadial[77][0] + FmRadial[78][0] + FmRadial[79][0] + FmRadial[80][0] + FmRadial[81][0] + FmRadial[82][0] + FmRadial[83][0] + FmRadial[84][0] + FmRadial[85][0] + FmRadial[86][0] + FmRadial[87][0] + FmRadial[88][0] + FmRadial[89][0] + FmRadial[90][0] + FmRadial[91][0] + FmRadial[92][0] + FmRadial[93][0] + FmRadial[94][0] + FmRadial[95][0] + FmRadial[96][0] + FmRadial[97][0] + FmRadial[98][0] + FmRadial[99][0] + FmRadial[100][0] + FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0] + FmTangential[41][0] + FmTangential[42][0] + FmTangential[43][0] + FmTangential[44][0] + FmTangential[45][0] + FmTangential[46][0] + FmTangential[47][0] + FmTangential[48][0] + FmTangential[49][0] + FmTangential[50][0] + FmTangential[51][0] + FmTangential[52][0] + FmTangential[53][0] + FmTangential[54][0] + FmTangential[55][0] + FmTangential[56][0] + FmTangential[57][0] + FmTangential[58][0] + FmTangential[59][0] + FmTangential[60][0] + FmTangential[61][0] + FmTangential[62][0] + FmTangential[63][0] + FmTangential[64][0] + FmTangential[65][0] + FmTangential[66][0] + FmTangential[67][0] + FmTangential[68][0] + FmTangential[69][0] + FmTangential[70][0] + FmTangential[71][0] + FmTangential[72][0] + FmTangential[73][0] + FmTangential[74][0] + FmTangential[75][0] + FmTangential[76][0] + FmTangential[77][0] + FmTangential[78][0] + FmTangential[79][0] + FmTangential[80][0] + FmTangential[81][0] + FmTangential[82][0] + FmTangential[83][0] + FmTangential[84][0] + FmTangential[85][0] + FmTangential[86][0] + FmTangential[87][0] + FmTangential[88][0] + FmTangential[89][0] + FmTangential[90][0] + FmTangential[91][0] + FmTangential[92][0] + FmTangential[93][0] + FmTangential[94][0] + FmTangential[95][0] + FmTangential[96][0] + FmTangential[97][0] + FmTangential[98][0] + FmTangential[99][0] + FmTangential[100][0]);

            c1[1] = c[1] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[1] + dt*muCargoTranslation*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1] + FmRadial[2][1] + FmRadial[3][1] + FmRadial[4][1] + FmRadial[5][1] + FmRadial[6][1] + FmRadial[7][1] + FmRadial[8][1] + FmRadial[9][1] + FmRadial[10][1] + FmRadial[11][1] + FmRadial[12][1] + FmRadial[13][1] + FmRadial[14][1] + FmRadial[15][1] + FmRadial[16][1] + FmRadial[17][1] + FmRadial[18][1] + FmRadial[19][1] + FmRadial[20][1] + FmRadial[21][1] + FmRadial[22][1] + FmRadial[23][1] + FmRadial[24][1] + FmRadial[25][1] + FmRadial[26][1] + FmRadial[27][1] + FmRadial[28][1] + FmRadial[29][1] + FmRadial[30][1] + FmRadial[31][1] + FmRadial[32][1] + FmRadial[33][1] + FmRadial[34][1] + FmRadial[35][1] + FmRadial[36][1] + FmRadial[37][1] + FmRadial[38][1] + FmRadial[39][1] + FmRadial[40][1] + FmRadial[41][1] + FmRadial[42][1] + FmRadial[43][1] + FmRadial[44][1] + FmRadial[45][1] + FmRadial[46][1] + FmRadial[47][1] + FmRadial[48][1] + FmRadial[49][1] + FmRadial[50][1] + FmRadial[51][1] + FmRadial[52][1] + FmRadial[53][1] + FmRadial[54][1] + FmRadial[55][1] + FmRadial[56][1] + FmRadial[57][1] + FmRadial[58][1] + FmRadial[59][1] + FmRadial[60][1] + FmRadial[61][1] + FmRadial[62][1] + FmRadial[63][1] + FmRadial[64][1] + FmRadial[65][1] + FmRadial[66][1] + FmRadial[67][1] + FmRadial[68][1] + FmRadial[69][1] + FmRadial[70][1] + FmRadial[71][1] + FmRadial[72][1] + FmRadial[73][1] + FmRadial[74][1] + FmRadial[75][1] + FmRadial[76][1] + FmRadial[77][1] + FmRadial[78][1] + FmRadial[79][1] + FmRadial[80][1] + FmRadial[81][1] + FmRadial[82][1] + FmRadial[83][1] + FmRadial[84][1] + FmRadial[85][1] + FmRadial[86][1] + FmRadial[87][1] + FmRadial[88][1] + FmRadial[89][1] + FmRadial[90][1] + FmRadial[91][1] + FmRadial[92][1] + FmRadial[93][1] + FmRadial[94][1] + FmRadial[95][1] + FmRadial[96][1] + FmRadial[97][1] + FmRadial[98][1] + FmRadial[99][1] + FmRadial[100][1] + FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1] + FmTangential[19][1] + FmTangential[20][1] + FmTangential[21][1] + FmTangential[22][1] + FmTangential[23][1] + FmTangential[24][1] + FmTangential[25][1] + FmTangential[26][1] + FmTangential[27][1] + FmTangential[28][1] + FmTangential[29][1] + FmTangential[30][1] + FmTangential[31][1] + FmTangential[32][1] + FmTangential[33][1] + FmTangential[34][1] + FmTangential[35][1] + FmTangential[36][1] + FmTangential[37][1] + FmTangential[38][1] + FmTangential[39][1] + FmTangential[40][1] + FmTangential[41][1] + FmTangential[42][1] + FmTangential[43][1] + FmTangential[44][1] + FmTangential[45][1] + FmTangential[46][1] + FmTangential[47][1] + FmTangential[48][1] + FmTangential[49][1] + FmTangential[50][1] + FmTangential[51][1] + FmTangential[52][1] + FmTangential[53][1] + FmTangential[54][1] + FmTangential[55][1] + FmTangential[56][1] + FmTangential[57][1] + FmTangential[58][1] + FmTangential[59][1] + FmTangential[60][1] + FmTangential[61][1] + FmTangential[62][1] + FmTangential[63][1] + FmTangential[64][1] + FmTangential[65][1] + FmTangential[66][1] + FmTangential[67][1] + FmTangential[68][1] + FmTangential[69][1] + FmTangential[70][1] + FmTangential[71][1] + FmTangential[72][1] + FmTangential[73][1] + FmTangential[74][1] + FmTangential[75][1] + FmTangential[76][1] + FmTangential[77][1] + FmTangential[78][1] + FmTangential[79][1] + FmTangential[80][1] + FmTangential[81][1] + FmTangential[82][1] + FmTangential[83][1] + FmTangential[84][1] + FmTangential[85][1] + FmTangential[86][1] + FmTangential[87][1] + FmTangential[88][1] + FmTangential[89][1] + FmTangential[90][1] + FmTangential[91][1] + FmTangential[92][1] + FmTangential[93][1] + FmTangential[94][1] + FmTangential[95][1] + FmTangential[96][1] + FmTangential[97][1] + FmTangential[98][1] + FmTangential[99][1] + FmTangential[100][1]);

            c1[2] = c[2] + sqrt(2)*sqrt(DCargoTranslation)*sqrt(dt)*Dbc[2] + dt*muCargoTranslation*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2] + FmRadial[2][2] + FmRadial[3][2] + FmRadial[4][2] + FmRadial[5][2] + FmRadial[6][2] + FmRadial[7][2] + FmRadial[8][2] + FmRadial[9][2] + FmRadial[10][2] + FmRadial[11][2] + FmRadial[12][2] + FmRadial[13][2] + FmRadial[14][2] + FmRadial[15][2] + FmRadial[16][2] + FmRadial[17][2] + FmRadial[18][2] + FmRadial[19][2] + FmRadial[20][2] + FmRadial[21][2] + FmRadial[22][2] + FmRadial[23][2] + FmRadial[24][2] + FmRadial[25][2] + FmRadial[26][2] + FmRadial[27][2] + FmRadial[28][2] + FmRadial[29][2] + FmRadial[30][2] + FmRadial[31][2] + FmRadial[32][2] + FmRadial[33][2] + FmRadial[34][2] + FmRadial[35][2] + FmRadial[36][2] + FmRadial[37][2] + FmRadial[38][2] + FmRadial[39][2] + FmRadial[40][2] + FmRadial[41][2] + FmRadial[42][2] + FmRadial[43][2] + FmRadial[44][2] + FmRadial[45][2] + FmRadial[46][2] + FmRadial[47][2] + FmRadial[48][2] + FmRadial[49][2] + FmRadial[50][2] + FmRadial[51][2] + FmRadial[52][2] + FmRadial[53][2] + FmRadial[54][2] + FmRadial[55][2] + FmRadial[56][2] + FmRadial[57][2] + FmRadial[58][2] + FmRadial[59][2] + FmRadial[60][2] + FmRadial[61][2] + FmRadial[62][2] + FmRadial[63][2] + FmRadial[64][2] + FmRadial[65][2] + FmRadial[66][2] + FmRadial[67][2] + FmRadial[68][2] + FmRadial[69][2] + FmRadial[70][2] + FmRadial[71][2] + FmRadial[72][2] + FmRadial[73][2] + FmRadial[74][2] + FmRadial[75][2] + FmRadial[76][2] + FmRadial[77][2] + FmRadial[78][2] + FmRadial[79][2] + FmRadial[80][2] + FmRadial[81][2] + FmRadial[82][2] + FmRadial[83][2] + FmRadial[84][2] + FmRadial[85][2] + FmRadial[86][2] + FmRadial[87][2] + FmRadial[88][2] + FmRadial[89][2] + FmRadial[90][2] + FmRadial[91][2] + FmRadial[92][2] + FmRadial[93][2] + FmRadial[94][2] + FmRadial[95][2] + FmRadial[96][2] + FmRadial[97][2] + FmRadial[98][2] + FmRadial[99][2] + FmRadial[100][2] + FmTangential[0][2] + FmTangential[1][2] + FmTangential[2][2] + FmTangential[3][2] + FmTangential[4][2] + FmTangential[5][2] + FmTangential[6][2] + FmTangential[7][2] + FmTangential[8][2] + FmTangential[9][2] + FmTangential[10][2] + FmTangential[11][2] + FmTangential[12][2] + FmTangential[13][2] + FmTangential[14][2] + FmTangential[15][2] + FmTangential[16][2] + FmTangential[17][2] + FmTangential[18][2] + FmTangential[19][2] + FmTangential[20][2] + FmTangential[21][2] + FmTangential[22][2] + FmTangential[23][2] + FmTangential[24][2] + FmTangential[25][2] + FmTangential[26][2] + FmTangential[27][2] + FmTangential[28][2] + FmTangential[29][2] + FmTangential[30][2] + FmTangential[31][2] + FmTangential[32][2] + FmTangential[33][2] + FmTangential[34][2] + FmTangential[35][2] + FmTangential[36][2] + FmTangential[37][2] + FmTangential[38][2] + FmTangential[39][2] + FmTangential[40][2] + FmTangential[41][2] + FmTangential[42][2] + FmTangential[43][2] + FmTangential[44][2] + FmTangential[45][2] + FmTangential[46][2] + FmTangential[47][2] + FmTangential[48][2] + FmTangential[49][2] + FmTangential[50][2] + FmTangential[51][2] + FmTangential[52][2] + FmTangential[53][2] + FmTangential[54][2] + FmTangential[55][2] + FmTangential[56][2] + FmTangential[57][2] + FmTangential[58][2] + FmTangential[59][2] + FmTangential[60][2] + FmTangential[61][2] + FmTangential[62][2] + FmTangential[63][2] + FmTangential[64][2] + FmTangential[65][2] + FmTangential[66][2] + FmTangential[67][2] + FmTangential[68][2] + FmTangential[69][2] + FmTangential[70][2] + FmTangential[71][2] + FmTangential[72][2] + FmTangential[73][2] + FmTangential[74][2] + FmTangential[75][2] + FmTangential[76][2] + FmTangential[77][2] + FmTangential[78][2] + FmTangential[79][2] + FmTangential[80][2] + FmTangential[81][2] + FmTangential[82][2] + FmTangential[83][2] + FmTangential[84][2] + FmTangential[85][2] + FmTangential[86][2] + FmTangential[87][2] + FmTangential[88][2] + FmTangential[89][2] + FmTangential[90][2] + FmTangential[91][2] + FmTangential[92][2] + FmTangential[93][2] + FmTangential[94][2] + FmTangential[95][2] + FmTangential[96][2] + FmTangential[97][2] + FmTangential[98][2] + FmTangential[99][2] + FmTangential[100][2]);

            theta1[0] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[0] + theta[0] + dt*muCargoRotation*(TorqeExt[0] - a[0][2]*FmTangential[0][1] - c[1]*FmTangential[0][2] + a[0][1]*FmTangential[0][2] - a[1][2]*FmTangential[1][1] - c[1]*FmTangential[1][2] + a[1][1]*FmTangential[1][2] - a[2][2]*FmTangential[2][1] - c[1]*FmTangential[2][2] + a[2][1]*FmTangential[2][2] - a[3][2]*FmTangential[3][1] - c[1]*FmTangential[3][2] + a[3][1]*FmTangential[3][2] - a[4][2]*FmTangential[4][1] - c[1]*FmTangential[4][2] + a[4][1]*FmTangential[4][2] - a[5][2]*FmTangential[5][1] - c[1]*FmTangential[5][2] + a[5][1]*FmTangential[5][2] - a[6][2]*FmTangential[6][1] - c[1]*FmTangential[6][2] + a[6][1]*FmTangential[6][2] - a[7][2]*FmTangential[7][1] - c[1]*FmTangential[7][2] + a[7][1]*FmTangential[7][2] - a[8][2]*FmTangential[8][1] - c[1]*FmTangential[8][2] + a[8][1]*FmTangential[8][2] - a[9][2]*FmTangential[9][1] - c[1]*FmTangential[9][2] + a[9][1]*FmTangential[9][2] - a[10][2]*FmTangential[10][1] - c[1]*FmTangential[10][2] + a[10][1]*FmTangential[10][2] - a[11][2]*FmTangential[11][1] - c[1]*FmTangential[11][2] + a[11][1]*FmTangential[11][2] - a[12][2]*FmTangential[12][1] - c[1]*FmTangential[12][2] + a[12][1]*FmTangential[12][2] - a[13][2]*FmTangential[13][1] - c[1]*FmTangential[13][2] + a[13][1]*FmTangential[13][2] - a[14][2]*FmTangential[14][1] - c[1]*FmTangential[14][2] + a[14][1]*FmTangential[14][2] - a[15][2]*FmTangential[15][1] - c[1]*FmTangential[15][2] + a[15][1]*FmTangential[15][2] - a[16][2]*FmTangential[16][1] - c[1]*FmTangential[16][2] + a[16][1]*FmTangential[16][2] - a[17][2]*FmTangential[17][1] - c[1]*FmTangential[17][2] + a[17][1]*FmTangential[17][2] - a[18][2]*FmTangential[18][1] - c[1]*FmTangential[18][2] + a[18][1]*FmTangential[18][2] - a[19][2]*FmTangential[19][1] - c[1]*FmTangential[19][2] + a[19][1]*FmTangential[19][2] - a[20][2]*FmTangential[20][1] - c[1]*FmTangential[20][2] + a[20][1]*FmTangential[20][2] - a[21][2]*FmTangential[21][1] - c[1]*FmTangential[21][2] + a[21][1]*FmTangential[21][2] - a[22][2]*FmTangential[22][1] - c[1]*FmTangential[22][2] + a[22][1]*FmTangential[22][2] - a[23][2]*FmTangential[23][1] - c[1]*FmTangential[23][2] + a[23][1]*FmTangential[23][2] - a[24][2]*FmTangential[24][1] - c[1]*FmTangential[24][2] + a[24][1]*FmTangential[24][2] - a[25][2]*FmTangential[25][1] - c[1]*FmTangential[25][2] + a[25][1]*FmTangential[25][2] - a[26][2]*FmTangential[26][1] - c[1]*FmTangential[26][2] + a[26][1]*FmTangential[26][2] - a[27][2]*FmTangential[27][1] - c[1]*FmTangential[27][2] + a[27][1]*FmTangential[27][2] - a[28][2]*FmTangential[28][1] - c[1]*FmTangential[28][2] + a[28][1]*FmTangential[28][2] - a[29][2]*FmTangential[29][1] - c[1]*FmTangential[29][2] + a[29][1]*FmTangential[29][2] - a[30][2]*FmTangential[30][1] - c[1]*FmTangential[30][2] + a[30][1]*FmTangential[30][2] - a[31][2]*FmTangential[31][1] - c[1]*FmTangential[31][2] + a[31][1]*FmTangential[31][2] - a[32][2]*FmTangential[32][1] - c[1]*FmTangential[32][2] + a[32][1]*FmTangential[32][2] - a[33][2]*FmTangential[33][1] - c[1]*FmTangential[33][2] + a[33][1]*FmTangential[33][2] - a[34][2]*FmTangential[34][1] - c[1]*FmTangential[34][2] + a[34][1]*FmTangential[34][2] - a[35][2]*FmTangential[35][1] - c[1]*FmTangential[35][2] + a[35][1]*FmTangential[35][2] - a[36][2]*FmTangential[36][1] - c[1]*FmTangential[36][2] + a[36][1]*FmTangential[36][2] - a[37][2]*FmTangential[37][1] - c[1]*FmTangential[37][2] + a[37][1]*FmTangential[37][2] - a[38][2]*FmTangential[38][1] - c[1]*FmTangential[38][2] + a[38][1]*FmTangential[38][2] - a[39][2]*FmTangential[39][1] - c[1]*FmTangential[39][2] + a[39][1]*FmTangential[39][2] - a[40][2]*FmTangential[40][1] - c[1]*FmTangential[40][2] + a[40][1]*FmTangential[40][2] - a[41][2]*FmTangential[41][1] - c[1]*FmTangential[41][2] + a[41][1]*FmTangential[41][2] - a[42][2]*FmTangential[42][1] - c[1]*FmTangential[42][2] + a[42][1]*FmTangential[42][2] - a[43][2]*FmTangential[43][1] - c[1]*FmTangential[43][2] + a[43][1]*FmTangential[43][2] - a[44][2]*FmTangential[44][1] - c[1]*FmTangential[44][2] + a[44][1]*FmTangential[44][2] - a[45][2]*FmTangential[45][1] - c[1]*FmTangential[45][2] + a[45][1]*FmTangential[45][2] - a[46][2]*FmTangential[46][1] - c[1]*FmTangential[46][2] + a[46][1]*FmTangential[46][2] - a[47][2]*FmTangential[47][1] - c[1]*FmTangential[47][2] + a[47][1]*FmTangential[47][2] - a[48][2]*FmTangential[48][1] - c[1]*FmTangential[48][2] + a[48][1]*FmTangential[48][2] - a[49][2]*FmTangential[49][1] - c[1]*FmTangential[49][2] + a[49][1]*FmTangential[49][2] - a[50][2]*FmTangential[50][1] - c[1]*FmTangential[50][2] + a[50][1]*FmTangential[50][2] - a[51][2]*FmTangential[51][1] - c[1]*FmTangential[51][2] + a[51][1]*FmTangential[51][2] - a[52][2]*FmTangential[52][1] - c[1]*FmTangential[52][2] + a[52][1]*FmTangential[52][2] - a[53][2]*FmTangential[53][1] - c[1]*FmTangential[53][2] + a[53][1]*FmTangential[53][2] - a[54][2]*FmTangential[54][1] - c[1]*FmTangential[54][2] + a[54][1]*FmTangential[54][2] - a[55][2]*FmTangential[55][1] - c[1]*FmTangential[55][2] + a[55][1]*FmTangential[55][2] - a[56][2]*FmTangential[56][1] - c[1]*FmTangential[56][2] + a[56][1]*FmTangential[56][2] - a[57][2]*FmTangential[57][1] - c[1]*FmTangential[57][2] + a[57][1]*FmTangential[57][2] - a[58][2]*FmTangential[58][1] - c[1]*FmTangential[58][2] + a[58][1]*FmTangential[58][2] - a[59][2]*FmTangential[59][1] - c[1]*FmTangential[59][2] + a[59][1]*FmTangential[59][2] - a[60][2]*FmTangential[60][1] - c[1]*FmTangential[60][2] + a[60][1]*FmTangential[60][2] - a[61][2]*FmTangential[61][1] - c[1]*FmTangential[61][2] + a[61][1]*FmTangential[61][2] - a[62][2]*FmTangential[62][1] - c[1]*FmTangential[62][2] + a[62][1]*FmTangential[62][2] - a[63][2]*FmTangential[63][1] - c[1]*FmTangential[63][2] + a[63][1]*FmTangential[63][2] - a[64][2]*FmTangential[64][1] - c[1]*FmTangential[64][2] + a[64][1]*FmTangential[64][2] - a[65][2]*FmTangential[65][1] - c[1]*FmTangential[65][2] + a[65][1]*FmTangential[65][2] - a[66][2]*FmTangential[66][1] - c[1]*FmTangential[66][2] + a[66][1]*FmTangential[66][2] - a[67][2]*FmTangential[67][1] - c[1]*FmTangential[67][2] + a[67][1]*FmTangential[67][2] - a[68][2]*FmTangential[68][1] - c[1]*FmTangential[68][2] + a[68][1]*FmTangential[68][2] - a[69][2]*FmTangential[69][1] - c[1]*FmTangential[69][2] + a[69][1]*FmTangential[69][2] - a[70][2]*FmTangential[70][1] - c[1]*FmTangential[70][2] + a[70][1]*FmTangential[70][2] - a[71][2]*FmTangential[71][1] - c[1]*FmTangential[71][2] + a[71][1]*FmTangential[71][2] - a[72][2]*FmTangential[72][1] - c[1]*FmTangential[72][2] + a[72][1]*FmTangential[72][2] - a[73][2]*FmTangential[73][1] - c[1]*FmTangential[73][2] + a[73][1]*FmTangential[73][2] - a[74][2]*FmTangential[74][1] - c[1]*FmTangential[74][2] + a[74][1]*FmTangential[74][2] - a[75][2]*FmTangential[75][1] - c[1]*FmTangential[75][2] + a[75][1]*FmTangential[75][2] - a[76][2]*FmTangential[76][1] - c[1]*FmTangential[76][2] + a[76][1]*FmTangential[76][2] - a[77][2]*FmTangential[77][1] - c[1]*FmTangential[77][2] + a[77][1]*FmTangential[77][2] - a[78][2]*FmTangential[78][1] - c[1]*FmTangential[78][2] + a[78][1]*FmTangential[78][2] - a[79][2]*FmTangential[79][1] - c[1]*FmTangential[79][2] + a[79][1]*FmTangential[79][2] - a[80][2]*FmTangential[80][1] - c[1]*FmTangential[80][2] + a[80][1]*FmTangential[80][2] - a[81][2]*FmTangential[81][1] - c[1]*FmTangential[81][2] + a[81][1]*FmTangential[81][2] - a[82][2]*FmTangential[82][1] - c[1]*FmTangential[82][2] + a[82][1]*FmTangential[82][2] - a[83][2]*FmTangential[83][1] - c[1]*FmTangential[83][2] + a[83][1]*FmTangential[83][2] - a[84][2]*FmTangential[84][1] - c[1]*FmTangential[84][2] + a[84][1]*FmTangential[84][2] - a[85][2]*FmTangential[85][1] - c[1]*FmTangential[85][2] + a[85][1]*FmTangential[85][2] - a[86][2]*FmTangential[86][1] - c[1]*FmTangential[86][2] + a[86][1]*FmTangential[86][2] - a[87][2]*FmTangential[87][1] - c[1]*FmTangential[87][2] + a[87][1]*FmTangential[87][2] - a[88][2]*FmTangential[88][1] - c[1]*FmTangential[88][2] + a[88][1]*FmTangential[88][2] - a[89][2]*FmTangential[89][1] - c[1]*FmTangential[89][2] + a[89][1]*FmTangential[89][2] - a[90][2]*FmTangential[90][1] - c[1]*FmTangential[90][2] + a[90][1]*FmTangential[90][2] - a[91][2]*FmTangential[91][1] - c[1]*FmTangential[91][2] + a[91][1]*FmTangential[91][2] - a[92][2]*FmTangential[92][1] - c[1]*FmTangential[92][2] + a[92][1]*FmTangential[92][2] - a[93][2]*FmTangential[93][1] - c[1]*FmTangential[93][2] + a[93][1]*FmTangential[93][2] - a[94][2]*FmTangential[94][1] - c[1]*FmTangential[94][2] + a[94][1]*FmTangential[94][2] - a[95][2]*FmTangential[95][1] - c[1]*FmTangential[95][2] + a[95][1]*FmTangential[95][2] - a[96][2]*FmTangential[96][1] - c[1]*FmTangential[96][2] + a[96][1]*FmTangential[96][2] - a[97][2]*FmTangential[97][1] - c[1]*FmTangential[97][2] + a[97][1]*FmTangential[97][2] - a[98][2]*FmTangential[98][1] - c[1]*FmTangential[98][2] + a[98][1]*FmTangential[98][2] - a[99][2]*FmTangential[99][1] - c[1]*FmTangential[99][2] + a[99][1]*FmTangential[99][2] - a[100][2]*FmTangential[100][1] + c[2]*(FmTangential[0][1] + FmTangential[1][1] + FmTangential[2][1] + FmTangential[3][1] + FmTangential[4][1] + FmTangential[5][1] + FmTangential[6][1] + FmTangential[7][1] + FmTangential[8][1] + FmTangential[9][1] + FmTangential[10][1] + FmTangential[11][1] + FmTangential[12][1] + FmTangential[13][1] + FmTangential[14][1] + FmTangential[15][1] + FmTangential[16][1] + FmTangential[17][1] + FmTangential[18][1] + FmTangential[19][1] + FmTangential[20][1] + FmTangential[21][1] + FmTangential[22][1] + FmTangential[23][1] + FmTangential[24][1] + FmTangential[25][1] + FmTangential[26][1] + FmTangential[27][1] + FmTangential[28][1] + FmTangential[29][1] + FmTangential[30][1] + FmTangential[31][1] + FmTangential[32][1] + FmTangential[33][1] + FmTangential[34][1] + FmTangential[35][1] + FmTangential[36][1] + FmTangential[37][1] + FmTangential[38][1] + FmTangential[39][1] + FmTangential[40][1] + FmTangential[41][1] + FmTangential[42][1] + FmTangential[43][1] + FmTangential[44][1] + FmTangential[45][1] + FmTangential[46][1] + FmTangential[47][1] + FmTangential[48][1] + FmTangential[49][1] + FmTangential[50][1] + FmTangential[51][1] + FmTangential[52][1] + FmTangential[53][1] + FmTangential[54][1] + FmTangential[55][1] + FmTangential[56][1] + FmTangential[57][1] + FmTangential[58][1] + FmTangential[59][1] + FmTangential[60][1] + FmTangential[61][1] + FmTangential[62][1] + FmTangential[63][1] + FmTangential[64][1] + FmTangential[65][1] + FmTangential[66][1] + FmTangential[67][1] + FmTangential[68][1] + FmTangential[69][1] + FmTangential[70][1] + FmTangential[71][1] + FmTangential[72][1] + FmTangential[73][1] + FmTangential[74][1] + FmTangential[75][1] + FmTangential[76][1] + FmTangential[77][1] + FmTangential[78][1] + FmTangential[79][1] + FmTangential[80][1] + FmTangential[81][1] + FmTangential[82][1] + FmTangential[83][1] + FmTangential[84][1] + FmTangential[85][1] + FmTangential[86][1] + FmTangential[87][1] + FmTangential[88][1] + FmTangential[89][1] + FmTangential[90][1] + FmTangential[91][1] + FmTangential[92][1] + FmTangential[93][1] + FmTangential[94][1] + FmTangential[95][1] + FmTangential[96][1] + FmTangential[97][1] + FmTangential[98][1] + FmTangential[99][1] + FmTangential[100][1]) - c[1]*FmTangential[100][2] + a[100][1]*FmTangential[100][2]);

            theta1[1] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[1] + theta[1] + dt*muCargoRotation*(TorqeExt[1] + a[0][2]*FmTangential[0][0] + c[0]*FmTangential[0][2] - a[0][0]*FmTangential[0][2] + a[1][2]*FmTangential[1][0] + c[0]*FmTangential[1][2] - a[1][0]*FmTangential[1][2] + a[2][2]*FmTangential[2][0] + c[0]*FmTangential[2][2] - a[2][0]*FmTangential[2][2] + a[3][2]*FmTangential[3][0] + c[0]*FmTangential[3][2] - a[3][0]*FmTangential[3][2] + a[4][2]*FmTangential[4][0] + c[0]*FmTangential[4][2] - a[4][0]*FmTangential[4][2] + a[5][2]*FmTangential[5][0] + c[0]*FmTangential[5][2] - a[5][0]*FmTangential[5][2] + a[6][2]*FmTangential[6][0] + c[0]*FmTangential[6][2] - a[6][0]*FmTangential[6][2] + a[7][2]*FmTangential[7][0] + c[0]*FmTangential[7][2] - a[7][0]*FmTangential[7][2] + a[8][2]*FmTangential[8][0] + c[0]*FmTangential[8][2] - a[8][0]*FmTangential[8][2] + a[9][2]*FmTangential[9][0] + c[0]*FmTangential[9][2] - a[9][0]*FmTangential[9][2] + a[10][2]*FmTangential[10][0] + c[0]*FmTangential[10][2] - a[10][0]*FmTangential[10][2] + a[11][2]*FmTangential[11][0] + c[0]*FmTangential[11][2] - a[11][0]*FmTangential[11][2] + a[12][2]*FmTangential[12][0] + c[0]*FmTangential[12][2] - a[12][0]*FmTangential[12][2] + a[13][2]*FmTangential[13][0] + c[0]*FmTangential[13][2] - a[13][0]*FmTangential[13][2] + a[14][2]*FmTangential[14][0] + c[0]*FmTangential[14][2] - a[14][0]*FmTangential[14][2] + a[15][2]*FmTangential[15][0] + c[0]*FmTangential[15][2] - a[15][0]*FmTangential[15][2] + a[16][2]*FmTangential[16][0] + c[0]*FmTangential[16][2] - a[16][0]*FmTangential[16][2] + a[17][2]*FmTangential[17][0] + c[0]*FmTangential[17][2] - a[17][0]*FmTangential[17][2] + a[18][2]*FmTangential[18][0] + c[0]*FmTangential[18][2] - a[18][0]*FmTangential[18][2] + a[19][2]*FmTangential[19][0] + c[0]*FmTangential[19][2] - a[19][0]*FmTangential[19][2] + a[20][2]*FmTangential[20][0] + c[0]*FmTangential[20][2] - a[20][0]*FmTangential[20][2] + a[21][2]*FmTangential[21][0] + c[0]*FmTangential[21][2] - a[21][0]*FmTangential[21][2] + a[22][2]*FmTangential[22][0] + c[0]*FmTangential[22][2] - a[22][0]*FmTangential[22][2] + a[23][2]*FmTangential[23][0] + c[0]*FmTangential[23][2] - a[23][0]*FmTangential[23][2] + a[24][2]*FmTangential[24][0] + c[0]*FmTangential[24][2] - a[24][0]*FmTangential[24][2] + a[25][2]*FmTangential[25][0] + c[0]*FmTangential[25][2] - a[25][0]*FmTangential[25][2] + a[26][2]*FmTangential[26][0] + c[0]*FmTangential[26][2] - a[26][0]*FmTangential[26][2] + a[27][2]*FmTangential[27][0] + c[0]*FmTangential[27][2] - a[27][0]*FmTangential[27][2] + a[28][2]*FmTangential[28][0] + c[0]*FmTangential[28][2] - a[28][0]*FmTangential[28][2] + a[29][2]*FmTangential[29][0] + c[0]*FmTangential[29][2] - a[29][0]*FmTangential[29][2] + a[30][2]*FmTangential[30][0] + c[0]*FmTangential[30][2] - a[30][0]*FmTangential[30][2] + a[31][2]*FmTangential[31][0] + c[0]*FmTangential[31][2] - a[31][0]*FmTangential[31][2] + a[32][2]*FmTangential[32][0] + c[0]*FmTangential[32][2] - a[32][0]*FmTangential[32][2] + a[33][2]*FmTangential[33][0] + c[0]*FmTangential[33][2] - a[33][0]*FmTangential[33][2] + a[34][2]*FmTangential[34][0] + c[0]*FmTangential[34][2] - a[34][0]*FmTangential[34][2] + a[35][2]*FmTangential[35][0] + c[0]*FmTangential[35][2] - a[35][0]*FmTangential[35][2] + a[36][2]*FmTangential[36][0] + c[0]*FmTangential[36][2] - a[36][0]*FmTangential[36][2] + a[37][2]*FmTangential[37][0] + c[0]*FmTangential[37][2] - a[37][0]*FmTangential[37][2] + a[38][2]*FmTangential[38][0] + c[0]*FmTangential[38][2] - a[38][0]*FmTangential[38][2] + a[39][2]*FmTangential[39][0] + c[0]*FmTangential[39][2] - a[39][0]*FmTangential[39][2] + a[40][2]*FmTangential[40][0] + c[0]*FmTangential[40][2] - a[40][0]*FmTangential[40][2] + a[41][2]*FmTangential[41][0] + c[0]*FmTangential[41][2] - a[41][0]*FmTangential[41][2] + a[42][2]*FmTangential[42][0] + c[0]*FmTangential[42][2] - a[42][0]*FmTangential[42][2] + a[43][2]*FmTangential[43][0] + c[0]*FmTangential[43][2] - a[43][0]*FmTangential[43][2] + a[44][2]*FmTangential[44][0] + c[0]*FmTangential[44][2] - a[44][0]*FmTangential[44][2] + a[45][2]*FmTangential[45][0] + c[0]*FmTangential[45][2] - a[45][0]*FmTangential[45][2] + a[46][2]*FmTangential[46][0] + c[0]*FmTangential[46][2] - a[46][0]*FmTangential[46][2] + a[47][2]*FmTangential[47][0] + c[0]*FmTangential[47][2] - a[47][0]*FmTangential[47][2] + a[48][2]*FmTangential[48][0] + c[0]*FmTangential[48][2] - a[48][0]*FmTangential[48][2] + a[49][2]*FmTangential[49][0] + c[0]*FmTangential[49][2] - a[49][0]*FmTangential[49][2] + a[50][2]*FmTangential[50][0] + c[0]*FmTangential[50][2] - a[50][0]*FmTangential[50][2] + a[51][2]*FmTangential[51][0] + c[0]*FmTangential[51][2] - a[51][0]*FmTangential[51][2] + a[52][2]*FmTangential[52][0] + c[0]*FmTangential[52][2] - a[52][0]*FmTangential[52][2] + a[53][2]*FmTangential[53][0] + c[0]*FmTangential[53][2] - a[53][0]*FmTangential[53][2] + a[54][2]*FmTangential[54][0] + c[0]*FmTangential[54][2] - a[54][0]*FmTangential[54][2] + a[55][2]*FmTangential[55][0] + c[0]*FmTangential[55][2] - a[55][0]*FmTangential[55][2] + a[56][2]*FmTangential[56][0] + c[0]*FmTangential[56][2] - a[56][0]*FmTangential[56][2] + a[57][2]*FmTangential[57][0] + c[0]*FmTangential[57][2] - a[57][0]*FmTangential[57][2] + a[58][2]*FmTangential[58][0] + c[0]*FmTangential[58][2] - a[58][0]*FmTangential[58][2] + a[59][2]*FmTangential[59][0] + c[0]*FmTangential[59][2] - a[59][0]*FmTangential[59][2] + a[60][2]*FmTangential[60][0] + c[0]*FmTangential[60][2] - a[60][0]*FmTangential[60][2] + a[61][2]*FmTangential[61][0] + c[0]*FmTangential[61][2] - a[61][0]*FmTangential[61][2] + a[62][2]*FmTangential[62][0] + c[0]*FmTangential[62][2] - a[62][0]*FmTangential[62][2] + a[63][2]*FmTangential[63][0] + c[0]*FmTangential[63][2] - a[63][0]*FmTangential[63][2] + a[64][2]*FmTangential[64][0] + c[0]*FmTangential[64][2] - a[64][0]*FmTangential[64][2] + a[65][2]*FmTangential[65][0] + c[0]*FmTangential[65][2] - a[65][0]*FmTangential[65][2] + a[66][2]*FmTangential[66][0] + c[0]*FmTangential[66][2] - a[66][0]*FmTangential[66][2] + a[67][2]*FmTangential[67][0] + c[0]*FmTangential[67][2] - a[67][0]*FmTangential[67][2] + a[68][2]*FmTangential[68][0] + c[0]*FmTangential[68][2] - a[68][0]*FmTangential[68][2] + a[69][2]*FmTangential[69][0] + c[0]*FmTangential[69][2] - a[69][0]*FmTangential[69][2] + a[70][2]*FmTangential[70][0] + c[0]*FmTangential[70][2] - a[70][0]*FmTangential[70][2] + a[71][2]*FmTangential[71][0] + c[0]*FmTangential[71][2] - a[71][0]*FmTangential[71][2] + a[72][2]*FmTangential[72][0] + c[0]*FmTangential[72][2] - a[72][0]*FmTangential[72][2] + a[73][2]*FmTangential[73][0] + c[0]*FmTangential[73][2] - a[73][0]*FmTangential[73][2] + a[74][2]*FmTangential[74][0] + c[0]*FmTangential[74][2] - a[74][0]*FmTangential[74][2] + a[75][2]*FmTangential[75][0] + c[0]*FmTangential[75][2] - a[75][0]*FmTangential[75][2] + a[76][2]*FmTangential[76][0] + c[0]*FmTangential[76][2] - a[76][0]*FmTangential[76][2] + a[77][2]*FmTangential[77][0] + c[0]*FmTangential[77][2] - a[77][0]*FmTangential[77][2] + a[78][2]*FmTangential[78][0] + c[0]*FmTangential[78][2] - a[78][0]*FmTangential[78][2] + a[79][2]*FmTangential[79][0] + c[0]*FmTangential[79][2] - a[79][0]*FmTangential[79][2] + a[80][2]*FmTangential[80][0] + c[0]*FmTangential[80][2] - a[80][0]*FmTangential[80][2] + a[81][2]*FmTangential[81][0] + c[0]*FmTangential[81][2] - a[81][0]*FmTangential[81][2] + a[82][2]*FmTangential[82][0] + c[0]*FmTangential[82][2] - a[82][0]*FmTangential[82][2] + a[83][2]*FmTangential[83][0] + c[0]*FmTangential[83][2] - a[83][0]*FmTangential[83][2] + a[84][2]*FmTangential[84][0] + c[0]*FmTangential[84][2] - a[84][0]*FmTangential[84][2] + a[85][2]*FmTangential[85][0] + c[0]*FmTangential[85][2] - a[85][0]*FmTangential[85][2] + a[86][2]*FmTangential[86][0] + c[0]*FmTangential[86][2] - a[86][0]*FmTangential[86][2] + a[87][2]*FmTangential[87][0] + c[0]*FmTangential[87][2] - a[87][0]*FmTangential[87][2] + a[88][2]*FmTangential[88][0] + c[0]*FmTangential[88][2] - a[88][0]*FmTangential[88][2] + a[89][2]*FmTangential[89][0] + c[0]*FmTangential[89][2] - a[89][0]*FmTangential[89][2] + a[90][2]*FmTangential[90][0] + c[0]*FmTangential[90][2] - a[90][0]*FmTangential[90][2] + a[91][2]*FmTangential[91][0] + c[0]*FmTangential[91][2] - a[91][0]*FmTangential[91][2] + a[92][2]*FmTangential[92][0] + c[0]*FmTangential[92][2] - a[92][0]*FmTangential[92][2] + a[93][2]*FmTangential[93][0] + c[0]*FmTangential[93][2] - a[93][0]*FmTangential[93][2] + a[94][2]*FmTangential[94][0] + c[0]*FmTangential[94][2] - a[94][0]*FmTangential[94][2] + a[95][2]*FmTangential[95][0] + c[0]*FmTangential[95][2] - a[95][0]*FmTangential[95][2] + a[96][2]*FmTangential[96][0] + c[0]*FmTangential[96][2] - a[96][0]*FmTangential[96][2] + a[97][2]*FmTangential[97][0] + c[0]*FmTangential[97][2] - a[97][0]*FmTangential[97][2] + a[98][2]*FmTangential[98][0] + c[0]*FmTangential[98][2] - a[98][0]*FmTangential[98][2] + a[99][2]*FmTangential[99][0] + c[0]*FmTangential[99][2] - a[99][0]*FmTangential[99][2] + a[100][2]*FmTangential[100][0] - c[2]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0] + FmTangential[41][0] + FmTangential[42][0] + FmTangential[43][0] + FmTangential[44][0] + FmTangential[45][0] + FmTangential[46][0] + FmTangential[47][0] + FmTangential[48][0] + FmTangential[49][0] + FmTangential[50][0] + FmTangential[51][0] + FmTangential[52][0] + FmTangential[53][0] + FmTangential[54][0] + FmTangential[55][0] + FmTangential[56][0] + FmTangential[57][0] + FmTangential[58][0] + FmTangential[59][0] + FmTangential[60][0] + FmTangential[61][0] + FmTangential[62][0] + FmTangential[63][0] + FmTangential[64][0] + FmTangential[65][0] + FmTangential[66][0] + FmTangential[67][0] + FmTangential[68][0] + FmTangential[69][0] + FmTangential[70][0] + FmTangential[71][0] + FmTangential[72][0] + FmTangential[73][0] + FmTangential[74][0] + FmTangential[75][0] + FmTangential[76][0] + FmTangential[77][0] + FmTangential[78][0] + FmTangential[79][0] + FmTangential[80][0] + FmTangential[81][0] + FmTangential[82][0] + FmTangential[83][0] + FmTangential[84][0] + FmTangential[85][0] + FmTangential[86][0] + FmTangential[87][0] + FmTangential[88][0] + FmTangential[89][0] + FmTangential[90][0] + FmTangential[91][0] + FmTangential[92][0] + FmTangential[93][0] + FmTangential[94][0] + FmTangential[95][0] + FmTangential[96][0] + FmTangential[97][0] + FmTangential[98][0] + FmTangential[99][0] + FmTangential[100][0]) + c[0]*FmTangential[100][2] - a[100][0]*FmTangential[100][2]);

            theta1[2] = sqrt(2)*sqrt(DCargoRotation)*sqrt(dt)*Rbc[2] + theta[2] + dt*muCargoRotation*(TorqeExt[2] - a[0][1]*FmTangential[0][0] - c[0]*FmTangential[0][1] + a[0][0]*FmTangential[0][1] - a[1][1]*FmTangential[1][0] - c[0]*FmTangential[1][1] + a[1][0]*FmTangential[1][1] - a[2][1]*FmTangential[2][0] - c[0]*FmTangential[2][1] + a[2][0]*FmTangential[2][1] - a[3][1]*FmTangential[3][0] - c[0]*FmTangential[3][1] + a[3][0]*FmTangential[3][1] - a[4][1]*FmTangential[4][0] - c[0]*FmTangential[4][1] + a[4][0]*FmTangential[4][1] - a[5][1]*FmTangential[5][0] - c[0]*FmTangential[5][1] + a[5][0]*FmTangential[5][1] - a[6][1]*FmTangential[6][0] - c[0]*FmTangential[6][1] + a[6][0]*FmTangential[6][1] - a[7][1]*FmTangential[7][0] - c[0]*FmTangential[7][1] + a[7][0]*FmTangential[7][1] - a[8][1]*FmTangential[8][0] - c[0]*FmTangential[8][1] + a[8][0]*FmTangential[8][1] - a[9][1]*FmTangential[9][0] - c[0]*FmTangential[9][1] + a[9][0]*FmTangential[9][1] - a[10][1]*FmTangential[10][0] - c[0]*FmTangential[10][1] + a[10][0]*FmTangential[10][1] - a[11][1]*FmTangential[11][0] - c[0]*FmTangential[11][1] + a[11][0]*FmTangential[11][1] - a[12][1]*FmTangential[12][0] - c[0]*FmTangential[12][1] + a[12][0]*FmTangential[12][1] - a[13][1]*FmTangential[13][0] - c[0]*FmTangential[13][1] + a[13][0]*FmTangential[13][1] - a[14][1]*FmTangential[14][0] - c[0]*FmTangential[14][1] + a[14][0]*FmTangential[14][1] - a[15][1]*FmTangential[15][0] - c[0]*FmTangential[15][1] + a[15][0]*FmTangential[15][1] - a[16][1]*FmTangential[16][0] - c[0]*FmTangential[16][1] + a[16][0]*FmTangential[16][1] - a[17][1]*FmTangential[17][0] - c[0]*FmTangential[17][1] + a[17][0]*FmTangential[17][1] - a[18][1]*FmTangential[18][0] - c[0]*FmTangential[18][1] + a[18][0]*FmTangential[18][1] - a[19][1]*FmTangential[19][0] - c[0]*FmTangential[19][1] + a[19][0]*FmTangential[19][1] - a[20][1]*FmTangential[20][0] - c[0]*FmTangential[20][1] + a[20][0]*FmTangential[20][1] - a[21][1]*FmTangential[21][0] - c[0]*FmTangential[21][1] + a[21][0]*FmTangential[21][1] - a[22][1]*FmTangential[22][0] - c[0]*FmTangential[22][1] + a[22][0]*FmTangential[22][1] - a[23][1]*FmTangential[23][0] - c[0]*FmTangential[23][1] + a[23][0]*FmTangential[23][1] - a[24][1]*FmTangential[24][0] - c[0]*FmTangential[24][1] + a[24][0]*FmTangential[24][1] - a[25][1]*FmTangential[25][0] - c[0]*FmTangential[25][1] + a[25][0]*FmTangential[25][1] - a[26][1]*FmTangential[26][0] - c[0]*FmTangential[26][1] + a[26][0]*FmTangential[26][1] - a[27][1]*FmTangential[27][0] - c[0]*FmTangential[27][1] + a[27][0]*FmTangential[27][1] - a[28][1]*FmTangential[28][0] - c[0]*FmTangential[28][1] + a[28][0]*FmTangential[28][1] - a[29][1]*FmTangential[29][0] - c[0]*FmTangential[29][1] + a[29][0]*FmTangential[29][1] - a[30][1]*FmTangential[30][0] - c[0]*FmTangential[30][1] + a[30][0]*FmTangential[30][1] - a[31][1]*FmTangential[31][0] - c[0]*FmTangential[31][1] + a[31][0]*FmTangential[31][1] - a[32][1]*FmTangential[32][0] - c[0]*FmTangential[32][1] + a[32][0]*FmTangential[32][1] - a[33][1]*FmTangential[33][0] - c[0]*FmTangential[33][1] + a[33][0]*FmTangential[33][1] - a[34][1]*FmTangential[34][0] - c[0]*FmTangential[34][1] + a[34][0]*FmTangential[34][1] - a[35][1]*FmTangential[35][0] - c[0]*FmTangential[35][1] + a[35][0]*FmTangential[35][1] - a[36][1]*FmTangential[36][0] - c[0]*FmTangential[36][1] + a[36][0]*FmTangential[36][1] - a[37][1]*FmTangential[37][0] - c[0]*FmTangential[37][1] + a[37][0]*FmTangential[37][1] - a[38][1]*FmTangential[38][0] - c[0]*FmTangential[38][1] + a[38][0]*FmTangential[38][1] - a[39][1]*FmTangential[39][0] - c[0]*FmTangential[39][1] + a[39][0]*FmTangential[39][1] - a[40][1]*FmTangential[40][0] - c[0]*FmTangential[40][1] + a[40][0]*FmTangential[40][1] - a[41][1]*FmTangential[41][0] - c[0]*FmTangential[41][1] + a[41][0]*FmTangential[41][1] - a[42][1]*FmTangential[42][0] - c[0]*FmTangential[42][1] + a[42][0]*FmTangential[42][1] - a[43][1]*FmTangential[43][0] - c[0]*FmTangential[43][1] + a[43][0]*FmTangential[43][1] - a[44][1]*FmTangential[44][0] - c[0]*FmTangential[44][1] + a[44][0]*FmTangential[44][1] - a[45][1]*FmTangential[45][0] - c[0]*FmTangential[45][1] + a[45][0]*FmTangential[45][1] - a[46][1]*FmTangential[46][0] - c[0]*FmTangential[46][1] + a[46][0]*FmTangential[46][1] - a[47][1]*FmTangential[47][0] - c[0]*FmTangential[47][1] + a[47][0]*FmTangential[47][1] - a[48][1]*FmTangential[48][0] - c[0]*FmTangential[48][1] + a[48][0]*FmTangential[48][1] - a[49][1]*FmTangential[49][0] - c[0]*FmTangential[49][1] + a[49][0]*FmTangential[49][1] - a[50][1]*FmTangential[50][0] - c[0]*FmTangential[50][1] + a[50][0]*FmTangential[50][1] - a[51][1]*FmTangential[51][0] - c[0]*FmTangential[51][1] + a[51][0]*FmTangential[51][1] - a[52][1]*FmTangential[52][0] - c[0]*FmTangential[52][1] + a[52][0]*FmTangential[52][1] - a[53][1]*FmTangential[53][0] - c[0]*FmTangential[53][1] + a[53][0]*FmTangential[53][1] - a[54][1]*FmTangential[54][0] - c[0]*FmTangential[54][1] + a[54][0]*FmTangential[54][1] - a[55][1]*FmTangential[55][0] - c[0]*FmTangential[55][1] + a[55][0]*FmTangential[55][1] - a[56][1]*FmTangential[56][0] - c[0]*FmTangential[56][1] + a[56][0]*FmTangential[56][1] - a[57][1]*FmTangential[57][0] - c[0]*FmTangential[57][1] + a[57][0]*FmTangential[57][1] - a[58][1]*FmTangential[58][0] - c[0]*FmTangential[58][1] + a[58][0]*FmTangential[58][1] - a[59][1]*FmTangential[59][0] - c[0]*FmTangential[59][1] + a[59][0]*FmTangential[59][1] - a[60][1]*FmTangential[60][0] - c[0]*FmTangential[60][1] + a[60][0]*FmTangential[60][1] - a[61][1]*FmTangential[61][0] - c[0]*FmTangential[61][1] + a[61][0]*FmTangential[61][1] - a[62][1]*FmTangential[62][0] - c[0]*FmTangential[62][1] + a[62][0]*FmTangential[62][1] - a[63][1]*FmTangential[63][0] - c[0]*FmTangential[63][1] + a[63][0]*FmTangential[63][1] - a[64][1]*FmTangential[64][0] - c[0]*FmTangential[64][1] + a[64][0]*FmTangential[64][1] - a[65][1]*FmTangential[65][0] - c[0]*FmTangential[65][1] + a[65][0]*FmTangential[65][1] - a[66][1]*FmTangential[66][0] - c[0]*FmTangential[66][1] + a[66][0]*FmTangential[66][1] - a[67][1]*FmTangential[67][0] - c[0]*FmTangential[67][1] + a[67][0]*FmTangential[67][1] - a[68][1]*FmTangential[68][0] - c[0]*FmTangential[68][1] + a[68][0]*FmTangential[68][1] - a[69][1]*FmTangential[69][0] - c[0]*FmTangential[69][1] + a[69][0]*FmTangential[69][1] - a[70][1]*FmTangential[70][0] - c[0]*FmTangential[70][1] + a[70][0]*FmTangential[70][1] - a[71][1]*FmTangential[71][0] - c[0]*FmTangential[71][1] + a[71][0]*FmTangential[71][1] - a[72][1]*FmTangential[72][0] - c[0]*FmTangential[72][1] + a[72][0]*FmTangential[72][1] - a[73][1]*FmTangential[73][0] - c[0]*FmTangential[73][1] + a[73][0]*FmTangential[73][1] - a[74][1]*FmTangential[74][0] - c[0]*FmTangential[74][1] + a[74][0]*FmTangential[74][1] - a[75][1]*FmTangential[75][0] - c[0]*FmTangential[75][1] + a[75][0]*FmTangential[75][1] - a[76][1]*FmTangential[76][0] - c[0]*FmTangential[76][1] + a[76][0]*FmTangential[76][1] - a[77][1]*FmTangential[77][0] - c[0]*FmTangential[77][1] + a[77][0]*FmTangential[77][1] - a[78][1]*FmTangential[78][0] - c[0]*FmTangential[78][1] + a[78][0]*FmTangential[78][1] - a[79][1]*FmTangential[79][0] - c[0]*FmTangential[79][1] + a[79][0]*FmTangential[79][1] - a[80][1]*FmTangential[80][0] - c[0]*FmTangential[80][1] + a[80][0]*FmTangential[80][1] - a[81][1]*FmTangential[81][0] - c[0]*FmTangential[81][1] + a[81][0]*FmTangential[81][1] - a[82][1]*FmTangential[82][0] - c[0]*FmTangential[82][1] + a[82][0]*FmTangential[82][1] - a[83][1]*FmTangential[83][0] - c[0]*FmTangential[83][1] + a[83][0]*FmTangential[83][1] - a[84][1]*FmTangential[84][0] - c[0]*FmTangential[84][1] + a[84][0]*FmTangential[84][1] - a[85][1]*FmTangential[85][0] - c[0]*FmTangential[85][1] + a[85][0]*FmTangential[85][1] - a[86][1]*FmTangential[86][0] - c[0]*FmTangential[86][1] + a[86][0]*FmTangential[86][1] - a[87][1]*FmTangential[87][0] - c[0]*FmTangential[87][1] + a[87][0]*FmTangential[87][1] - a[88][1]*FmTangential[88][0] - c[0]*FmTangential[88][1] + a[88][0]*FmTangential[88][1] - a[89][1]*FmTangential[89][0] - c[0]*FmTangential[89][1] + a[89][0]*FmTangential[89][1] - a[90][1]*FmTangential[90][0] - c[0]*FmTangential[90][1] + a[90][0]*FmTangential[90][1] - a[91][1]*FmTangential[91][0] - c[0]*FmTangential[91][1] + a[91][0]*FmTangential[91][1] - a[92][1]*FmTangential[92][0] - c[0]*FmTangential[92][1] + a[92][0]*FmTangential[92][1] - a[93][1]*FmTangential[93][0] - c[0]*FmTangential[93][1] + a[93][0]*FmTangential[93][1] - a[94][1]*FmTangential[94][0] - c[0]*FmTangential[94][1] + a[94][0]*FmTangential[94][1] - a[95][1]*FmTangential[95][0] - c[0]*FmTangential[95][1] + a[95][0]*FmTangential[95][1] - a[96][1]*FmTangential[96][0] - c[0]*FmTangential[96][1] + a[96][0]*FmTangential[96][1] - a[97][1]*FmTangential[97][0] - c[0]*FmTangential[97][1] + a[97][0]*FmTangential[97][1] - a[98][1]*FmTangential[98][0] - c[0]*FmTangential[98][1] + a[98][0]*FmTangential[98][1] - a[99][1]*FmTangential[99][0] - c[0]*FmTangential[99][1] + a[99][0]*FmTangential[99][1] - a[100][1]*FmTangential[100][0] + c[1]*(FmTangential[0][0] + FmTangential[1][0] + FmTangential[2][0] + FmTangential[3][0] + FmTangential[4][0] + FmTangential[5][0] + FmTangential[6][0] + FmTangential[7][0] + FmTangential[8][0] + FmTangential[9][0] + FmTangential[10][0] + FmTangential[11][0] + FmTangential[12][0] + FmTangential[13][0] + FmTangential[14][0] + FmTangential[15][0] + FmTangential[16][0] + FmTangential[17][0] + FmTangential[18][0] + FmTangential[19][0] + FmTangential[20][0] + FmTangential[21][0] + FmTangential[22][0] + FmTangential[23][0] + FmTangential[24][0] + FmTangential[25][0] + FmTangential[26][0] + FmTangential[27][0] + FmTangential[28][0] + FmTangential[29][0] + FmTangential[30][0] + FmTangential[31][0] + FmTangential[32][0] + FmTangential[33][0] + FmTangential[34][0] + FmTangential[35][0] + FmTangential[36][0] + FmTangential[37][0] + FmTangential[38][0] + FmTangential[39][0] + FmTangential[40][0] + FmTangential[41][0] + FmTangential[42][0] + FmTangential[43][0] + FmTangential[44][0] + FmTangential[45][0] + FmTangential[46][0] + FmTangential[47][0] + FmTangential[48][0] + FmTangential[49][0] + FmTangential[50][0] + FmTangential[51][0] + FmTangential[52][0] + FmTangential[53][0] + FmTangential[54][0] + FmTangential[55][0] + FmTangential[56][0] + FmTangential[57][0] + FmTangential[58][0] + FmTangential[59][0] + FmTangential[60][0] + FmTangential[61][0] + FmTangential[62][0] + FmTangential[63][0] + FmTangential[64][0] + FmTangential[65][0] + FmTangential[66][0] + FmTangential[67][0] + FmTangential[68][0] + FmTangential[69][0] + FmTangential[70][0] + FmTangential[71][0] + FmTangential[72][0] + FmTangential[73][0] + FmTangential[74][0] + FmTangential[75][0] + FmTangential[76][0] + FmTangential[77][0] + FmTangential[78][0] + FmTangential[79][0] + FmTangential[80][0] + FmTangential[81][0] + FmTangential[82][0] + FmTangential[83][0] + FmTangential[84][0] + FmTangential[85][0] + FmTangential[86][0] + FmTangential[87][0] + FmTangential[88][0] + FmTangential[89][0] + FmTangential[90][0] + FmTangential[91][0] + FmTangential[92][0] + FmTangential[93][0] + FmTangential[94][0] + FmTangential[95][0] + FmTangential[96][0] + FmTangential[97][0] + FmTangential[98][0] + FmTangential[99][0] + FmTangential[100][0]) - c[0]*FmTangential[100][1] + a[100][0]*FmTangential[100][1]);

            a1[0][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[0][0] + theta[2]*a[0][1] - theta1[2]*a[0][1] - theta[1]*a[0][2] + theta1[1]*a[0][2];

            a1[0][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[0][0] + theta1[2]*a[0][0] + a[0][1] + theta[0]*a[0][2] - theta1[0]*a[0][2];

            a1[0][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[0][0] - theta1[1]*a[0][0] - theta[0]*a[0][1] + theta1[0]*a[0][1] + a[0][2];

            a1[1][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[1][0] + theta[2]*a[1][1] - theta1[2]*a[1][1] - theta[1]*a[1][2] + theta1[1]*a[1][2];

            a1[1][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[1][0] + theta1[2]*a[1][0] + a[1][1] + theta[0]*a[1][2] - theta1[0]*a[1][2];

            a1[1][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[1][0] - theta1[1]*a[1][0] - theta[0]*a[1][1] + theta1[0]*a[1][1] + a[1][2];

            a1[2][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[2][0] + theta[2]*a[2][1] - theta1[2]*a[2][1] - theta[1]*a[2][2] + theta1[1]*a[2][2];

            a1[2][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[2][0] + theta1[2]*a[2][0] + a[2][1] + theta[0]*a[2][2] - theta1[0]*a[2][2];

            a1[2][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[2][0] - theta1[1]*a[2][0] - theta[0]*a[2][1] + theta1[0]*a[2][1] + a[2][2];

            a1[3][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[3][0] + theta[2]*a[3][1] - theta1[2]*a[3][1] - theta[1]*a[3][2] + theta1[1]*a[3][2];

            a1[3][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[3][0] + theta1[2]*a[3][0] + a[3][1] + theta[0]*a[3][2] - theta1[0]*a[3][2];

            a1[3][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[3][0] - theta1[1]*a[3][0] - theta[0]*a[3][1] + theta1[0]*a[3][1] + a[3][2];

            a1[4][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[4][0] + theta[2]*a[4][1] - theta1[2]*a[4][1] - theta[1]*a[4][2] + theta1[1]*a[4][2];

            a1[4][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[4][0] + theta1[2]*a[4][0] + a[4][1] + theta[0]*a[4][2] - theta1[0]*a[4][2];

            a1[4][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[4][0] - theta1[1]*a[4][0] - theta[0]*a[4][1] + theta1[0]*a[4][1] + a[4][2];

            a1[5][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[5][0] + theta[2]*a[5][1] - theta1[2]*a[5][1] - theta[1]*a[5][2] + theta1[1]*a[5][2];

            a1[5][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[5][0] + theta1[2]*a[5][0] + a[5][1] + theta[0]*a[5][2] - theta1[0]*a[5][2];

            a1[5][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[5][0] - theta1[1]*a[5][0] - theta[0]*a[5][1] + theta1[0]*a[5][1] + a[5][2];

            a1[6][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[6][0] + theta[2]*a[6][1] - theta1[2]*a[6][1] - theta[1]*a[6][2] + theta1[1]*a[6][2];

            a1[6][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[6][0] + theta1[2]*a[6][0] + a[6][1] + theta[0]*a[6][2] - theta1[0]*a[6][2];

            a1[6][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[6][0] - theta1[1]*a[6][0] - theta[0]*a[6][1] + theta1[0]*a[6][1] + a[6][2];

            a1[7][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[7][0] + theta[2]*a[7][1] - theta1[2]*a[7][1] - theta[1]*a[7][2] + theta1[1]*a[7][2];

            a1[7][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[7][0] + theta1[2]*a[7][0] + a[7][1] + theta[0]*a[7][2] - theta1[0]*a[7][2];

            a1[7][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[7][0] - theta1[1]*a[7][0] - theta[0]*a[7][1] + theta1[0]*a[7][1] + a[7][2];

            a1[8][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[8][0] + theta[2]*a[8][1] - theta1[2]*a[8][1] - theta[1]*a[8][2] + theta1[1]*a[8][2];

            a1[8][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[8][0] + theta1[2]*a[8][0] + a[8][1] + theta[0]*a[8][2] - theta1[0]*a[8][2];

            a1[8][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[8][0] - theta1[1]*a[8][0] - theta[0]*a[8][1] + theta1[0]*a[8][1] + a[8][2];

            a1[9][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[9][0] + theta[2]*a[9][1] - theta1[2]*a[9][1] - theta[1]*a[9][2] + theta1[1]*a[9][2];

            a1[9][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[9][0] + theta1[2]*a[9][0] + a[9][1] + theta[0]*a[9][2] - theta1[0]*a[9][2];

            a1[9][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[9][0] - theta1[1]*a[9][0] - theta[0]*a[9][1] + theta1[0]*a[9][1] + a[9][2];

            a1[10][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[10][0] + theta[2]*a[10][1] - theta1[2]*a[10][1] - theta[1]*a[10][2] + theta1[1]*a[10][2];

            a1[10][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[10][0] + theta1[2]*a[10][0] + a[10][1] + theta[0]*a[10][2] - theta1[0]*a[10][2];

            a1[10][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[10][0] - theta1[1]*a[10][0] - theta[0]*a[10][1] + theta1[0]*a[10][1] + a[10][2];

            a1[11][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[11][0] + theta[2]*a[11][1] - theta1[2]*a[11][1] - theta[1]*a[11][2] + theta1[1]*a[11][2];

            a1[11][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[11][0] + theta1[2]*a[11][0] + a[11][1] + theta[0]*a[11][2] - theta1[0]*a[11][2];

            a1[11][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[11][0] - theta1[1]*a[11][0] - theta[0]*a[11][1] + theta1[0]*a[11][1] + a[11][2];

            a1[12][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[12][0] + theta[2]*a[12][1] - theta1[2]*a[12][1] - theta[1]*a[12][2] + theta1[1]*a[12][2];

            a1[12][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[12][0] + theta1[2]*a[12][0] + a[12][1] + theta[0]*a[12][2] - theta1[0]*a[12][2];

            a1[12][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[12][0] - theta1[1]*a[12][0] - theta[0]*a[12][1] + theta1[0]*a[12][1] + a[12][2];

            a1[13][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[13][0] + theta[2]*a[13][1] - theta1[2]*a[13][1] - theta[1]*a[13][2] + theta1[1]*a[13][2];

            a1[13][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[13][0] + theta1[2]*a[13][0] + a[13][1] + theta[0]*a[13][2] - theta1[0]*a[13][2];

            a1[13][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[13][0] - theta1[1]*a[13][0] - theta[0]*a[13][1] + theta1[0]*a[13][1] + a[13][2];

            a1[14][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[14][0] + theta[2]*a[14][1] - theta1[2]*a[14][1] - theta[1]*a[14][2] + theta1[1]*a[14][2];

            a1[14][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[14][0] + theta1[2]*a[14][0] + a[14][1] + theta[0]*a[14][2] - theta1[0]*a[14][2];

            a1[14][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[14][0] - theta1[1]*a[14][0] - theta[0]*a[14][1] + theta1[0]*a[14][1] + a[14][2];

            a1[15][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[15][0] + theta[2]*a[15][1] - theta1[2]*a[15][1] - theta[1]*a[15][2] + theta1[1]*a[15][2];

            a1[15][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[15][0] + theta1[2]*a[15][0] + a[15][1] + theta[0]*a[15][2] - theta1[0]*a[15][2];

            a1[15][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[15][0] - theta1[1]*a[15][0] - theta[0]*a[15][1] + theta1[0]*a[15][1] + a[15][2];

            a1[16][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[16][0] + theta[2]*a[16][1] - theta1[2]*a[16][1] - theta[1]*a[16][2] + theta1[1]*a[16][2];

            a1[16][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[16][0] + theta1[2]*a[16][0] + a[16][1] + theta[0]*a[16][2] - theta1[0]*a[16][2];

            a1[16][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[16][0] - theta1[1]*a[16][0] - theta[0]*a[16][1] + theta1[0]*a[16][1] + a[16][2];

            a1[17][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[17][0] + theta[2]*a[17][1] - theta1[2]*a[17][1] - theta[1]*a[17][2] + theta1[1]*a[17][2];

            a1[17][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[17][0] + theta1[2]*a[17][0] + a[17][1] + theta[0]*a[17][2] - theta1[0]*a[17][2];

            a1[17][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[17][0] - theta1[1]*a[17][0] - theta[0]*a[17][1] + theta1[0]*a[17][1] + a[17][2];

            a1[18][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[18][0] + theta[2]*a[18][1] - theta1[2]*a[18][1] - theta[1]*a[18][2] + theta1[1]*a[18][2];

            a1[18][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[18][0] + theta1[2]*a[18][0] + a[18][1] + theta[0]*a[18][2] - theta1[0]*a[18][2];

            a1[18][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[18][0] - theta1[1]*a[18][0] - theta[0]*a[18][1] + theta1[0]*a[18][1] + a[18][2];

            a1[19][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[19][0] + theta[2]*a[19][1] - theta1[2]*a[19][1] - theta[1]*a[19][2] + theta1[1]*a[19][2];

            a1[19][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[19][0] + theta1[2]*a[19][0] + a[19][1] + theta[0]*a[19][2] - theta1[0]*a[19][2];

            a1[19][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[19][0] - theta1[1]*a[19][0] - theta[0]*a[19][1] + theta1[0]*a[19][1] + a[19][2];

            a1[20][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[20][0] + theta[2]*a[20][1] - theta1[2]*a[20][1] - theta[1]*a[20][2] + theta1[1]*a[20][2];

            a1[20][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[20][0] + theta1[2]*a[20][0] + a[20][1] + theta[0]*a[20][2] - theta1[0]*a[20][2];

            a1[20][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[20][0] - theta1[1]*a[20][0] - theta[0]*a[20][1] + theta1[0]*a[20][1] + a[20][2];

            a1[21][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[21][0] + theta[2]*a[21][1] - theta1[2]*a[21][1] - theta[1]*a[21][2] + theta1[1]*a[21][2];

            a1[21][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[21][0] + theta1[2]*a[21][0] + a[21][1] + theta[0]*a[21][2] - theta1[0]*a[21][2];

            a1[21][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[21][0] - theta1[1]*a[21][0] - theta[0]*a[21][1] + theta1[0]*a[21][1] + a[21][2];

            a1[22][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[22][0] + theta[2]*a[22][1] - theta1[2]*a[22][1] - theta[1]*a[22][2] + theta1[1]*a[22][2];

            a1[22][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[22][0] + theta1[2]*a[22][0] + a[22][1] + theta[0]*a[22][2] - theta1[0]*a[22][2];

            a1[22][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[22][0] - theta1[1]*a[22][0] - theta[0]*a[22][1] + theta1[0]*a[22][1] + a[22][2];

            a1[23][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[23][0] + theta[2]*a[23][1] - theta1[2]*a[23][1] - theta[1]*a[23][2] + theta1[1]*a[23][2];

            a1[23][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[23][0] + theta1[2]*a[23][0] + a[23][1] + theta[0]*a[23][2] - theta1[0]*a[23][2];

            a1[23][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[23][0] - theta1[1]*a[23][0] - theta[0]*a[23][1] + theta1[0]*a[23][1] + a[23][2];

            a1[24][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[24][0] + theta[2]*a[24][1] - theta1[2]*a[24][1] - theta[1]*a[24][2] + theta1[1]*a[24][2];

            a1[24][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[24][0] + theta1[2]*a[24][0] + a[24][1] + theta[0]*a[24][2] - theta1[0]*a[24][2];

            a1[24][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[24][0] - theta1[1]*a[24][0] - theta[0]*a[24][1] + theta1[0]*a[24][1] + a[24][2];

            a1[25][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[25][0] + theta[2]*a[25][1] - theta1[2]*a[25][1] - theta[1]*a[25][2] + theta1[1]*a[25][2];

            a1[25][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[25][0] + theta1[2]*a[25][0] + a[25][1] + theta[0]*a[25][2] - theta1[0]*a[25][2];

            a1[25][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[25][0] - theta1[1]*a[25][0] - theta[0]*a[25][1] + theta1[0]*a[25][1] + a[25][2];

            a1[26][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[26][0] + theta[2]*a[26][1] - theta1[2]*a[26][1] - theta[1]*a[26][2] + theta1[1]*a[26][2];

            a1[26][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[26][0] + theta1[2]*a[26][0] + a[26][1] + theta[0]*a[26][2] - theta1[0]*a[26][2];

            a1[26][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[26][0] - theta1[1]*a[26][0] - theta[0]*a[26][1] + theta1[0]*a[26][1] + a[26][2];

            a1[27][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[27][0] + theta[2]*a[27][1] - theta1[2]*a[27][1] - theta[1]*a[27][2] + theta1[1]*a[27][2];

            a1[27][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[27][0] + theta1[2]*a[27][0] + a[27][1] + theta[0]*a[27][2] - theta1[0]*a[27][2];

            a1[27][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[27][0] - theta1[1]*a[27][0] - theta[0]*a[27][1] + theta1[0]*a[27][1] + a[27][2];

            a1[28][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[28][0] + theta[2]*a[28][1] - theta1[2]*a[28][1] - theta[1]*a[28][2] + theta1[1]*a[28][2];

            a1[28][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[28][0] + theta1[2]*a[28][0] + a[28][1] + theta[0]*a[28][2] - theta1[0]*a[28][2];

            a1[28][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[28][0] - theta1[1]*a[28][0] - theta[0]*a[28][1] + theta1[0]*a[28][1] + a[28][2];

            a1[29][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[29][0] + theta[2]*a[29][1] - theta1[2]*a[29][1] - theta[1]*a[29][2] + theta1[1]*a[29][2];

            a1[29][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[29][0] + theta1[2]*a[29][0] + a[29][1] + theta[0]*a[29][2] - theta1[0]*a[29][2];

            a1[29][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[29][0] - theta1[1]*a[29][0] - theta[0]*a[29][1] + theta1[0]*a[29][1] + a[29][2];

            a1[30][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[30][0] + theta[2]*a[30][1] - theta1[2]*a[30][1] - theta[1]*a[30][2] + theta1[1]*a[30][2];

            a1[30][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[30][0] + theta1[2]*a[30][0] + a[30][1] + theta[0]*a[30][2] - theta1[0]*a[30][2];

            a1[30][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[30][0] - theta1[1]*a[30][0] - theta[0]*a[30][1] + theta1[0]*a[30][1] + a[30][2];

            a1[31][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[31][0] + theta[2]*a[31][1] - theta1[2]*a[31][1] - theta[1]*a[31][2] + theta1[1]*a[31][2];

            a1[31][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[31][0] + theta1[2]*a[31][0] + a[31][1] + theta[0]*a[31][2] - theta1[0]*a[31][2];

            a1[31][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[31][0] - theta1[1]*a[31][0] - theta[0]*a[31][1] + theta1[0]*a[31][1] + a[31][2];

            a1[32][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[32][0] + theta[2]*a[32][1] - theta1[2]*a[32][1] - theta[1]*a[32][2] + theta1[1]*a[32][2];

            a1[32][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[32][0] + theta1[2]*a[32][0] + a[32][1] + theta[0]*a[32][2] - theta1[0]*a[32][2];

            a1[32][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[32][0] - theta1[1]*a[32][0] - theta[0]*a[32][1] + theta1[0]*a[32][1] + a[32][2];

            a1[33][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[33][0] + theta[2]*a[33][1] - theta1[2]*a[33][1] - theta[1]*a[33][2] + theta1[1]*a[33][2];

            a1[33][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[33][0] + theta1[2]*a[33][0] + a[33][1] + theta[0]*a[33][2] - theta1[0]*a[33][2];

            a1[33][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[33][0] - theta1[1]*a[33][0] - theta[0]*a[33][1] + theta1[0]*a[33][1] + a[33][2];

            a1[34][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[34][0] + theta[2]*a[34][1] - theta1[2]*a[34][1] - theta[1]*a[34][2] + theta1[1]*a[34][2];

            a1[34][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[34][0] + theta1[2]*a[34][0] + a[34][1] + theta[0]*a[34][2] - theta1[0]*a[34][2];

            a1[34][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[34][0] - theta1[1]*a[34][0] - theta[0]*a[34][1] + theta1[0]*a[34][1] + a[34][2];

            a1[35][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[35][0] + theta[2]*a[35][1] - theta1[2]*a[35][1] - theta[1]*a[35][2] + theta1[1]*a[35][2];

            a1[35][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[35][0] + theta1[2]*a[35][0] + a[35][1] + theta[0]*a[35][2] - theta1[0]*a[35][2];

            a1[35][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[35][0] - theta1[1]*a[35][0] - theta[0]*a[35][1] + theta1[0]*a[35][1] + a[35][2];

            a1[36][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[36][0] + theta[2]*a[36][1] - theta1[2]*a[36][1] - theta[1]*a[36][2] + theta1[1]*a[36][2];

            a1[36][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[36][0] + theta1[2]*a[36][0] + a[36][1] + theta[0]*a[36][2] - theta1[0]*a[36][2];

            a1[36][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[36][0] - theta1[1]*a[36][0] - theta[0]*a[36][1] + theta1[0]*a[36][1] + a[36][2];

            a1[37][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[37][0] + theta[2]*a[37][1] - theta1[2]*a[37][1] - theta[1]*a[37][2] + theta1[1]*a[37][2];

            a1[37][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[37][0] + theta1[2]*a[37][0] + a[37][1] + theta[0]*a[37][2] - theta1[0]*a[37][2];

            a1[37][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[37][0] - theta1[1]*a[37][0] - theta[0]*a[37][1] + theta1[0]*a[37][1] + a[37][2];

            a1[38][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[38][0] + theta[2]*a[38][1] - theta1[2]*a[38][1] - theta[1]*a[38][2] + theta1[1]*a[38][2];

            a1[38][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[38][0] + theta1[2]*a[38][0] + a[38][1] + theta[0]*a[38][2] - theta1[0]*a[38][2];

            a1[38][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[38][0] - theta1[1]*a[38][0] - theta[0]*a[38][1] + theta1[0]*a[38][1] + a[38][2];

            a1[39][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[39][0] + theta[2]*a[39][1] - theta1[2]*a[39][1] - theta[1]*a[39][2] + theta1[1]*a[39][2];

            a1[39][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[39][0] + theta1[2]*a[39][0] + a[39][1] + theta[0]*a[39][2] - theta1[0]*a[39][2];

            a1[39][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[39][0] - theta1[1]*a[39][0] - theta[0]*a[39][1] + theta1[0]*a[39][1] + a[39][2];

            a1[40][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[40][0] + theta[2]*a[40][1] - theta1[2]*a[40][1] - theta[1]*a[40][2] + theta1[1]*a[40][2];

            a1[40][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[40][0] + theta1[2]*a[40][0] + a[40][1] + theta[0]*a[40][2] - theta1[0]*a[40][2];

            a1[40][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[40][0] - theta1[1]*a[40][0] - theta[0]*a[40][1] + theta1[0]*a[40][1] + a[40][2];

            a1[41][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[41][0] + theta[2]*a[41][1] - theta1[2]*a[41][1] - theta[1]*a[41][2] + theta1[1]*a[41][2];

            a1[41][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[41][0] + theta1[2]*a[41][0] + a[41][1] + theta[0]*a[41][2] - theta1[0]*a[41][2];

            a1[41][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[41][0] - theta1[1]*a[41][0] - theta[0]*a[41][1] + theta1[0]*a[41][1] + a[41][2];

            a1[42][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[42][0] + theta[2]*a[42][1] - theta1[2]*a[42][1] - theta[1]*a[42][2] + theta1[1]*a[42][2];

            a1[42][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[42][0] + theta1[2]*a[42][0] + a[42][1] + theta[0]*a[42][2] - theta1[0]*a[42][2];

            a1[42][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[42][0] - theta1[1]*a[42][0] - theta[0]*a[42][1] + theta1[0]*a[42][1] + a[42][2];

            a1[43][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[43][0] + theta[2]*a[43][1] - theta1[2]*a[43][1] - theta[1]*a[43][2] + theta1[1]*a[43][2];

            a1[43][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[43][0] + theta1[2]*a[43][0] + a[43][1] + theta[0]*a[43][2] - theta1[0]*a[43][2];

            a1[43][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[43][0] - theta1[1]*a[43][0] - theta[0]*a[43][1] + theta1[0]*a[43][1] + a[43][2];

            a1[44][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[44][0] + theta[2]*a[44][1] - theta1[2]*a[44][1] - theta[1]*a[44][2] + theta1[1]*a[44][2];

            a1[44][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[44][0] + theta1[2]*a[44][0] + a[44][1] + theta[0]*a[44][2] - theta1[0]*a[44][2];

            a1[44][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[44][0] - theta1[1]*a[44][0] - theta[0]*a[44][1] + theta1[0]*a[44][1] + a[44][2];

            a1[45][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[45][0] + theta[2]*a[45][1] - theta1[2]*a[45][1] - theta[1]*a[45][2] + theta1[1]*a[45][2];

            a1[45][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[45][0] + theta1[2]*a[45][0] + a[45][1] + theta[0]*a[45][2] - theta1[0]*a[45][2];

            a1[45][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[45][0] - theta1[1]*a[45][0] - theta[0]*a[45][1] + theta1[0]*a[45][1] + a[45][2];

            a1[46][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[46][0] + theta[2]*a[46][1] - theta1[2]*a[46][1] - theta[1]*a[46][2] + theta1[1]*a[46][2];

            a1[46][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[46][0] + theta1[2]*a[46][0] + a[46][1] + theta[0]*a[46][2] - theta1[0]*a[46][2];

            a1[46][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[46][0] - theta1[1]*a[46][0] - theta[0]*a[46][1] + theta1[0]*a[46][1] + a[46][2];

            a1[47][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[47][0] + theta[2]*a[47][1] - theta1[2]*a[47][1] - theta[1]*a[47][2] + theta1[1]*a[47][2];

            a1[47][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[47][0] + theta1[2]*a[47][0] + a[47][1] + theta[0]*a[47][2] - theta1[0]*a[47][2];

            a1[47][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[47][0] - theta1[1]*a[47][0] - theta[0]*a[47][1] + theta1[0]*a[47][1] + a[47][2];

            a1[48][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[48][0] + theta[2]*a[48][1] - theta1[2]*a[48][1] - theta[1]*a[48][2] + theta1[1]*a[48][2];

            a1[48][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[48][0] + theta1[2]*a[48][0] + a[48][1] + theta[0]*a[48][2] - theta1[0]*a[48][2];

            a1[48][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[48][0] - theta1[1]*a[48][0] - theta[0]*a[48][1] + theta1[0]*a[48][1] + a[48][2];

            a1[49][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[49][0] + theta[2]*a[49][1] - theta1[2]*a[49][1] - theta[1]*a[49][2] + theta1[1]*a[49][2];

            a1[49][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[49][0] + theta1[2]*a[49][0] + a[49][1] + theta[0]*a[49][2] - theta1[0]*a[49][2];

            a1[49][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[49][0] - theta1[1]*a[49][0] - theta[0]*a[49][1] + theta1[0]*a[49][1] + a[49][2];

            a1[50][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[50][0] + theta[2]*a[50][1] - theta1[2]*a[50][1] - theta[1]*a[50][2] + theta1[1]*a[50][2];

            a1[50][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[50][0] + theta1[2]*a[50][0] + a[50][1] + theta[0]*a[50][2] - theta1[0]*a[50][2];

            a1[50][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[50][0] - theta1[1]*a[50][0] - theta[0]*a[50][1] + theta1[0]*a[50][1] + a[50][2];

            a1[51][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[51][0] + theta[2]*a[51][1] - theta1[2]*a[51][1] - theta[1]*a[51][2] + theta1[1]*a[51][2];

            a1[51][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[51][0] + theta1[2]*a[51][0] + a[51][1] + theta[0]*a[51][2] - theta1[0]*a[51][2];

            a1[51][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[51][0] - theta1[1]*a[51][0] - theta[0]*a[51][1] + theta1[0]*a[51][1] + a[51][2];

            a1[52][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[52][0] + theta[2]*a[52][1] - theta1[2]*a[52][1] - theta[1]*a[52][2] + theta1[1]*a[52][2];

            a1[52][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[52][0] + theta1[2]*a[52][0] + a[52][1] + theta[0]*a[52][2] - theta1[0]*a[52][2];

            a1[52][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[52][0] - theta1[1]*a[52][0] - theta[0]*a[52][1] + theta1[0]*a[52][1] + a[52][2];

            a1[53][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[53][0] + theta[2]*a[53][1] - theta1[2]*a[53][1] - theta[1]*a[53][2] + theta1[1]*a[53][2];

            a1[53][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[53][0] + theta1[2]*a[53][0] + a[53][1] + theta[0]*a[53][2] - theta1[0]*a[53][2];

            a1[53][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[53][0] - theta1[1]*a[53][0] - theta[0]*a[53][1] + theta1[0]*a[53][1] + a[53][2];

            a1[54][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[54][0] + theta[2]*a[54][1] - theta1[2]*a[54][1] - theta[1]*a[54][2] + theta1[1]*a[54][2];

            a1[54][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[54][0] + theta1[2]*a[54][0] + a[54][1] + theta[0]*a[54][2] - theta1[0]*a[54][2];

            a1[54][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[54][0] - theta1[1]*a[54][0] - theta[0]*a[54][1] + theta1[0]*a[54][1] + a[54][2];

            a1[55][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[55][0] + theta[2]*a[55][1] - theta1[2]*a[55][1] - theta[1]*a[55][2] + theta1[1]*a[55][2];

            a1[55][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[55][0] + theta1[2]*a[55][0] + a[55][1] + theta[0]*a[55][2] - theta1[0]*a[55][2];

            a1[55][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[55][0] - theta1[1]*a[55][0] - theta[0]*a[55][1] + theta1[0]*a[55][1] + a[55][2];

            a1[56][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[56][0] + theta[2]*a[56][1] - theta1[2]*a[56][1] - theta[1]*a[56][2] + theta1[1]*a[56][2];

            a1[56][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[56][0] + theta1[2]*a[56][0] + a[56][1] + theta[0]*a[56][2] - theta1[0]*a[56][2];

            a1[56][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[56][0] - theta1[1]*a[56][0] - theta[0]*a[56][1] + theta1[0]*a[56][1] + a[56][2];

            a1[57][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[57][0] + theta[2]*a[57][1] - theta1[2]*a[57][1] - theta[1]*a[57][2] + theta1[1]*a[57][2];

            a1[57][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[57][0] + theta1[2]*a[57][0] + a[57][1] + theta[0]*a[57][2] - theta1[0]*a[57][2];

            a1[57][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[57][0] - theta1[1]*a[57][0] - theta[0]*a[57][1] + theta1[0]*a[57][1] + a[57][2];

            a1[58][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[58][0] + theta[2]*a[58][1] - theta1[2]*a[58][1] - theta[1]*a[58][2] + theta1[1]*a[58][2];

            a1[58][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[58][0] + theta1[2]*a[58][0] + a[58][1] + theta[0]*a[58][2] - theta1[0]*a[58][2];

            a1[58][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[58][0] - theta1[1]*a[58][0] - theta[0]*a[58][1] + theta1[0]*a[58][1] + a[58][2];

            a1[59][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[59][0] + theta[2]*a[59][1] - theta1[2]*a[59][1] - theta[1]*a[59][2] + theta1[1]*a[59][2];

            a1[59][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[59][0] + theta1[2]*a[59][0] + a[59][1] + theta[0]*a[59][2] - theta1[0]*a[59][2];

            a1[59][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[59][0] - theta1[1]*a[59][0] - theta[0]*a[59][1] + theta1[0]*a[59][1] + a[59][2];

            a1[60][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[60][0] + theta[2]*a[60][1] - theta1[2]*a[60][1] - theta[1]*a[60][2] + theta1[1]*a[60][2];

            a1[60][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[60][0] + theta1[2]*a[60][0] + a[60][1] + theta[0]*a[60][2] - theta1[0]*a[60][2];

            a1[60][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[60][0] - theta1[1]*a[60][0] - theta[0]*a[60][1] + theta1[0]*a[60][1] + a[60][2];

            a1[61][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[61][0] + theta[2]*a[61][1] - theta1[2]*a[61][1] - theta[1]*a[61][2] + theta1[1]*a[61][2];

            a1[61][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[61][0] + theta1[2]*a[61][0] + a[61][1] + theta[0]*a[61][2] - theta1[0]*a[61][2];

            a1[61][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[61][0] - theta1[1]*a[61][0] - theta[0]*a[61][1] + theta1[0]*a[61][1] + a[61][2];

            a1[62][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[62][0] + theta[2]*a[62][1] - theta1[2]*a[62][1] - theta[1]*a[62][2] + theta1[1]*a[62][2];

            a1[62][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[62][0] + theta1[2]*a[62][0] + a[62][1] + theta[0]*a[62][2] - theta1[0]*a[62][2];

            a1[62][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[62][0] - theta1[1]*a[62][0] - theta[0]*a[62][1] + theta1[0]*a[62][1] + a[62][2];

            a1[63][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[63][0] + theta[2]*a[63][1] - theta1[2]*a[63][1] - theta[1]*a[63][2] + theta1[1]*a[63][2];

            a1[63][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[63][0] + theta1[2]*a[63][0] + a[63][1] + theta[0]*a[63][2] - theta1[0]*a[63][2];

            a1[63][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[63][0] - theta1[1]*a[63][0] - theta[0]*a[63][1] + theta1[0]*a[63][1] + a[63][2];

            a1[64][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[64][0] + theta[2]*a[64][1] - theta1[2]*a[64][1] - theta[1]*a[64][2] + theta1[1]*a[64][2];

            a1[64][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[64][0] + theta1[2]*a[64][0] + a[64][1] + theta[0]*a[64][2] - theta1[0]*a[64][2];

            a1[64][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[64][0] - theta1[1]*a[64][0] - theta[0]*a[64][1] + theta1[0]*a[64][1] + a[64][2];

            a1[65][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[65][0] + theta[2]*a[65][1] - theta1[2]*a[65][1] - theta[1]*a[65][2] + theta1[1]*a[65][2];

            a1[65][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[65][0] + theta1[2]*a[65][0] + a[65][1] + theta[0]*a[65][2] - theta1[0]*a[65][2];

            a1[65][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[65][0] - theta1[1]*a[65][0] - theta[0]*a[65][1] + theta1[0]*a[65][1] + a[65][2];

            a1[66][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[66][0] + theta[2]*a[66][1] - theta1[2]*a[66][1] - theta[1]*a[66][2] + theta1[1]*a[66][2];

            a1[66][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[66][0] + theta1[2]*a[66][0] + a[66][1] + theta[0]*a[66][2] - theta1[0]*a[66][2];

            a1[66][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[66][0] - theta1[1]*a[66][0] - theta[0]*a[66][1] + theta1[0]*a[66][1] + a[66][2];

            a1[67][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[67][0] + theta[2]*a[67][1] - theta1[2]*a[67][1] - theta[1]*a[67][2] + theta1[1]*a[67][2];

            a1[67][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[67][0] + theta1[2]*a[67][0] + a[67][1] + theta[0]*a[67][2] - theta1[0]*a[67][2];

            a1[67][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[67][0] - theta1[1]*a[67][0] - theta[0]*a[67][1] + theta1[0]*a[67][1] + a[67][2];

            a1[68][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[68][0] + theta[2]*a[68][1] - theta1[2]*a[68][1] - theta[1]*a[68][2] + theta1[1]*a[68][2];

            a1[68][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[68][0] + theta1[2]*a[68][0] + a[68][1] + theta[0]*a[68][2] - theta1[0]*a[68][2];

            a1[68][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[68][0] - theta1[1]*a[68][0] - theta[0]*a[68][1] + theta1[0]*a[68][1] + a[68][2];

            a1[69][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[69][0] + theta[2]*a[69][1] - theta1[2]*a[69][1] - theta[1]*a[69][2] + theta1[1]*a[69][2];

            a1[69][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[69][0] + theta1[2]*a[69][0] + a[69][1] + theta[0]*a[69][2] - theta1[0]*a[69][2];

            a1[69][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[69][0] - theta1[1]*a[69][0] - theta[0]*a[69][1] + theta1[0]*a[69][1] + a[69][2];

            a1[70][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[70][0] + theta[2]*a[70][1] - theta1[2]*a[70][1] - theta[1]*a[70][2] + theta1[1]*a[70][2];

            a1[70][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[70][0] + theta1[2]*a[70][0] + a[70][1] + theta[0]*a[70][2] - theta1[0]*a[70][2];

            a1[70][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[70][0] - theta1[1]*a[70][0] - theta[0]*a[70][1] + theta1[0]*a[70][1] + a[70][2];

            a1[71][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[71][0] + theta[2]*a[71][1] - theta1[2]*a[71][1] - theta[1]*a[71][2] + theta1[1]*a[71][2];

            a1[71][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[71][0] + theta1[2]*a[71][0] + a[71][1] + theta[0]*a[71][2] - theta1[0]*a[71][2];

            a1[71][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[71][0] - theta1[1]*a[71][0] - theta[0]*a[71][1] + theta1[0]*a[71][1] + a[71][2];

            a1[72][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[72][0] + theta[2]*a[72][1] - theta1[2]*a[72][1] - theta[1]*a[72][2] + theta1[1]*a[72][2];

            a1[72][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[72][0] + theta1[2]*a[72][0] + a[72][1] + theta[0]*a[72][2] - theta1[0]*a[72][2];

            a1[72][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[72][0] - theta1[1]*a[72][0] - theta[0]*a[72][1] + theta1[0]*a[72][1] + a[72][2];

            a1[73][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[73][0] + theta[2]*a[73][1] - theta1[2]*a[73][1] - theta[1]*a[73][2] + theta1[1]*a[73][2];

            a1[73][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[73][0] + theta1[2]*a[73][0] + a[73][1] + theta[0]*a[73][2] - theta1[0]*a[73][2];

            a1[73][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[73][0] - theta1[1]*a[73][0] - theta[0]*a[73][1] + theta1[0]*a[73][1] + a[73][2];

            a1[74][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[74][0] + theta[2]*a[74][1] - theta1[2]*a[74][1] - theta[1]*a[74][2] + theta1[1]*a[74][2];

            a1[74][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[74][0] + theta1[2]*a[74][0] + a[74][1] + theta[0]*a[74][2] - theta1[0]*a[74][2];

            a1[74][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[74][0] - theta1[1]*a[74][0] - theta[0]*a[74][1] + theta1[0]*a[74][1] + a[74][2];

            a1[75][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[75][0] + theta[2]*a[75][1] - theta1[2]*a[75][1] - theta[1]*a[75][2] + theta1[1]*a[75][2];

            a1[75][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[75][0] + theta1[2]*a[75][0] + a[75][1] + theta[0]*a[75][2] - theta1[0]*a[75][2];

            a1[75][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[75][0] - theta1[1]*a[75][0] - theta[0]*a[75][1] + theta1[0]*a[75][1] + a[75][2];

            a1[76][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[76][0] + theta[2]*a[76][1] - theta1[2]*a[76][1] - theta[1]*a[76][2] + theta1[1]*a[76][2];

            a1[76][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[76][0] + theta1[2]*a[76][0] + a[76][1] + theta[0]*a[76][2] - theta1[0]*a[76][2];

            a1[76][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[76][0] - theta1[1]*a[76][0] - theta[0]*a[76][1] + theta1[0]*a[76][1] + a[76][2];

            a1[77][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[77][0] + theta[2]*a[77][1] - theta1[2]*a[77][1] - theta[1]*a[77][2] + theta1[1]*a[77][2];

            a1[77][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[77][0] + theta1[2]*a[77][0] + a[77][1] + theta[0]*a[77][2] - theta1[0]*a[77][2];

            a1[77][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[77][0] - theta1[1]*a[77][0] - theta[0]*a[77][1] + theta1[0]*a[77][1] + a[77][2];

            a1[78][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[78][0] + theta[2]*a[78][1] - theta1[2]*a[78][1] - theta[1]*a[78][2] + theta1[1]*a[78][2];

            a1[78][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[78][0] + theta1[2]*a[78][0] + a[78][1] + theta[0]*a[78][2] - theta1[0]*a[78][2];

            a1[78][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[78][0] - theta1[1]*a[78][0] - theta[0]*a[78][1] + theta1[0]*a[78][1] + a[78][2];

            a1[79][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[79][0] + theta[2]*a[79][1] - theta1[2]*a[79][1] - theta[1]*a[79][2] + theta1[1]*a[79][2];

            a1[79][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[79][0] + theta1[2]*a[79][0] + a[79][1] + theta[0]*a[79][2] - theta1[0]*a[79][2];

            a1[79][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[79][0] - theta1[1]*a[79][0] - theta[0]*a[79][1] + theta1[0]*a[79][1] + a[79][2];

            a1[80][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[80][0] + theta[2]*a[80][1] - theta1[2]*a[80][1] - theta[1]*a[80][2] + theta1[1]*a[80][2];

            a1[80][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[80][0] + theta1[2]*a[80][0] + a[80][1] + theta[0]*a[80][2] - theta1[0]*a[80][2];

            a1[80][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[80][0] - theta1[1]*a[80][0] - theta[0]*a[80][1] + theta1[0]*a[80][1] + a[80][2];

            a1[81][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[81][0] + theta[2]*a[81][1] - theta1[2]*a[81][1] - theta[1]*a[81][2] + theta1[1]*a[81][2];

            a1[81][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[81][0] + theta1[2]*a[81][0] + a[81][1] + theta[0]*a[81][2] - theta1[0]*a[81][2];

            a1[81][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[81][0] - theta1[1]*a[81][0] - theta[0]*a[81][1] + theta1[0]*a[81][1] + a[81][2];

            a1[82][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[82][0] + theta[2]*a[82][1] - theta1[2]*a[82][1] - theta[1]*a[82][2] + theta1[1]*a[82][2];

            a1[82][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[82][0] + theta1[2]*a[82][0] + a[82][1] + theta[0]*a[82][2] - theta1[0]*a[82][2];

            a1[82][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[82][0] - theta1[1]*a[82][0] - theta[0]*a[82][1] + theta1[0]*a[82][1] + a[82][2];

            a1[83][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[83][0] + theta[2]*a[83][1] - theta1[2]*a[83][1] - theta[1]*a[83][2] + theta1[1]*a[83][2];

            a1[83][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[83][0] + theta1[2]*a[83][0] + a[83][1] + theta[0]*a[83][2] - theta1[0]*a[83][2];

            a1[83][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[83][0] - theta1[1]*a[83][0] - theta[0]*a[83][1] + theta1[0]*a[83][1] + a[83][2];

            a1[84][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[84][0] + theta[2]*a[84][1] - theta1[2]*a[84][1] - theta[1]*a[84][2] + theta1[1]*a[84][2];

            a1[84][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[84][0] + theta1[2]*a[84][0] + a[84][1] + theta[0]*a[84][2] - theta1[0]*a[84][2];

            a1[84][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[84][0] - theta1[1]*a[84][0] - theta[0]*a[84][1] + theta1[0]*a[84][1] + a[84][2];

            a1[85][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[85][0] + theta[2]*a[85][1] - theta1[2]*a[85][1] - theta[1]*a[85][2] + theta1[1]*a[85][2];

            a1[85][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[85][0] + theta1[2]*a[85][0] + a[85][1] + theta[0]*a[85][2] - theta1[0]*a[85][2];

            a1[85][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[85][0] - theta1[1]*a[85][0] - theta[0]*a[85][1] + theta1[0]*a[85][1] + a[85][2];

            a1[86][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[86][0] + theta[2]*a[86][1] - theta1[2]*a[86][1] - theta[1]*a[86][2] + theta1[1]*a[86][2];

            a1[86][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[86][0] + theta1[2]*a[86][0] + a[86][1] + theta[0]*a[86][2] - theta1[0]*a[86][2];

            a1[86][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[86][0] - theta1[1]*a[86][0] - theta[0]*a[86][1] + theta1[0]*a[86][1] + a[86][2];

            a1[87][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[87][0] + theta[2]*a[87][1] - theta1[2]*a[87][1] - theta[1]*a[87][2] + theta1[1]*a[87][2];

            a1[87][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[87][0] + theta1[2]*a[87][0] + a[87][1] + theta[0]*a[87][2] - theta1[0]*a[87][2];

            a1[87][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[87][0] - theta1[1]*a[87][0] - theta[0]*a[87][1] + theta1[0]*a[87][1] + a[87][2];

            a1[88][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[88][0] + theta[2]*a[88][1] - theta1[2]*a[88][1] - theta[1]*a[88][2] + theta1[1]*a[88][2];

            a1[88][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[88][0] + theta1[2]*a[88][0] + a[88][1] + theta[0]*a[88][2] - theta1[0]*a[88][2];

            a1[88][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[88][0] - theta1[1]*a[88][0] - theta[0]*a[88][1] + theta1[0]*a[88][1] + a[88][2];

            a1[89][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[89][0] + theta[2]*a[89][1] - theta1[2]*a[89][1] - theta[1]*a[89][2] + theta1[1]*a[89][2];

            a1[89][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[89][0] + theta1[2]*a[89][0] + a[89][1] + theta[0]*a[89][2] - theta1[0]*a[89][2];

            a1[89][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[89][0] - theta1[1]*a[89][0] - theta[0]*a[89][1] + theta1[0]*a[89][1] + a[89][2];

            a1[90][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[90][0] + theta[2]*a[90][1] - theta1[2]*a[90][1] - theta[1]*a[90][2] + theta1[1]*a[90][2];

            a1[90][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[90][0] + theta1[2]*a[90][0] + a[90][1] + theta[0]*a[90][2] - theta1[0]*a[90][2];

            a1[90][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[90][0] - theta1[1]*a[90][0] - theta[0]*a[90][1] + theta1[0]*a[90][1] + a[90][2];

            a1[91][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[91][0] + theta[2]*a[91][1] - theta1[2]*a[91][1] - theta[1]*a[91][2] + theta1[1]*a[91][2];

            a1[91][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[91][0] + theta1[2]*a[91][0] + a[91][1] + theta[0]*a[91][2] - theta1[0]*a[91][2];

            a1[91][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[91][0] - theta1[1]*a[91][0] - theta[0]*a[91][1] + theta1[0]*a[91][1] + a[91][2];

            a1[92][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[92][0] + theta[2]*a[92][1] - theta1[2]*a[92][1] - theta[1]*a[92][2] + theta1[1]*a[92][2];

            a1[92][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[92][0] + theta1[2]*a[92][0] + a[92][1] + theta[0]*a[92][2] - theta1[0]*a[92][2];

            a1[92][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[92][0] - theta1[1]*a[92][0] - theta[0]*a[92][1] + theta1[0]*a[92][1] + a[92][2];

            a1[93][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[93][0] + theta[2]*a[93][1] - theta1[2]*a[93][1] - theta[1]*a[93][2] + theta1[1]*a[93][2];

            a1[93][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[93][0] + theta1[2]*a[93][0] + a[93][1] + theta[0]*a[93][2] - theta1[0]*a[93][2];

            a1[93][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[93][0] - theta1[1]*a[93][0] - theta[0]*a[93][1] + theta1[0]*a[93][1] + a[93][2];

            a1[94][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[94][0] + theta[2]*a[94][1] - theta1[2]*a[94][1] - theta[1]*a[94][2] + theta1[1]*a[94][2];

            a1[94][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[94][0] + theta1[2]*a[94][0] + a[94][1] + theta[0]*a[94][2] - theta1[0]*a[94][2];

            a1[94][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[94][0] - theta1[1]*a[94][0] - theta[0]*a[94][1] + theta1[0]*a[94][1] + a[94][2];

            a1[95][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[95][0] + theta[2]*a[95][1] - theta1[2]*a[95][1] - theta[1]*a[95][2] + theta1[1]*a[95][2];

            a1[95][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[95][0] + theta1[2]*a[95][0] + a[95][1] + theta[0]*a[95][2] - theta1[0]*a[95][2];

            a1[95][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[95][0] - theta1[1]*a[95][0] - theta[0]*a[95][1] + theta1[0]*a[95][1] + a[95][2];

            a1[96][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[96][0] + theta[2]*a[96][1] - theta1[2]*a[96][1] - theta[1]*a[96][2] + theta1[1]*a[96][2];

            a1[96][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[96][0] + theta1[2]*a[96][0] + a[96][1] + theta[0]*a[96][2] - theta1[0]*a[96][2];

            a1[96][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[96][0] - theta1[1]*a[96][0] - theta[0]*a[96][1] + theta1[0]*a[96][1] + a[96][2];

            a1[97][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[97][0] + theta[2]*a[97][1] - theta1[2]*a[97][1] - theta[1]*a[97][2] + theta1[1]*a[97][2];

            a1[97][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[97][0] + theta1[2]*a[97][0] + a[97][1] + theta[0]*a[97][2] - theta1[0]*a[97][2];

            a1[97][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[97][0] - theta1[1]*a[97][0] - theta[0]*a[97][1] + theta1[0]*a[97][1] + a[97][2];

            a1[98][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[98][0] + theta[2]*a[98][1] - theta1[2]*a[98][1] - theta[1]*a[98][2] + theta1[1]*a[98][2];

            a1[98][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[98][0] + theta1[2]*a[98][0] + a[98][1] + theta[0]*a[98][2] - theta1[0]*a[98][2];

            a1[98][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[98][0] - theta1[1]*a[98][0] - theta[0]*a[98][1] + theta1[0]*a[98][1] + a[98][2];

            a1[99][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[99][0] + theta[2]*a[99][1] - theta1[2]*a[99][1] - theta[1]*a[99][2] + theta1[1]*a[99][2];

            a1[99][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[99][0] + theta1[2]*a[99][0] + a[99][1] + theta[0]*a[99][2] - theta1[0]*a[99][2];

            a1[99][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[99][0] - theta1[1]*a[99][0] - theta[0]*a[99][1] + theta1[0]*a[99][1] + a[99][2];

            a1[100][0] = -c[0] + c1[0] + c[2]*theta[1] - c[1]*theta[2] - c[2]*theta1[1] + c[1]*theta1[2] + a[100][0] + theta[2]*a[100][1] - theta1[2]*a[100][1] - theta[1]*a[100][2] + theta1[1]*a[100][2];

            a1[100][1] = -c[1] + c1[1] - c[2]*theta[0] + c[0]*theta[2] + c[2]*theta1[0] - c[0]*theta1[2] - theta[2]*a[100][0] + theta1[2]*a[100][0] + a[100][1] + theta[0]*a[100][2] - theta1[0]*a[100][2];

            a1[100][2] = -c[2] + c1[2] + c[1]*theta[0] - c[0]*theta[1] - c[1]*theta1[0] + c[0]*theta1[1] + theta[1]*a[100][0] - theta1[1]*a[100][0] - theta[0]*a[100][1] + theta1[0]*a[100][1] + a[100][2];

            break;

        default:
            printf("Bad value for total_motors\n");
            exit(0);
    }
}
