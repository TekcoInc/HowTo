# Introducción a Hybrid UI

Descripción | Nivel
------------ | ------------
En este HowTo haremos un ejemplo básico con Kendo Hybrid UI. | Principiante

*Lector de Noticias*

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

El paso siguiente es definir un Layout, el layout es básicamente la estructura de nuestro sitio, normalmente en un layout se define el encabezado (header) y el pie de página (footer).

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
		<section data-role="layout" data-id="default">
			<header data-role="header">
				<div data-role="navbar">
					<a data-role="button" data-align="left" data-icon="more"></a>
					Lector de Noticias
					<a data-role="button" data-align="right" data-icon="about"></a>
				</div>
			</header>
			<!--El contenido de la vista será cargado acá-->
			<footer data-role="footer">
				<div data-role="tabstrip">
					<a href="#home" data-icon="home">Inicio</a>
				</div>
			</footer>
		</section>
	</body>
</html>
```

Como podemos suponer el paso siguiente es crear una vista, como en cualquier otro sitio web una vista es el contenedor de los controles HTML que realizarán una funcionalidad específica, en este caso la vista será el contenedor del listado de las noticias.

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
		<div id="home"
			 data-role="view"
			 data-layout="default">
			 <p>Hola Mundo</p>
		</div>
		
		<section data-role="layout" data-id="default">
			<header data-role="header">
				<div data-role="navbar">
					<a data-role="button" data-align="left" data-icon="more"></a>
					Lector de Noticias
					<a data-role="button" data-align="right" data-icon="about"></a>
				</div>
			</header>
			<!--El contenido de la vista será cargado acá-->
			<footer data-role="footer">
				<div data-role="tabstrip">
					<a href="#home" data-icon="home">Inicio</a>
				</div>
			</footer>
		</section>
	</body>
</html>
```

Tanto las vistas como los layout deben tener un role y un id, de esta forma se podrá asociar el contenedor con su contenido. En el ejemplo anterior vemos que esto se logra con los atributos `data-role` y `data-id`.

Si en este momento corremos la aplicación, podremos ver... ¡Nada!, esto se debe a que formalmente no hemos inicializado la aplicación para ser una aplicación Kendo Hybrid UI, la inicialización la logramos llamando una función de la librería de Kendo.

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
		<div id="home"
			 data-role="view"
			 data-layout="default">
			 <p>Hola Mundo</p>
		</div>
		
		<section data-role="layout" data-id="default">
			<header data-role="header">
				<div data-role="navbar">
					<a data-role="button" data-align="left" data-icon="more"></a>
					Lector de Noticias
					<a data-role="button" data-align="right" data-icon="about"></a>
				</div>
			</header>
			<!--El contenido de la vista será cargado acá-->
			<footer data-role="footer">
				<div data-role="tabstrip">
					<a href="#home" data-icon="home">Inicio</a>
				</div>
			</footer>
		</section>
		
		<script>
			var app = new kendo.mobile.Application();
		</script>
	</body>
</html>
```
En este momento si corremos la aplicación podremos ver el mensaje "Hola Mundo" además de algunos otros aspectos gráficos que Kendo Hybrid UI automáticamente coloca para mejorar la UI de nuestra aplicación.

El propósito de esta aplicación es listar un conjunto de noticias provenientes de un servicio REST y al dar clic/tab en una, mostrar un modal con el detalle de la misma. De esta forma nuestra aplicación estará conformada por 2 vistas.

Continuaremos modificando la vista `home` para incluir un widget que mostrará la lista de noticias.

```html
<div id="home" data-role="view" data-layout="default">
	<ul id="newsList" data-role="listview"></ul>
	
	<script id="newsRowTemplate" type="text/x-kendo-template">
		<ul>
			<li><a data-rel="modalview" data-role="button" ></a></li>
		</ul>
	</script>
</div>
```

Ahora agregaremos la vista para el detalle de la noticia.

```html
<div id="detail" data-role="modalview">
	<div data-role="header">
		<div data-role="navbar">
			<a data-align="right" data-role="button">Cerrar</a>
		</div>
	</div>
	<div>
		<div>
			<img class="alertimage"/>
		</div>
		<div class="listviewdiv">
			<p class="item-info"></p>
		</div>
	</div>
</div>
```

```html
```

Gracias por leer este HowTo.

[@jramirezdev](https://github.com/jramirezdev)
