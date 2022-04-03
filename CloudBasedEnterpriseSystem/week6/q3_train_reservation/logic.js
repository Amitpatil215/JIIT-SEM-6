function validateEmail() {
    let email = document.getElementById('email').value
    const regex = new RegExp("\\w@[a-z].[a-z]");

    isMatched = email.match(regex);
    if (isMatched) {

        console.log(true);
    }
}

function onFormSubmission() {

    validateEmail()
}