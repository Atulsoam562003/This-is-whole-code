import React, { useState } from "react";

function InputArea(props) {

    const [task ,setTask] = useState("");

    function onChange(event) {
        const newValue = event.target.value;
        setTask(newValue);
    }

    return (
    <div className="form">
        <input type="text"
          name = "todo"
          value={task}
          onChange = {onChange}
        />
        <button onClick={ () => {
            props.addItem(task);
            setTask("");
        }}>
          <span>Add</span>
        </button>
      </div>
    );
}

export default InputArea;