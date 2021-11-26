async function login() {
    const plate = document.getElementById('floatingInput').value;
    const url = `http://127.0.0.1:3000/student/${plate}`;

    // body: JSON.stringify(data)
    fetch(url, {
        method: 'POST',
        mode: 'cors',
        cache: 'no-cache',
        credentials: 'same-origin',
        headers: {
          'Content-Type': 'application/json'
        },
        redirect: 'follow',
        referrerPolicy: 'no-referrer'
        })
        .then(res => {
            if (res.status != 200) {
                alert('No encontrado');
                throw new Error('An error ocurred in login')
            }

            res.json().then(r => {
                document.cookie = `matricula=${r}; expires=Thu, 01 Jan 2025 00:00:00 UTC; path=/;`;
                location.replace('http://127.0.0.1:5500/front/assistance.html');
            });
        })
        .catch(error => console.error('Error:', error))
        .then(response => console.log('Success:', response));
}
