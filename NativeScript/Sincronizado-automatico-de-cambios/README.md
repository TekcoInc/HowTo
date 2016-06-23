## Sincronización automática de cambios en NativeScript

Descripción | Nivel
------------ | ------------
En este HowTo veremos cómo es posible configurar la actualización automática de cambios en el emulador/dispositivo en NativeScript | Principiante

Lo primero que necesitamos es tener lista la instalación de **NativeScript**, puedes ver el cómo en el siguiente link: [NativeScript Instalación](http://docs.nativescript.org/start/quick-setup).

Una vez el ambiente está listo, desde la consola vamos a crear la aplicación con el comando:

``` tns create HelloNativeScript```

La instrucción anterior se encarga de crear una nueva aplicación NativeScript con el nombre HelloNativeScript.

![Create NativeScript Project](http://res.cloudinary.com/julitogtu/image/upload/v1466708599/ns1_gajqgr.png)

El siguiente paso es añadir las plataformas que van a soportar, para este ejemplo añadimos soporte para Android:

``` tns platform add android```

![Add Android Platform](http://res.cloudinary.com/julitogtu/image/upload/v1466708899/ns2_dwbeki.png)

Ahora, vamos a usar [Visual Studio Code](``` tns platform add android```) para editar el proyecto, en este caso podemos abrir directamente VSCode con el siguiente comando:

``` code .```

Una vez se abra VSCode, en la carpeta platforms se puede ver que existe la carpeta android, ya que fué la plataforma que añadimos anteriormente:

![Visual Studio Code](http://res.cloudinary.com/julitogtu/image/upload/v1466709148/ns3_cjbygm.png)

Ahora, abrimos el emulador para Android [Genymotion](https://www.genymotion.com/) para probar la aplicación, y ejecutamos algunos de los dispositivos virtuales configurados:

![Genymotion Emulator](http://res.cloudinary.com/julitogtu/image/upload/v1466709456/ns4_q9ernb.png)

Ahora, para ejecutar el proyecto y habilitar la opción de sincronización automática, utilizamos el siguiente comando:

``` tns livesync android --watch```

El comando anterior ejecuta el proyecto en el emulador y cuando se realice algún cambio en el proyecto será actualizado automáticamente en el emulador sin necesidad de volver a lanzar la aplicación:

![](http://res.cloudinary.com/julitogtu/image/upload/v1466710881/ns_3_h9yacn.gif)

Gracias por leer este HowTo.

[@julitogtu](https://twitter.com/julitogtu)
