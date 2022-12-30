import React from 'react';

const year = new Date().getFullYear();

function Footer() {
    return (
        <footer>
            <p> AtulSoam Copyright &copy; {year} </p>
        </footer>
    );
}

export default Footer;