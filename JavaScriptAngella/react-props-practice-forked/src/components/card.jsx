import React from "react";
import Avatar from "./Avatar";
import Details from "./Details";

function Card(props) {
    return (
        <div className="card">
        <div className="top">
          <h1>{props.key}</h1>
          <h2 className="name">{props.name}</h2>
          <Avatar src = {props.imgURL} />
        </div>
        <div className="bottom">
        <Details phone = {props.phone} email = {props.email}/>
        </div>
      </div>
    );
}

export default Card;