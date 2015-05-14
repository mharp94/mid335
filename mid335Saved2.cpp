#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

//frequency definitions
#define A4 440.0
#define F0 A4
#define F0_note A
#define F0_octave 4

float arr[111] = {16.35, 17.32, 18.35, 19.45, 20.60, 21.83, 23.12, 24.50, 25.96, 27.50, 29.14, 30.87, 32.70, 34.65, 36.71,
36.71, 
38.89,   
41.20,  
43.65,
46.25,
49.00,
51.91,
55.00,
58.27,
61.74, 
65.41, 
69.30,   
73.42,  
77.78,  
82.41,         
87.31, 
92.50, 
98.00,
103.83,
110.00, 
116.54, 
123.47,
130.81,
138.59, 
146.83,
155.56,
164.81,
174.61,
185.00,
196.00,
207.65,
220.00,
233.08,
246.94,
261.63,
277.18,
349.23,  
369.99,
392.00,  
415.3,
440.00,
466.16,  
493.88, 
523.25,
554.37, 
587.33,  
622.25,
659.25,
698.46,
739.99,
783.99,
830.61, 
880.00, 
932.33,  
987.77, 
1046.50,
1108.73,     
1174.66,   
1244.51,     
1318.51,     
1396.91,     
1479.98,     
1567.98,     
1661.22,   
1760.00,    
1864.66, 
1975.53,    
2093.00,    
2217.46,    
2349.32,     
2489.02,    
2637.02,     
2793.83,     
2959.96,     
3135.96,     
3322.44,    
3520.00,
3729.31,
3951.07, 
4186.01,
4434.92,
4698.63,   
4978.03,    
5274.04,  
5587.65,     
6271.93,     
7040.00,     
7902.13 };

typedef enum {
    C = 1,
    Cs,
    D,
    Ds,
    E,
    F,
    Fs,
    G,
    Gs,
    A,  
    As,
    B,
    Z,
    END = B,
    HALF_STEPS_PER_OCTAVE = B
} note_t;

double freq(note_t note, int octave_delta);

int main(int argc, char *argv[]) {
    
    note_t note;
    float octave_delta, tolerance;

    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <NOTE>  <OCTAVE_DELTA> <TOLERANCE>" << endl;
        return 0;
    }
    
    note = (note_t)(toupper(argv[1][0]) - 64);
    
    switch(toupper(argv[1][0])) {
        case 'A': note = A; break;
        case 'B': note = B; break;
        case 'C': note = C; break;
        case 'D': note = D; break;
        case 'E': note = E; break;
        case 'F': note = F; break;
        case 'Z': note = Z; break; //
    }
    //You may call your unit test here...

    if (note > END + 1) {
        cout << "Invalid note!" << endl;
        return 1;
    }

    octave_delta = atoi(argv[2]);
    tolerance = atof(argv[3]);


    cout << "Tolerance: " << (float)octave_delta << "\n";

    if (note == 13 && octave_delta == 0) {
        cout << "Freq function unit-test\n\n";
        cout << "note octave value  diff\n";
        cout << "---- ------ ------ -------\n";

	for (int i = 1; i < 13; i++) {
            float diff = freq((note_t)i, 0) - arr[i - 1];

	    cout << i << "    " << 0 << "    " << freq((note_t)i, 0) << "  " << fabs(diff);
	    if ( fabs(diff) > tolerance ) {
		cout << "<---- Bad\n";
            } else {
		cout << "<---- Good\n";
            }
	    
	}
        /* note = (note_t)(1);
        float diff = freq(note, 0) - 16.35;
        cout << "1    0    " << freq(note, 0)  << "    " << fabs(diff) << endl; 
        */
    }

    //cout << HALF_STEPS_PER_OCTAVE << endl;
    //cout << freq(note, octave_delta) << endl;
    return 0;
}

//-----------------------------------------------------------
//Generate a frequency in hz that is half_steps away from C_4
//Do not modify this function.
//-----------------------------------------------------------
double freq(note_t note, int octave_delta)
{
    float freq;
    double factor;
    double a;
    int n;
    int octave = octave_delta - F0_octave;

    a = pow(2.0, 1.0/(double)HALF_STEPS_PER_OCTAVE);
    n = note - F0_note;
    freq = F0 * pow(a, (double)n);
    factor = pow(2.0, (double)octave);
    freq = freq * factor;
    return freq;
}


