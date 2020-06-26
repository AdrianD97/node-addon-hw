var addon = require('bindings')('addon.node');

console.log('This should be five:', addon.mysqrt(25));

console.log('This should be six:', addon.mysqrt(36));

console.log('This should be seven:', addon.mysqrt(49));

console.log('This should be eight:', addon.mysqrt(64));

console.log('This should be nine:', addon.mysqrt(81));

console.log('This should be ten:', addon.mysqrt(100));

