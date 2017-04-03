
module ListItemSpec = {
 include ReactRe.Component;
 let name = "Maty component";
 type props = {count: int, count2: int};

  let render {props, state, updater} => {   
   <div>
    <div>
      (ReactRe.stringToElement "Hello world First number")
      (ReactRe.stringToElement (string_of_int props.count))
      (ReactRe.stringToElement " - Second number:")
      (ReactRe.stringToElement (string_of_int props.count2))
    </div>
   </div>;
 } 
};
module ListItem = {
  include ReactRe.CreateComponent ListItemSpec;
  let createElement ::count ::count2 => wrapProps {count:count, count2:count2};

}

