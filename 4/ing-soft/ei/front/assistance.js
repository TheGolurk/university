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
            throw new Error('An error ocurred in login')
        }
        console.log('data', res);
        res.json()
    })
    .catch(error => console.error('Error:', error))
    .then(response => console.log('Success:', response));

