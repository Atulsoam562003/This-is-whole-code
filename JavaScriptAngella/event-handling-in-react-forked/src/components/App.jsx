import React, { useState } from "react";

function App() {

    const [headingText , setHeadingText] = useState("Hello");
    const [initialcolor ,changeColor] = useState("white");
    function handleClick() {
      setHeadingText("Submitted");
    }

    function handleHover() {
      initialcolor === "white" ? changeColor("black") : changeColor("white");
    }

  return (
    <div className="container">
      <h1>{headingText}</h1>
      <input type="text" placeholder="What's your name?" />
      <button onClick={handleClick} onMouseOver = {handleHover} onMouseOut = {handleHover}
      style = {{background : initialcolor}}>Submit</button>
    </div>
  );
}

export default App;
