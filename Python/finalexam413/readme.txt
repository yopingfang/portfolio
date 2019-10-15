Welcome to the 413 final exam!  Here's the rules:

1. 4 hours maximum.  You must turn in the final 4 hours from the time you open any
   other file in this project.  When your 4 hours is finished, zip and submit to the Grader.

2. You may use old projects, internet searches, StackOverflow, and anything else that is not
   help from live human beings.

3. Everything you need to do is listed in the bullet points below.  You can also
   search the project for `TODO:`.

4. Do not look at the code (beyond this file) until you are ready to start the exam.
   Once you open the code files, your 4 hours starts!


-------------------------------------------------------------------------------------------


    You:    "I wish the Final had never come to me. I wish none of this had happened."

    Dr. A:  "So do all who live to see such times; but that is not for them to decide.
            All we have to decide is what to do with the 4 hours that is given to us."

            "And so it begins, the great Final Exam of our time..."

                                     //
                                     //
                                   _ //
                                .' . // '.
                               '_ '_\/_'  `_
                               .  . \\  .  .
                              .==. ` \\' .'
                       .\|   //bd\\   \,
                       \_'`._\\__//_.'`.;
                         `.__      __,' \\
                             |    |      \\
                             |    |       `
                             |    |
                             |    |
                             |____|
                            =='  '==

-------------------------------------------------------------------------------------------


- Run the project
    * You should be able to run the project immediately and load http://localhost:8000/
      This is a great way to test whether things are working with Python/Django/DMP.


- Make migrations and migrate
    * see homepage/models.py for the CurrencyPrice model
    * consider it finished (no additional coding required)


- Load the data into the database
    * you can use either data.csv or data.json to load the data - the two files
      contain the same data


- homepage/views/index.html: Set the title of the index page
    to "Crypto Search" by overriding the title block from base.htm.
    * Upon reload, your browser tab should show "Crypto Search"
      instead of "413 Final".
    * Do not make any changes to base.htm for this step.


- homepage/views/index.py: Add four fields to the form
    symbol is a choice field
        (choices are already listed in index.py)
    start_date is a date field (not a combined date/time field)
        (this is the starting search date in the format `yyyy-mm-dd`)
    end_date is a date field (not a combined date/time field)
        (this is the ending search date in the format `yyyy-mm-dd`)
    sort is a choice field
        (choices are already listed in index.py)


- homepage/views/index.py: If the form is valid, query and order the CurrencyPrice table
    based on the parameters sent in the form.  Show this list.
    * you don't have to clean any fields - assume the user enters data correctly


- homepage/templates/index.html: print the results as a <table> with three columns:
    ===============================
    |  Symbol  |  Date  |  Price  |
    ===============================
    (data continues here)


- homepage/styles/index.css: add the following styles to the form_container:
    * float the container on the left side of the page
    * give the container a 1px border, solid line, #CCCCCC color
    * give the container a 40px margin on the right side
    * give the container a 12px padding on all sides
    * set the width of the container to 500px
    * give the container a 8px radius


- homepage/styles/index.css: add the following styles to the table:
    * Cells should have a 1px border, solid line, #CCCCCC color
    * Cells should have 12px of padding on all sides
    * The header row should be bold text with no borders


- homepage/views/lowest.py: query the lowest (oldest) date for a symbol.
    (hint: google how to do a SELECT MIN query with django)
    * Create this file in the project.
    * The symbol is sent as a url parameter, such as:
        http://localhost:8000/homepage/lowest/ETH
        http://localhost:8000/homepage/lowest/BTC
    * Return an HttpResponse with the date string directly from the view
    * All that is needed here is a process_request() method (no form, no template),
      but you are welcome to use a template if you want.
    * Test by typing the url into your browser.
        (you should get a single date string back)
    * You can assume the url will be sent correctly - you don't have to worry
      about errors like bad or missing symbol codes.


- homepage/scripts/index.js: Ajax for lowest
    * When the `Set Starting Date` button is clicked, call (via ajax) the url:
        http://localhost:8000/homepage/lowest/ETH
      where ETH is the currently-selected symbol (BTC, ETH, or XRP)
        (you'll have to retrieve the currently-selected symbol from the form first)
    * When the success response comes back, set the value of the starting date field


- homepage/views/highest.py: query the highest (newest) date for a symbol.
    * Create this file in the project.
    * This is the exact same as lowest.py, but it does a
      SELET MAX query with django.


- homepage/scripts/index.js: Ajax for highest
    * This is the exact same process you did with the lowest, only with
      the `Set Ending Date` button and setting the ending date field.
