//expresiones regulares
var expreNomyApe = /^[a-zA-ZÀ-ÿ\s]{1,40}$/;
var expredir = /^[a-zA-Z0-9_,_.À-ÿ\s]{1,40}$/;
var expretel = /^\d{7,14}$/;
var expremail = /^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$/;
let elementoSex = document.querySelector('input[name="sexo"]:checked');
let elementoPas = document.querySelector('input[name="pasatiempos"]:checked');
let elementoPasC = document.querySelector('input[name="pasatiemposC"]:checked');

function validacion(){
    
    if(document.frm.nombre.value.trim().length < 3 || !expreNomyApe.test(document.frm.nombre.value)){
        document.getElementById("nombre").focus();
        nom.style.display="";
        return false;
    }nom.style.display="none";

    if(document.frm.apellido.value.trim().length < 3 || !expreNomyApe.test(document.frm.apellido.value)){
        document.getElementById("apellido").focus();
        app.style.display="";
        return false;
    }app.style.display="none";

    if(document.frm.direccion.value.trim().length < 11 || !expredir.test(document.frm.direccion.value)){
        document.getElementById("direccion").focus();
        dir.style.display="";
        return false;
    }dir.style.display="none";

    if(document.frm.telefono.value.trim().length < 10 || !expretel.test(document.frm.telefono.value)){
        document.getElementById("telefono").focus();
        tel.style.display="";
        return false;
    }tel.style.display="none";

    if(document.frm.email.value.trim().length < 15 || !expremail.test(document.frm.email.value)){
        document.getElementById("email").focus();
        ema.style.display="";
        return false;
    }ema.style.display="none";

    if(!document.querySelector('input[name="sexo"]:checked')){
        document.getElementById("sexo").focus();
        sex.style.display="";
        return false;
    }sex.style.display="none";

    if(!document.querySelector('input[name="pasatiempos"]:checked')) {
        document.getElementById("pasatiempos").focus();
        pas.style.display="";
        return false;
    }pas.style.display="none";

    if(!document.querySelector('input[name="pasatiemposC"]:checked')) {
        document.getElementById("pasatiemposC").focus();
        paC.style.display="";
        return false;
    }paC.style.display="none";

    btn.style.display="";
    frm.submit();
}