var newsReaderViewModel = kendo.observable({
    newsListView: null,
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
            console.log("News DataSource Error: " + kendo.stringify(e));
        }
    })
});

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
