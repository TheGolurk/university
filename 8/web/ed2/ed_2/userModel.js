const mongoose = require('mongoose');
const bcrypt = require('bcrypt');

const userSchema = new mongoose.Schema({
  email: {
    type: String,
    required: true,
    unique: true
  },
  password: {
    type: String,
    required: true
  }
});

userSchema.pre('save', async function (next) {
    if (!this.isModified('password')) {
      return next();
    }

    const hashedPassword = await bcrypt.hash(this.password, 10).catch(error => { return next(error) });
    this.password = hashedPassword;
    return next();
});

userSchema.methods.comparePassword = async function (candidatePassword, next) {
    const isMatch = await bcrypt.compare(candidatePassword, this.password).catch(error => { return next(error) });
    return isMatch;
};

const User = mongoose.model('User', userSchema);
module.exports = User;
