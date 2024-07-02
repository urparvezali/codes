use mongodb::{options::ClientOptions, Client};

pub async fn dbconnection() -> Result<Client, mongodb::error::Error> {
    // let url = "mongodb+srv://urparvezali:MDBP%40sswors102938@cluster0.jfrvstu.mongodb.net";
	let url = "mongodb://localhost:27017";
    let opt = ClientOptions::parse(url).await.unwrap();
    Client::with_options(opt)
}