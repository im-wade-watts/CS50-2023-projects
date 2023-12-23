var choice1 = document.getElementById("5to1");
var choice2 = document.getElementById("3to1");
var choice3 = document.getElementById("1to1");
var choice4 = document.getElementById("1to3");
var choice5 = document.getElementById("1to5");
var checkBtn = document.getElementById("check-btn");
var multipleChoiceResult = document.getElementById("multiple-choice-result");
var freeResponseResult = document.getElementById("free-response-result");

// multiple choice question
choice1.addEventListener("click", function(){
    multipleChoiceResult.innerHTML = "";
    multipleChoiceResult.innerHTML = "Sorry, try again!";
    choice1.style.backgroundColor = "#f73030";
})

choice2.addEventListener("click", function(){
    multipleChoiceResult.innerHTML = "";
    multipleChoiceResult.innerHTML = "Sorry, try again!";
    choice2.style.backgroundColor = "#f73030";
})

choice3.addEventListener("click", function(){
    multipleChoiceResult.innerHTML = "";
    multipleChoiceResult.innerHTML = "Incorrect, try again!";
    choice3.style.backgroundColor = "#f73030";

})
choice4.addEventListener("click", function(){
    multipleChoiceResult.innerHTML = "";
    multipleChoiceResult.innerHTML = "Incorrect, try again!";
    choice4.style.backgroundColor = "#f73030";

})

choice5.addEventListener("click", function(){
    multipleChoiceResult.innerHTML = "";
    multipleChoiceResult.innerHTML = "Correct! New Zeland has an aproximate ratio of people to sheep about 1 person to 5 sheeps!";
    choice5.style.backgroundColor = "#c0f760";

})

// free response question
checkBtn.addEventListener("click", function(){
    var userInput = document.getElementById("user-input").value;
    if(userInput.toLowerCase() == "switzerland"){
        freeResponseResult.innerHTML = "Correct!";

    }
    else{
        freeResponseResult.innerHTML = "Sorry, try again";
    }
})
