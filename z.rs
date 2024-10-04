#[derive(Debug, Clone)]
enum Gender {
    Male,
    Female,
}
#[derive(Debug)]
struct User {
    email: String,
    password: String,
    name: Option<String>,
    gender: Option<Gender>,
}
impl User {
    fn new(email: String, password: String) -> Self {
        Self {
            email,
            password,
            name: None,
            gender: None,
        }
    }
    fn set_name(&mut self, name: String) -> &mut Self {
        self.name = Some(name);
        self
    }
    fn set_gender(&mut self, gender: Gender) -> &mut Self {
        self.gender = Some(gender);
        self
    }
    fn build(&mut self) -> Self {
        Self {
            email: self.email.clone(),
            password: self.password.clone(),
            name: self.name.clone(),
            gender: self.gender.clone(),
        }
    }
}

fn main() {
    let mut user = User::new("mail@mail.com".to_string(), "mypass".to_string())
        .set_gender(Gender::Male)
        .set_name("MyName".to_string())
        .build();
	user.name = Some("FUCK".to_string());
    dbg!(user);
}
