arr = [1,2,3];


multiplyBY2 = (value)=>{
    return 2*value;
}

Array.prototype.mapCustom = function (callbackFunction){
    let arr = [];
    for(let i = 0; i<this.length; i++){
        arr.push(callbackFunction(this[i]));
    }
    return arr;
}
console.log(arr.__proto_);

console.log(arr.mapCustom(multiplyBY2));
