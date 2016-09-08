# Introducción a Hybrid UI

Descripción | Nivel
------------ | ------------
En este HowTo haremos un ejemplo básico con Kendo Hybrid UI. | Principiante

El primer paso para poder trabajar con Kendo Hybrid UI es colocar las referencias correspondintes para los estilos y las librería javascript, esto se puede realizar de dos formas:

1) Descargar el paquete de Kendo y referenciar los archivos locales.

2) Utilizar la red CDN de Telerik (requiere conexión a internet 100%).

Sea cual sea la opción que elijamos debemos referenciar lo siguiente:

Estilos:

* kendo.mobile.all.min.css

Javascript:

* jquery.min.js
* kendo.all.min.js

De esta forma entonces procederemos a crear un archivo .HTML y agregamos las referencias de esta manera:

```html
<!DOCTYPE html>
<html>
	<head>
		<title></title>
		<meta charset="utf-8" />

		<link rel="stylesheet" href="http://kendo.cdn.telerik.com/2016.2.714/styles/kendo.mobile.all.min.css">

		<script src="http://kendo.cdn.telerik.com/2016.2.714/js/jquery.min.js"></script>
		<script src="http://kendo.cdn.telerik.com/2016.2.714/js/kendo.all.min.js"></script>
		<script src="http://kendo.cdn.telerik.com/2016.2.714/js/cultures/kendo.culture.es-CO.min.js"></script>
		<script src="http://kendo.cdn.telerik.com/2016.2.714/js/messages/kendo.messages.es-CO.min.js"></script>
	</head>
	<body>
	</body>
</html>
```


Gracias por leer este HowTo.

[@jramirezdev](https://github.com/jramirezdev)
