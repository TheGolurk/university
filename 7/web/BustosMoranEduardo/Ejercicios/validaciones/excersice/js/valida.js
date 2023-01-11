function validacion(){
    if(document.getElementById("nombre").value.length==0){
        alert("Favor de escribir su Nombre");
        document.frm.nombre.focus();
        return false;
    }
    if(document.getElementById("apellidos").value.length==0){
        alert("Favor de escribir sus Apellidos");
        document.frm.apellidos.focus();
        return false;
    }
    if(document.getElementById("Direccion").value.length==0){
        alert("Favor de escribir su Direccion");
        document.frm.txtapm.focus();
        return false;
    }
    if(document.getElementById("Telefono").value.length==0){
        alert("Favor de escribir su Telefono");
        document.frm.Telefono.focus();
        return false;
    }
    if(document.getElementById("Movil").value.length==0){
        alert("Favor de escribir su Movil");
        document.frm.Movil.focus();
        return false;
    }
    frm.submit();
}