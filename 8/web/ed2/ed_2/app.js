const express = require('express');
const dotenv = require('dotenv');
const jwt = require('jsonwebtoken');
const path = require('path');
const connectDB = require('./db');
const User = require('./userModel');

dotenv.config();

const app = express();

app.use(express.json());
app.use(express.urlencoded({ extended: false }));

connectDB();

app.get('/', (req, res) => {
  res.sendFile(__dirname + '/index.html');
});

app.get('/register', (req, res) => {
  res.sendFile(path.join(__dirname, 'registro.html'));
});

app.post('/register', async (req, res, next) => {
  const { email, password } = req.body;
  const user = new User({ email, password });
  await user.save().catch(error => {
    return next(error);
  }).then(() => {
    res.json({ message: 'User registered successfully' });
  })
});

app.get('/login', (req, res) => {
  res.sendFile(path.join(__dirname, 'login.html'));
});

app.post('/login', async (req, res, next) => {
  const {
    email,
    password,
  } = req.body;

  const user = await User.findOne({ email }).catch(error => { return next(error); });
  const isMatch = await user.comparePassword(password).catch(error => { return next(error); });

  if (!isMatch || !user) {
    return res.status(401).json({ message: 'Authentication failed' });
  }

  const token = jwt.sign({ email: user.email }, "HOLACOMOESTAS");
  res.json({ token });
});

app.get('/users', async (req, res, next) => {
  const users = await User.find().catch(error => { return next(error); }).then(() => res.json(users));
});

const PORT = 3000;

app.listen(PORT, () => {
  console.log(`Server listening on port ${PORT}`);
});

