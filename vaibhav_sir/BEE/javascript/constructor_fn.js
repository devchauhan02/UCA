
var max_mark = 500;
// var student = {
//     fname : "fname",
//     college: "chitkara",
//     obtainded_mark : 200,
//     check_result : function(){
//         let percentage = (student.obtainded_mark/max_mark)*100;
//         if(percentage>=40){
//             return "Pass";
//         }
//         else{
//             return "Fail";
//         }
//     }
// }

// console.log(student.check_result());


// function student(fname,obtained_mark){
//     return {
//         fname : fname,
//         obtained_mark : obtained_mark,
//         check_result : function(){
//             let percentage = (obtainded_mark/max_mark)*100;
//             if(percentage>=40){
//                 return "Pass";
//             }
//             else{
//                 return "Fail";
//             }
//         },
//     }

// }
// console.log(student1);

// var  student1 = student("jitendra",400);
// console.log(student1.check_result());


// function student(fname,obtained_mark){
//     return {
//         fname : fname,
//         obtained_mark : obtained_mark,
//         check_result : function(){
//             let percentage = (this.obtainded_mark/max_mark)*100;
//             if(percentage>=40){
//                 return "Pass";
//             }
//             else{
//                 return "Fail";
//             }
//         },
//     }

// }
// console.log(student1);



function student(fname,obtained_mark){
    return {
        fname : fname,
        obtained_mark : obtained_mark,
        check_result : function(){
            let percentage = (this.obtainded_mark/max_mark)*100;
            if(percentage>=40){
                return "Pass";
            }
            else{
                return "Fail";
            }
        },
    }

}

var student2 = new student("jitu",300);
console.log(student2.check_result());
// console.log(student1);