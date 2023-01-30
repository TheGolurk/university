(async function execute() {
    const res = await fetch('https://jsonplaceholder.typicode.com/posts')
        .then(response => {
            return response.json();
        })
        .catch(err => {
            console.error(err);
            alert(err);
        })

    const table = document.getElementById("tabla-datos");
    res.forEach(item => {
        let row = table.insertRow();

        let idVenta = row.insertCell(0);
        idVenta.innerHTML = item.userId;

        let idUsuario = row.insertCell(1);
        idUsuario.innerHTML = item.id;

        let idPro = row.insertCell(2);
        idPro.innerHTML = item.title;

        let total = row.insertCell(3);
        total.innerHTML = item.body;

       
    });

})()