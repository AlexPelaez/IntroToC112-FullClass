
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ELEMENT_FILENAME "element_db.csv"

typedef struct {
    int atomic_number;
    char symbol[4];
    char name[25];
    float atomic_weight;
    char state[25];
    char bonding_type[25];
    char discovered[25];
} element_t;

element_t * find_element( element_t * list, char * symbol );

int main( int argc, char * argv[] )
{
    if ( argc < 2 )
    {
        printf(" ERROR: Please provide at least one program argument.\n");
        return 0;
    }

    element_t * elements = (element_t *)calloc( 118 , sizeof( element_t ) );

    FILE * element_file = fopen( ELEMENT_FILENAME, "r" );
    if ( element_file != NULL )
    {
        char line[100];
        while( fgets(line, 100, element_file ) != NULL )
        {
            // remove newline character from line
            char * nl = strchr( line, '\n' );
            if ( nl )
            {
                *nl = '\0';
            }
            //printf("line = %s\n", line );
            element_t e;
            char * str = strtok( line, "," );
            int col = 0;
            while ( str != NULL )
            {
                switch( col )
                {
                    case 0:
                        e.atomic_number = atoi( str );
                        break;
                    case 1:
                        strcpy( e.symbol, str );
                        break;
                    case 2:
                        strcpy( e.name, str );
                        break;
                    case 3:
                        e.atomic_weight=  atof( str );
                        break;
                    case 4:
                        strcpy(e.state, str);
                        break;
                    case 5:
                        strcpy(e.bonding_type,str);
                        break;
                    case 6:
                        strcpy(e.discovered,str);
                        break;
                }
                str = strtok( NULL, "," );
                col++;
            }
            elements[ e.atomic_number - 1 ] = e;


            //printf(" %s\n", elements[ e.atomic_number - 1].symbol );
        }
        fclose( element_file );
    }

    // process program arguments.
    FILE * output_f = NULL;
    int i;
    for( i = 1; i < argc; i++ )
    {
        if ( i == 1 ) // check for filename
        {
            char * dot = strchr( argv[i], '.' );
            if ( dot )
            {
                // this is a filename
                output_f = fopen( argv[i], "w" );
                continue;
            }
            else
            {
              output_f=stdout;
            }
        }

        // Look up this element
        element_t * ele = find_element( elements, argv[i] );
        if(ele == NULL){
          printf("WARNING: No such element: %s\n",ele->symbol );
          continue;
        }
         if ( ele )
        {
            fprintf(output_f,"---------------\n" );
            fprintf(output_f,"| %d\t%f\n",ele->atomic_number, ele->atomic_weight);
            fprintf(output_f,"| %s\t%s\n",ele->symbol,ele->name );
            fprintf(output_f,"| %s\n",ele->state );
            fprintf(output_f,"| %s\n", ele->bonding_type);
            fprintf(output_f,"| Found: %s\n", ele->discovered);
            fprintf(output_f,"---------------\n" );
            continue;
          //  printf("%d %s %s %f %s %s %s\n", ele->atomic_number, ele->symbol, ele->name, ele->atomic_weight, ele->state, ele->bonding_type, ele->discovered);
        }

    }
    fclose(output_f);
    return 0;
}





element_t * find_element( element_t * list, char * symbol )
{
    int i;
    for( i = 0; i < 118; i++ )
    {
        if ( strcmp( list[i].symbol, symbol ) == 0 )
        {
            element_t * result = &list[i];
            return result;
        }
    }
    return NULL;
}
