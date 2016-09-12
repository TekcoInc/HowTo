# An overview of NativeScript UI

## Creación de la aplicación

```javascript
tns create DemoNativeScriptUI --template tns-template-blank
cd DemoNativeScriptUI
tns platform add android
```

##  Revisar el archivo app.js

```javascript
var application = require("application");
application.cssFile = "./app.css";
application.start({ moduleName: "main-page" });
```

## AbsoluteLayout

* Navegar al archivo main-page.xml
* 