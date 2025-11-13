function Navbar() {
  return (
    <nav  style={{
      backgroundColor: "#2a4d69",
      color: "white",
      padding: "15px 30px",
      display: "flex",
      justifyContent: "space-between",
      alignItems: "center",
    }}>
      <h2><a href="/" style={{ color: "white", textDecoration: "none" }}>My Project</a></h2>
      <div style={{ display: "flex", gap: "20px" }}>
        <a href="#about" style={{ color: "white", textDecoration: "none", fontSize:"18px", fontWeight:"bold"}}>About</a>
        <a href="#team" style={{ color: "white", textDecoration: "none" , fontSize:"18px" , fontWeight:"bold"}}>Team</a>
        <a href="#contact" style={{ color: "white", textDecoration: "none" , fontSize:"18px", fontWeight:"bold" }}>Contact</a>
      </div>
    </nav>
  );
}
export default Navbar;
