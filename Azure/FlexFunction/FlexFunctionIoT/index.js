module.exports = async function (context, req) {
    const accountSid = 'TWILIO_ACCOUNT_SID';
    const authToken = 'TWILIO_AUTH';
    const client = require('twilio')(accountSid, authToken);

    client.wireless.commands
               .create({sim: 'SIM_SSID', command: '1'})
               .then(command => console.log(command.sid));
};