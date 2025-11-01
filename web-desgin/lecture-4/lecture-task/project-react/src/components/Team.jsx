import { useState } from "react";

function Team() {
      const [liked, setLiked] = useState(false);

  const teamMembers = [
    { name: "Rasha Tiaseer", role: "Project Leader" },
    { name: "Roaa Taiseer", role: "Designer" },
    { name: "Salma Ahmed", role: "Developer" },
    { name: "Ahmed Khalid", role: "Tester" },
  ];

  return (
    <section id="team" style={{ padding: "40px 0", backgroundColor: "#f4f6f8" }}>
      <h2 style={{ textAlign: "center", color: "#2a4d69" }}>Our Team</h2>
      <div
        style={{
          display: "grid",
          gridTemplateColumns: "repeat(auto-fit, minmax(200px, 1fr))",
          gap: "20px",
          maxWidth: "1000px",
          margin: "30px auto",
          padding: "0 20px",
        }}
      >
        {teamMembers.map((member, index) => (
          <div
            key={index}
            style={{
              background: "white",
              borderRadius: "15px",
              boxShadow: "0 4px 10px rgba(0,0,0,0.1)",
              textAlign: "center",
              padding: "20px",
              transition: "transform 0.2s",
            }}
            onMouseEnter={(e) => (e.currentTarget.style.transform = "scale(1.05)")}
            onMouseLeave={(e) => (e.currentTarget.style.transform = "scale(1)")}
          >
            <h3 style={{ color: "#2a4d69", marginBottom: "5px" }}>{member.name}</h3>
            <p style={{ color: "#4b86b4" }}>{member.role}</p>
          </div>
        ))}
      </div>
      {/* <LikeButton/> */}
       <div style={{ textAlign: "center", marginTop: "20px" }}>
      <button
        onClick={() => setLiked(!liked)}
        style={{
          padding: "10px 20px",
          backgroundColor: liked ? "#4CAF50" : "#007bff",
          color: "white",
          border: "none",
          borderRadius: "10px",
          cursor: "pointer",
          transition: "0.3s",
        }}
      >
        {liked ? "💚 Liked!" : "Like 👍"}
      </button>
    </div>
    </section>
  );
}

export default Team;
