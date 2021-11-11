PAV - P2: detección de actividad vocal (VAD)
============================================

Esta práctica se distribuye a través del repositorio GitHub [Práctica 2](https://github.com/albino-pav/P2),
y una parte de su gestión se realizará mediante esta web de trabajo colaborativo.  Al contrario que Git,
GitHub se gestiona completamente desde un entorno gráfico bastante intuitivo. Además, está razonablemente
documentado, tanto internamente, mediante sus [Guías de GitHub](https://guides.github.com/), como
externamente, mediante infinidad de tutoriales, guías y vídeos disponibles gratuitamente en internet.


Inicialización del repositorio de la práctica.
----------------------------------------------

Para cargar los ficheros en su ordenador personal debe seguir los pasos siguientes:

*	Abra una cuenta GitHub para gestionar esta y el resto de prácticas del curso.
*	Cree un repositorio GitHub con el contenido inicial de la práctica (sólo debe hacerlo uno de los
	integrantes del grupo de laboratorio, cuya página GitHub actuará de repositorio central del grupo):
	-	Acceda la página de la [Práctica 2](https://github.com/albino-pav/P2).
	-	En la parte superior derecha encontrará el botón **`Fork`**. Apriételo y, después de unos segundos,
		se creará en su cuenta GitHub un proyecto con el mismo nombre (**P2**). Si ya tuviera uno con ese 
		nombre, se utilizará el nombre **P2-1**, y así sucesivamente.
*	Habilite al resto de miembros del grupo como *colaboradores* del proyecto; de este modo, podrán
	subir sus modificaciones al repositorio central:
	-	En la página principal del repositorio, en la pestaña **:gear:`Settings`**, escoja la opción 
		**Collaborators** y añada a su compañero de prácticas.
	-	Éste recibirá un email solicitándole confirmación. Una vez confirmado, tanto él como el
		propietario podrán gestionar el repositorio, por ejemplo: crear ramas en él o subir las
		modificaciones de su directorio local de trabajo al repositorio GitHub.
*	En la página principal del repositorio, localice el botón **Branch: master** y úselo para crear
	una rama nueva con los primeros apellidos de los integrantes del equipo de prácticas separados por
	guion (**fulano-mengano**).
*	Todos los miembros del grupo deben realizar su copia local en su ordenador personal.
	-	Copie la dirección de su copia del repositorio apretando en el botón **Clone or download**.
		Asegúrese de usar *Clone with HTTPS*.
	-	Abra una sesión de Bash en su ordenador personal y vaya al directorio **PAV**. Desde ahí, ejecute:

		```.sh
		git clone dirección-del-fork-de-la-práctica
		```

	-	Vaya al directorio de la práctica `cd P2`.
	-	Añada la etiqueta `origin` a su copia del repositorio. Esto es útil para facilitar los *push* y
		*pull* al repositorio original:
		```.sh
		git remote add origin dirección-del-fork-de-la-práctica
		```
	-	Cambie a la rama **fulano-mengano** con la orden:

		```.sh
		git checkout fulano-mengano
		```

*	A partir de este momento, todos los miembros del grupo de prácticas pueden trabajar en su directorio
	local del modo habitual.
	-	También puede utilizar el repositorio remoto como repositorio central para el trabajo colaborativo
		de los distintos miembros del grupo de prácticas; o puede serle útil usarlo como copia de
		seguridad.
	-	Cada vez que quiera subir sus cambios locales al repositorio GitHub deberá confirmar los
		cambios en su directorio local:

		```.sh
		git add .
		git commit -m "Mensaje del commit"
		```

		y, a continuación, subirlos con la orden:

		```.sh
		git push -u origin fulano-mengano
		```

*	Al final de la práctica, la rama **fulano-mengano** del repositorio GitHub servirá para remitir la
	práctica para su evaluación utilizando el mecanismo *pull request*.
	-	Vaya a la página principal de la copia del repositorio y asegúrese de estar en la rama
		**fulano-mengano**.
	-	Pulse en el botón **New pull request**, y siga las instrucciones de GitHub.


Entrega de la práctica.
-----------------------

Responda, en este mismo documento (README.md), los ejercicios indicados a continuación. Este documento es
un fichero de texto escrito con un formato denominado _**markdown**_. La principal característica de este
formato es que, manteniendo la legibilidad cuando se visualiza con herramientas en modo texto (`more`,
`less`, editores varios, ...), permite amplias posibilidades de visualización con formato en una amplia
gama de aplicaciones; muy notablemente, **GitHub**, **Doxygen** y **Facebook** (ciertamente, :eyes:).

En GitHub. cuando existe un fichero denominado README.md en el directorio raíz de un repositorio, se
interpreta y muestra al entrar en el repositorio.

Debe redactar las respuestas a los ejercicios usando Markdown. Puede encontrar información acerca de su
sintáxis en la página web [Sintaxis de Markdown](https://daringfireball.net/projects/markdown/syntax).
También puede consultar el documento adjunto [MARKDOWN.md](MARKDOWN.md), en el que se enumeran los
elementos más relevantes para completar la redacción de esta práctica.

Recuerde realizar el *pull request* una vez completada la práctica.

Ejercicios
----------

### Etiquetado manual de los segmentos de voz y silencio

- Etiquete manualmente los segmentos de voz y silencio del fichero grabado al efecto. Inserte, a 
  continuación, una captura de `wavesurfer` en la que se vea con claridad la señal temporal, el contorno de
  potencia y la tasa de cruces por cero, junto con el etiquetado manual de los segmentos.

![1 (3)](https://user-images.githubusercontent.com/71181207/138514994-810e3034-5a0d-4183-b95b-ef5cf05d4460.png)

- A la vista de la gráfica, indique qué valores considera adecuados para las magnitudes siguientes:

	* Incremento del nivel potencia en dB, respecto al nivel correspondiente al silencio inicial, para
	  estar seguros de que un segmento de señal se corresponde con voz.
	  
	  Tenemos un silencio entorno a los 16 dBs, obteniendo un pico a causa de ruido de 42.82 dBs.
	  Teniendo un incremento de 27 dBs.
	  Vemos como incrementa a 60.72 dBs al comienzar con la primera palabra. Viniendo de 17.98 dBs.
	  Teniendo un incremento de 46 dBs.
	  Decidimos un valor minimo para asegurar que un segmento de señal es voz, cogemos el de 16 dBs.
	  Al ser el más pequeño determina la transición de silencio a voz.
	  Hemos comparado con el resto de la señal y vemos que se respeta.
	  
	* Duración mínima razonable de los segmentos de voz y silencio.
		
	  Duración mínima segmento voz es de 0.55 segundos.
	  Duración mínima segmento silencio es de 0.75 segundos.

	* ¿Es capaz de sacar alguna conclusión a partir de la evolución de la tasa de cruces por cero?
	  
	  Vemos que el valor de tasa de cruces por cero incrementa mucho al haber silencios y se estabiliza al haber voz, pudiendo saber cuando tenemos voz o silencio en función de esta.

### Desarrollo del detector de actividad vocal

- Complete el código de los ficheros de la práctica para implementar un detector de actividad vocal tan
  exacto como sea posible. Tome como objetivo la maximización de la puntuación-F `TOTAL`.
	
	Primero añadimos el codigo de pav_analysis.c y pav_analysis.h que implementamos en la Practica 1, con ello somos capaces de poder obtener las características correspondientes de cada trama. Siendo la potencia, tasa de cruces por cero y por último la amplitud media.
	Una vez hecho esto pasamos a modificar el fichero meson.build para la compilación y enlazado de todos los .c, donde incluimos el fichero pav_analysis.c.
	
	![image](https://user-images.githubusercontent.com/71181207/139592260-d652128a-7f88-4242-b566-b3d8b652febc.png)

	Procedemos a modificar el vad.c, donde incluimos la libreria de pav_analysis.h para poder completar la función compute_features() mediante las funciones que ya desarrollamos para la obtención de las características de la señal.
	
	![image](https://user-images.githubusercontent.com/71181207/139592165-0847e0db-8ba8-41d6-bcb6-982ca5bbd364.png)

	![image](https://user-images.githubusercontent.com/71181207/139592457-9baf6d20-7c93-47b1-a665-8f98b321d894.png)
	
	Seguidamente desarrollamos una primera propuesta de maquina de estados. Dado que el automata se basa en mayor parte en la potencia de la trama, lo que hacemos es inicializar un threshold inicial p1 en la funcion vad() que diferencie las tramas de silencio con las de voz. En clase declaramos la variable alpha1, valor que le sumamos al p0 para la obtencion del umbral. De esta forma si la potencia de la trama actual es mayor a dicho valor determinaremos que la trama en este caso es de voz y en caso contrario seria silencio.
	
	![image](https://user-images.githubusercontent.com/71181207/139592457-9baf6d20-7c93-47b1-a665-8f98b321d894.png)
	
	Los primeros resultados de detección que obtuvimos en clase fueron bastante malos, y poco a poco, al ir cambiando el valor del parámetro alpha1 alcanzamos una detección de tramas silencio/voz decente de momento. A continuacion, evaluamos los resultados con vad_evaluation.pl con el próposito de concretar el valor de 'Recall', que nos indica la proporción de muestras que detecta nuestro algoritmo respecto al Ground Truth. Además, 'Precicion' nos indica la proporción de las muestras detectadas por nuestro algoritmo respecto al conjunto de muestras detectadas de la máquina de estados. Haciendo la media harmónica de los parámetros de 'Recall' y 'Precision' obtenemos la medida F-score. Como observamos en la siguiente captura obtenemos una F-score de 82,439%.
	
	****captura pendiente********* (captura #2 del google doc)
	
	**Primera Mejora del Autómata**
	
	De momento el umbral p1 adquiere el valor tomado de la potencia en la primera trama más una diferencia. Deducimos que esta forma de definir el umbral se puede optimizar. Entonces, lo que hemos pensado para mejorar el umbral es hacer el promedio de la potencia en la primera trama, de manera que cojeremos el valor de potencia promedio de las primeras tramas.
	
	****captura pendiente******** (formula de la media, la tengo que hacer con el ipad)
	
	Con el objetivo de aplicar la mejora comentada, modificamos pav_analysis.c y su libreria para añadir la nueva función compute_init_power().
	
	****captura pendiente******** (captura #3 del google doc)
	
	Agregamos dos características más a VAD_DATA, "p0" y "num_trama" particulares de la señal. Con "p0" conseguimos mantener el valor que vamos calculando de la potencia a medida que van sucediendo las tramas, y la variable "num_trama" la usamos como un contador.
	
	****captura pendiente******** (captura #4 del google doc)
	
	Como podemos apreciar en la siguiente captura modificamos el estado inicial del automata.
	
	****captura pendiente******** (captura #5 del google doc)
	
	Observamos que hasta que no se hayanprocesado 10 tramas del audio, que las adjudicamos como silencio, entonces se van sumando la potencia en lineal de las distintas tramas. Las podemos sumar en lineal ya que con la funcion compute_init_power() pasamos de dB's a lineal. 
	
	El automata no modificara su estado y permanecera en en el estado INIT a lo largo de las 10 tramas. Cuando hayamos hecho la suma de la potencia de las tramas, calculamos el promedio de la potencia en logaritmico i asignamos este valor a p0 y tambien modificamos de la misma forma el valor del threshold p1.
	
	
- Inserte una gráfica en la que se vea con claridad la señal temporal, el etiquetado manual y la detección
  automática conseguida para el fichero grabado al efecto. 


- Explique, si existen. las discrepancias entre el etiquetado manual y la detección automática.

- Evalúe los resultados sobre la base de datos `db.v4` con el script `vad_evaluation.pl` e inserte a 
  continuación las tasas de sensibilidad (*recall*) y precisión para el conjunto de la base de datos (sólo
  el resumen).


### Trabajos de ampliación

#### Cancelación del ruido en los segmentos de silencio

- Si ha desarrollado el algoritmo para la cancelación de los segmentos de silencio, inserte una gráfica en
  la que se vea con claridad la señal antes y después de la cancelación (puede que `wavesurfer` no sea la
  mejor opción para esto, ya que no es capaz de visualizar varias señales al mismo tiempo).

#### Gestión de las opciones del programa usando `docopt_c`

- Si ha usado `docopt_c` para realizar la gestión de las opciones y argumentos del programa `vad`, inserte
  una captura de pantalla en la que se vea el mensaje de ayuda del programa.


### Contribuciones adicionales y/o comentarios acerca de la práctica

- Indique a continuación si ha realizado algún tipo de aportación suplementaria (algoritmos de detección o 
  parámetros alternativos, etc.).

- Si lo desea, puede realizar también algún comentario acerca de la realización de la práctica que
  considere de interés de cara a su evaluación.


### Antes de entregar la práctica

Recuerde comprobar que el repositorio cuenta con los códigos correctos y en condiciones de ser 
correctamente compilados con la orden `meson bin; ninja -C bin`. El programa generado (`bin/vad`) será
el usado, sin más opciones, para realizar la evaluación *ciega* del sistema.
