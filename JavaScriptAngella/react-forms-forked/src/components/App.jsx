import React, { useState } from "react";



function App() {

  const [name , setName] = useState("");
  const [currentColor , setColor] = useState("white");
  const [headingText , setHeading] = useState("");

  function handleChange(event) {
    setName(event.target.value);
  }
  function changeColor() {
    currentColor === "white" ? setColor("black") : setColor("white");
  }
  function handleClick(event) {
    setHeading(name);
    // this will prevent the default behavior like -> refreshing the page.
    event.preventDefault();
  }

  return (
    <div className="container">
      <h1>Hello {headingText}</h1>
      <form onSubmit={handleClick}>
        <input
          onChange={handleChange}
          type="text"
          placeholder="What's your name?"
          value={name}
        />
        <button type = "submit" onMouseOver = {changeColor} onMouseOut = {changeColor} style = {{background : currentColor}}>Submit</button>
      </form>
    </div>
  );
}

export default App;
