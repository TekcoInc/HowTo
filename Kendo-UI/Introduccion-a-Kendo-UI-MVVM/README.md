# Introducción a Kendo UI MVVM

Descripción | Nivel
------------ | ------------
En este HowTo haremos un formulario de recolección de datos y lo asociaremos a un model con MVVM. | Principiante

El primer paso para poder trabajar con Kendo UI MVVM es colocar las referencias correspondintes para los estilos y las librería javascript, esto se puede realizar de dos formas:

1) Descargar el paquete de Kendo y referenciar los archivos locales.

2) Utilizar la red CDN de Telerik (requiere conexión a internet 100%).

Sea cual sea la opción que elijamos debemos referenciar lo siguiente:

Javascript:

* jquery.min.js
* kendo.all.min.js

De esta forma entonces procederemos a crear un archivo .HTML y agregamos las referencias de esta manera:

```html
<!DOCTYPE html>
<html>
	<head>
    <title>Mi formulario con Kendo UI MVVM</title>
    <meta charset="utf-8" />
    
    <link href="https://kendo.cdn.telerik.com/2016.3.914/styles/kendo.common.min.css" rel="stylesheet" type="text/css" />
    <link href="https://kendo.cdn.telerik.com/2016.3.914/styles/kendo.default.min.css" rel="stylesheet" type="text/css" />

    <script src="https://kendo.cdn.telerik.com/2016.3.914/js/jquery.min.js"></script>
    <script src="https://kendo.cdn.telerik.com/2016.3.914/js/kendo.all.min.js"></script>
    <script src="https://kendo.cdn.telerik.com/2016.3.914/js/cultures/kendo.culture.es-CO.min.js"></script>
    <script src="https://kendo.cdn.telerik.com/2016.3.914/js/messages/kendo.messages.es-CO.min.js"></script>
    <script src="myViewModel.js"></script>
	</head>
	<body>
	</body>
</html>
```
Ahora definimos la estructura básica del formulario HTML.

```html
<!DOCTYPE html>
<html>
<head>
    <title>Mi formulario con Kendo UI MVVM</title>
    <meta charset="utf-8" />
    
    <link href="https://kendo.cdn.telerik.com/2016.3.914/styles/kendo.common.min.css" rel="stylesheet" type="text/css" />
    <link href="https://kendo.cdn.telerik.com/2016.3.914/styles/kendo.default.min.css" rel="stylesheet" type="text/css" />

    <script src="https://kendo.cdn.telerik.com/2016.3.914/js/jquery.min.js"></script>
    <script src="https://kendo.cdn.telerik.com/2016.3.914/js/kendo.all.min.js"></script>
    <script src="https://kendo.cdn.telerik.com/2016.3.914/js/cultures/kendo.culture.es-CO.min.js"></script>
    <script src="https://kendo.cdn.telerik.com/2016.3.914/js/messages/kendo.messages.es-CO.min.js"></script>
    <script src="myViewModel.js"></script>
</head>
<body>
    <div class="form">
        <h3>Mis gastos</h3>
        <dl>
            <dt>Tipo Gasto</dt>
            <dd>
                <select id="tipoGasto">
                    <option value="comida">Comida</option>
                    <option value="compras">Compras</option>
                    <option value="facturas">Facturas</option>
                </select>
            </dd>
            <dt>Valor</dt>
            <dd><input id="valor" type="number" /></dd>

            <dt>&nbsp;</dt>
            <dd><button id="add" class="k-button">Agregar</button></dd>
        </dl>
    </div>

    <table id="gastos"></table>
</body>
</html>
```
El paso siguiente es definir un ViewModel, esto es un objeto Observable que permite realizar binding de propiedades y funciones en dos vías: Si cambia en el html cambia en el js y viceversa.

Creamos entonces un archivo un archivo llamado `myViewModel.js`, una vez creado definiremos el ViewModel para la vista.

```javascript
viewModel = kendo.observable({
    tiposDeGastos: [],
    tipoDeGastoSeleccionado: "",
    cantidadDigitada: 0,
    agregar: function (e) { },
    gastosAgregados: []
});

kendo.bind($("#miFormulario"), viewModel);
```
Inicialmente el ViewModel contendrá datos vacíos, pero en algunos casos como el nuestro tendrá valores por defecto, en este caso serán los tipos de gastos que se listarán en el dropdown. Sabiendo que esto es un pre-requisito procederemos a agregarlos.

```javascript
viewModel = kendo.observable({
    tiposDeGastos: [
        { nombre: "Comida", valor: "comida" },
        { nombre: "Compras", valor: "compras" },
        { nombre: "Facturas", valor: "facturas" }
    ],
    tipoDeGastoSeleccionado: "",
    cantidadDigitada: 0,
    agregar: function (e) { },
    gastosAgregados: []
});

kendo.bind($("#miFormulario"), viewModel);
```

Una vez agregado el listado en el ViewModel no es necesario que los elementos estén "quemados" en el HTML por tanto los eliminaremos.

```html
<!DOCTYPE html>
<html>
<head>
    <title>Mi formulario con Kendo UI MVVM</title>
    <meta charset="utf-8" />
    
    <link href="https://kendo.cdn.telerik.com/2016.3.914/styles/kendo.common.min.css" rel="stylesheet" type="text/css" />
    <link href="https://kendo.cdn.telerik.com/2016.3.914/styles/kendo.default.min.css" rel="stylesheet" type="text/css" />

    <script src="https://kendo.cdn.telerik.com/2016.3.914/js/jquery.min.js"></script>
    <script src="https://kendo.cdn.telerik.com/2016.3.914/js/kendo.all.min.js"></script>
    <script src="https://kendo.cdn.telerik.com/2016.3.914/js/cultures/kendo.culture.es-CO.min.js"></script>
    <script src="https://kendo.cdn.telerik.com/2016.3.914/js/messages/kendo.messages.es-CO.min.js"></script>
    <script src="myViewModel.js"></script>
</head>
<body>
    <div id="miFormulario" class="form">
        <h3>Mis gastos</h3>
        <dl>
            <dt>Tipo Gasto</dt>
            <dd>
                <select id="tipoGasto"></select>
            </dd>
            <dt>Valor</dt>
            <dd><input id="valor" type="number" /></dd>

            <dt>&nbsp;</dt>
            <dd><button id="agregar" class="k-button">Agregar</button></dd>
        </dl>
    </div>

    <table id="gastos"></table>
</body>
</html>
```
Ahora procederemos a hacer el primer enlace (binding) entre la vista (HTML) y el ViewModel, para este primer caso haremos uso de "data-attributes" en el HTML, donde podremos indicar qué propiedades del elemento HTML serán enlazadas con las correspondientes del ViewModel, algunos atributos no necesariamente están definidos en el ViewModel.

```html
<select id="tipoGasto" data-role="dropdownlist" data-bind="source: tiposDeGastos, value: tipoDeGastoSeleccionado" data-text-field="nombre" data-value-field="valor"></select>
```

Aquí podemos notar los siguientes "data-attributes":

* data-role
* data-bind
* data-text-field
* data-value-field

En este caso todos estos atributos son propios de Kendo UI, específicamente del Widget DropDownList, pero pueden existir otros casos donde los atributos a los que se le hace binding sean nativos de HTML.

Ahora realizaremos el binding para el input donde se ingresará la cantidad.

```html
<input id="valor" type="text" data-role="numerictextbox" data-bind="value: cantidadDigitada" />
```

Aquí vemos que los "data-attributes" asignados fueron:

* data-role
* data-bind

Con la diferencia que ahora estamos creando un widget de tipo "numerictextbox" y asignando su propiedad "value".

El siguiente elemento que nos falta enlazar es el botón, lo haremos de la siguiente forma:

```html
<button id="agregar" class="k-button" data-bind="click: agregar">Agregar</button>
```

En este ejemplo podemos ver que no estamos creando ningún widget de Kendo, simplemente hacemos binding al evento click del elemento "<button>" de HTML.

El último elemento que nos falta es un widget para mostrar los elementos que vamos agregando, para esto usaremos el widget Grid de Kendo.

```html
<table id="gastos" data-role="grid" data-sortable="true" data-bind="source: gastosAgregados" data-columns='["nombre", "valor"]'></table>
```

Aquí podemos observar dos nuevos atributos:

* data-sortable
* data-columns

Son asignados en este caso ya que son propiedades del Grid de Kendo.

Para finalizar el ejemplo nos falta agregar la lógica de inserción de nuevos registros a la colección.

```javascript
    agregar: function (e) {
        var list = this.get("gastosAgregados");
        
        list.push({
            nombre: this.get("tipoDeGastoSeleccionado"),
            valor: this.get("cantidadDigitada")
        });

        this.set("tipoDeGastoSeleccionado", "comida");
        this.set("cantidadDigitada", 0);
    }
```

Ejecuta la aplicación y prueba :)

Gracias por leer este HowTo.

[@jramirezdev](https://github.com/jramirezdev)
