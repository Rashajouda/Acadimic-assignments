import image from '../assets/images/6518027.jpg';
function ImageSection() {
  return (
    <div id="image" style={{ textAlign: "center", margin: "40px 0" }}>
      <img
        src={image}
        alt="Sample"
        style={{ width:"40%", borderRadius: "15px", boxShadow: "0 0 10px rgba(0,0,0,0.2)" }}
      />
      <p style={{ marginTop: "10px", color: "#333" }}>
        This image is displayed using a React component.
      </p>
    </div>
  );
}

export default ImageSection;
