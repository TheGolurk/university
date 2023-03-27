const mongoose = require('mongoose');

const connectDB = async () => {
    const conn = await mongoose.connect("mongodb://root:root@localhost:27017", {
        useNewUrlParser: true,
        useUnifiedTopology: true,
      }).catch(err => {
        console.error(`Error connecting to MongoDB: ${err.message}`);
        process.exit(1);
      });
    console.log(`MongoDB connected: ${conn.connection.host}`);
};

module.exports = connectDB;
