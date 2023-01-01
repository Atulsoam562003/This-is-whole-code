import React from "react";

function Form(props) {
  return (
    <form className="form">
      <input type="text" placeholder="Username" />
      <input type="password" placeholder="Password" />
      {!props.valid &&  <div> <input type="password" placeholder="Confirm Password" /></div>}
      <button type="submit">{props.valid ? "Login" : "Register"} </button>
    </form>
  );
}

export default Form;
