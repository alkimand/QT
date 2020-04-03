.pragma library

const DataType = {"PERSENT_DATA_TYPE":1, "CURRENCY_DATA_TYPE":2, "DATE_DATA_TYPE":3, "YERS_DATA_TYPE":4,"CALENDAR_DATA_TYPE":5,"STRING_DATA_TYPE":6};
Object.freeze(DataType);

function valueToUserText(value, dataType){
    var userText = "";
    //console.log("valueToUserText=" + value)
    switch (dataType)   {
    case DataType.PERSENT_DATA_TYPE:
        userText = (value + "%").toString(10);
        break

    case DataType.CURRENCY_DATA_TYPE:
        userText = (value + " руб.").toString(10);
        break;

    case DataType.DATE_DATA_TYPE:
        userText = (value).toString(10);//convert
		userText = Qt.formatDate(userText, "dd.MM.yyyy");
        break;

    case DataType.YERS_DATA_TYPE:
        userText = (value + " years").toString(10);
        break;

    case DataType.STRING_DATA_TYPE:
        userText = (value).toString(10);
        break;
    }

    return userText;
}


