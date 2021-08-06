let date = new Date();

var address = require('address');

var id = address.mac((err,address) => {
    console.log(address);
    return address;
})
console.log(typeof(id));

    