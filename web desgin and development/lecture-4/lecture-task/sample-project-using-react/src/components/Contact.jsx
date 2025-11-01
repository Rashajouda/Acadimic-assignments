import { useState } from "react";


function Contact() {
    const [message, setMessage] = useState("");
    const [name, setName] = useState("");
  const [email, setEmail] = useState("");
  return (
    <section id="contact" style={{ padding: "60px 20px", textAlign: "center" }}>
      <h2 style={{ color: "#2a4d69" }}>Contact Us</h2>
      <p style={{ color: "#555" }}>Have a question or want to reach out?</p>
    <form action="" method="get"  style={{
          maxWidth: 720,
          textAlign:"center",
          margin: "0 auto",
          display: "grid",
          gap: 12,
          gridTemplateColumns: "1fr 1fr",
        }}>
        
              <input
          type="text"
          placeholder="Your name"
          value={name}
          onChange={(e) => setName(e.target.value)}
          style={{
            padding: "12px 14px",
            borderRadius: 10,
            border: "1px solid #d7e0ea",
            outline: "none",
            boxShadow: "inset 0 1px 0 rgba(255,255,255,0.6)",
          }}
          aria-label="Name"
        />
        <input
          type="text"
          placeholder="Your Email"
          value={email}
          onChange={(e) => setEmail(e.target.value)}
          style={{
            padding: "12px 14px",
            borderRadius: 10,
            border: "1px solid #d7e0ea",
            outline: "none",
            boxShadow: "inset 0 1px 0 rgba(255,255,255,0.6)",
          }}
          aria-label="Name"
        />
       <textarea
          placeholder="Write your message..."
          value={message}
          onChange={(e) => setMessage(e.target.value)}
          rows={10}
          cols={50}
          style={{
            gridColumn: "1 / -1",
            padding: "12px 14px",
            borderRadius: 10,
            border: "1px solid #d7e0ea",
            outline: "none",
            resize: "vertical",
          }}
          aria-label="Message"
        />
        <br/>

      <button
        style={{
          marginTop: "15px",
          width:"100%",
          display:"block",
          backgroundColor: "#2a4d69",
          color: "white",
          padding: "15px 25px",
          border: "none",
          fontSize:"16px",
          borderRadius: "10px",
          cursor: "pointer",
        }}
        onClick={(e)=> setMessage('')
        }
      >
        📧 Send Message
      </button>
    </form>
    </section>
  );
}
export default Contact;
