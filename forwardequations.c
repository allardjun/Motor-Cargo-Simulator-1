//prototypes
void compute_next_locations();

void compute_next_locations(){
    switch(total_pulling_motors){
        case 0:
            a[0][0] = a1[0][0];

            a[0][1] = a1[0][1];

            a[0][2] = a1[0][2];

            c1[0] = (xiCargoTranslation*c[0] + dt*(Fsteric[0] + Ftrap[0]))/xiCargoTranslation;

            c1[1] = (xiCargoTranslation*c[1] + dt*(Fsteric[1] + Ftrap[1]))/xiCargoTranslation;

            c1[2] = (xiCargoTranslation*c[2] + dt*(Fsteric[2] + Ftrap[2]))/xiCargoTranslation;

            omega[0] = 0;

            omega[1] = 0;

            omega[2] = 0;

        case 1:
            a1[0][0] = -((xiAnchor[0]*(c[1] - a[0][1])*(c[1]*a[0][0] - c[0]*a[0][1]))/xiCargoRotation) - (xiAnchor[0]*(-c[2] + a[0][2])*(-(c[2]*a[0][0]) + c[0]*a[0][2]))/xiCargoRotation + ((xiCargoRotation + xiAnchor[0]*(pow(c[1],2) + pow(c[2],2) - 2*c[1]*a[0][1] + pow(a[0][1],2) - 2*c[2]*a[0][2] + pow(a[0][2],2)))*(xiAnchor[0]*a[0][0] + dt*FmTangential[0][0]))/(xiCargoRotation*xiAnchor[0]) - ((c[0] - a[0][0])*(c[1] - a[0][1])*(xiAnchor[0]*a[0][1] + dt*FmTangential[0][1]))/xiCargoRotation - ((c[0] - a[0][0])*(c[2] - a[0][2])*(xiAnchor[0]*a[0][2] + dt*FmTangential[0][2]))/xiCargoRotation;

            a1[0][1] = -((xiAnchor[0]*(-c[0] + a[0][0])*(c[1]*a[0][0] - c[0]*a[0][1]))/xiCargoRotation) - (xiAnchor[0]*(c[2] - a[0][2])*(c[2]*a[0][1] - c[1]*a[0][2]))/xiCargoRotation - ((c[0] - a[0][0])*(c[1] - a[0][1])*(xiAnchor[0]*a[0][0] + dt*FmTangential[0][0]))/xiCargoRotation + ((xiCargoRotation + xiAnchor[0]*(pow(c[0],2) + pow(c[2],2) - 2*c[0]*a[0][0] + pow(a[0][0],2) - 2*c[2]*a[0][2] + pow(a[0][2],2)))*(xiAnchor[0]*a[0][1] + dt*FmTangential[0][1]))/(xiCargoRotation*xiAnchor[0]) - ((c[1] - a[0][1])*(c[2] - a[0][2])*(xiAnchor[0]*a[0][2] + dt*FmTangential[0][2]))/xiCargoRotation;

            a1[0][2] = -((xiAnchor[0]*(c[0] - a[0][0])*(-(c[2]*a[0][0]) + c[0]*a[0][2]))/xiCargoRotation) - (xiAnchor[0]*(-c[1] + a[0][1])*(c[2]*a[0][1] - c[1]*a[0][2]))/xiCargoRotation - ((c[0] - a[0][0])*(c[2] - a[0][2])*(xiAnchor[0]*a[0][0] + dt*FmTangential[0][0]))/xiCargoRotation - ((c[1] - a[0][1])*(c[2] - a[0][2])*(xiAnchor[0]*a[0][1] + dt*FmTangential[0][1]))/xiCargoRotation + ((xiCargoRotation + xiAnchor[0]*(pow(c[0],2) + pow(c[1],2) - 2*c[0]*a[0][0] + pow(a[0][0],2) - 2*c[1]*a[0][1] + pow(a[0][1],2)))*(xiAnchor[0]*a[0][2] + dt*FmTangential[0][2]))/(xiCargoRotation*xiAnchor[0]);

            c1[0] = -((-(xiCargoTranslation*c[0]) + xiAnchor[0]*a[0][0] - dt*(Fsteric[0] + Ftrap[0] + FmRadial[0][0]))/xiCargoTranslation) + (xiAnchor[0]*a[0][0] + dt*FmTangential[0][0])/xiCargoTranslation;

            c1[1] = -((-(xiCargoTranslation*c[1]) + xiAnchor[0]*a[0][1] - dt*(Fsteric[1] + Ftrap[1] + FmRadial[0][1]))/xiCargoTranslation) + (xiAnchor[0]*a[0][1] + dt*FmTangential[0][1])/xiCargoTranslation;

            c1[2] = -((-(xiCargoTranslation*c[2]) + xiAnchor[0]*a[0][2] - dt*(Fsteric[2] + Ftrap[2] + FmRadial[0][2]))/xiCargoTranslation) + (xiAnchor[0]*a[0][2] + dt*FmTangential[0][2])/xiCargoTranslation;

            omega[0] = -((xiAnchor[0]*(c[2]*a[0][1] - c[1]*a[0][2]))/(dt*xiCargoRotation)) + ((c[2] - a[0][2])*(xiAnchor[0]*a[0][1] + dt*FmTangential[0][1]))/(dt*xiCargoRotation) + ((-c[1] + a[0][1])*(xiAnchor[0]*a[0][2] + dt*FmTangential[0][2]))/(dt*xiCargoRotation);

            omega[1] = -((xiAnchor[0]*(-(c[2]*a[0][0]) + c[0]*a[0][2]))/(dt*xiCargoRotation)) + ((-c[2] + a[0][2])*(xiAnchor[0]*a[0][0] + dt*FmTangential[0][0]))/(dt*xiCargoRotation) + ((c[0] - a[0][0])*(xiAnchor[0]*a[0][2] + dt*FmTangential[0][2]))/(dt*xiCargoRotation);

            omega[2] = -((xiAnchor[0]*(c[1]*a[0][0] - c[0]*a[0][1]))/(dt*xiCargoRotation)) + ((c[1] - a[0][1])*(xiAnchor[0]*a[0][0] + dt*FmTangential[0][0]))/(dt*xiCargoRotation) + ((-c[0] + a[0][0])*(xiAnchor[0]*a[0][1] + dt*FmTangential[0][1]))/(dt*xiCargoRotation);

            break;

        case 2:
            a1[0][0] = -(((c[1] - a[0][1])*(c[1]*(xiAnchor[0]*a[0][0] + xiAnchor[1]*a[1][0]) - c[0]*(xiAnchor[0]*a[0][1] + xiAnchor[1]*a[1][1])))/xiCargoRotation) - ((-c[2] + a[0][2])*(-(c[2]*(xiAnchor[0]*a[0][0] + xiAnchor[1]*a[1][0])) + c[0]*(xiAnchor[0]*a[0][2] + xiAnchor[1]*a[1][2])))/xiCargoRotation + ((xiCargoRotation + xiAnchor[0]*(pow(c[1],2) + pow(c[2],2) - 2*c[1]*a[0][1] + pow(a[0][1],2) - 2*c[2]*a[0][2] + pow(a[0][2],2)))*(xiAnchor[0]*a[0][0] + dt*FmTangential[0][0]))/(xiCargoRotation*xiAnchor[0]) - ((c[0] - a[0][0])*(c[1] - a[0][1])*(xiAnchor[0]*a[0][1] + dt*FmTangential[0][1]))/xiCargoRotation - ((c[0] - a[0][0])*(c[2] - a[0][2])*(xiAnchor[0]*a[0][2] + dt*FmTangential[0][2]))/xiCargoRotation + ((pow(c[1],2) + pow(c[2],2) + a[0][1]*a[1][1] - c[1]*(a[0][1] + a[1][1]) + a[0][2]*a[1][2] - c[2]*(a[0][2] + a[1][2]))*(xiAnchor[1]*a[1][0] + dt*FmTangential[1][0]))/xiCargoRotation - ((c[1] - a[0][1])*(c[0] - a[1][0])*(xiAnchor[1]*a[1][1] + dt*FmTangential[1][1]))/xiCargoRotation - ((c[2] - a[0][2])*(c[0] - a[1][0])*(xiAnchor[1]*a[1][2] + dt*FmTangential[1][2]))/xiCargoRotation;

            a1[0][1] = -(((-c[0] + a[0][0])*(c[1]*(xiAnchor[0]*a[0][0] + xiAnchor[1]*a[1][0]) - c[0]*(xiAnchor[0]*a[0][1] + xiAnchor[1]*a[1][1])))/xiCargoRotation) - ((c[2] - a[0][2])*(c[2]*(xiAnchor[0]*a[0][1] + xiAnchor[1]*a[1][1]) - c[1]*(xiAnchor[0]*a[0][2] + xiAnchor[1]*a[1][2])))/xiCargoRotation - ((c[0] - a[0][0])*(c[1] - a[0][1])*(xiAnchor[0]*a[0][0] + dt*FmTangential[0][0]))/xiCargoRotation + ((xiCargoRotation + xiAnchor[0]*(pow(c[0],2) + pow(c[2],2) - 2*c[0]*a[0][0] + pow(a[0][0],2) - 2*c[2]*a[0][2] + pow(a[0][2],2)))*(xiAnchor[0]*a[0][1] + dt*FmTangential[0][1]))/(xiCargoRotation*xiAnchor[0]) - ((c[1] - a[0][1])*(c[2] - a[0][2])*(xiAnchor[0]*a[0][2] + dt*FmTangential[0][2]))/xiCargoRotation - ((c[0] - a[0][0])*(c[1] - a[1][1])*(xiAnchor[1]*a[1][0] + dt*FmTangential[1][0]))/xiCargoRotation + ((pow(c[0],2) + pow(c[2],2) + a[0][0]*a[1][0] - c[0]*(a[0][0] + a[1][0]) + a[0][2]*a[1][2] - c[2]*(a[0][2] + a[1][2]))*(xiAnchor[1]*a[1][1] + dt*FmTangential[1][1]))/xiCargoRotation - ((c[2] - a[0][2])*(c[1] - a[1][1])*(xiAnchor[1]*a[1][2] + dt*FmTangential[1][2]))/xiCargoRotation;

            a1[0][2] = -(((c[0] - a[0][0])*(-(c[2]*(xiAnchor[0]*a[0][0] + xiAnchor[1]*a[1][0])) + c[0]*(xiAnchor[0]*a[0][2] + xiAnchor[1]*a[1][2])))/xiCargoRotation) - ((-c[1] + a[0][1])*(c[2]*(xiAnchor[0]*a[0][1] + xiAnchor[1]*a[1][1]) - c[1]*(xiAnchor[0]*a[0][2] + xiAnchor[1]*a[1][2])))/xiCargoRotation - ((c[0] - a[0][0])*(c[2] - a[0][2])*(xiAnchor[0]*a[0][0] + dt*FmTangential[0][0]))/xiCargoRotation - ((c[1] - a[0][1])*(c[2] - a[0][2])*(xiAnchor[0]*a[0][1] + dt*FmTangential[0][1]))/xiCargoRotation + ((xiCargoRotation + xiAnchor[0]*(pow(c[0],2) + pow(c[1],2) - 2*c[0]*a[0][0] + pow(a[0][0],2) - 2*c[1]*a[0][1] + pow(a[0][1],2)))*(xiAnchor[0]*a[0][2] + dt*FmTangential[0][2]))/(xiCargoRotation*xiAnchor[0]) - ((c[0] - a[0][0])*(c[2] - a[1][2])*(xiAnchor[1]*a[1][0] + dt*FmTangential[1][0]))/xiCargoRotation - ((c[1] - a[0][1])*(c[2] - a[1][2])*(xiAnchor[1]*a[1][1] + dt*FmTangential[1][1]))/xiCargoRotation + ((pow(c[0],2) + pow(c[1],2) + a[0][0]*a[1][0] - c[0]*(a[0][0] + a[1][0]) + a[0][1]*a[1][1] - c[1]*(a[0][1] + a[1][1]))*(xiAnchor[1]*a[1][2] + dt*FmTangential[1][2]))/xiCargoRotation;

            a1[1][0] = -(((c[1] - a[1][1])*(c[1]*(xiAnchor[0]*a[0][0] + xiAnchor[1]*a[1][0]) - c[0]*(xiAnchor[0]*a[0][1] + xiAnchor[1]*a[1][1])))/xiCargoRotation) - ((-c[2] + a[1][2])*(-(c[2]*(xiAnchor[0]*a[0][0] + xiAnchor[1]*a[1][0])) + c[0]*(xiAnchor[0]*a[0][2] + xiAnchor[1]*a[1][2])))/xiCargoRotation + ((pow(c[1],2) + pow(c[2],2) + a[0][1]*a[1][1] - c[1]*(a[0][1] + a[1][1]) + a[0][2]*a[1][2] - c[2]*(a[0][2] + a[1][2]))*(xiAnchor[0]*a[0][0] + dt*FmTangential[0][0]))/xiCargoRotation - ((c[0] - a[0][0])*(c[1] - a[1][1])*(xiAnchor[0]*a[0][1] + dt*FmTangential[0][1]))/xiCargoRotation - ((c[0] - a[0][0])*(c[2] - a[1][2])*(xiAnchor[0]*a[0][2] + dt*FmTangential[0][2]))/xiCargoRotation + ((xiCargoRotation + xiAnchor[1]*(pow(c[1],2) + pow(c[2],2) - 2*c[1]*a[1][1] + pow(a[1][1],2) - 2*c[2]*a[1][2] + pow(a[1][2],2)))*(xiAnchor[1]*a[1][0] + dt*FmTangential[1][0]))/(xiCargoRotation*xiAnchor[1]) - ((c[0] - a[1][0])*(c[1] - a[1][1])*(xiAnchor[1]*a[1][1] + dt*FmTangential[1][1]))/xiCargoRotation - ((c[0] - a[1][0])*(c[2] - a[1][2])*(xiAnchor[1]*a[1][2] + dt*FmTangential[1][2]))/xiCargoRotation;

            a1[1][1] = -(((-c[0] + a[1][0])*(c[1]*(xiAnchor[0]*a[0][0] + xiAnchor[1]*a[1][0]) - c[0]*(xiAnchor[0]*a[0][1] + xiAnchor[1]*a[1][1])))/xiCargoRotation) - ((c[2] - a[1][2])*(c[2]*(xiAnchor[0]*a[0][1] + xiAnchor[1]*a[1][1]) - c[1]*(xiAnchor[0]*a[0][2] + xiAnchor[1]*a[1][2])))/xiCargoRotation - ((c[1] - a[0][1])*(c[0] - a[1][0])*(xiAnchor[0]*a[0][0] + dt*FmTangential[0][0]))/xiCargoRotation + ((pow(c[0],2) + pow(c[2],2) + a[0][0]*a[1][0] - c[0]*(a[0][0] + a[1][0]) + a[0][2]*a[1][2] - c[2]*(a[0][2] + a[1][2]))*(xiAnchor[0]*a[0][1] + dt*FmTangential[0][1]))/xiCargoRotation - ((c[1] - a[0][1])*(c[2] - a[1][2])*(xiAnchor[0]*a[0][2] + dt*FmTangential[0][2]))/xiCargoRotation - ((c[0] - a[1][0])*(c[1] - a[1][1])*(xiAnchor[1]*a[1][0] + dt*FmTangential[1][0]))/xiCargoRotation + ((xiCargoRotation + xiAnchor[1]*(pow(c[0],2) + pow(c[2],2) - 2*c[0]*a[1][0] + pow(a[1][0],2) - 2*c[2]*a[1][2] + pow(a[1][2],2)))*(xiAnchor[1]*a[1][1] + dt*FmTangential[1][1]))/(xiCargoRotation*xiAnchor[1]) - ((c[1] - a[1][1])*(c[2] - a[1][2])*(xiAnchor[1]*a[1][2] + dt*FmTangential[1][2]))/xiCargoRotation;

            a1[1][2] = -(((c[0] - a[1][0])*(-(c[2]*(xiAnchor[0]*a[0][0] + xiAnchor[1]*a[1][0])) + c[0]*(xiAnchor[0]*a[0][2] + xiAnchor[1]*a[1][2])))/xiCargoRotation) - ((-c[1] + a[1][1])*(c[2]*(xiAnchor[0]*a[0][1] + xiAnchor[1]*a[1][1]) - c[1]*(xiAnchor[0]*a[0][2] + xiAnchor[1]*a[1][2])))/xiCargoRotation - ((c[2] - a[0][2])*(c[0] - a[1][0])*(xiAnchor[0]*a[0][0] + dt*FmTangential[0][0]))/xiCargoRotation - ((c[2] - a[0][2])*(c[1] - a[1][1])*(xiAnchor[0]*a[0][1] + dt*FmTangential[0][1]))/xiCargoRotation + ((pow(c[0],2) + pow(c[1],2) + a[0][0]*a[1][0] - c[0]*(a[0][0] + a[1][0]) + a[0][1]*a[1][1] - c[1]*(a[0][1] + a[1][1]))*(xiAnchor[0]*a[0][2] + dt*FmTangential[0][2]))/xiCargoRotation - ((c[0] - a[1][0])*(c[2] - a[1][2])*(xiAnchor[1]*a[1][0] + dt*FmTangential[1][0]))/xiCargoRotation - ((c[1] - a[1][1])*(c[2] - a[1][2])*(xiAnchor[1]*a[1][1] + dt*FmTangential[1][1]))/xiCargoRotation + ((xiCargoRotation + xiAnchor[1]*(pow(c[0],2) + pow(c[1],2) - 2*c[0]*a[1][0] + pow(a[1][0],2) - 2*c[1]*a[1][1] + pow(a[1][1],2)))*(xiAnchor[1]*a[1][2] + dt*FmTangential[1][2]))/(xiCargoRotation*xiAnchor[1]);

            c1[0] = -((-(xiCargoTranslation*c[0]) + xiAnchor[0]*a[0][0] + xiAnchor[1]*a[1][0] - dt*(Fsteric[0] + Ftrap[0] + FmRadial[0][0] + FmRadial[1][0]))/xiCargoTranslation) + (xiAnchor[0]*a[0][0] + dt*FmTangential[0][0])/xiCargoTranslation + (xiAnchor[1]*a[1][0] + dt*FmTangential[1][0])/xiCargoTranslation;

            c1[1] = -((-(xiCargoTranslation*c[1]) + xiAnchor[0]*a[0][1] + xiAnchor[1]*a[1][1] - dt*(Fsteric[1] + Ftrap[1] + FmRadial[0][1] + FmRadial[1][1]))/xiCargoTranslation) + (xiAnchor[0]*a[0][1] + dt*FmTangential[0][1])/xiCargoTranslation + (xiAnchor[1]*a[1][1] + dt*FmTangential[1][1])/xiCargoTranslation;

            c1[2] = -((-(xiCargoTranslation*c[2]) + xiAnchor[0]*a[0][2] + xiAnchor[1]*a[1][2] - dt*(Fsteric[2] + Ftrap[2] + FmRadial[0][2] + FmRadial[1][2]))/xiCargoTranslation) + (xiAnchor[0]*a[0][2] + dt*FmTangential[0][2])/xiCargoTranslation + (xiAnchor[1]*a[1][2] + dt*FmTangential[1][2])/xiCargoTranslation;

            omega[0] = -((c[2]*(xiAnchor[0]*a[0][1] + xiAnchor[1]*a[1][1]) - c[1]*(xiAnchor[0]*a[0][2] + xiAnchor[1]*a[1][2]))/(dt*xiCargoRotation)) + ((c[2] - a[0][2])*(xiAnchor[0]*a[0][1] + dt*FmTangential[0][1]))/(dt*xiCargoRotation) + ((-c[1] + a[0][1])*(xiAnchor[0]*a[0][2] + dt*FmTangential[0][2]))/(dt*xiCargoRotation) + ((c[2] - a[1][2])*(xiAnchor[1]*a[1][1] + dt*FmTangential[1][1]))/(dt*xiCargoRotation) + ((-c[1] + a[1][1])*(xiAnchor[1]*a[1][2] + dt*FmTangential[1][2]))/(dt*xiCargoRotation);

            omega[1] = -((-(c[2]*(xiAnchor[0]*a[0][0] + xiAnchor[1]*a[1][0])) + c[0]*(xiAnchor[0]*a[0][2] + xiAnchor[1]*a[1][2]))/(dt*xiCargoRotation)) + ((-c[2] + a[0][2])*(xiAnchor[0]*a[0][0] + dt*FmTangential[0][0]))/(dt*xiCargoRotation) + ((c[0] - a[0][0])*(xiAnchor[0]*a[0][2] + dt*FmTangential[0][2]))/(dt*xiCargoRotation) + ((-c[2] + a[1][2])*(xiAnchor[1]*a[1][0] + dt*FmTangential[1][0]))/(dt*xiCargoRotation) + ((c[0] - a[1][0])*(xiAnchor[1]*a[1][2] + dt*FmTangential[1][2]))/(dt*xiCargoRotation);

            omega[2] = -((c[1]*(xiAnchor[0]*a[0][0] + xiAnchor[1]*a[1][0]) - c[0]*(xiAnchor[0]*a[0][1] + xiAnchor[1]*a[1][1]))/(dt*xiCargoRotation)) + ((c[1] - a[0][1])*(xiAnchor[0]*a[0][0] + dt*FmTangential[0][0]))/(dt*xiCargoRotation) + ((-c[0] + a[0][0])*(xiAnchor[0]*a[0][1] + dt*FmTangential[0][1]))/(dt*xiCargoRotation) + ((c[1] - a[1][1])*(xiAnchor[1]*a[1][0] + dt*FmTangential[1][0]))/(dt*xiCargoRotation) + ((-c[0] + a[1][0])*(xiAnchor[1]*a[1][1] + dt*FmTangential[1][1]))/(dt*xiCargoRotation);

            break;

        default:
            printf("Bad value for total_pulling_motors\n");
    }
}
