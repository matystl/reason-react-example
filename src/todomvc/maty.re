module type Maty1Type = {
    let createElement: count2::int => children::list ReactRe.reactElement => ref::(ReactRe.reactRef => unit)? => key::string? => unit => ReactRe.reactElement;
};

module ListSpec = fun (Subcomponent: Maty1Type) => {
 include ReactRe.Component;   
 let name= "Top something";
 type props = {listContent: list int};

 let render {props} => {
  /*module Maty1 = {
    let createElement = props.listItemFunc;
  };*/
  let children_list = List.map (fun x => <Subcomponent key=(string_of_int x) count2=x />)
                          props.listContent;
  /*let children_list = [(ReactRe.stringToElement "aaa11")];*/
  <div>
    (ReactRe.listToElement children_list)
  </div>
 };
};


module List = fun (Subcomponent: Maty1Type) => {

  include ReactRe.CreateComponent (ListSpec Subcomponent);
  let createElement listContent::(listContent : list int) => wrapProps {listContent: listContent};
};



