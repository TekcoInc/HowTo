## Usando los controles desde C++/CLI

¡Hola a tod@s!

En este HowTo veremos cómo podemos trabajar con la suite UI for WinForms desde aplicaciones escritas con C++/CLI.

Lo primero que debes hacer es instalar el paquete de los controles, para esto puedes ir al website de Telerik y descargar el instalador Universal, es un .exe con el cual se pueden instalar todos los productos de ellos, estos controles tienen un soporte bastante amplio para versiones del framework .NET y también de Visual Studio.

Una vez instalados los controles dentro de Visual Studio encontrarás en la lista de templates una sección llamada Telerik, y un sub-menú que indica los tipos de controles que hemos instalado, veríamos una pantalla muy similar a la siguiente:

![](http://jorgeramirez.ninja/content/images/2015/11/Capture1.PNG)

Esto es un buen indicador de que las librerías se han instalado correctamente, pero como se puede ver en la imágen, los templates sólo aplican para C# y Visual Basic, entonces desafortunadamente no los podemos usar.

Aunque no podamos usar estos templates es posible usar los controles, para esto vamos a crear un nuevo proyecto usando el template *CLR Empty Project*.

![](http://jorgeramirez.ninja/content/images/2015/11/Capture2.PNG)

Una vez creado el proyecto debemos agregar las referencias a las dll's de Telerik, para esto buscamos en el proyecto la sección *References* damos clic derecho y seleccionamos *Add Reference...*

![](http://jorgeramirez.ninja/content/images/2015/11/Capture3.PNG)

En el diálogo de agregar referencia debemos seleccionar la sección *Browse* y allí buscar el folder donde se ecuentran las dll's, este folder típicamente es: C:\Program Files (x86)\Telerik\UI for WinForms Q3 2015\Bin40

> La ruta del folder cambia dependiendo de la versión de los controles que tengas instalada

![](http://jorgeramirez.ninja/content/images/2015/11/Capture4.PNG)

Allí debemos agregar las siguientes dll's:

- TelerikCommon
- Telerik.WinControls
- Telerik.WinControls.UI

Una vez agregadas las dll's el paso siguiente es crear un formulario, para esto seleccionamos el proyecto, damos clic derecho opción *Add-->New Item* o simplemente *CTRL+SHIFT+A* allí seleccionamos el menú *UI* y la plantilla *Windows Form*

![](http://jorgeramirez.ninja/content/images/2015/11/Capture5.PNG)

Una vez creado el formulario, veremos como se han agregado un par de archivos .h/.cpp correspondientes al código del formulario así como también varias referencias a librerías del .NET framework.

![](http://jorgeramirez.ninja/content/images/2015/11/Capture6.PNG)

En la parte derecha podemos ver un error bastante desagradable correspondiente al diseñador de windows forms, puede que esto no suceda en tu máquina, pero de suceder la solución es muy simple, cierra el archivo *MyForm.h* y vuélvelo a abrir... el diseñador funcionará de forma mágica #GraciasMicrosoft :stuck_out_tongue:

![](http://jorgeramirez.ninja/content/images/2015/11/Capture7.PNG)

Ahora bien, para lograr que el formulario sea acorde a los formularios de Telerik, debemos ir al archivo *MyForm.h* y agregar el namespace *Telerik::WinControls::UI* y hacer que la clase *MyForm* herede de *RadForm*, el código se vería así:

[](http://jorgeramirez.ninja/content/images/2015/11/Capture8.PNG)

Con este ajuste podremos ver que el formulario ha cambiado en su apariencia, ahora tiene el skin por defecto que aplica Telerik para los formularios.

![](http://jorgeramirez.ninja/content/images/2015/11/Capture9.PNG)

Para trabajar en el diseño gráfico del formulario podemos hacerlo de 2 formas, la primera sería agregar nuestros controles desde el código y la segunda sería haciendo uso de los controles disponibles en el *Toolbox*, gracias a que hemos instalado los controles usando el instalador de Telerik, ahora en el *Toolbox* podemos ver la lista de todos los controles de winforms disponibles.

![](http://jorgeramirez.ninja/content/images/2015/11/Capture10.PNG)

> ¡Atención! Una anotación importante, todos los cambios que hagamos usando el diseñador se verán reflejados únicamente en el archivo .h, así pues, en el header no sólo estarían las declaracions sino también las implementaciones, esto no es buena práctica, lo recomendado sería usar el diseñador y posteriormente hacer los cambios adecuados para que tanto declaraciones como implementaciones estén en los archivos correspondientes, en este post lo dejaremos tal como lo hace el diseñador.

Ahora usando el diseñador voy a arrastrar tres controles desde el *Toolbox*, un RadTextBox, un RadButton y un RadDesktopAlert. Usando el panel de propiedades cambiaré el texto del botón a "Click Me!", en este momento el formulario se debe ver así:

![](http://jorgeramirez.ninja/content/images/2015/11/Capture12.PNG)

El control RadDesktopAlert nos permite mostrar notificaciones en el escritorio del cliente, por defecto se mostrarán en la esquina inferior derecha, esto puede ser modificado por código o desde las propiedades del control.

Ahora como podrás imaginar, lo que vamos a hacer es que al dar clic en el botón se muestre una notificación con el texto que hayamos introducido en la caja de texto. Para esto procederemos a dar doble clic en el botón, esto creará el handler correspondiente para el evento Click del botón, allí escribiremos el código correspondiente para leer el texto y mostrarlo en la notificación.

```cpp
System::Void radButton1_Click(System::Object^  sender, System::EventArgs^  e) {

		radDesktopAlert1->ContentText = radTextBox1->Text;

		radDesktopAlert1->Show();
}
```

Ahora crearemos un nuevo archivo de código donde escribiremos la función de entrada a nuestro programa, para esto seleccionamos el proyecto, damos clic derecho opción *Add-->New Item* o simplemente *CTRL+SHIFT+A* allí seleccionamos el menú *Code* y la plantilla *C++ File(.cpp)* llamaremos al archivo *Main.cpp*

En el archivo *Main.cpp* lo que haremos es indicar que el formulario se debe iniciar al lanzar el programa, esto lo logramos con el siguiente código:

```cpp
#include "MyForm.h"

using namespace System;
using namespace Projectcpp;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());
}
```

El último paso es indicarle al Linker cuál es el punto de entrada del programa y con cuál sub-sistema debería trabajar, esto lo hacemos en propiedades del proyecto:

![](http://jorgeramirez.ninja/content/images/2015/11/Capture14.PNG)

El SubSystem debe ser Windows ya que la aplicación cuenta con interfaz gráfica:

![](http://jorgeramirez.ninja/content/images/2015/11/Capture13.PNG)

En Entry Point debemos escribir el nombre de la función que será nuestro punto de entrada, para nuestro caso el nombre es "Main", si tuviera otro nombre lo deberíamos especificar allí.

Hecho esto podemos iniciar el Windows Debugger, veremos el formulario, procedemos a escribir un texto y dar clic en el botón, se mostrará una hermosa notificación en la esquina inferior derecha de nuestro escritorio:

![](http://jorgeramirez.ninja/content/images/2015/11/Capture16.PNG)

Para finalizar, no olvides que Telerik cuenta con una amplia documentación en línea y muchos foros de soporte.

Happy Coding++

@jramirezdev
