#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv)
{
//Conector para acceder al servidor de bases de datos
MYSQLconn;
int err;
MYSQL_RESresultado;
MYSQL_ROW row;

//creamos una conexion al servidor
conn= mysql_init(NULL);
if(conn==NULL){
    printf ("Error al crear la conexion: %u %s\n", 
            mysql_errno(conn), mysql_error(conn));
    exit (1);
}
//inicializar la conexion, indicando nuestras claves de acceso
// al servidor de bases de datos (user,pass)
conn = mysql_real_connect (conn, "localhost","root", "mysql", NULL, 0, NULL, 0);
if (conn==NULL)
{
    printf ("Error al inicializar la conexion: %u %s\n", 
            mysql_errno(conn), mysql_error(conn));
    exit (1);
}
//Buscar el circuito más jugado de un jugador por su nombre

printf ("Dame el nombre de un jugador\n");
    scanf("%d",nombre);
    strcpy(consulta,"SELECT CIRCUITOFAV FROM JUGADOR WHERE NOMBRE='");
    strcat(consulta,NOMBRE);
    strcat(consulta,"'");
    err=mysql_query(conn,consulta);

    if(err!=0){
        printf("Error al consultar los datos de la base %u%s\n",
               mysql_errno(conn),mysql_error(conn));
        exit(1);
    }
    resultado=mysql_store_result(conn);

    row =mysql_fetch_row(resultado);
    if(row==NULL)
        printf ("No se han obtenido datos\n");
    else 
        while(row!=NULL){
        JUGADORMASRAPIDO=atoi(row[3]);

        printf("El circuito más jugador del jugador con nombre %d és %s\n",NOMBRE, row[6]);

        //obtenemos la siguiente fila
        row=mysql_fetch_row(resultado);

//cerrar la conexion 
        mysql_close(conn);
        exit(0);
}
}
