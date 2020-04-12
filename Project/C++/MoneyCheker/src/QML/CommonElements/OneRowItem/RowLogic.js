.pragma library

const DataType = {"PERSENT_DATA_TYPE":1, "CURRENCY_DATA_TYPE":2, "DATE_DATA_TYPE":3, "YERS_DATA_TYPE":4,"CALENDAR_DATA_TYPE":5,"STRING_DATA_TYPE":6};
Object.freeze(DataType);

function valueToUserText(value, dataType, language="en_EN"){
    var userText = "";
    //console.log("valueToUserText=" + value)
    switch (dataType)   {
    case DataType.PERSENT_DATA_TYPE:
        userText = (number_format(value, 3, '.', ' ') + "%").toString(10);
        break
		
    case DataType.CURRENCY_DATA_TYPE:
        userText = (number_format(value, 0, '.', ' ') + " руб.").toString(10);
        break;

    case DataType.DATE_DATA_TYPE:
		console.log("value+" + value);
		userText = value.toLocaleString(Qt.locale(language), "MMM, yyyy")
        console.log("userText+" + userText);
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

function number_format(number, decimals, dec_point, thousands_sep) {
    number = (number + '').replace(/[^0-9+\-Ee.]/g, '');
    var n = !isFinite(+number) ? 0 : +number,
        prec = !isFinite(+decimals) ? 0 : Math.abs(decimals),
        sep = (typeof thousands_sep === 'undefined') ? ',' : thousands_sep,
        dec = (typeof dec_point === 'undefined') ? '.' : dec_point,
        s = '',
        toFixedFix = function (n, prec) {
            var k = Math.pow(10, prec);
            return '' + Math.round(n * k) / k;
        };
    s = (prec ? toFixedFix(n, prec) : '' + Math.round(n)).split('.');
    if (s[0].length > 3) {
        s[0] = s[0].replace(/\B(?=(?:\d{3})+(?!\d))/g, sep);
    }
    if ((s[1] || '').length < prec) {
        s[1] = s[1] || '';
        s[1] += new Array(prec - s[1].length + 1).join('0');
    }
    return s.join(dec);
}

function formatDate(date){

return ('0' +(date.getDate())).slice(-2)+'.'+ ('0' +(date.getMonth()+1)).slice(-2)+'.'+('0'+date.getFullYear()).slice(-2);

}

