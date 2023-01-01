import React from "react";

function Input(props) {
    return (
        <input type={props.type} placeholder={props.text} />
    );
}

export default Input;