#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//  Standard Code trasnl_table
//   AAs  = FFLLSSSSYY**CC*WLLLLPPPPHHQQRRRRIIIMTTTTNNKKSSRRVVVVAAAADDEEGGGG
// Starts = ---M------**--*----M---------------M----------------------------
// Base1  = TTTTTTTTTTTTTTTTCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAGGGGGGGGGGGGGGGG
// Base2  = TTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGGTTTTCCCCAAAAGGGG
// Base3  = TCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAGTCAG


const int idxT = 0;
const int idxC = 1;
const int idxA = 2;
const int idxG = 3;

const char translationTable[] = "FFLLSSSSYY**CC*WLLLLPPPPHHQQRRRRIIIMTTTTNNKKSSRRVVVVAAAADDEEGGGG";

int _getOffsetForNucleotide(char nucleotide, int codonPosition) {

    int multiplier = (int)pow(4.0 , (3.0 - codonPosition));

    nucleotide = (char)toupper(nucleotide);

    switch (nucleotide) {
        case 'T': case 'U':
            return multiplier * idxT;
            case 'C':
            return multiplier * idxC;
        case 'A':
            return multiplier * idxA;
        case 'G':
            return multiplier * idxG;
        default: {
            printf("the nucleotide %c is not recognized", nucleotide);
            return -1;
        }
    }
}

char translate( char codon[]) {
    if(strlen(codon) != 3){
        printf("a codon must have a length of 3\n");
        return 1;
    }

    int totalOffset = 0;
    for (int i = 0; i < 3; ++i) {
        char nuc = codon[i];
        int offset = _getOffsetForNucleotide(nuc, i+1);

        if (offset == -1) {
            return -1;
        }
        totalOffset += offset;
    }
    return translationTable[totalOffset];
}

int main() {
    char codon[3];

    while (1) {
        printf("type a codon or X to exit ...\n");
        scanf("%s", codon);

        if(strcasecmp(codon, "X") == 0){
            return 1;
        }

        char aminoAcid = translate(codon);

        printf("%s translates to %c\n\n", codon, aminoAcid);

    }

}

