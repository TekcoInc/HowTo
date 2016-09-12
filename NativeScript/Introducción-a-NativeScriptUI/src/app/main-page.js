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