import React from "react";

function Details(props) {
    return (
        <div className="info">
            <p>{props.phone}</p>
            <p>{props.email}</p>
        </div>
    );
}

export default Details;