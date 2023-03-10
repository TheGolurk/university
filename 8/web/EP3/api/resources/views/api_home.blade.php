<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>HOME</title>

    <style>
        @import url(https://fonts.googleapis.com/css?family=Montserrat);
        @-webkit-keyframes spin {
            0% {
                transform: rotate(0deg);
            }
            100% {
                transform: rotate(360deg);
            }
        }
        @keyframes spin {
            0% {
                transform: rotate(0deg);
            }
            100% {
                transform: rotate(360deg);
            }
        }
        @-webkit-keyframes color-1 {
            0% {
                background-color: #eb73b9;
            }
            100% {
                background-color: #17ead9;
            }
        }
        @keyframes color-1 {
            0% {
                background-color: #eb73b9;
            }
            100% {
                background-color: #17ead9;
            }
        }
        ::-moz-selection {
            background: #6078ea;
            color: white;
            text-shadow: none;
        }
        ::selection {
            background: #6078ea;
            color: white;
            text-shadow: none;
        }

        ::-webkit-selection {
            background: #6078ea;
            color: white;
            text-shadow: none;
        }

        body {
            font-family: "Montserrat", "Helevtica", sans-serif;
            position: relative;
            width: 100%;
            height: 100vh;
            background-color: #f2ecec;
            color: #4b4848;
            display: flex;
            justify-content: center;
            align-items: center;
            transition: background-color 1.25s ease-in-out;
        }
        body.is-focus {
            background-color: #17ead9;
        }

        .title-container {
            position: absolute;
            top: 38%;
            left: 50%;
            width: 80%;
            margin: 0 auto;
            text-align: center;
            overflow: hidden;
            transform: translate(-50%, -50%);
        }
        .title-container .title {
            transform: translateY(-100%);
            transition: transform 0.3s ease;
            transition-delay: 0.25s;
            margin: 0;
            color: #6078ea;
        }
        .title-container .title-down {
            transform: translateY(100%);
            transition: transform 0.3s ease;
            transition-delay: 0.25s;
            margin: 0;
            color: #6078ea;
        }
        .is-focus .title-container .title {
            transform: translateY(0);
        }
        .is-type .title-container .title-down {
            transform: translateY(-30px);
        }
        .is-type .title-container .title {
            transform: translateY(-100%);
        }

        .field-container {
            position: relative;
            padding: 0;
            margin: 0;
            border: 0;
            width: 330px;
            height: 40px;
        }

        .icons-container {
            position: absolute;
            top: 11px;
            right: -25px;
            width: 35px;
            height: 35px;
            overflow: hidden;
        }

        .icon-close {
            position: absolute;
            top: 2px;
            left: 2px;
            width: 75%;
            height: 75%;
            opacity: 0;
            cursor: pointer;
            transform: translateX(-200%);
            border-radius: 50%;
            transition: opacity 0.25s ease, transform 0.43s cubic-bezier(0.694, 0.048, 0.335, 1);
        }
        .icon-close:before {
            content: "";
            border-radius: 50%;
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            opacity: 0;
            border: 2px solid transparent;
            border-top-color: #6078ea;
            border-left-color: #6078ea;
            border-bottom-color: #6078ea;
            transition: opacity 0.2s ease;
        }
        .icon-close .x-up {
            position: relative;
            width: 100%;
            height: 50%;
        }
        .icon-close .x-up:before {
            content: "";
            position: absolute;
            bottom: 2px;
            left: 3px;
            width: 50%;
            height: 2px;
            background-color: #6078ea;
            transform: rotate(45deg);
        }
        .icon-close .x-up:after {
            content: "";
            position: absolute;
            bottom: 2px;
            right: 0px;
            width: 50%;
            height: 2px;
            background-color: #6078ea;
            transform: rotate(-45deg);
        }
        .icon-close .x-down {
            position: relative;
            width: 100%;
            height: 50%;
        }
        .icon-close .x-down:before {
            content: "";
            position: absolute;
            top: 5px;
            left: 4px;
            width: 50%;
            height: 2px;
            background-color: #6078ea;
            transform: rotate(-45deg);
        }
        .icon-close .x-down:after {
            content: "";
            position: absolute;
            top: 5px;
            right: 1px;
            width: 50%;
            height: 2px;
            background-color: #6078ea;
            transform: rotate(45deg);
        }
        .is-type .icon-close:before {
            opacity: 1;
            -webkit-animation: spin 0.85s infinite;
            animation: spin 0.85s infinite;
        }
        .is-type .icon-close .x-up:before, .is-type .icon-close .x-up:after {
            -webkit-animation: color-1 0.85s infinite;
            animation: color-1 0.85s infinite;
        }
        .is-type .icon-close .x-up:after {
            -webkit-animation-delay: 0.3s;
            animation-delay: 0.3s;
        }
        .is-type .icon-close .x-down:before, .is-type .icon-close .x-down:after {
            -webkit-animation: color-1 0.85s infinite;
            animation: color-1 0.85s infinite;
        }
        .is-type .icon-close .x-down:before {
            -webkit-animation-delay: 0.2s;
            animation-delay: 0.2s;
        }
        .is-type .icon-close .x-down:after {
            -webkit-animation-delay: 0.1s;
            animation-delay: 0.1s;
        }

        .icon-search {
            position: relative;
            top: 5px;
            left: 8px;
            width: 50%;
            height: 50%;
            opacity: 1;
            border-radius: 50%;
            border: 3px solid #c7d0f8;
            transition: opacity 0.25s ease, transform 0.43s cubic-bezier(0.694, 0.048, 0.335, 1);
        }
        .icon-search:after {
            content: "";
            position: absolute;
            bottom: -9px;
            right: -2px;
            width: 4px;
            border-radius: 3px;
            transform: rotate(-45deg);
            height: 10px;
            background-color: #c7d0f8;
        }

        .field {
            border: 0;
            width: 100%;
            height: 100%;
            padding: 10px 20px;
            background: white;
            border-radius: 3px;
            box-shadow: 0px 8px 15px rgba(75, 72, 72, 0.1);
            transition: all 0.4s ease;
        }
        .field:focus {
            outline: none;
            box-shadow: 0px 9px 20px rgba(75, 72, 72, 0.3);
        }
        .field:focus + .icons-container .icon-close {
            opacity: 1;
            transform: translateX(0);
        }
        .field:focus + .icons-container .icon-search {
            opacity: 0;
            transform: translateX(200%);
        }

        .button-56 {
            align-items: center;
            background-color: #fee6e3;
            border: 2px solid #111;
            border-radius: 8px;
            box-sizing: border-box;
            color: #111;
            cursor: pointer;
            display: flex;
            font-family: Inter,sans-serif;
            font-size: 16px;
            height: 48px;
            justify-content: center;
            line-height: 24px;
            max-width: 100%;
            padding: 0 25px;
            position: relative;
            text-align: center;
            text-decoration: none;
            user-select: none;
            -webkit-user-select: none;
            touch-action: manipulation;
        }

        .button-56:after {
            background-color: #111;
            border-radius: 8px;
            content: "";
            display: block;
            height: 48px;
            left: 0;
            width: 100%;
            position: absolute;
            top: -2px;
            transform: translate(8px, 8px);
            transition: transform .2s ease-out;
            z-index: -1;
        }

        .button-56:hover:after {
            transform: translate(0, 0);
        }

        .button-56:active {
            background-color: #ffdeda;
            outline: 0;
        }

        .button-56:hover {
            outline: 0;
        }

        @media (min-width: 768px) {
            .button-56 {
                padding: 0 40px;
            }
        }


    </style>

</head>
<body>

    <div id="resultado">
        @if(isset($resultado))
            <img src="{{ $resultado }}" alt="">
        @endif
    </div>

    <div class="title-container">
        <h1 class="title">It's all about context.</h1>
        <h1 class="title-down">Ajax'ing something...</h1>
    </div>

    <fieldset class="field-container">

        <form method="GET" action="{{ route('get_api_home') }}" id="login-form">
            <input id="busqueda" type="text" placeholder="Search..." class="field" name="busqueda"/>
            <div class="icons-container">
                <div class="icon-search"></div>
                <div class="icon-close">
                    <div class="x-up"></div>
                    <div class="x-down"></div>
                </div>
            </div>
        <br>
        <button class="button-56" role="button">Buscar</button>
        </form>

    </fieldset>

    <script !src="">
        $(document).on('ready', function() {

            $('.field').on('focus', function() {
                $('body').addClass('is-focus');
            });

            $('.field').on('blur', function() {
                $('body').removeClass('is-focus is-type');
            });

            $('.field').on('keydown', function(event) {
                $('body').addClass('is-type');
                if((event.which === 8) && $(this).val() === '') {
                    $('body').removeClass('is-type');
                }
            });

        });

        var form = document.getElementById("login-form");
        function handleForm(event) {
            event.preventDefault();
        }

        form.addEventListener('submit', handleForm);


    </script>

</body>
</html>
