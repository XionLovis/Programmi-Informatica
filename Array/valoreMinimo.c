/* scrivi qui il codice che ritorna il valore minimo
   dell'array A di interi che ha lunghezza len. */

int valore_minimo_array(int *A, int len){
    int i;
    int *s;
    int min;

    s = &A[0];
    min = *s;

    for(i = 0; i++; s++) {
        if(*s < min)
            min = *s;
    }
    return min;
}
