Incluir archivo de formato log llamado "mylog.log" para que funcione correctamente el programa.

En caso de querer verificar con todos los casos, en el codigo main cambiar el valor de la variable "shorttest" de TRUE a FALSE, ya que en su defecto solo leera las primeras 100 entradas.

--------------------------------------------------------------------------------------------------------

Se usa el algoritmo de ordenamiento tipo merge lo que da como complejidad O(5*n*log(n)) en el peor de los casos, mientras que para el algoritmo de busqueda se utiliza un algoritmo O(4*n) en el peor de los casos ya que a pesar de solo recorrer una vez como algoritmo en ambos casos, puede llegar a haber hasta 5 comparaciones por entrada de la bitacora, ya que compara Mes, Dia, Hora, Minuto, Segundo para el algoritmo de ordenamiento, mientras que el algoritmo de busqueda solo compara el mes y el dia, pero lo hace 2 veces por entrada para poder mostrar el resultado.