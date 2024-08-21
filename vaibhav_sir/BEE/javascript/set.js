var set = new Set();

set.add(1);
set.add(2);
set.add(10);

for(i = 0; i<3; i++){
    console.log(set[i]);
    // console.log(i);
}
set.entries();
for(const val of set.values()){
    console.log(val);
}

set[0] = 10;
set[0] = 20;
console.log(set[1]);

console.log(set);