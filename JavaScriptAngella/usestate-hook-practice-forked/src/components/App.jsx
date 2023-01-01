import React, { useState } from "react";


function App(props) {
  let now = new Date().toLocaleTimeString().substring(0,8);
  function sayHi() {
    console.log("HI");
  }
  setInterval(currentTime,1000);

  const [time , setTime] = useState(now);

  function currentTime () {
    const newTime = new Date().toLocaleTimeString().substring(0,8);
    setTime(newTime)
  }

  return (
    <div className="container">
      <h1>{time}</h1>
      <button onClick={currentTime}>Get Time</button>
    </div>
  );
}

export default App;
