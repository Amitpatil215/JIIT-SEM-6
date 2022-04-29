function validateEmail() {
    let email = document.getElementById('email').value
    const regex = new RegExp("\\w@[a-z].[a-z]");

    isMatched = email.match(/\w@[a-z].[a-z]/);
    if (isMatched) {

        console.log(true);
    } else {
        console.log(false);

    }
}

function onFormSubmission() {

    validateEmail()
}