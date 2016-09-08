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
	<ul id="newsList" data-role="listview" data-template="newsRowTemplate"></ul>
	
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

Con esto hemos terminado de definir parcialmente lo que será la UI de nuestra aplicación, el paso siguiente es comenzar a crear la lógica que consultará el servicio REST, esta lógica la escribiremos en javascript haciendo uso del framework MVVM que contiene Kendo.

Recordemos que cuando usamos MVVM lo común es crear un ViewModel por cada vista que tenga nuestra aplicación, para nuestro caso necesitamos 2, una para la vista Maestra y otro para la vista Detalle, si queremos podemos crear cada una en archivos javascript separados pero no esta mal que ambas estén en uno sólo, para nuestro caso crearemos un sólo archivo.

Pasemos entonces a crear un archivo llamado `newsReaderViewModel.js`, una vez creado definiremos el ViewModel para la vista maestra.

```javascript
var newsReaderViewModel = kendo.observable({
    newsReaderDS: new kendo.data.DataSource({
        transport: {
            read: {
                url: "https://api.myjson.com/bins/3k7i8",
                contentType: "application/json",
                type: "GET",
                dataType: "json"
            }
        },
        schema: {
            model: {
                id: "id",
                fields: {
                    id: {
                        type: "integer"
                    },
                    title: {
                        type: "string"
                    },
                    content: {
                        type: "string"
                    },
                    image: {
                        type: "string"
                    }
                }
            }
        },
        error: function(e) {
            console.log("newsReaderDS Error: " + kendo.stringify(e));
        }
    })
});
```

A continuación crearemos el ViewModel para la vista de detalle:

```javascript
var newsDetailViewModel = kendo.observable({
    content: "",
    imageUrl: "",
    openModal: function (e) {
        var link = e.target.context;
        var dataContent = $(link).attr("data-content");
        var dataImage = $(link).attr("data-image");

        newsDetailViewModel.set("content", dataContent);
        newsDetailViewModel.set("imageUrl", dataImage);
    },
    closeModal: function (e) {
        var modalView = e.sender.element.closest("[data-role=modalview]").data("kendoMobileModalView");
        modalView.close();
    }
});
```

El paso siguiente es agregar la referencia al archivo javascript en nuestra página html, esto lo podemos hacer en el head:

```html
<script src="newsReaderViewModel.js"></script>
```

Con la lógica ya definida el paso siguiente es retomar el html y agregar los atributos correspondientes para que el framework de MVVM pueda realizar los bindings correspondientes entre la UI y el ViewModel.

La vista maestro se define de la siguiente forma:

```html
<div id="home" data-role="view" data-layout="default" data-model="newsReaderViewModel">
	<ul id="newsList" data-role="listview" data-template="newsRowTemplate" data-bind="source: newsReaderDS"></ul>
	
	<script id="newsRowTemplate" type="text/x-kendo-template">
		<ul>
			<li><a data-rel="modalview" href="\#detail" data-content="#: content #" data-image="#: image #">#: title #</a></li>
		</ul>
	</script>
</div>
```

La vista detalle se define de la siguiente forma:

```html
<div id="detail" data-role="modalview" data-model="newsDetailViewModel" data-bind="events: {beforeOpen: openModal}">
	<div data-role="header">
		<div data-role="navbar">
			<a data-align="right" data-role="button" data-bind="events: {click: closeModal}">Cerrar</a>
		</div>
	</div>
	<div>
		<div>
			<img class="alertimage" data-bind="attr: { src: imageUrl }"/>
		</div>
		<div class="listviewdiv">
			<p class="item-info" data-bind="text: content"></p>
		</div>
	</div>
</div>
```

```html

```

Gracias por leer este HowTo.

[@jramirezdev](https://github.com/jramirezdev)
