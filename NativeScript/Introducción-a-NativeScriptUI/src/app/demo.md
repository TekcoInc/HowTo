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
* Agregar el siguiente contenido dentro del elemento page:

```xml
<AbsoluteLayout width="210" height="310" style.backgroundColor="lightgray">
   <Label text="10, 10" left="10" top="10" width="90" height="90" backgroundColor="red"/>
   <Label text="110, 10" left="110" top="10" width="90" height="90" backgroundColor="green"/>
   <Label text="110, 110" left="110" top="110" width="90" height="90" backgroundColor="blue"/>
   <Label text="10, 110" left="10" top="110" width="90" height="90" backgroundColor="yellow"/>
   <Label text="10, 210" left="10" top="210" width="90" height="90" backgroundColor="pink"/>
   <Label text="10, 110" left="110" top="210" width="90" height="90" backgroundColor="white"/>
 </AbsoluteLayout>
```

## DockLayout

* Navegar al archivo main-page.xml
* Agregar el siguiente contenido dentro del elemento page:

```xml
<DockLayout width="210" height="210" style.backgroundColor="lightgray" stretchLastChild="false">
    <Label text="left" dock="left" width="60" backgroundColor="red"/>
    <Label text="top" dock="top" height="60" backgroundColor="green"/>
    <Label text="right" dock="right" width="60" backgroundColor="blue"/>
    <Label text="bottom" dock="bottom" height="60" backgroundColor="yellow"/>
</DockLayout>
```

## GridLayout

* Navegar al archivo main-page.xml
* Agregar el siguiente contenido dentro del elemento page:

```xml
<GridLayout columns="50, auto, *" rows="50, auto, *" width="210" height="210" 
    style.backgroundColor="lightgray" >
    <Label text="Label 1" row="0" col="0" backgroundColor="red"/>
    <Label text="Label 2" row="0" col="1" colSpan="2" backgroundColor="green"/>
    <Label text="Label 3" row="1" col="0" rowSpan="2" backgroundColor="blue"/>
    <Label text="Label 4" row="1" col="1" backgroundColor="yellow"/>
    <Label text="Label 5" row="1" col="2" backgroundColor="orange"/>
    <Label text="Label 6" row="2" col="1" backgroundColor="pink"/>
    <Label text="Label 7" row="2" col="2" backgroundColor="purple"/>
</GridLayout>
```

## StackLayout

* Navegar al archivo main-page.xml
* Agregar el siguiente contenido dentro del elemento page:

```xml
<StackLayout orientation="vertical" width="210" height="210" style.backgroundColor="lightgray">
    <Label text="Label 1" width="50" height="50" backgroundColor="red"/>
    <Label text="Label 2" width="50" height="50" backgroundColor="green"/>
    <Label text="Label 3" width="50" height="50" backgroundColor="blue"/>
    <Label text="Label 4" width="50" height="50" backgroundColor="yellow"/>
</StackLayout>
```

## WrapLayout

* Navegar al archivo main-page.xml
* Agregar el siguiente contenido dentro del elemento page:

```xml
<WrapLayout orientation="horizontal" width="210" height="210" style.backgroundColor="lightgray">
    <Label text="Label 1" width="70" height="70" backgroundColor="red"/>
    <Label text="Label 2" width="70" height="70" backgroundColor="green"/>
    <Label text="Label 3" width="70" height="70" backgroundColor="blue"/>
    <Label text="Label 4" width="70" height="70" backgroundColor="yellow"/>
</WrapLayout>
```

## ActionBar

* Navegar al archivo main-page.xml
* Agregar el siguiente contenido dentro del elemento page y antes del layout:

```xml
<ActionBar title="NativeScript UI Basics">
  <ActionItem tap="onShare"
      android.systemIcon="ic_menu_share" android.position="actionBar"/>
  <ActionItem tap="onNew"
      text="New item" android.position="popup"/>
  <ActionItem tap="onViewAll"
      text="View All" android.position="popup"/>
</ActionBar>
```

* Agregar en **app.js** el siguiente código JavaScript:

```javascript
var dialogs = require("ui/dialogs");

function onNew(args) {
    dialogs.alert({
        title: "NativeScript UI Bascis",
        message: "Welcome to NativeScript, learn how to create native mobile applications for Android and iOS",
        okButtonText: "OK"
    });
}

function onViewAll(args) {
    dialogs.alert({
        title: "NativeScript UI Bascis",
        message: "Welcome to NativeScript, learn how to create native mobile applications for Android and iOS",
        okButtonText: "OK"
    });
}

function onShare(args) {
    dialogs.alert({
        title: "NativeScript UI Bascis",
        message: "Welcome to NativeScript, learn how to create native mobile applications for Android and iOS",
        okButtonText: "OK"
    });
}

exports.onNew = onNew;
exports.onViewAll = onViewAll;
exports.onShare = onShare;
```

## Componentes

* En **main.page.js** cambiar el layout actual por un GridLayout, y adicionar una caja de texto, un botón y un elemento WebView:

```xml
<GridLayout columns="*,auto" rows="auto, *" width="100%" height="100%" 
    style.backgroundColor="lightgray" >
    <TextView text="{{ pageurl }}" row="0" col="0" />
    <Button col="1" tap="buttonTap" text="Load Page" />
    <WebView src="{{ loadPage }}" row="1" colSpan="2"/>
</GridLayout>
```

* En **main-page.js** el código debe verse:

```javascript
var dialogs = require("ui/dialogs");
var observable = require("data/observable").Observable;

var page;
var mainViewModel = new observable({
    pageurl: "https://www.nativescript.org/",
    loadPage: "https://www.nativescript.org/"
});

function pageLoaded(args) {
    page = args.object;
    page.bindingContext = mainViewModel;
}

function onNew(args) {
    dialogs.alert({
        title: "NativeScript UI Bascis",
        message: "Welcome to NativeScript, learn how to create native mobile applications for Android and iOS",
        okButtonText: "OK"
    });
}

function onViewAll(args) {
    dialogs.alert({
        title: "NativeScript UI Bascis",
        message: "Welcome to NativeScript, learn how to create native mobile applications for Android and iOS",
        okButtonText: "OK"
    });
}

function onShare(args) {
    dialogs.alert({
        title: "NativeScript UI Bascis",
        message: "Welcome to NativeScript, learn how to create native mobile applications for Android and iOS",
        okButtonText: "OK"
    });
}

function buttonTap(args){
    mainViewModel.loadPage = mainViewModel.pageurl;
    dialogs.alert({
        title: "NativeScript UI Bascis",
        message: "Loading page: " + mainViewModel.pageurl,
        okButtonText: "OK"
    });
}

exports.onNew = onNew;
exports.onViewAll = onViewAll;
exports.onShare = onShare;
exports.buttonTap = buttonTap;
exports.pageLoaded = pageLoaded;
```

![Demo NativeScript WebView](http://res.cloudinary.com/julitogtu/image/upload/v1473368724/webview_yskxls.jpg)