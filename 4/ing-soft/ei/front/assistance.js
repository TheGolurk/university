const plate = getCookie('matricula');
getCurrentStudent();

function getCurrentStudent() {
    const url = `http://127.0.0.1:3000/student`;

    fetch(url, {
        method: 'GET',
        credentials: 'include'
        })
        .then(res => {
            if (res.status != 200) {
                throw new Error('An error ocurred in login')
            }
            res.json().then(r => {
                document.getElementById('title_name').innerHTML = r.matricula;
                document.getElementById('name_general').innerHTML = r.nombre;
            });
        })
        .catch(error => console.error('Error:', error))

}

function take_assistance() {
    if (plate === '') {
        alert('No existe matricula');
        throw new Error('No plate provided');
    }

    const url = `http://127.0.0.1:3000/student/assistance/${plate}`;

    fetch(url, {
        method: 'POST',
        mode: 'cors',
        cache: 'no-cache',
        credentials: 'include',
        headers: {
        'Content-Type': 'application/json'
        },
        redirect: 'follow',
        referrerPolicy: 'no-referrer'
        })
        .then(res => {
            console.log(res);
            if (res.status != 200) {
                throw new Error('An error ocurred in login')
            }
            res.text().then(r => {
                if (r === 'assistance already taken') {
                    alert('Asistencia ya tomada');
                }
            });
        })
        .catch(error => console.error('Error:', error))
        .then(response => console.log('Success:', response));
}

function getCookie(cname) {
    let name = cname + "=";
    let decodedCookie = decodeURIComponent(document.cookie);
    let ca = decodedCookie.split(';');
    for(let i = 0; i <ca.length; i++) {
      let c = ca[i];
      while (c.charAt(0) == ' ') {
        c = c.substring(1);
      }
      if (c.indexOf(name) == 0) {
        return c.substring(name.length, c.length);
      }
    }
    return "";
}