$(function (context) {
    return function () {

        $('#start_date_button').click(function() {
            var symbol = document.getElementById("symbol-list").value;
            $.ajax({
                url: "/homepage/lowest/" + symbol,
            }).done(function(content){
                $('#start-date').val(content);
            });
        });

        $('#end_date_button').click(function() {
            var symbol = document.getElementById("symbol-list").value;
            $.ajax({
                url: "/homepage/highest/" + symbol,
            }).done(function(content){
                $('#end-date').val(content);
            });
        });

    }
}(DMP_CONTEXT.get()))