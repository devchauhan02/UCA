function foo(arg1,arg2){
    return arg1*arg2;
}

// rest operator 

function foo1(...arg){
    let final_result = 1;
    for(i = 0; i<arg.length; i++){
        final_result*=arg[i];
    }
    return final_result;
}

console.log(foo1(1,2,3));